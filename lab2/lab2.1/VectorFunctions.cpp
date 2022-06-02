#include "VectorFunctions.h"

using namespace std;

string GetStringFromInputStream()
{
	cout << "Enter a float numbers through a space:" << endl;
	string str;
	getline(cin, str);
	return str;
}

vector<float> GetFloatVectorFromString(const string& str)
{
	vector<float> newVector;
	stringstream ss;
	ss.str(str);
	float number;
	while (ss >> number)
	{
		newVector.push_back(number);
	}
	if (!ss.eof())
		newVector = {};
	return newVector;
}

void TransformVectorWithVariant2(vector<float>& vector)
{
	if (vector.size() != 0)
	{
		float min = *min_element(vector.begin(), vector.end());
		transform(vector.begin(), vector.end(), vector.begin(), [min](float element) {
			return element * min;
		});
	}
}

void SortVector(vector<float>& vector)
{
	sort(vector.begin(), vector.end());
}

void PrintVector(const vector<float>& vector)
{
	copy(vector.begin(), vector.end(), ostream_iterator<float>(cout << fixed << setprecision(3), " "));
}