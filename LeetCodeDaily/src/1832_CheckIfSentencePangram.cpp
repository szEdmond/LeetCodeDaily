#include<iostream>
#include<vector>

// english alphabet 26 letters...

bool checkIfPangram(std::string sentence) {
	std::vector<int> n(26, 0);

	// given char - 'a' equals its index in alphabetical order, ASCII value 'a'-'a' = 0 | 'b'-'a' = 1 ...
	for (const char& c : sentence) 
		n[c - 'a']++;


	for (int i = 0; i < n.size(); i++)
		if (n[i] == 0) // if one of the letters doesn't appear
			return false;
	return true;
}

int main()
{
	std::string sentence = "thequickbrownfoxjumpsoverthelazydog";
	std::cout << checkIfPangram(sentence) << std::endl;
}