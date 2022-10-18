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
ll n,tam;
ll ar[140000], t[700000];
void init(int b, int e, int node,int level)
{
	if(b == e)
	{
		t[node] = ar[b];
		//cout<<t[node]<<' '<<node<<' '<<level<<" hoja\n";
		return;
	}
	int mid = (b+e)/2, l = node*2+1, r= l+1;
	init(b, mid, l, level+1);
	init(mid+1, e, r, level +1);
	if((level%2+2)%2 != (n%2+2)%2)
	{
		//cout<<"asd";
		t[node] = t[l]|t[r];
	}
	else
		t[node] = t[l]^t[r];
	//cout<<t[node]<<' '<<node<<' '<<level<<' '<<(level%2+2)%2<<' '<<(n%2+2)%2<<' '<<t[l]<<' '<<t[r]<<" el nodo\n"<<n<<endl;
}
void update(int b, int e, int node, int pos, ll val, int level)
{
	if(b == e)
	{
		t[node] = val;
		return;
	}
	int mid = (b+e)/2, l = node*2+1, r = l +1;
	if(pos>mid)
		update(mid+1, e, r, pos, val, level+1);
	else
		update(b, mid, l,pos, val, level+1);
	if((level%2+2)%2 != (n%2+2)%2)
		t[node] = t[l]|t[r];
	else
		t[node] = t[l]^t[r];
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int q;
	cin>>n>>q;
	tam=1;
	int m = n;
	while(m--)
		tam*=2;
	//cout<<tam<<" tamano"<<endl;
	for(int i = 0; i < tam; i++)
	{
		cin>>ar[i];
	}
	init(0,tam-1,0,0);
	int a;
	ll b;
	//cout<<t[0]<<" el primero"<<endl;
	for(int i = 0; i < q; i++)
	{
		cin>>a>>b;
		update(0,tam-1, 0, a-1, b,0);
		cout<<t[0]<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS