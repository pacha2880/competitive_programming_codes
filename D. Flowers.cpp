#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007ll
#define EPS			1e-9
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
ll BIT[100005], ar[100005];
int n,k;
void update(int pos, ll val)
{
	pos++;
	while(pos <= 100005)
	{
		BIT[pos] += val;
		BIT[pos] %= MOD;
		pos += (pos & -pos);
	}
}
ll query(int pos)
{
	pos++;
	ll res = 0;
	while(pos > 0)
	{
		res += BIT[pos];
		res %= MOD;
		pos -= (pos & -pos);
 	}
 	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	cin>>n>>k;
	mem(BIT,0);
	for(int i = 0; i < k-1; i++)
	{
		update(i, 1);
		ar[i] = 1;
	}
	update(k-1,2);
	ar[k-1] = 2;
	for(int i = k; i < 100001; i++)
	{
		ar[i] = ar[i-1] + ar[i-k];
		ar[i] %= MOD;
		update(i,ar[i]);
	}
	int a,b;
	ll res;
	for(int i = 0; i < n; i++)
	{
		cin>>a>>b;
		res = ((query(b-1) - query(a-2))%MOD + MOD)%MOD;
		cout<<res<<'\n'; 	
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS