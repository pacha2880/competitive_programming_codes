#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int ll
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

// #pragma GCC optimization ("O2")
// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
const int tam = 1000001;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int l[22 * tam], r[22 * tam];
int indu = 0;
// vector<st> tres;
int exi = 0;
int update(int t, int b, int e, int val)
{
    // cout<<t<<' '<<b<<' '<<e<<'\n';
	if(b == e)
    {
        if(t == -1) exi = 1;
        l[indu] = -1, r[indu] = -1;
		return indu++;
    }
    if(t == -1)
        t = indu, l[indu] = -1, r[indu] = -1, indu++;
	int mid = (b + e) / 2;
    int re;
    int va = indu++;
	if(mid >= val)
    {
        l[va] = update(l[t], b, mid, val);
        r[va] = r[t];
    }
    else
    {
        r[va] = update(r[t], mid + 1, e, val);
        l[va] = l[t];
    }
    return va++;
}
struct Node{ int de, val, res; Node *par, *go; };
typedef Node* pNode;
pNode find(pNode nod, int de)
{
	while(nod->de > de)
		if(nod->go->de < de)
			nod = nod->par;
		else
			nod = nod->go;
	return nod;
}
pNode add(pNode nod, int ind, int res)
{
	pNode nuevo = new Node();
	nuevo->par = nod;
    nuevo->val = ind;
    nuevo->res = res;
	nuevo->de = nod->de + 1;
	if(nod->de - nod->go->de == nod->go->de - nod->go->go->de)
		nuevo->go = nod->go->go;
	else
		nuevo->go = nod;
	return nuevo;
}
signed main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int q;
    cin>>q;
    vector<pNode> heads;
    l[0] = r[0] = -1;
    indu = 1;
    Node rot = {0, 0, 0, 0, 0};
    rot.par = rot.go = &rot;
    pNode head = &rot;
    heads.pb(head);
    while(q--)
    {
        char ch;
        cin>>ch;
        // cout<<q<<' '<<resus.back()<<'\n';
        if(ch == '?')
        {
            cout<<heads.back()->res<<'\n';
            cout.flush();
        }
        else if(ch == '+')
        {
            int x;
            cin>>x;
            exi = 0;
            int neo = update(heads.back()->val, 0, tam - 1, x);
            heads.pb(add(heads.back(), neo, heads.back()->res + exi));
        }
        else if(ch == '-')
        {
            int x;
            cin>>x;
            auto head = find(heads.back(), heads.back()->de - x);
            heads.pb(head);
        }
        else
        {
            heads.pop_back();
        }
    }
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
