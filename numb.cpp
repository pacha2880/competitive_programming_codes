#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
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
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
// sort(all(v), [](int a, int b){ return a > b; });


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

int cantDiv(int n)
{
	int res = 0;
	for(int i = 1; i <= n; i++)
		if(n % i == 0)
			res++;
	return res;
}

int cantDivr(int n)
{
	int res = 0;
	for(int i = 1; i * i <= n; i++)
		if(n % i == 0)
		{
			res += 2;
			if(i * i == n)
				res--;
		}
	return res;
}

int sumaDivr(int n)
{
	int res = 0;
	for(int i = 1; i * i <= n; i++)
		if(n % i == 0)
		{
			res += i + n / i;
			if(i * i == n)
				res -= i;
		}
	return res;
}

bool primo(int n)
{
	return cantDiv(n) == 2;
}

bool primor(int n)
{
	return cantDivr(n) == 2;
}
const int tam = 10000010;
bool pri[tam];
vector<int> primos;
void criba()
{
	for(int i = 2; i < tam; i++)
		pri[i] = true;
	for(int i = 2; i < tam; i++)
	{
		if(pri[i])
		{
			for(int j = i + i; j < tam; j += i)
				pri[j] = false;
			primos.push_back(i);
		}
	}
}
vector<int> facts(int n)
{
	vector<int> res;
	for(int i = 2; i * i <= n; i++)
	{
		if(n % i == 0)
		{
			res.push_back(i);
			while(n % i == 0)
				n /= i;
		}
	}
	if(n > 1) res.push_back(n);
	return res;
}

map<int, int> factsexp(int n)
{
	map<int, int> res;
	for(int i = 2; i * i <= n; i++)
	{
		while(n % i == 0)
			n /= i, res[i]++;
	}
	if(n > 1) res[n]++;
	return res;
}

map<int, int> factsexp1(int n)
{
	map<int, int> res;
	for(int i = 0; primos[i] * primos[i] <= n; i++)
	{
		while(n % primos[i] == 0)
		{
			n /= primos[i], res[primos[i]]++;
		}
	}
	if(n > 1) res[n]++;
	return res;
}
int cantDiv1(int n)
{
	int res = 1;
	for(ii hola : factsexp1(n))
		res *= hola.s + 1;
	return res;
}
int pot(int base, int exp)
{
	int res = 1;
	for(int i = 0 ; i < exp; i++)
		res *= base;
	return res;
}
int sumaDiv1(int n)
{
	int res = 1;
	for(ii par : factsexp1(n))
	{
		res *= (pot(par.f, par.s + 1) - 1) / (par.f - 1);
	}
	return res;
}
int main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
	int n, a;
	criba();
	cout<<primos.size()<<'\n';
	cin>>n;
	while(n--)
	{
		cin>>a;
		if(pri[a])
			cout<<"Yes\n";
		else
			cout<<"No\n";
		map<int, int> fa = factsexp1(a);
		for(auto pa : fa)
			cout<<pa.first<<','<<pa.second<<' ';
		cout<<'\n';
		cout<<"cantDiv "<<cantDiv1(a)<<'\n';
		cout<<"sumaDiv "<<sumaDiv1(a)<<'\n';
	}
	return 0;
}

// se vuelve más fácil
// cada día es un poco más fácil, pero tienes que hacerlo cada día
// es la parte difícil, pero se vuelve más fácil
