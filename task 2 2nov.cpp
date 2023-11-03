#include <bits/stdc++.h>
using namespace std;

vector<int> solution(string binaryString, vector<string> requests)
{
    int n = binaryString.size();
    vector<int> ones(n), zeros(n);
    for(int i = 0; i < n; i++)
    {
        if(binaryString[i] == '1')
            ones[i]++;
        else
            zeros[i]++;
        if(i)
        {
            ones[i] += ones[i - 1];
            zeros[i] += zeros[i - 1];
        }
    }
    vector<int> ans;
    for(string s : requests)
    {
        if(s == "flip")
            swap(ones, zeros);
        else
        {
            // from
        }
    }
    return ans;
}

int main()
{
    
	return 0;
}
