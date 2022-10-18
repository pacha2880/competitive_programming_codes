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
#define fore(i, b, e)	for(ll i = b; i < e; i++)
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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1);
int si[2];
ll v[2][2000000];
char nextchar(string &s, int &ind)
{
	if(ind == s.size())
		return 0;
	return s[ind++];
}
ll nextint(string &s, int &ind)
{
	ll res = 0;
	while(s[ind] >= '0' && s[ind] <= '9')
	{
		res *= 10;
		res += (int)(s[ind++] - '0');
	}
	return res;
}
int ops[2000000];
pair<pair<int, int>, int> sec[2000000];
pair<pair<int, int>, int> st[2000000];
void proc(string s, int in, bool bo)
{
	char ch;
	int state = 0;
	int isec = 0;
	int iops = 0;
	int ist = 0;
	int par;
	pair<int, int> ran1;
	pair<pair<int, int>, int> rac1, rac2;
	int opi;
	string candi = "";
	si[in] = 0;
	set<ll> sat;
	int ind = 0;
	int op = -1;
	while(1)
	{
		if(ind == s.size())
			break;
		ch = s[ind++];
		//cout<<ch<<' '<<state<<'\n';
		if(state == 0)
		{
			if(ch == '(')
			{
				ops[iops++] = op;
			}
			else if(ch == '[')
			{
				par = si[in];
				v[in][si[in]++] = nextint(s, ind);
				//cout<<v[in][si[in]-1]<<'\n';
				state = 1;
			}
			else if(ch == ')')
			{
				opi = ops[--iops];
				if(opi == 2)
				{
					sec[isec-1].s = 0;
					st[ist++] = sec[isec - 1];
				}
				if(opi == 1)
				{
					rac1 = sec[--isec];
					rac2 = sec[--isec];
					sec[isec++] = mp(mp(rac2.f.f, rac1.f.s), -1);
				}
				if(opi == 3)
				{
					sec[isec - 1].s = 1;
					st[ist++] = sec[isec - 1];
				}
			}
			else if(ch == ',')
			{

			}
			else if(ch == 'c')
			{
				op = 1;
				ind += 5;
				//cout<<s[ind]<<' '<<ind<<" co\n";
			}
			else if(s[ind] == 'o')
			{
				op = 2;
				ind += 5;
				//cout<<s[ind]<<' '<<ind<<" so\n";
			}
			else
			{
				op = 3;
				ind += 6;
				//cout<<s[ind]<<' '<<ind<<" sh\n";
			}
		}
		else if(state == 1)
		{
			if(ch ==']')
			{
				state = 0;	
				sec[isec++] = mp(mp(par, si[in]), -1);
			}
			else
			{
				v[in][si[in]++] = nextint(s, ind);
			}
		}
	}
	//cout<<"chacha\n";
	pair<int, int> last = mp(10000000, 10000000);
	//cout<<st.size()<<' '<<si[in]<<'\n';
	//sort(st, st + ist);
	reverse(st, st + ist);
	fore(i, 0, ist)
	{
		ran1 = st[i].f;
		if(last.f > st[i].f.f)
		{
			sort(v[in] + ran1.f, v[in] + ran1.s);
			if(bo && st[i].s == 1)
			{
				reverse(v[in] + ran1.f, v[in] + ran1.s);
			}
			last = st[i].f;
		}
	}
	//cout<<'\n';
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("110.in", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	string a, b;
	cin>>a>>b;
	fore(k, 0, 2)
	{
		proc(a, 0, k);  proc(b, 1, k);
		if(si[0] == si[1])
		{
			fore(i, 0, si[0])
			{
				if(v[0][i] != v[1][i])
				{
					cout<<"not equal\n";
					return 0;
				}
			}
		}
		else
		{
			cout<<"not equal\n";
			return 0;
		}
	}
	cout<<"equal\n";
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	