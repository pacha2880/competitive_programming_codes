#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
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
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
int grid[200][200];
int ocu[200][200];
bool acti[200][200];
int per[200][200];
pair<int,int> parent[200][200];
int ava[2][2][6] = {{{0, 1, 1, 0, -1, -1},{1,1,0,-1,0,1}},
			{{0, 1, 1, 0, -1, -1},{1,0,-1,-1,-1,0}}};
pair<int,int> find(pair<int,int> n)
{
	if(parent[n.f][n.s] == mp(-1, -1)) return n;
	return parent[n.f][n.s] = find(parent[n.f][n.s]);
}
void jo(pair<int,int> a, pair<int,int> b)
{
	pair<int,int> axa, axb, axc;
	if(acti[b.f][b.s])
	{
		axa = find(a), axb = find(b);
		if(axa != axb)
		{
			int con = 0;
			fore(i, 0, 6)
			{
				axc = mp(a.f + ava[0][0][i], a.s + ava[a.f&1][1][i]);
				if( acti[axc.f][axc.s] && find(axc) == axb)
				{
					con++;
					ocu[axc.f][axc.s]++;
				}
			}
			parent[axa.f][axa.s] = axb;
			per[axb.f][axb.s] += per[axa.f][axa.s] - 2 * con;
			ocu[a.f][a.s] += con;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	fore(i, 0, 200)
	fore(j, 0, 200)
	parent[i][j] = mp(-1, -1), per[i][j] = 6;
	int n, m, ax;
	cin>>n>>m;
	pair<int,int> a;
	fore(i, 1, n+1)
	{
		fore(j, 1, m + (i&1))
		{
			cin>>ax;
			if(ax)
			{
				acti[i][j] = 1;
				a = mp(i, j);
				//cout<<i<<' '<<j<<'\n';
				fore(i, 0, 6)
				{
					jo(a, mp(a.f + ava[0][0][i], a.s + ava[a.f&1][1][i]));
					//cout<<a.f + ava[0][0][i]<<','<<a.s + ava[a.f&1][1][i]<<' ';
				}
				//cout<<'\n';
				
			}
		}
	}
	/*fore(i, 1, n+1)
	{
		fore(j, 1, m+1)
		{
			if(acti[i][j])
			{
				a = find(mp(i, j));
				cout<<per[a.f][a.s]<<' ';
			}
			else
				cout<<0<<' ';
		}
		cout<<'\n';
	}
	fore(i, 1, n+1)
	{
		fore(j, 1, m+1)
		{
			if(acti[i][j])
			{
				a = find(mp(i, j));
				cout<<ocu[a.f][a.s]<<' ';
			}
			else
				cout<<0<<' ';
		}
		cout<<'\n';
	}
	cout<<'\n';*/
	int q;
	cin>>q;
	char ch;
	int x, y;
	while(q--)
	{
		cin>>ch>>x>>y;
		if(ch == 'a')
		{
			acti[x][y] = 1;
			a = mp(x, y);
			fore(i, 0, 6)
			jo(a, mp(a.f + ava[0][0][i], a.s + ava[a.f&1][1][i]));
			/*fore(i, 1, n+1)
			{
				fore(j, 1, m+1)
				{
					if(acti[i][j])
					{
						a = find(mp(i, j));
						cout<<per[a.f][a.s]<<' ';
					}
					else
						cout<<0<<' ';
				}
				cout<<'\n';
			}
			fore(i, 1, n+1)
			{
				fore(j, 1, m+1)
				{
					if(acti[i][j])
					{
						a = find(mp(i, j));
						cout<<ocu[a.f][a.s]<<' ';
					}
					else
						cout<<0<<' ';
				}
				cout<<'\n';
			}
			cout<<'\n';*/

		}
		else
		{
			a = find(mp(x, y));
			if(acti[x][y])
			cout<<per[a.f][a.s]<<'\n';
			else
				cout<<0<<'\n';
		}
	}
	return 0;
}
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2