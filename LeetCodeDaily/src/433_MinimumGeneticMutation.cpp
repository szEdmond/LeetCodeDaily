#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

int minMutation(string start, string end, vector<string>& bank) {

	unordered_set<string> st{ bank.begin(), bank.end() };
	// if mutation not in list: -1
	if (!st.count(end)) return -1;
	
	queue<string> q;
	q.push(start);
	int steps = 0;
	int s;
	string cur;
	string temp;
	while (!q.empty()) {
		s = q.size();

		// check all the possibile strings in queue
		while (s--) {
			cur = q.front();
			q.pop();

			// if word matches end mutation, return
			if (cur == end) return steps;
			
			st.erase(cur);
			// 8chars, 4 mutation per char, 
			// if it is a possible mutation add to queue
			for (int i = 0; i < 8; i++) {
				temp = cur;
				temp[i] = 'A';
				if (st.count(temp)) q.push(temp);
				temp[i] = 'C';
				if (st.count(temp)) q.push(temp);
				temp[i] = 'G';
				if (st.count(temp)) q.push(temp);
				temp[i] = 'T';
				if (st.count(temp)) q.push(temp);
			}
		}

		steps++;
	}
	return -1;
}

int main() 
{
	vector<string> sv{ "AAAACCCC","AAACCCCC","AACCCCCC" };
	std::cout << minMutation("AAAAACCC", "AACCCCCC", sv);
}