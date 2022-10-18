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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
char ma[1010][1010];
pair<pair<int, int>, pair<int, int>> dir[1010][1010];
pair<char, int> dirs[100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m;
	string s;
	int cono;
	cin>>n>>m;
	fore(i, 0, n) 
	{
		cin>>s;
		cono = 0;
		fore(j, 0, m)
		{
			ma[i][j] = s[j];	
			dir[i][j] = mp(mp(0, 0), mp(0,0));
			if(s[j] != '#')
			{
				dir[i][j].f.f = cono;
				cono++;
			}
			else
				cono = 0;
		}
		cono = 0;
		for(int j = m-1;j > -1; j--)
		{
			if(s[j] != '#')
			{
				dir[i][j].f.s = cono;
				cono++;
			}
			else
				cono = 0;
		}
	}
	vector<pair<int, int>> v;
	fore(i, 0, m) 
	{
		cono = 0;
		fore(j, 0, n)
		{
			if(ma[j][i] != '#')
			{
				dir[j][i].s.f = cono;
				cono++;
				if(ma[j][i] != '.')
					v.pb(mp(j, i));
			}
			else
				cono = 0;
		}
		cono = 0;
		for(int j = n-1;j > -1; j--)
		{
			if(ma[j][i] != '#')
			{
				dir[j][i].s.s = cono;
				cono++;
			}
			else
				cono = 0;
		}
	}
	int k;
	cin>>k;
	fore(i, 0, k)
	cin>>dirs[i].f>>dirs[i].s;
	int x, y;
	string res = "";
	bool bo = 0;
	fore(i, 0, v.size())
	{
		x = v[i].f, y = v[i].s;
		//cout<<x<<' '<<y<<"qweqwe\n";
		bo = true;
		fore(i, 0, k)
		{
			//cout<<x<<' '<<y<<" -> ";
			//cout<<dir[x][y].f.f<<' '<<dir[x][y].f.s<<' '<<dir[x][y].s.f<<' '<<dir[x][y].s.s<<'\n';
			if(dirs[i].f == 'W')
			{
				if(dir[x][y].f.f >= dirs[i].s)
					y -= dirs[i].s;
				else
				{
					bo = false;
					break;
				}
			}
			if(dirs[i].f == 'E')
			{
				if(dir[x][y].f.s >= dirs[i].s)
					y += dirs[i].s;
				else
				{
					bo = false;
					break;
				}
			}
			if(dirs[i].f == 'N')
			{
				if(dir[x][y].s.f >= dirs[i].s)
					x -= dirs[i].s;
				else
				{
					bo = false;
					break;
				}
			}
			if(dirs[i].f == 'S')
			{
				if(dir[x][y].s.s >= dirs[i].s)
					x += dirs[i].s;
				else
				{
					bo = false;
					break;
				}
			}
		}
		if(bo)
			res += ma[v[i].f][v[i].s];
	}
	sort(all(res));
	if(res.size())
		cout<<res<<'\n';
	else
		cout<<"no solution\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2