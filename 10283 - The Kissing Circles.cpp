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

typedef long double 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
ll area(ll a, ll b, ll c)
{
	ll s = (a + b + c) / 2;
	return sqrt(s * (s - a) * (s - b) * (s - c));
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	long double R, n;
	cout<<fixed<<setprecision(10);
	while(cin>>R)
	{
		cin>>n;
		if(fabs(n - 1) < EPS)
		{
			cout<<(double)R<<' '<<0.0<<' '<<0.0<<'\n';
			continue;
		}
		if(fabs(n - 2) < EPS)
		{
			cout<<(double)(R / 2)<<' '<<0.0<<' '<<(double)(R * R * PI / 2)<<'\n';
			continue;
		}
		long double al = PI / n;
		long double r = (R * sin(al)) / (1 + sin(al));
		long double an = (n - 2) * PI / (2 * n);
		long double ver = (area(R - r, R - r, 2 * r) - r * r * an) * n;
		long double zu = R * R * PI - r * r * PI * n - ver;
		cout<<(double)r<<' '<<(double)ver<<' '<<(double)zu<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2