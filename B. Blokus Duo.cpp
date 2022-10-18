#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1);
int tab[14][14];
set<int> g[700];
bool vis[700];
vii oca[200], ocb[200];
int poa[200], pob[200];
int nu = 0;
void df1(int node)
{
    // cout<<node<<'\n';
    vis[node] = 1;
    if(node >= 400)
        pob[nu] = node - 400;
    else
        poa[nu] = node - 200;
    nu++;
    for(int x : g[node])
        if(!vis[x])
            df1(x);
}
bool valid(int x, int y, int ch)
{
    return x > -1 && x < 14 && y > -1 && y < 14 && tab[x][y] == ch;
}
int ta = 0, tb = 0;
int dir[2][4] = {{1, 0, -1, 0}, {0, -1, 0, 1}}, dir1[2][4] = {{1, 1, -1, -1}, {1, -1, -1, 1}};
void dfs1(int x, int y, int ch)
{
    // cout<<x<<' '<<y<<'\n';
    tab[x][y] = 0;
    fore(i, 0, 4)
    {
        int xx = x + dir[0][i], yy = y + dir[1][i];
        // cout<<xx<<' '<<yy<<' '<<tab[xx][yy]<<'\n';
        if(valid(xx, yy, ch))
            dfs1(xx, yy, ch);
    }
}
bool valid1(int x, int y, int ch)
{
    return x > -1 && x < 14 && y > -1 && y < 14 && tab[x][y] != ch;
}
void look1(int x, int y, int su)
{
    // cout<<'$'<<x<<' '<<y<<'\n';
    if(su == 400)
        ocb[tb].pb({x + 1, y + 1}), tab[x][y] = su + tb;
    else
        oca[ta].pb({x + 1, y + 1}), tab[x][y] = su + ta;
    fore(i, 0, 4)
    {
        int xx = x + dir1[0][i], yy = y + dir1[1][i];
        if(su == 400)
        {
            // cout<<x<<' '<<y<<' '<<su<<" - "<<xx<<' '<<yy<<" % "<<tab[x][y]<<' '<<tab[xx][yy]<<'\n';
            if(valid1(xx, yy, su + tb) && tab[xx][yy] >= 400)
                g[tab[xx][yy]].insert(400 + tb), g[400 + tb].insert(tab[xx][yy]);
        }
        else
        {
            if(valid1(xx, yy, su + ta) && tab[xx][yy] >= 200 && tab[xx][yy] < 400)
                g[tab[xx][yy]].insert(200 + ta), g[200 + ta].insert(tab[xx][yy]);
        }
        xx = x + dir[0][i], yy = y + dir[1][i];
        // cout<<xx<<' '<<yy<<' '<<(int)tab[xx][yy]<<'\n';
        if(valid(xx, yy, 0))
            look1(xx, yy, su);
    }
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	fore(i, 0, 14)
    fore(j, 0, 14)
    {
        char ch;
        cin>>ch;
        tab[i][j] = ch;
    }
    dfs1(4, 4, 'P');
    look1(4, 4, 200);
    // cout<<"-----------\n";
    ta++;
    dfs1(9, 9, 'O');
    look1(9, 9, 400);
    tb++;
    fore(i, 0, 14) fore(j, 0, 14)
    {
        if(tab[i][j] == 'P')
        {
            dfs1(i, j, 'P');
            look1(i, j, 200);
            ta++;
        }
        if(tab[i][j] == 'O')
        {
            dfs1(i, j, 'O');
            look1(i, j, 400);
            tb++;
        }
    }
    nu = 0;
    df1(200);
    nu = 0;
    df1(400);
    // cout<<poa[0]<<' '<<oca[0].size()<<'\n';
    cout<<ta + tb<<'\n';
    fore(i, 0, min(ta, tb))
    {
        // cout<<i<<' '<<poa[i]<<' '<<pob[i]<<'\n';
        cout<<"P "<<oca[poa[i]].size()<<' ';
        for(ii cat : oca[poa[i]])
            cout<<cat.f<<' '<<cat.s<<' ';
        cout<<'\n';
        cout<<"O "<<ocb[pob[i]].size()<<' ';
        for(ii cat : ocb[pob[i]])
            cout<<cat.f<<' '<<cat.s<<' ';
        cout<<'\n';
    }
    if(ta > tb)
    {
        fore(i, tb, ta)
        {
            cout<<"P "<<oca[poa[i]].size()<<' ';
            for(ii cat : oca[poa[i]])
                cout<<cat.f<<' '<<cat.s<<' ';
            cout<<'\n';
        }
    }
    else
    {
        fore(i, ta, tb)
        {
            cout<<"O "<<ocb[pob[i]].size()<<' ';
            for(ii cat : ocb[pob[i]])
                cout<<cat.f<<' '<<cat.s<<' ';
            cout<<'\n';
        }
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
