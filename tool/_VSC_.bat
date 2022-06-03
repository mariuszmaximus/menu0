cd /d %~dp0
cd ..

set JM_NINJA=d:\bin\ninja
set JM_CMAKE=d:\bin\cmake-3.23.1-windows-x86_64\bin

set MB_NINJA=c:\bin\ninja
set MB_CMAKE=c:\bin\cmake-3.23.1-windows-x86_64\bin

set MSYS_DIR=C:\msys64\mingw64\bin

@rem ustawiam środowisko 
@rem   czysty PATH bez ustawien komputera 
@rem   tylko VSC + kompilator + ninja + cmake
set PATH=C:\Windows\System32;"C:\Users\%USERNAME%\AppData\Local\Programs\Microsoft VS Code";%MB_NINJA%;%MB_CMAKE%;%JM_NINJA%;%JM_CMAKE%;%MSYS_DIR%

@rem do testow porownawczych BLUE vs ...
set BLUE_DIR=D:\delphi\USG_USB\U32\bin\

code .\

@rem pause