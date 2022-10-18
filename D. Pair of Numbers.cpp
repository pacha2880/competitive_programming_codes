#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
#define EPS			1e-9
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int tam = 1000010;
const int logTam = 21;

int logTable[tam];
int sparseTable[logTam][tam];
int A[tam], n; // a[] es el arreglo original. n es el tamaño del arreglo.

void makeSparseTable()
{
	logTable[0] = logTable[1] = 0;

	for (int i = 2; i <= n; i++)
	{
		logTable[i] = logTable[ i >> 1 ] + 1;
	}

	for (int i = 0; i < n; i++)
	{
		sparseTable[0][i] = A[i];
	}

	for (int k = 1; (1 << k) < n; k++)
	{
		for (int i = 0; i + (1 << k) <= n; i++)
		{
			int x = sparseTable[k-1][i];
			int y = sparseTable[k-1][i + (1 << (k-1))];
			sparseTable[k][i] = __gcd(x,y);
		}
	}
}

int queryST(int i, int j)
{
	int k = logTable[j - i];
	int x = sparseTable[k][i];
	int y = sparseTable[k][j - (1 << k) + 1];
	return __gcd(x,y);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int lo, hi, mid, res, l, r;
	cin>>n;
	ii ar[n];
	for(int i = 0; i < n; i++)
		cin>>A[i];
	makeSparseTable();
	for(int i = 0; i < n; i++)
	{
		lo = i, hi = n-1;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(queryST(i, mid) == A[i])
				res = mid, lo = mid + 1;
			else
				hi = mid - 1;
		}
		r = res;
		lo = 0, hi = i;
		while(lo <= hi)
		{
			mid = (lo + hi) / 2;
			if(queryST(mid, i) == A[i])
				res = mid, hi = mid - 1;
			else
				lo = mid + 1;
		}
		l = res;
		ar[i] = mp(r - l, l);
	}
	sort(ar, ar + n);
	int maxi = ar[n-1].f, con = 0;
	vi v;
	int prev = -1;
	for(int i = n-1; i > -1; i--)
	{
		if(ar[i].f != maxi) break;
		if(ar[i].s == prev) continue;
		prev = ar[i].s;
		con++;
		v.pb(ar[i].s + 1);
	}
	sort(all(v));
	cout<<con<<' '<<maxi<<endl;
	for(int i = 0; i < v.size(); i++)
	{
		if(i > 0) cout<<' ';
		cout<<v[i];
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS