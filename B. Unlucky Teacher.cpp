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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("asd.txt", "w", stdout);
	int cas;
	cin>>cas;
	while(cas--)
	{
		int n, m;
		cin>>n>>m;
		int que[n][4];
		mem(que, 0);
		mem(que, 0);
		char cha, chb;
		for(int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
			{
				cin>>cha>>chb;	
				que[j][cha - 'A'] = (chb == 'T'? 1 : -1);
			}

		}
		for(int i = 0; i < n; i++)
		{
			if(i > 0) cout<<' ';
			int con = 0;
			bool bo = true;
			for(int j = 0; j < 4; j++)
			{
				if(que[i][j] == 1)
					{
						cha = 'A' + j;
						cout<<cha;
						bo = false;
						break;
					}
				if(que[i][j] == -1)
					con++;
			}
			if(bo)
			{
				if(con < 3)
					cout<<'?';
				else
				{
					for(int j = 0; j < 4; j++)
					{
						if(que[i][j] == 0)
							{
								cha = 'A' + j;
								cout<<cha;
								break;
							}
					}
				}
			}
		}
		cout<<'\n';
	}
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS