// https://codeforces.com/contest/1912/problem/J
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
typedef vector<vector<ll> > Matrix;
Matrix ones(int n) {
  Matrix r(n,vector<ll>(n));
  fore(i,0,n)r[i][i]=1;
  return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
  int n=sz(a),m=sz(b[0]),z=sz(a[0]);
  Matrix r(n,vector<ll>(m));
  fore(i,0,n)fore(j,0,m)fore(k,0,z)
  {
    r[i][j]+=a[i][k]*b[k][j];//,r[i][j]%=mod;
  }
  return r;
}
Matrix be(Matrix b, ll e) {
  Matrix r=ones(sz(b));
  while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
  return r;
}

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    int t;
    cin>>t;
    while(t--)
    {
        int t, s;
        cin>>t>>s;
        vi ar(s);
        fore(i, 0, s) cin>>ar[i];
        if(t == 0)
            cout<<1<<'\n';
        else if(s == 1)
        {
            cout<<(t % ar[0] == 0)<<'\n';
        }
        else if(s == 2)
        {
            int ma = *max_element(all(ar));
            Matrix mat(2 * ma, vi(2 * ma));
            fore(i, 0, ma - 1)
                mat[i * 2 + 2][i * 2] = mat[i * 2 + 3][i * 2 + 1] = 1;
            // fore(j, ar[0] - 1, ma)
            //     mat[j * 2][(j - ar[0] + 1) * 2]++;
            // fore(j, ar[1] - 1, ma)
            //     mat[j * 2 + 1][(j - ar[1] + 1) * 2]++, mat[j * 2 + 1][(j - ar[1] + 1) * 2 + 1]++;
            fore(i, 0, ma * 2)
            {
                fore(j, 0, ma * 2)
                    cout<<mat[i][j];
                cout<<'\n';
            }
            cout<<be(mat, t)[0][0]<<'\n';   
        }
        else
        {
            int ma = *max_element(all(ar));
            Matrix mat(3 * (ma + 1), vi(3 * (ma + 1)));
            fore(i, 0, ma)
                mat[i * 3 + 3][i * 3] = mat[i * 3 + 4][i * 3 + 1] = mat[i * 3 + 5][i * 3 + 2] = 1;
            mat[3 * ma - 3 * ar[0]][3 * ma] = 1;
            mat[3 * ma - 3 * ar[1]][3 * ma + 1] = mat[3 * ma + 1 - 3 * ar[1]][3 * ma + 1] = 1;
            mat[3 * ma - 3 * ar[2]][3 * ma + 2] = mat[3 * ma + 1 - 3 * ar[2]][3 * ma + 2] = 
                                            mat[3 * ma + 2 - 3 * ar[2]][3 * ma + 2] = 1;
            fore(i, 0, (ma + 1) * 3)
            {
                fore(j, 0, (ma + 1) * 3)
                    cout<<mat[i][j]<<' ';
                cout<<'\n';
            }
            auto cat = be(mat, 2);
            cout<<'\n';
            fore(i, 0, (ma + 1) * 3)
            {
                fore(j, 0, (ma + 1) * 3)
                    cout<<cat[i][j]<<' ';
                cout<<'\n';
            }
            cout<<cat[0][0] + cat[0][1] + cat[0][2]<<'\n';
        }
    }
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad
// Take a sad song and make it better
