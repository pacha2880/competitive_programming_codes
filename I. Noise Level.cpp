#include<bits/stdc++.h>
#define int     long long
#define f 		first
#define s 		second
#define pb      push_back
#define index   int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define sz(v) 	(int)v.size()
#define fore(i, b, e)   for(int i = b; i < e; i++)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int tam = 200010;

signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q, p;
    cin>>n>>m>>q>>p;
    vector<string> tab(n);
    vector<vi> cucu(n, vi(m));
    fore(i, 0, n) cin>>tab[i];
    vector<vi> visos(n, vi(m));
    int visa = 0;
    auto in = [&](int x, int y)
    {
        return x >= 0 && x < n && y >= 0 && y < m && tab[x][y] != '*';
    };
    vii dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    fore(i, 0, n)
    {
        fore(j, 0, m)
        {
            if(tab[i][j] >= 'A' && tab[i][j] <= 'Z')
            {
                int bala = (tab[i][j] - 'A' + 1) * q;
                visa++;
                visos[i][j] = visa;
                queue<vi> que;
                que.push({i, j, bala});
                // cout<<i<<' '<<j<<' '<<bala<<'\n';
                cucu[i][j] += bala;
                while(!que.empty())
                {
                    int x = que.front()[0], y = que.front()[1], bala = que.front()[2];
                    que.pop();
                    if(bala == 1) continue;
                    fore(i, 0, 4)
                    {
                        int xx = x + dir[i].f, yy = y + dir[i].s;
                        if(in(xx, yy) && visos[xx][yy] != visa)
                        {
                            visos[xx][yy] = visa;
                            cucu[xx][yy] += bala / 2;
                            que.push({xx, yy, bala / 2});
                        }
                    }
                }
            }
        }
    }
    int res = 0;
    fore(i, 0, n)
        fore(j, 0, m) res += cucu[i][j] > p;
    cout<<res<<'\n';
	return 0;
}