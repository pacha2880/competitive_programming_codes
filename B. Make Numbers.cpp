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
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int ar[4];
set<int> st;
vector<vi> op[5];
int cal(int pos, vi &v, vi &op)
{
	if(pos == op.size())
		return v[pos];
	if(op[pos] == 0)
		return v[pos] + cal(pos + 1, v, op);
	if(op[pos] == 1)
		return v[pos] - cal(pos + 1, v, op);
	v[pos + 1] *= v[pos];
	return cal(pos + 1, v, op);
}
void go(vi &v, int mask)
{
	if(mask == 0)
	{
		int n = v.size(), xa;
		if(n > 1)
		{
			// for(int x : v)
			// 	cout<<x<<' ';
			// cout<<'\n';
			vi ax = v;
			fore(i, 0, op[n].size())
			{
				xa = cal(0, v, op[n][i]);
				// cout<<xa<<'\n';
				st.insert(xa);
				v = ax;
			}
		}
	}
	else
	{
		fore(i, 1, 15)
		{
			if((i & mask) == i)
			{
				vector<int> va;
				fore(j, 0, 4)
				{
					if(i & (1<<j))
						va.pb(ar[j]);
				}
				sort(all(va));
				do
				{
					int nu = 0;
					for(int x : va)
					{
						nu *= 10;
						nu += x;
					}
					v.pb(nu);
					go(v, mask ^ i);
					v.pop_back();
				}
				while(next_permutation(all(va)));	
			}
		}
	}
}
void ops(int i, vi vu)
{
	op[i + 1].pb(vu);
	if(i == 3) return;
	fore(j, 0, 3)
	{
		vu.pb(j);
		ops(i + 1, vu);
		vu.pop_back();
	}
}
int main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	fore(i, 0, 4) cin>>ar[i];
	vi v, vu;
	ops(0, vu);
	// fore(i, 2, 5)
	// {
	// 	cout<<op[i].size()<<'\n';
	// }
	go(v, 15);
	for(auto it = st.begin(); it != st.end();)
	{
		if(*it < 0)
			it = st.erase(it);
		else
			it++;
	}
	cout<<st.size()<<'\n';
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil