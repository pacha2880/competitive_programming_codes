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
		ll ar[200020], br[200000];
	int main()
	{
		ios::sync_with_stdio(false); cin.tie(0);
		//freopen("qwe.txt", "r", stdin);
		//freopen("asd.txt", "w", stdout);
		int n;
		cin>>n;
		for(int i = 0; i<n/2; i++)
		{
			cin>>br[i];
		}
		ll ce = ar[n/2-1] = br[n/2-1]/2;
		ll to = ar[n/2] = ar[n/2-1] +(br[n/2-1]&1);
		for(int i = n/2-2; i>-1;i--)
		{
			if(br[i]-to<ce)
			{
				ce = br[i]-to;
				ar[i] = ce;
				ar[n-i-1] = to;
			}
			else
			{
				to = br[i] - ce;
				ar[i] = ce;
				ar[n-1-i] = to;
			}
		}
		for(int i = 0 ;i<n; i++)
		{
			if(i>0)cout<<' ';
			cout<<ar[i];
		}
		return 0;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS