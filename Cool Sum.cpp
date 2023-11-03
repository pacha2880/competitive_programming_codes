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

#pragma GCC optimization ("O2")
// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = (1<<18) + 1;
const int MOD1 = 1000000007;
const int MOD = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 
// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
// MAXN must be power of 2 !!
// MOD-1 needs to be a multiple of MAXN !!
// big mod and primitive root for NTT:
int pot(int b, int e)
{
  int res = 1;
  while(e)
  {
    if(e & 1) res = res * b % MOD;
    b = b * b % MOD;
    e /= 2;
  }
  return res;
}
const int MAXN = 1<<20;
typedef ll tf;
tf addmod(tf a, tf b){tf r=a+b;if(r>=MOD)r-=MOD;return r;}
tf submod(tf a, tf b){tf r=a-b;if(r<0)r+=MOD;return r;}
tf mulmod(ll a, ll b){return a*b%MOD;}
tf inv(tf a){return pot(a,MOD-2);}
typedef vector<tf> poly;
const tf  RT=3;
// const tf MOD=2305843009255636993,RT=5;
// FFT
// struct CD {
// 	double r,i;
// 	CD(double r=0, double i=0):r(r),i(i){}
// 	double real()const{return r;}
// 	void operator/=(const int c){r/=c, i/=c;}
// };
// CD operator*(const CD& a, const CD& b){
// 	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
// CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
// CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
// const double pi=acos(-1.0);
// NTT

struct CD {
	tf x;
	CD(tf x):x(x){}
	CD(){}
};
CD operator*(const CD& a, const CD& b){return CD(mulmod(a.x,b.x));}
CD operator+(const CD& a, const CD& b){return CD(addmod(a.x,b.x));}
CD operator-(const CD& a, const CD& b){return CD(submod(a.x,b.x));}
vector<tf> rts(MAXN+9,-1);
CD root(int n, bool inv){
	tf r=rts[n]<0?rts[n]=pot(RT,(MOD-1)/n):rts[n];
	return CD(inv?pot(r,MOD-2):r);
}

CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		// double z=2*pi/m*(inv?-1:1); // FFT
		// CD wi=CD(cos(z),sin(z)); // FFT
		CD wi=root(m,inv); // NTT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	// if(inv)fore(i,0,n)a[i]/=n; // FFT
	if(inv){ // NTT
		CD z(pot(n,MOD-2)); // pot: modular exponentiation
		fore(i,0,n)a[i]=a[i]*z;
	}
}
poly multiply(poly& p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	// fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	fore(i,0,n)res.pb(cp1[i].x); // NTT
	return res;
}
vi fac(tam), facin(tam);
int bino(int n, int k) {
    return fac[n] * facin[k] % MOD * facin[n - k] % MOD;
};
void precalbino() {
    fac[0] = 1;
    fore(i, 1, tam)
        fac[i] = fac[i - 1] * i % MOD;
    facin[tam - 1] = pot(fac[tam - 1], MOD - 2);
    for(int i = tam - 2; i >= 0; i--)
        facin[i] = facin[i + 1] * (i + 1) % MOD;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int k, n;
    cin>>k>>n;
    int len = 1<<k;
    auto poto = [&](vi a, int b)
    {
        vi res({1});
        while(b)
        {
            if(b & 1)
            {
                res = multiply(res, a);
                fore(i, len, sz(res))
                    res[i - len] = addmod(res[i - len], res[i]);
                res.resize(len);
            }
            a = multiply(a, a);
            fore(i, len, sz(a))
                a[i - len] = addmod(a[i - len], a[i]);
            a.resize(len);
            b /= 2;
        }
        return res;
    };
    vi res;
    if(n < (1<<12))
        res = poto({1, 1}, n);
    else
    {
        precalbino();
        vi res2(len);
        fore(i, 0, n / (1<<12) + 1)
            res2[i % len] = addmod(res2[i % len], bino(n / (1<<12), i));
        fore(i, 0, 12)
        {
            res2 = multiply(res2, res2);
            fore(i, len, sz(res2))
                res2[i - len] = addmod(res2[i - len], res2[i]);
            res2.resize(len);
        }
        vi res1 = poto({1, 1}, n % (1<<12));
        res = multiply(res1, res2);
        fore(i, len, sz(res))
            res[i - len] = addmod(res[i - len], res[i]);
        res.resize(len);
    }
    while(sz(res) < len)
        res.pb(0);
    fore(i, 0, len)
        cout<<res[i]<<' ';
    cout<<'\n';
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
// Take a sad song and make it better
