#include<bits/stdc++.h>
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
int ar[tam], t[4 * tam];
void init(int b, int e, int node)
{
    if(b == e)
    {
        t[node] = ar[b];
        return;
    }
    index;
    init(b, mid, l);
    init(mid + 1, e, r);
    t[node] = max(t[l], t[r]);
}
int query(int b, int e, int node, int pos, int val)
{
    if(b <= pos && t[node] <= val)
        return -1;
    if(b == e)
    {
        if(t[node] > val)
            return b;
        return -1;
    }
    index;
    if(mid < pos)
        return query(mid + 1, e, r, pos, val);
    int va = query(b, mid, l, pos, val);
    if(va == -1)
        va = query(mid + 1, e, r, pos, val);
    return va;
}
void update(int b, int e, int node, int pos, int val)
{
    if(b == e)
    {
        t[node] = val;
        return;
    }
    index;
    if(pos <= mid)
        update(b, mid, l, pos, val);
    else
        update(mid + 1, e, r, pos, val);
    t[node] = max(t[l], t[r]);
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    // vi ar(n);
    fore(i, 0, n) cin>>ar[i];
    init(0, n - 1, 0);
    fore(i, 0, n)
    {
        if(ar[i] == -1) continue;
        int va = i;
        while(va != -1)
        {
            cout<<ar[va]<<' ';
            int ax = ar[va], ex = va;
            ar[va] = -1;
            va = query(0, n - 1, 0, ex, ax);
            update(0, n - 1, 0, ex, -1);
        }
        cout<<'\n';
    }
	return 0;
}