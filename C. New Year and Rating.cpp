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
const int MOD = 1000000009;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int ar[200010], di[200020];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, maxo = 0;
	int ini = 0;
	cin>>n;
	set<int> st;
	fore(i, 0, n) 
	{
		cin>>ar[i]>>di[i];
		st.insert(di[i]);
		ini += ar[i];
		if(i < n - 1)
			maxo = max(maxo, ini);
	}
	//cout<<maxo<<'\n';
	if(st.size() == 1)
	{
		if(*st.begin() == 1)
			cout<<"Infinity\n";
		else
			cout<<1899 - maxo + ini<<'\n';
	}
	else
	{
		ini = 0;
		fore(i, 0, n)
		{
			if(i > 0)
			{
				if(di[i] != di[i-1])
				{
					break;
				}
			}
			ini -= ar[i];
		}
		ini += 1900;
		//cout<<ini<<'\n';
		int betin;
		int maxin = -MOD;
		bool bo;
		fore(i, 0, 210)
		{
			betin = ini + i;
			bo = true;
			fore(i, 0, n)
			{
				if(betin < 1900 && (di[i] == 1) || betin >= 1900 && (di[i] == 2))
				{
					bo = false;
					break;
				}
				betin += ar[i];
			}
			if(bo)
				maxin = max(maxin, betin);
		}
		fore(i, 1, 210)
		{
			betin = ini - i;
			bo = true;
			fore(i, 0, n)
			{
				if(betin < 1900 && (di[i] == 1) || betin >= 1900 && (di[i] == 2))
				{
					bo = false;
					break;
				}
				betin += ar[i];
			}
			if(bo)
				maxin = max(maxin, betin);
		}
		if(maxin != -MOD)
			cout<<maxin<<'\n';
		else
			cout<<"Impossible\n";
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	