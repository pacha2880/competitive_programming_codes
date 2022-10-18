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
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<pair<int, int>> ar;
int er[100], ax[100];
int n;
void produce()
{
	int fro = 0, la = -1, bo = 0;
	ar.clear();
	fore(i, 0, n)
	{
		if(!bo)
		{
			bo = 1;
			la = er[i];
		}
		else
		{
			if(er[i - 1] != er[i] - 1)
			{
				ar.pb({er[fro], er[i - 1]});
				fro = i;
			}
		}
	}
	ar.pb({er[fro], er[n - 1]});
}
void make(vector<int> ras)
{
	int ind = n - 1, und = 0;
	//cout<<"el ras "<<ras.size()<<'\n';
	for(int am : ras)
	{
		//cout<<am<<','<<ind<<' ';
		fore(i, und, und + am)
		{
			//cout<<'*'<<ind - am + i + 1<<'*';
			ax[ind - am + i - und + 1] = er[i];
		}
		ind -= am;
		und += am;
	}
	//cout<<'\n';
	fore(i, 0, n) er[i] = ax[i];
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n;
	fore(i, 0, n)
		cin>>er[i];
	produce();
	int ind;
	vector<int> ras;
	int cuan, cuen, cuin;
	vector<vector<int>> res;
	while(ar.size() > 2)
	{
		//cout<<ar.size()<<'\n';
		ras.clear();
		cuan = 0;
		if(ar[0].f == 1)
		{
			ind = 2;
			cuin = ar[0].s - ar[0].f + 1;
			cuan = ar[1].s - ar[1].f + 1;
			while(ar[ind].s != ar[1].f - 1)
			{
				cuan += ar[ind].s - ar[ind].f + 1;
				ind++;
			}
			cuen = ar[ind].s - ar[ind].f + 1;
			ras.pb(cuin);
			ras.pb(cuan);
			ras.pb(cuen);
			if(ind < ar.size() - 1)
				ras.pb(n - cuan - cuen - cuin);
		}
		else
		{
			ind = 1;
			cuan = ar[0].s - ar[0].f + 1;
			//cout<<"miar\n";
			//fore(i, 0, ar.size()) cout<<ar[i].f<<' '<<ar[i].s<<'\n';
			while(ar[ind].s != ar[0].f - 1)
			{
				cuan += ar[ind].s - ar[ind].f + 1;
				ind++;
			}
			cuen = ar[ind].s - ar[ind].f + 1;
			ras.pb(cuan);
			ras.pb(cuen);
			if(ind < ar.size() - 1)
				ras.pb(n - cuan - cuen);
		}
		make(ras);
		/*fore(i, 0, n)
		cout<<er[i]<<' ';
		cout<<'\n';*/
		produce();
		res.pb(ras);
		
	}
	if(ar.size() == 2)
	{
		ras.clear();
		ras.pb(ar[0].s - ar[0].f + 1);
		ras.pb(ar[1].s - ar[1].f + 1);
		res.pb(ras);
	}
	cout<<res.size()<<'\n';
	fore(i, 0, res.size())
	{
		cout<<res[i].size();
		fore(j, 0, res[i].size())
			cout<<' '<<res[i][j];
		cout<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	