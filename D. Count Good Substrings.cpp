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
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	string s;
	vll a,b;
	cin>>s;
	int con=1;
	bool ba,fi;
	if(s[0] == 'a')
	{
		fi = true;
		ba = true;
	}
	else
	{
		fi = false;
		ba = false;
	}
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] == 'a')
		{
			if(ba)
				con++;
			else
			{
				b.pb(con);
				con=1;
				ba = true;
			}
		}
		else
		{
			if(ba)
			{
				a.pb(con);
				con = 1;
				ba = false;
			}
			else
				con++;
		}
	}
	if(ba)
		a.pb(con);
	else
		b.pb(con);
	ll par = 0, impar = 0, rese = 0, reso = 0;
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i]%2 == 1)
		{
			rese += ((a[i]+1)*(a[i]/2))/2;
			reso += ((a[i]+1)*(a[i]/2+1))/2;
		}
		else
		{
			rese += (a[i]*(a[i]/2))/2;
			reso += ((a[i]+2)*(a[i]/2))/2;
		}
		rese += impar*((a[i]+1)/2) + par*(a[i]/2);
		reso += par*((a[i]+1)/2) + impar*(a[i]/2);
		if(a[i]%2 == 1)
			swap(par,impar);
		par += a[i]/2;
		impar += (a[i]+1)/2;
		if(i + !fi < b.size())
		{
			
		if(b[i+!fi]%2==1)
			swap(par,impar);
		}
	}
	par = impar = 0;
	for(int i = 0; i < b.size(); i++)
	{
		if(b[i]%2 == 1)
		{
			rese += ((b[i]+1)*(b[i]/2))/2;
			reso += ((b[i]+1)*(b[i]/2+1))/2;
		}
		else
		{
			rese += (b[i]*(b[i]/2))/2;
			reso += ((b[i]+2)*(b[i]/2))/2;
		}
		rese += impar*((b[i]+1)/2) + par*(b[i]/2);
		reso += par*((b[i]+1)/2) + impar*(b[i]/2);
		if(b[i]%2 == 1)
			swap(par,impar);
		par += b[i]/2;
		impar += (b[i]+1)/2;
		if(i + fi < a.size())
		{

		if(a[i+fi]%2==1)
			swap(par,impar);	
		}
	}

	cout<<rese<<' '<<reso;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS