#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string ReplaceString(const string& currentStr, const string& strSearch, const string& strReplace)
{
	string resultStr;
	size_t pos = 0;
	int strSerchLength = strSearch.length();
	int currentStrLength = currentStr.length();
	while (pos < currentStrLength)
	{
		size_t foundPos = currentStr.find(strSearch, pos);
		if (foundPos == -1)
			foundPos = currentStrLength;
		resultStr.append(currentStr, pos, foundPos - pos);
		if (foundPos != currentStrLength)
			resultStr += strReplace;
		pos = foundPos + strSerchLength;
	}
	return resultStr;
}

void CopyAndReplaceStream(ifstream& fin, ofstream& fout, const string& strSearch,
	const string& strReplace)
{
	string currentStr;

	while (getline(fin, currentStr))
	{
		fout << ReplaceString(currentStr, strSearch, strReplace) << "\n";
	}
};

int main(int argc, char* argv[])
{
	if (argc != 5)
	{
		cout << "\nNumber parameters is wrong, use replace.exe <input file> <output file> ";
		cout << "<search string> <replace string>";
		return 1;
	}

	ifstream fin(argv[1]);
	if (!fin.is_open())
	{
		cout << "\nCan't open input file " << argv[1];
		return 1;
	}

	ofstream fout(argv[2]);
	if (!fout.is_open())
	{
		cout << "\nCan't open output file " << argv[2];
		return 1;
	}

	string strSearch = argv[3], strReplace = argv[4];

	if (strSearch == "")
	{
		cout << "\nSearch string can't be empty ";
		return 1;
	}

	if (strReplace == "")
	{
		cout << "\nReplace string can't be empty ";
		return 1;
	}

	CopyAndReplaceStream(fin, fout, strSearch, strReplace);

	return 0;
}
