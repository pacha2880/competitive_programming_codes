			#include <bits/stdc++.h>
		#define PI 			acos(-1)
		#define mp			make_pair
		#define pb			push_back
		#define all(a)		(a).begin(), (a).end()
		#define srt(a)			sort(all(a))
		#define mem(a, h)	memset(a, (h), sizeof(a))
		#define f 			first
		#define s 			second
		#define MOD			1000000007
		int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

		using namespace std;

		typedef long long 		ll;
		typedef unsigned long long 		ull;
		typedef pair<int, int>  ii;
		typedef vector<int>     vi;
		typedef vector<ii>      vii;
		typedef vector<ll>      vll;
		pair<ii,int> que[200001];
		ll res = 0;
		int sz;
		ll ar[200001], ax[1000001];
		bool cmp(pair<ii,int> a, pair<ii,int> b)
		{
			int num = a.f.f/sz;
			if(num == b.f.f/sz)
				return (num & 1 ? a.f.s < b.f.s : b.f.s < a.f.s);
			return a.f.f < b.f.f;
		}
		void add(ll val)
		{
			res -= ax[val]*ax[val]*val;
			ax[val]++;
			res += ax[val]*ax[val]*val;
		}
		void sub(ll val)
		{
			res -= ax[val]*ax[val]*val;
			ax[val]--;
			res += ax[val]*ax[val]*val;
		}
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n,m;
			cin>>n>>m;
			sz = sqrt(n) + 1;
			ll resp[m];
			mem(ax,0);
			for(int i = 0; i < n; i++)
				cin>>ar[i];
			for(int i = 0; i < m; i++)
			{
				cin>>que[i].f.f>>que[i].f.s;
				que[i].f.f--;
				que[i].f.s--;
				que[i].s = i;
			}
			sort(que, que + m, cmp);
			int l = 0, r =-1, L, R;
			for(int i = 0; i < m; i++)
			{
				L = que[i].f.f, R= que[i].f.s;
				while(l < L)
				{
					sub(ar[l]);
					l++;
				}
				while(l > L)
				{
					l--;
					add(ar[l]);	
				}
				while(r > R)
				{
					sub(ar[r]);
					r--;
				}
				while(r < R)
				{
					r++;
					add(ar[r]);
				}
				resp[que[i].s] = res;
			}
			for(int i = 0; i < m; i++)
			{
				cout<<resp[i]<<'\n';
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS