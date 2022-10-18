#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1e9+7;
 
#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define bt(i) (1LL<<(i))
 
#define debug(x) cerr<<#x<<" = "<<(x)<<"\n"
#define hoise cerr<<"hoise\n"
#define tham getchar()
 
mt19937 rng((unsigned int) chrono::system_clock::now().time_since_epoch().count());
 
inline ll MOD(ll x, ll m = mod){
    if(x < m && x >= 0) return x;
    ll y = x % m;
    return (y < 0)? y+m: y;
}
 
const int nmax = 1e3+5;
///====================== template =========================
 
///utility function for modular addition
inline ll add(ll x, ll y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
 
///utility function for modular multiplication
inline ll mult(ll x, ll y){
    x *= y;
    if(x >= mod) x%= mod;
    return x;
}
 
///An algebraic extended number system, where w^3 = 1
///A number is a+bw, a and b are in modular field
///multiplication rule is special w*w = - w - 1 (as w^2 + w + 1 = 0)
struct extNum{
    ll a, b;
    extNum(ll _a = 0, ll _b = 0){
        a = _a, b = _b;
    }
    extNum operator+(extNum x){
        return extNum(add(a, x.a), add(b, x.b));
    }
    extNum operator*(ll k){
        return extNum(mult(a, k), mult(b, k));
    }
    extNum operator*(extNum x){
        ll na = MOD(a*x.a - b*x.b);
        ll nb = MOD(a*x.b + b*x.a - b*x.b);
        return extNum(na, nb);
    }
    void print(){
        cout<<a<<" + w"<<b<<"\n";
    }
}w(0, 1), w2(mod-1, mod-1);     ///these are w and w^2 respectively
 
 
///Convolution code, Given a list of count of numbers in base 3
///converts them into a point value form like ordinary fwht, except
///unlike fwht, the values used are 1, w, w^2
///Takes time O(n log_3(n))
typedef vector<extNum> poly;
void FWHT(poly &coefs, poly &vals, bool invert = false) {
	vals = coefs;
	int n = vals.size();
    for (int len = 1; len < n; len *= 3) {
        int pitch = len*3;
        int len2 = len*2;
        for (int i = 0; i < n; i += pitch) {
            for (int j = 0; j < len; j++) {
                extNum a = vals[i + j];
                extNum b = vals[i + j + len];
                extNum c = vals[i + j + len2];
                vals[i+j] = a + b + c;
                vals[i+j+len] = a + b*w + c*w2;
                vals[i+j+len2] = a + b*w2 + c*w;
                if(invert) swap(vals[i+j+len], vals[i+j+len2]);
            }
        }
    }
 
    ll inv3 = (mod+1)/3, inv = 1;
    for(int i = 1; i<n; i*= 3)
        inv = (inv3*inv) % mod;
    if (invert)
        for (int i = 0; i < n; i++) vals[i] = vals[i]*inv;
    return;
}
 
///Performing the convolution and multiplication is done
///via divide and conquer, kind of like binary exponentiating
extNum expo(extNum x, ll n){
	extNum ret(1);
    while(n){
        if(n & 1LL) ret = (ret*x);
        x = (x*x);
        n >>= 1;
    }
    return ret;
}
 
///Sieve to calculate primes upto 10^3 = cube_root(10^9)
vector<int> primes;
bool composite[nmax];
int sieve(){
    for(int i = 2; i<nmax; i++){
        if(composite[i]) continue;
        primes.push_back(i);
        for(int j = i+i; j<nmax; j+=i) composite[j] = true;
    }
    return primes.size();
}
 
///exponentiating in mod
ll modexpo(ll x, ll n, ll m = mod){
	if(n == 0) return (m == 1)? 0: 1;
	ll y = modexpo(x*x % m, n >> 1, m);
	return (n&1)? y*x % m: y;
}
 
///Rabin_miller to quickly check if a number is prime
///SPRP is a proven list of witnesses that can check prime for
///number upto 1e18
ll SPRP[7] = {2LL, 325LL, 9375LL, 28178LL, 450775LL, 9780504LL, 1795265022LL};
bool RabinMiller(ll p, int t = 7)		//t = 7 for SPRP base
{
    if(p < 4) return (p > 1);
    if(!(p & 1LL)) return false;
    ll x = p - 1;
    int e = __builtin_ctzll(x);
    x >>= e;
    while(t--)
    {
        //ll witness = (rng() % (p-3)) + 2;	//Using random witness
        ll witness = SPRP[t];
        witness = modexpo(witness%p, x, p);
        if(witness <= 1) continue;
        for(int i = 0; i<e && witness != p-1; i++)
            witness = (witness * witness) % p;
        if(witness != p-1) return false;
    }
    return true;
}
 
///check if a number is square, works for number upto 1e9
bool isSquare(ll x){
    ll r = sqrtl(x);
    for(ll i = r-3; i<=r+3; i++)
        if(i*i == x) return true;
    return false;
}
 
///Computes tau(n) = count of divisors of a number, in O(max^(1/3))
///We try to divide by primes till max^(1/3)
///After that only p, p^2, pq or 1 remain
///these are checked by isSquare and Rabin_miller
///We don't need the primes p or q, just their exponent is enough
int SpecialTau(int n){
    int ret = 1;
    for(int i = 0; i<primes.size(); i++){
        int freq = 0;
        while(n % primes[i] == 0) freq++, n/= primes[i];
        ret *= (freq+1);
    }
    if(n == 1) return ret;
    else if(isSquare(n)) return 3*ret;
    else if(RabinMiller(n)) return 2*ret;
    else return 4*ret;
}
 
///converts the binary representation of x to ternary
///5 (101 in binary) is transformed to 10 (101 in ternary)
int tobase3(int x){
    int ret = 0;
    for(int i = 10; i>=0; i--){
        ret*= 3;
        if(bt(i)&x) ret += 1;
    }
    return ret;
}
 
int MAX = 177147; ///3^11, since maximum divisor count is 1344, which has 11 bits
 
///FIRST PART OF THE SOLUTION:
///Take the numbers, compute their count of divisors - 1
///As this is the equivalent nim-stack for these numbers
///Then they are converted to base3, for the next step of
///solution
void first(int n, int k, poly &p){
    set<int> st;
    for(int i = 0; i<n; i++){
        int x;
        cin>>x;
        assert(1 <= x && x <= 1000000000);
        st.insert(x);
        x = SpecialTau(x)-1;
        x = tobase3(x);
        p[x].a += 1;
    }
    assert(st.size() == n);
}
 
 
///SECOND PART OF THE SOLUTION:
///A assignment of values (in nim equivalent stone count) is winning
///if we convert the binary representations to base-3 and 3-xor of them
///is non-zero, So we need to perform fwht convolution K times.
///That is done via modified fwht and divide and conquer
void second(int n, int k, poly &p){
    FWHT(p, p);
    for(int i = 0; i<MAX; i++)
        p[i] = expo(p[i], k);
    FWHT(p, p, true);
    ll ans = 0;
    for(int i = 1; i<MAX; i++)
        ans = add(ans, p[i].a);
    cout<<ans<<"\n";
}
 
#define time__(f, s) \
    {clock_t CLK = clock(); \
    f;  \
    fprintf(stderr, #s " %.3f\n", (double)(clock() - CLK) / CLOCKS_PER_SEC);}
void solve(){
    sieve();
 
    int tc;
    cin>>tc;
    assert(1 <= tc && tc <= 5);
    for(int i = 0; i<tc; i++){
        int n, k;
        poly p(MAX);
        cin>>n>>k;
        assert(1 <= n && n <= 100000);
        assert(1 <= k && k <= 1000000000);
        first(n, k, p);
        second(n, k, p);
    }
    //time__(first(n, k, p), first step:);
    //time__(second(n, k, p), second step:);
}
 
int main(){
    FASTIO;
    solve();
    //time__(solve(), time:);
}