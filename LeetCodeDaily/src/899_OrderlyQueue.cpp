#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string orderlyQueue(string s, int k) {
        // for k letters in 's' we choose the max value one and append it to the back 
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        // if its k == 1 find the substring from the looping string
        string temp=s;
        s+=s;
        for(int i=1;i<temp.length();i++){
            temp=min(temp,s.substr(i,temp.size()));
        }
        return temp;
}

int main()
{
    std::cout << orderlyQueue("cba", 1);
}