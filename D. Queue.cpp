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
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	string s;
	cin>>s;
	vi v;
	char ch = s[0];
	int con = 1;
	for(int i = 1; i < s.size(); i++)
	{
		if(s[i] == ch)
			con++;
		else
		{
			v.pb(con);
			con = 1;
			ch = s[i];
		}
	}
	v.pb(con);
	int n = v.size();
	int in = 0, fi = n;
	if(s[0] == 'F') in = 1;
	if(s[s.size()-1] == 'M') fi = n-1;
	if(v.size() == 1 || fi == in) {cout<<0; return 0;}
	int t = (fi - in) / 2;
	int mam[t], maf[t], arm[t], arf[t];
	maf[0] = v[in+1];
	arf[0] = maf[0];
	mam[t-1] = v[fi-2];
	arm[t-1] = mam[t-1];
	con = 1;
	for(int i = in+2; i < fi; i+=2)
	{
		arf[con] = v[i+1];
		arm[t-1-con] = v[fi-2-(i-in)];
		con++; 
	}
	int sum = arm[0] - 1, tiem = arf[0];
	//cout<<tiem<<endl;
	for(int i = 1; i < t; i++)
	{
		if(tiem < arm[i])
		{
			tiem += arm[i] - tiem;
		}
		tiem += arf[i];
		if(i < t - 1) arm[i+1] += arm[i];
		//cout<<tiem<<"--"<<arm[i]<<' '<<arf[i]<<endl;
	}
	cout<<sum + tiem;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS