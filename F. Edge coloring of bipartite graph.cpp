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
const ld PI = acosl(-1); 
int go[2000][1000];
vector<short> g[2000];
int edge[2000][2000];
pair<short, short> ar[tam];
int res[100000];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int x, y, m, a, b;
	cin>>x>>y>>m;
	int n = x + y;
	fore(i, 0, m)
	{
		cin>>a>>b;
		a--;
		b += x - 1;
		ar[i] = {a, b};
		g[a].pb(b);
		g[b].pb(a);
		edge[a][b] = i;
		edge[b][a] = i;
	}
	int gra = 0;
	mem(go, -1);
	fore(i, 0, n) gra = max(gra, (int)g[i].size());
	int dif1, dif2, sam, fro, to, co, toto;
	fore(i, 0, m)
	{
		sam = dif1 = dif2 = -1;
		a = ar[i].f, b = ar[i].s;
		fore(j, 0, gra)
		{
			if(go[a][j] == -1 && go[b][j] == -1)
			{
				sam = j;
				break;
			}
			if(dif1 == -1 && go[a][j] != -1 && go[b][j] == -1)
				dif1 = j;
			if(dif2 == -1 && go[a][j] == -1 && go[b][j] != -1)
				dif2 = j;
		}
		if(sam != -1)
		{
			res[i] = sam;
			go[a][res[i]] = b;
			go[b][res[i]] = a;
		}
		else
		{
			//cout<<"ruf "<<dif1<<' '<<dif2<<'\n';
			fro = b, to = a, co = dif1;
			int tua;
			bool bo;
			do
			{
				toto = go[to][co];
				go[to][co] = fro;
				go[fro][co] = to;
				res[edge[to][fro]] = co;
				if(co == dif2)
					co = dif1;
				else
					co = dif2;
				fro = to;
				to = toto;
			}
			while(go[to][co] != -1 && go[to][co] != fro);
			if(go[to][co] == -1)
			{
				int ca = co == dif2? dif1 : dif2;
				go[to][ca] = -1;	
			}
			go[to][co] = fro;
			go[fro][co] = to;
			res[edge[to][fro]] = co;
		}
		//cout<<"rai "<<i<<' '<<res[i]<<'\n';
	}
	cout<<gra<<'\n';
	fore(i, 0, m)
	{
		if(i > 0) cout<<' ';
		cout<<res[i] + 1;
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	