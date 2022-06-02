set PROGRAM="%~1"

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ���� 1 ��������� �������������� ����
%PROGRAM% notExistFile.txt
if NOT ERRORLEVEL 1 goto err

rem ���� 2 ��������� ������ ����
%PROGRAM% emptyInputFile.txt
if NOT ERRORLEVEL 1 goto err

rem ���� 3 ���� � ����������� ����������
%PROGRAM% wrongMatrix.txt
if NOT ERRORLEVEL 1 goto err

rem ���� 4 ���� � �������� � ������� �������������
%PROGRAM% zeroDeterminant.txt
if NOT ERRORLEVEL 1 goto err

rem �������� ���� ��������� �� ��������� ��������
rem ���� 5 ���� � �������� � ��������� �������������
%PROGRAM% >testResult.txt matrix.txt
if ERRORLEVEL 1 goto err
fc.exe testResult.txt resultForMatrix.txt > nul
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1