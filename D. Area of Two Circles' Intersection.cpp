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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
ld EPS = 1e-9;
const ld PI = acosl(-1); 
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	ll x1, y1, r1, d, x2, y2, r2;
	cin>>x1>>y1>>r1>>x2>>y2>>r2;
	d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	if(d > (r1 + r2) * (r1 + r2))
		cout<<0<<'\n';
	else
	{
		if(r1 < r2)
		{
			swap(r1, r2);
		}
		EPS = r1*r1 / 1e15;
		if(r1*r1 > d + r2 * r2 + 2 * r2 * sqrtl(d) - EPS)
			cout<<fixed<<setprecision(6)<<(double)(r2 * r2 * PI)<<'\n';
		else
		{
			ld a1 = acosl((d - r2 * r2 + r1 * r1) / (2 * r1 * sqrtl(d)));
			ld a2 = acosl((d + r2 * r2 - r1 * r1) / (2 * r2 * sqrtl(d)));
			//cout<<(double)a1*180/PI<<' '<<(double)a2*180/PI<<'\n';
			ld ar1 = r1 * r1 * a1 - r1 * r1 * sinl(2 * a1) / 2;
			ld ar2 = r2 * r2 * a2 - r2 * r2 * sinl(2 * a2) / 2;
			cout<<fixed<<setprecision(6)<<(double)(ar1 + ar2)<<'\n';
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	