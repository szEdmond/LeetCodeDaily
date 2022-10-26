#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//------------ TLE ------------
//bool checkSubarraySum(vector<int>& nums, int k) {
//    int sum = 0;
//    for (int i = 0; i < nums.size(); i++) {
//        sum = nums[i];
//        for (int j = i + 1; j < nums.size(); j++) {
//            sum += nums[j];
//            if (sum % k == 0) return true;
//        }
//    }
//    return false;
//}
bool checkSubarraySum(vector<int>& nums, int k) 
{
    unordered_map<int, int> mp = {{0, -1}};
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum += nums[i];
        if (k != 0)
            sum = sum % k;
        //check if remainder already in map and check if subarray
        if (mp.find(sum) != mp.end()) {
            if (i - mp[sum] > 1)
                return true;
        }
        else
            mp[sum] = i;
    }
    return false;
}

int main()
{
    vector<int> iv{ 23,2,6,4,7 };
    cout<<checkSubarraySum(iv, 13);
}