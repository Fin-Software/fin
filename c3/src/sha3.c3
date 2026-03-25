// Copyright (c) 2025-2026 Zack Puhl <github@xmit.xyz>. All rights reserved.
// Use of this source code is governed by the MIT license
// a copy of which can be found in the LICENSE_STDLIB file.
module std::crypto::sha3;

import std::crypto @public;

<* Used for creating SHA-3 HMACs with the "legacy" (i.e., non-KMAC) construction. *>
const char IPAD @local = 0x36;
<* Used for creating SHA-3 HMACs with the "legacy" (i.e., non-KMAC) construction. *>
const char OPAD @local = 0x5c;

<* Valid hash digest sizes; transparently equates to the valid Keccak security levels. *>
const usz[] DIGEST_SIZES = keccak::SECURITY_LEVELS;

<* The Keccak domain-separation delimiter to use specifically for SHA-3. *>
const DEFAULT_DELIMITER = 0x06;

<*
 Generate and return a SHA-3 hash. The return byte array's length is dependent upon the `$hash_bits` used.

 @param $hash_bits : "The strength of the hash function to use. Also determines the fixed output size."
 @param [in] data : "The data to hash."

 @require @in($hash_bits, ...DIGEST_SIZES) : "You must use a valid SHA-3 digest size."

 @return "An array of `$outlen_bytes` bytes containing the hash."
*>
macro char[*] hash($hash_bits, char[] data)
{
	char[$hash_bits / 8] result @noinit;
	hash_into($hash_bits, result[..], data);
	return result;
}

<*
 Generate a SHA-3 hash into a buffer. The length of the `into` buffer determines the resultant size of the hash.
 Note that changes to the requested output length _does not_ affect the contents of the returned hash.

 @param $hash_bits : "The strength of the hash function to use. Also determines the fixed output size."
 @param [out] into : "The destination slice for the hash result."
 @param [in] data : "The data to hash."

 @require @in($hash_bits, ...DIGEST_SIZES) : "You must use a valid SHA-3 digest size."
 @require into.len > 0 : "The destination result slice must have a length greater than 0."
*>
macro void hash_into($hash_bits, char[] into, char[] data)
{
	Sha3{$hash_bits} s;
	s.init();
	s.update(data);
	s.final(into);
}

<*
 SHA-3 is not vulnerable to length extension attacks; therefore, `SHA-3(key || message)` is
 valid and doesn't require the nested HMAC construction.

 **WARNING**: This is not an 'official' NIST HMAC, and it's not likely to be used widely. You should
 NOT use this if you want to form SHA-3 HMACs that will validate with non-C3 implementations of SHA-3.
 If that's your requirement, you should use the plain `hmac` construction instead.

 @param $hash_bits : "The strength of the hash function to use. Also determines the fixed output size."
 @param [in] key : "The secrete key used to authenticate the data."
 @param [in] data : "The data to authenticate."

 @require @in($hash_bits, ...DIGEST_SIZES) : "You must use a valid SHA-3 digest size."

 @return "An array of `$outlen_bytes` bytes containing the hash."
*>
macro char[*] simple_hmac($hash_bits, char[] key, char[] data)
{
	char[$hash_bits / 8] result @noinit;
	simple_hmac_into($hash_bits, result[..], key, data);
	return result;
}

<*

 SHA-3 is not vulnerable to length extension attacks; therefore, `SHA-3(key || message)` is
 valid and doesn't require the nested HMAC construction.

 **WARNING**: This is not an 'official' NIST HMAC, and it's not likely to be used widely. You should
 NOT use this if you want to form SHA-3 HMACs that will validate with non-C3 implementations of SHA-3.
 If that's your requirement, you should use the plain `hmac_into` construction instead.

 @param $hash_bits : "The strength of the hash function to use. Also determines the fixed output size."
 @param [out] into : "The destination slice for the hash result."
 @param [in] key : "The secrete key used to authenticate the data."
 @param [in] data : "The data to authenticate."

 @require @in($hash_bits, ...DIGEST_SIZES) : "You must use a valid SHA-3 digest size."
 @require into.len > 0 : "You must use an output length over zero bytes."
*>
macro void simple_hmac_into($hash_bits, char[] into, char[] key, char[] data)
{
	Sha3{$hash_bits} s;
	s.init();
	s.update(key);
	s.update(data);
	s.final(into);
}

<*
 While SHA-3 is not vulnerable to length extension attacks, and `SHA-3(key || message)` works
 just fine, many libraries will still use the old nested construction from SHA-2. This carries
 that implementation over, but also allows one to specify a "tag size", which is the desired
 length of the resulting hash (i.e., 'squeezed' at that length from the Keccak sponge).

 The ordinary std::hash::hmac module is NOT used for this, because we can specify a "tag size"
 with this macro to get a variable-length MAC.

 Formula: `H((K' ^ opad) || H((K' ^ ipad) || m))`, where `K' = K.len > block_size ? H(K) : K`

 @param $hash_bits : "The strength of the hash function to use. Does NOT determine the output size."
 @param $tag_size : "The size, in bytes, of the resulting MAC byte array."
 @param [in] key : "The secret key used to authenticate the data."
 @param [in] data : "The data to use when creating the HMAC."

 @require @in($hash_bits, ...DIGEST_SIZES) : "You must use a valid SHA-3 digest size."
 @require $tag_size > 0 : "You must use a tag size over zero bytes."

 @return "An array of `$outlen_bytes` bytes containing the hash."
*>
macro char[*] hmac($hash_bits, usz $tag_size, char[] key, char[] data)
{
	char[$tag_size] result @noinit;
	hmac_into($hash_bits, result[..], key, data);
	return result;
}

<*
 While SHA-3 is not vulnerable to length extension attacks, and `SHA-3(key || message)` works
 just fine, many libraries will still use the old nested construction from SHA-2. This carries
 that implementation over, but also allows one to specify a "tag size", which is the desired
 length of the resulting hash (i.e., 'squeezed' at that length from the Keccak sponge).

 The ordinary std::hash::hmac module is NOT used for this, because we can specify a "tag size"
 with this macro to get a variable-length MAC.

 Formula: `H((K' ^ opad) || H((K' ^ ipad) || m))`, where `K' = K.len > block_size ? H(K) : K`

 @param $hash_bits : "The strength of the hash function to use. Does NOT determine the output size."
 @param [out] into : "The destination slice for the hash result. The size of this slice determined the resultant tag length."
 @param [in] key : "The secret key used to authenticate the data."
 @param [in] data : "The data to use when creating the HMAC."

 @require @in($hash_bits, ...DIGEST_SIZES) : "You must use a valid SHA-3 digest size."
 @require into.len > 0 : "You must use an output length over zero bytes."
*>
macro void hmac_into($hash_bits, char[] into, char[] key, char[] data)
{
	usz $block_size = keccak::rate($hash_bits);
	char[$block_size] k_prime;
	if (key.len > $block_size)
	{
		hash_into($hash_bits, k_prime[:$hash_bits / 8], key);
	}
	else
	{
		k_prime[:key.len] = key[..];
	}
	char[$block_size] _ipad @noinit; _ipad[..] = IPAD; array::@zip_into(_ipad[..], k_prime, fn (a, b) => a ^ b);
	char[$block_size] _opad @noinit; _opad[..] = OPAD; array::@zip_into(_opad[..], k_prime, fn (a, b) => a ^ b);

	char[$hash_bits / 8] intermediate_ipad = simple_hmac($hash_bits, _ipad[..], data);
	simple_hmac_into($hash_bits, into, _opad[..], intermediate_ipad[..]);
}

<*
 A struct wrapping the base Keccak construct. Maintained as its own full structure for member flexibility.

 @require @in(HASH_BITS, ...DIGEST_SIZES) : "You must use a valid SHA-3 digest size."
*>
struct Sha3 <HASH_BITS>
{
	inline Keccak{HASH_BITS} k;
}

<*
 Initialize the inner Keccak context with the SHA-3 domain-separation delimiter.
*>
fn void Sha3.init(&self)
{
	keccak::@init_runtime_size(self, $sizeof(*self));
	self.k.init(runtime_delimiter: DEFAULT_DELIMITER);
}

// Copyright (c) 2025-2026 Zack Puhl <github@xmit.xyz>. All rights reserved.
// Use of this source code is governed by the MIT license
// a copy of which can be found in the LICENSE_STDLIB file.
module std::crypto::keccak;

<* The default Keccak `F` value for this implementation, per specification documents. *>
const DEFAULT_F = 1600;
<* The default amount of rounds used in the base Keccak construct. *>
const DEFAULT_ROUNDS = 24;
<* The default domain separation delimiter used in the base Keccak construct. *>
const DEFAULT_DELIMITER = 0x01;

<* The set of valid Keccak security levels supported by this implementation. *>
const usz[] SECURITY_LEVELS = { 224, 256, 384, 512 };

<*
 Get the constant Keccak `rate` value based on the given `F` and `SECURITY_LEVEL` attributes.

 @param $security_level : "The Keccak security level being used."
 @param $f : "The Keccak `F` parameter to use. Defaults to `1600`."

 @return "The constant Keccak `rate` value."
*>
macro rate($security_level, $f = DEFAULT_F) @const => ($f - ($security_level * 2)) / 8;

<*
 Generate and return an XOF result of the specified `$outlen_bytes`.

 @param $security_level : "The security level of the XOF to use when hashing."
 @param $outlen_bytes : "The length of the XOF hash to return,"
 @param [in] data : "The data to hash."
 @param $rounds : "An optional compile-time override of the rounds count used in hash computation."
 @param $delimiter : "An optional compile-time override of the delimiter used in hash computation."

 @require @in($security_level, ...SECURITY_LEVELS) : "Shake and Shake-derived structures must use a valid security level."
 @require $outlen_bytes > 0 : "You must use an output length over zero bytes."

 @return "A character array of the specified `$outlen_bytes` size containing the XOF result."
*>
macro char[*] xof($security_level, $outlen_bytes, char[] data, $rounds = DEFAULT_ROUNDS, $delimiter = DEFAULT_DELIMITER)
{
	char[$outlen_bytes] result @noinit;
	xof_into($security_level, result[..], data, $rounds: $rounds, $delimiter: $delimiter);
	return result;
}

<* When hashing with the base Keccak context, it's the same thing as using the XOF construct. *>
alias hash = xof;

<*
 Generate an XOF result of `into.len` bytes and store the result in the `into` slice.

 @param $security_level : "The security level of the XOF to use when hashing."
 @param [out] into : "The destination for the generated variable-length hash."
 @param [in] data : "The data to hash."

 @require @in($security_level, ...SECURITY_LEVELS) : "Shake and Shake-derived structures must use a valid security level."
 @require into.len > 0 : "The destination slice must have a length greater than zero."
 @param $rounds : "An optional compile-time override of the rounds count used in hash computation."
 @param $delimiter : "An optional compile-time override of the delimiter used in hash computation."
*>
macro void xof_into($security_level, char[] into, char[] data, $rounds = DEFAULT_ROUNDS, $delimiter = DEFAULT_DELIMITER)
{
	Keccak{$security_level} k;
	k.init($rounds, $delimiter);
	k.update(data);
	k.final(into);
}

<* When hashing with the base Keccak context, it's the same thing as using the XOF construct. *>
alias hash_into = xof_into;

<* The default Keccak context always employs the default `F` value of `1600`. *>
alias Keccak <SECURITY_LEVEL> = KeccakContext { DEFAULT_F, SECURITY_LEVEL };


// ==========================================================================================
module std::crypto::keccak @private;

import std::math;

<* A set of KeccakContext states used in its private state machine. *>
constdef KeccakState : inline int
{
	UNINITIALIZED,
	INITIALIZED,
	ABSORBING,
	SQUEEZING,
	FINALIZED,
}

<* The state machine is just the state, typedef'd to another type in case something else is added in the future. *>
typedef KeccakStateMachine @structlike = inline KeccakState;

<*
 Initialize the runtime value of the Keccak context that indicates the _true_ size of the dependent/derived class.
 This need sprang from the desire to delineate between `updated` and `finalized` states, where the latter implicitly
 finalizes and zeros the entire struct. In cases when a child struct type is inlining the KeccakContext type, we need
 to know the extent to zeroize, and the only way to do that at the time of writing is through runtime propagation.

 @param #instance : "The `KeccakContext` instance to modify."
 @param runtime_size : "The struct's size in bytes."
*>
macro void @init_runtime_size(#instance, usz runtime_size)
{
	if (!$defined(#instance.runtime_struct_size) ||| #instance.runtime_struct_size > 0) return;
	#instance.runtime_struct_size = runtime_size;
}

<*
 Transition the `KeccakStateMachine` the the specified state. This allows fine control over whether each
 transition is permitted and why.

 @param to_state : "The state to transition into."
*>
fn void KeccakStateMachine.transition(&self, KeccakState to_state)
{
	KeccakState from_state = *self;
	if (from_state == FINALIZED) abort("Cannot change from a finalized Keccak state - use `wipe` or create a new context instead.");
	switch (to_state)
	{
		case UNINITIALIZED: abort("Cannot change to an uninitialized Keccak state - use `wipe` or create a new context instead.");
		case INITIALIZED:
			if (from_state != UNINITIALIZED) abort("Can only change to an initialized state from an uninitialized Keccak state.");
		case ABSORBING:
			switch (from_state)
			{
				case UNINITIALIZED: abort("You must initialize a Keccak context before updating it.");
			}
		case SQUEEZING:
			switch (from_state)
			{
				case UNINITIALIZED: abort("You must initialize and update a Keccak context before squeezing it.");
				case INITIALIZED: abort("You must update a Keccak context before squeezing it.");
			}
		case FINALIZED: break;
		default: unreachable("Not a valid KeccakState");
	}
	*self = (KeccakStateMachine)to_state;
}

<* Keccak private constant. *>
const ulong[24] RC = {   // round constants
	0x0000_0000_0000_0001,  0x0000_0000_0000_8082,  0x8000_0000_0000_808a,  0x8000_0000_8000_8000,
	0x0000_0000_0000_808b,  0x0000_0000_8000_0001,  0x8000_0000_8000_8081,  0x8000_0000_0000_8009,
	0x0000_0000_0000_008a,  0x0000_0000_0000_0088,  0x0000_0000_8000_8009,  0x0000_0000_8000_000a,
	0x0000_0000_8000_808b,  0x8000_0000_0000_008b,  0x8000_0000_0000_8089,  0x8000_0000_0000_8003,
	0x8000_0000_0000_8002,  0x8000_0000_0000_0080,  0x0000_0000_0000_800a,  0x8000_0000_8000_000a,
	0x8000_0000_8000_8081,  0x8000_0000_0000_8080,  0x0000_0000_8000_0001,  0x8000_0000_8000_8008,
};

<* Keccak private constant. *>
const char[24] RHO = {
	1,  3,  6,  10, 15, 21,
	28, 36, 45, 55, 2,  14,
	27, 41, 56, 8,  25, 43,
	62, 18, 39, 61, 20, 44
};

<* Keccak private constant. *>
const char[24] PI = {
	10, 7,  11, 17, 18, 3,
	5,  16, 8,  21, 24, 4,
	15, 23, 19, 13, 12, 2,
	20, 14, 22, 9,  6,  1
};

<* The base Keccak context data structure used to generate XOF outputs. *>
struct KeccakContext <F, OUTPUT_BITS> @align(ulong.sizeof)
{
	union @align(ulong.sizeof)   // keccak sponge state
	{
		ulong[F / 8 / ulong.sizeof] sponge;
		char[F / 8] sponge_bytes;
	}
	union @align(ulong.sizeof)
	{
		ulong[rate(OUTPUT_BITS) / ulong.sizeof] buf_words;
		char[rate(OUTPUT_BITS)] buf;
	}
	usz offset;   // tracking leftover bytes from absorption
	char runtime_delimiter;
	char runtime_rounds;
	usz runtime_struct_size;
	bool is_padded;
	KeccakStateMachine state;
}

<*
 Initialize the base Keccak context.

 @param runtime_rounds : "An optional runtime override of the rounds count used in hash computation."
 @param runtime_delimiter : "An optional runtime override of the delimiter used in hash computation."

 @require runtime_rounds <= (12 + 2 * math::@intlog2(F / 25)) : "Amount of rounds cannot exceed MAX_ROUNDS."
*>
fn void KeccakContext.init(&self, char runtime_rounds = DEFAULT_ROUNDS, char runtime_delimiter = DEFAULT_DELIMITER)
{
	@init_runtime_size(self, $sizeof(*self));
	usz struct_sz = self.runtime_struct_size;
	*self = {
		.runtime_rounds = runtime_rounds,
		.runtime_delimiter = runtime_delimiter,
		.runtime_struct_size = struct_sz,
	};
	self.state.transition(INITIALIZED);
}

<*
 Update the Keccak context.

 @param [in] data : "The data to absorb."
*>
fn void KeccakContext.update(&self, char[] data) @inline => self.absorb(data);

<*
 Finalize the Keccak context, storing the XOF result into the output buffer (at the slice's length) and crystallizing.

 @param [out] into : "The destination for the XOF output. This slice's length will be wholly filled with the resultant XOF."
*>
fn void KeccakContext.final(&self, char[] into)
{
	defer self.finalize();
	if (!self.is_padded) self.pad();
	self.squeeze(into);
}

<*
 Finalizes the Keccak context. Unless `wipe` is called explicitly, or the state is reset to `UNINITIALIZED`, the
 context can no longer be used. All context memory is cleared first, followed by a retention of the `FINALIZED` state.
*>
fn void KeccakContext.finalize(&self)
{
	self.wipe();
	self.state.transition(FINALIZED);
}

<* Explicitly zeros the instance based on the runtime size. A minimum `$sizeof(KeccakContext)` is assumed. *>
fn void KeccakContext.wipe(&self) @inline => mem::zero_volatile(((char*)self)[:max($sizeof(*self), self.runtime_struct_size)]);

<* An internal function used to XOR the sponge with the partial "stomach" buffer (data awaiting digestion). *>
fn void KeccakContext.fill_block(&self)
{
	usz i = 0;
	for (; i < (self.offset / ulong.sizeof); i++) self.sponge[i] ^= self.buf_words[i];
	for (i = i * ulong.sizeof; i < self.offset; i++) self.sponge_bytes[i] ^= self.buf[i];
	self.permute_r();
	self.offset = 0;
}

<*
 Update the Keccak context.

 @param [in] input : "The data to absorb."
*>
fn void KeccakContext.absorb(&self, char[] input)
{
	self.state.transition(ABSORBING);
	if (!input.len) return;

	usz i;

	if (self.offset > 0)   // handle any leftovers
	{
		usz left = min(rate(OUTPUT_BITS) - self.offset, input.len);

		self.buf[self.offset:left] = input[:left];
		self.offset += left;

		if (left == input.len) return;   // awaiting more input before running rounds

		if (self.offset == rate(OUTPUT_BITS)) self.fill_block();

		i = left;
	}

	bool is_aligned = 0 == (uptr)&input[i] % ulong.sizeof;
	if (is_aligned)
	{
		for (; i + rate(OUTPUT_BITS) < input.len; i += rate(OUTPUT_BITS))
		{
			foreach (j, c : *(ulong[rate(OUTPUT_BITS) / ulong.sizeof]*)(&input[i])) self.sponge[j] ^= c;
			self.permute_r();
		}
	}
	else
	{
		for (; i + rate(OUTPUT_BITS) < input.len; i += rate(OUTPUT_BITS))
		{
			foreach (j, c : input[i:rate(OUTPUT_BITS)]) self.sponge_bytes[j] ^= c;
			self.permute_r();
		}
	}

	usz left = input.len - i;
	if (left > 0) self.buf[:left] = input[i:left];

	self.offset = left;
}

<*
 Pad the remainder of the Keccak sponge and run a final permutation before squeezing.
*>
fn void KeccakContext.pad(&self)
{
	usz i = 0;
	for (; i < (self.offset / ulong.sizeof); i++) self.sponge[i] ^= self.buf_words[i];
	for (i = i * ulong.sizeof; i < self.offset; i++) self.sponge_bytes[i] ^= self.buf[i];

	if (self.offset == rate(OUTPUT_BITS))
	{
		self.permute_r();
		self.offset = 0;
	}

	self.sponge_bytes[self.offset] ^= self.runtime_delimiter;
	self.sponge_bytes[rate(OUTPUT_BITS) - 1] ^= 0x80;

	self.permute_r();
	self.offset = 0;

	self.is_padded = true;
}

<*
 "Squeeze" data from the Keccak sponge construction into the `out` buffer.

 @param [out] out : "The destination for the squeezed data. The length of this slice determines the output length produced."
*>
fn void KeccakContext.squeeze(&self, char[] out)
{
	self.state.transition(SQUEEZING);
	if (!out.len) return;

	usz i;

	if (self.offset == rate(OUTPUT_BITS))
	{
		self.permute_r();
	}
	else if (self.offset > 0)
	{
		char[rate(OUTPUT_BITS)] localbuf;
		localbuf[..] = self.buf[..];

		usz left = min(rate(OUTPUT_BITS) - self.offset, out.len);

		out[:left] = localbuf[self.offset:left];
		self.offset += left;

		if (left == out.len) return;   // awaiting more data

		if (self.offset == rate(OUTPUT_BITS))
		{
			self.offset = 0;
			self.permute_r();
		}

		i = left;
	}

	for (; i + rate(OUTPUT_BITS) < out.len; i += rate(OUTPUT_BITS))
	{
		out[i:rate(OUTPUT_BITS)] = self.sponge_bytes[:rate(OUTPUT_BITS)];
		self.permute_r();
	}

	usz left = out.len - i;
	if (left > 0) out[i:left] = self.sponge_bytes[:left];

	self.offset = left;
}

<*
 Execute a set of permutations on the sponge buffer.
*>
fn void KeccakContext.permute_r(&self) @inline
{
	for (usz i = RC.len - self.runtime_rounds; i < RC.len; i++) self.round(RC[i]);
}

<*
 An individual permutation "round" of Keccak as applied to the current sponge data.
*>
fn void KeccakContext.round(&self, ulong rc)
{
	ulong[6] b;

	// theta
	$for var $x = 0; $x < 5; ++$x:
		$for var $y = 0; $y < 25; $y += 5:
			b[$x] ^= self.sponge[$x + $y];
		$endfor
	$endfor
	$for var $x = 0; $x < 5; ++$x:
		$for var $y = 0; $y < 25; $y += 5:
			self.sponge[$x + $y] ^= b[($x + 4) % 5] ^ b[($x + 1) % 5].rotl(1);
		$endfor
	$endfor

	// rho and pi
	b[5] = self.sponge[1];
	$for var $x = 0; $x < 24; ++$x:
		b[0] = self.sponge[PI[$x]];
		self.sponge[PI[$x]] = b[5].rotl(RHO[$x]);
		b[5] = b[0];
	$endfor

	// chi
	$for var $y = 0; $y < 25; $y += 5:
		$for var $x = 0; $x < 5; ++$x:
			b[$x] = self.sponge[$y + $x];
		$endfor
		$for var $x = 0; $x < 5; ++$x:
			self.sponge[$y + $x] ^= (~b[($x + 1) % 5]) & b[($x + 2) % 5];
		$endfor
	$endfor

	// iota
	self.sponge[0] ^= rc;
}
