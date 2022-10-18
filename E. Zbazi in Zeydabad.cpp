#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(ll)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(ll i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(ll i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(ll i = b, asdz = e, frz; i < asdz; i+=frz)
#define index	ll mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](ll a, ll b){ return a > b; });


using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const ll tam = 100010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int t[24020];
void update(int node, int b, int e, int pos, int val)
{
	if(b == e)
	{
		t[node] += val;
		return;
	}
	index;
	if(mid >= pos)
		update(l, b, mid, pos, val);
	else
		update(r, mid + 1, e, pos, val);
	t[node] = t[l] + t[r];
}
int query(int node, int b, int e, int i, int j)
{
	if(b >= i && e <= j)
		return t[node];
	index;
	if(mid >= j)
		return query(l, b, mid, i, j);
	if(mid < i)
		return query(r, mid + 1, e, i, j);
	return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
}
string z[6030];
int con[4][3030][3030];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m;
	cin>>n>>m;
	fore(i, 0, n)
		cin>>z[i];
	int cuan = 0;
	fore(i, 0, n)
	{
		cuan = 0;
		fore(j, 0, m)
		{
			if(z[i][j] == 'z')
				cuan++;
			else
				cuan = 0;
			con[0][i][j] = cuan;
		}
	}
	fore(i, 0, n)
	{
		cuan = 0;
		for(int j = m - 1; j > -1; j--)
		{
			if(z[i][j] == 'z')
				cuan++;
			else
				cuan = 0;
			con[1][i][j] = cuan;
		}
	}
	for(int i = n - 1 + m - 1; i > -1; i--)
	{
		cuan = 0;
		for(int j = 0; j < m && i - j > -1; j++)
		{
			if(i - j >= n) continue;
			if(z[i - j][j] == 'z')
				cuan++;
			else
				cuan = 0;
			con[0][i - j][j] = min(con[0][i - j][j], cuan);
		}
	}
	fore(i, -m + 1, n)
	{
		cuan = 0;
		// cout<<i<<'\n';
		for(int j = 0; j < m && i + j < n; j++)
		{
			if(i + j < 0) continue;
			if(z[i + j][m - 1 - j] == 'z')
				cuan++;
			else
				cuan = 0;
			con[1][i + j][m - 1 - j] = min(con[1][i + j][m - 1 - j], cuan);
		}
	}
	ll res = 0;

	fore(i, -m + 1, n)
	{
		mem(t, 0);
		set<pair<int, int>> st;
		for(int j = 0; j < m && i + j < n; j++)
		{
			if(i + j < 0) continue;
			while(st.size() > 0 && st.begin()->f < j)
			{
				update(0, 0, 6000, st.begin()->s, -1);
				st.erase(st.begin());
			}
			if(z[i + j][m - 1 - j] == 'z')
			{
				update(0, 0, 6000, j, 1);
				st.insert({j + con[0][i + j][m - 1 - j] - 1, j});
				// cout<<j<<' '<<con[1][i + j][m - 1 - j]<<' '<<j - con[1][i + j][m - 1 - j] + 1<<'\n';
				res += query(0, 0, 6000, j - con[1][i + j][m - 1 - j] + 1, j);
			}
		}
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	