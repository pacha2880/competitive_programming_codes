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
			ii ara[200001],ta[600004];
			void inita(int b, int e, int node)
			{
				if(b == e) {ta[node] = ara[b]; return;}
				int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
				inita(b, mid, l);
				inita(mid + 1, e, r);
				{
					ta[node].f = max(ta[l].f, ta[r].f);
					ta[node].s = min(ta[l].s, ta[r].s);
				}
			}
			ii querya(int b, int e, int node, int i, int j)
			{
				if(b >= i && e <= j)
					return ta[node];
				int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
				if(i > mid)
					return querya(mid + 1, e, r, i, j);
				if(j <= mid)
					return querya(b, mid, l, i, j);
				ii x = querya(mid + 1, e, r, i, j), 
				    y = querya(b, mid, l, i, j), p;
				    p.f=max(x.f,y.f);
				    p.s=min(x.s,y.s);
				return p;
			}
			int main()
			{
				ios::sync_with_stdio(false); cin.tie(0);
				//freopen("", "r", stdin);
				//freopen("", "w", stdout);
				int n, lo, hi, mid, resi, resj;
				ll res = 0;
				cin>>n;
				for(int i = 0; i < n; i++)
					cin>>ara[i].f;
				for(int i = 0; i < n; i++)
					cin>> ara[i].s;
				inita(0,n-1,0);
				ii p;
				for(int i = 0; i < n; i++)
				{
					lo = i, hi = n - 1, resi = 0;
					while(lo <= hi)
					{
						mid = (lo + hi) / 2;
						p = querya(0,n-1,0,i,mid);
						
						if(p.f == p.s)
						{
							resi = mid;
							hi = mid - 1;
						}
						else
							if(p.f < p.s)
								lo = mid + 1;
							else
								hi = mid - 1;
					}
					lo = i, hi = n - 1, resj = -1;
					while(lo <= hi)
					{
						mid = (lo + hi) / 2;
						p = querya(0,n-1,0,i,mid);
						
						if(p.f == p.s)
						{
							resj = mid;
							lo = mid + 1;
						}
						else
							if(p.f < p.s)
								lo = mid + 1;
							else
								hi = mid - 1;
					}
					res += (ll)(resj - resi + 1);
				}
				cout<<res;
				return 0;
			}

		// read the question correctly (is y a vowel? what are the exact constraints?)
		// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS