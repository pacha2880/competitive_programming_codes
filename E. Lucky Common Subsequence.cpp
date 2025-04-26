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
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vi kmp(string s)
{
	int n = s.size();
	vi pi(n, 0);
	fore(i, 1, n)
	{
		int j = pi[i - 1];
		while(j > 0 && s[j] != s[i])
			j = pi[j - 1];
		if(s[j] == s[i])
			j++;
		pi[i] = j;
	}
	return pi;
}
int aut[tam][26];
void genAut(string &s) {
	vi pi = kmp(s);
	int n = sz(s);
	fore(i, 0, n) {
		aut[i][s[i] - 'A'] = i + 1;
	}
	fore(i, 0, n + 1) {
		fore(c, 0, 26){
			if(aut[i][c]) continue;
			if (i < n && s[i] == 'A' + c) aut[i][c] = i + 1;
			else if(i > 0) aut[i][c] = aut[pi[i - 1]][c];
			else aut[i][c] = 0;
		}
	}
}
int dp[110][110][110];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	string a, b, c;
	cin>>a>>b>>c;
	int n = sz(a), m = sz(b), o = sz(c);
	genAut(c);
	fore(i, 0, n) a[i] -= 'A';
	fore(i, 0, m) b[i] -= 'A';
	// fore(i, 0, o)
	// {
	// 	fore(j, 0, 26)
	// 		cout<<aut[i][j]<<' ';
	// 	cout<<'\n';
	// }
	fore(i, 1, n + 1)
		fore(j, 1, m + 1)
		{
			fore(k, 0, o)
			{
				// cout<<(char)b[j]<<'\n';
				// cout<<i<<' '<<j<<' '<<k<<' '<<aut[k][a[i]]<<' '<<aut[k][b[j]]<<endl;
				dp[i][j][k] = max(dp[i - 1][j][k], dp[i][j][k]);
				dp[i][j][k] = max(dp[i][j - 1][k], dp[i][j][k]);
				if(a[i - 1] == b[j - 1])
				{
					dp[i][j][aut[k][b[j - 1]]] = max(dp[i][j][aut[k][b[j - 1]]], dp[i - 1][j - 1][k] + 1);
				}
			}
		}
	ii res(0, 0);
	fore(i, 0, o)
	{
		// cout<<i<<' '<<dp[n][m][i]<<'\n';
		res = max(res, {dp[n][m][i], i});
	}
	// cout<<res.f<<' '<<res.s<<'\n';
	// return 0;
	if(res.f)
	{
		int i = n, j = m, k = res.s;
		string out;
		int cana = res.f;
		while(cana)
		{
			// cout<<i<<' '<<j<<' '<<k<<' '<<cana<<'\n';
			// cout<<(char)('A' + a[i - 1])<<' '<<(char)('A' + b[j - 1])<<'\n';
				if(dp[i - 1][j][k] == cana)
				{
					i--;
					continue;
				}
				if(dp[i][j - 1][k] == cana)
				{
					j--;
					continue;
				}
			fore(kk, 0, o)
			{
				if(aut[kk][b[j - 1]] == k && a[i - 1] == b[j - 1] && dp[i - 1][j - 1][kk] == cana - 1)
				{
					cana--;
					out += b[j - 1] + 'A';
					i--;
					j--;
					k = kk;
					break;
				}
			}
		}
		reverse(all(out));
		cout<<out<<'\n';
	}
	else
		cout<<0<<'\n';
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
