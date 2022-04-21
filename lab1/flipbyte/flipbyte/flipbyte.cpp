#include <fstream>
#include <iostream>
#include <string>

using namespace std;

unsigned int FlipByte(unsigned int number) 
{
	unsigned int currentBit = 0, symmetricBit = 0, newNumber = number;
	for (int i = 0; i < 4; i++)
	{
		currentBit = (number >> i) & 1;
		symmetricBit = (number >> (7 - i)) & 1;
		if (currentBit != symmetricBit)
		{
			newNumber ^= ((1 << i) | (1 << (7 - i)));
		}
	}
	return newNumber;
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "\nNumber parameters is wrong, use flipbyte.exe <number 0..255>\n";
		return 1;
	}

	unsigned int inputNumber = 0;

	try
	{
		inputNumber = stoi(argv[1]);

		if (inputNumber > 255)
		{
			throw invalid_argument("Number must be less then 255\n");
		}
	}
	catch (invalid_argument& e)
	{
		cout << e.what() << endl;
		return 1;
	}

	cout << "New number: " << FlipByte(inputNumber) << endl;

	return 0;
}