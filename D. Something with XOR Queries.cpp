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
int ar[5010], er[5010], re[5010], ru[5010], ro[5010];
int n;
int pot(int n)
{
	int po = 1, con = 0;
	while(po < n)
	{
		po *= 2;
		con++;
	}
	return con;
}
int pon(int n)
{
	int po = 1, con = 0;
	while(po < n)
	{
		po *= 2;
		con++;
	}
	return po == n;
}
void vol(int x)
{
	fore(i, 0, n / x)
	{
		forg()
	}

}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	cin>>n;
	bool bo = true;
	fore(i, 0, n)
	{
		cout<<"? "<<i<<' '<<i<<endl;
		cin>>ar[i];
		if(i > 0)
			bo &= ar[i] == ar[i - 1];
		cout<<"? 0"<<' '<<i<<endl;
		cin>>er[i];
	}
	if(ar[0] == 0)
	{
		fore(i, 0, n)
			re[i] = er[i];
	}
	else
	{
		int ind = -1;
		fore(i, 0, n)
		{
			if(er[i] == 0)
			{
				ind = i;
				break;
			}
		}
		int end;
		fore(i, 1, ind)
		{
			if(ar[i] == ind)
				end = i;
		}
		fore(i, 0, n)
			re[i] = er[i] ^ end;
	}
	cout<<"!"<<endl;
	if(bo)
	{
		int con = 1;
		if(pon(n))
		{
			fore(i, 1, n + 1)
			{
				fore(i, 0, n)
					ru[i] = re[i];	
			}
		}
		fore(i, 0, n / 2)
			swap(ru[i], ru[n - 1 - i]);
		fore(i, 0, n)
			ro[ru[i]] = i;
		bo = true;
		fore(i, 0, n)
		{
			bo &= (ru[i] ^ ro[i]) == ar[i];
			bo &= (ru[0] ^ ro[i]) == er[i];
		}
		con += bo;
		if(n > 3)
		{
			fore(i, 0, n / 4)
			{
				swap(ru[i], ru[n / 2 - 1 - i]);
				swap(ru[n / 2 + i], ru[n - 1 - i]);
			}
			fore(i, 0, n)
				ro[ru[i]] = i;
			bo = true;
			fore(i, 0, n)
			{
				bo &= (ru[i] ^ ro[i]) == ar[i];
				bo &= (ru[0] ^ ro[i]) == er[i];
			}
			con += bo;
			fore(i, 0, n / 2)
				swap(ru[i], ru[n - 1 - i]);
			fore(i, 0, n)
				ro[ru[i]] = i;
			bo = true;
			fore(i, 0, n)
			{
				bo &= (ru[i] ^ ro[i]) == ar[i];
				bo &= (ru[0] ^ ro[i]) == er[i];
			}
			con += bo;
		}
		cout<<con<<'\n';
	}
	else
		cout<<"1"<<endl;
	fore(i, 0, n)
	{
		if(i > 0)
			cout<<' ';
		cout<<re[i];
	}
	cout<<endl;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2	