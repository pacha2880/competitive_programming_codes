#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>	ii;
typedef vector<int>		vi;
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	ii coor[100000];
	int c=0,di=0;
	coor[0]=make_pair(0,0);
	while(c<99999)
	{
		di++;
		c++;
		coor[c]=make_pair(coor[c-1].f,coor[c-1].s+1);
		for(int i=0;i<di-1&&c<99999;i++)
		{
			coor[c+1]=make_pair(coor[c].f-1,coor[c].s+1);
			c++;
		}
		for(int i=0;i<di&&c<99999;i++)
		{
			coor[c+1]=make_pair(coor[c].f-1,coor[c].s);
			c++;
		}
		for(int i=0;i<di&&c<99999;i++)
		{
			coor[c+1]=make_pair(coor[c].f,coor[c].s-1);
			c++;
		}
		for(int i=0;i<di&&c<99999;i++)
		{
			coor[c+1]=make_pair(coor[c].f+1,coor[c].s-1);
			c++;
		}
		for(int i=0;i<di&&c<99999;i++)
		{
			coor[c+1]=make_pair(coor[c].f+1,coor[c].s);
			c++;
		}
		for(int i=0;i<di&&c<99999;i++)
		{
			coor[c+1]=make_pair(coor[c].f,coor[c].s+1);
			c++;
		}
	}
	while(cin>>c)
		cout<<coor[c-1].f<<' '<<coor[c-1].s<<endl;
	return 0;
}