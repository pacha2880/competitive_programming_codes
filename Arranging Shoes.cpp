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
const int tam = 1000010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
int ar[tam];
ii t[4 * tam];
ii join(ii a, ii b)
{
    return {min(a.f, b.f), max(a.s, b.s)};
}

void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = {ar[b], ar[b]};
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
}
int query1(int b, int e, int node, int i, int j)
{
	if(i <= b && j >= e)
		return t[node].f;
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid >= j)
		return query1(b, mid, l, i, j);
	if(mid < i)
		return query1(mid + 1, e, r, i, j);
	return min(query1(b, mid, l, i, j), query1(mid + 1, e, r, i, j));
}
int query2(int b, int e, int node, int i, int j)
{
	if(i <= b && j >= e)
		return t[node].s;
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid >= j)
		return query2(b, mid, l, i, j);
	if(mid < i)
		return query2(mid + 1, e, r, i, j);
	return max(query2(b, mid, l, i, j), query2(mid + 1, e, r, i, j));
}
// int query()
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	int n;
    cin>>n;
    fore(i, 0, n) cin>>ar[i];
    init(0, n - 1, 0);
    int sol = 0;
    fore(i, 0, n)
    {
        // cout<<"#### "<<ar[i]<<'\n';
        int lo = i + 1, hi = n - 1, mid, res = n;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(query1(0, n - 1, 0, i, mid) < ar[i])
                res = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        sol += res - i - 1;
        // cout<<i<<' '<<sol<<'\n';
        lo = i + 1, hi = n - 1, res = n;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            // cout<<mid<<' '<<query2(0, n - 1, 0, i, mid)<<'\n';
            if(query2(0, n - 1, 0, i, mid) > ar[i])
                res = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        int der = res;
        // cout<<"der "<<der<<'\n';
        int izq;
        lo = 0, hi = i;
        while(lo <= hi)
        {
            mid = (lo + hi) / 2;
            if(query2(0, n - 1, 0, mid, i) == ar[i])
                izq = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        // cout<<"izq "<<izq<<'\n';
        if(res < n)
        {
            int mami = query1(0, n - 1, 0, i, der);
            // cout<<mami<<'\n';
            if(mami < ar[i])
            {
                lo = izq, hi = i;
                int lef;
                while(lo <= hi)
                {
                    mid = (lo + hi) / 2;
                    if(query1(0, n - 1, 0, mid, i) > mami)
                        lef = mid, hi = mid - 1;
                    else
                        lo = mid + 1;
                }
                // cout<<"lef "<<lef<<'\n';
                int rig;
                lo = der, hi = n - 1;
                while(lo <= hi)
                {
                    mid = (lo + hi) / 2;
                    if(query1(0, n - 1, 0, der, mid) > mami)
                        rig = mid, lo = mid + 1;
                    else
                        hi = mid - 1;
                }
                // cout<<"rig "<<rig<<'\n';
                sol += (rig - der + 1) * (i - lef + 1);
            }
        }
        // cout<<i<<' '<<sol<<'\n';
    }
    cout<<sol<<'\n';
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
