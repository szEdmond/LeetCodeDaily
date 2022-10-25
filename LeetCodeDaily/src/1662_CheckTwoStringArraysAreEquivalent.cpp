#include <iostream>
#include <vector>

using namespace std;

bool arrayStringsAreEqual(const vector<string>& word1, const vector<string>& word2)
{
	string s1, s2;

	for (const string& s : word1)
		s1 += s;
	for (const string& s : word2)
		s2 += s;

	return s1 == s2;
}

int main()
{
	cout<<arrayStringsAreEqual({"ab", "c"},{"a","bc"});
}