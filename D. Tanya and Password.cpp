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

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	map<string, vector<string>> g;
	map<string, int> in, out;
	int n;
	string s;
	cin>>n;
	fore(i, 0, n)
	{
		cin>>s;
		g[s.substr(0, 2)].pb(s.substr(1, 2));
		out[s.substr(0, 2)]++;
		in[s.substr(1, 2)]++;
		in[s.substr(0, 2)] = in[s.substr(0, 2)];
		//cout<<s.substr(1, 2)<<'\n';
	}
	s = s.substr(0, 2);
	vector<pair<pair<int, int>, string>> dif;
	for(auto pa : in)
	{
		//cout<<pa.f<<' '<<pa.s<<' '<<out[pa.f]<<'\n';
		if(pa.s != out[pa.f])
		{
			dif.pb(mp(mp(pa.s, out[pa.f]), pa.f));
		}
	}
	//cout<<dif.size()<<'\n';
	string la;
	if(dif.size() == 2 || dif.size() == 0)
	{
		if(dif.size() == 2)
		{
			//cout<<dif[0].f.f<<' '<< dif[0].f.s <<' '<< dif[1].f.f<<' '<< dif[1].f.s<<' '<<dif[0].s<<' '<<dif[1].s<<'\n';
			if(dif[0].f.f != dif[0].f.s - 1 || dif[1].f.f - 1 != dif[1].f.s)
			{
				swap(dif[0], dif[1]);
				if(dif[0].f.f != dif[0].f.s - 1 || dif[1].f.f - 1 != dif[1].f.s)
				{
					cout<<"NO\n";
					return 0;
				}
				else
					la = dif[1].s;
			}
			else
				la = dif[1].s;
			s = dif[0].s;
		}
		string ax, ox;
		vector<string> neo;
		vector<string> road;
		road.pb(s);
		map<string, int> po;
		for(auto pa : g)
			po[pa.f] = 0;
		while(road.size() > 0)
		{
			s = road.back();
			if(po[s] == g[s].size())
			{
				neo.pb(s);
				road.pop_back();
			}
			else
			{
				road.pb(g[s][po[s]++]);
			}
		}
		string res = "";
		res = neo[neo.size()-1];
		for(int i = neo.size()-2; i > -1; i--)
			res += neo[i][1];
		//cout<<res<<'\n';
			if(res.size() == n + 2)
				cout<<"YES\n"<<res<<'\n';
			else
				cout<<"NO\n";
	}
	else
	{
		cout<<"NO\n";
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	