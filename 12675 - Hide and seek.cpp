#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 10010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
	point operator -(point p) {return point(x - p.x, y - p.y);}
	point operator +(point p) {return point(x + p.x, y + p.y);}
	ll operator ^(point p) {return x * p.y - y * p.x;}
  	ll operator *(point p) {return x * p.x + y * p.y;}
  	point operator *(ll a) {return point(x * a, y * a);}
	bool operator <(point p) {return x == p.x ? y < p.y : x < p.x;}
	bool left(point a, point b) {return ((b - a) ^ (*this - a)) > 0;}
	ostream& operator<<(ostream& os) {
		return os << "("<< x << "," << y << ")";
	}

};
int lug[3][tam];
point ar[3][tam];
pair<int, int> sweep[4 * tam];
bool cmp(pair<int, int> a, pair<int, int> b)
{
	if(lug[a.f][a.s] == lug[b.f][b.s])
		return (ar[a.f][a.s] ^ ar[b.f][b.s]) > 0;
	return lug[a.f][a.s] < lug[b.f][b.s];
}
struct stru
{
	bool operator()(int a, int b)
	{
		if((ar[1][a] ^ ar[1][b]) > 0)
			return ar[1][b].left(ar[2][a], ar[1][a]);
		return ar[1][a].left(ar[1][b], ar[2][b]);
	}
};
int pren[10010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int s, n, m;
	while(cin>>s)
	{
		cin>>n>>m;
		fore(i, 0, n) cin>>ar[0][i].x>>ar[0][i].y;
		fore(i, 0, m) fore(j, 1, 3) cin>>ar[j][i].x>>ar[j][i].y;
		fore(i, 0, s)
		{
			int x = ar[0][i].x, y = ar[0][i].y;
			int ind = 0;
			fore(j, 0, n) 
			{
				ar[0][j].x -= x, ar[0][j].y -= y;
				if(j != i)
				{
					lug[0][j] = ar[0][j].y > 0 || ar[0][j].y == 0 && ar[0][j].x > 0;
					sweep[ind++] = {0, j};
				}
			}
			fore(j, 0, m) 
			{
				fore(k, 1, 3) ar[k][j].x -= x, ar[k][j].y -= y;
				if((ar[1][j] ^ ar[2][j]) < 0)
					swap(ar[1][j], ar[2][j]);
				fore(k, 1, 3)
				{
					lug[k][j] = ar[k][j].y > 0 || ar[k][j].y == 0 && ar[k][j].x > 0;
					sweep[ind++] = {k, j};
				}
			}
			sort(sweep, sweep + ind, cmp);
			set<int, stru> st;
			fore(j, 0, n)
			{
				pren[j] = j != i;
			}
			int ax, bx;
			fore(asd, 0, 2 * ind)
			{
				int i = asd % ind;
				if(sweep[i].f == 0)
				{
					if(st.size())
					{
						ax = *st.begin();
						pren[sweep[i].s] &= ar[0][sweep[i].s].left(ar[1][ax], ar[2][ax]);
					}
				}
				if(sweep[i].f == 1)
				{
					st.insert(sweep[i].s);
				}
				if(sweep[i].f == 2)
				{
					st.erase(sweep[i].s);
				}
			}
			int res = 0;
			fore(i, 0, n)
				res += pren[i];	
			cout<<res<<'\n';
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	