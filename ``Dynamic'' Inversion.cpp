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
		int BIT[200010];
				int ar[200010],po[200010],posq[200010],por[200010],nen[200010];
		void update(int pos, int val)
		{
			pos++;
			while(pos < 200010)
			{
				BIT[pos] += val;
				pos += (pos & -pos);
			}
		}
		int query(int pos)
		{
			pos++;
			int res = 0;
			while(pos > 0)
			{
				res += BIT[pos];
				pos -= (pos & -pos);
			}
			return res;
		}
		int squ[450][450];
		int main()
		{
			ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("asd.txt", "w", stdout);
			int n, m,a,hi,lo,res,mid;
			ll inv;
			while(cin>>n)
			{
				cin>>m;
				inv = 0;
				ar[n]=n;
				for(int i = 0; i < n; i++)
				{
					cin>>ar[i];
					ar[i]--;
				}
				mem(nen,0);
				mem(BIT,0);
				for(int i = n-1; i > -1; i--)
				{
					inv += (ll)query(ar[i]);
					update(ar[i], 1);
				}
				int sz = sqrt(n)+1;
				for(int i = 0;i<sz;i++)
					squ[sz-1][i] = n;
				int in = 0;
				for(int i = 0; i < n; i += sz)
				{
					for(int j = i; j < i + sz && j < n; j++)
					{
						squ[in][j-i] = ar[j];
						po[ar[j]] = j;
						posq[ar[j]] = in;
					}
					in++;
				}
				for(int i = 0; i < sz; i++)
				{
					sort(squ[i],squ[i]+sz);
				}
				for(int i = 0;i<sz;i++)
				{
					if(squ[sz-1][i] == n)
						nen[sz-1]++;
				}
				for(int i = 0; i < n; i++)
				{
					por[squ[i/sz][i%sz]]=i%sz;
				}
				int pos, poq;
				res=0;
				while(m--)
				{
					cin>>a;
					cout<<inv<<'\n';
					a--;
					pos = po[a];
					poq = posq[a];
					if(pos % sz != 0)
					{
						poq++;
						while(pos%sz!=0 && pos < n)
						{
							if(ar[pos]<a)
								inv--;
							pos++;
						}
					}
					for(int i = poq; i < sz ; i++)
					{
						hi=sz-1, lo=0, res=-1;
						while(lo<=hi)
						{
							mid = (lo + hi) / 2;
							if(squ[i][mid]<a)
							{
								res = mid;
								lo = mid +1;
							}
							else
								hi = mid - 1;
						}
						inv -= (ll)res+1ll;
					}
					pos = po[a];
					poq = posq[a];
					if(pos % sz != sz-1)
					{
						poq--;
						while(pos%sz!=sz-1 && pos > -1)
						{
							if(ar[pos]>a&&ar[pos]!=n)
								inv--;
							pos--;
						}
					}
					for(int i = poq; i > -1; i--)
					{
						hi=sz-1, lo=0, res=sz;
						while(lo<=hi)
						{
							mid = (lo + hi) / 2;
							if(squ[i][mid]>a)
							{
								res = mid;
								hi = mid - 1;
							}
							else
								lo = mid + 1;
						}
						inv -= (ll)sz-(ll)res-(ll)nen[i];
					}
					nen[posq[a]]++;
					ar[po[a]]=n;
					squ[posq[a]][por[a]]=n;
					sort(squ[posq[a]],squ[posq[a]]+sz);
					for(int i = 0; i<sz;i++)
					{
						por[squ[posq[a]][i]]=i;
					}

				}
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS