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
	int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

	using namespace std;

	typedef long long 		ll;
	typedef unsigned long long 		ull;
	typedef pair<int, int>  ii;
	typedef vector<int>     vi;
	typedef vector<ii>      vii;
	typedef vector<ll>      vll;
	char fra[4000][1000],dib[6] = {'_','/','\\','_','/','\\'};
	int lo = 1, hi = 1, ori = 0, x, y;
	void frac(int lev)
	{
		if(lev == 0)
		{
			fra[y][x] = dib[ori];
			lo = max(lo,x+1);
			hi = max(hi,y+1);
		}
		else
		{
			frac(lev-1);
			ori++;
			ori%=6;
			if(ori == 0) y++;
			if(ori == 1) y++;
			if(ori == 2) x++;
			if(ori == 3) {x++, y--;}
			if(ori == 4) {x--, y--;}
			if(ori == 5) x--;
			frac(lev-1);
			ori+=4;
			ori%=6;
			if(ori == 0) x++;
			if(ori == 1) y--;
			if(ori == 2) y--;
			if(ori == 3) y--;
			if(ori == 4) x--;
			if(ori == 5) y++;
			frac(lev-1);
			ori++;
			ori%=6;
			if(ori == 0) y++;
			if(ori == 1) y++;
			if(ori == 2) x++;
			if(ori == 3) {x++, y--;}
			if(ori == 4) {x--, y--;}
			if(ori == 5) x--;
			frac(lev-1);
		}
	}
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		int n;
		bool t = false;
		while(cin>>n)
		{
			if(t) cout<<endl;
			t=true;
		for(int i = 0;i < 4000;i++)
			for(int j = 0;j<1000;j++)
				fra[i][j]='.';
		ori = 0;
		lo = 1;
		hi = 1;
		x = 0, y = 0;
		frac(n);
		for(int i = lo-1; i > -1; i--)
		{
			for(int j = 0; j < hi; j++)
				cout<<fra[j][i];
			cout<<'\n';
		}
		}
		return 0;
	}