#include <bits/stdc++.h>
#define f first
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
int n;
ll pe[200005],co[200005];
bool visited[200005];
vi g[200005];
vector<pair<ll,ll>> gp[200005];
pair<ll,ll> dfs(int node)
{
    pair<ll,ll> res(0,0);
    pair<ll,ll> r;
    visited[node]=1;
    for(int i=0;i<g[node].size();i++)
    {
        if(!visited[g[node][i]])
        {
            r= dfs(g[node][i]);
            res.first+= pe[g[node][i]] + r.first + r.second;
            res.second += pe[g[node][i]]+ r.second; 
            gp[node][i] = mp(pe[g[node][i]] + r.first + r.second,pe[g[node][i]]+ r.second);
        }
    }
    return res;
}
ll dfs1(int node, ll pare,ll parb)
{
    //cout<<"nodo "<<node<<endl;
    ll ar = pe[node]+parb, res = pare, res1, par= 0;
    visited[node]=1;
    for(int i=0;i<g[node].size();i++)
    {
    	if(!visited[g[node][i]])
    	{
    		res += gp[node][i].f;
            //cout<<gp[node][i].f<<'#'<<g[node][i]<<' ';
        	ar += gp[node][i].s;
    	}
     }
     //cout<<res<<endl;
    res1=res +ar;
    //cout<<res1<<' '<<ar<<' '<<"asd"<<endl;
    for(int i=0;i<g[node].size(); i++)
    {
        if(!visited[g[node][i]])
        {
            res = max(res,dfs1(g[node][i],res1-gp[node][i].f-gp[node][i].s,ar-gp[node][i].s));
        }
    }
    return res;
}
int main()
{
	int a,b;
    cin>>n;
    pair<ll,ll> par(0,0);
    for(int i=0;i<n;i++)
        cin>>pe[i];
    for(int i=0; i< n-1;i++)
    {
        cin>>a>>b;
        g[a-1].pb(b-1);
        g[b-1].pb(a-1);
        gp[a-1].pb(par);
        gp[b-1].pb(par);
    }
    memset(visited,0,sizeof(visited));
    //cout<<123<<endl;
    par = dfs(0);
    //cout<<par.f<<' '<<par.s<<endl;
    memset(visited,0,sizeof(visited));
    cout<<dfs1(0,0,0); 
    return 0;
}
