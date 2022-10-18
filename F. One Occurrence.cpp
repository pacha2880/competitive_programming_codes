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
		int res=0,sz;
		int par[850],ar[500000],frec[500002];

			pair<pair<int,int>,int> que[500000];
		void add(int val,int ind)
		{
			frec[val]++;
			if(frec[val]==1)
			{
				par[ind/sz]++;
				res++;
			}
			else
				if(frec[val]==2)
				{
					par[ind/sz]--;
					res--;
				}
		}
		void sub(int val,int ind)
		{
			frec[val]--;
			if(frec[val]==1)
			{
				par[ind/sz]++;
				res++;
			}
			else
				if(frec[val]==0)
				{
					par[ind/sz]--;
					res--;
				}
		}
		int query()
		{
			if(res == 0) return 0;
			for(int i = 0; i <= sz; i++)
			{
				if(par[i]>0)
				{
					for(int j = sz*i;;j++)
					{
						if(frec[ar[j]]==1)
						{
							return ar[j];
						}
					}		
				}
			}
		}
		bool cmp(pair<pair<int,int>,int> a, pair<pair<int,int>,int> b)    
		{
			int num = a.f.f/sz, nub = b.f.f/sz;
		  if (num == nub)
		  {
		    return (num&1? a.f.s < b.f.s : a.f.s > b.f.s);
		  }
		  return num < nub;
		}
		int main()
		{
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			mem(par,0);
			int n,m;
			scanf("%d", &n);
			sz=sqrt(n);
			//cin>>n;
			//sz = sqrt(n);
			mem(frec,0);
			for(int i = 0;i<n;i++)
			{
				//cin>>ar[i];
				scanf("%d", &ar[i]);
			}
			//cin>>m;
			scanf("%d", &m);
			for(int i = 0; i < m; i++)
			{
				scanf("%d %d", &que[i].f.f, &que[i].f.s);
				que[i].f.f--;
				que[i].f.s--;
				que[i].s=i;
			}
			sort(que, que + m, cmp);
			for(int i = que[0].f.f;i<=que[0].f.s;i++)
			{
				add(ar[i],i);
			}
			int l = que[0].f.f,r=que[0].f.s;
			int resp[m];

			resp[que[0].s]=query();
			for(int j =1;j<m;j++)
			{
				if(que[j].f.f<l)
				{
					while(que[j].f.f<l)
					{
						l--;
						add(ar[l],l);
					}
				}
				else
				{
						while(l<que[j].f.f)
					{
						sub(ar[l],l);
						l++;
					}
				}
				if(que[j].f.s<r)
				{
						while(que[j].f.s<r)
					{
						sub(ar[r],r);
						r--;
					}
				}
				else
				{
						while(r<que[j].f.s)
					{
						r++;
						add(ar[r],r);
					}
				}
				resp[que[j].s]=(query());
			}
			for(int i = 0; i < m; i++)
			{
				//cout<<resp[i]<<'\n';
				printf("%d\n", resp[i]);
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS

