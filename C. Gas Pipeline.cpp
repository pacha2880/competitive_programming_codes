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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas;
	cin>>cas;
	while(cas--){
		ll n, a, b;
		cin>>n>>a>>b;
		string s;
		cin>>s;
		ll cos = b;
		bool bo = true, bu = true;
		int lau = -1;
		fore(i, 1, n-1)
		{
			if(s[i] == '1')
			{
				if(bu)
				{
					cos += 4 * b + 2 * a + i * a + (i-1)*b;
					bu = false;
				}
				else if(bo)
				{
					if(i - lau >= 3)
					{
						if((i - lau - 1) * a + (i - lau - 2) * b * 2 < (i - lau- 1) * a + 2 * a + (i - lau - 2) * b)
						{
							cos += (i - lau - 1) * a + (i - lau - 2) * b * 2 + 4 * b + a;
						}
						else
							cos += (i - lau- 1) * a + 2 * a + (i - lau - 2) * b + 4*b + a;
					}
					else
					{
						cos += 4 * b + 2 * a;
					}
				}
				else
					cos += a + 2 * b;
				bo = false;
				lau = i;
			}
			else
				bo = true;
		}
		if(!bu)
		{
			cos += (n-1 - lau) * a + a + (n-1 - lau) * b;
		}
		else
			cos += n * a + n * b;
		cout<<cos<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2