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
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
bitset<40000> bi;
vi pri, pric;
int maxi;
void criba()
{
	bi.set();
	bi[0]=bi[1]=0;
	for(int i=2;i<40000;i++)
		if(bi[i])
		{
			for(int j=i+i;j<40000;j+=i)
				bi[j]=0;
			pri.pb(i);
			pric.pb(i*i);
		}
}
bool prime(int n)
{
	if(n>maxi)
	{
		for(int i=0;pric[i]<=n;i++)
			if(n%pri[i]==0)
				return false;
		return true;
	}
	else
		return bi[n];
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	criba();
	maxi = pri[pri.size()-1];
	int n;
	while(cin>>n)
	{
		while(!prime(n))
			n--;
		cout<<n<<endl;
	}
	return 0;
}