	#include <bits/stdc++.h>
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

typedef long long 		ll;
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int m,n,a;
	cin>>m>>n;
	int conv[m],ar[n][m],con;
	ll mini[m];
	for(int i=0;i<m;i++)
		mini[i]=i+1;
	for(int i = 0; i<m;i++)
	{
		cin>>a;
		conv[a-1] = i;
		ar[0][i]=i;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=0; j < m; j++)
		{
			cin>>a;
			ar[i][j]=conv[a-1];
		}
	}
	for(int i=1;i<n;i++)
	{
		con = 1;
		mini[ar[i][0]]=1;
		for(int j = 1;j<m;j++)
		{
			if(ar[i][j]==ar[i][j-1]+1)
			{
				con++;
				mini[ar[i][j]]=min((ll)con,mini[ar[i][j]]);
			}
			else
			{
				con=1;
				mini[ar[i][j]]=1;
			}
		}
	}
	ll res=0;
	for(int i = 0;i<m;i++)
	{
		res+=mini[i];
	}
	cout<<res;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS