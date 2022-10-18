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
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1);

int main()
{
  std::ios::sync_with_stdio(false); cin.tie(0);
  //freopen("asd.txt","r",stdin);
  //freopen("","w",stdout);
  int n;
  set<ll> st;
  ll res = 0;
  set<ll>::iterator my, l, r;
  cin>>n;
  ll ar[n];
  fore(i, 0, n)
  {
    cin>>ar[i];
    st.insert(ar[i]);
  }
  ll ax, ux, ex;
  fore(i, 0, n)
  {
    ux = res;
    my = st.find(ar[i]);
    l = my;
    l--;
    r = my;
    r++;
    int repos = 10;
    //cout<<*my<<' '<<*l<<' '<<*r<<'\n';
    while(1)
    {
      ex = res;
      //cout<<'=';
      if(my == st.begin())
      {
        //cout<<"\nchanfle\n";
        res += ar[n-1] - ar[0];
        break;
      }
      if(r == st.end())
      {
        //cout<<"\nchoclo \n"<<' ';
        res += ar[n-1] - ar[0];
        break;
      }
      if(*r - *my <= *my - *l)
      {
        ax = *my - *l;
        //cout<<*my + *my - *l<<" @ ";;
        my = st.upper_bound(*my + *my - *l);
        my--;
        //cout<<*my<<'\n';
        res += *my - *l - ax;
        r = my;
        r++;
      }
      else
      {
        ax = *r - *my;
        my = st.lower_bound(*my - *r + *my);
        res += *r - *my - ax;
        l = my;
        l--;  
      }
      //cout<<*my<<'-';
      //cout<<res<<'\n';
      //cout<<*my<<'-'<<res - ex<<' ';
    }
    //cout<<"\n # "<<i<<' '<<res - ux<<'\n';
  }
  cout<<res<<'\n';
  return 0;
}
// PLUS ULTRA!
//You have n clothes and a washer. The washer is large enough to wash all clothes at once. However, we should worry about color transfer:  if we put clothes of different colors in the washer, the dye from one may stain another. Precisely, let ri, gi, bi denote the amount of red, green, blue color of the i-th clothes. When n clothes are washed together, the color transfer c is defined by