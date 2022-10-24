#include <iostream>
#include <vector>
#include <string>
#include<set>
using namespace std;

int len = 0;

bool isUnique(string& s) {
    vector<int> ch(26, 0);
    for (int i = 0; i < s.size(); i++) {
        if (ch[s[i] - 'a'] == 1)
            return false;
        ch[s[i] - 'a']++;
    }
    return true;
}
void checkLen(string str, vector<string>& arr, int itr) {
    if (!isUnique(str)) return;
    if (str.size() > len) len = str.size();
    for (int i = itr; i < arr.size(); i++)
        checkLen(str + arr[i], arr, i + 1);
}
int maxLength(vector<string>& arr) {
    checkLen("", arr, 0);
    return len;
}

void main()
{
    vector<string> sv {"un", "iq", "ue"};
    std::cout << maxLength(sv);
}