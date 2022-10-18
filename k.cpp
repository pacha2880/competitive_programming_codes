#include <iostream>
#include <vector>
//#include <limits>
#include <stdlib.h>
#include <algorithm>
#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <bits/extc++.h>
typedef long long       ll;
//#define int               long long
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define mt                make_tuple
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define f first
#define s second
#define fore(i,b,e)      for(int i=(int)b,o_o=e;i<(int)o_o;++i)
#define forr(i,b,e)      for(int i=(int)b,o_o=e;i<(int)o_o;++i)
#define deb(x)           cerr << "# " << (#x) << " = " << (x) << endl;
#define sz(x)            (int)x.size()
#define endl             '\n'
//int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//const int INF = numeric_limits<int>::max() / 4;
const int tam = 100010;
vector<pair<int, ll> > g[9 * tam];
ll dis[9 * tam];
bool vis[9 * tam];
int n;
void init(int b, int e, int node, int par)
{
  if(b == e)
  {
      g[par + tam].pb({e, 0});
      g[e].pb({par + 5 * tam, 0});
      return;
  }
    g[node + 5 * tam].pb({par + 5 * tam, 0});
    g[par + tam].pb({node + tam, 0});
  int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
  init(b, mid, l, node);
  init(mid + 1, e, r, node);
}
void connect(int b, int e, int node, int i, int j, int pos, int val, int dest)
{
  if(b >= i && e <= j)
  {
      if(b == e)
      {
          if(dest)
            g[e].pb({pos, val});
        else
            g[pos].pb({e, val});
       return;   
      }
    if(dest)
      g[tam*5 + node].pb(mp(pos, val));
    else
      g[pos].pb(mp(tam + node, val));
    return;
  }
  int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
  if(mid >= j)
    connect(b, mid, l, i, j, pos, val, dest);
  else if(mid < i)
    connect(mid + 1, e, r, i, j, pos, val, dest);
  else
  {
    connect(mid + 1, e, r, i, j, pos, val, dest);
    connect(b, mid, l, i, j, pos, val, dest);
  }
}
signed main()
{
//   std::ios::sync_with_stdio(false); cin.tie(0);
  //freopen("","r",stdin);
  //freopen("","w",stdout);
  int n, p, s;
  cin>>n>>p>>s;
  s--;
  init(0, n - 1, 0, 4 * tam - 1);
  while(p--)
  {
    string s;
    cin>>s;
    if(s == "basic")
    {
      int a, b, c;
      cin>>a>>b>>c;
      g[a - 1].pb(mp(b - 1, c));
    }
    else if(s == "fixed-origin")
    {
      int a, b, c, d;
      cin>>a>>b>>c>>d;
      connect(0, n - 1, 0, b - 1, c - 1, a - 1, d, 0);
    }
    else
    {
      int a, b, c, d;
      cin>>a>>b>>c>>d;
      connect(0, n - 1, 0, b - 1, c - 1, a - 1, d, 1);
    }

  }
  ll gran = 1ll * 1e9 * 1e9;
  fore(i, 0, 9 * tam) dis[i] = gran;
  dis[s] = 0;
  priority_queue<pair<ll, int> > que;
  que.push(mp(0, s));
  while(!que.empty())
  {
    int node = que.top().s;
    que.pop();
    if(vis[node]) continue;
    vis[node] = 1;
    for(pair<ll, int> cat : g[node])
    {
      ll val = dis[node] + cat.s;
      if(dis[cat.f] > val)
      {
        dis[cat.f] = val;
        que.push(mp(-val, cat.f));
      }
    }
  }
  fore(i, 0, n)
  {
    if(i > 0) cout<<' ';
    if(dis[i] == gran)
      cout<<-1;
    else
      cout<<dis[i];
  }
  cout<<'\n';
  return 0;
}
// Dinosaurs