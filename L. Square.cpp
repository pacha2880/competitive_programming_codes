#include <bits/stdc++.h>


#define pb                push_back

#define all(a)            (a).begin(), (a).end()
#define mem(a,h)          memset(a, (h), sizeof(a))
#define mul(a,b) (((a%MOD) * (b%MOD))%MOD)
#define forg(i, b, e, c)    for (ll i = (ll)b; i < (ll)e; i+=c)
#define forr(i, b, e)    for (ll i = b; i < e; i++)
#define fore(i, b, e)    for (ll i = b; i < e; i++)


using namespace std;



typedef long long  ll;

//typedef tree<vh,null_type,less<vh>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define initseg ll new_nodo=(nodo*2),mid=(iz+der)/2;
#define fi first
#define se second
#define ptr item*
#define __ll128 ll
#define tam 2105510
#define tamlog 14
const ll INF= 1e18;
const ll MOD= 1e9+7;
typedef vector<ll> vi;

typedef double ldb;
int v[tam];
int cant[tam],marca[tam];
vi descomp(int &x)
{
    for(ll i = 2; i * i <= x; i++)
    {
    	int hola = 0;
    	while(x % i == 0)
    	{
    		hola++;
    		x /= i;
    	}
    	cant[i] += hola & 1;
    }
    if(x > 1) cant[x]++;
}
ll pot(ll b,ll e)
{
    b%=MOD;
    ll res=1;
    while(e)
    {
        if (e&1)res*=b,res%=MOD;
        e/=2;b*=b;b%=MOD;
    }
    return res;
}
int main()
{
    forr(i,2,tam)
    {
        if (marca[i]!=0)continue;
        forg(j,i,tam,i)
        {

            marca[j]=i;
        }
    }
    int n;
    cin>>n;
    forr(i,0,n)
    {
        cin>>v[i];
        descomp(v[i]);
    }
    ll res=1;
    forr(i,2,tam)
    {
        if (marca[i]==i)
        {

            res*=pot(i,min(n-cant[i],cant[i])),res%=MOD;
        }
    }
    cout<<res<<endl;
}
