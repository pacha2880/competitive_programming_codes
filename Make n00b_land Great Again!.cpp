#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
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
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
 
 
using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;
 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
 
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
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi pos(tam), endo(tam);
int curpo = 1;
vi g[tam];
vi negan(tam);
vi dep(tam);
void dfs(int node)
{
    // cout<<node<<'\n';
    pos[node] = curpo++;
    for(int x : g[node])
        dep[x] = dep[node] + 1, dfs(x);
    negan[curpo] = 1;
    endo[node] = curpo++;
}
int bit[2][tam];
int query(int cual, int pos)
{
    int res = 0;
    while(pos > 0)
        res += bit[cual][pos], pos -= pos & -pos;
    return res;
}
void update(int cual, int pos, int val)
{
    while(pos < tam)
        bit[cual][pos] += val, pos += pos & -pos;
}
int n, m;
vector<vi> tiene(tam);
vi meta(tam);
vector<pair<int, ii>> ques(tam);
vi res(tam, -1);
 
int trepos = -1;
void dnc(int l, int r, vi &candi)
{
    if(l > r) return;
    int mid = (l + r) / 2;
    while(trepos < mid)
    {
        trepos++;
        int a = ques[trepos].f, b = ques[trepos].s.f, c = ques[trepos].s.s;
        update(0, pos[a], b - dep[a] * c);
        update(0, endo[a], -b + dep[a] * c);
        update(1, pos[a], c);
        update(1, endo[a], -c);
    }
    while(trepos > mid)
    {
        int a = ques[trepos].f, b = ques[trepos].s.f, c = ques[trepos].s.s;
        update(0, pos[a], -b + dep[a] * c);
        update(0, endo[a], +b - dep[a] * c);
        update(1, pos[a], -c);
        update(1, endo[a], +c);
        trepos--;
    }
    vi les, ris;
    for(int x : candi)
    {
        int su = 0;
        for(int y : tiene[x])
        {
            su += query(0, pos[y]) + query(1, pos[y]) * dep[y];
            if(su >= meta[x]) break;
        }
        if(su >= meta[x])
            res[x] = mid + 1, les.pb(x);
        else
            ris.pb(x);
    }
    candi.clear();
    dnc(l, mid - 1, les);
    dnc(mid + 1, r, ris);
}
 
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int m;
	cin>>n>>m;
    fore(i, 1, n)
    {
        int x;
        cin>>x;
        x--;
        g[x].pb(i);
    }
    // fore(i, 0, n)
    // {
    //     cout<<'#'<<i<<'\n';
    //     for(int x : G[i])
    //         cout<<x<<' ';
    //     cout<<'\n';
    // }
    dfs(0);
    // cout<<curpo<<'\n';
    // fore(i, 0, curpo)
    //     cout<<i<<' '<<negan[i]<<'\n';
    // fore(i, 0, n)
    //     cout<<i<<' '<<pos[i]<<' '<<endo[i]<<'\n';
    
    // init(0, curpo - 1, 0);
    // cout<<t[0].val<<' '<<t[0].neg<<' '<<t[0].pos<<'\n';
    // cout<<"--------------\n";
    // update(0, curpo - 1, 0, pos[2] + 1, endo[2] - 1, 5);
    // fore(i, 0, curpo)
    //     cout<<i<<' '<<segQuery(0, curpo - 1, 0, i, i)<<'\n';
    // cout<<"\ncddcd\n";
    // update(0, curpo - 1, 0, pos[0] + 1, endo[0] - 1, 1);
    // fore(i, 0, curpo)
    //     cout<<i<<' '<<segQuery(0, curpo - 1, 0, i, i)<<'\n';
    // cout<<"\ncddcd\n";
    // update(0, curpo - 1, 0, pos[2], pos[2], 7);
    // fore(i, 0, curpo)
    //     cout<<i<<' '<<segQuery(0, curpo - 1, 0, i, i)<<'\n';
    // cout<<"\ncddcd\n";
    // update(0, curpo - 1, 0, endo[2], endo[2], 7);
    // fore(i, 0, curpo)
    //     cout<<i<<' '<<segQuery(0, curpo - 1, 0, i, i)<<'\n';
    // cout<<"\ncddcd\n";
    // cout<<segQuery(0, curpo - 1, 0, 0, pos[2])<<'\n';
    // cout<<segQuery(0, curpo - 1, 0, 0, pos[4])<<'\n';
    // cout<<segQuery(0, curpo - 1, 0, 0, pos[5])<<'\n';
    // cout<<segQuery(0, curpo - 1, 0, 0, pos[3])<<'\n';
    // cout<<segQuery(0, curpo - 1, 0, 0, pos[1])<<'\n';
 
    // return 0;
    fore(i, 0, n)
    {
        int x;
        cin>>x;
        tiene[x - 1].pb(i);
    }
    fore(i, 0, m) cin>>meta[i];
    int q;
    cin>>q;
    fore(i, 0, q)
    {
        int a, b, c;
        cin>>a>>b>>c;
        ques[i] = {a - 1, {b, c}};
    }
    vi asd(m);
    fore(i, 0, m) asd[i] = i;
    dnc(0, q - 1, asd);
    fore(i, 0, m)
        if(res[i] == -1)
            cout<<"rekt\n";
        else
            cout<<res[i]<<'\n';
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// efe no más.
// Si no vá por todo, andá pa' allá bobo.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Take a sad song and make it better