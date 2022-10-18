#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD				1000000007
#define MOD1			998244353
#define EPS				1e-12
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

int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	double x1, y1, x2, y2, x, y, vx, vy, ti = 0, tf = 1e15, t1, t2;
	cin>>x1>>y1>>x2>>y2;
	while(n--)
	{
		cin>>x>>y>>vx>>vy;
		if(fabs(vx) < EPS)
		{
			if(x > x1 + EPS && x < x2 - EPS)
			{
				t1 = 0, t2 = 1e15;
			}
			else
			{
				cout<<-1;
				return 0;
			}
		}
		else
		{
			t1 = (x1 - x) / vx;
			t2 = (x2 - x) / vx;
			if(t1 > t2)
				swap(t1, t2);
		}
		ti = max(ti, t1);
		tf = min(tf, t2);
		if(fabs(vy) < EPS)
		{
			if(y > y1 + EPS && y < y2 - EPS)
			{
				t1 = 0, t2 = 1e15;
			}
			else
			{
				cout<<-1;
				return 0;
			}
		}
		else
		{
			t1 = (y1 - y) / vy;
			t2 = (y2 - y) / vy;
			if(t1 > t2)
				swap(t1, t2);
		}
		ti = max(ti, t1);
		tf = min(tf, t2);
	}
	//cout<<tf<<' '<<ti<<'\n';
	if(tf > ti + EPS)
		cout<<fixed<<setprecision(7)<<ti<<'\n';
	else
		cout<<-1;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2