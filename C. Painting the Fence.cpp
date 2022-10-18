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
#define fore(i, b, e)	for(ll i = b; i < e; i++)
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
pair<int, int> ar[5050];
int pin[5050], un[5050], pre[5050];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, q;
	cin>>n>>q;
	fore(i, 0, q) 
	{
		cin>>ar[i].f>>ar[i].s;
		ar[i].f--;
		ar[i].s--;
		fore(j, ar[i].f, ar[i].s + 1)
			pin[j]++;
	}
	int tot = 0;
	fore(i, 0, n)
		if(pin[i])
			tot++;
	int con, res = 100000, ra, man;
	fore(i, 0, q)
	{
		ra = 0;
		fore(j, ar[i].f, ar[i].s + 1)
		{
			pin[j]--;
			if(pin[j] == 0)
				ra++;
		}
		fore(j, 0, n)
		{
			un[j] = (pin[j] == 1 ? 1 : 0);
			if(j == 0)
				pre[j] = un[j];
			else
				pre[j] = pre[j-1] + un[j];
		}
		man = 100000;
		fore(j, 0, q)
		{
			if(i != j)
			{
				man = min(man,pre[ar[j].s] - (ar[j].f == 0 ? 0 : pre[ar[j].f-1]));
			}
		}
		res = min(res, ra + man);
		fore(j, ar[i].f, ar[i].s + 1)
			pin[j]++;
	}
	cout<<tot - res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	