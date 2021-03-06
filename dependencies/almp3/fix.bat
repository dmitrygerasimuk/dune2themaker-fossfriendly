@echo off
echo.
set MAKE_PROJECT=FBlend
if [%1] == [djgpp]   goto djgpp
if [%1] == [mingw32] goto mingw32
if [%1] == [msvc]    goto msvc
if [%1] == [unix]    goto unix

if [%1] == [help]    goto help
if [%1] == [--help]  goto help
if [%1] == [-?]      goto help
if [%1] == []        goto help

goto help

:djgpp
set MAKE_COMPILER=DJGPP
set MAKEFILE=makefile.dj
goto fix

:mingw32
set MAKE_COMPILER=Mingw32
set MAKEFILE=makefile.mgw
goto fix

:msvc
set MAKE_COMPILER=MSVC
set MAKEFILE=makefile.vc
goto fix


:help

echo Compilation target adjustment.
echo   Usage: fix [platform]
echo.
echo   [platform] is one of: djgpp, mingw32, msvc or unix
echo   Example: fix mingw32
echo.
goto end

:fix

echo Configuring %MAKE_PROJECT% for %MAKE_COMPILER%...

echo # generated by fix.bat > makefile
echo include make/%MAKEFILE% >> makefile


:done

set MAKE_PROJECT=
set MAKEFILE=
set MAKE_COMPILER=

echo Done! Now run make to start the compilation.
echo.

:end


