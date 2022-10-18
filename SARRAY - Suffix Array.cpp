#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI 				acos(-1)
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define MOD				1000000007
#define MOD1			998244353
#define EPS				1e-9
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
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
const int tam = 100010;
string asd;
bool cmp(int a, int b)
{
	return asd[a] < asd[b];
}
vector<int> suffixa(string& s){ // O(n logn)
	int n = s.size(), cc = 0;
	asd = s;
	vector<int> sa(n), sa1(n), col(n, -1), col1(n), head(n);
	fore(i,0,n)
	{
		sa[i] = i;
		col[i] = s[i];
	}
	sort(col.begin(), col.end());
	stable_sort(sa.begin(), sa.end(), cmp);
	col[sa[0]] = head[0] = cc = 0;
	fore(i,1,n)
	{
		if(s[sa[i]] != s[sa[i - 1]])
		{
			cc++;
			head[cc] = i;
		}
		col[sa[i]] = cc;
	}
	for(int k=1;k<n;k*=2){
		fore(i, 0, n)
			sa1[head[col[(sa[i] - k + n) % n]]++] = (sa[i] - k + n) % n;
		sa = sa1;
		col1[sa[0]] = head[0] = cc = 0;
		fore(i,1,n)
		{
			if(col[sa[i]] != col[sa[i - 1]] || col[(sa[i] + k) % n] != col[(sa[i - 1] + k) % n])
			{
				cc++;
				head[cc] = i;
			}
			col1[sa[i]]=cc;
		}
		col = col1;
	}
	return sa;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	string s;
	cin>>s;
	s += '$';
	vector<int> suf = suffixa(s);
	fore(i, 1, suf.size())
		cout<<suf[i]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2