#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> in)
{
    vector<string> ar;
    // convert numbers to strings
    for(int i = 0; i < in.size(); i++)
    {
        string s = "";
        int n = in[i];
        while(n)
        {
            s += (n % 10) + '0';
            n /= 10;
        }
        reverse(s.begin(), s.end());
        ar.push_back(s);
    }
    map<string, pair<int, map<char, int>>> ma;
    int ans = 0;
    for(string s : ar)
    {
        for(int i = 0; i < s.size(); i++)
        {
            string aux = s.substr(0, i) + s.substr(i + 1);
            ans += ma[aux].first - ma[aux].second[s[i]];
            ma[aux].first++;
            ma[aux].second[s[i]]++;
        }
    }
    return ans;
}

int main()
{
    cout<<solution({1, 151, 241, 1, 9, 22, 351})<<'\n';
	return 0;
}
