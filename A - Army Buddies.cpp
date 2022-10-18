#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                emplace_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define f first
#define s second
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
int parent[2][100010];
int find(int ti, int n)
{
	if(parent[ti][n] == -1) return n;
	return parent[ti][n] = find(ti, parent[ti][n]);
}
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("qwe.txt","r",stdin);
    //freopen("asd.txt","w",stdout);
    int n, m, axa, axb, a, b, prea, preb;
    while(1)
    {
    	cin>>n>>m;
    	if(n == 0 && m == 0) break;
    	fore(i, 0, n+2) fore(j, 0, 2) parent[j][i] = -1;
    	while(m--)
    	{
    		cin>>a>>b;
    		if(find(0, a - 1) == 0)
    			cout<<'*';
    		else
    			cout<<(find(0, a - 1));
    		cout<<' ';
    		if(find(1, b + 1) == n + 1)
    			cout<<'*';
    		else
    			cout<<(find(1, b + 1));
    		cout<<'\n';
    		fore(i, a, b+1)
    		parent[1][find(1, i)] = find(1, b + 1);
    		for(int i = b; i >= a; i--)
    			parent[0][find(0, i)] = find(0, a - 1);
    	}
    	cout<<"-\n";
    }
    return 0;
}
// PLUS ULTRA!