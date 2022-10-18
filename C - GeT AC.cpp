#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD				1000000007
#define MOD1			998244353
#define EPS				1e-9
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int tam = 10000010;
int n;
map<string, int> dp[300];
string add = "ACGT";
ll f(int pos, string s)
{
	if(s.substr(1) == "AGC" || s.substr(1) == "ACG" || s.substr(1) == "GAC")
		return 0;
	if(s[0] + s.substr(2) == "AGC" || s.substr(0, 2) + s[3] == "AGC")
		return 0;
	//cout<<pos<<' '<<s<<'\n';
	if(pos == n-1) return 1;
	if(dp[pos][s] != 0) return dp[pos][s];
	ll res = 0;
	fore(i, 0, 4)
		res = (res + f(pos + 1, (s + add[i]).substr(1))) % MOD;
	//cout<<pos<<' '<<s<<' '<<res<<'\n';
	return dp[pos][s] = res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n;
	ll res = 0;
	fore(i, 0, 4)
	{
		string s = "   ";
		s += add[i];
		res = (res + f(0, s)) % MOD;
		//cout<<res<<"$\n";
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2