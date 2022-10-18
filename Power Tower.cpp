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
vi pri;
vll pric;
bitset<100000> bi;

	int l,r;

	int a[100030];
void criba()
{
	bi.set();
	for(int i=2;i<100000;i++)
		if(bi[i])
		{
			for(int j=i+i;j<100000;j+=i)
				bi[j]=0;
			pri.push_back(i);
			pric.push_back((ll)i*(ll)i);
		}
}
ll phi(int n)
{
	int s = pri.size(), i =0;
	ll res = n;
	while(pric[i]<=n)
	{
		if(n%pri[i]==0)
			res-=res/pri[i];
		while(n%pri[i]==0)
			n/=pri[i];
		i++;
		if(i==s) break;
	}
	if(n>1) res-= res/n;
	return res;
}
ll modpow(ll base, ll exp, ll modu)
{
	if(exp==0) return 1;
	ll b = base*base;
	ll res = (modpow((b>modu?b%modu+modu:b),exp/2,modu)*(exp&1?base:1));
	return (res>modu?res%modu+modu:res);
}
ll pow(ll x,ll y,ll mod){
	ll z=1;
	while(y){
		if(y&1) z=z*x;
		if(z>mod) z=z%mod+mod; //en realidad >log2(mod)
		x=x*x;
		if(x>mod) x=x%mod+mod; //en realidad >log2(mod)
		y>>=1;
	}
	return z;
}
ll phipow(ll base, int ind, ll modu)
{
	
	if(modu == 1) return 1;
	if(ind == r) return (base>=modu?(base%modu +modu):base);
	ll fi = phi(modu), exp =phipow(a[ind+1],ind+1,fi);
	return modpow(base,exp,modu);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	criba();
	int n, modu,q;
	cin>>n>>modu;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		l--;
		r--;
		cout<<phipow(a[l],l,modu)%modu<<endl;
	}

	return 0;
}