#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define EPS			1e-9
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m, a, b;
	cin>>n>>m;
	map<pair<int,int>,int> ma;
	vi in[n],out[n];
	for(int i = 0; i < m; i++)
	{
		cin>>a>>b;
		a--, b--;
		out[a].pb(b);
		in[b].pb(a);
	}
	for(int i = 0; i < n; i++)
		for(int j = 0; j < in[i].size(); j++)
			for(int k = 0; k < out[i].size(); k++)
				{
					if(in[i][j]!=out[i][k])
					{
						ma[mp(in[i][j],out[i][k])]++;
					}
				}
	map<pair<int,int>,int>::iterator it;
	ll res = 0,ax;
	for(it = ma.begin(); it != ma.end(); it++)
	{
		//cout<<(it->f).f+1<<' '<<(it->f).s+1<<' '<<it->s<<endl;
		ax = it->second;
		res+= (ax*(ax-1))/2;
	}
	cout<<res;

	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS