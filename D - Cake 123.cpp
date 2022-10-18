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
const int tam = 10000010;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll ar[3][1000], ta[3], k;
	fore(i, 0, 3)
		cin>>ta[i];
	cin>>k;
	fore(i, 0, 3)
	{
		fore(j, 0, ta[i])
			cin>>ar[i][j];
		sort(ar[i], ar[i] + ta[i]);
	}
	priority_queue<pair<ll, pair<int, pair<int, int> > > > que;
	que.push(mp(ar[0][ta[0] - 1] + ar[1][ta[1] - 1] + ar[2][ta[2] - 1], mp(ta[0]-1, mp(ta[1]-1, ta[2]-1))));
	int x, y, z;
	map<pair<int,pair<int,int>>, bool> visi;
	int con = 0;
	while(con < k)
	{
		x = que.top().s.f;
		y = que.top().s.s.f;
		z = que.top().s.s.s;
		cout<<que.top().f<<'\n';
		con++;
		que.pop();
		if(x > 0 && !visi[mp(x-1, mp(y, z))])
		{
			visi[mp(x-1, mp(y, z))] = 1;
			que.push(mp(ar[0][x-1] + ar[1][y] + ar[2][z], mp(x-1, mp(y, z))));
		}
		if(y > 0 && !visi[mp(x, mp(y-1, z))])
		{
			visi[mp(x, mp(y-1, z))] = 1;
			que.push(mp(ar[0][x] + ar[1][y-1] + ar[2][z], mp(x, mp(y-1, z))));
		}
		if(z > 0 && !visi[mp(x, mp(y, z-1))])
		{
			visi[mp(x, mp(y, z-1))] = 1;
			que.push(mp(ar[0][x] + ar[1][y] + ar[2][z-1], mp(x, mp(y, z-1))));
		}
	}
	return 	0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2