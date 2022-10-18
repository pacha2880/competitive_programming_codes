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
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n;
			cin>>n;
			ll a,b,c,ra,rb,rc,ma, ab, bc, ac, abc, sa,sb,sc;
			ll par;
			bool bba,bbb,bbc;
			ll res;
			for(int i = 0; i<n;i++)
			{
				cin>>a>>b>>c;
				ra=sqrt(a), rb = sqrt(b), rc = sqrt(c);
				ma = max(ra,max(rb,rc));
				ab=bc=ac=abc=sa=sb=sc=0;
				if(ra*ra==a)
				{
					if(a==b&&b==c)
					{
						ab++;
						ac++;
						bc++;
						abc++;
					}
					else
						if(a==b)
							ab++;
						else
							if(a==c)
								ac++;
							else
								sa++;

				}
				else
					if(rb*rb==b)
					{
						if(b==c)
							bc++;
						else
							sb++;
					}
					else
						if(rc*rc==c)
							sc++;
				for(int i = 1; i <= ma; i++)
				{
					bba=bbb=bbc=0;
					if(i<=ra&&i*i!=a)
					{
						if(a%i==0)
						{
							bba=1;
						}
					}
					if(i<=rb&&i*i!=b)
					{
						if(b%i==0)
						{
							bbb=1;
						}
					}
					if(i<=rc&&i*i!=c)
					{
						if(c%i==0)
						{
							bbc=1;
						}
					}
					if(bba&&bbb&&bbc)
					{
						ab+=2;
						ac+=2;
						bc+=2;
						abc+=2;
					}
					else
					{
						if(bba&&bbb)
							ab+=2;
						else
							if(bba&&bbc)
								ac+=2;
							else
								if(bbb&&bbc)
									bc+=2;
							else
							{
								if(bba)
									sa+=2;
								if(bbb)
									sb+=2;
								if(bbc)
									sc+=2;
							}
					}
				}
				cout<<sa<<' '<<sb<<' '<<sc<<' '<<ab<<' '<<bc<<' '<<ac<<' '<<abc<<endl;
				res=0;
				res+=sa*sb*sc;
				abc--;
				res+=((abc*abc*abc+6ll*abc*abc+11ll*abc+6ll)/6ll)*(abc>=0ll?1ll:0ll);
				par=(ab*(ab+1ll))/2ll;
				res+=par*(sc?1ll&&ab>1ll:0ll);
				res+=par*sc;
				par=(ac*(ac+1ll))/2ll;
				res+=par*(sb?1ll&&ac>1ll:0ll);
				res+=par*sb;
				par=(bc*(bc+1ll))/2ll;
				res+=par*(sa?1ll&&bc>1ll:0ll);
				res+=par*sa; 
				cout<<res<<'\n';
			}

			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS 	