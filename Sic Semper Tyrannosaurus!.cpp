#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PI                acos(-1)
#define pb                push_back
#define mp                make_pair
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define forr(i, b, e)     for(ll i = b; i < e; i++)
#define forite(i, b, e)    for(auto i = b; i!=e; i++)
#define forg(i, b, e, m)  for(ll i = b; i < e; i+=m)

#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;

typedef __int128    ll;
typedef long int    li;
typedef pair<ll, ll>  ii;
typedef vector<ll>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const ll INF = ll(1e18);
#define tam 233200
#define tamlog 61
#define ptr nodo*

typedef pair<ll,ii> iii;
typedef long double lldb;
int n;
char inv[340];
string dp[340];
string f(int n)
{
    if (n==0)
        return "";
    if (dp[n]!="")
    return dp[n];
    string resp,auxr;
    if (n%2==1)
    {
        
        resp=f(n/2);
        if (rand()%2)
        resp+='y';
        else
        resp+='Y';
        resp+=f(n/2);
    }
    else
    {   
        auxr=f(n/2);
        resp+=auxr;
        forr(j,0,auxr.size())
        resp+=inv[auxr[j]];
        
    }
    return dp[n]=resp;
}
int  main()
{   
    //ios::sync_with_stdio(false);cin.tie(0);
    string a, s[5] = {"yYYYYyyYYYYYyyyYYYYY", "YyYYYYyyYYYYYyyyYYYYY", "YYyYYYYyyYYYYYyyyYYYYY","YYYyYYYYyyYYYYYyyyYYYYY", " YyYYYyyYYYYyyyYYYYYyYYYY"}
    cin>>n;
    srand(time(0));
    while(n > 0)
    {
        int po = 0;
        a = s[rand()%5];
        while(po < a.size() && n > 0)
        {
            cout<<a[po];
            po++;
            n--;
        }
        
    }
    cout<<f(n)<<endl;
}

// PLUS ULTRA!  
