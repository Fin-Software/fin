// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

//
//    Required Lowerings
//

// Desugar operators: combined assignment, optional-unwrap, try, short-circuit, orelse
// Convert where statements to their if-elseif-else statement form
// Reduce value declarations to their simplest disambiguated form
// Reduce value assignments to their simplest disambiguated form
// Convert routine declarations to value declarations
// Convert loops to their most simple while form
// Desugar errdefer statements
// Desugar defer statements

//
//    Required Optimization
//

// Stablely reorder struct fields from widest to narrowest

//
//    Optional Runtime Safety-check Insertion
//

// Check null pointer dereference
// Check indexes exceeding bounds
// Check overflow and underflow
// Check division by zero
