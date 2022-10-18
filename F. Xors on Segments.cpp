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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
const int sq = 500;
int ar[tam];
int res[tam];
bool comp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
	if(a.f.f / sq == b.f.f / sq)
		return a.f.s < b.f.s;
	return a.f.f / sq < b.f.f / sq;
}
struct trie
{
	int maxo, mino, nam;
	trie* ce;
	trie* un;
	trie() {ce = un = NULL; maxo = 0; mino = MOD;}
};
typedef trie* ptrie;
void del(ptrie t)
{
	if(t)
	{
		del(t->ce);
		del(t->un);
		delete t;	
	}
}
void add(string &s, int ind, int num, ptrie t, int nam)
{
	if(ind < s.size())
	{
		ptrie go;
		if(s[ind] == '0')
		{
			if(t->ce == NULL)
				t->ce = new trie();
			go = t->ce;
		}
		else
		{
			if(t->un == NULL)
				t->un = new trie();
			go = t->un;
		}
		add(s, ind + 1, num, go, nam);
	}
	else
		t->nam = nam;
	t->maxo = max(max(t->ce ? t->ce->maxo : 0, t->un ? t->un->maxo : 0), num);
	t->mino = min(min(t->ce ? t->ce->mino : MOD, t->un ? t->un->mino : MOD), num);
}
int ask1(string &s, int ind, int num, ptrie t)
{
	if(ind == s.size())
		return t->nam;
	ptrie go;
	if(s[ind] == '0')
	{
		if(t->un != NULL && t->un->maxo > num)
			go = t->un;
		else if(t->ce != NULL && t->ce->maxo > num)
			go = t->ce;
		else
			return -1;
	}
	else
	{
		if(t->ce != NULL && t->ce->maxo > num)
			go = t->ce;
		else if(t->un != NULL && t->un->maxo > num)
			go = t->un;
		else
			return -1;
	}
	return ask1(s, ind + 1, num, go);
}
int ask2(string &s, int ind, int num, ptrie t)
{
	if(ind == s.size())
		return t->nam;
	ptrie go;
	if(s[ind] == '0')
	{
		if(t->un != NULL && t->un->mino < num)
			go = t->un;
		else if(t->ce != NULL && t->ce->mino < num)
			go = t->ce;
		else
			return -1;
	}
	else
	{
		if(t->ce != NULL && t->ce->mino < num)
			go = t->ce;
		else if(t->un != NULL && t->un->mino < num)
			go = t->un;
		else
			return -1;
	}
	return ask2(s, ind + 1, num, go);
}
string tost(int n)
{
	string res = "";
	while(n > 0)
	{
		res += (n % 2) + '0';
		n /= 2;
	}
	while(res.size() < 22)
		res += '0';
	reverse(all(res));
	return res;
}
int xo[1000010];
int ros[tam];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("que.txt", "w", stdout);
	fore(i, 1, 1000010)
		xo[i] = xo[i - 1] ^ i;
	int n, m;
	cin>>n>>m;
	fore(i, 0, n) cin>>ar[i];
	int a, b;
	vector<pair<pair<int, int>, int>> que;
	ptrie t1 = 0, t2 = 0;
	int ras;
	string s1, s2;
	int x, y, x1, y1;
	fore(i, 0, m)
	{
		cin>>a>>b;
		a--;
		b--;
		if(b - a < sq)
		{
			del(t1);
			del(t2);
			t1 = new trie();
			t2 = new trie();
			ras = 0;
			// cout<<a<<' '<<b<<'\n';
			fore(i, a, b + 1)
			{
				x = ar[i] - 1;
				y = ar[i];
				s1 = tost(xo[x]);
				s2 = tost(xo[y]);
				add(s1, 0, x, t2, xo[x]);
				add(s2, 0, y, t1, xo[y]);
				x1 = ask1(s1, 0, x, t1);
				y1 = ask2(s2, 0, y, t2);
				// cout<<i<<" -> "<<x<<','<<xo[x]<<' '<<y<<','<<xo[y]<<' '<<x1<<' '<<y1<<'\n';;
				ras = max(ras, max(xo[x] ^ ask1(s1, 0, x, t1), xo[y] ^ ask2(s2, 0, y, t2)));
			}
			// cout<<ras<<'\n';
			res[i] = ras;
		}
		else
			que.pb({{a, b}, i});
	}
	sort(all(que), comp);
	int level = 0;
	int nu = sq;
	while(nu <= n)
	{
		for(int i = nu - 1; i > nu - sq - 1; i--)
		{
			ros[i] = ros[i + 1];
			for(int j = i; j < nu; j++)
				ros[i] = max(ros[i], ar[i] > ar[j] ? xo[ar[i]] ^ xo[ar[j] - 1] : xo[ar[i] - 1] ^ xo[ar[j]]);
		}
		nu += sq;
	}
	int divo = -1, lasto = -1, rus;
	fore(i, 0, que.size())
	{
		// cout<<i<<'\n';
		if(que[i].f.f / sq != divo)
		{
			divo = que[i].f.f / sq;
			lasto = que[i].f.f / sq * sq + sq;
			del(t1);
			del(t2);
			t1 = new trie();
			t2 = new trie();
			ras = 0;
		}
		while(que[i].f.s >= lasto)
		{
			x = ar[lasto] - 1;
			y = ar[lasto];
			s1 = tost(xo[x]);
			s2 = tost(xo[y]);
			add(s1, 0, x, t2, xo[x]);
			add(s2, 0, y, t1, xo[y]);
			ras = max(ras, max(xo[x] ^ ask1(s1, 0, x, t1), xo[y] ^ ask2(s2, 0, y, t2)));
			lasto++;
		}
		// cout<<i<<'\n';
		rus = ros[que[i].f.f];
		fore(j, que[i].f.f, que[i].f.f / sq * sq + sq)
		{
			// cout<<j<<'\n';
			x = ar[j] - 1;
			y = ar[j];
			s1 = tost(xo[x]);
			s2 = tost(xo[y]);
			rus = max(rus, max(xo[x] ^ ask1(s1, 0, x, t1), xo[y] ^ ask2(s2, 0, y, t2)));
		}
		// cout<<i<<'\n';
		res[que[i].s] = max(rus, ras);
	}
	fore(i, 0, m) cout<<res[i]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	