
SET-UP INSTRUCTIONS

--------------------------------------------------------------------------------

Set "grm" file extension to C/C++

This allows easy access to your Token-Action and Node-Action function names.
Double click on the name, then right-click and select "Go To Definition".
The Visual Studio "File Extension" setting is found at:

TOOLS / OPTIONS / TEXT EDITOR / FILE EXTENSION

--------------------------------------------------------------------------------

Set Tabs To 3 (or not)

LALR source code and grammars were written with tabs set to 3, indent 3, and
keep tabs.  When released, all files have the tabs removed and they should look
like the original appearance on my computer.  You may want to change tabs to 3
or you may not.

The Visual Studio tab setting is found at:

TOOLS / OPTIONS / TEXT EDITOR / ALL LANGUAGES / TABS

--------------------------------------------------------------------------------

Read-Only Files

Make sure you are not able to modify read-only files, as LALR generates two of
them, and DFA generates two of them. The VS setting is found at

TOOLS / OPTIONS / ENVIRONMENT / DOCUMENTS

On the right side, the second [ ] box down from the top. This may already be set
properly.

--------------------------------------------------------------------------------

Enable Virtual Space

My personal preference. This is the way it always was in the IBM mainframe days.
Can't find it outside of Visual Studio. Poor new generation nerds. There was a
book written about them, "The Inmates Are Running The Asylum". The Visual Studio
setting is here:

TOOLS / OPTIONS / TEXT EDITOR / ALL LANGUAGES / GENERAL

"Settings" is on right. Click the box [ ] next to "Enable Virtual Space".

--------------------------------------------------------------------------------

Set the File Extension for "grm"

TOOLS / OPTIONS / TEXT EDITOR / FILE EXTENSION

On the right, type in "grm", select C++, and Add.

This will make life easier, because you can right-click on a action name in your
grammar and select "Go To Definition" and it goes to your code.  Very nice.

But it's better to turn off all formatting because Visual Studio will try to
format your grammar into C++ code and it will look bad.  The formatting settings
are here:

TOOLS / OPTIONS / TEXT EDITOR / C/C++ / Code Style / Formatting

Turn off most or all of the formatting, to suit your needs.

--------------------------------------------------------------------------------

Try LALR

Go into the folder:

SOFTWARE / LRSTAR / LRSTAR.24.0.000 / examples / Calc

Double-click workspace.sln

In Visual Studio, do a Build / Build Solution,
and click Local Windows Debugger.

Look at file test.output.txt,
then look at file Calc.grm.

--------------------------------------------------------------------------------


