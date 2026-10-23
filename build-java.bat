@echo off
rem Compiles every Java solution with its Main.java test driver and runs it.
setlocal enabledelayedexpansion
cd /d "%~dp0"

set failures=0

for /d %%D in (problems\*) do (
    if exist "%%D\Solution.java" if exist "%%D\Main.java" (
        set "out=build\java\%%~nxD"
        echo === %%~nxD
        if exist "!out!" rmdir /s /q "!out!"

        javac -Xlint:all -Werror -d "!out!" "%%D\Solution.java" "%%D\Main.java"
        if errorlevel 1 (
            set /a failures+=1
        ) else (
            java -cp "!out!" Main
            if errorlevel 1 set /a failures+=1
        )
    )
)

echo.
if %failures% equ 0 (
    echo All Java solutions passed.
    exit /b 0
)
echo %failures% problem(s) failed.
exit /b 1
