#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


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
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "w", stdout);
	//freopen("qwe.txt", "r", stdin);
	int t;
	cin>>t;
	int x, y, n, res, ax;
	while(t--)
	{
		cin>>x>>y>>n;
				ax = n;
		if(x == y)
		{
			cout<<"0\n";
		}
		else if(n == 0)
		{
			if(x < y)
				cout<<1<<'\n';
			else
				cout<<0<<'\n';
		}
		else
		{
			int bi = 0, con = 0;
			fore(i, 0, 31)
			{
				if(((1 << i) & x) != ((1 << i) & y))
					bi = i;
			}
			if(n < (1<<bi));
			else if(n & (1<<bi))
			{
				con = 1;
				fore(i, 0, 31)
				{
					if((n & (1 << i)) && i != bi)
					{
						if(i > bi)
							con += (1 << (i - 1));
						else
							con += 1 << i;
					}
				}
			}
			else
			{
				if(n > (1<<bi))
				{
					fore(i, 0, 31)
					{
						if(((1 << i) & n) && i > bi)
						{
							n ^= (1<<i);
							fore(j, 0, i)
								n |= (1<<j);
							break;
						}
					}
					con = 1;
				}
				fore(i, 0, 31)
				{
					if((n & (1 << i)) && i != bi)
					{
						if(i > bi)
							con += (1 << (i - 1));
						else
							con += 1 << i;
					}
				}
			}
			n = ax;
			if(x < y)
				cout<<n - con + 1<<'\n';
			else
				cout<<con<<'\n';
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	