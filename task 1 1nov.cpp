#include <bits/stdc++.h>
using namespace std;

vector<bool> solution(vector<vector<int>> queries)
{
    int wid = 0, hei = 0;
    vector<bool> ans;
    for(auto query : queries)
    {
        if(query[0] == 0)
        {
            wid = max(wid, min(query[1], query[2]));
            hei = max(hei, max(query[1], query[2]));
        }
        else
        {
            ans.push_back(min(query[1], query[2]) >= wid && max(query[1], query[2]) >= hei);
        }
    }
    return ans;
}

int main()
{
    for(auto x : solution({{0, 1, 3}, {0, 4, 2}, {1, 3, 4}, {1, 3, 2}}))
    {
        cout << x << " ";
    }
	return 0;
}
