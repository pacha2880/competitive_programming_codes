#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int ar[30010];
int ones[30010];
void build(int b, int e)
{
	if(b < e)
	{
		int mid = (b + e) / 2;
		ones[mid] = e - mid;
		build(b, mid);
		build(mid + 1, e);
	}
}
int findel(int b, int e, int k)
{
	if(e == b)
		return e + 1;
	int mid = (b + e) / 2;
	if(ones[mid] >= k)
	{
		ones[mid]--;
		return findel(mid + 1, e, k);
	}
	else
		return findel(b, mid, k - ones[mid]);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, a;
	cin>>n;
	ordered_set st;
	fore(i, 0, n)
	{
		cin>>ar[i];
	}
	build(0, n - 1);
	for(int i = n - 1; i > -1; i--)
	{
		if(ar[i] > i)
		{
			cout<<"NIE\n";
			return 0;
		}
		else
		{
			ar[i] = findel(0, n - 1, ar[i] + 1);
		}
	}
	fore(i, 0, n)
		cout<<ar[i]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	