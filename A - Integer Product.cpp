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
map<int, vector<int>> cosos;
map<int, map<int, int>> casos;
ll conv(string s)
{
	ll mul = 1000000000;
	ll num = 0;
	fore(i, 0, (int)s.size())
	{
		num *= 10;
		num += s[i] - '0';
		mul /= 10;
	}
	return num * mul;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	ll a, b, g;
	ll uni = 0;
	char ch;
	string s, so;
	cin.ignore();
	while(n--)
	{
		getline(cin, so);
		stringstream ss;
		ss << so;
		ss>>a;
		s = "";
		if(ss >> ch)
		{
			ss >> s;
		}
		a = a * 1000000000 + conv(s);
		g = __gcd(a, MOD - 7ll);
		//cout<<a<<' ';
		a /= g;
		b = (MOD - 7) / g;
		//cout<<a<<' '<<b<<'\n';
			cosos[b].pb(a);
		if(b == 1)
			uni++;
	}
	int box;
	for(auto cat : cosos)
	{
		fore(j, 0, (int)cat.s.size())
		{
			//cout<<cat.s[j]<<' ';
			box = cat.s[j];
			for(int k = 1; k * k <= box && k < 10000; k++)
			{
				if(box % k == 0)
				{
					if((int)cosos[k].size() > 0)
						casos[k][cat.f]++;
					if((int)cosos[box / k].size() > 0 && k != box / k)
						casos[box / k][cat.f]++;
				}
			}
		}
	}
	//cout<<'\n';
	ll res = 0, ras = 0;
	for(auto cat : cosos)
	{
		if((int)casos[cat.f].size() > 0)
		fore(j, 0, (int)cat.s.size())
		{
			box = cat.s[j];
			for(int k = 1; k * k <= box; k++)
			{
				if(box % k == 0)
				{
					{
						if(k != box / k)
						res += casos[cat.f][box / k];
						res += casos[cat.f][k];
					}
				}
			}
		}
	}
	cout<<(res - uni) / 2<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	 	