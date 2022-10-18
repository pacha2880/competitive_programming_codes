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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
int ar[100010]; 
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	vector<int> v, v1;
	fore(i, 0, n)
	v.pb(i + 1);
	int a, b;
	while(v.size() > 1)
	{
		v1.clear();
		forg(i, 1, v.size(), 2)
		{
			cout<<"? "<<v[i - 1]<<' '<<v[i]<<'\n';
			cout.flush();
			cin>>a;
			cout<<"? "<<v[i]<<' '<<v[i - 1]<<'\n';
			cout.flush();
			cin>>b;
			if(a > b)
			{
				ar[v[i - 1] - 1] = a;
				v1.pb(v[i]);
			}
			else
			{
				ar[v[i] - 1] = b;
				v1.pb(v[i - 1]);	
			}
		}
		if(v.size() % 2 == 1)
			v1.pb(v.back());
		swap(v, v1);
	}
	ar[v[0] - 1] = n;
	cout<<'!';
	fore(i, 0, n)
	cout<<' '<<ar[i];
	cout<<'\n';
	cout.flush();
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2		