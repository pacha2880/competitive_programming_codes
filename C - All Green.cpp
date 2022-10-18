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
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	ll g, ax;
	cin>>n>>g;
	int ar[n], val[n];
	fore(i, 0, n) cin>>ar[i]>>val[i];
	int res = 10000000, can;
	for(int i = 0; i < (1<<n); i++)
	{
		ax = g;
		can = 0;
		fore(j, 0, n)
		{
			if((1<<j) & i)
			{
				can += ar[j];
				ax -= (j+1) * 100 * ar[j] + val[j];
			}
		}
		if(ax <= 0)
			res = min(res, can);
		else
		{
			fore(j, 0, n)
			{
				if(!((1<<j) & i))
				{
					if(ax <= (j+1) * 100 * ar[j] + val[j])
					{
						if(ax <= (j+1) * 100 * ar[j])
						{
							res = min((ll)res, can + ax / ((j+1) * 100) + (ax % ((j+1) * 100) > 0? 1: 0));
						}
						else
							res = min(res, can + ar[j]);
					}
				}
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2