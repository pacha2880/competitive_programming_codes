#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
typedef long long       ll;
#define pb                push_back
#define mp    make_pair
#define sz(a)   a.size()
#define mods(a, m)   ((a % m + m) % m) 
#define md(a)    mods(a, MOD)
#define all(a)            (a).begin(), (a).end()
#define clr(a,h)          memset(a, (h), sizeof(a))
#define mem(a,h)          memset(a, (h), sizeof(a))
#define F first
#define S second
#define f first
#define s second
#define fore(i, b, e)   for (int i = b; i < e; i++)
#define forr(i, b, e)     for (int  i = b; i < e; i++)
int faster_in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -faster_in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;
typedef long double       ld;

typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
const int INF = int(1e9 + 7);
const int MOD = 100000007;
const double EPS = 1e-9;
const double PI = acos(-1);
vector<ll> divi[360010], gsi[360010];
bool visited[360010];
void divis(int n)
{
   int gs;
   visited[n] = 1;
   for(int i = 1; i * i <= n; i++)
   {
      if(n % i == 0)
      {
         divi[n].pb(i);
         if(!visited[i])
            divis(i);
         if(i * i != n)
         {
            divi[n].pb(n / i);
            if(!visited[n / i])
              divis(n / i);
         }
      }
   }
   sort(all(divi[n]));
}
bool marcs[360010]; ll mis[360010];
ll pot(ll b, ll e)
{
   ll res = 1;
   b%=MOD;
   while(e > 0)
   {
      if(e & 1) res = res * b ,res%=MOD;
      b = b * b;b%=MOD;
      e /= 2;
   }
   return res;
}
ll lemma(ll n, ll p)
{
  ll res = 0;
  fore(i, 1, n + 1)
  {
    res += pot(p, __gcd((ll)i, n));
    res %= MOD;
  }
  //cout<<res<<'\n';
  return res * pot(n, MOD - 2) % MOD;
}
int main()
{
    //std::ios::sync_with_stdio(false); cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    ll s, p, gs, tami, cono, res = 0;
    divis(360000);
    while(1)
    {
       cin>>p>>s;
       if(s == -1 && p == -1) break;
       gs = 1e9;
       res = 0;
       fore(i, 0, s) {cin>>mis[i]; gs = min(gs, mis[i]);}
       sort(mis, mis + s);
       fore(i, 0, s) mis[i] -= gs;
       gs = 0;
       fore(i, 0, s) gs = __gcd(gs, mis[i]);
       fore(i, 0, s) {mis[i] /= gs; marcs[mis[i]] = 1;}
       tami = 360000 / gs;
       bool bo;
       //cout<<tami<<'\n';
       //fore(i, 0, s) cout<<mis[i]<<' ';
       //cout<<'\n'<<'\n';
       res = 0;
       bool cha = false;
       fore(i, 0, divi[tami].size())
       {
          if(divi[tami][i] == tami) continue;
          //cout<<divi[tami][i]<<'-';
          bo = true;
          fore(j, 0, s)
          {
            if(!marcs[(mis[j] + divi[tami][i]) % tami])
            {
                //cout<<"  #  "<<mis[j]<<'\n';
                bo = false;
                break;
            }
          }
          //cout<<"sad";
          if(bo)
          {
            cha = true;
            //cout<<divi[tami][i]<<' '<<tami<<'\n';
              ll cona = 0, bas;
              fore(j, 1, s)
              {
                if(mis[j] == divi[tami][i])
                {
                  cona = j;
                  break;
                }
              }
              //if(cona == 0) continue;
              //cout<<cona<<'\n';
              bas = pot(p, cona);
              //cout<<bas<<'\n';
              //cout<<cona<<'\n';
              res = lemma(s / cona, bas);
              break;
          }
       }
       if(res == 0 && !cha)
        res = pot(p, s);
      fore(i, 0, s) marcs[mis[i]] = 0;
       cout<<res <<'\n';
    }
    return 0;
}
// PLUS ULTRA!  