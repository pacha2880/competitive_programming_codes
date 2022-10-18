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
		int n,a,b,sol=0;
		cin>>n;
		if(n==1)
		{
			cin>>a;
			if(a==1)
				cout<<"Second"<<endl;
			else
				cout<<"First"<<endl;
			return 0;
		}
		while(n--)
		{
			cin>>a;
			if(a>1)
				sol+=(a+1)/2;
		}
		if(sol%2==1)
			cout<<"First"<<endl;
		else
			cout<<"Second"<<endl;
		return 0;
	}

	// read the question correctly (is y a vowel? what are the exact constraints?)
	// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS