#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define MOD1		998244353
#define EPS			1e-9
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
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n,m;
	cin>>n>>m;
	int ma1[n][m], ma2[n][m], xo[n][m];
	for(int i = 0; i < n ; i++)
		for(int j = 0; j < m; j++)
		{
			cin>>ma1[i][j];
		}
		//cout<<'\n'<<'\n';
		vector<pair<int,int>> ve;
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin>>ma2[i][j];
			xo[i][j] = ma1[i][j]^ma2[i][j];
			if(xo[i][j])
				ve.pb(mp(i,j));
		}
		//cout<<'\n';
	}
	sort(ve.begin(), ve.end());
	for(int i = 1; i < ve.size(); i++)
	{
		if(ve[i].f != ve[0].f && ve[i].s != ve[0].s)
		{
			xo[ve[0].f][ve[0].s] ^= 1;
			xo[ve[i].f][ve[0].s] ^= 1;
			xo[ve[0].f][ve[i].s] ^= 1;
			xo[ve[i].f][ve[i].s] ^= 1;
		}
	}
	int con = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			con += xo[i][j];
	if(con == 0)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS