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
map<int,map<int,int> > g;
vector<bool> visited;
vi parent;
bool bfs(){
	queue<int> que;
	que.push(0);
	int node;
	map<int,int>::iterator it;
	while(!que.empty()){
		node=que.front();
		que.pop();
		for(it=g[node].begin();it!=g[node].end();it++){
			if(!visited[it->first]&&it->second>0){
				visited[it->first]=1;
				parent[it->first]=node;
				que.push(it->first);
			}
		}
	}
	return visited[1];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int a,b,c,d;
	cin>>a>>b;
	for(int i=2;i<a+2;i++){
		cin>>c;
		g[i][1]=1;
		for(int j=0;j<c;j++){
			cin>>d;
			g[0][d+a]=1;
			g[d+a][i]=1;
		}
	}
	int flow=0,fl,nod;
		parent.assign(b+a+2,-1);
		visited.assign(b+a+2,0);
	while(bfs()){
		nod=1;
		while(parent[nod]!=0){
			g[nod][parent[nod]]++;
			g[parent[nod]][nod]--;
			nod=parent[nod];
		}
		flow++;
		parent.assign(b+a+2,-1);
		visited.assign(b+a+2,0);
	}
	if(flow==a) cout<<"Downtown";
	else
		cout<<"MermeladaDeNaranja";
	return 0;
}