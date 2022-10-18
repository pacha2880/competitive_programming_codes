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
int bit[400005];
void update(int pos, int val)
{
	pos++;
	while(pos < 400005)
	{
		bit[pos] = max(bit[pos], val);
		pos += (pos & -pos);
	}
}
int query(int pos)
{
	pos++;
	int res = 0;
	while(pos > 1)
	{
		res = max(res,bit[pos]);
		pos -= (pos & -pos);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int n, a;
	cin>>n;
	int ar[n];
	map<int,vector<int>> mp;
	for(int i = 0; i < n; i++)
	{
		cin>>a;
		mp[a].pb(i);
	}
	map<int,vector<int>>::iterator it;
	int con = 0;
	for(it = mp.begin(); it != mp.end(); it++)
	{
		for(int i = 0; i < (it->s).size(); i++)
			ar[(it->s)[i]] = con;
		con+=2;
	}
	mem(bit, 0);
	int ax;
	for(int i = n-1; i > -1; i--)
	{
		ax = ar[i];
		ar[i] = query(ar[i]-1);
		//cout<<ar[i]<<' ';
		if(ar[i] == 0)
			ar[i] = -1;
		else
			ar[i] -= i+2;
		update(ax, i+1);
	}
	//cout<<endl;
	for(int i = 0; i < n; i++)
	{
		if(i > 0) cout<<' ';
		cout<<ar[i];
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS