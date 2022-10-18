#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
bool used[tam];
vector<int> chi[tam];
int ar[tam];
int rus[tam];
int can[tam];
int gon(int nu)
{
	int res = 0;
	if(used[nu]) return rus[nu];
	used[nu] = 1;
	for(int x : chi[nu])
	{
		res = max(res, gon(x));
	}
	return rus[nu] = res + can[nu];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int t, n;
	cin>>t;
	while(t--)
	{
		mem(can, 0);
		mem(used, 0);
		fore(i, 0, tam)
			chi[i].clear();
		cin>>n;
		fore(i, 0, n)
		{
			cin>>ar[i];
			can[ar[i]]++;
		}
		sort(ar, ar + n);
		fore(i, 0, n)
		{
			if(!used[ar[i]])
			{
				used[ar[i]] = 1;
				forg(j, ar[i] + ar[i], tam, ar[i])
				{
					if(can[j] > 0)
						chi[ar[i]].pb(j);
				}
			}
		}
		int res = 0;
		mem(used, 0);
		mem(rus, 0);
		fore(i, 0, n)
		{
			res = max(res, gon(ar[i]));
		}
		cout<<n - res<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	