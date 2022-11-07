#include <iostream>
#include <string>

using namespace std;

bool isVowel(char c) {
	c = tolower(c);
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
	return false;
}

string reverseVowels(string s) {
	int l = 0;
	int r = s.size()-1;

	while (l < r) {
		if (isVowel(s[l]) && isVowel(s[r])) {
			swap(s[l], s[r]);
			l++; r--;
		}
		if (!isVowel(s[l]))
			l++;
		if (!isVowel(s[r]))
			r--;
	}
	return s;
}

int main()
{
	std::cout << reverseVowels("lEetcode");
}
