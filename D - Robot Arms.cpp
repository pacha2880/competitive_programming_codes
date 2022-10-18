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
const int tam = 100010;int ara[100010], arb[100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	string dir = "DULR";
	int ar[31];
	ll d[31];
	d[0] = 1;
	fore(i, 1, 31)
		d[i] = d[i -1] * 2;
	bool bo = false;
	pair<int,int> que[n];
	fore(i, 0, n) cin>>que[i].f>>que[i].s;
	fore(i, 0, n-1)
	{
		if((abs(que[i].f + que[i].s) % 2) != (abs(que[i+1].f + que[i+1].s) % 2))
		{
			cout<<"-1\n";
			return 0;
		}
	}
	bo = ((que[0].f + que[0].s) % 2) == 0;
	cout<<31 + bo<<'\n';
	if(bo) cout<<1<<' ';
	fore(i, 0, 31)
	{
		if(i > 0) cout<<' ';
		cout<<d[i];
	}
	cout<<'\n';
	fore(i, 0, n)
	{
		ll a = que[i].f, b = que[i].s;
		ll su = abs(a) + abs(b);
		string res = "";
		if(bo)
		{
			res += "L";
			su+= (a < 0 ? -1 : 1);
			a++;
		}
		int sen = 1;
		for(int i = 30; i > -1; i--)
		{
			ar[i] = sen;
			if(d[i] > su)
				sen = abs(sen-1);
			su = abs(su - d[i]);
		}
		ll va = 0;
		fore(i, 0, 31)
		{
			if(ar[i])
				va += d[i];
			else
				va -= d[i];
		}
		//cout<<va<<'\n';
		ll ax = abs(a);
		fore(i, 0, 31)
		{
			if(ax & d[i])
			{
				ax += (ar[i] ? -1 : 1) * d[i];
				ar[i] += 2;
			}
		}
		fore(i, 0, 31)
		{
			if(b < 0)
			{
			if((ar[i] < 2))
			{
				ar[i] = abs(ar[i] - 1);
			}	
		}
			if( a < 0)
			{
				if(ar[i] > 1)
				{
					if(ar[i] == 2)
						ar[i] = 3;
					else
						ar[i] = 2;
				}
			}
		}
		fore(i, 0, 31)
			res += dir[ar[i]];
			cout<<res<<'\n';
			ll x = 0, y = 0;

	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2