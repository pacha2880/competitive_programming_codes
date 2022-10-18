#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define MOD1		998244353
#define EPS			1e-9
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int mat[1010][1010];
int main()
{
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("control.in", "r", stdin);
	//freopen("control.out", "w", stdout);
	int n, m;
	cin>>n>>m;
	fore(i, 0, n)
		fore(j, 0, m)
			cin>>mat[i][j];
	map<int,vector<int>> ma;
	map<int,int> mac;
	fore(i, 0, m)
	{
		bool con = false;
		fore(j, 1, n)
		{
			if(mat[j][i] != mat[0][i])
			{
				con = true;
				break;
			}
		}
		if(con)
		{
			ma[mat[0][i]].pb(i);
		}
	}
	int k = 0;
	vector<int> ron[ma.size()];
	map<int,int> tran;
	bool bo = false;
	int qwer = 0;
	for(map<int,vector<int>>::iterator it = ma.begin(); it != ma.end(); it++, qwer++)
	{
		ron[qwer] = it->s;
	}
	k = min((int)ma.size(), 7);
	bool rbo = false;
	if(k == 0) rbo = true;
	int colo[10];
	int poso[(int)ma.size()];
	for(int i = 0; i < ma.size(); i++)
		poso[i] = i;
	double t = clock();
	int locas[10];
	bool aw;
	while( (clock() - t) / CLOCKS_PER_SEC < 4.9)
	{
		shuffle(poso, poso + ma.size(), rng);
		for(int i = 0; i < k; i++)
		{
			locas[i] = ron[poso[i]][rng()%(ron[poso[i]].size())];
		}	
		bool nok = true;
		for(int j = 1; j < n; j++)
		{
			aw = true;
			for(int i = 0; i < k; i++)
			{
				if(mat[0][locas[i]] != mat[j][locas[i]])
				{
					aw = false;
					break;
				}
			}
			if(aw == true)
			{
				nok = false;
				break;
			}

		}
		for(int i = 0; i < k; i++)
			colo[i] = locas[i];
		if(!nok) continue;

		if(!rbo)
		{

			do
			{
				bo = true;
				bool eq;
				fore(i, 1, n)
				{
					eq = true;
					fore(j, 0, k)
					{
						if(mat[i][colo[j]] != mat[0][colo[j]])
						{
							eq = false;
							break;
						}
					}
					if(eq)
					{
						bo = false;
						break;
					}
				}
				if(bo) break;
			}
			while(next_permutation(colo, colo + k));
		}
		cout<<"Yes\n";
		vector<pair<int,int>> prin;
		set<int> st;
		for(int i = 0; i < k; i++)
		{
			prin.pb(mp(mat[0][colo[i]], i+1));
			st.insert(mat[0][colo[i]]);
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
			{
				if(st.find(mat[i][j]) == st.end())
				{
					prin.pb(mp(mat[i][j], 0));
					st.insert(mat[i][j]);
				}
			}
		sort(prin.begin(), prin.end());
		fore(i, 0, prin.size())
		{
			cout<<prin[i].f<<" -> "<<prin[i].s<<'\n';
		}
		return 0;
	}
		
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2