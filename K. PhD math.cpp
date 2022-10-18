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

typedef unsigned long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

string tosrt(ll n)
{
	string res = "";
	if(n == 0) return "0";
	char ch;
	while(n>0)
	{
		ch = n%10 + '0';
		res += ch;
		n/=10;
	}
	reverse(res.begin(), res.end());
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int casos;
	cin>>casos;
	while(casos--)
	{
		ll a, b, p, nu;
		int n;
		cin>>a>>b>>n>>p;
		string num = "";
		while(num.size() < n)

		{
			a *= 10;
			nu = a/b;
			a = a % b;
			num += tosrt(nu);
		}
		ll axi[p], axi2[p];
		mem(axi, 0);
		ll res = 0;
		for(int i = 0; i < n; i++)
		{
			ll asd = num[i] - '0';
			ll su = asd % p; 
			for(int j = 0; j < p; j++)
			{
				axi2[(j + su)%p] = axi[j];
			}
			axi2[su]++;
			res += axi2[0];
			mem(axi, 0);
			for(int j = 0; j < p; j++)
			{
				axi[(j*10)%p]+= axi2[j];
			}

		}
		cout<<res<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS