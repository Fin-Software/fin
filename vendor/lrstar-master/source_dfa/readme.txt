
HOW TO COMPILE LRSTAR & DFA FROM THE SOURCE CODE.

The source code in LRSTAR compiles without error
when compiling with GCC 4.6.1.  This is based on my
experience on Windows as of March 28 2014.  If not using
the option "-w", many warning messages will be displayed,
but these are not a problem.

The default is 32-bit executables.  If you want 64-bit
executables, use -D x64 or -Dx64

---------------------------------------------------------

ON WINDOWS SYSTEMS:

   Visual C++ workspaces are already defined for this in
   the "source" directory.

   If you are not using Visual C++, do the following:

   1. Specify WINDOWS and LRSTAR on the command line:

      /D WINDOWS /D LRSTAR

      Compile all the code (*.cpp) to make lrstar.exe

   2. Specify WINDOWS and DFA on the command line:

      /D WINDOWS /D DFA

      Compile all the code (*.cpp) to make dfa.exe

---------------------------------------------------------

ON LINUX SYSTEMS:

   For compiling with GCC:

   1. Specify LINUX and LRSTAR on the command line:

      gcc *.cpp -lstdc++ -w -DUNIX -DLRSTAR -olrstar

   2. Specify LINUX and DFA on the command line:

      gcc *.cpp -lstdc++ -w -DUNIX -DDFA -odfa

	This is the recommended batch file:

	@echo off
	if exist *.obj del *.obj
	if exist *.o   del *.o
	del dfa.exe lrstar.exe
	gcc -Os *.cpp -lstdc++ -w -DUNIX -DDFA -o dfa -s
	gcc -Os *.cpp -lstdc++ -w -DUNIX -DLRSTAR -o lrstar -s

	To get the definition of S_IREAD and S_IWRITE,
	you may have to add:

   -D_GNU_SOURCE  (on the command line)

	Or put this in the code:

	#define _GNU_SOURCE

---------------------------------------------------------

ON MAC OS X SYSTEMS:

	I don't know about this, sorry.

---------------------------------------------------------



