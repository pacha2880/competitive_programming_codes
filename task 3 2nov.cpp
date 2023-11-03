#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> matrix, int frame)
{
    map<int, unordered_set<int>> ma;
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i <= n - frame; i++)
    {
        for(int j = 0; j <= m - frame; j++)
        {
            int sum = 0;
            for(int k = i; k < i + frame; k++)
                for(int l = j; l < j + frame; l++)
                    if(k == i || k == i + frame - 1 || l == j || l == j + frame - 1)
                        sum += matrix[k][l];
            for(int k = i; k < i + frame; k++)
                for(int l = j; l < j + frame; l++)
                    if(k == i || k == i + frame - 1 || l == j || l == j + frame - 1)
                        ma[sum].insert(matrix[k][l]);
        }
    }
    int ans = 0;
    for(int i : (--ma.end())->second)
        ans += i;
    return ans;
}

int main()
{
    cout<<solution({{9, 7, 8, 9, 2},
                    {6, 9, 9, 6, 1},
                    {4, 10, 1, 3, 10},
                    {18, 2, 3, 9, 3},
                    {4, 6, 8, 5, 21}}, 3);
	return 0;
}
