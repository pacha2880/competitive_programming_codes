#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define MOD1		998244353
#define EPS			1e-9
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n,ua,ub,uc,ca,cb,cc;
	cin>>n;
	string a,b,c;
	while(n--)
	{
		cin>>a>>b>>c;
		ua = 0, ub = 0, uc = 0;
		for(int i = 0; i < a.size(); i++)
		{
			ua += a[i] == '1';
			ub += b[i] == '1';
			uc += c[i] == '1';
		}
		ca = a.size() - ua;
		cb = a.size() - ub;
		cc = a.size() - uc;
		int mi = min(ua,min(cb,cc));
		int res = mi;
		ua -= mi;
		cb -= mi;
		cc -= mi;
		mi = min(ub,min(ca,cc));
		res += mi;
		ub -= mi;
		ca -= mi;
		cc -= mi;
		mi = min(uc,min(ca,cb));
		uc -= mi;
		ca -= mi;
		cb -= mi;
		res += mi;
		res += min(ua,min(ub,uc));
		for(int i = 0; i < res; i++)
			cout<<1;
		for(int i = res; i < a.size(); i++)
			cout<<0;
		cout<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS