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
	int n;
	cin>>n;
	int co[2][n];
	int a;
	cin>>a;
	if(a == 1)
		co[0][0] = 1, co[1][0] = 0;
	else
		co[1][0] = 1, co[0][0] = 0;
	int ar[n];
	ar[0] = a;
	fore(i, 1, n)
	{
		cin>>a;
		ar[i] = a;
		co[0][i] = co[0][i-1];
		co[1][i] = co[1][i-1];
		co[a == 2][i]++;
	}
	int cx = 0, cy = 0, lo, hi, mid, res, ac, au, px, py, can;
	vector<pair<int, int>> v;
	bool bo;
	fore(i, 0, n)
	{
		bo = false;
		if(ar[i] == 1)
		{
			cx++;
			bo = cx > cy;
		}
		else
		{
			cy++;
			bo = cy > cx;
		}
		if(bo)
		{
			ac = i+1;
			px = py = 0;
			if(cx > cy)
			{
				px = 1;
				au = cx;
			}
			else
			{
				py = 1, au = cy;
			}
			while(ac < n)
			{
				lo = ac, hi = n-1, res = -1;
				while(lo <= hi)
				{
					mid = (lo + hi) / 2;
					if(co[0][mid] - co[0][ac-1] >= au || co[1][mid] - co[1][ac-1] >= au)
						res = mid, hi = mid - 1;
					else
						lo = mid + 1;
				}
				if(res == -1) {ac = n + 1; break;}
				can++;
				if(co[0][res] - co[0][ac-1] == au)
					px++;
				else
					py++;
				//cout<<'#'<<ac<<' '<<res<<' '<<px<<' '<<py<<' '<<co[0][res] <<' '<<co[0][ac-1]<< '\n';
				ac = res + 1;
			}
			//cout<<px<<' '<<py<<' '<<i<<'\n';
			if(ac == n && px != py)
			{
				if(px > py && ar[n-1] == 1 || py > px && ar[n-1] == 2)
				v.pb(mp(max(px, py), au));
			}
		}
	}
	cout<<v.size()<<'\n';
	sort(all(v));
	fore(i, 0, v.size())
	cout<<v[i].f<<' '<<v[i].s<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2