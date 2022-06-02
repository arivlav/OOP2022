set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ���� 1 ������������ ���������� ����������
%PROGRAM% fox.txt "%TEMP%\fox.txt" cat
if NOT ERRORLEVEL 1 goto err

rem ���� 2 ��������� �������������� ����
%PROGRAM% notExistFile.txt "%TEMP%\fox.txt" bird cat
if NOT ERRORLEVEL 1 goto err

rem ���� 3  ������, ������� ���� �� ����� ���� ������
%PROGRAM% fox.txt "%TEMP%\fox.txt" "" cat
if NOT ERRORLEVEL 1 goto err

rem ���� 4  ������, �� ������� �������� �� ����� ���� ������
%PROGRAM% fox.txt "%TEMP%\fox.txt" bird ""
if NOT ERRORLEVEL 1 goto err

rem ���� 5 ��������� ������ ����
%PROGRAM% emptyInputFile.txt "%TEMP%\empty.txt" bird cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\empty.txt" emptyInputFile.txt >nul
if ERRORLEVEL 1 goto err

rem ���� 6 ����� � ������ ���
%PROGRAM% fox.txt "%TEMP%\fox.txt" bird cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\fox.txt" fox.txt >nul
if ERRORLEVEL 1 goto err

rem ���� 7 ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% fox.txt "%TEMP%\fox.txt" dog cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\fox.txt" fox-replace-dog-with-cat.txt >nul
if ERRORLEVEL 1 goto err

rem ���� 8
%PROGRAM% specialTest.txt "%TEMP%\fox.txt" 1231234 cat
if ERRORLEVEL 1 goto err
fc.exe "%TEMP%\fox.txt" specialTestResult.txt >nul
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1