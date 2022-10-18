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
ll ar[100010];
pair<ll, int> nuar[100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll n, ne, k, di, ala = 0;
	ll re = 0;
	cin>>n>>k;
	ne = n;
	map<ll, ll> ma;
	fore(i, 0, n) {cin>>ar[i]; ma[ar[i]]++; ala += ar[i];}
	if(ala < k)
	{
		cout<<"-1\n";
		return 0;
	}
	for(auto pa : ma)
	{
		if(k >= n * (pa.f - re))
		{
			k -= n * (pa.f - re);
			re += pa.f - re;
			n -= pa.s;
		}
		else
		{
			di = k / n;
			k -= n * di;
			re += di;
			break;
		}
	}
	int in = 0;
	fore(i, 0, ne)
	{
		if(ar[i] > re)
		{
			nuar[in++] = mp(ar[i] - re, i + 1);
		}
	}
	ne = n;
	fore(i, 0, k)
	{
		if(nuar[i].f == 1)
		{
			nuar[i].f = -1;
		}
		else
		{
			nuar[n++] = nuar[i];
			nuar[i].f = -1;
		}
	}
	bool bo = false;
	fore(i, 0, n)
	{
		if(bo) cout<<' ';
		if(nuar[i].f > 0)
		{
			cout<<nuar[i].s;
			bo = true;
		}
	}
	cout<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2