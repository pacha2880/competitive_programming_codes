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
		#define EPS			1e-9
		int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

		using namespace std;

		typedef long long 		ll;
		typedef unsigned long long 		ull;
		typedef pair<int, int>  ii;
		typedef vector<int>     vi;
		typedef vector<ii>      vii;
		typedef vector<ll>      vll;
		bool comp(ii a, ii b)
		{
			return (a.s==b.s? a.f>b.f : a.s < b.s);
		}
		bool comp1(ii a, ii b)
		{
			return (a.f==b.f? a.s>b.s : a.f < b.f);
		}
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n,m,k;
			int suma[] = {1,1,1,-1,-1,-1,0,0},suma1[] = {1,0,-1,1,0,-1,1,-1};
			map<int,map<int,bool> > ma;
			map<int,map<int,pair<int,int> > > ma1,ma2,ma3,ma4;
			cin>>n>>m;
			ii ar[m];
			for(int i =0;i<m;i++)
			{
				cin>>ar[i].f>>ar[i].s;
				ma[ar[i].f][ar[i].s]=1;
				ma1[ar[i].f][ar[i].s]=ma2[ar[i].f][ar[i].s]=mp(ar[i].f,ar[i].s);
				ma3[ar[i].f][ar[i].s]=mp(ar[i].f,ar[i].f);
				ma4[ar[i].f][ar[i].s]=mp(ar[i].s,ar[i].s);
			}
			for(int i=0;i<m;i++)
			{
				for(int j=0;j<15;j++)
				{
					k=j%8;
					if(ma[ar[i].f+suma[k]][ar[i].s+suma1[k]])
					{
						ma1[ar[i].f+suma[k]][ar[i].s+suma1[k]].f = max(ma1[ar[i].f+suma[k]][ar[i].s+suma1[k]].f,ma1[ar[i].f][ar[i].s].f);
						ma1[ar[i].f+suma[k]][ar[i].s+suma1[k]].s = max(ma1[ar[i].f+suma[k]][ar[i].s+suma1[k]].s,ma1[ar[i].f][ar[i].s].s);	
						ma1[ar[i].f][ar[i].s]=ma1[ar[i].f+suma[k]][ar[i].s+suma1[k]];	
						ma2[ar[i].f+suma[k]][ar[i].s+suma1[k]].f = min(ma2[ar[i].f+suma[k]][ar[i].s+suma1[k]].f,ma2[ar[i].f][ar[i].s].f);
						ma2[ar[i].f+suma[k]][ar[i].s+suma1[k]].s = min(ma2[ar[i].f+suma[k]][ar[i].s+suma1[k]].s,ma2[ar[i].f][ar[i].s].s);	
						ma2[ar[i].f][ar[i].s]=ma2[ar[i].f+suma[k]][ar[i].s+suma1[k]];	
						ma3[ar[i].f+suma[k]][ar[i].s+suma1[k]].f = max(ma3[ar[i].f+suma[k]][ar[i].s+suma1[k]].f,ma3[ar[i].f][ar[i].s].f);
						ma3[ar[i].f+suma[k]][ar[i].s+suma1[k]].s = min(ma3[ar[i].f+suma[k]][ar[i].s+suma1[k]].s,ma3[ar[i].f][ar[i].s].s);	
						ma3[ar[i].f][ar[i].s]=ma3[ar[i].f+suma[k]][ar[i].s+suma1[k]];
						ma4[ar[i].f+suma[k]][ar[i].s+suma1[k]].f = max(ma4[ar[i].f+suma[k]][ar[i].s+suma1[k]].f,ma4[ar[i].f][ar[i].s].f);
						ma4[ar[i].f+suma[k]][ar[i].s+suma1[k]].s = min(ma4[ar[i].f+suma[k]][ar[i].s+suma1[k]].s,ma4[ar[i].f][ar[i].s].s);	
						ma4[ar[i].f][ar[i].s]=ma4[ar[i].f+suma[k]][ar[i].s+suma1[k]];	
					}
				}
				if((ma1[ar[i].f][ar[i].s].f==n)&&(ma1[ar[i].f][ar[i].s].s==n)||(ma2[ar[i].f][ar[i].s].f==1)&&(ma2[ar[i].f][ar[i].s].s==1)
					||(ma3[ar[i].f][ar[i].s].f==n)&&(ma3[ar[i].f][ar[i].s].s==1)||(ma4[ar[i].f][ar[i].s].f==n)&&(ma4[ar[i].f][ar[i].s].s==1))
				{
					cout<<-1;
					return 0;
				}
			}
			sort(ar,ar+m,comp);
			int maa=0,mii=n;
			for(int i=0;i<m;i++)
			{
				if(ma3[ar[i].f][ar[i].s].s<=maa || ma3[ar[i].f][ar[i].s].s==1)
					maa=max(maa,ma3[ar[i].f][ar[i].s].f);
			}
			if(maa==n)
			{
					cout<<-1;
					return 0;
				}
			sort(ar,ar+m,comp1);
			maa=0;
			for(int i=0;i<m;i++)
			{
				if(ma4[ar[i].f][ar[i].s].s<=maa || ma4[ar[i].f][ar[i].s].s==1)
					maa=max(maa,ma4[ar[i].f][ar[i].s].f);
			}
			if(maa==n)
			{
					cout<<-1;
					return 0;
				}
			cout<<n*2-2;
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS