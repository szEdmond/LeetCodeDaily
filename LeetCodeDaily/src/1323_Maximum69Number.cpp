#include<iostream>
#include <vector>

using namespace std;
// 9669
vector<int> getDigits(int num) {
	vector<int>nums;
	while (num) {
		int	x = num % 10;
		num /= 10;
		nums.push_back(x);
	}
	return nums;
}
int maximum69Number(int num) {
	vector<int>nums = getDigits(num);
	
	int r = nums.size()-1;
	while (r >= 0) {
		if (nums[r] == 6) {
			nums[r] = 9;
			r = -1;
		}
		else if (nums[r] != 6) r--;
	}
	int res = 0;
	int loc = 1;
	for (int i = 0; i < nums.size(); ++i) {
		res += nums[i] * loc;
		loc *= 10;
	}
	return res;
}

int main()
{
	cout << maximum69Number(9669);
}
