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
int ar[40000000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, m, can = 0, k;
	cin>>n>>m>>k;
	string s[n];
	fore(i, 0, n) cin>>s[i];
	fore(i, 0, n)
	{
		fore(j, 0, m)
		{
			int au = 1;
			while(s[i][j] == '*' && i - au > -1 && i + au < n && j + au < m && j - au > -1)
			{
				if(s[i - au][j] == '*' && s[i + au][j] == '*' && s[i][j + au] == '*' && s[i][j - au] == '*')
					ar[can++] = (au * (n + 1) + i) * (m + 1) + j;
				au++;
			}
		}
	}
	sort(ar, ar + can);
	if(can < k)
		cout<<-1;
	else
	{
		int j = ar[k - 1] % (m + 1) + 1;
		int i = ar[k - 1] / (m + 1) % (n + 1) + 1;
		int au = ar[k - 1] / (m + 1) / (n + 1);
		cout<<i<<' '<<j<<'\n'<<i - au<<' '<<j<<'\n'<<i + au<<' '<<j<<'\n'<<i<<' '<<j - au<<'\n'<<i<<' '<<j + au<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	