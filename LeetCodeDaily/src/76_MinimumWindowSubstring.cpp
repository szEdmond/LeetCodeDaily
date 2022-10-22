#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

string minWindow(string s, string t) {
    unordered_map<char, int> mp;

    int ans = INT_MAX;
    int start = 0;

    for (char& c : t)
        mp[c]++;

    int count = mp.size();

    int left = 0, right = 0;

    while (right < s.length()) {
        mp[s[right]]--;
        if (mp[s[right]] == 0)
            count--;

        if (count == 0) {
            while (count == 0) {
                if (ans > right - left + 1) {
                    ans = right - left + 1;
                    start = left;
                }
                mp[s[left]]++;
                if (mp[s[left]] > 0)
                    count++;

                left++;
            }
        }
        right++;
    }
    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "";
}

void main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<minWindow(s, t);
}