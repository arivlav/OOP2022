#include "VectorFunctions.h"
using namespace std;

int main()
{
	string inputString = GetStringFromInputStream();
	vector<float> floatVector = GetFloatVectorFromString(inputString);
	TransformVectorWithVariant2(floatVector);
	SortVector(floatVector);
	PrintVector(floatVector);
}

