#include <bits/stdc++.h>
using namespace std;
// returns true if first wins
// O(numStates * (n^3))
// numStates can vary but its exponential

// there is 2 * n^2 possible stack choices
// the depth of the recursion is n
// the branching is n^2
so  O((n ^ 2)^n)
map<vector<pair<int, int>>, bool> dp;
bool wins(vector<pair<int, int>> state)
{
	sort(state.begin(), state.end());
	if(dp.count(state)) return sp[state];
	int n = state.size();
	bool win = false;
	// every pair of stacks
	for(int i = 0; i < n; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			if(state[i].first == state[j].first || state[i].second == state[j].second)
			{
				vector<pair<int, int>> new_state;
				// put other stacks
				for(int k = 0; k < n; k++)
				{
					if(k != i && k != j)
						new_state.push_back(state[k]);
				}
				// try i on top of j;
				new_state.push_back({state[i].first, state[i].second + state[j].second});
				// win will become true if wins(new_state) is false
				// we are in a win state if we reach a losing state in the move
				win |= !wins(new_state);

				// we can stop here
				// we can return a tuple
				// if(win)
				// 	return (i, j, 1) 
				// pop it
				new_state.pop_back();
				// try j on top of i
				new_state.push_back({state[j].first, state[i].second + state[j].second});
				win |= !wins(new_state);
				// if(win)
				// 	return (j, i, 1) 

				// if wins(new_state) is allways true, win will remain false
			}
		}
	}
	// if we don't find any pair of stacks that can be merged, then win will remain false
	// if we reach the end its a loss
	// return here or store here the last possible move
	return dp[state] = win;
}



int main()
{
	return 0;
}
