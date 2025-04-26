#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define fore(i, b, e)	  for (int i = b; i < e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const double EPS = 1e-9;
const double PI = acos(-1);


int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    vector<vector<int>> G(101, vector<int>(101));
    fore(i, 0, 101)
    {
    	fore(j, 0, 101)
    	{
    		if (i == j || i == 0 || j == 0) continue;
            unordered_set<int> st;
    		for (int k = 1; k < i; k++)
    		{
                if(k == j) continue;
    			st.insert(G[k][j]);
    		}
    		for (int k = 1; k < j; k++)
    		{
                if(k == i) continue;
                st.insert(G[i][k]);
    		}
            for (int k = 1; j - k > 0 && i - k > 0; k++)
            {
                st.insert(G[i - k][j - k]);
            }
            G[i][j] = 0;
            while(st.count(G[i][j]))
                G[i][j]++;
    	}
    }
    int n;
    cin >> n;
    int res = 0;
    bool win = false;
    while (n--)
    {
    	int a, b;
    	cin >> a >> b;
    	res ^= G[a][b];
    	if (a == b || b == 0 || a == 0) win = true;
    }
    if (res == 0 && !win) cout << 'N' << '\n';
    else cout << 'Y' << '\n';
    return 0;
}
// PLUS ULTRA!