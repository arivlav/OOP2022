#include "CCar.h"
#include "CCarManager.h"

using namespace std;

int main(int, char *[])
{
	CCar car;
	CCarManager carManager(car);

	string instruction;
	cout << endl << ">";
	while (getline(cin, instruction))
	{
		carManager.DoInstruction(instruction);
		cout << endl << ">";
	}
	return 0;
}
