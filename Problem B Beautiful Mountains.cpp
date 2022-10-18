#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1);

int ar[tam];
int ind[tam];
int pis[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, a, la = MOD;
	cin>>n;
	int in = 0, fru = -1;
	bool meu = false;
	int mam = MOD, frm = 0;;
	fore(i, 0, n)
	{
		cin>>ar[i];
		if(meu)
		{
			if(ar[i] != -1)
			{
				mam = min(mam, ar[i]);
				fore(j, frm, i)
					ar[j] = mam;
				meu = false;
			}
		}
		else
		{
			if(ar[i] == -1)
			{
				meu = true;
				frm = i;
				mam = la;
			}
		}
		la = ar[i];
	}
	la = -1;
	bool su = true;
	fore(i, 0, n)
	{
		cout<<ar[i]<<' ';	
		a = ar[i];
		if(su)
		{
			if(a < la)
			{
				su = false;
			}
		}
		else
		{
			if(a > la)
			{
				in++;
				// cout<<fru<<' '<<i<<'\n';
				fore(j, fru, i)
					pis[j] = 1;
				su = 1;
			}
		}
		ind[i] = in;
		if(a != la) fru = i;
		la = a;
	}
	cout<<'\n';
	fore(i, 0, n) cout<<ind[i]<<' ';
	cout<<'\n';
	fore(i, 0, n) cout<<pis[i]<<' ';
	cout<<'\n';
	bool res = false;
	fore(x, 3, n + 1)
	{
		if(x <= n && (n % x == 0 || n % x >= 3))
		{
			// cout<<x<<'\n';
			bool ru = true;
			la = -1;
			forg(i, 0, n, x)
			{
				// cout<<i<<' '<<pis[i]<<' ';
				if(i + x < n)
				{
					if(ind[i] != ind[i + x - 1])
					{
						// cout<<ind[i + x - 1]<<'\n';
						if(!pis[i] || ind[i + x - 1] > ind[i] + 1)
							ru = false;
					}
					// else
					// 	cout<<"igual\n";
				}
				else
				{
					if(ind[i] != ind[n - 1])
					{
						// cout<<ind[n - 1]<<'\n';
						if(!pis[i] || ind[n - 1] > ind[i] + 1)
							ru = false;
					}	
				}
			}
			res |= ru;
			if(ru)
				cout<<x<<'\n';
		}
	}
	if(res)
		cout<<"Y\n";
	else
		cout<<"N\n";
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil