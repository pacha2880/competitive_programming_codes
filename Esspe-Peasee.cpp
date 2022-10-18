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
ll x,y,d;
void extended(ll a, ll b)
{
    if(b==0) { x = 1ULL; y = 0; d = a; return; }
    extended(b,a%b);
    ll x1 = y;
    ll y1 = x - (a/b)*y;
    x = x1;
    y = y1;
}
int main()
{
    //std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ll a,b,c,g,aa,bb,cc,nc,nf,a1,b1,a2,b2;
    while(true)
    {
        cin>>a>>b>>c;
        if(a ==0&&b==0&&c==0) break;
        if(a==0&&b==0)
        {   
            cout<<"Unquibable!\n";
            continue;
        }   
        if(c==0)
        {   
            
            cout<<0<<" fooms and "<<0<<" foobs for a twob!"<<'\n';
            continue;
        }
        g = __gcd(a,b);
        if(c%g!=0)
        {   
            cout<<"Unquibable!\n";
            continue;
        }
        if(a==0)
        {
            cout<<0<<" fooms and "<<c/b<<" foob"<<((c/b)==1ull?"":"s")<<" for a twob!"<<'\n';
            continue;   
        }
        if(b==0)
        {
            cout<<c/a<<" foom"<<((c/a)==1ull?"":"s")<<" and "<<0<<" foobs for a twob!"<<'\n';
            continue;
        }
        aa=a/g, bb=b/g, cc=c/g;
        extended(aa,bb);
        x*=cc;
        y*=cc;
        nc = ceil(((double)(-x))/((double)(bb)));
        nf = floor(((double)(y))/((double)(aa)));
        if(nf<nc)
        {
            cout<<"Unquibable!\n";
            continue;   
        }
        a1 = x + bb*nc;
        b1 = y - aa*nc;
        a2 = x + bb*nf;
        b2 = y - aa*nf;
        if(a1+b1 < a2+b2)
        {
            cout<<a1<<" foom"<<(a1==1ULL?"":"s")<<" and "<<b1<<" foob"<<(b1==1ULL?"":"s")<<" for a twob!"<<'\n';
        }
        else
        {
            cout<<a2<<" foom"<<(a2==1ULL?"":"s")<<" and "<<b2<<" foob"<<(b2==1ULL?"":"s")<<" for a twob!"<<'\n';    
        }

    }
    return 0;
}
// PLUS ULTRA!