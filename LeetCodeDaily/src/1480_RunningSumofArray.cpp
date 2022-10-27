#include<iostream>
#include<vector>

using namespace std;
//
//vector<int>runningSum(vector<int>& nums) {
//    vector<int>ans{ nums[0] };
//    for (int i = 1; i < nums.size(); i++) {
//        ans.push_back(nums[i] + ans[i - 1]);
//    }
//    return ans;
//}

vector<int>runningSum(vector<int>& nums) {
	for (int i = 1; i < nums.size(); i++) {
		nums[i] += nums[i - 1];
	}
	return nums;
}

int main() 
{
	vector<int> iv{ 1,2,3,4 };
	runningSum(iv);
	cout << "stop" << endl;
}