
/////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                 //
//    LRSTAR Main Header

      #pragma once
      #include "stdio.h"

      #ifndef _WIN32
      #define _read     read
      #define _write    write
      #define _open     open
      #define _close    close
      #define _chmod    chmod
      #define _unlink   unlink
      #endif

      extern FILE* output;
      extern int   n_errors;
      extern void  quit (int rc);

//
////////////////////////////////////////////////////////////////////////////////////////////////////
