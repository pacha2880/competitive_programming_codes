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
		int n;
		ll k, inf = (1ll<<61);
		cin>>n>>k;
		ll v[n],nx[n];
		for(int i = 0; i < n; i++)
			cin>>v[i];
		int last = n;
		for(int i = n - 1; i > -1; i--)
		{
			nx[i] = last;
			if(v[i] > 1) last = i;
		}
		ll pro, sum;
		int res = 0;
		for(int i = 0; i < n; i++)
		{
			sum = 0, pro = 1;
			for(int j = i; j < n; j = nx[j])
			{
				if(pro > inf / v[j])
					break;
				sum += v[j];
				pro *= v[j];
				if(pro % k == 0)
				{
					ll x = pro / k - sum;
					if(x >= 0 && x <= nx[j] - j - 1)
						res++;
				}
				sum += nx[j] - j - 1;
			}
		}
		cout<<res;
		return 0;
	}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS