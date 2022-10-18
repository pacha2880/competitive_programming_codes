#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD1			998244353
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
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
const int tam = 100010;
const int MOD = 1e9+7;
const double EPS = 1e-9;
struct Mat
{
	int mat[5][5];
	Mat() {mem(mat,0);}
	Mat(int let)
	{
		mem(mat, 0);
		fore(i, 0, 4)
			mat[i][i] = 1;
		mat[4][4] = 2;
		mat[4][let] = 1;
		mat[let][let] = 0;
		mat[let][4] = -1;
		/*cout<<'\n';
		fore(i, 0, 8)
		{
			fore(j, 0, 8)
				cout<<mat[i][j]<<' ';
			cout<<'\n';
		}*/
	}
};
Mat join(Mat a, Mat b)
{
	Mat res;
	fore(i, 0, 5)
	{
		fore(j, 0, 5)
		{
			ll val = 0;
			fore(k, 0, 5)
				val = (val + (ll)a.mat[i][k] * b.mat[k][j]) % MOD;
			res.mat[i][j] = val;
		}
	}
	return res;
}
int ar[500050]; Mat t[2000020];
void init(int b, int e, int node)
{
	if(b == e)
	{
		t[node] = Mat(ar[b]);
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	init(b, mid, l);
	init(mid + 1, e, r);
	t[node] = join(t[l], t[r]);
}
Mat query(int b, int e, int node, int i, int j)
{
	if(b >= i && e <= j)
	{
		return t[node];
	}
	int mid = ( b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(mid >= j)
		return query(b, mid, l, i, j);
	if(mid < i)
		return query(mid +1, e, r, i, j);
	return join(query(b, mid, l, i, j), query(mid + 1, e, r, i, j));
}
ll resu(Mat m)
{
	ll ar[] = {0,0,0,0,1}, resu[5];
	mem(resu, 0);
	fore(i, 0, 5)
	{
		//cout<<i<<'\n';
		fore(j, 0, 5)
		{
			resu[i] = (resu[i] + m.mat[j][i] * ar[j]) % MOD;
			//cout<<resu[i]<<' ';
		}
		//cout<<'\n';
	}
	//cout<<resu[4]<<' '<<resu[5]<<' '<<resu[6]<<' '<<resu[7]<<'\n';
	return (resu[4]-1 + MOD) % MOD;
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int conv[300];
	conv['A'] = 0;
	conv['C'] = 1;
	conv['G'] = 2;
	conv['T'] = 3;
	int n, q;
	scanf("%d %d", &n, &q);
	string s;
	char ch;
	
		scanf("%c", &ch);
	fore(i, 0, n)
	{
		scanf("%c", &ch);
		ar[i] = conv[ch]; 
	}
	init(0, n-1, 0);
	int a, b;
	int res;
	while(q--)
	{
		scanf("%d %d", &a, &b);
		res = (query(0, n-1, 0, a-1, b-1).mat[4][4] - 1 + MOD) % MOD;
		//cout<<(query(0, n-1, 0, a-1, b-1).mat[4][4] - 1 + MOD) % MOD<<'\n';
		printf("%d\n", res);
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2