#include <iostream>
#include <vector>
#include <string>

std::string intToRoman(int);

int main()
{
	std::cout << intToRoman(1994);
}

std::string intToRoman(int num) 
{
	const std::vector<int> VALUE { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
	const std::vector<std::string> SYMBOL { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };

	std::string result = "";
	for (int i = 0; i < SYMBOL.size(); ++i) {
		while (num >= VALUE[i]) {
			result.append(SYMBOL[i]);
			num -= VALUE[i];
		}
	}
	return result;
}