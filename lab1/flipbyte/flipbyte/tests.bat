set PROGRAM="%~1"
set EXPECTEDRESULT=96

%PROGRAM% > nul
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM%
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% 23 1
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% a
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% -1
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% 256
if NOT ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% 6
if ERRORLEVEL 1 goto err

rem ��� ������� � ����������� ����������� ��������� ������� ��� ��������
%PROGRAM% 96
if ERRORLEVEL 1 goto err

echo OK
exit 0

:err
echo Program testing failed
exit 1