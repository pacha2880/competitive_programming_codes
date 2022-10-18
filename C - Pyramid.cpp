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
#define EPS				1e-9
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
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	pair<pair<int,int>, int> ar[n];
	fore(i, 0 , n) cin>> ar[i].f.f>>ar[i].f.s>>ar[i].s;
	bool bo;
	int x, y, h;
	int po;
	fore(i, 0, 101)
		fore(j, 0, 101)
		{
			bo = true;
			x = i, y = j;
			po = 0;
			while(po < n && ar[po].s == 0)
			{
				po++;
			}
			if(po == n)
			{
				fore(i, 0, 101)
					fore(j, 0, 101)
					{
						fore(k, 0, n)
						{
							if(i != ar[k].f.f || j != ar[k].f.s)
							{
								cout<<i<<' '<<j<<' '<<1<<'\n';
								return 0;
							}
						}
					}
			}
			h = abs(x - ar[po].f.f) + abs(y - ar[po].f.s) + ar[po].s;
			fore(k, 0, n)
			{
				if(ar[k].s == 0)
				{
					if(abs(x - ar[k].f.f) + abs(y - ar[k].f.s) < h)
					{
						bo = false;
						break;
					}
				}
				else if(abs(x - ar[k].f.f) + abs(y - ar[k].f.s) + ar[k].s != h)
				{
					bo = false; break;
				}
			}
			if(bo && h > 0)
			{
				cout<<x<<' '<<y<<' '<<h<<'\n';
				return 0;
			}
		}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2