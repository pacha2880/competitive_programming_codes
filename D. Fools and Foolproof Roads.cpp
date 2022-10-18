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
#define forg(i, b, e, m)	for(ll i = b; i < e; i+=m)
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
int parent[100010], tot[100010];
pair<int, int> po[100010];
int find(int n)
{
	if(parent[n] == -1)
		return n;
	return parent[n] = find(parent[n]);
}
bool visited[100010];
pair<int, pair<int, int>> ar[100010];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int n, m, p, q;
	cin>>n>>m>>p>>q;
	int a, b, c;
	mem(parent, -1);
	fore(i, 0, m)
	{
		cin>>ar[i].s.f>>ar[i].s.s>>ar[i].f;
		ar[i].s.f--;
		ar[i].s.s--;
	}
	fore(i, 0, n)
	{
		po[i] = {i, -1};
	}
	sort(ar, ar + m);
	//cout<<"chispas\n";
	fore(i, 0, m)
	{
		a = find(ar[i].s.f);
		b = find(ar[i].s.s);
		if(a != b)
		{
			parent[a] = b;
			po[b].s = a;
			//cout<<a + 1<<' '<<b + 1 << ' ' << ar[i].f<<'\n';
			tot[b] = min((ll)1e9, 1ll * tot[a] + tot[b] + ar[i].f);
			//cout<<tot[b]<<'\n';
		}
		else
			tot[b] = min((ll)1e9, 1ll * tot[b] + ar[i].f);
	}
	pair<int, pair<int, int>> cat, cat1;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> que;
	fore(i, 0, n)
	{
		a = find(i);
		if(!visited[a])
		{
			//cout<<"cacho "<<a + 1<<' '<<tot[a]<<'\n';
			visited[a] = 1;
			que.push({tot[a], {a, po[a].s}});
		}
	}
	if(que.size() < q)
		cout<<"NO\n";
	else if(que.size() == q)
	{
		if(p > 0)
		{
			while(!que.empty())
			{
				cat = que.top();
				if(cat.s.s != -1)
				{
					cout<<"YES\n";
					fore(i, 0, p)
						cout<<cat.s.f + 1<<' '<<cat.s.s + 1<<'\n';
					return 0;
				}
				que.pop();
			}
			cout<<"NO\n";
		}
		else
			cout<<"YES\n";
	}
	else if((int)que.size() - p > q)
	{
		cout<<"NO\n";
		//cout<<"chancleta"<<que.size()<<'\n';
	}
	else
	{
		cout<<"YES\n";
		fore(i, 0, p)
		{
			if(que.size() == q)
			{
				while(!que.empty())
				{
					cat = que.top();
					if(cat.s.s != -1)
					{
						fore(j, i, p)
							cout<<cat.s.f + 1<<' '<<cat.s.s + 1<<'\n';
						return 0;
					}
					que.pop();
				}
			}
			else
			{
				cat = que.top();
				que.pop();
				cat1 = que.top();
				que.pop();
				cout<<cat.s.f + 1<<' '<<cat1.s.f + 1<<'\n';
				que.push({min((ll)1e9, 2ll * cat.f + 2ll * cat1.f + 1), {cat.s.f, cat1.s.f}});
			}
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	