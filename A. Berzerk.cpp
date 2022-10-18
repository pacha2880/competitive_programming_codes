	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			firs
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
	int n,a,ax,b;
	cin>>n>>a;
	int st[n][2], ara[a];
	for(int i=0;i<n;i++)
		st[i][0]=st[i][1]=1;
	string poses[3] = {"Win", "Loop", "Lose"};
	for(int i=0;i<a;i++)
	{
		cin>>ara[i];
		st[n-ara[i]][0]=0;
	}
	cin>>b;
	int arb[b];
	for(int i=0;i<b;i++)
	{
		cin>>arb[i];
		st[n-arb[i]][1]=0;
	}
	bool l,e;
	for(int k=0;k<500000000/((n-1)*(a+b));k++)
	for(int i=1;i<n;i++)
	{
			l=e=false;
			for(int j = 0; j<a; j++)
			{
				ax=(n+i+ara[j])%n;
				if(st[ax][1]==2||ax==0)
				{
					st[i][0] = 0;
					e=1;
					break;
				}
				if(st[ax][1]==1)
					l=true;
			}
			if(!e)
			{
				if(l)
					st[i][0]=1;
				else
					st[i][0]=2;
			}
			l=e=false;
			for(int j = 0; j<b; j++)
			{
				ax=(n+i+arb[j])%n;
				if(st[ax][0]==2||ax==0)
				{
					st[i][1] = 0;
					e=1;
					break;
				}
				if(st[ax][0]==1)
					l=true;
			}
			if(!e)
			{
				if(l)
					st[i][1]=1;
				else
					st[i][1]=2;
			}
	}
	for(int i=1;i<n;i++)
	{
		if(i>1) cout<<' ';
		cout<<poses[st[i][0]];
	}
	cout<<endl;
	for(int i=1;i<n;i++)
	{
		if(i>1) cout<<' ';
		cout<<poses[st[i][1]];
	}
	cout<<endl;
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS