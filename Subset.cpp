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
			int n,a,num;
			cin>>n;
			int sz = sqrt(n),li,res;
			int ar[1<<16],sos[1<<16];
			vi del,add;
			string s;
			mem(ar,0);
			mem(sos,0);
			for(int i = 0; i < n; i += sz)
			{
				li = i + sz;
				add.clear();
				del.clear();
				for(int j = i; j < li && j < n; j++)
				{
					cin>>s>>num;
					if(s == "add")
					{
						ar[num]++;
						add.pb(num);
					}
					else
						if(s == "del")
						{
							del.pb(num);
							ar[num]--;
						}
						else
						{
							res = 0;
							res += sos[num];
							for(int k = 0; k < add.size(); k++)
								res += ((num & add[k]) == add[k]);
							for(int k = 0; k < del.size(); k++)
								res -= ((num & del[k]) == del[k]);
							cout<<res<<endl;
						}
				}
				mem(sos,0);
				for(int j = 0; j < (1<<16); j++)
					sos[j] = ar[j];
				for(int j = 0; j < 16; j++) for(int mask = 0; mask < (1<<16); mask++)
				{
					if(mask & (1 << j))
						sos[mask] += sos[mask ^ (1 << j)];
				}

			}
			return 0;
		}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS