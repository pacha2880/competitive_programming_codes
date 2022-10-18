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
ll w[100000];
int b,e;
vi pri;
vll pric;
bitset<100000> bi;
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
ll modpow(ll base, ll exp, ll modu)
{
	if(exp==0) return 1;
	ll res = (modpow((base*base)%modu,exp/2,modu)*(exp&1?base:1));
	return (res>log2(modu)?res%modu+modu:res);
}
ll fie(ll n)
{
	int s = pri.size(), i = 0;
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
	if(n>1) res--;\
	return res;
}
ll phipow(ll base, int ind,ll modu)
{
	if(ind == e)
		return (base>log2(modu)?base%modu+modu:base);
	if(modu==1) return 0;
	ll fi = fie(modu), exp = phipow(w[ind+1],ind+1,fi);
		ll a = modpow(base,exp,modu);
		return a;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int n,q;
	ll modu;
	criba();
	cin>>n>>modu;
	for(int i=0;i<n;i++)
		cin>>w[i];
	cin>>q;
	bool t;
	while(q--)
	{
		cin>>b>>e;
		b--;
		e--;
		cout<<phipow(w[b],b,modu)%modu<<endl;
	}
	return 0;
}