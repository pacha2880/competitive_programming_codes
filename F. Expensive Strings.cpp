#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


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
const int tam = 2000030;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> asd;
bool cmp(int a, int b)
{
	return asd[a] < asd[b];
}
int fruta[tam];
vector<int> suffixa(vector<int> &s)
{
	int n = s.size(), cc, ax;
	vector<int> sa(n), sa1(n), col(n), col1(n), head(n);
	fore(i, 0, n) sa[i] = i;
	asd = s;
	stable_sort(sa.begin(), sa.end(), cmp);
	head[0] = col[sa[0]] = cc = 0;
	fore(i, 1, n)
	{
		if(s[sa[i]] != s[sa[i - 1]])
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
		swap(sa, sa1);
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

vector<int> lcp(vector<int> &s, vector<int> &sa)
{
	int n = s.size(), k, z = 0;
	vector<int> sa1(n), lcp(n);
	fore(i, 0, n) sa1[sa[i]] = i;
	fore(i, 0, n)
	{
		k = sa1[i];
		if(k < n - 1)
			while(s[i + z] == s[sa[k + 1] + z])
				z++;
		lcp[k] = z;
		z = max(z - 1, 0);
	}
	return lcp;
}
ll vals[tam];
ll ar[tam], sui[tam], suf[tam], ur[tam];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n;
	cin>>n;
	int yr = n;
	vector<string> ss(n);
	fore(i, 0, n) cin>>ss[i];
	vector<int> s;
	int pos = 0, x;
	ll res = 0, ras = -1;
	int cu = MOD, ca = -MOD;
	fore(i, 0, n)
	{
		cin>>x;
		fore(j, pos, pos + ss[i].size())
			vals[j] = x;
		fore(j, 0, ss[i].size())
			s.pb(ss[i][j]);
		s.pb(ras--);
		pos += ss[i].size();
		vals[pos] = 0;
		pos++;
	}
	fore(i, 0, s.size())
		vals[(int)s.size() + i] = vals[i];
	int ti = s.size();
	fore(i, 0, ti)
	{
		s.pb(s[i]);
		if(s[i + ti] < 0)
			s[i + ti] = ras--;
	}
	vector<int> su = suffixa(s);
	vector<int> lc = lcp(s, su);
	n = s.size();
	fore(i, 0, n)
		ar[i] = vals[su[i]];
	int po = 0, nu = -1;
	fore(i, 0, n)
	{
		if(i > 0)
			suf[i] = suf[i - 1] + ar[i];
		else
			suf[i] = ar[i];
	}
	stack<int> st;
	set<int> cocos;
	ll pi = 0, pu = 0;
	int pili;
	fore(i, 0, n)
	{
		while(!st.empty() && lc[st.top()] > lc[i])
		{
			nu = st.top();
			st.pop();
			if(!st.empty() && lc[st.top()] == lc[nu]) continue;
			res = max(res, (suf[i] - (st.empty() ? 0 : suf[st.top()])) * lc[nu]);
		}
		st.push(i);
	}
	cout<<res / 2<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	