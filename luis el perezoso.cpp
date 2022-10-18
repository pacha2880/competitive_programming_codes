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
	vi pri;
	vll pric;
	bitset<100000> bi;
	void criba()
	{
		bi.set();
		for(int i=2;i<100000;i++)
		{
			if(bi[i])
			{
				for(int j = i + i; j < 100000; j += i)
					bi[j] = 0;
				pri.pb(i);
				pric.pb(ll(i)*ll(i));
			}
		}
	}

	map<ll,int> fac(ll n)
	{
		map<ll,int> res;
		int i = 0, s = pri.size();
		while(pric[i]<n)
		{
			while(n%pri[i]==0)
			{
				res[pri[i]]++;
				n/=pri[i];
			}
			i++;
			if(i == s)
				break;
		}
		if(n>1)
			res[n]++;
		return res;
	}
	ll pot(ll b, int e)
	{
		if(e == 0) return 1;
		return pot(b*b,e/2)*(e&1?b:1);
	}
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);	
		ll n;
		criba();
		cin>>n;
		map<ll,int> mp;
		map<ll,int>::iterator it,itt;
		mp = fac(n);
		ll du = pot(2ll,mp[2ll])*(2ll),nu;
		it = mp.begin();

		for (auto itt : mp) {}
		pair<int, string> is = {12, "sfds"};
	
		if(it->first == 2ll)
			it++;
		for(;it!=mp.end();it++)
		{
			cout<<it->first<<' '<<it->second<<endl;
			nu = it->first;
			for(int i=0;i<it->second;i++)
			{
				itt = it;
				itt++;
				for(;itt!=mp.end();itt++)
				{
					
				}
			}
		}
		cout<<du;
		return 0;
	}