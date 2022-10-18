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
	//freopen("asd.txt", "w", stdout);
	int n, d;
	ll din;
	cin>>n>>d>>din;
	ii ar[n];
	int poso[n];
	ll sus[n];
	fore(i, 0, n) {cin>>ar[i].f; ar[i].s = i;}
	ar[n-1].f = 0;
	sort(ar, ar + n);
	reverse(ar, ar + n);
	sus[0] = ar[0].f;
	poso[ar[0].s] = 0;
	fore(i, 1, n)
	{
		poso[ar[i].s] = i;
		sus[i] = sus[i-1] + ar[i].f;
	}
	//fore(i, 0, n)
	//cout<<sus[i]<<'\n';
	fore(i, 0, n - 1)
	{
		//cout<<din<<' ';
		if(poso[i] < d)
		{
			//cout<<'@'<<sus[d-1]<<'\n';
			if(sus[d-1] > din)
			{
				cout<<i+1<<'\n';
				return 0;
			}
		}
		else
		{
			//cout<<(d > 1 ? sus[d-2] : 0) + ar[poso[i]].f<<'\n';
			if((d > 1 ? sus[d-2] : 0) + ar[poso[i]].f > din)
			{
				cout<<i + 1<<'\n';
				return 0;
			}
		}
	}
	cout<<n<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	