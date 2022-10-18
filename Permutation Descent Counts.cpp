#include <bits/stdc++.h>
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

const int INF = int(1e9 + 7);
typedef long long       ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
int MOD = 1001113;
int main()
{
    std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int dp[100][100];
    for(int i = 0; i<100; i++)
        for(int j = 0; j<100; j++)
            dp[i][j]=1;
    for(int i = 2; i < 100; i++)
        for(int j = 1; j < i; j++)
            dp[i][j] = (((i-j+1)*dp[i-1][j-1])%MOD + ((j+1)*dp[i-1][j])%MOD)%MOD;

    int n,a,b,c;
    cin>>n;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b>>c;
        cout<<a<<' '<<dp[b-1][c]<<endl;
    }
    return 0;
}
// PLUS ULTRA!