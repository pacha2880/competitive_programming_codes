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
const ll MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int poa[10000001], pob[10000001], poad[10000001], pobd[10000001];
ll pot(ll b, ll e, ll m)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % m;
		b = b * b % m;
		e /= 2;
	}
	return res;
}
ll x, y, d;
void extendedEuclid(ll a, ll b)//ecuacion diofantica ax + by = 1
{
	if(b==0) {x=1; y=0; d=a; return;}
	extendedEuclid(b,a%b);
	ll x1=y;
	y = x-(a/b)*y;
	x=x1;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int m, h1, a1, x1, y1, h2, a2, x2, y2;
	cin>>m;
	cin>>h1>>a1>>x1>>y1;
	cin>>h2>>a2>>x2>>y2;	
	poa[1] = x1;
	//cout<<"caca";
	if(x1 <= 1)
	{
		fore(i, 0, 10000001)
		{
			poa[i] = x1;
			poad[i] = (i + 1) % m;
		}
	}
	else
	{
		fore(i, 2, 10000001)
			poa[i] = 1ll* poa[i-1] * x1 % m;
		poad[0] = 1;
		fore(i, 1, 10000001)
			poad[i] = (poad[i-1] + poa[i]) % m;
	}
	//cout<<"caca";
	if(x2 <= 1)
	{
		fore(i, 0, 10000001)
		{
			pob[i] = x2;
			pobd[i] = (i + 1) % m;
		}
	}
	else
	{
		//cout<<"coco";
		pob[1] = x2;
		fore(i, 2, 10000001)
			pob[i] = 1ll* pob[i-1] * x2 % m;
		pobd[0] = 1;
		fore(i, 1, 10000001)
			pobd[i] = (pobd[i-1] + pob[i]) % m;
	}
	//cout<<"caca";
	ll a = -1, b = -1, pa = -1, pb = -1;
	fore(i, 1, 10000001)
	{
		if((1ll * poa[i] * h1 % m + 1ll * y1 * poad[i-1]) % m == a1 && a != -1 && pa == -1)
			pa = i - a;
		 if(  (1ll * pob[i] * h2 % m + 1ll * y2 * pobd[i-1]) % m == a2 && b != -1 && pb == -1)
		 	pb = i - b;
		if((1ll * poa[i] * h1 % m + 1ll * y1 * poad[i-1]) % m == a1 && a == -1)
			a = i;
		 if(  (1ll * pob[i] * h2 % m + 1ll * y2 * pobd[i-1]) % m == a2 && b == -1)
		 	b = i;
		/*if(i < 10)
		{
			cout<<i<<' '<<poad[i-1]<<' '<<poad[i]<<'\n';
			cout<<(1ll * poa[i] * h1 % m + 1ll * y1 * poad[i-1])<<' '<< (1ll * pob[i] * h2 % m + 1ll * y2 * pobd[i-1])<<'\n';
		}*/
		if((1ll * poa[i] * h1 % m + 1ll * y1 * poad[i-1]) % m == a1 &&  (1ll * pob[i] * h2 % m + 1ll * y2 * pobd[i-1]) % m == a2)
		{
			cout<<i;
			return 0;
		}
		 
	}
	//cout<<a<<' '<<pa<<' '<<b<<' '<<pb<<'\n';
	ll A = pa, B = -pb, C = b - a;
	extendedEuclid(A, B);
	ll a3 = B / d, b3 = A / d, X, Y;
	//cout<<"sfasdf     "<<x<<' '<<y<<' '<<d<<'\n';
	if(C % d != 0 || a == -1 || b == -1 || pa == -1 || pb == -1)
	{
		cout<<-1<<'\n';
	}
	else
	{
		x *= C / d;
		y *= C / d;
		ll re = MOD * MOD;
		//cout<<re<<'\n';
		ll gx, gy;
		for(ll i = 0; i < 10000001; i ++)
		{
			X = x + a3 * i, Y = y - b3 * i;
			if(X >= 0 && Y >= 0 && a + pa * X > 0)
			{
				/*if(re > a + pa * X)
				{
					cout<<i<<' '<<X<<' '<<a + pa * X<<'\n';
				}*/	
				re = min(re, a + pa * X);

			}
			X = x + a3 * (-i), Y = y - b3 * (-i);
			if(X >= 0 && Y >= 0 && a + pa * X > 0)
			{
				/*if(re > a + pa * X)
				{
					cout<<i<<' '<<X<<' '<<a + pa * X<<'\n';
				}*/	
				re = min(re, a + pa * X);
			}
		}
		if(re == MOD * MOD)
			cout<<"-1\n";
		else
			cout<<re<<'\n';
	}
	
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	