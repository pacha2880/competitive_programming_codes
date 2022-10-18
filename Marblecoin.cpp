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
		int A[400004], T[600003];
		ll pot[500000];
		void init(int b, int e, int node)
		{
			if(b==e) {T[node] = A[b]; return;}
			int mid = (b + e) /2, l = node*2+1, r = l+1;
			init(mid+1, e, r);
			init(b,mid, l);
			T[node] = max(T[l],T[r]);
		}
		int query(int b, int e, int node, int i, int j)
		{
			if(b>=i&&e<=j) return T[node];
			int mid = (b+e)/2, l = node*2+1, r= l+1;
			if(mid<i) return query(mid+1,e,r,i,j);
			if(mid>=j) return query(b,mid,l,i,j);
			return max(query(b,mid,l,i,j),query(mid+1,e,r,i,j));
		}
		bool comp(vector<ll> a, vector<ll> b)
		{
			int i =a.size()-1, j = b.size()-1;
			while(a[i]==b[j]&&i>-1&&j>-1)
				i--, j--;
			if(i==-1) return false;
			if(j==-1) return true;
			return a[i]>b[j];
		}
		int main()
		{
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			ll mod = 1000000007ll;
			pot[0]=1;
			for(int i = 1;i<500000;i++)
			{
				pot[i] = (pot[i-1]*365ll)%mod;
			}
			int n,m,res,from,lo,hi,mid,maxi,val;
			ll fin;
			vector<vector<ll>> sv;
			vector<ll> v;
			while(cin>>n)
			{
				sv.clear();
				while(n--)
				{
					cin>>m;
					for(int i = 0; i<m;i++)
					{
						cin>>A[m-i-1];
					}
					init(0,m-1,0);
					res=0;
					from = 0;
					while(from<m)
					{
						maxi = query(0,m-1,0,from,m-1);
						lo = from,hi = m-1;
						while(lo<=hi)
						{
							mid = (lo + hi) / 2;
							val = query(0,m-1,0,mid,m-1);
							if(val==maxi)
							{
								res = mid;
								lo = mid + 1;
							}
							else
								if(val>maxi)
									lo = mid + 1;
								else
									hi = mid-1;
						}
						val = sv.size();
						sv.pb(v);
						for(int i = from; i<=res; i++)
							sv[val].pb(A[i]);
						from = res+1;
					}
				}
				sort(sv.begin(), sv.end(), comp);
				val = 1;
				fin=0;
				for(int i = 0; i< sv.size();i++)
				{
					for(int j = 0; j < sv[i].size();j++)
					{
						fin += (sv[i][j]*pot[val])%mod;
						fin%=mod;
						val++;
					}
				}
				cout<<fin<<endl;
			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS