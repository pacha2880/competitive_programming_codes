	#include <bits/stdc++.h>
	#include <prize.h>
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

	/*int er[] = {4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 3, 1, 4, 4, 4, 4, 2, 4, 4, 4, 3};
	vector<int> ar(100034);
	int q;
	int n;
	vector<int> ask(int i)
	{
		q++;
		vector<int> res(2, 0);
		fore(j, 0, i)
			res[0] += ar[j] < ar[i];
		fore(j, i + 1, 100034)
			res[1] += ar[j] < ar[i];
		return res;
	}
	int find_best(int n);
	int main()
	{
		q = 0;
		fore(i, 0, 100000) ar[i] = 4;
		fore(i, 100000, 100034) ar[i] = er[i - 100000];
		cout<<find_best(100034)<<'\n';
		cout<<q<<'\n';
		return 0;
	}*/
	int res, su;
	void f(int b, int e, int mi, int ma)
	{
		int mini = (b + e) / 2, maxi = mini;
		bool bo = true;
		int can = 0;
		while(true)
		{
			if(bo)
			{	
				if(mini == b - 1) return;		
				auto ar = ask(mini);
				if(ar[0] + ar[1] == su)
				{
					if(ar[0] > mi)
						f(b, mini - 1, mi, ar[0]);
					if(ma > ar[0] + can)
						f(maxi + 1, e, ar[0] + can, ma);
					return;
				}
				else
				{
					if(ar[0] + ar[1] == 0)
					{
						res = mini;
						return;
					}
					can++;
					bo = false;
					maxi++;
				}
			}
			else
			{

				if(maxi == e + 1) return;		
				auto ar = ask(maxi);
				if(ar[0] + ar[1] == su)
				{
					if(ar[0] - can > mi)
						f(b, mini - 1, mi, ar[0] - can);
					if(ma > ar[0])
						f(maxi + 1, e, ar[0], ma);
					return;
				}
				else
				{
					if(ar[0] + ar[1] == 0)
					{
						res = maxi;
						return;
					}
					can++;
					bo = true;
					mini++;
				}
			}
		}
	}
	int find_best(int n)
	{
		pair<int, pair<int, int>> maxi{0,{0, 0}};
		fore(i, 0, 473)
		{
			auto ar = ask(i);
			if(ar[0] + ar[1] == 0)
				return i;
			if(ar[0] + ar[1] > 40)
			{
				maxi = mp(ar[0] + ar[1], mp(i, ar[0]));
				break;
			}
			maxi = max(maxi, mp(ar[0] + ar[1], mp(i, ar[0])));
		}
		int posa, canso;
		for(int i = n - 1; i > -1; i--)
		{
			auto ar = ask(i);
			if(ar[0] + ar[1] == 0)
				return i;
			if(ar[0] + ar[1] == maxi.f)
			{
				canso = ar[0];
				posa = i;
				break;
			}
		}
		su = maxi.f;
		f(maxi.s.f + 1, posa - 1, maxi.s.s, maxi.f);
		return res;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	