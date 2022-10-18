#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);
int cribi[100010];
int has[100010];
ll pot(ll b, ll e, ll m)
{
	ll res = 1;
	while(e > 0)
	{
		if(e & 1) res = res * b % m;
		b = b * b % m;
		e /= 2;
	}
	return res;
}
ll hs(string s)
{

	int p = 997, m[2], in[2];

		m[0] = 998244353, m[1] = 1000000009;
		ll h[2];
		fore(i, 0, 2)
		{
			in[i] = pot(p, m[i]-2, m[i]);
			ll acu = 1;
			h[i] = 0;
			fore(j, 0, s.size())
			{
				h[i] = (h[i] + acu * s[j]) % m[i];
				acu = (acu * p) % m[i];
			}
		}
	return (h[0] << 32) | h[1];;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	freopen("asd.txt", "w", stdout);
	fore(we, 28, 29)
	{
	string s = "";
	int ta = we;
	fore(i, 0, ta) s += 'y';
	string res;
	int op = 10000000;
	bool bo;
	string combo;
	int me;
	fore(i, 0, (1<<ta))
	{
		set<ll> st;
		fore(j, 0, ta)
		{
			if(((1<<j) & i) > 0)
				s[j] = 'y';
			else
				s[j] = 'Y';
		}
		fore(i, 0, ta)
		{
			fore(j, i, ta)
			{
				bo = true;
				if((j - i) & 1)
				{
					combo = s.substr(i, j - i + 1);
					me = combo.size()/2;
					fore(i, 0, me)
					{
						if(combo[i] != combo[i+me])
						{
							bo = false;
							break;
						}
					}
				}
				else
					bo = false;
				if(bo)
					st.insert(hs(combo));
			}
		}
		if(st.size() < op)
		{
			op = st.size();
			res = s;
		}

	}
	//cout<<op<<'\n';
	cout<<ta<<' '<<res<<'\n';
	}
	return 0;
}
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2