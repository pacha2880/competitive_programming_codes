#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
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
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll tam = 100010;
const ll MOD = 1e9+7;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	ll lev[70];
	lev[0] = 0;
	fore(i, 1, 70)
		lev[i] = lev[i-1] * 2 + 1;
	ll n, k;
	char ch[3];
	while(cin>>n)
	{
		cin>>k;
		ch[0] = 'A', ch[1] = 'B', ch[2] = 'C';
			if(n < 64 && k > lev[n])
			{
				cout<<"Orz\n";
				continue;
			}
			ll al = 0;
			while(lev[al] < k)
			{
				al++;
			}
			if((n - al) % 2 == 1)
				swap(ch[1], ch[2]);
			n = al;
			//cout<<n<<' '<<k<<'\n';
			int pos = 0;
			while(lev[n-1] + 1 != k)
			{
				if(lev[n-1] < k)
				{
					k -= lev[n-1] + 1;
					swap(ch[0], ch[2]);
				}
				else
				{
					swap(ch[1], ch[2]);
				}
				n--;
			}
		cout<<"move "<<n<<" from "<<ch[0]<<" to "<<ch[1]<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2