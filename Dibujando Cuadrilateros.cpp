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
struct point 
{
	double x, y;
	point() {}
	point(double x, double y) : x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	double operator ^(point p) {return x * p.y - y * p.x;}
	double norm() {return hypot(x, y);}
};
double an[2020];
point ar[2020];
int ord[4020];
ll cons[2020];
void calan(int cen, int n)
{
	point p = ar[n] - ar[cen];
	an[n] = atan2(p.y, p.x);
}
bool comp(int a, int b)
{
	return an[a] < an[b] - EPS;
}
	ll n;
bool ang(int a, int b)
{
	return ((ar[ord[a]]-ar[ord[0]]) ^ (ar[ord[b]]-ar[ord[0]])) > EPS;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n;
	fore(i, 0, n) cin>>ar[i].x>>ar[i].y;
	ll re = 0, su = 0;
	//cout<<fixed<<setprecision(2);
	//cout<<asin(0.5)<<' '<<asin(0)<<'\n';
	fore(i, 0, n)
	{
		an[i] = -1e9;
		fore(j, 0, n)
		{
			ord[j] = j;
			if(i != j)
				calan(i, j);
		}
		/*fore(i, 0, n)
		cout<<an[i]<<'\n';*/
		sort(ord, ord + n, comp);
		int co = 1;
		int has = 0;
		bool bo = 1;
		su = 0;
		fore(i, n, 2 * n - 1) ord[i] = ord[i - n + 1];
		//cout<<ar[ord[0]].x<<' '<<ar[ord[0]].y<<'\n';
		fore(i, 1, n)
		{
			co = max(co, i+1);
			while(ang(i, co))
			{
				//cout<<co<<' ';
				//cout<<su<<'/';
			co++;
			}
			co--;
			ll x = co - i;
			su += x * (x-1) / 2;
			//cout<<su<<' ';
		}
		//cout<<su<<'\n';
		re += (n-1)*(n-2)*(n-3)/2/3 - su;
		//cout<<'\n';

	}
	//cout<<re<<'\n';
	cout<<n*(n-1)*(n-2)*(n-3) / 2 / 3 / 4  - re<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2