	#include <bits/stdc++.h>
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	//#define PI 				acos(-1)
	#define mp				make_pair
	#define pb				push_back
	#define all(a)			(a).begin(), (a).end()
	#define sz(a)			a.size()
	#define srt(a)			sort(all(a))
	#define mem(a, h)		memset(a, (h), sizeof(a))
	#define f 				first
	#define s 				second
	#define MOD1			998244353
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
	//find_by_order kth largest  order_of_key <
	const int tam = 100010;
	const int MOD = 1e9+7;
	const double EPS = 1e-8;
	const double PI = acos(-1);
	int dp[110][110][110];
	pair<int,pair<int,int>> par[110][110][110];
	vector<int> kmp(string s)
	{
		int n = s.size();
		vector<int> pi(n);
		fore(i, 1, n)
		{
			int j = pi[i-1];
			while(j > 0 && s[j] != s[i])
				j = pi[j-1];
			if(s[j] == s[i])
				j++;
			pi[i] = j;
		}
		return pi;
	}
	int main()
	{
		ios::sync_with_stdio(0); cin.tie(0);
		//freopen("qwe.txt", "r", stdin);
		//freopen("asd.txt", "w", stdout);
		mem(dp, 0);
		string a, b, c;
		cin>>a>>b>>c;
		vector<int> pi = kmp(c);
		//fore(i, 0, c.size()) cout<<pi[i]<<' ';
		int jo;
		fore(i, 1, a.size()+1)
		{
			fore(j, 1, b.size()+1)
			{
				fore(k, 0, c.size())
				{
					if(a[i-1] == b[j-1])
					{
						jo = k;
						while(jo > 0 && a[i-1] != c[jo]) 
							jo = pi[jo-1];
						if(c[jo] == a[i-1]) jo++;
						if(jo < c.size())
						{
							if(dp[k][i-1][j-1] + 1 > dp[jo][i][j])
							{
								par[jo][i][j] = mp(k, mp(i-1, j-1));
								dp[jo][i][j] = dp[k][i-1][j-1] + 1;
							}
						}
					}
					if(dp[k][i][j] < dp[k][i-1][j])
					{
						par[k][i][j] = mp(k, mp(i-1, j));
						dp[k][i][j] = dp[k][i-1][j];
					}
					if(dp[k][i][j] < dp[k][i][j-1])
					{
						par[k][i][j] = mp(k, mp(i, j-1));
						dp[k][i][j] = dp[k][i][j-1];
					}
				}
			}
		}
		int ma = 0, in = 0;
		fore(i, 0, c.size()) 
		{
			//cout<<dp[i][a.size()][b.size()]<<'\n';
			if(ma < dp[i][a.size()][b.size()])
			{
				ma = dp[i][a.size()][b.size()];
				in = i;
			}
		}
		int x = a.size(), y = b.size();
		string res = "";
		//cout<<ma<<'\n';
		if(ma == 0)
		{
			cout<<ma<<'\n';
			return 0;
		}
		int nk, nx, ny;
		while(x > 0 && y > 0)
		{
			nk = par[in][x][y].f;
			nx = par[in][x][y].s.f;
			ny = par[in][x][y].s.s;
			if(nx == x - 1 && ny == y - 1 && ma)
			{
				ma--;
				res += b[ny];
			}
			//cout<<x<<' '<<y<<' '<<in<<' '<<nx<<' '<<ny<<' '<<nk<<'\n';
			in = nk;
			x = nx;
			y = ny;
		}
		reverse(res.begin(), res.end());
		cout<<res<<'\n';
		return 0;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2