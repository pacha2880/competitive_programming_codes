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
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	int ar[n];
	cin>>ar[0];
	int pre = ar[0],a;
	for(int i=1;i<n;i++)
	{
		cin>>ar[i];
	}
	int x[n];
	bool b,q = false;
	vi res;
	for(int i = 1; i<=n;i++)
	{
		pre=0;
		for(int j=0;j<i;j++)
		{
			x[j]=ar[j]-pre;
			pre=ar[j];
		}
		b=true;
		for(int j=i;j<n;j++)
		{
			if(ar[j]!=x[(j)%i]+ar[j-1])
			{
				b=false;
				break;
			}
		}
		if(b) res.pb(i);
	}
	cout<<res.size()<<'\n';
	for(int i=0;i<res.size();i++)
	{
		if(i>0) cout<<' ';
		cout<<res[i];
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS