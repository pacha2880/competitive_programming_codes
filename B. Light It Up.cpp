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
			//ios::sync_with_stdio(false); cin.tie(0);
			//freopen("", "r", stdin);
			//freopen("", "w", stdout);
			ll n,s;
			cin>>n>>s;
			ll po[n],pre[n];
			for(ll i = 0;i<n;i++)
			{
				cin>>po[i];
			}
			pre[n-1]=(s-po[n-1])*(n%2==0?1:0);
			for(ll i = n-2;i>-1;i--)
			{
				pre[i] = pre[i+1] +(po[i+1]-po[i])*(i%2==1?1:0);
			}
			ll ma = 0;
			for(ll i = 0;i<n-1;i+=2)
			{
				ma = max(ma, (s-po[i]-pre[i]-1)-pre[i]);
			}
			ma = max(ma, (s-po[n-1]-1)*(n%2==1?1:0)-pre[n-1]);
			cout<<ma+po[0]+pre[0];
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS