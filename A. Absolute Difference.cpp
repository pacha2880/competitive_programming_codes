/*
               __
              / _)
     _.----._/ /
    /         /
 __/ (  | (  |
/__.-'|_|--|_|
*/
#include <bits/stdc++.h>
 //#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <bits/extc++.h>
typedef long long ll;
#define int long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define all(a) (a).begin(), (a).end()
#define clr(a, h) memset(a, (h), sizeof(a))
#define f first
#define s second
#define fore(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
#define forr(i, b, e) for (int i = (int) b, o_o = e; i < (int) o_o; ++i)
#define deb(x) cerr << "# " << (#x) << " = " << (x) << endl;
#define sz(x) (int) x.size()
#define endl '\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")

typedef pair < int, int > ii;
typedef vector < int > vi;
typedef vector < ii > vii;
typedef vector < ll > vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
double res = 0;
double sua = 0, sub = 0;
void f(vii a, vii b)
{
    int posb = 0;
    double sas = 0, sus = 0;
    for(ii x : a)
    {
        while(posb < sz(b) && b[posb].s <= x.f)
        sas += (b[posb].s - b[posb].f) / sub * (b[posb].s + b[posb].f) , sus += (b[posb].s - b[posb].f) / sub, posb++;
        res += (x.s - x.f) / sua / 2 * ((x.f + x.s) * sus - sas);
    }
    sas = 0, sus = 0;
    posb = sz(b) - 1;
    for(int i = sz(a) - 1; i > -1; i--)
    {
        ii x = a[i];
        while(posb > -1 && b[posb].f >= x.s)
        sas += (b[posb].s - b[posb].f) / sub * (b[posb].s + b[posb].f) , sus += (b[posb].s - b[posb].f) / sub, posb--;
        res += (x.s - x.f) / sua / 2 * (sas - (x.f + x.s) * sus);
    }
}
void both(vii a, vii b)
{
    sua = sz(a), sub = sz(b);
    int posb = 0;
    double sas = 0, sus = 0;
    for(ii x : a)
    {
        while(posb < sz(b) && b[posb].f <= x.f)
            sas += b[posb].f / sub, sus += 1 / sub, posb++;
            res += (x.f * sus - sas) / sua;
    }
    sas = 0, sus = 0;
    posb = sz(b) - 1;
    for(int i = sz(a) - 1; i > -1; i--)
    {
        ii x = a[i];
        while(posb > -1 && b[posb].f > x.f)
            sas += b[posb].f / sub, sus += 1 / sub, posb--;
            res += (sas - x.f * sus) / sua;
    }
}
void one(vii a, vii b, double sua, double sub)
{
    int posb = 0;
    double sas = 0, sus = 0;
    // for(ii x: a) cout<<x.f<<' '<<x.s<<'\n';
    // cout<<'$'<<'\n';
    // for(ii x : b) cout<<x.f<<' '<<x.s<<'\n';
    for(ii x : a)
    {
        // cout<<x.f<<'\n';
        while(posb < sz(b) && b[posb].s <= x.f) //cout<<b[posb].f<<' '<<b[posb].s<<' '<<posb<<' '<<sub<<' '<<(b[posb].s + b[posb].f) / 2<<' '<<(b[posb].s - b[posb].f) / sub<<'\n',
        sas += (b[posb].s - b[posb].f) / sub * (b[posb].s + b[posb].f), sus += (b[posb].s - b[posb].f) / sub, posb++;
        // cout<<"###"<<sas<<" "<<sus<<'\n';
        res += (x.f * sus * 2 - sas) / sua / 2;
    }
    sas = 0, sus = 0;
    posb = sz(b) - 1;
    for(int i = sz(a) - 1; i > -1; i--)
    {
        ii x = a[i];
        while(posb > -1 && b[posb].f >= x.s)
        sas += (b[posb].s - b[posb].f) / sub * (b[posb].s + b[posb].f), sus += (b[posb].s - b[posb].f) / sub, posb--;
        res += (sas - x.f * sus * 2) / sua / 2;
    }
}
signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("","r",stdin);
    //freopen("","w",stdout);
    int n, m;
    vii a, b;
    cin>>n>>m;
    vector<ii> sweep;
    vii intera(n), interb(m);
    fore(i, 0, n) {
        int a, b;
        cin>>a>>b;
        intera[i] = {a, b};
        sua += b - a;
        sweep.pb({a, -1});
        sweep.pb({b, 1});
    }
    fore(i, 0, m) 
    {
        int a, b;
        cin>>a>>b;
        interb[i] = {a, b};
        sub += b - a;
        sweep.pb({a, -2});
        sweep.pb({b, 2});
    }
    // cout<<'@'<<sub<<'\n';
    vii nea, neb;
    sort(all(sweep));
    int la = sweep[0].f;
    int aa = 0, bb = 0;
    for(ii cat : sweep)
    {
        // cout<<aa<<' '<<bb<<' '<<la<<' '<<cat.f<<'\n';
        if(cat.f > la)
        {
            // cout<<bb<<'\n';
            if(aa)
                nea.pb({la, cat.f});
            if(bb)
                neb.pb({la, cat.f});// cout<<"metiendo\n";
            if(aa && bb)
            {
                double delta = cat.f - la;
                res += delta / sua * delta / sub *  delta / 3;
            }
        }
        if(cat.s == -2)
        bb++;
        if(cat.s == -1)
        aa++;
        if(cat.s == 2)
        bb--;
        if(cat.s == 1)
        aa--;
        la = cat.f;
    }
    if(sua == 0 || sub == 0)
    {
        sort(all(intera));
        sort(all(interb));
        if(sua == 0 && sub == 0)
        {
            both(intera, interb);
        }
        else if(sua == 0)
            one(intera, neb, sz(intera), sub);
        else if(sub == 0)
            one(interb, nea, sz(interb), sua);
        // cout<<res<<'\n';
    }
    else
        f(nea, neb);
    cout<<fixed<<setprecision(9)<<res<<'\n';
    return 0;
}