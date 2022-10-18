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
string asd;
bool cmp(int a, int b)
{
	return asd[a] < asd[b];
}
vector<int> suffixa(string &s)
{
	int n = s.size(), cc, ax;
	vector<int> sa(n), sa1(n), col(n), col1(n), head(n);
	fore(i, 0, n) sa[i] = i;
	asd = s;
	stable_sort(sa.begin(), sa.end(), cmp);
	head[0] = col[sa[0]] = cc = 0;
	fore(i, 1, n)
	{
		if(s[sa[i]] != s[sa[i-1]])
			cc++, head[cc] = i;
		col[sa[i]] = cc;
	}
	for(int k = 1; k < n; k *= 2)
	{
		fore(i, 0, n)
		{
			ax = (sa[i] - k + n) % n;
			sa1[head[col[ax]]++] = ax;
		}
		sa = sa1;
		col1[sa[0]] = head[0] = cc = 0;
		fore(i, 1, n)
		{
			if(col[sa[i]] != col[sa[i - 1]] || col[(sa[i] + k) % n] != col[(sa[i - 1] + k) % n])
				cc++, head[cc] = i;
			col1[sa[i]] = cc;
		}
		col = col1;
	}
	return sa;

}
vector<int> lcp(string &s, vector<int> &sa)
{
	int n = s.size(), k, z = 0;
	vector<int> sa1(n), lcp(n);
	fore(i, 0, n) sa1[sa[i]] = i;
	fore(i, 0, n)
	{
		k = sa1[i];
		if(k < n - 1)
			while(s[i + z] == s[sa[k+1] + z])
				z++;
		lcp[k] = z;
		z = max(z-1, 0);
	}
	return lcp;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n;
	cin>>n;
	string s, ax;
	char ch = 'Z' + 1;
	bool bo;
	while(n--)
	{
		cin>>s;
		ax = s;
		if(s.size() == 1)
		{
			cout<<1;
			continue;
		}
		int li = 0;
		s += ch;
		s += '$';
		int in = 1;
		vector<int> mins;
		vector<int> sa = suffixa(s), lc = lcp(s, sa);
		{
			bo = true;
			for(int i = 1; i < s.size()-1; i++)
			{
				if(li > sa[i]) {break;}
				li = sa[i];
				mins.pb(sa[i]);
				in++;
			}
			ax += '$';
			sa = suffixa(ax);
			lc = lcp(ax, sa);
			in = mins.size();
			vector<pair<int,int>> ve;
			int le = 0;
			fore(i, 1, in)
			{
				ve.pb(mp(le, sa[i]));
				if(lc[i] + sa[i] != ax.size()-1)
					le++;
			}
			sort(ve.begin(), ve.end());
			fore(i, 0, in)
			{
				cout<<mins[i]<<' ';
			}
			cout<<'\n';
			fore(i, 0, in)
			{
				cout<<ve[i].f<<' '<<ve[i].s<<'\n';;
			}
			cout<<'\n';
			fore(i, 0, in)
			{
				if(ve[i].s != mins[i])
				{
					bo = false;
					break;
				}
			}
			if(bo) cout<<1; else cout<<0;
		}
	}
	cout<<'\n';
	return 0;
}
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2