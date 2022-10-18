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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	freopen("asd.txt", "w", stdout);
	__int128 cat[40];
	for(int i=0;i<40;i++)
	{
		int n = i;
		__int128 bino[n+1];
		fore(i, 0, n+1) bino[i] = 0;
		bino[0]=1;
		for(int i=1;i<=2*n;i++)
			for(int j=min(i,n);j>0;j--)
				bino[j]+=bino[j-1];
		cat[i] = bino[n]/(n+1);
		//cout<<i<<"   "<<(ll)cat[i]<<'\n';
	}
	__int128 cato[40][40];
	fore(i, 0, 40) fore(j, 0, 40) cato[i][j] = 0;
	fore(i, 1, 40)
	cato[0][i] = 1;
	fore(i, 2, 40)
	{
		fore(j, 1, 40)
		{
			fore(k, 0, j)
				cato[j][i] += cato[k][i-1] * cato[j-1-k][i-1]; 
		}
	}
	cout<<'{';
	fore(i, 1, 39)
	{
		if(i > 1) cout<<',';
		cout<<'{';

		fore(j, 1, 39)
		{
			if(j > 1) cout<<',';
				cout<<(ll)(cat[i] - cato[i][j]);
		}
		cout<<'}';
	}
	cout<<'}';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2