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
const int tam = 300003;
ll bit[tam][2],resp[tam];
pair<pair<ll,int>,pair<int,int>> ar[tam];
void update(int pos,ll val, int bi)
{
	pos++;
	while(pos<tam-2)
	{
		bit[pos][bi]+=val;
		pos += (pos&-pos);
	}
}
ll query(int pos,int bi)
{
	ll res = 0;
	pos++;
	while(pos>0)
	{
		res+=bit[pos][bi];
		pos-=(pos&-pos);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n,m,a,b;
	cin>>n>>m;
	mem(bit,0);
	mem(resp,0);
	for(int i=0;i<n;i++)
	{
		cin>>ar[i].s.f>>ar[i].s.s;
		ar[i].f.f = ar[i].s.s-ar[i].s.f;
		ar[i].f.s=i;
		resp[i]-=ar[i].s.f+ar[i].s.s;
	}
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--,b--;
		if(ar[b].f.f>ar[a].f.f)
		{
			resp[a]-=ar[b].s.f+ar[a].s.s;
			resp[b]-=ar[a].s.s+ar[b].s.f;
		}
		else
		{
			resp[a]-=ar[a].s.f+ar[b].s.s;
			resp[b]-=ar[a].s.f+ar[b].s.s;
		}
	}
	sort(ar,ar+n);
	for(int i=0;i<n;i++)
	{
		update(i,ar[i].s.f,0);
		update(i,ar[i].s.s,1);
	}
	int lo,hi,mid,res;
	ll par[n];
	for(int i=0;i<n;i++)
	{
		lo = 0; hi = n-1, res = -1;
		while(lo<=hi)
		{
			mid = (lo+hi)/2;
			if(ar[mid].f.f<ar[i].f.f)
			{
				lo = mid+1;
				res=mid;
			}
			else
				hi=mid-1;
		}
		par[ar[i].f.s] = query(res,1) + query(n-1,0) -query(res,0) + ar[i].s.f*(ll)(res+1) + ar[i].s.s*(ll)(n-res-1);
		resp[ar[i].f.s] += par[ar[i].f.s];
	}
	for(int i=0;i<n;i++)
	{
		if(i>0) cout<<' ';
		cout<<resp[i];
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS