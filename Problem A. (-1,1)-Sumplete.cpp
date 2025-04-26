#include <bits/stdc++.h>
#define f           first
#define s           second
#define pb          push_back
// #define int         long long
#define all(v)      v.begin(), v.end()
#define fore(a, b, c)   for(int a = b; a < c; a++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int tam = 200010;


signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    vector<string> tab(n);
    fore(i, 0, n) cin>>tab[i];
    vi fi(n), col(n);
    int ss = 0, su = 0;
    fore(i, 0, n) cin>>fi[i], ss += fi[i];
    fore(i, 0, n) cin>>col[i], ss -= col[i];
    int s = 2 * n, t = 2 * n + 1;
    vector<vi> res(n, vi(n));
    fore(i, 0, n)
    {
        fore(j, 0, n)
        {
            res[i][j] = tab[i][j] == '-';
            if(tab[i][j] == '-')
                fi[i]++, col[j]++;
        }
    }
    fore(i, 0, n)
    {
        if(fi[i] < 0 || col[i] < 0)
        {
            cout<<"No\n";
            return 0;
        }
    }
    vector<vi> fils(n + 1);
    vi pus(n);
    vector<vi> vis(n, vi(n));
    bool bo = 1;
    fore(i, 0, n)
    {
        pus[i] = n - 1;
        fils[fi[i]].pb(i);
    }
    for(int i = n; i > 0;)
    {
        if(fils[i].empty())
        {
            i--;
            continue;
        }
        int nu = fils[i].back();
        fils[i].pop_back();
        fils[i - 1].pb(nu);
        while(pus[nu] > 0 && !col[pus[nu]])
            pus[nu]--;
        if(pus[nu] == -1)
        {
            bo = 0;
            break;
        }
        res[nu][pus[nu]] ^= 1;
        col[pus[nu]]--;
        pus[nu]--;
        
    }
    fore(i, 0, n) if(col[i]) bo = 0;
    if(bo)
    {
        cout<<"Yes\n";
        fore(i, 0, n)
        {
            fore(j, 0, n)
                cout<<res[i][j];
            cout<<'\n';
        }
    }
    else
        cout<<"No\n";
    return 0;
}