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
	int n,x,y,z,lx,ly,lz,a,b,c,d;
	while(cin>>n&&n)
	{
		x = y = z = 0;
		lx = ly = lz = 1000000000;
		while(n--)
		{
			cin>>a>>b>>c>>d;
			if(lx==0||ly==0||lz==0) continue;
			if(a<x && a+d<=x || a>=x+lx) {lx = 0; continue;}
			if(b<y && b+d<=y || b>=y+ly) {ly = 0; continue;}
			if(c<z && c+d<=z || c>=z+lz) {lx = 0; continue;}
			if(a>=x)
			{
				lx = min(lx-a+x,d);
				x = a;	
			}
			else
				lx = min(lx,a+d-x);
			if(b>=y)
			{
				ly = min(ly-b+y,d);
				y = b;
			}
			else
				ly = min(ly,b+d-y);
			if(c>=z)
			{
				lz = min(lz-c+z,d);	
				z = c;
			}
			else
				lz = min(lz,c+d-z);
		}
		cout<<lx*ly*lz<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS