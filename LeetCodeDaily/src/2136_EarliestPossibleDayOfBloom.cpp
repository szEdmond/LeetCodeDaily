#include <iostream>
#include <algorithm>
#include <vector>

// plants grow by themself
// sort them 
// think about "planting it after it grew"

int earliestFullBloom(std::vector<int>& plantTime, std::vector<int>& growTime) {
	std::vector < std::pair<int, int> > v;
	for (int i = 0; i < plantTime.size(); i++)
		v.push_back({ growTime[i],plantTime[i] });
	sort(v.begin(), v.end());
	int ans = 0;
	for (auto item : v)
		ans = std::max(ans, item.first) + item.second;
	return ans;
}

int main()
{
	std::vector<int> plantT{ 1,4,3 };
	std::vector<int> growT{ 2,3,1 };
	std::cout << earliestFullBloom(plantT, growT);
}

//1, 2 , 3
//3  1   4