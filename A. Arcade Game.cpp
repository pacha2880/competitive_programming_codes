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
#define MOD1		998244353
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
double pot(double b, int e)
{
	if(e == 0) return 1;
	return pot(b*b, e/2) * (e&1? b : 1.0);
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	map<int,int> fac[11];
	int maxi[11];
	for(int i = 10; i > 1; i--)
	{
		int ar[i];
		for(int j = 0; j < i; j++)
			ar[j] = j;
		int con = 0;
		do
		{
			int su = 0;
			for(int j = 0; j < i; j++)
			{
				su *= 10;
				su += ar[j];
			}
			fac[i][su] = con;
			con++;
		}
		while(next_permutation(ar,ar+i));
		maxi[i] = con-1;
	}
	int ta[11];
	int n;
	cin>>n;
	string s, s1;
	int ms[200];
	int ar[20];
	cout<<fixed<<setprecision(9);
	while(n--)
	{
		cin>>s;
		s1 = s;
		sort(s.begin(), s.end());
		for(int i = 0; i < s.size(); i++)
			ms[s[i]] = i;
		for(int i = 0; i < s1.size(); i++)
			ar[i] = ms[s1[i]];
		int po = 0;
		for(int i = 0; i < s.size(); i++)
		{
			po *= 10;
			po += ar[i];
		}
		if(s.size() == 1)
		{
			cout<<0.0<<'\n';
			continue;
		}
		po = fac[s.size()][po];
		if(po == maxi[s.size()])
			cout<<0.0<<'\n';
		else
		{
			double ex = maxi[s.size()]+1;
			//cout<<ex<<' '<<po<<' '<<maxi[s.size()] - 1-po<<' ';
			cout<<1.0/ex*pot(1.0/ex+1.0, maxi[s.size()] - 1 - po)<<'\n';
		}
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS