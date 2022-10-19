#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// comparison operator for sort
static bool compare(pair<string, int> p1, pair<string, int> p2)
{
    if (p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first))
        return true;
    return false;
}

vector<string> topKFrequent(vector<string>& words, int k) {
    unordered_map<string, int> mp;

    for (int i = 0; i < words.size(); i++)
        mp[words[i]]++;

    vector<pair<string, int>> vec;
    for (auto it = mp.begin(); it != mp.end(); it++)
        vec.push_back({ it->first,it->second });

    sort(vec.begin(), vec.end(), compare);

    vector<string> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(vec[i].first);
    }

    return ans;
}

int main() 
{
    std::vector<string> words{"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    int k = 4;
    std::vector<string> result = topKFrequent(words, k);
    for (const string& s : result) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

