set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem тест 1 неправильное количество параметров
%PROGRAM% fox.txt "%TEMP%\fox.txt" cat
if NOT ERRORLEVEL 1 goto err

rem тест 2 указываем несуществующий файл
%PROGRAM% notExistFile.txt "%TEMP%\fox.txt" bird cat
if NOT ERRORLEVEL 1 goto err

rem тест 3  строка, которую ищем не может быть пустой
%PROGRAM% fox.txt "%TEMP%\fox.txt" "" cat
if NOT ERRORLEVEL 1 goto err

rem тест 4  строку, на которую заменяем не может быть пустой
%PROGRAM% fox.txt "%TEMP%\fox.txt" bird ""
if NOT ERRORLEVEL 1 goto err

rem тест 5 проверяем пустой файл
%PROGRAM% emptyInputFile.txt "%TEMP%\empty.txt" bird cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\empty.txt" emptyInputFile.txt >nul
if ERRORLEVEL 1 goto err

rem тест 6 слова в строке нет
%PROGRAM% fox.txt "%TEMP%\fox.txt" bird cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\fox.txt" fox.txt >nul
if ERRORLEVEL 1 goto err

rem тест 7 При запуске с правильными параметрами ожидается нулевой код возврата
%PROGRAM% fox.txt "%TEMP%\fox.txt" dog cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\fox.txt" fox-replace-dog-with-cat.txt >nul
if ERRORLEVEL 1 goto err

rem тест 8
%PROGRAM% specialTest.txt "%TEMP%\fox.txt" 1231234 cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\fox.txt" specialTestResult.txt >nul
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1