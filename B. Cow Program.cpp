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
int visited[200005], ar[200005],n;
ll add[200005];
void dfs(int pos)
{
	if(pos + ar[pos] > n )
	{
		add[pos] = ar[pos];
		visited[pos] = 2;
		return;
	}
	add[pos] = ar[pos];
	if(pos + ar[pos] - ar[pos+ar[pos]] < 1)
	{
		add[pos] += ar[pos+ar[pos]];
		visited[pos] = 2;
		return;
	} 
	if(pos + ar[pos] - ar[pos+ar[pos]] == 1)
	{
		add[pos] = -1;
		visited[pos] = 2;
		return;
	} 
	if(visited[pos + ar[pos] - ar[pos+ar[pos]]] == 1)
	{
		add[pos] = -1;
		visited[pos] = 2;
		return;
	}
	if(visited[pos + ar[pos] - ar[pos+ar[pos]]] == 2)
	{
		if(add[pos + ar[pos] - ar[pos+ar[pos]]] == -1)
			add[pos] = -1;
		else
			add[pos] += ar[pos+ar[pos]] + add[pos + ar[pos] - ar[pos+ar[pos]]];
		visited[pos] = 2;
		return;
	}
	add[pos] += ar[pos+ar[pos]];
	visited[pos] = 1;
	dfs(pos + ar[pos] - ar[pos+ar[pos]]);
	if(add[pos + ar[pos] - ar[pos+ar[pos]]] == -1)
		add[pos] = -1;
	else
		add[pos] += add[pos + ar[pos] - ar[pos+ar[pos]]];
	visited[pos] = 2;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	mem(visited,-1);
	mem(add,0);
	cin>>n;
	for(int i = 2; i <= n; i++)
		cin>>ar[i];
	for(int i = 2; i <= n ; i++)
	{
		if(visited[i] == -1)
			dfs(i);
	}
	int asd,bsd;
	for(int i = 2; i <= n; i++)
	{
		asd = i-1, bsd = i;
		if(bsd - ar[i] < 1)
		{
			cout<<asd+ar[i]<<'\n'; continue;
		}
		if(bsd - ar[i] == 1)
		{
			cout<<-1<<'\n'; continue;
		}
		asd += ar[i];
		bsd -= ar[i];
		if(add[bsd] == -1)
			cout<<-1;
		else
			cout<<asd + add[bsd];
		cout<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS