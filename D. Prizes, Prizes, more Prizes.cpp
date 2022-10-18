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
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll n,a,b,c,d,e;
	cin>>n;
	ll ar[n];
	for(int i = 0; i< n; i++)
		cin>>ar[i];
	cin>>a>>b>>c>>d>>e;
	ll res[5];
	mem(res,0);
	ll sum = 0;
	for(int i = 0; i<n; i++)
	{
		sum+=ar[i];
		while(sum>=a)
		{
			if(sum>=e)
			{
				res[4]+= sum/e;
				sum%=e;
			}
			else
				if(sum>=d)
				{
					res[3]+= sum/d;
					sum%=d;
				}
				else
					if(sum>=c)
					{
						res[2]+= sum/c;
						sum%=c;
					}
					else
						if(sum>=b)
						{
							res[1]+= sum/b;
							sum%=b;
						}
						else
						{
							res[0]+= sum/a;
							sum%=a;
						}
		}
	}
	for(int i = 0; i<5; i++)
	{
		if(i>0) cout<<' ';
		cout<<res[i];
	}
	cout<<endl<<sum;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS