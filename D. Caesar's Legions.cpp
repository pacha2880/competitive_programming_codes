#include <bits/stdc++.h>
#define mem(a, h)		memset(a, (h), sizeof(a))

using namespace std;
const int MOD = 100000000;
int n1,n2,k1,k2,dp[101][101][11][11];
int f(int sol, int cab, int cons, int conc)
{
    if(cons>k1||conc>k2||sol>n1||cab>n2) return 0;
    if(sol+cab==n1+n2) return 1;
    int &res = dp[sol][cab][cons][conc];
    if(res != -1) return res;
    return res = (f(sol+1,cab,cons+1,0) + f(sol,cab+1,0,conc+1)) % MOD;
}
int main()
{
	mem(dp, -1);
    cin>>n1>>n2>>k1>>k2;
    cout<<f(0,0,0,0);
    return 0;
}