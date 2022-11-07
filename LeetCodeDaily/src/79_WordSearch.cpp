#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool helper(vector<vector<char>>& board, string& word, int i, int j, int curlength) {
	if (curlength == word.size()) 
		return true;

	if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '0')
		return false;

	if (board[i][j] != word[curlength]) return false;

	char temp = board[i][j];
	board[i][j] = '0';

	if (helper(board, word, i + 1, j, curlength+1) ||
		helper(board, word, i - 1, j, curlength+1) ||
		helper(board, word, i, j + 1, curlength+1) ||
		helper(board, word, i, j - 1, curlength+1))
		return true;
	
	board[i][j] = temp;
	return false;
}

bool exist(vector<vector<char>>& board, string word) {
	for (int i = 0; i < board.size(); ++i) {
		for (int j = 0; j < board[0].size(); ++j) {
			if (helper(board, word, i, j, 0))
				return true;
		}
	}
	return false;
}

int main() {
	vector<vector<char>> board {{'A','B','C','E'}, {'S','F','C','S'}, {'A','D','E','E'}};
	
	cout << exist(board, "SEE");
}