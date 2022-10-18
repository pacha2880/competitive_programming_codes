#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
vector<string> split(string s, char ch)
{
	vector<string> res;
	string ac = "";
	fore(i, 0, s.size())
	{
		if(s[i] == ch)
		{
			res.pb(ac);
			ac = "";
		}
		else
			ac += s[i];
	}
	res.pb(ac);
	return res;
}
vector<ll> poly(string s)
{
	vector<ll> res;
	for(int i = s.size() - 1; i > -1; i--)
	{
		res.pb(s[i] - '0');
	}
	return res;
}
vector<ll> add(vector<ll> a, vector<ll> b)
{
	if(a.size() < b.size())
		swap(a, b);
	fore(i, 0, b.size())
		a[i] += b[i];
	return a;
}
vector<ll> mult(vector<ll> a, vector<ll> b)
{
	vector<ll> res((int)a.size() + (int)b.size() - 1, 0);
	fore(i, 0, a.size())
		fore(j, 0, b.size())
			res[i + j] += a[i] * b[j];
	return res;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	string s;
	while(true)
	{
		cin>>s;
		int minba = 2;
		fore(i, 0, s.size())
		{
			if(s[i] >= '0' && s[i] <= '9')
				minba = max(minba, 1 + s[i] - '0');
		}
		if(s == "=")
			break;
		vector<string> exp, sum, mul;
		vector<ll> pola, polb, polc, pold;
		exp = split(s, '=');
		sum = split(exp[0], '+');
		mul = split(sum[0], '*');
		pola = poly(mul[0]);
		fore(i, 1, mul.size())
		{
			polb = poly(mul[i]);
			pola = mult(pola, polb);
		}
		fore(i, 1, sum.size())
		{
			mul = split(sum[i], '*');
			polc = poly(mul[0]);
			fore(i, 1, mul.size())
			{
				polb = poly(mul[i]);
				polc = mult(polc, polb);
			}
			pola = add(pola, polc);
		}
		pold = pola;
		sum = split(exp[1], '+');
		mul = split(sum[0], '*');
		pola = poly(mul[0]);
		fore(i, 1, mul.size())
		{
			polb = poly(mul[i]);
			pola = mult(pola, polb);
		}
		fore(i, 1, sum.size())
		{
			mul = split(sum[i], '*');
			polc = poly(mul[0]);
			fore(i, 1, mul.size())
			{
				polb = poly(mul[i]);
				polc = mult(polc, polb);
			}
			pola = add(pola, polc);
		}
		fore(i, 0, pola.size()) pola[i] = -pola[i];
		pola = add(pola, pold);
		int st = 0;
		while(st < pola.size() && pola[st] == 0) st++;
		if(st == pola.size())
		{
			cout<<minba<<"+\n";
		}
		else
		{
			vector<ll> res;
			//cout<<minba<<' '<<pola[st]<<'\n';
			fore(i, 1, abs(pola[st]))
			{
				if(1ll * i * i > abs(pola[st]))
					break;
				if(pola[st] % i == 0)
				{
					//cout<<i<<" we ";
					vector<ll> ca;
					if(i >= minba)
						ca.pb(i);
					if(i != abs(pola[st]) / i && abs(pola[st]) / i >= minba) 
						ca.pb(abs(pola[st]) / i);
					fore(i, 0, ca.size())
					{
						bool bo = true;
						ll ac = pola[st] / ca[i];
						//cout<<ac<<' '<<pola[st]<<' '<<ca[i]<<'\n';
						fore(j, st + 1, pola.size())
						{
							ac += pola[j];
							if(ac % ca[i] != 0)
							{
								bo = false;
								break;
							}
							ac /= ca[i];
						}
						//cout<<"asd "<<ca[i]<<' '<<ac<<'\n';
						if(ac == 0 && bo)
							res.pb(ca[i]);
					}
				}
			}
			if(res.size() == 0)
				cout<<"*\n";
			else
			{
				sort(all(res));
				fore(i, 0, res.size())
				{
					if(i > 0) cout<<' ';
					cout<<res[i];
				}
				cout<<'\n';
			}
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2		