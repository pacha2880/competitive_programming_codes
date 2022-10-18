#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)	for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)	for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
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
const int tam = 1010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int cols[tam][3];
int si[tam];
vii res;
int n, lib;
pair<int, int> col[tam][3];
int us[tam];
int bob[5][3] = {{1, 2, 3}, {1, 1, 1}, {1, 1, 2}, {1, 1, 3}, {1, 2, 2}};
bool bad()
{
	mem(us, 0);
	bool res = false;
	fore(i, 0, n + 1)
	{
		if(si[i])
		{
			if((cols[i][0] != cols[i][1] || cols[i][1] != cols[i][2]))
				res = true;
			fore(j, 0, 3)
				col[cols[i][j]][us[cols[i][j]]++] = {3 - j, i};
		}
		else
			lib = i;
	}
	return res;
}
void mov(int i, int j)
{
	res.pb({i, j});
	cols[j][si[j]++] = cols[i][si[i] - 1];
	si[i]--;

}
void loc()
{
	fore(i, 0, n + 1)
	{
		if(si[i] == 0)
			lib = i;
	}
	fore(j, 0, 3) 
		mov(n, lib);
}
void dale(int co, int wae)
{
	int a, b, c;
	a = col[co][0].s;
	b = col[co][1].s;
	c = col[co][2].s;
	if(wae == 0)
	{
		if(b == c)
		{
			mov(b, lib);
			mov(a, b);
			mov(lib, a);
		}
		else if(a == c)
		{
			mov(b, lib);
			mov(a, b);
			mov(a, lib);
			mov(b, a);
			mov(b, a);
			mov(b, lib);
		}
		else if(a == b)
		{
			mov(c, lib);
			mov(c, lib);
			mov(a, c);
			mov(a, c);
			mov(a, lib);
		}
		else
		{
			mov(c, lib);
			mov(c, lib);
			mov(b, lib);
			mov(a, c);
			mov(b, c);
			mov(b, a);
		}
	}
	else if(wae == 1)
	{
		mov(a, lib);
		mov(b, lib);
		mov(c, lib);
		mov(a, b);
		mov(a, c);
	}
	else if(wae == 2)
	{
		if(b == c)
			swap(a, b);
		if(a == c)
		{
			mov(a, lib);
			mov(a, lib);
			mov(b, lib);
			mov(a, b);
		}
		else
		{
			mov(a, lib);
			mov(b, lib);
			mov(c, a);
			mov(c, lib);
			mov(c, b);
		}
	}
	else if(wae == 3)
	{
		if(b == c)
			swap(a, b);
		if(a == c)
		{
			mov(a, lib);
			mov(a, lib);
			mov(b, a);
			mov(lib, b);
			mov(lib, a);
		}
		else
		{
			mov(c, lib);
			mov(c, lib);
			mov(a, c);
			mov(b, c);
			mov(lib, a);
			mov(lib, b);
		}
	}
	else if(wae == 4)
	{
		if(a == c)
			swap(b, c);
		if(a == b)
		{
			mov(a, lib);
			mov(a, lib);
			mov(c, a);
			mov(c, lib);
			mov(c, a);
		}
		else
		{
			mov(a, lib);
			mov(b, a);
			mov(b, lib);
			mov(c, b);
			mov(c, lib);
			mov(c, b);
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int a;
	cin>>n;
	fore(i, 0, 3) 
	fore(j, 0, n) {
		// cout<<i<<' '<<j<<'\n';
		si[j]++;
		cin>>cols[j][2 - i];
		cols[j][2 - i]--;
		// cout<<"shu\n";
	}
	lib = n;
	bool bo;
	int co = 0;
	while(bad())
	{
		fore(i, 0, n)
		{
			sort(col[i], col[i] + 3);
			fore(j, 0, 5)
			{
				bo = true;
				fore(k, 0, 3)
					bo &= col[i][k].f == bob[j][k];
				if(bo)
				{
					if(j != 0 || col[i][0].s != col[i][1].s || col[i][1].s != col[i][2].s)
					{
						dale(i, j);
						j = 5;
						i = n;
					}
				}
			}
		}
		co++;
		if(co == 6 * n) break;
	}
	if(si[n])
		loc();
	// assert(res.size() <= 6 * n);
	cout<<res.size()<<'\n';
	for(auto cat : res)
		cout<<cat.f + 1<<' '<<cat.s + 1<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	