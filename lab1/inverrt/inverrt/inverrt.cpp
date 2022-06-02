#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <array>
#include <cmath>

using namespace std;

const int MAIN_MATRIX_SIZE = 3;
const int SUPPORT_MATRIX_SIZE = 2;
const int HAS_ERROR = 1;
const int NO_ERROR = 0;

typedef double MainMatrix[MAIN_MATRIX_SIZE][MAIN_MATRIX_SIZE];
typedef double SupportMatrix[SUPPORT_MATRIX_SIZE][SUPPORT_MATRIX_SIZE];


using Matrix3x3 = array<array<double, 3>, 3>;

void GetMatrixFromFile(ifstream &fin, MainMatrix &getedMatrix, int &error)
{
	error = NO_ERROR;
	try
	{
		for (int i = 0; i < MAIN_MATRIX_SIZE; i++)
			for (int j = 0; j < MAIN_MATRIX_SIZE; j++)
			{
				if (!(fin >> getedMatrix[i][j]))
				{
					cout << "Can't read matrix's element. Check input file\n";
					throw HAS_ERROR;
				}
			}

		if (fin.bad() || !fin.eof())
		{
			cout << "Wrong format of input file\n";
			throw HAS_ERROR; //выбрасывать исключения в виде объектов
		}
	}
	catch (int codeError)
	{
 		error = codeError;
	}
}

double GetDeterminant(MainMatrix &matrix) {
	return matrix[0][0] * matrix[1][1] * matrix[2][2] 
		+ matrix[0][1] * matrix[1][2] * matrix[2][0]
		+ matrix[0][2] * matrix[1][0] * matrix[2][1]
		- matrix[0][2] * matrix[1][1] * matrix[2][0]
		- matrix[0][0] * matrix[1][2] * matrix[2][1]
		- matrix[0][1] * matrix[1][0] * matrix[2][2];
}

//примитивныее типы принимать по значению
double GetCurrentElementForInverseMatrix(MainMatrix &matrix, const double &determinant, const int &currentRowPos, const int &currentColumnPos)
{
	SupportMatrix helpMatrix;
	int row = 0, column = 0;
	for (int i = 0; i < MAIN_MATRIX_SIZE; i++)
		if (i != currentRowPos)
		{
			for (int j = 0; j < MAIN_MATRIX_SIZE; j++)
				if (j != currentColumnPos)
				{

					helpMatrix[row][column] = matrix[i][j];
					column++;
				}
			column = 0;
			row++;
		}
	double newMatrixElement = helpMatrix[0][0] * helpMatrix[1][1] - helpMatrix[0][1] * helpMatrix[1][0];
	newMatrixElement /= determinant;
	if ((currentRowPos + currentColumnPos) % 2 == 1)
		newMatrixElement *= -1;
	return newMatrixElement;
}

//не понятно какая матрица изменяется
void GetInverseMatrix(MainMatrix &initialMatrix, MainMatrix &inverseMatrix, int &error)
{
	error = NO_ERROR;
	double determinant = GetDeterminant(initialMatrix);
	if (fpclassify(determinant) != FP_ZERO) 
	{
		//отдельная функция
		for (int i = 0; i < MAIN_MATRIX_SIZE; i++)
			for (int j = 0; j < MAIN_MATRIX_SIZE; j++)
				inverseMatrix[i][j] = GetCurrentElementForInverseMatrix(initialMatrix, determinant, i, j);
	}
	else
	{
		error = HAS_ERROR;
		//вывод обработать в отдельной функции
		cout << "Inverse matrix is not exist." << endl;
	}
}

void PrintMatrix(MainMatrix &matrix)
{
	for (int i = 0; i < MAIN_MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MAIN_MATRIX_SIZE; j++)
		{
			cout.width(15);
			cout.setf(ios::fixed);
			cout.precision(3);
			cout << matrix[j][i];
		}
		cout << endl;
	}
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "\nNumber parameters is wrong, use invert.exe <input file>";
		return 1;
	}
	//сделать функцию, котоая счмтает матрицу из файла
	ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		cout << "\nCan't open input file " << argv[1];
		return 1;
	}

	MainMatrix initialMatrix, inverseMatrix;
	int error = NO_ERROR;
	GetMatrixFromFile(fin, initialMatrix, error);
	if (error)
		return 1;
	cout << "Initial matrix: " << endl;
	PrintMatrix(initialMatrix);
	//error = 1;
	GetInverseMatrix(initialMatrix, inverseMatrix, error);
	if (error)
		return 1;
	cout << "Inverse matrix: " << endl;
	PrintMatrix(inverseMatrix);
	return 0;
}
