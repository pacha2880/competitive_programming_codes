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
		ii inte(ii a, ii b)
		{
			if(a.s < b.f)
			{
				return mp(-1,-1);
			}
			if(b<a) swap(a,b);
			return mp(b.f,a.s);
		}
		ii res(ii a, ii b)
		{
			if(a.s < b.f)
			{
				return mp(-1,-1);
			}
			if(b<a) swap(a,b);
			return mp(b.f,a.s);
		}
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n;
			cin>>n;
			ii le,sl, seg[n];
			le.f = le.s = sl.f = sl.s = 0;
			int fi = 0, se = 0;
			for(int i = 0;i<n;i++)
			{
				cin>>seg[i].f>>seg[i].s;
				if(seg[i].s-seg[i].f<fi)
				{
					se = fi;
					sl = le;
					 fi = seg[i].s-seg[i].f;
					 le = seg[i];
				}
				else
					if(seg[i].s-seg[i].f<se)
					{
						se =seg[i].s-seg[i].f;
						sl = seg[i];	
					}	
			}
			ii tota = le, totb = sl;
			int con1 = 0,con2=0, fi1,fi2;
			ii ax,ax1,ax2;
			for(int i = 0;i<n;i++)
			{
				ax = tota;
				tota = inte(tota, seg[i]);
				if(tota==mp(-1,-1))
				{
					if(con1 ==0)
					{
						tota = ax;
					}
					con1++;
				}
				ax = totb;
				totb = inte(totb,seg[i]);
				if(totb==mp(-1,-1))
				{
					if(con2 ==0)
					{
						totb = ax;
					}
					con2++;
				}
			}
			if(con1 == 1)
			{
				cout<<tota.s-tota.f;
				return 0;
			}
			if(con1 >1 )
			{
				if(con2 >1)
					cout<<0;
				else
					cout<<totb.s-totb.f;
				return 0;
			}
			for(int i =0;i<n;i++)
			{

			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS