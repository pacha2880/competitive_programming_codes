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
string tab[10000];
bool mar[100010];
	int n, m;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n>>m;
	fore(i, 0, n)
		cin>>tab[i];
	int b, e;
	vector<pair<int, int>> go, ngo;
	go.pb({0, n});
	int res = 0;
	bool bo;
	char ch;
	int can;
	fore(pos, 0, m)
	{
		bo = false;
		ngo.clear();
		fore(k, 0, go.size())
		{
			//cout<<pos<<' '<<k<<' '<<go[k].f<<' '<<go[k].s<<'\n';
			b = go[k].f, e = go[k].s;
			ch = tab[b][pos];
			can = 1;
			fore(i, b + 1, e)
			{
				if(tab[i][pos] == ch)
					can++;
				else if(tab[i][pos] > ch)
				{
					if(can > 1)
					{
						//cout<<i - can<<' '<<i<<'\n';
						ngo.pb({i - can, i});
					}
					can = 1;
					ch = tab[i][pos];
				}
				else
				{
					bo = true;
					break;
				}
			}
			if(can > 1)
			{
				//cout<<e - can<<' '<<e<<'\n';
				ngo.pb({e - can, e});
			}
			if(bo)
			{
				res++;
				break;
			}
		}
		//cout<<bo<<'\n';
		if(!bo)
			go = ngo;	
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	