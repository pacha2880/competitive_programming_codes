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
		ii num[100500], ax[100500];
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			int n,q,a,b,x,res,lo,hi,mid,re;
			char t;
			cin>>n>>q;
			sz=sqrt(n);
			for(int i = 0;i < n; i++)
			{
				cin>>num[i].f;
				num[i].s = i; 
			}
			for(int i = n; i< 100500;i++)
			{
				num[i].f=INT_MAX;
				num[i].s=i;
			}
			for(int i = 0; i < 100500; i++)
				ax[i] = num[i];
			for(int i = 0 ; i < n; i += sz)
			{
				sort(num + i, num + i + sz);
			}
			for(int i = 0; i < n; i++)
				ax[num[i].s].s = i;
			for(int i = 0; i < q; i++)
			{
				cin>>t;
				if(t=='M')
				{
					cin>>a>>x;
					a--;
					ax[a].f=x;
					num[ax[a].s].f=x;
					a = a/sz;
					sort(num + a, num + a + sz);
					for(int i = a; i < a + sz; i++)
					{
						ax[num[i].s].s = i;
					}
				}
				else
				{
					res=0;
					cin>>a>>b>>x;
					a--;
					b--;
					while(a % sz != 0 && a <= b)
					{
						if(ax[a].f <= x)
							res++;
						a++;
					}
					while(b % sz != sz-1 && a < b)
					{
						if(ax[b].f <= x)
							res++;
						b--;
					}
					cout<<res<<' ';
					for(int i = a; i < b; i+=sz)
					{
						for(int j = i; j< i+sz; j++)
							cout<<num[j].f<<' ';
						cout<<endl;
						lo = a, hi = a + sz - 1, re = a - 1;
						while(lo <= hi)
						{
							mid = (hi +lo)/2;
							if(num[mid].f<=x)
							{
								re = mid;
								lo = mid + 1;
							}
							else
								hi = mid - 1;
						}
						res += re + 1 - a;
					}
					cout<<res<<endl;
				}
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS