#include <bits/stdc++.h>
using namespace std;



int distinctStrings(string s)
{
    int n = s.size();
	const int MOD = 1000000007;
	vector<int> dp1(n + 1), dp2(n + 1);
	vector<int> ax(500, -1);
    dp1[1] = 1;
	dp2[1] = 1;
	ax[s[0]] = 1;
    for (int i = 2; i <= n; i++) {
		dp2[i] = (dp2[i - 1] + dp1[i - 1]) % MOD;
		dp1[i] = dp2[i - 1];
        if (ax[s[i - 1]] != -1)
            dp1[i] = dp1[i] - dp1[ax[s[i - 1]]];
        ax[s[i - 1]] = i;
    }
 
    return (dp1[n] + dp2[n] + MOD - 1) % MOD;
}

int main()
{
	cout<<distinctStrings("dd")<<'\n';
	cout<<distinctStrings("abc")<<'\n';
	cout<<distinctStrings("abcd")<<'\n';
	cout<<distinctStrings("abcda")<<'\n';
	return 0;
}
