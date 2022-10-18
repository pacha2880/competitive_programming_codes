#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI                acos(-1)
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
using namespace __gnu_pbds;

typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//const int MOD = 1000000;
#define tam 213456;
int cans[4];
short int dp[4][4][39][39][39][39];
short int f(int les, int nums, int cana, int canb, int canc, int cand, short int MOD)
{
	les &= 3;
	nums &= 3;
	//cout<<les<<' '<<nums<<' '<<cana<<' '<<canb<<' '<<canc<<' '<<cand<<'\n';
	if(cana + canb + canc + cand == 0)
		return 1;
	if(dp[les][nums][cana][canb][canc][cand] != (short int)-1) return dp[les][nums][cana][canb][canc][cand];
	short int res = 0;
	if(cana > 0 && les != 0 && nums != 0)
	{
		res += f(les << 1, nums << 1, cana-1, canb, canc, cand, MOD);
		res %= MOD;
	}
	if(canb > 0 && les != 0 && nums != 3)
	{
		res += f(les << 1, (nums << 1) + 1, cana, canb-1, canc, cand, MOD);
		res %= MOD;
	}
	if(canc > 0 && les != 3 && nums != 0)
	{
		res += f((les << 1) + 1, nums << 1, cana, canb, canc-1, cand, MOD);
		res %= MOD;
	}
	if(cand > 0 && les != 3 && nums != 3)
	{
		res += f((les << 1) + 1, (nums << 1) + 1, cana, canb, canc, cand-1, MOD);
		res %= MOD;
	}
	return dp[les][nums][cana][canb][canc][cand] = res;
}
int main()
{
    //std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int tot = 0;
    for(int i = 0; i < 4; i++)
    {
    	cin>>cans[i];
    	tot += cans[i];
    }
   int res = 0;
   int les[2][4] = {{0, 0, 2, 2}, {0, 0, 1, 1}};
   int nus[2][4] = {{0, 2, 0, 2}, {0, 1, 0, 1}};
   bool lis[10];
   clr(lis, 0);
   clr(dp, -1);
   int a,b,c,d;
   if(tot <= 2)
   {
   		for(int i = 0; i < 4; i++)
   		{
   			if(cans[i] == 2)
   			{
   				cout<<1<<'\n';
   				return 0;
   			}
   		}
   		cout<<tot<<'\n';
   		return 0;
   }
   int MOD = 15625;
    for(int i = 0; i < 4; i++)
    	for(int j = 0; j < 4; j++)
    	{
    		//cout<<i<<' '<<j<<'\n'<<'\n';
    		if(cans[i] > 0 && cans[j] > 0 && i != j)
    		{
    			cans[i]--;
    			cans[j]--;
    			a = cans[0];
    			b = cans[1];
    			c = cans[2];
    			d = cans[3];
    			res += f(les[0][i] | les[1][j], nus[0][i] | nus[1][j], a, b, c, d, MOD);
    			res %= MOD;
    			cans[i]++;
    			cans[j]++;
    		}
    		//cout<<i<<' '<<j<<'\n';
    		if(cans[i] > 1 && i == j && !lis[i])
    		{
    			lis[i] = 1;
    			cans[i]--;
    			cans[j]--;
    			a = cans[0];
    			b = cans[1];
    			c = cans[2];
    			d = cans[3];
    			res += f(les[0][i] | les[1][j], nus[0][i] | nus[1][j], a, b, c, d, MOD);
    			res %= MOD;
    			cans[i]++;
    			cans[j]++;
    		}
    	}
    int res1 = 0;
    MOD = 64;
    clr(dp, -1);
    clr(lis, 0);
    for(int i = 0; i < 4; i++)
      for(int j = 0; j < 4; j++)
      {
        //cout<<i<<' '<<j<<'\n'<<'\n';
        if(cans[i] > 0 && cans[j] > 0 && i != j)
        {
          cans[i]--;
          cans[j]--;
          a = cans[0];
          b = cans[1];
          c = cans[2];
          d = cans[3];
          res1 += f(les[0][i] | les[1][j], nus[0][i] | nus[1][j], a, b, c, d, MOD);
          res1 %= MOD;
          cans[i]++;
          cans[j]++;
        }
        //cout<<i<<' '<<j<<'\n';
        if(cans[i] > 1 && i == j && !lis[i])
        {
          lis[i] = 1;
          cans[i]--;
          cans[j]--;
          a = cans[0];
          b = cans[1];
          c = cans[2];
          d = cans[3];
          res1 += f(les[0][i] | les[1][j], nus[0][i] | nus[1][j], a, b, c, d, MOD);
          res1 %= MOD;
          cans[i]++;
          cans[j]++;
        }
      }
    //cout<<res<<' '<<res1<<'\n';
    while(res % MOD != res1)
    {
      res += 15625;
    }
    cout<<res%1000000<<'\n';
}
// PLUS ULTRA!