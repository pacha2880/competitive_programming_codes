#include <bits/stdc++.h>
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

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int n;
	cin>>n;
	vector<pair<int, pair<int, int>>> que(n);
	vector<pair<pair<int, int>, int>> lineas;
	fore(i, 0, n)
	{
		cin>>que[i].f>>que[i].s.f;
		if(que[i].f == 1)
		{
			cin>>que[i].s.s;
			lineas.pb({que[i].s, i});
		}
		if(que[i].f ==  2)
			que[i].s.f--;
	}
	sort(all(lineas));
	int sq = 2500;
	vi deled(n), res(n, -1ll * MOD * MOD);
	vi dels(sq);
	vii hull(n);
	forg(i, 0, n, sq)
	{
		// cout<<"------ "<<i<<'\n';
		vii xs;
		int top = min(i + sq, n);
		int pod = 0;
		fore(j, i, top)
			if(que[j].f == 2)
				dels[pod++] = que[j].s.f;
		
		fore(j, i, top)
		{
			if(que[j].f == 2)
				deled[que[j].s.f] = 1;
			if(que[j].f == 3)
			{
				fore(k, 0, pod)
				{
					// cout<<'%'<<x<<'\n';
					if(!deled[dels[k]] && dels[k] < j)
					{
						// cout<<"#"<<x<<'\n';
						// cout<<que[j].s.f<<' '<<que[j].s.f * que[x].s.f + que[x].s.s<<'\n';
						res[j] = max(res[j], que[j].s.f * que[dels[k]].s.f + que[dels[k]].s.s);
					}
				}
				fore(k, i, j)
					if(!deled[k] && que[k].f == 1)
						res[j] = max(res[j], que[j].s.f * que[k].s.f + que[k].s.s);
				xs.pb({que[j].s.f, j});
			}
		}
		sort(all(xs));
		int sih = 0;
		for(auto cat : lineas)
		{
			// cout<<cat.s<<' '<<deled[cat.s]<<'\n';
			if(cat.s >= i || deled[cat.s]) continue;
			while(sih > 0)
			{
				if(hull[sih - 1].f == cat.f.f)
					sih--;
				if(sih < 2)
					break;
				auto a = hull[sih - 1];
				auto b = hull[sih - 2];
				if((ld)(b.s - a.s) / (a.f - b.f) >= (ld)(cat.f.s - a.s) / (a.f - cat.f.f))
					sih--;
				else
					break;
			}
			hull[sih++] = cat.f;
		}
		// cout<<"hull\n";
		// for(ii cat : hull)
		// 	cout<<cat.f<<' '<<cat.s<<'\n';
		int poh = 0;
		if(sih > 0)
			for(ii x : xs)
			{
				while(poh < sih - 1 && hull[poh].f * x.f + hull[poh].s <= hull[poh + 1].f * x.f + hull[poh + 1].s)
					poh++;
				res[x.s] = max(res[x.s], hull[poh].f * x.f + hull[poh].s);			
			}
	}
	fore(i, 0, n)
	{
		if(que[i].f == 3)
			if(res[i] == -1ll * MOD * MOD)
				cout<<"EMPTY SET\n";
			else
				cout<<res[i]<<'\n';
	}
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
