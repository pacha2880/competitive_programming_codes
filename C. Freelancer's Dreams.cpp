#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define mp              make_pair
#define pb              push_back
#define all(a)          (a).begin(), (a).end()
#define sz(a)           (int)a.size()
#define eq(a, b)        (fabs(a - b) < EPS)
#define md(a, b)        ((a) % b + b) % b
#define mod(a)          md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)          sort(all(a))
#define mem(a, h)       memset(a, (h), sizeof(a))
#define f               first
#define s               second
#define forn(i, n)          for(int i = 0; i < n; i++)
#define fore(i, b, e)   for(int i = b; i < e; i++)
#define forg(i, b, e, m)    for(int i = b; i < e; i+=m)
#define index   int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

typedef long long       ll;
typedef long double ld; 
typedef unsigned long long      ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
vector<int> X,Y;
vector<vector<double> > A;
vector<double> b,c;
double z;
int n,m;
void pivot(int x, int y){
    swap(X[y],Y[x]);
    b[x]/=A[x][y];
    fore(i,0,m)if(i!=y)A[x][i]/=A[x][y];
    A[x][y]=1/A[x][y];
    fore(i,0,n)if(i!=x&&abs(A[i][y])>EPS){
        b[i]-=A[i][y]*b[x];
        fore(j,0,m)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
        A[i][y]=-A[i][y]*A[x][y];
    }
    z+=c[y]*b[x];
    fore(i,0,m)if(i!=y)c[i]-=c[y]*A[x][i];
    c[y]=-c[y]*A[x][y];
}
pair<double,vector<double>> simplex( //maximize c^T x s.t. Ax <= b, x>=0
                    vector<vector<double>> _A, vector<double> _b, vector<double> _c){
    // returns pair (maximum value, solution vector)
    A=_A;b=_b;c=_c;
    n=b.size();m=c.size();z=0;
    X=vector<int>(m);Y=vector<int>(n);
    fore(i,0,m)X[i]=i;
    fore(i,0,n)Y[i]=i+m;
    while(1){
        int x=-1,y=-1;
        double mn = -EPS;
        fore(i,0,n)if(b[i]<mn)mn=b[i],x=i;
        if(x<0)break;
        fore(i,0,m)if(A[x][i]<-EPS){y=i;break;}
        assert(y>=0); // no solution to Ax<=b
        pivot(x, y);
    }
    while(1){
        double mx=EPS;
        int x=-1,y=-1;
        fore(i,0,m)if(c[i]>mx)mx=c[i],y=i;
        if(y<0)break;
        double mn=1e200;
        fore(i,0,n)if(A[i][y]>EPS&&b[i]/A[i][y]<mn)mn=b[i]/A[i][y],x=i;
        assert(x>=0); // c^T x is unbounded
        pivot(x,y);        
    }
    vector<double> r(m);
    fore(i,0,n)if(Y[i]<m)r[Y[i]]=b[i];
    return mp(z,r);
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("asd.txt", "r", stdin);
    // freopen("qwe.txt", "w", stdout);
    int n;
    double p, q, a, b;
    cin>>n>>p>>q;
    vector<vector<double>> A(2, vector<double>(n));
    vector<double> B = {-p, -q}, c(n);
    fore(i, 0, n)
    {
        cin>>a>>b;
        A[0][i] = -a;
        A[1][i] = -b;
        c[i] = -1;
    }
    cout<<fixed<<setprecision(6)<<-simplex(A, B, c).f<<'\n';
    return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
