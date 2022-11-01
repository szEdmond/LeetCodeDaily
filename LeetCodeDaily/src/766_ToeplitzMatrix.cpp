#include <iostream>
#include <vector>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix)
{
    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[0].size(); j++) {

            //if (i <= 0 || j <= 0 || (i == 0  && j == matrix.size()-1) ) {
            //    continue;
            //}

            //check top left element against current
            if (matrix[i][j] != matrix[i - 1][j - 1])
                return false;

        }
    }
    return true;
}

int main()
{
    // 11  74   0  93
    // 40  11  74   7
    vector<vector<int>> ivv{ {11,74,0,93},{40,11,74,7} };
    cout << isToeplitzMatrix(ivv);
}