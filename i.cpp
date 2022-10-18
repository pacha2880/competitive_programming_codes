#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;
//using namespace __gnu_pbds;

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
bool operator <(vector<int> &a, vector <int> &b)
{
	int ta = 0, tb = 0;
	while(ta < a.size() && tb < b.size() && a[ta] == b[tb])
		ta++, tb++;
	if(ta < a.size() && tb < b.size())
		return a[ta] < b[tb];
	return a.size() < b.size();
}
int ar[100010], t[400040], resi[100010], conta[100010];
vector<int> sus[100010];
void update(int b, int e, int node, int pos, int val)
{
	if(b == e)
	{
		if(val == 1)
		{
			if(conta[b] == 1)
			{
				t[node] = 1;
			}
				conta[b]--;
		}
		else
		{
			conta[b]++;
			t[node] = 0;
		}
		return;
	}
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(pos <= mid) 
		update(b, mid, l, pos, val);
	else 
		update(mid + 1, e, r, pos, val);
	t[node] = t[l] + t[r];
}
int querys(int b, int e, int node, int i, int j)
{
	if(b >= i && e <= j)
		return t[node];
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(i > mid)
		return querys(mid + 1, e, r, i, j);
	if(j <= mid) 
		return querys(b, mid, l, i, j);
	return querys(b, mid, l, i, j) + querys(mid + 1, e, r, i, j);
}

int query(int b, int e, int node, int i, int j)
{
	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
	if(b >= i && e <= j)
	{
		if(t[node] == 0)
			return -1;
		if(b == e) return b;
		if(t[r] > 0)
			return query(mid + 1, e, r, i, j);
		return query(b, mid, l, i, j);
	}
	if(i > mid)
		return query(mid + 1, e, r, i, j);
	if(j <= mid) 
		return query(b, mid, l, i, j);

	if(querys(mid + 1, e, r, i, j) > 0)
		return query(mid + 1, e, r, i, j);
	return query(b, mid, l, i, j);
}
int main()
{
	//ios::sync_with_stdio(0); cin.tie(0);
	//freopen("qwe.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	vector<pair<pair<vector<int>, int>, pair<int, int>>> v;
	int ax;
	int n, m;
	cin>>n>>m;
	int a, b, c;
	fore(i, 0, n)
	{
		cin>>a;
		ax = a;
		vector<int> my;
		for(int j = 2; j * j <= ax; j++)
		{
			if(ax % j == 0)
			{
				sus[j].pb(i);
				while(ax % j == 0)
					ax /= j;
			}
		}
		if(ax != 1)
		{
			sus[ax].pb(i);
		}
	}
	fore(i, 0, m)
	{
		cin>>a>>b>>c;
		ax = c;
		vector<int> my;
		for(int j = 2; j * j <= ax; j++)
		{
			if(ax % j == 0)
			{
				my.pb(j);
				while(ax % j == 0)
					ax /= j;
			}
		}
		if(ax != 1)
		my.pb(ax);
		v.pb(mp(mp(my, i), mp(a - 1, b -1)));
	}
	sort(all(v));
	int nums[100];
	int cant = 0, res = 0;
	int desd;
	fore(i, 0, n) conta[i] = 1;
	fore(i, 0, n) update(0, n-1, 0, i, 1);
	fore(i, 0, m)
	{
		//cout<<i<<'\n';
		res = 0;
		bool bo;
		if(v[i].f.f.size() == 0)
		{
			resi[v[i].f.s] = v[i].s.s;
			continue;
		}
		fore(j, 0, cant)
		{
			//cout<<j<<'#';
			bo = false;
			fore(k, 0, v[i].f.f.size())
			{
				if(nums[j] == v[i].f.f[k])
					bo = true;
			}
			if(!bo)
			{
				res++;
				fore(l, 0, sus[nums[j]].size())
					update(0, n-1, 0, sus[nums[j]][l], 1);
				nums[j] = 1e8;
			}
		}
		sort(nums, nums + cant);
		cant -= res;
		
		//cout<<i<<'\n';
		fore(k, 0, v[i].f.f.size())
		{
			bo = false;
			fore(j, 0, cant)
			{
				if(nums[j] == v[i].f.f[k])
					bo = true;
			}
			if(!bo)
			{
				//cout<<k<<' ';
				nums[cant++] = v[i].f.f[k];
				//cout<<nums[cant-1]<<'\n';
				fore(l, 0, sus[nums[cant-1]].size())
				{
					//cout<<sus[nums[cant-1]][l]<<'.';
					update(0, n-1, 0, sus[nums[cant-1]][l], -1);
				}
				//cout<<cant<<'\n';
			}
		}
		resi[v[i].f.s] = query(0, n-1, 0, v[i].s.f, v[i].s.s);
		fore(i, 0, n) cout<<conta[i]<<' ';
		cout<<'\n';
	}
	fore(i, 0, m)
		cout<<(resi[i] == -1? -1 : resi[i] + 1)<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2