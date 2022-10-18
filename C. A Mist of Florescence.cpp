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
	int main()
	{
		//ios::sync_with_stdio(false); cin.tie(0);
		//freopen("", "r", stdin);
		//freopen("", "w", stdout);
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		pair<int,int> p[4] = { {-a,0},{-b,1},{-c,2},{-d,3}};
		sort(p,p+4);
		char chh[4] = {'A','B','C','D'},ch[4] = {chh[p[0].s],chh[p[1].s],chh[p[2].s],chh[p[3].s]};
		a = -p[0].f, b = -p[1].f, c = -p[2].f, d = -p[3].f;		
		char mat[50][50];
		for(int i = 0;i<50;i++)
			for(int j = 0;j<50;j++)
				mat[i][j]=ch[3];
		//mem(mat,0);
		for(int i = 0;i<49;i++)
		{
			if(a==0)
				break;
			mat[i][i]=ch[0];
			a--;
		}
		for(int i = 3;i<49;i++)
		{
			if(a==0)
				break;
			mat[i][i-3]=ch[0];
			a--;
		}
		for(int i = 6;i<49;i++)
		{
			if(a==0)
				break;
			mat[i][i-6]=ch[0];
			a--;
		}
		for(int i = 0;i<49;i++)
		{
			if(mat[i][i]!=ch[0])
			{
				if(b==0)
					break;
				mat[i][i]=ch[1];
				b--;
			}
		}
		for(int i = 3;i<49;i++)
		{
			if(mat[i][i-3]!=ch[0])
			{
				if(b==0)
					break;
				mat[i][i-3]=ch[1];
				b--;
			}
		}
		for(int i = 6;i<49;i++)
		{
			if(mat[i][i-6]!=ch[0])
			{
				if(b==0)
					break;
				mat[i][i-6]=ch[1];
				b--;
			}
		}
		for(int i = 9;i<49;i++)
		{
			if(b==0)
				break;
			mat[i][i-9]=ch[1];
			b--;
		}
		for(int i = 12;i<49;i++)
		{
			if(b==0)
				break;
			mat[i][i-12]=ch[1];
			b--;
		}
		for(int i = 15;i<49;i++)
		{
			if(b==0)
				break;
			mat[i][i-15]=ch[1];
			b--;
		}
		//d
		d--;
		for(int i = 1;i<48;i++)
		{
				if(d==0)
					break;
				mat[i][i-1]=ch[3];
				mat[i+1][i-1]=ch[2];
				d--;
				c--;
		}
		for(int i = 4;i<48;i++)
		{
				if(d==0)
					break;
				mat[i][i-4]=ch[3];
				mat[i+1][i-4]=ch[2];
				d--;
				c--;
		}
		for(int i = 7;i<48;i++)
		{
				if(d==0)
					break;
				mat[i][i-7]=ch[3];
				mat[i+1][i-7]=ch[2];
				d--;
				c--;
		}
		//c
		for(int i = 0;i<46;i++)
		{
				if(c==0)
					break;
				mat[i][i+3]=ch[2];
				c--;
		}
		for(int i = 0;i<43;i++)
		{
				if(c==0)
					break;
				mat[i][i+6]=ch[2];
				c--;
		}
		for(int i = 0;i<40;i++)
		{
				if(c==0)
					break;
				mat[i][i+9]=ch[2];
				c--;
		}
		cout<<"50 50\n";
		for(int i=0;i<50;i++)
		{
			for(int j = 0;j<50;j++)
			{
				cout<<mat[i][j];
			}
			cout<<endl;
		}
		return 0;
	}