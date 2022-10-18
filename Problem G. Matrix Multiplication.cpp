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
bitset<4000> mat[3][4000], x, res[3];
	int n;
void mul(int pos)
{
	res[pos].reset();
	for(int i = 0; i < n; i++)
		res[pos][i] = (mat[pos][i] & x).count()&1;
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	cin>>n;
	string s;
	int conv[200];
	for(int i = 0; i < 10; i++)
		conv[i + '0'] = i;
	conv['A'] = 10;
	conv['B'] = 11;
	conv['C'] = 12;
	conv['D'] = 13;
	conv['E'] = 14;
	conv['F'] = 15;
	int com;
	for(int l = 0; l < 3; l++)
	{
		for(int i = 0; i < n; i++)
		{
			mat[l][i].reset();
			cin>>s;
			int pos = 0;
			for(int j = 0; j < s.size(); j++)
			{
				com = conv[s[j]];
				for(int k = 1<<3; k > 0 && pos < n; k>>=1, pos++)
				{
					mat[l][i][pos] = k&com;
					//cout<<mat[l][i][pos];
				}
			}
		}
	}
	double t = clock();
	while((clock() - t) / CLOCKS_PER_SEC < 0.8)
	{
		srand (time(NULL));
		x.reset();
		for(int i = 0; i < n; i++)
			x[i] = rand() % 2;
		//cout<<'\n';
		mul(2);
		mul(1);
		x = res[1];
		mul(0);
		if(res[2] != res[0])
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
	return 0;
}
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2