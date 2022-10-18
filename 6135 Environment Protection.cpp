#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
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
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
double de;
int k;
double p[2][10], q[2][10];
double f(double x, int ti)
{
	double a = 0, b = 0;
	double ax = 1;
	fore(i, 0, k+1)
	{
		a += ax * p[ti][i];
		b += ax * q[ti][i];
		ax *= x;
	}
	return max(a / b + de, 0.0);
}
double simpson(double f(double, int), double a, double b, int in)
{
	int n = 100000;
	double s = f(a, in) + f(b, in);
	double h = (b - a) / n;
	fore(i, 1, n)
		s += ((i & 1) ? 4 : 2) * f(a + h * i, in);
	return s * (h / 3);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	double w, d, a;
	cout<<fixed<<setprecision(5);
	while(cin>>w)
	{
		cin>>d>>a>>k;
		fore(i, 0, 2)
		{ 
			fore(j, 0, k+1) cin>>p[i][j];
			fore(j, 0, k+1) cin>>q[i][j];
		}
		double lo = 0, hi = d;
		de = d;
		//cout<<f(6,0)<<' '<<f(6,1)<<'\n';
		//cout<<simpson(0, w, 0)<<' '<< simpson(0, w, 1)<<'\n';;
		fore(i, 0, 30)
		{
			de = (lo + hi) / 2;
			//cout<<lo<<' '<<hi<<' '<<de<<' '<<simpson(0, w, 0)<<' '<< simpson(0, w, 1)<<'\n';;
			if(simpson(f, 0, w, 0) - simpson(f, 0, w, 1) > a)
				hi = de;
			else
				lo = de;
		}
		cout<<hi<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2 	