#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD				1000000007
#define MOD1			998244353
#define EPS				1e-9
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("asd1.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, k;
	cin>>n>>k;
	int ar[n];
	string s;
	cin>>s;
	vector<int> con;
	con.pb(0);
	char ig;
	int can  =0;
	fore(i, 0, n)
	{
		if(i == 0) ig = s[i];

		if(ig != s[i])
		{
			con.pb(can);
			ig = s[i];
			can = 1;
		}
		else
			can++;
	}
	con.pb(can);
	con.pb(0);
	int l, r;
	if(s[0] == '0')
		l = 0;
	else
		l = 1;
	int su = 0;
	fore(i, l, min((int)con.size(), 2*k+ l+1) )
		su += con[i];
	r = 2*k +((l-1)) + 1;
	int res = su;
	r+=2, l+=2;
	while(r < con.size())
	{
		su -= con[l-1] + con[l-2];
		su += con[r-1] + con[r];
		res = max(res, su);
		l += 2;
		r += 2;
	}
	cout<<res<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2