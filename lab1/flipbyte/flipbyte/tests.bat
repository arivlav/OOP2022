@ECHO OFF
set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM%
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% 23 1
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% a
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% -1
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% 256
if NOT ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% >testResult.txt 6
if ERRORLEVEL 1 goto err
fc.exe "testResult.txt" resultForSix.txt >nul
if ERRORLEVEL 1 goto err

rem При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% >testResult.txt 96
if ERRORLEVEL 1 goto err
fc.exe "testResult.txt" resultForNineSix.txt >nul
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1