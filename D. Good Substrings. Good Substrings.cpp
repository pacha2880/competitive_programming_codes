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
	ll mod = (ll)MOD*293ll*8191ll;
	string s,a;
	bool good[26];
	int k, nu;
	cin>>s>>a>>k;
	for(int i = 0; i < 26; i++)
		good[i] = a[i]=='1';
	set<ll> st;
	ll stri;
	for(int i = 0; i < s.size(); i++)
	{
		nu = 0;
		stri = 0;
		for(int j = 1; j+i <= s.size(); j++ )
		{
			nu+=!good[s[i+j-1] - 'a'];
			if(nu > k)
				break;
			stri*=26ll;
			stri+= (ll)(s[i+j-1] - 'a' + 1);
			stri%=mod;
			st.insert(stri);
		}
	}
	cout<<st.size();
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS