	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			firs
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
bitset<200000> bi;
vector<ll> pri,pric;
void criba()
{
	bi.set();
	bi[0]=bi[1]=0;
	for(int i=2;i<200000;i++)
	{
		if(bi[i])
		{
			for(int j = i+i;j<200000;j+=i)
				bi[j]=0;
			pri.pb(i);
			pric.pb((ll)i*(ll)i);
		}
	}
}
ll count(ll n)
{
	ll res = 1,z;
	int con = 0;
	while(pric[con]<=n)
	{
		if(n%pri[con]==0)
		{
			z=1;
			while(n%pri[con]==0)
			{
				z++;
				n/=pri[con];
			}
			res*=z;
		}
		con++;
	}
	if(n>1) res*=2;
	return res;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll n;
	cin>>n;
	criba();
	cout<<count(n)<<endl;;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS