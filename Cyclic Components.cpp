	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
bool visited[200020];
map<int, vi> g;
map<int, vi> mp;
int dfs(int n,int k)
{
	if(!visited[n])
	{
		visited[n]=true;
		mp[k].push_back(n);
		for(int i=0;i<g[n].size();i++)
		{
			dfs(g[n][i],k);
		}
	}

}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int ari[200020],a,b;
	memset(visited,0,sizeof(visited));
	memset(ari,0,sizeof(ari));
	int n,k,x,y;
	cin>>n>>k;
	for(int i=0;i<k;i++)
	{
		cin>>a>>b;
		a--;
		b--;
		g[a].pb(b);
		g[b].pb(a);
		ari[a]++;
		ari[b]++;
	}
	for(int i=0;i<n;i++)
	{
		dfs(i,i);
	}
	map<int,vi>::iterator it;
	int con = 0;
	bool t;
	for(it=mp.begin();it!=mp.end();it++)
	{
		t = true;
		for(int i=0;i<it->second.size();i++)
		{
			if(ari[it->second[i]]!=2)
			{
				t = false;
				break;
			}
		}
		con+=t;
	}
	cout<<con;
	return 0;
}