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
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
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
const int logTam = 21;
int n; 
int ar[tam], table[logTam][tam], maxp[tam], maxs[tam];
void inispar()
{
	fore(i, 0, n) table[0][i] = ar[i];
	for(int k = 0; (1 << k) < n; k++)
		for(int i = 0; i + (1 << k) < n; i++)
			table[k + 1][i] = min(table[k][i], table[k][i + (1 << k)]);
}
int query(int b, int e)
{
	int lev = 31 - __builtin_clz(e - b + 1);	
	return min(table[lev][b], table[lev][e - (1 << lev) + 1]);	
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int cas;
	cin>>cas;
	while(cas--)
	{
		cin>>n;
		fore(i, 0, n)
		{
			cin>>ar[i];
			if(i == 0)
				maxp[i] = ar[i];
			else
				maxp[i] = max(maxp[i - 1], ar[i]);
		}
		inispar();
		maxs[n - 1] = ar[n - 1];
		for(int i = n - 2; i > -1; i--)
			maxs[i] = max(maxs[i + 1], ar[i]);
		int lo, hi, mid, res, res1;
		bool bo = true;
		int que;
		fore(i, 0, n - 2)
		{
			lo = i + 2, hi = n - 1, res = -1;
			while(lo <= hi)
			{
				mid = (lo + hi) / 2;
				if(maxs[mid] <= maxp[i])
					res = mid, hi = mid - 1;
				else
					lo = mid + 1;
			}
			que = query(i + 1, res - 1);
			if(res != -1 && maxs[res] == maxp[i])
			{
				if(que == maxp[i])
				{
					cout<<"YES\n";
					cout<<i + 1<<' '<<res - i - 1<<' '<<n - res<<'\n';
					bo = false;
					break;	
				}
				else if(que > maxp[i] && res < n - 1 && ar[res] == maxp[i] && maxs[res + 1] == maxp[i])
				{
					cout<<"YES\n";
					cout<<i + 1<<' '<<res - i<<' '<<n - res - 1<<'\n';
					bo = false;
					break;	
				}
			}
		}
		if(bo)
			cout<<"NO\n";
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	