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
const char INF = 100;

pair<int, int> act[tam], neu[tam], pro[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	map<int, vector<int>> ma;
	int a, b;
	fore(i, 0, m)
	{
		cin>>a>>b;
		ma[a].pb(b);
	}
	if(!ma.count(n))
		ma[n] = {0, n + 1};
	int la = 1, sact = 2, sneu = 0, from;
	ma[1].pb(n + 1);
	sort(all(ma[1]));
	act[0] = {1, 0};
	act[1] = {ma[1][0] - 1, 2};
	bool pren, prea, preb;
	for(auto cat : ma)
	{
		if(cat.f == 1) continue;
		cat.s.pb(0);
		cat.s.pb(n + 1);
		sort(all(cat.s));
		sneu = 0;
		fore(i, 1, cat.s.size())
		if(cat.s[i] - 1 > cat.s[i - 1])
		{
			neu[sneu++] = {cat.s[i - 1] + 1, 1};
			neu[sneu++] = {cat.s[i] - 1, 3};
		}
			//cout<<"el neu \n";
			//fore(i, 0, sneu)
			//	cout<<neu[i].f<<' '<<neu[i].s<<'\n';
			//	cout<<"fin neu\n";
		if(sneu == 0)
		{
			cout<<-1<<'\n';
			return 0;
		}
		if(cat.f - 1 > la)
		{
			int ind = -1;
			forg(i, 1, sneu, 2)
			{
				if(neu[i].f >= act[0].f)
				{
					ind = i - 1;
					break;
				}
			}
			//cout<<"el ind "<<neu[ind].f<<'\n';
			if(ind == -1)
			{
				cout<<-1<<'\n';
				return 0;
			}
			act[0] = {max(neu[ind].f, act[0].f), 0};
			fore(i, ind + 1, sneu)
				act[i - ind] = {neu[i].f, neu[i].s - 1};
			sact = sneu - ind;
		}
		else
		{
			fore(i, 0, sact)
			{
				neu[sneu++] = act[i];
			}
			sact = 0;
			sort(neu, neu + sneu);
			pren = prea = preb = 0;
			fore(i, 0, sneu)
			{
				if(neu[i].s == 0)
				{
					prea = 1;
					if(preb && !pren)
					{
						pren = 1;
						from = neu[i].f;
					}
				}
				else if(neu[i].s == 1)
				{
					preb = 1;
					if(prea)
					{
						pren = 1;
						from = neu[i].f;
					}
				}
				else if(neu[i].s == 2)
				{
					prea = 0;		
				}
				else
				{
					preb = 0;
					if(pren)
					{
						act[sact++] = {from, 0};
						act[sact++] = {neu[i].f, 2};
						pren = 0;
					}
				}
			}
		}
		if(sact == 0)
		{
			cout<<-1;
			return 0;
		}
		//cout<<cat.f<<'\n';
		//fore(i, 0, sact)
		//{
		//	cout<<act[i].f<<' '<<act[i].s<<'\n';
		//}
		la = cat.f;
	}
	if(sact > 0 && act[sact - 1].f == n)
		cout<<2 * n - 2<<'\n';
	else
		cout<<-1<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	