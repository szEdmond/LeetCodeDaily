#include<iostream>
#include<vector>
#include <algorithm>
#include<numeric>
#include<set>
using namespace std;

vector<int> findErrorNums(vector<int>& nums) 
{
    // sum elements
    int initialSum = std::accumulate(nums.begin(), nums.end(), 0);
    // set to remove dupes;
    set<int> s;
    for (int& i : nums)
        s.insert(i);

    // sum of set
    int sum = accumulate(s.begin(), s.end(), 0);
    // difference of the 2 is the repeated number
    int repeated = initialSum - sum;

    int supposedSum = 0;
    for (int i = 1; i <= nums.size(); i++)
        supposedSum += i;
    // subtracting the sum(which misses a digit) from supposedsum gives us the missing number
    int missing = supposedSum - sum;

    return { repeated, missing };
}
int main()
{
    vector<int> asd{3,2,2};
    vector<int>ans = findErrorNums(asd);
    for (int& i : ans)
        cout << i << endl;
}