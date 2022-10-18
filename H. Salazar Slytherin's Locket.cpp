#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
ll dp[100][100][100];
ll f(int base, int pos, int cant)
{
	if(cant == -1 || cant == base + 1)
		return 0;
	if(pos == -1)
		return cant == 0;
	if(dp[base][pos][cant] != -1) return dp[base][pos][cant];
	ll &res = dp[base][pos][cant];
	res = cant * f(base, pos - 1, cant - 1) + 
			(base - cant) * f(base, pos - 1, cant + 1);
	return res;
}
int ar[10000];
int canti[1000];
ll chu(ll x, int b)
{
	int pos = 0;
	fore(i, 0, b) canti[i] = 0;
	while(x > 0)
	{
		ar[pos++] = x % b;
		x /= b;
	}
	if(pos <= 1) return 0;
	int con = 0;
	ll res = 0;
	//cout<<"chen\n";	
	for(int i = pos - 1; i > -1; i--)
	{
		//cout<<ar[i]<<' ';
		fore(j, pos - 1 == i, ar[i])
		{
			if(canti[j] & 1)
				res += f(b, i - 1, con - 1);
			else
				res += f(b, i - 1, con + 1);
		}
		if(i < pos - 1)
			res += (b - 1) * f(b, i - 1, 1);
		canti[ar[i]]++;
		if(canti[ar[i]] & 1)
			con++;
		else
			con--;
	}
	res += con == 0;
	//cout<<'\n';
	//cout<<res<<'\n';
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int q;
	cin>>q;
	int b;
	ll l, r;
	mem(dp, -1);
	while(q--)
	{
		cin>>b>>l>>r;
		cout<<chu(r, b) - chu(l - 1, b)<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	