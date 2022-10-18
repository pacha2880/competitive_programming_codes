#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>	ii;
typedef vector<int>		vi;
vector<vi> graph;
int fin[500000],ord[500000];
int tree[500010],MaxVal;
int pos=0;
void update(int idx ,int val){
	idx++;
    while (idx <= MaxVal){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}
int read(int idx){
    int sum = 0;
    idx++;
    while (idx > 0){
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}
int dfs(int n,int p,int parent)
{
	ord[n]=pos;
	fin[p]=pos;	
	for(int i=0;i<graph[n].size();i++)
	{
		if(parent!=graph[n][i])
		{
			pos++;
			fin[p]=dfs(graph[n][i],pos,n);
		}
	}
	return fin[p];
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,a,b;

	scanf("%d",&n);
	vi er;
	graph.assign(n,er);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d", &a,&b);
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	dfs(0,0,0);
	map<int,vi> colors;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		colors[a].push_back(i);
	}
	scanf("%d",&a);
	pair<int,pair<int,int> > pa[a];
	for(int i=0;i<a;i++)
	{
		scanf("%d %d", &pa[i].second.first,&pa[i].first);
		pa[i].second.first--;
		pa[i].second.second=i;
	}
	sort(pa,pa+a);
	b=0;
	int res[a];
	MaxVal=n;
	for(int i=0;i<a;i++)
	{
		if(pa[i].first!=b)
		{
			for(int j=0;j<colors[b].size();j++)
				update(ord[colors[b][j]],-1);
			b=pa[i].first;
			for(int j=0;j<colors[b].size();j++)
				update(ord[colors[b][j]],1);
		}
		res[pa[i].second.second]= -read(ord[pa[i].second.first]-1)+read(fin[ord[pa[i].second.first]]);
	}
	for(int i=0;i<a;i++) printf("%d\n",res[i]);
	return 0;
}