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
const int tam = 100'010;
const int MOD = 1'000'000'007;
const int MOD1 = 998'244'353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int t;
	cin>>t;
	fore(i, 1, t + 1)
	{
		int e, w;
		cin>>e>>w;
		vi au(w), last(w);
		int res = 0;
		stack<vector<int>> st;
		fore(i, 0, e)
		{
			cout<<i<<'\n';
			vi neu(w), bot(w), ax(w);
			fore(i, 0, w)
			{
				cin>>neu[i];
				ax[i] = neu[i];
				if(neu[i] < last[i])
					neu[i] = last[i] - neu[i];
				else
				{
					bot[i] = neu[i] - last[i];
					res += bot[i];
					neu[i] = 0;
				}
			}
			swap(last, ax);
			bool bo = true;
			do
			{
				bo = false;
				int su = 0;
				fore(i, 0, w)
				{
					if(neu[i] > au[i])
					{
						res += au[i];
						au[i] = 0;
						neu[i] -= au[i];
						bo = true;
					}
					else
					{
						res += neu[i];
						au[i] -= neu[i];
						su += au[i];
						neu[i] = 0;
					}
				}
				if(bo)
				{
					res += 2 * su;
					fore(i, 0, w)
						bot[i] += au[i];
					au = st.top();
					st.pop();
				}
			}
			while(bo);
			int sua = 0, sub = 0;
			fore(i, 0, w)
			{
				cout<<au[i]<<' '<<bot[i]<<'\n';
				sua += au[i], sub += bot[i];
			}
			if(sub > 0)
			{
				if(sua > 0)
					st.push(au);
				swap(au, bot);
			}
			cout<<"### "<<res<<'\n';
		}

		fore(i, 0, w)
			res += last[i];
		cout<<"Case "<<i<<": "<<res<<'\n';
	}
	return 0;
}
// f
// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
