#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if (strs.size() == 1) 
        return { {strs[0]} };

    vector<vector<string>> ans;
    unordered_map<string, vector<string>> mp;

    for (int i = 0; i < strs.size(); i++) {
        string temp = strs[i];
        sort(strs[i].begin(), strs[i].end());
        mp[strs[i]].push_back(temp);
    }

    for (auto item : mp) 
        ans.push_back(item.second);
   
    return ans;
}

int main() {
    vector<string> sv{ "eat","tea","tan","ate","nat","bat" };
    groupAnagrams(sv);
}