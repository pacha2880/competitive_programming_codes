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
		int sz;
		bool cmp(pair<ii,int> a, pair<ii,int> b)
		{
			int num = a.f.f/sz;
			if(num == b.f.f/sz)
				return ((num & 1) ? a.f.s < b.f.s : b.f.s < a.f.s);
			return a.f.f < b.f.f;
		}
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n,m,res = 0;
			cin>>n>>m;
			sz = sqrt(n) + 1;
			int ar[n], resp[m],ax[n+1];
			mem(ax,0);
			for(int i = 0; i < n; i++)
			{
				cin>>ar[i];
			}
			pair<ii,int> que[m];
			for(int i = 0; i < m; i++)
			{
				cin>>que[i].f.f;
				cin>>que[i].f.s;
				que[i].f.f--;
				que[i].f.s--;
				que[i].s = i;
			}
			sort(que, que + m, cmp);
			int l = 0, r = -1;
			for(int i = 0; i < m; i++)
			{
				while(l < que[i].f.f)
				{
					if(ar[l] <= n)
					{
						ax[ar[l]]--;
						if(ax[ar[l]] == ar[l])
							res++;
						if(ax[ar[l]] == ar[l] - 1)
							res--;
					}
					l++;
				}
				while(l > que[i].f.f)
				{	
					l--;
					if(ar[l] <= n)
					{
						ax[ar[l]]++;
						if(ax[ar[l]] == ar[l])
							res++;
						if(ax[ar[l]] == ar[l] + 1)
							res--;
					}
				}
				while(r < que[i].f.s)
				{
					r++;
					if(ar[r] <= n)
					{
						ax[ar[r]]++;
						if(ax[ar[r]] == ar[r])
							res++;
						if(ax[ar[r]] == ar[r] + 1)
							res--;
					}
				}
				while(r > que[i].f.s)
				{
					if(ar[r] <= n)
					{
						ax[ar[r]]--;
						if(ax[ar[r]] == ar[r])
							res++;
						if(ax[ar[r]] == ar[r] - 1)
							res--;
					}
					r--;
				}
				resp[que[i].s] = res;
			}
			for(int i = 0; i < m; i++)
				cout<<resp[i]<<'\n';
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS