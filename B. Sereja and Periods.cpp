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
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int va, vb;
	string a, b;
	cin>>va>>vb;
	cin>>a>>b;
	int n = a.size(), m = b.size();
	int ina = 0, inb = 0, cana = 0, canb = 0;
	do
	{
		if(cana == 100000)
		{
			cana = 0, canb = 0;
			break;
		}
		if(a[ina] == b[inb])
		{
			inb++;
			if(inb == m)
				canb++, inb = 0;
		}
		ina++;
		if(ina == n)
			cana++, ina = 0;
	}
	while(ina != 0 || inb != 0);
	//cout<<cana<<' '<<canb<<'\n';
	int un = 0, dos = 0, modi = 0, madi = va;
	if(cana > 0 )
	 un = va / cana, dos = canb * un / vb, modi = un % vb, madi = va % cana;
	inb = 0;
	int ala = 0;
	fore(i, 0, madi)
	{
		fore(i, 0, n)
		{
			if(a[i] == b[inb])
			{
				inb++;
				if(inb == m)
				{
					ala++;
					inb = 0;
				}
			}
		}
	}
	cout<<dos + ala / vb<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2