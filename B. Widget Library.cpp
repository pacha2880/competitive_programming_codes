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
#define forn(i, n)			for(ll i = 0; i < n; i++)
#define fore(i, b, e)	for(ll i = b; i < e; i++)
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
//ll in(){ll r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const ll tam = 100010;
const ll MOD = 1000000007;
const ll MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
struct wid
{
	ll wi, hi, tip, bor, spa;
	vector<wid*> v;
	wid(ll wi, ll hi) : wi(wi), hi(hi)
	{
		tip = 0;
	}
	wid(ll tip) : tip(tip) {
		wi = -1, hi = -1;
		bor = spa = 0;
	}
	void add(wid *w)
	{
		//cout<<"estoy addiendo a   -->>  "<<w->wi<<' '<<w->hi<<'\n';
		v.pb(w);
	}
	ll getWi()
	{
		if(wi != - 1) return wi;
		if(tip == 1)
		{
			ll su = bor * 2 + (sz(v) - 1) * spa;
			if(sz(v) == 0) su = 0;
			for(auto cat : v)
				su += cat->getWi();
			return wi = su;
		}
		else
		{
			ll ma = 0;
			if(sz(v) == 0) return wi = 0;
			for(auto cat : v)
				ma = max(ma, cat->getWi());
			return wi = ma + bor * 2;
		}
	}
	ll getHi()
	{
		if(hi != -1) return hi;
		if(tip == 0)
		{
			ll su = bor * 2 + (sz(v) - 1) * spa;
			if(sz(v) == 0) su = 0;
			for(auto cat : v)
				su += cat->getHi();
			return hi = su;
		}
		else
		{
			ll ma = 0;
			if(sz(v) == 0) return hi = 0;
			for(auto cat : v)
				ma = max(ma, cat->getHi());
			return hi = ma + bor * 2;
		}
	}
};
ll toll(string s)
{
	ll res = 0;
	fore(i, 0, s.size())
	{
		res *= 10;
		res += s[i] - '0';
	}
	return res;
}
pair<string, string> spla(string s, char ch)
{
	ll in = 0;
	while(s[in] != ch) in++;
	return {s.substr(0, in), s.substr(in + 1)};
}
typedef wid* pwid;
map<string, pwid> todo;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	ll n;
	cin>>n;
	string s, so, sa;
	vector<string> va;
	cin.ignore();
	fore(kl, 0, n)
	{
		getline(cin, s);
		stringstream sc;
		sc << s;
		bool bo = false;
		while(sc >> s)
		{
			if(s == "Widget")
			{
				sc >> s;
				ll i = 0;
				so = "";
				while(s[i] != '(')
					so += s[i++];
				auto cat = spla(s.substr(i + 1, s.size() - i - 2), ',');
				todo[so] = new wid(toll(cat.f), toll(cat.s));
			}
			else if(s == "VBox")
			{
				sc >> s;
				todo[s] = new wid(0);
			}
			else if(s == "HBox")
			{
				sc >> s;
				todo[s] = new wid(1);
			}
			else
			{
				//cout<<"coco\n";
				auto cat = spla(s, '.');
				s = cat.f;
				ll i = 0;
				so = "";
				while(cat.s[i] != '(')
					so += cat.s[i++];
				string susu = cat.s.substr(i + 1, cat.s.size() - i - 2);
				//cout<<so<<'\n';
				//cout<<susu<<' '<<toll(susu)<<'\n';	
				if(so == "pack")
					todo[cat.f]->add(todo[susu]);
				else if(so == "set_border")
					todo[cat.f]->bor = toll(susu);
				else
					todo[cat.f]->spa = toll(susu);
			}
		}
	}
	for(auto cat : todo)
	{
		cout<<cat.f<<' '<<cat.s->getWi()<<' '<<cat.s->getHi()<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constralls?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs ll?) ARRAY OUT OF BOUNDSS2	