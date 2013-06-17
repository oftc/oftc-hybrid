@echo off

SET GYP=c:\dev\gyp\gyp

%GYP% oftc-hybrid.gyp --depth=. -Dlibrary=static_library -Icommon.gypi
