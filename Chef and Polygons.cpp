#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
struct point
{
	ll x, y;
	point(ll x = 0, ll y = 0) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
};
bool intri(point a, point b, point c, point p)
{
	if(((b - a) ^ (c - a)) < 0)
		swap(b, c);
	/*cout<<a.x<<' '<<a.y<<'\n';
	cout<<b.x<<' '<<b.y<<'\n';
	cout<<c.x<<' '<<c.y<<'\n';
	cout<<p.x<<' '<<p.y<<'\n';
	cout<<((b - a) ^ (p - a))<<'\n';
	cout<<((c - b)^(p - b))<<'\n';
	cout<<((a - c) ^ (p - c))<<'\n';*/
	bool bo =  (((b - a) ^ (p - a)) > 0) && (((c - b)^(p - b)) > 0) && (((a - c) ^ (p - c)) > 0);
	//cout<<"res "<<bo<<'\n';
	return bo;
}
int can[200][200];
point ro[200], ne[4000];
int area(int ina, int inb, int inc)
{
	point a = ro[ina], b = ro[inb], c = ro[inc];
	int res = 0;
	res += (((a - ro[0]) ^ (b - ro[0])) < 0 ? 1 : -1) * can[ina][inb];
	res += (((b - ro[0]) ^ (c - ro[0])) < 0 ? 1 : -1) * can[inb][inc];
	res += (((c - ro[0]) ^ (a - ro[0])) < 0 ? 1 : -1) * can[inc][ina];
	return abs(res);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	fore(i, 0, n) cin>>ro[i].x>>ro[i].y;
	fore(i, 0, m) cin>>ne[i].x>>ne[i].y;
	fore(i, 0, n)
		fore(j, 0, m)
			can[i][j] = 0;
	fore(i, 1, n)
		fore(j, i + 1, n)
		{
			fore(k, 0, m)
			{
				if(intri(ro[0], ro[i], ro[j], ne[k]))
				{
					//cout<<i<<' '<<j<<' '<<k<<'\n';
					can[i][j]++;
					can[j][i]++;
				}
			}
		}
		/*cout<<'\n';
	fore(i, 0, n)
	{
		fore(j, 0, n)
			cout<<can[i][j]<<' ';
		cout<<'\n';
	}
	cout<<'\n';*/
	int q;
	cin>>q;
	int ta;
	while(q--)
	{
		cin>>ta;
		int ar[ta];
		ll res = 0;
		fore(i, 0, ta) {cin>>ar[i]; ar[i]--;}
		fore(i, 1, ta - 1)
		{
			res += area(ar[0], ar[i], ar[i+1]);
		}
		cout<<res<<'\n';

	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2