#include <iostream>
#include <vector>
#include <unordered_map>

bool containsNearbyDuplicates(std::vector<int>& nums, int k) {
	std::unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++) {
		if (mp.count(nums[i]))
			if (i - mp[nums[i]] <= k)
				return true;
		mp[nums[i]] = i;
	}
	return false;
}
	
int main()
{
	std::vector<int> v{ 1,2,3,1,2,3 };
	std::cout << containsNearbyDuplicates(v, 2);
}