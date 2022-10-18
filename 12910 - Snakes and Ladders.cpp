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

//typedef long long 		;
typedef unsigned long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 10000;
const int MOD = 1e9+7;
const int MOD1 = 988244535;
const double EPS = 1e-9;
const double PI = acos(-1);

int gauss(vector<vector<double>> a, vector<double> &res)
{
	int n = a.size(), m = a[0].size()-1;
	vector<int> where(m, -1);
	for(int col = 0, row = 0; col < m && row < n; col++)
	{
		fore(i, row, n) 
		if(fabs(a[i][col]) > fabs(a[row][col]) + EPS)
			swap(a[i], a[row]);
		if(fabs(a[row][col]) < EPS)
			continue;
		where[col] = row;
		fore(i, 0, n)
		{
			if(i != row)
			{
				double red = a[i][col] / a[row][col];
				fore(j, col, m + 1)
					a[i][j] -= red * a[row][j];
			}
		}
		row++;
	}
	res.assign(m, 0);
	fore(i, 0, m)
		if(where[i] != -1)
			res[i] = a[where[i]][m] / a[where[i]][i];
	double sum;
	fore(i, 0, n)
	{
		sum = 0;
		fore(j, 0, m)
		sum += res[j] * a[i][j];
		if(fabs(sum - a[i][m]) > EPS)
			return 0;
	}

	fore(i, 0, m)
	if(where[i] == -1)
		return MOD;
	return 1;
}
int lim;
int fixed(int i)
{
	if(i >= lim)
		i = lim - i%lim - 2;
	return i;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int w, h, s;
	int connect[150];
	cout<<fixed<<setprecision(3);
	while(cin>>w)
	{
		fore(i, 0, 150)
		connect[i] = i;
		cin>>h>>s;
		lim = w * h;
		int a, b;
		while(s--)
		{
			cin>>a>>b;
			connect[a-1] = b-1;
		}
		vector<double> res, add;
		vector<vector<double>> mat;
		fore(i, 0, lim-1)
		{
			add.assign(lim+1, 0);
			add[lim] = 1;
			add[i] = 1;
			fore(j, 1, 7)
				add[connect[fixed(i+j)]] -= 1 / 6.0;
			mat.pb(add);
		}
		add.assign(lim+1, 0);
		add[lim-1] = 1;
		mat.pb(add);
		/*fore(i, 0, lim)
		{
			fore(j, 0, lim+1)
			cout<<mat[i][j]<<' ';
			cout<<'\n';
		}*/
		int re = gauss(mat, res);
		assert(re == 1);
		cout<<res[0]<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2