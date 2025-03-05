
/* Copyright 2018 Paul B Mann.  BSD License. */

		#include "CM_Global.h"
		#include "LG_Global.h"

	// 1 = upper, 2 = lower, 4 = '_', 8 = digit, 16 = quote ("|')
		uchar charcode[256] =
		{
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0, 16,  0,  0,  0,  0, 16,  0,  0,  0,  0,  0,  0,  0,  0,
			  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  0,  0,  0,  0,  0,  0,
			  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  4,
    		 16,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
			  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  0,  0,  0,  0,  0,

			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
		};

	// numeric[x] gives 1..10 for digits 0..9
		uchar numeric[256] =
		{
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			1,  2,  3,  4,  5,  6,  7,  8,  9, 10,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
		};

	// 1 = upper, 2 = lower, 4 = '_'
		uchar alpha[256] =
		{
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,
		     1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  1,  0,  0,  0,  0,  4,
			  0,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,
			  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  2,  0,  0,  0,  0,  0,

			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
			  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
		};

	// upper[x] gives the uppercase of x.
		uchar upper[256] =
		{
			  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
			 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
			 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
			 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
			 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
			 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
			 96, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
			 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90,123,124,125,126,127,

			128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
			144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
			160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,
			176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,
			192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
			208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
			224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
			240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
		};

	// lower[x] makes lower case of x.
		uchar lower[256] =
		{
			  0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
			 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
			 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
			 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
			 64, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
			112,113,114,115,116,117,118,119,120,121,122, 91, 92, 93, 94, 95,
			 96, 97, 98, 99,100,101,102,103,104,105,106,107,108,109,110,111,
			112,113,114,115,116,117,118,119,120,121,122,123,124,125,126,127,

			128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,
			144,145,146,147,148,149,150,151,152,153,154,155,156,157,158,159,
			160,161,162,163,164,165,166,167,168,169,170,171,172,173,174,175,
			176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,
			192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,207,
			208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,
			224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,
			240,241,242,243,244,245,246,247,248,249,250,251,252,253,254,255
		};

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int	itsakeyword (char* terminal)
{
		char* p;
	  	if (terminal[0] == '<') return 0;
      if (terminal[0] == '{') return 0;
		for (p = terminal; *p != 0; p++)
		{
			if (alpha[*p] & 3) // upper or lower case letter?
			{
				return (1);  // YES
			}
		}
		return (0); // NO
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

char* strchr (char*p, char c)
{
      while (*p && (*p++ != c));
      if (*p == 0) return (NULL);
      return (p-1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

char* strrchr (char* str, char c)
{
      char *p;
      p = str--;
      while (*p++); // Find 0 byte.

      p--;
      while (--p != str && *p != c);
      if (p == str) return (NULL);
      return (p);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

char* mystrlwr (char* s)
{
		for (char* p = s; *p != 0; p++)
		{
			*p = lower[*p];
		}
		return s;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

char* mystrupr (char* s)
{
		for (char* p = s; *p != 0; p++)
		{
			*p = upper[*p];
		}
		return s;
}

#ifndef WINDOWS
///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//		_filelength function supplied by Vasko Mitanov, Feb 2012.               //

long	_filelength (int fd)
{
		struct stat st;
		fstat(fd, &st);
		return st.st_size;
}
#endif

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  PRT_ARGS (int na, char** arg, int destination)
{
      int i;
		if (destination == 0) printf      (  "%s %s %s %s.\n", program, version, bits, copywrt);
		else				       prt_logonly ("\n%s %s %s %s.\n", program, version, bits, copywrt);
		if (na > 1)
		{
			if (destination == 0) ;
			else                  prt_logonly ("\n");
			for (i = 1; i < na; i++)
			{
				if (destination == 0) printf      ("%s ", arg[i]);
				else                  prt_logonly ("%s ", arg[i]);
			}
			if (destination == 0) printf      ("\n");
			else                  prt_logonly ("\n\n");
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   SET_OPTNS (int na, char** arg)
{
      int i, ne = 0;
      for (i = 2; i < na; i++)
      {
			if (!SET_OPTN (arg[i])) ne++;
		}
		if (ne > 0)
		{
			printf ("\n   OPTION   DEFAULT  DESCRIPTION\n");
			for (i = 0; *LGOption[i].name != 0; i++)
			{
				printf ("   %-6s  %8d  %s.\n", LGOption[i].name, LGOption[i].defvalue, LGOption[i].desc);
			}
			printf ("\n");
			return (0);
		}
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   SET_OPTN (char* opt)
{
		return (set_optn (LGOption, opt));
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   SET_OPTN_MA (char* opt)
{
		return (set_optn (MAOption, opt));
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   set_optn (OPTION* option, char* opt)
{
      int  i;
      char *o, *n;

		int value = 0;
		if      (*opt == '/' ) { opt++; value = 1; }
		else if (*opt == '-' ) { opt++; value = 1; }
		else if (*opt == '!' ) { opt++; value = 0; }
		else value = 1;

      for (i = 0; *option[i].name != 0; i++)
      {
         n = option[i].name;
         for (o = opt;; o++, n++)
         {
            if (*n == 0)					  // name end?
				{
					if (*o ==  0  ) goto set; // Got a match!
				  	if (*o == '\"') goto set; // Got a match!
					if (*o == '=' ) goto val; // Equals!
					if (*o == ' ' ) goto spa; // Whitespace!
					if (*o == '\t') goto spa; // Whitespace!
					goto next;                // Not a match yet!
				}
            if (*o ==  0)      goto next; // Not a match	yet
            if (*o != *n)      goto next; // Not a match	yet
         }
next:    continue;
      }

      n_errors++;
		printf ("Program option '%s' is invalid, not one of the following:\n", opt);
		return (0);

spa:	while (*o == ' ' || *o == '\t') o++; // bypass spaces and tabs
		if (*o == '=')
      {
val: 	   o++;
		   while (*o == ' ' || *o == '\t') o++; // bypass spaces and tabs
		   if (*o < '0' || *o > '9')
         {
		      n_errors++;
				printf ("Program option '%s' specifies an invalid number.\n", opt);
		      return (0);
         }
         value = atoi(o);
      }

set:  optn[option[i].numb] = value;
		if (optn [LG_VERBOSE] > 2) printf ("%s = %d\n", option[i].name, value);
		return 1;
}

///////////////////////////////////////////////////////////////////////////////

int   GetMaxValues (char* dn)
{
		char* p;
		int   rc;   // Return code.
      int   nb;	// Number of bytes read.
		int   linenumb;
		int   filedesc = -1;
		int   filesize;

		#ifdef WINDOWS
      strcpy (exefid, getenv ("USERPROFILE"));
      strcat (exefid, "\\AppData\\Local\\LRSTAR");
      strcat (exefid, "\\memory.txt");
      filedesc = open (exefid, 0);				// Open the file.
		#endif
      if (filedesc < 0)								// File not found.
		{
		   strcpy (exefid, dn);
			strcat (exefid, "memory.txt");
			filedesc = open (exefid, 0);        // Open the file.
			if (filedesc < 0)							// File not found.
			{
				SaveMaxValues ();						// Create it.
				return 1;
			}
		}

		rc = 1; // OK
		linenumb = 1;
      filesize = _filelength (filedesc) + 2;		// Set amount to read.
      ALLOC (input_start, filesize);
      nb = read (filedesc, input_start, filesize);
      if (nb <= 0)
		{
			SaveMaxValues ();						      // Create it.
			goto Ret;
		}

      input_end = input_start + nb;					// Set end-of-buffer pointer.
      *(input_end)   = EOL_CHAR;
      *(input_end+1) = EOF_CHAR;

		p = input_start;
		do
		{
Find:		while (*p != '/' && *p != EOF_CHAR && *p != '\n') p++; // Find first "
			if (*p == '\n')
			{
				p++;
				linenumb++;
				goto Find;
			}
			if (*p == EOF_CHAR) goto Ret;
			char* option = p;										// Set option start.
    		while (*p != EOF_CHAR && *p != '\n') p++;		// Find end of line.
			if (*p == '\n') linenumb++;
			if (*p == EOF_CHAR) goto Ret;

			*p++ = 0;  // skip over \n
         if (SET_OPTN_MA (option) == 0)
			{
				printf ("\n   OPTION   DEFAULT  DESCRIPTION\n");
				for (int i = 0; *MAOption[i].name != 0; i++)
				{
					printf ("   %-6s  %8d  %s.\n", MAOption[i].name, MAOption[i].defvalue, MAOption[i].desc);
				}
				printf ("\n");
				rc = 0; // error
				goto Ret;
			}
		}
		while (p < input_end);

Ret:  FREE (input_start, filesize);
      close (filedesc);								// Close input file.
      return rc;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  SaveMaxValues ()
{
		int i;
      FILE* fp;
		fp = fopen (exefid, "w");
		if (fp == NULL)
		{
			printf ("Error: Cannot write file: '%s'.\n", exefid);
			Quit();
		}
		else
		{
			fprintf (fp, "\nMemory Allocation Options (maximum values).\n");
			fprintf (fp, "Modify these values to suit your needs.\n\n");
			for (i = 0; *MAOption[i].name != 0; i++)
			{
				fprintf (fp, "/%-6s = %8d   %s\n", MAOption[i].name, optn[MAOption[i].numb], MAOption[i].desc);
			}
			fclose (fp);
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   get_fid (char *arg, char *dir, char *fn, char *ft)
{
      int  len;
      char *f, c, *last_slash, *last_dot;

      dir[0] = 0;
      fn [0] = 0;
      ft [0] = 0;

		last_slash = strrchr(arg, '\\');
		if (last_slash != NULL)
		{
			f = last_slash + 1;			// Point at filename start.
			c = *f;							// Save the char.
			*f = 0;							// Drop null there.
         if (f-arg < MAX_DIR)			// If length is OK.
         {
				strcpy (dir, arg);		// Copy to 'dir'.
         }
         else								// Directory name is too long.
         {
				n_errors++;
				if (n_errors == 1) printf ("\n");
            printf ("Directory name\n\n%s\n\nhas more than %d characters.\n\n", arg, MAX_DIR-1);
            return (0);
         }
			*f = c;							// Replace char.
      }
		else f = arg;						// Point at filename start.

		last_dot = strrchr (f, '.');
		if (last_dot != NULL)
		{
			*last_dot = 0;
			if (last_dot-f < MAX_FILENAME)
			{
				strcpy (fn, f);			// Copy to 'fn'.
         }
         else								// Filename is too long.
         {
				n_errors++;
				if (n_errors == 1) printf ("\n");
		      printf ("Filename\n\n%s\n\nhas more than %d characters.\n\n", f, MAX_FILENAME-1);
            return (0);
         }
			*last_dot = '.';				// Replace dot.
			len = (int)strlen(last_dot);
			if (len < MAX_FILETYPE)
			{
				strcpy (ft, last_dot);	// Copy to 'ft'.
			}
			else								// Filetype is too long.
			{
				n_errors++;
				if (n_errors == 1) printf ("\n");
				printf ("Filetype\n\n%s\n\nhas more than %d characters.\n\n", last_dot, MAX_FILETYPE-1);
            return (0);
			}
		}
		else									// No '\' and no '.'
		{
			len = (int)strlen (f);
			if (len < MAX_FILENAME)
			{
				strcpy (fn, f);			// Copy to 'fn'.
         }
         else								// Filename is too long.
         {
				n_errors++;
				if (n_errors == 1) printf ("\n");
		      printf ("Filename\n\n%s\n\nhas more than %d characters.\n\n", f, MAX_FILENAME-1);
            return (0);
         }
		}
		return 1;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

char*	get_file (char *dir, char *fn, char *ft, int *nb, int flags)
{
      char  fid [MAX_PATH], *filep;
      int   fl, n, fd;

      strcpy (fid, dir);
      strcat (fid, fn);
      strcat (fid, ft);
      if ((fd = open (fid, flags)) < 0)
      {
         *nb = 0;
         return (NULL);
      }
      fl = _filelength (fd);
      ALLOC (filep, fl+3);
		*filep = '\n';											// Put newline at beginning.
      n = read (fd, filep+1, fl);
      close (fd);
      if (n < 0) goto Err;
		if (*(filep+n) != '\n') *(filep+n++) = '\n';	// Put newline there.
      *nb = n;													// Don't include EOF.
      return (filep);

Err: 	n_errors++;
		prt_log ("Read error on file %s.\n\n", fid);
      return (NULL);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

#ifdef _DEBUG
char* alloc (char *s, char*& x, int size, int n)
{
      x = (char*)malloc (n*size);
      if (x == NULL)
      {
         n_errors++;
			prt_log ("Allocation error for '%s', %u bytes not available.\n\n", s, size*n);
         Quit();
      }
		memory_usage += n*size;
		if (memory_usage > memory_max) memory_max = memory_usage;
      return (x);
}
#else
char* alloc (char*& x, int size, int n)
{
      x = (char*)malloc (n*size);
      if (x == NULL)
      {
         n_errors++;
			prt_log ("Allocation error, %u bytes not available.\n\n", size*n);
			Quit();
      }
		memory_usage += n*size;
		if (memory_usage > memory_max) memory_max = memory_usage;
      return (x);
}
#endif

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  ralloc (char*& x, int size, int n1, int n2)
{
      x = (char*)realloc (x, size*n2);
		memory_usage -= (n1-n2)*size;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  frea  (char*& x, int size, int n)
{
      free (x);
		memory_usage -= n*size;
      x = NULL;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int  fastcmp (int *a, int *b, int n)
{
      int i;
      for (i = 0; i < n; i++)
      {
         if (a[i] != b[i]) return (0);
      }
      return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  fastcpy (int *a, int *b, int n)
{
      int i;
      for (i = 0; i < n; i++) b[i] = a[i];
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  fastini (int v, int *b, int n)
{
      int i;
      for (i = 0; i < n; i++) b[i] = v;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   fastmrg (int *a, int *b, int n)
{
      int i;
      for (i = 0; i < n; i++)
      {
         if (a[i] == 0)    continue;
         if (a[i] == b[i]) continue;
         if (b[i] != 0)    return (0);
         b[i] = a[i];
      }
      return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  fastor (int *a, int *b, int n)
{
      int i;
      for (i = 0; i < n; i++) b[i] |= a[i];
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //

void  fix_backslash (char *in) // Change \\ to \ in place.
{
      char *out = in;
      while (*in != 0)
      {
         if (*in == '\\' && *(in+1) == '\\') in++;
         *out++ = *in++;
      }
      *out = 0;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   symlen (int s, char** term_name, char** head_name)
{
      int L;
      if (s >= 0) L = (int)strlen (term_name [s]);
      else        L = (int)strlen (head_name [-s]);
      return (L);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int	sqrt (int n) // Not very efficient.
{
		int r;
		for (r = 1; r < 65535; r++)
		{
			if (r*r >= n) return (r);
		}
		return (65535);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    number - put commas into number (12,345,002)    							  //

void  number (int x, char* string)
{
		int i, j, k;
		char buff[16];
		sprintf (buff, "%d\0", x);
		k = (int)strlen (buff);
		i = k + (k-1)/3;
		string[i--] = 0;
		j = 0;
		while (1)
		{
			string[i--] = buff[--k];
			if (k == 0) break;
			if (++j % 3 == 0) string[i--] = ',';
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    SORT - Sort one vector.

void  SORT (int *start, int *end) /* Integer bubble sort. */
{
	// Sort in place, destroys the original order.
      int *p, *q, x;

      end--;
      p = start;
      while (p < end)
      {
         x = *(q = ++p);
         do
         {
            if (x < *--q)
            {
               *(q+1) = *q;
               *q = x;
            }
            else break;
         }
         while (q > start);
      }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    SORT2 - Sort one vector of length n.                                   //

void  SORT2 (int* value, int* seq, int n)
{
//    Sort in place.  Destroys the original order, but seq contains the original order.

      int *last;
      int *v1, *v2, vt;
      int *s1, *s2, st;

      if (n <= 1) return;

   // Note:  when using pointers instead of indexes,
   // we must be careful not to decrement below zero.

      last = value + n - 1;
		v1 = value;
		s1 = seq;
      while (v1 < last)			// from first to last-1
      {
			v2 = ++v1;
			s2 = ++s1;
         while (v2 > value)	// while next one > first in list.
         {
            vt = *v2--;			// save higher one into temp.
            st = *s2--;			// save higher one's index into temp.
            if (vt < *v2)		// if temp less than one above ...
            {
               *(v2+1) = *v2;		// switch these two ...
               *(s2+1) = *s2;		//	.
               *v2 = vt;			// .
               *s2 = st;			// done switching.
            }
            else break;
         }
      }
	/*	for (int i = 0; i < n; i++)
		{
			printf ("%5d %5d\n", value[i], seq[i]);
		}
	*/
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//    SORT3 - Sort three vectors of length n, see SORT2 above for explanation.

void  SORT3 (int* a, int* b, int* c, int n)
{
      int *last;
      int *a1, *a2, at;
      int *b1, *b2, bt;
      int *c1, *c2, ct;

      if (n <= 1) return;

   // Note: when using pointers instead of indexes,
   // we must be careful not to decrement below zero.

		a1 = a;
		b1 = b;
		c1 = c;
      last = a + n - 1;
      while (a1 < last)			// from first to last-1
      {
			a2 = ++a1;
			b2 = ++b1;
			c2 = ++c1;
         while (a2 > a)			// while next one > first in list.
         {
            at = *a2--;			// save higher one into temp.
            bt = *b2--;			// save other ones too.
            ct = *c2--;			// save other ones too.
            if (at < *a2)		// if temp less than one above ...
            {
               *(a2+1) = *a2;		// switch these three ...
               *(b2+1) = *b2;		//	.
               *(c2+1) = *c2;		//	.
               *a2 = at;			// .
               *b2 = bt;			// done switching.
               *c2 = ct;			// done switching.
            }
            else break;
         }
      }
/*	  	for (int i = 0; i < n; i++)
		{
			printf ("%5d %5d %5d\n", a[i], b[i], c[i]);
		}  */
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //

void  SORTNAMES (char** name, int n, int* seq)
{
   /* seq - the sorted sequence:
	         name[seq[0]] gives the first name in the sorted list.

				example:
				name[0] = "c", seq[0] = 3
				name[1] = "d", seq[1] = 2
				name[2] = "b", seq[2] = 0
				name[3] = "a", seq[3] = 1
	 */

      char **P, *P_temp;
      int  *L, L_temp, seq_temp, i, j, leng, c;

      ALLOC (P, n);
      ALLOC (L, n);
      for (i = 0; i < n; i++)
      {
         P[i]   = name[i];
         L[i]   = (int)strlen (name[i]);
         seq[i] = i;
      }
      for (i = 1; i < n; i++)	// Bubble sort algorithm.
      {
         P_temp   = P[i];
         L_temp   = L[i];
         seq_temp = seq[i];
         j        = i - 1;
         do
         {
            leng = L[j];
            if (L_temp < L[j]) leng = L_temp;
            c = strncmp (P_temp, P[j], leng);
            if (c < 0 || (c == 0 && L_temp < L[j]))
            {
               P[j+1]   = P[j];
               L[j+1]	= L[j];
               seq[j+1]	= seq[j];
               P[j]		= P_temp;
               L[j]		= L_temp;
               seq[j]	= seq_temp;
            }
            else break;
         }
         while (--j >= 0);
      }
      FREE (L, n);
      FREE (P, n);
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //

void  SORTNAMES2 (char** start, int n, int* seq, int* pos)
{
   /* seq - the sorted sequence:
	         start[seq[0]] gives the first name in the sorted list.

      pos - the position or rank in the sorted order:
				pos[0] gives the position of start[0] in the sorted list.

				example:
				start[0] = "c", seq[0] = 3, pos[0] = 2
				start[1] = "d", seq[1] = 2, pos[1] = 3
				start[2] = "b", seq[2] = 0, pos[2] = 1
				start[3] = "a", seq[3] = 1, pos[3] = 0
	 */

      char **p, *p_temp;
      int  *L, L_temp, seq_temp, i, j, leng, c;

      ALLOC (p, n);
      ALLOC (L, n);
      for (i = 0; i < n; i++)
      {
         p[i] = start[i];
         L[i] = (int)strlen (start[i]);
         seq[i] = i;
         pos[i] = i;
      }
      for (i = 1; i < n; i++)	// Bubble sort algorithm.
      {
         p_temp   = p[i];
         L_temp   = L[i];
         seq_temp = seq[i];
         j        = i - 1;
         do
         {
            leng = L[j];
            if (L_temp < L[j]) leng = L_temp;
            c = strncmp (p_temp, p[j], leng);
            if (c < 0 || (c == 0 && L_temp < L[j]))
            {
               p[j+1]         = p[j];
               L[j+1]			= L[j];
               seq[j+1]			= seq[j];
               p[j]				= p_temp;
               L[j]				= L_temp;
               seq[j]			= seq_temp;
               pos[seq[j+1]] = j+1;
               pos[seq[j]]   = j;
            }
            else break;
         }
         while (--j >= 0);
      }
      FREE (L, n);
      FREE (p, n);
}

/*--- Attach Function. -----------------------------------------------------*/

/*    Attach a Child to a Parent node to establish a relationship.
      This builds a relationship of all those items associated with
      a parent item.  This routine returns:

      1 for already attached
      0 for not previously attached
*/

int   ATTACH (int x, int y) // Attach y to x (add y to x set).
{
	/* Attach a Child to a Parent node to establish a relationship.
      This builds a relationship of all those items associated with
      a parent item.  This routine returns:
      1 for already attached
      0 for not previously attached
	*/
      int ptr, pre;
      if (f_child [x] == -1)
      {
         f_child [x] = n_childs;
      }
      else
      {
         ptr = f_child [x];
         do
         {
            if (child [ptr].numb == y) // already attached?
               return (1);
            pre = ptr;
            ptr = child [ptr].link;
         }
         while (ptr != -1);
         child [pre].link = n_childs;
      }
      if (n_childs >= max_child)
		{
			MemCrash ("Number of child nodes", max_child);
		}
      child [n_childs].numb = y;
      child [n_childs++].link = -1;
		if (n_childs > max_child_usage)
      {
         max_child_usage = n_childs;
      }
      return (0);
}

int   ATTACHED (int x, int y)
{
      int ptr;
      if (f_child [x] == -1) return (0);
      ptr = f_child [x];
      do
      {
         if (child [ptr].numb == y) return (1);
      }
      while ((ptr = child [ptr].link) != -1);
      return (0);
}

/*
Original version ...
////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//    DeRemer & Pennello's Digraph Algorithm.                                 //
//    From "Efficient Computation of LALR(1) Look-Ahead Sets."                //
//    Printed in TOPLAS, Oct 1982.                                            //
//                                                                            //
//    Modified by me (Paul Mann in 1985) because it did not work when I first //
//    implemented it, without a separate top variable.  My version turned out //
//    to be a simpler algorithm, actually! [Oct 14 2005]                      //
//                                                                            //
//    Global variables expected:                                              //
//    n_bytes, f_child, child                                                 //

      static char**  graph;     // Graph pointer.
      static int     depth;     // Depth of stack.
   // static int     top;       // Top of stack. (DeRemer's version)
      static int*    N;         // Depth value for nodes.
      static int*    S;         // Stack of node numbers.

void  T_GRAPH (char **g, int nr) // Traverse graph and do transitive closure.
{
      int x;              // Node number.
   // top   = 0;          // Top of stack. (DeRemer's version)
      depth = 0;          // Depth of tree.
      graph = g;          // Set graph pointer.
      ALLOC (N, nr);      // Allocate N, number of rows.
      ALLOC (S, (nr+1));  // Allocate S, number of rows + 1;

   // Mark nodes as not traversed.
      for (x = 0; x < nr; x++) N [x] = 0;

   // Traverse all nodes in the graph.
      for (x = 0; x < nr; x++)
      {
         if (N [x] == 0) TRAVERSE (x);
      }
      FREE (S);
      FREE (N);
}

void  TRAVERSE (int x) // Traverse node x in a graph.
{
      int i;                           // Index of a child node.
      int y;                           // Child node number.
      i = f_child [x];                 // Get first child of node x.
      if (i == -1)                     // If no children.
      {
         N [x] = 2147483647;           // Mark it as traversed.
         return;
      }
   // S [++top] = x;                   // Put x on the stack. (DeRemer's version)
   // N [x] = ++depth;                 // Depth of node x.    (DeRemer's version)
      S [++depth] = x;                 // Put x on the stack. (My version)
      N [x] = depth;                   // Depth of node x.    (My version)
      do
      {
         y = child [i].numb;           // Get child node y.
         if (N [y] == 0) TRAVERSE (y); // If node y not traversed.
         if (N [y] < N [x])            // If depth of y < depth of x,
             N [x] = N [y];            // Set depth of x to depth of y.
         FASTOR (graph [y], graph [x], n_words); // Or y set onto x set.
         i = child [i].link;              // Get next child of node x.
      }
      while (i != -1);

   // prt_lst ("N[x], depth = %d, %d\n", N[x], depth);
   // prt_lst ("S[N[x]],  x = %d, %d\n", S[N[x]],  x);
   // if (N [x] == depth)                 // Original line from DeRemer's paper.
      if (S [N [x]] == x)                 // Modification by me, originally done in 1985.
      {
         for (;;)                         // For all nodes in this cycle.
         {
         // y = S [top--];                // Get node y from stack. (DeRemer's version)
            y = S [depth--];              // Get node y from stack. (My version)
            N [y] = 2147483647;           // Mark it as traversed.
            if (y == x) break;            // If we are back to the root.
            FASTCPY (graph [x], graph [y], n_words); // Copy set x to set y.
         }
      }
   // depth--;                            // Decrement depth. (DeRemer's version)
                                          // Nothing.         (My version)
      return;
}
End of Original version.
*/

////////////////////////////////////////////////////////////////////////////////
//                                                                            //
//    DeRemer & Pennello's Digraph Algorithm.                                 //
//    From "Efficient Computation of LALR(1) Look-Ahead Sets."                //
//    Printed in TOPLAS, Oct 1982.                                            //
//                                                                            //
//    Modified by me (PBM in 1985) because it did not work when I first       //
//    implemented it, without a separate top variable.  My version turned     //
//    out to be a simpler algorithm, actually! [Oct 14 2005]                  //
//                                                                            //
//    Global variables expected:                                              //
//    f_child, child                                                          //

      static char**  graph;     // Graph pointer.
      static int     top;       // Top of stack. (DeRemer's version)
      static int     depth;     // Depth of stack.
      static int     nw;        // Number of 32-bit words.
      static int*    N;         // Depth value for nodes.
      static int*    S;         // Stack of node numbers.

void  T_GRAPH (char **g, int nr, int nc) // Traverse graph, do transitive closure.
{
      int x;            // Node number.
      top   = 0;        // Top of stack. (DeRemer's version)
      depth = 0;        // Depth of tree.
      graph = g;        // Set graph pointer.
		nw = (nc + 3)/4;  // Number of 4-byte words.
      ALLOC (N, nr);    // Allocate N, number of rows.
      ALLOC (S, nr+1);	// Allocate S, number of rows + 1;

   // Mark nodes as not traversed.
      for (x = 0; x < nr; x++) N [x] = 0;

   // Traverse all nodes in the graph.
      for (x = 0; x < nr; x++)
      {
         if (N [x] == 0) TRAVERSE (x);
      }
      FREE (S, nr+1);
      FREE (N, nr);
}

void  TRAVERSE (int x) // Traverse node x in a graph.
{
      int i;                           // Index of a child node.
      int y;                           // Child node number.
      i = f_child [x];                 // Get first child of node x.
      if (i == -1)                     // If no children.
      {
         N [x] = 2147483647;           // Mark it as traversed.
         return;
      }
      S [++top] = x;                   // Put x on the stack. (DeRemer's version)
      N [x] = ++depth;                 // Depth of node x.    (DeRemer's version)
   // S [++depth] = x;                 // Put x on the stack. (My version)
   // N [x] = depth;                   // Depth of node x.    (My version)
      do
      {
         y = child [i].numb;                 // Get child node y.
         if (N [y] == 0) TRAVERSE (y);       // If node y not traversed.
         if (N [y] < N [x])                  // If depth of y < depth of x,
             N [x] = N [y];                  // Set depth of x to depth of y.
         FASTOR (graph [y], graph [x], nw);  // Or y set onto x set.
         i = child [i].link;                 // Get next child of node x.
      }
      while (i != -1);
      if (N [x] == depth)                    // Original line from DeRemer's paper.
   // if (S [N [x]] == x)                    // Modification by me, originally done in 1985.
      {
         for (;;)                            // For all nodes in this cycle.
         {
            y = S [top--];                   // Get node y from stack. (DeRemer's version)
         // y = S [depth--];                 // Get node y from stack. (My version)
            N [y] = 2147483647;              // Mark it as traversed.
            if (y == x) break;                  // If we are back to the root.
            FASTCPY (graph [x], graph [y], nw); // Copy set x to set y.
         }
      }
      depth--;                               // Decrement depth. (DeRemer's version)
}

void  P_GRAPH (char** graph, int nr, int nc) // Print graph.
{
      int r, c;
      printf ("\nGraph [%d x %d]\n", nr, nc);
		printf ("     ");
      for (c = 0; c < nc; c++)
      {
         printf ("%3d", c);
		}
      printf ("\n");
      for (r = 0; r < nr; r++)
      {
         printf ("%3d: ", r);
         for (c = 0; c < nc; c++)
         {
            if (graph[r][c])    printf ("  1");
				else                printf ("  0");
         }
	      printf ("\n");
      }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  SORTNUMBS (int* numb, int n, int* seq)
{
		/* seq - the sorted sequence:
					numb[seq[0]] gives the first number in the sorted list.

			example:
					numb[0] = "c", seq[0] = 3
					numb[1] = "d", seq[1] = 2
					numb[2] = "b", seq[2] = 0
					numb[3] = "a", seq[3] = 1
		*/
		int i, j, numb_temp, seq_temp;

      for (i = 1; i < n; i++)	// Bubble sort algorithm.
      {
         numb_temp = numb[i];
         seq_temp  = seq[i];
         j = i - 1;
         do
         {
            if (numb_temp < numb[j])
            {
               numb[j+1]     = numb[j];
               seq[j+1]		  = seq[j];
               numb[j]		  = numb_temp;
               seq[j]		  = seq_temp;
            }
            else break;
         }
         while (--j >= 0);
      }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  SORTNUMBS2 (int* numb, int n, int* seq, int* pos)
{
   /* seq - the sorted sequence:
	         numb[seq[0]] gives the first number in the sorted list.

      pos - the position or rank in the sorted order:
				pos[0] gives the position of numb[0] in the sorted list.

		example:
				numb[0] = "c", seq[0] = 3, pos[0] = 2
				numb[1] = "d", seq[1] = 2, pos[1] = 3
				numb[2] = "b", seq[2] = 0, pos[2] = 1
				numb[3] = "a", seq[3] = 1, pos[3] = 0
	 */
		int i, j, numb_temp, seq_temp;

      for (i = 0; i < n; i++) { seq[i] = i; pos[i] = i; }

      for (i = 1; i < n; i++)	// Bubble sort algorithm.
      {
         numb_temp = numb[i];
         seq_temp  = seq[i];
         j = i - 1;
         do
         {
            if (numb_temp < numb[j])
            {
               numb[j+1]     = numb[j];
               seq[j+1]		  = seq[j];
               numb[j]		  = numb_temp;
               seq[j]		  = seq_temp;
               pos[seq[j+1]] = j+1;
               pos[seq[j]]   = j;
            }
            else break;
         }
         while (--j >= 0);
      }
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   open_log (char* fid)
{
		int i = (int)strlen (fid);
      strcat (fid, ".log.txt");
   // chmod  (fid, S_IWRITE);
  		logfp = fopen (fid, "w");
		if (logfp == NULL)
		{
			printf ("Log file %s cannot be created.\n", fid);
			fid[i] = 0;
			return (0);
		}
		fid[i] = 0;
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   close_log ()
{
		if (logfp != NULL) fclose (logfp);
		logfp = NULL;
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  prt_log (char *format,...) // Print both on screen and to log file (if not quiet option).
{
      va_list argptr;
      va_start (argptr, format);
	   vprintf (format, argptr); // Print on screen.
		va_end (argptr);
		if (logfp != NULL)
		{
			va_start (argptr, format);
			vfprintf (logfp, format, argptr); // Print in log file.
			va_end (argptr);
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  prt_logonly (char *format,...) // Print only to the log file (not on screen).
{
      va_list argptr;
		if (logfp != NULL)
		{
			va_start (argptr, format);
			vfprintf (logfp, format, argptr); // Print in log file.
			va_end (argptr);
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   open_con (char* fid)
{
		int i = (int)strlen(fid);
		strcat(fid, ".conflicts.txt");
	// chmod  (fid, S_IWRITE);
		confp = fopen(fid, "w");
		if (confp == NULL)
		{
			prt_log("Conflict listing file %s cannot be created.\n", fid);
			fid[i] = 0;
			return (0);
		}
		fid[i] = 0;
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   close_con()
{
		if (confp != NULL) fclose(confp);
		confp = NULL;
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  prt_con (char *format, ...)
{
		va_list argptr;
		if (confp != NULL)
		{
			va_start(argptr, format);
			vfprintf(confp, format, argptr);
			va_end(argptr);
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   open_grm (char* fid)
{
		int i = (int)strlen (fid);
      strcat (fid, ".grammar.txt");
   // chmod (fid, S_IWRITE);
      grmfp = fopen (fid, "w");
      if (grmfp == NULL)
      {
         prt_log ("Grammar listing file %s cannot be created.\n", fid);
			fid[i] = 0;
         return (0);
      }
		fid[i] = 0;
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   close_grm ()
{
		if (grmfp != NULL) fclose (grmfp);
		grmfp = NULL;
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   prt_grm (char *format,...)
{
		if (option_grammar == 0) return 0;
      int length = 0;
      va_list argptr;
		if (grmfp != NULL)
		{
	      va_start (argptr, format);
		   length = vfprintf (grmfp, format, argptr);
			va_end (argptr);
		}
      return length;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   open_sta (char* fid)
{
		int i = (int)strlen (fid);
      strcat (fid, ".states.txt");
   // chmod (fid, S_IWRITE);
      stafp = fopen (fid, "w");
      if (stafp == NULL)
      {
         prt_log ("States listing file %s cannot be created.\n", fid);
			fid[i] = 0;
         return (0);
      }
		fid[i] = 0;
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   close_sta ()
{
		if (stafp != NULL) fclose (stafp);
		stafp = NULL;
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  prt_sta (char *format,...)
{
      va_list argptr;
   // Print to state listing file.
		if (stafp != NULL)
		{
	      va_start (argptr, format);
		   vfprintf (stafp, format, argptr);
			va_end (argptr);
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   open_warn (char* fid)
{
		int i = (int)strlen (fid);
      strcat (fid, ".warnings.txt");
   // chmod (fid, S_IWRITE);
      lstfp = fopen (fid, "w");
      if (lstfp == NULL)
      {
         prt_log ("Warning file '%s' cannot be created.\n", fid);
			fid[i] = 0;
         return (0);
      }
      prt_warn ("\n");
		fid[i] = 0;
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   close_warn ()
{
		if (lstfp != NULL)
		{
			if (n_warnings == 1) prt_warn ("%d warning.\n", n_warnings);
			else                 prt_warn ("%d warnings.\n", n_warnings);
			fclose (lstfp);
			lstfp = NULL;
		}
		return (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  prt_warn (char *format,...)
{
      va_list argptr;
//    va_start (argptr, format);
//    vprintf (format, argptr); // Print on screen.
//		va_end (argptr);
//    Print to listing file.
		if (lstfp != NULL)
		{
	      va_start (argptr, format);
		   vfprintf (lstfp, format, argptr);
			va_end (argptr);
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  prt_num (char* desc, int n, char* name, int max)
{
      char bar [11] = "**********";
		char num [14] = "             ";
		char num2[14] = "             ";
		double pc;
		if (max == 0) pc = 0;
      else pc = 100.0*n/max;
      bar[(int)pc/10] = 0;
	  	number (n, num);
	  	number (max, num2);
      prt_logonly ("%-32s  %-4s = %9s/%10s  %3.0f%% %s\n", desc, name, num, num2, pc, bar);
      bar[(int)pc/10] = '*';
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int   inputi (char* Msg)
{
      int nb;												/* Number of bytes read.      */
		filedesc = open (grmfid, 0);					/* Open the file.             */
		if (filedesc < 0)									/* If open error.             */
		{
         if (*Msg != 0)
         {
		   	n_errors++;
            prt_log ("%s: %s.\n", Msg, grmfid);
         }
         return 0;
      }
		filesize = _filelength (filedesc);

		ALLOC (input_start, filesize + 10);
		*input_start++ = '\n';                    // Put EOL at the beggining.

		nb = read (filedesc, input_start, filesize);
		if (nb <= 0)                           	// If read error.
		{
			n_errors++;
			prt_log ("Read error on file %s, or it's empty.\n\n", grmfid);
			return 0; // Error
		}

		input_end = input_start + nb;					// Set end-of-buffer pointer.
		*input_end++ = '\n';
		*input_end++ = 26;								// Parser needs 2 EOFs.
		*input_end++ = 26;
		*input_end++ = 0;									// ??
		close (filedesc);									// Close input file.

		n_lines = 0;
		char* p = input_start;
		while (*p != EOF_CHAR)
		{
			while (*p != '\n') p++;
			n_lines++;
			p++;
		}
		ALLOC (line_ptr, n_lines+5);  // Allow extra lines at end.
		for (int i = 0; i < n_lines+5; i++)
		{
			line_ptr[i] = NULL;
		}
		return 1; // OK
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  inputt (void)
{
		if (input_start != NULL)
		{
			input_start--;
			FREE (input_start, filesize+10);	// Free input buffer space.
  	  		FREE (line_ptr, n_lines+5);
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  prt_error (char* msg, char* start, char* end, int linenum)
{
		if (++n_errors == 1) prt_log ("\n");
		if (start != NULL && end == NULL)
		{
			for (end = start; *end != 0; end++);
		}
		prt_message ("Error, ", msg, start, end, linenum);
		if (n_errors >= max_errors)
		{
			prt_log ("Maximum number of errors (%d) has been reached.\n", max_errors);
			Quit();
		}
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  prt_warning (char* msg, char* start, char* end, int linenum)
{
		n_warnings++;
		if (start != NULL && end == NULL)
		{
			for (end = start; *end != 0; end++);
		}
		prt_message ("Warning, ", msg, start, end, linenum);
/*		if (n_warnings >= max_errors)
		{
			printf  ("Maximum number of warnings (%d) has been reached.\n", max_errors);
			prt_warn ("Maximum number of warnings (%d) has been reached.\n", max_errors);
			Quit();
		}	*/
}

////////////////////////////////////////////////////////////////////////////////
//                                                                            //

void  prt_message (char* msgtype, char* msg, char* tokenstart, char* tokenend, int tokenlinenumb)
{
      char  c;
      char* p;					// char pointer.
      char* q;					// char pointer.
      int   i;					// Start of token.
      int   j;					// End of token.
      int   k;					// End of token.
      int   column;			// column where token starts.
		char* linestart;		// Line start pointer.
		char* lineend = 0;	// Line end pointer.
		char  line[10000];	// Line string to be printed.
		int   linelength;		// Line length.
		int   tokenlength;	// Token length.

	// Check line number ...
		if (tokenlinenumb > 0) // Line number defined?
		{
			linestart = line_ptr [tokenlinenumb];							// Get Line start.
 			if (linestart >= input_start || linestart < input_end)	// Line start in input buffer?
			{
				for (lineend = linestart; *lineend != '\n'; lineend++);
				lineend++;
			}
			else linestart = NULL;
		}
		else linestart = NULL;

	// Check token ...
		if (tokenstart != NULL) // Token start looks OK.
		{
		// Check token start ...
   		if (tokenstart >= input_start && tokenstart < input_end) // Token is in input buffer?
			{
				if (linestart == NULL)											// Get line start from token.
				{
				// Get line start ...
					for (linestart = tokenstart-1; *linestart != '\n'; linestart--);
					for (lineend   = tokenstart;   *lineend   != '\n'; lineend++  );
					linestart++;	// Line start.
					lineend++;		// Line start of next line.

				// Get line number ...
					tokenlinenumb = 0; // Maybe this should be 1, so double click will go to file.
					for (i = 1; i < n_lines; i++) // Not fast, could make this a binary search, later.
					{
						if (line_ptr[i] == linestart)
						{
							tokenlinenumb = i;
							break;
						}
					}
				}
			}
		// Check token end ...
			if (tokenend < tokenstart) // token end is NULL or bad?
			{
				for (tokenend = tokenstart; *tokenend != 0; tokenend++);
			}
		}

	// Check line start ...
		if (linestart != NULL)
		{
			if (lineend > linestart + 9999) lineend = linestart + 9999;

		// Remove trailing whitespace.
			lineend--;															// Backup to '\n'
			if (*lineend == '\n') lineend--;								// If '\n' backup again.
			while (*lineend == ' ' || *lineend == '\t') lineend--;// Backup to first non-blank.
			if (lineend < linestart) lineend = linestart;			// In case of blank line (?).
			lineend++;															// Point at '\n' or next character.

		// Make line ...
			i = 0;
			for (p = linestart; p < lineend; p++)						// Scan to end of line.
			{
				if (*p == '\t') line[i++] = ' ';							// Move space, not tab.
				else            line[i++] = *p;							// Move character to line.
			}
			line[i] = 0;

		// Print line.
			if (*msgtype == 'W')
			{
				if (option_warnings)
				   printf   ("%s(%04d) : %s\n", grmfid, tokenlinenumb, line);
				   prt_warn ("%s(%04d) : %s\n", grmfid, tokenlinenumb, line);
			}
			else  prt_log ("%s(%04d) : %s\n", grmfid, tokenlinenumb, line);

		// See if token is outside this line ...
			if (tokenstart < linestart || tokenstart >= lineend)
			{
				if (tokenstart != NULL)												// Token is not null?
				{
				// Find first match in this line ...
					tokenlength = (int)(tokenend - tokenstart);						// Get token length.
					for (p = linestart; p < lineend; p++)						// Scan to end of line.
					{
						if (*p == *tokenstart)										// First characters match?
						{
							int len = tokenlength;
							if (len > lineend-p) len = (int)(lineend-p);
							if (strncmp (p, tokenstart, len) == 0)				// Whole tokens match?
							{
								tokenstart = p;										// Set tokenstart to p in this line.
								tokenend   = p + len;								// Set tokenend.
								goto Ptr;												// Go print pointer and message.
							}
						}
					}
				}

			// Token is NULL or not found in line.
				column = (int)(lineend - linestart);
				for (i = 0; i < column; i++) line[i] = '.';
				line[i] = 0;
				if (*msgtype == 'W')
				{
					if (option_warnings)
					   printf   ("%s(%04d) : %s\n", grmfid, tokenlinenumb, line);
					   prt_warn ("%s(%04d) : %s\n", grmfid, tokenlinenumb, line);
				}
				else  prt_log ("%s(%04d) : %s\n", grmfid, tokenlinenumb, line);
			}
			else
			{
			// Make pointer ...
		Ptr:	if (tokenend > lineend) tokenend = lineend;
				linelength  = (int)(lineend - linestart);
				tokenlength = (int)(tokenend - tokenstart);
				column      = (int)(tokenstart - linestart);								// Column number for token start.
				for (i = 0;   i < column;      i++) line[i]   = '.';
				for (j = 0;   j < tokenlength; j++) line[i+j] = '^';
				for (k = i+j; k < linelength;  k++) line[k]   = '.';
				line[k] = 0;
				if (*msgtype == 'W')
				{
					if (option_warnings)
					   printf   ("%s(%04d) : %s\n", grmfid, tokenlinenumb, line);
                  prt_warn ("%s(%04d) : %s\n", grmfid, tokenlinenumb, line);
				}
				else  prt_log ("%s(%04d) : %s\n", grmfid, tokenlinenumb, line);
			}
		}

	// Print message ...
		char MsgType[32];
		strcpy (MsgType, msgtype);
    	if (tokenstart != NULL)
		{
			if (tokenend > tokenstart + 30) tokenend = tokenstart + 30;
			c = *tokenend;
			*tokenend = 0;
			sprintf (line, msg, tokenstart);
			*tokenend = c;
		}
      else // Token is NULL
		{
			sprintf (line, msg, tokenstart);
		}
		p = line;
		char* end = "\n";
		do
		{
			for (q = p; *q != 0 && *q != '\n'; q++); // Find 0 or '\n'
			c = *q;
			*q = 0;
			if (c == 0) end = ".\n\n"; // Last time?
			if (*msgtype == 'W')
			{
				if (option_warnings)
					printf   ("%s(%04d) : %s%s%s", grmfid, tokenlinenumb, MsgType, p, end);
					prt_warn ("%s(%04d) : %s%s%s", grmfid, tokenlinenumb, MsgType, p, end);
			}
			else  prt_log ("%s(%04d) : %s%s%s", grmfid, tokenlinenumb, MsgType, p, end);
			*q++ = c;
			p = q;
			*MsgType = 0; // Only print "Error:" on the first line.
		}
		while (c == '\n');
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
/*
void  C_FIRSTNT () // Compute First Nonterminal Set (not used)
{
      int h, p, s, t;
		n_words = (N_heads +  3)/4;   // Number of 4-byte words.
      n_bytes = 4*n_words;				// Number of bytes to allocate.
      ALLOC (FIRSTNT, N_heads);
      for (h = 0; h < N_heads; h++)
      {
         ALLOC (FIRSTNT[h], n_bytes);
         memset (FIRSTNT[h], 0, n_bytes);
      }

      for (h = 0; h < N_heads; h++)
      {
         for (p = F_prod[h]; p < F_prod[h+1]; p++)
         {
            t = F_tail[p];
Next:       if (t < F_tail[p+1])
            {
               if ((s = Tail[t]) < 0)
               {
                  FIRSTNT[h][-s] = 1;
                  if (nullable[-s])
                  {
                     t++;
                     goto Next;
                  }
               }
            }
         }
      }

      n_childs = 0;
      ALLOC (f_child, N_heads);
      ALLOC (child, max_child);

      for (h = 0; h < N_heads; h++) f_child [h] = -1;
      for (p = 0; p < N_prods; p++)
      {
         h = head_sym [p];
         t = F_tail [p];
Nxt:     if (t < F_tail [p+1])
         {
            if ((s = Tail [t]) < 0)
            {
               if (h != -s) ATTACH (h, -s);
               if (nullable [-s])
               {
                  t++;
                  goto Nxt;
               }
            }
         }
      }
      T_GRAPH (FIRSTNT, N_heads, N_heads);
      FREE (child, max_child);
      FREE (f_child, N_heads);
   // P_FIRST ();
}
*/
///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  C_EQUIVALENCE_N (int n_heads, int* f_prod, int* f_tail, int* tail, char**& EQUIVALENCE)
{
      int h, p, s, t;
		int n_words, n_bytes;

		n_words = (n_heads +  3)/4;   // Number of 4-byte words.
      n_bytes = 4*n_words;				// Number of bytes to allocate.
      ALLOC (EQUIVALENCE, n_heads);
      for (h = 0; h < n_heads; h++)
      {
         ALLOC  (EQUIVALENCE[h], n_bytes);
         memset (EQUIVALENCE[h], 0, n_bytes);
      }
      for (h = 0; h < n_heads; h++) // for all heads.
      {
         for (p = f_prod[h]; p < f_prod[h+1]; p++) // for all prod.
         {
            if (f_tail[p+1]-f_tail[p] == 1) // unit production?
            {
               t = f_tail[p];
               s = tail[t];
               if (s < 0) // nonterminal?
               {
						EQUIVALENCE[h][-s] = 1;
               }
            }
         }
      }
      n_childs = 0;
      ALLOC (f_child, n_heads);
      ALLOC (child, max_child);
      for (h = 0; h < n_heads; h++) f_child [h] = -1;
      for (h = 0; h < n_heads; h++) // for all heads.
      {
         for (p = f_prod[h]; p < f_prod[h+1]; p++) // for all prod.
         {
            if (f_tail[p+1]-f_tail[p] == 1) // unit production?
            {
               t = f_tail[p];
               s = tail[t];
               if (s < 0) // nonterminal?
               {
                  if (h != -s) ATTACH (h,-s);
               }
            }
         }
      }
      T_GRAPH (EQUIVALENCE, n_heads, n_heads);
      FREE (child, max_child);
      FREE (f_child, n_heads);
   // P_EQUIVALENT ();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  C_EQUIVALENCE_T (int n_heads, int N_terms, int* f_prod, int* f_tail, int* tail, char**& EQUIVALENCE)
{
      int h, p, s, t;
		int n_words, n_bytes;

		n_words = (N_terms +  3)/4;   // Number of 4-byte words.
      n_bytes = 4*n_words;				// Number of bytes to allocate.
      ALLOC (EQUIVALENCE, n_heads);
      for (h = 0; h < n_heads; h++)
      {
         ALLOC  (EQUIVALENCE[h], n_bytes);
         memset (EQUIVALENCE[h], 0, n_bytes);
      }
      for (h = 0; h < n_heads; h++) // for all heads.
      {
         for (p = f_prod[h]; p < f_prod[h+1]; p++) // for all prod.
         {
            if (f_tail[p+1]-f_tail[p] == 1) // unit production?
            {
               t = f_tail[p];
               s = tail[t];
               if (s >= 0) // terminal?
               {
                  EQUIVALENCE[h][s] = 1;
               }
            }
         }
      }
      n_childs = 0;
      ALLOC (f_child, n_heads);
      ALLOC (child, max_child);
      for (h = 0; h < n_heads; h++) f_child [h] = -1;
      for (h = 0; h < n_heads; h++) // for all heads.
      {
         for (p = f_prod[h]; p < f_prod[h+1]; p++) // for all prod.
         {
            if (f_tail[p+1]-f_tail[p] == 1) // unit production?
            {
               t = f_tail[p];
               s = tail[t];
               if (s < 0) // nonterminal?
               {
                  if (h != -s) ATTACH (h,-s);
               }
            }
         }
      }
      T_GRAPH (EQUIVALENCE, n_heads, N_terms);
      FREE (child, max_child);
      FREE (f_child, n_heads);
   // P_EQUIVALENT ();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  C_FIRST (int n_heads, int N_terms, int* f_prod, int* f_tail, int* tail, char**& FIRST, int* nullable)
{
      int h, p, s, t;
		int n_words, n_bytes;

		n_words = (N_terms +  3)/4;   // Number of 4-byte words.
      n_bytes = 4*n_words;				// Number of bytes to allocate.

      ALLOC (FIRST, n_heads);
      for (h = 0; h < n_heads; h++)
      {
         ALLOC (FIRST[h], n_bytes);
         memset (FIRST[h], 0, n_bytes);
      }
      for (h = 0; h < n_heads; h++)
      {
         for (p = f_prod[h]; p < f_prod[h+1]; p++)
         {
            t = f_tail[p];
Next:       if (t < f_tail[p+1])
            {
               if ((s = tail[t]) < 0)
               {
                  if (nullable[-s])
                  {
                     t++;
                     goto Next;
                  }
               }
               else
					{
						FIRST[h][s] = 1;
					}
            }
         }
      }
      n_childs = 0;
      ALLOC (f_child, n_heads);
      ALLOC (child, max_child);

      for (h = 0; h < n_heads; h++) f_child [h] = -1;
      for (h = 0; h < n_heads; h++) // for all heads.
      {
         for (p = f_prod[h]; p < f_prod[h+1]; p++) // for all prod.
         {
            t = f_tail [p];
Nxt:        if (t < f_tail [p+1])
            {
               s = tail [t];
               if (s < 0)
               {
                  if (h != -s) ATTACH (h, -s);
                  if (nullable [-s])
                  {
                     t++;
                     goto Nxt;
                  }
               }
            }
         }
      }
      T_GRAPH (FIRST, n_heads, N_terms);
      FREE (child, max_child);
      FREE (f_child, n_heads);
   // P_FIRST ();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  C_FOLLOW (int n_heads, int N_terms, int* f_prod, int* f_tail, int* tail, char**  FIRST, char**& FOLLOW, int* nullable)
{
      int h, p, s, t, N, T;
		int n_words, n_bytes;

		n_words = (N_terms +  3)/4;   // Number of 4-byte words.
      n_bytes = 4*n_words;				// Number of bytes to allocate.

      ALLOC (FOLLOW, n_heads);
      for (h = 0; h < n_heads; h++)
      {
         ALLOC (FOLLOW[h], n_bytes);
         memset (FOLLOW[h], 0, n_bytes);
      }

      for (h = 0; h < n_heads; h++)    // For all heads.
      {
         for (p = f_prod [h]; p < f_prod [h+1]; p++) // For all productions.
         {
            for (t = f_tail [p]; t < f_tail[p+1]; t++) // For all tails.
            {
               if ((s = tail [t]) < 0) // If nonterminal
               {
                  N = -s;
                  T = t + 1;
Next:             if (T < f_tail[p+1])
                  {
                     if ((s = tail[T]) < 0) // Next one is nonterminal?
                     {
                        FASTOR (FIRST[-s], FOLLOW[N], n_words);
                        if (nullable[-s]) { T++; goto Next; }
                     }
                     else
							{
								FOLLOW[N][s] = 1;
							}
                  }
               }
            }
         }
      }

      n_childs = 0;
      ALLOC (f_child, n_heads);
      ALLOC (child, max_child);

      for (h = 0; h < n_heads; h++) f_child [h] = -1;
      for (h = 0; h < n_heads; h++) // for all heads.
      {
         for (p = f_prod[h]; p < f_prod[h+1]; p++) // for all prod.
         {
            t = f_tail[p+1]-1;         // Last Tail.
Nxt:        if (t >= f_tail[p])
            {
               if ((s = tail [t]) < 0) // If nonterminal
               {
                  if (h != -s)
                  {
                     ATTACH (-s, h);
                  // prt_con ("%s <- %s\n", head_name[-s], head_name[h]);
                  }
                  if (nullable[-s])
                  {
                     t--;
                     goto Nxt;
                  }
               }
            }
         }
      }
      T_GRAPH (FOLLOW, n_heads, N_terms);
      FREE (child, max_child);
      FREE (f_child, n_heads);
   // P_FOLLOW ();
}

#ifdef _DEBUG
///////////////////////////////////////////////////////////////////////////////
//																									  //
//		Print First Set.

void  P_FIRST (int n_heads, int N_terms, char** FIRST, char** term_name, char** head_name)
{
      int h, t;

      printf ("First Set ...\n");
      for (h = 0; h < n_heads; h++)
      {
         printf ("   ");
         if (h == 0) prt_con ("%s:\n", head_name[0]);
         else prt_sym (-h, ":\n", term_name, head_name);
         for (t = 0; t < N_terms; t++)
         {
				if (FIRST[h][t])				// If t is in FIRST set?
            {
               printf ("      ");
               prt_sym (t, "\n", term_name, head_name);
            }
         }
      }
      printf ("\n");
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//		Print Follow Set.

void  P_FOLLOW (int n_heads, int N_terms, char** FOLLOW, char** term_name, char** head_name)
{
      int h, t;
      printf ("Follow Set ...\n");
      for (h = 0; h < n_heads; h++)
      {
         printf ("   ");
         if (h == 0) prt_con ("%s:\n", head_name[0]);
         else prt_sym (-h, ":\n", term_name, head_name);
         for (t = 0; t < N_terms; t++)
         {
				if (FOLLOW[h][t])				// If t is in FIRST set?
            {
               printf ("      ");
               prt_sym (t, "\n", term_name, head_name);
            }
         }
      }
      printf ("\n");
}
#endif

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

int	prt_sym (int s, char *sp, char** term_name, char** head_name)
{
		int len;
      char *p;
      if (s >= 0)                 /* Terminal symbol? */
         p = term_name[s];
      else                        /* Nonterminal symbol? */
         p = head_name[-s];

      prt_sta ("%s%s", p, sp);
		len = (int)strlen(p) + (int)strlen(sp);
		return (len);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//		Best algorithm for space usage (does not need predefined Cameto).

void  C_CAMEFROM (int   N_states,
						int*  tt_start,
						int*  tt_action,
						int*  ntt_start,
						int*  ntt_action,
						int*& f_camefrom,
						int*& camefrom)
{
      int* n_cameto;
      int  s, i, x, n, sum;

      ALLOC (n_cameto, N_states+1);
      FASTINI (0, n_cameto, N_states+1);

   // Count the number of cameto's for each state.
		n_cameto[0] = 0;
      for (s = 0; s < N_states; s++)
      {
         for (i = tt_start[s]; i < tt_start[s+1]; i++)
         {
            x = tt_action[i];					// x = goto state.
            if (x > 0) n_cameto[x+1]++;	// Increment number of transition to this state.
         }
         for (i = ntt_start[s]; i < ntt_start[s+1]; i++)
         {
            x = ntt_action[i];					// x = goto state.
            if (x > 0) n_cameto[x+1]++;	// Increment number of transition to this state.
         }
      }

   // Define the first camefrom index for each state.
      n = sum = 0;
		f_camefrom = n_cameto;					// f_camefrom uses same space as n_cameto!
      for (x = 0; x < N_states; x++)		// For all goto states.
      {
         sum += n;								// Increment sum by number of cameto's from last state.
         n = n_cameto[x+1];					// Save number of cameto's.
         f_camefrom[x+1] = sum;				// Define first camefrom, sum of all previous states.
      }
      sum += n;

   // Populate the camefrom list using the first camefrom indexes.
      ALLOC (camefrom, sum);
      for (s = 0; s < N_states; s++)
      {
         for (i = tt_start[s]; i < tt_start[s+1]; i++)
         {
            x = tt_action[i];
            if (x > 0) camefrom [f_camefrom[x+1]++] = s;
         }
         for (i = ntt_start[s]; i < ntt_start[s+1]; i++)
         {
            x = ntt_action[i];
            if (x > 0) camefrom [f_camefrom[x+1]++] = s;
         }
      }
}

void  Quit ()
{
		#ifdef _DEBUG
	//	printf ("Terminating\n");
		#endif
      inputt ();
      LG::Terminate ();
		close_log ();
		exit (1);
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //

void  SORTSYMB (int *s, char *start[], int n)
{
      char **p, *p2;
      int   *L, L2, s2, i, j, leng, c;

      ALLOC (p, n);
      ALLOC (L, n);

   // Define 's' array, sequence of items.
      for (i = 0; i < n; i++)
      {
         p[i] = start [i];
         L[i] = (int)strlen (p[i]);
         if (p[i][0] == '\'' || p[i][0] == '\"') // Quote (')?
         {
            p[i] += 1;
            L[i] -= 2;
         }
         s[i] = i;
      }

   // Do bubble sort, 's' array will contain the sorted sequence.
      for (i = 1; i < n; i++)
      {
         p2 = p[i];
         L2 = L[i];
         s2 = s[i];
         j  = i - 1;
         do
         {
            leng = L[j];
            if (L2 < L[j]) leng = L2;
            c = strncmp (p2, p[j], leng);
            if (c < 0 || (c == 0 && L2 < L[j]))
            {
               p[j+1] = p[j];
               p[j]   = p2;
               L[j+1] = L[j];
               L[j]   = L2;
               s[j+1] = s[j];
               s[j]   = s2;
            }
            else break;
         }
         while (--j >= 0);
      }

      FREE (L, n);
      FREE (p, n);
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//																																 //

char* get_typestr (int* x, int n)
{
		int i, max = 0, min = 0;
		for (i = 0; i < n; i++)
		{
			if (x[i] > max) max = x[i];
			else if (x[i] < min) min = x[i];
		}
		if (min >= 0)
		{
			if      (max <=        127) return ("uchar"  ); // 1 byte
			else if (max <=        255) return ("uchar"  ); // 1 byte
			else if (max <=      32767) return ("ushort" ); // 2 bytes
			else if (max <=      65535) return ("ushort" ); // 2 bytes
			else if (max <= 2147483647) return ("uint"   ); // 4 bytes
			else                        return ("uint"   ); // 4 bytes
		}
		else if (max > -min)
      {
			if      (max <=        127) return ("char"   ); // 1 byte
			else if (max <=      32767) return ("short"  ); // 2 bytes
			else                        return ("int"    ); // 4 bytes
      }
		else
		{
			if      (min >=       -127) return ("char"   ); // 1 byte
			else if (min >=     -32767) return ("short"  ); // 2 bytes
			else                        return ("int"    ); // 4 bytes
		}
		return (""); // never gets here, avoid compiler error.
}

///////////////////////////////////////////////////////////////////////////////////////////////////
//																																 //

int   get_typesize (int *x, int n)
{
		int i, max = 0, min = 0;
		for (i = 0; i < n; i++)
		{
			if      (x[i] > max) max = x[i];
			else if (x[i] < min) min = x[i];
		}
		if (min == 0)
		{
			if      (max <=        255) return (1); // 1 byte
			else if (max <=      65535) return (2); // 2 bytes
			else                        return (4); // 4 bytes
		}
		else if (max > -min)
      {
			if      (max <=        127) return (1); // 1 byte
			else if (max <=      32767) return (2); // 2 bytes
			else                        return (4); // 4 bytes
      }
		else
		{
			if      (min >=       -127) return (1); // 1 byte
			else if (min >=     -32767) return (2); // 2 bytes
			else                        return (4); // 4 bytes
		}
		return (0); // never gets here.
}

//                                                                           //
///////////////////////////////////////////////////////////////////////////////

