set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem тест 1 указываем несуществующий файл
%PROGRAM% notExistFile.txt
if NOT ERRORLEVEL 1 goto err

rem тест 2 проверяем пустой файл
%PROGRAM% emptyInputFile.txt
if NOT ERRORLEVEL 1 goto err

rem тест 3 файл с нечисловыми значениями
%PROGRAM% wrongMatrix.txt
if NOT ERRORLEVEL 1 goto err

rem тест 4 файл с матрицей с нулевым определителем
%PROGRAM% zeroDeterminant.txt
if NOT ERRORLEVEL 1 goto err

rem выходной файл созлавать во временном каталоге
rem тест 5 файл с матрицей с ненулевым определителем
%PROGRAM% >testResult.txt matrix.txt
if ERRORLEVEL 1 goto err
fc.exe testResult.txt resultForMatrix.txt > nul
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1