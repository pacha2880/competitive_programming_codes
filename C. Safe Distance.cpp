#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
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
const int tam = 1010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const ld EPS = 1e-9;
const double PI = acos(-1); 
struct point
{
	ld x, y;
	point() {}
	point(ld x, ld y) : x(x), y(y) {}
	ld sq() {return x * x + y * y;}
	point operator -(point p) {return {x - p.x, y - p.y};}
};
point ar[tam];
int parent[tam];
int x, y, n;
int find(int n)
{
	if(parent[n] == -1) return n;
	return parent[n] = find(parent[n]);
}
bool f(ld rad)
{
	mem(parent, -1);
	int a, b;
	fore(i, 0, n)
	{
		if(ar[i].x - rad < EPS)
		{
			a = find(n), b = find(i);
			if(a != b)
				parent[a] = b;
		}
		if(ar[i].y - rad < EPS)
		{
			a = find(n + 1), b = find(i);
			if(a != b)
				parent[a] = b;
		}
		if(ar[i].x + rad > x - EPS)
		{
			a = find(n + 2), b = find(i);
			if(a != b)
				parent[a] = b;
		}
		if(ar[i].y + rad > y - EPS)
		{
			a = find(n + 3), b = find(i);
			if(a != b)
				parent[a] = b;
		}
		fore(j, i + 1, n)
		{
			if((ar[i] - ar[j]).sq() < 4 * rad * rad + EPS)
			{
				a = find(i), b = find(j);
				if(a != b)
					parent[a] = b;
			}
		}
	}
	return find(n) != find(n + 1) && find(n) != find(n + 2) &&
			find(n + 1) != find(n + 3) && find(n + 2) != find(n + 3);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>x>>y>>n;
	fore(i, 0, n)
		cin>>ar[i].x>>ar[i].y;
	ld lo = 0, hi = 1000000, mid;
	fore(i, 0, 100)
	{
		mid = (lo + hi) / 2;
		if(f(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout<<fixed<<setprecision(5)<<(double)mid<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	