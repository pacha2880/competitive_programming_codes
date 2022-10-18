#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l + node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });


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
const int tam = 2010;
const ll MOD = 100000000000007ll;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
int ar[tam], n;
vector<int> nums[tam];
int le[tam], ri[tam];
pair<ll, int> fin[tam][tam];
pair<ll, int> fro[tam][tam];
int dis(int fro, int to)
{
	if(fro > to)
		swap(fro, to);
	return min(to - fro, fro + n - to);
}
int go(int nu, int fro, int to)
{
	if(fro == to)
		return nums[nu].size() == 1 ? 0 : n;
	if(nums[nu].size() == 2)
		return dis(fro, to);
	if(fro > to)
		swap(fro, to);
	return min(2 * (le[to] - fro) + fro + n - to, 2 * (fro + (ri[to] > to ? n - ri[to] : -ri[to])) + to - fro);
}
string tost(int n)
{
	string res = "";
	do
	{
		res += '0' + (n % 10);
		n /= 10;
	}
	while(n > 0);
	reverse(all(res));
	return res;
}
int main()
{
	// ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("asd.txt", "r", stdin);
	//freopen("qwe.txt", "w", stdout);
	int s;
	cin>>n>>s;
	s--;
	set<int> st;
	fore(i, 0, n)
	{
		cin>>ar[i];
		st.insert(ar[i]);
	}
	int co = 0;
	map<int, int> ma;
	for(int x : st)
		ma[x] = co++;
	fore(i, 0, n) 
	{
		ar[i] = ma[ar[i]];
		nums[ar[i]].pb(i);
	}
	// fore(i, 0, n)
	// 	cout<<ar[i]<<' ';
	// cout<<'\n';
	fore(i, 0, co)
	{
		int si = nums[i].size();
		fore(j, 0, si)
		{
			le[nums[i][j]] = nums[i][(j - 1 + si) % si];
			ri[nums[i][j]] = nums[i][(j + 1) % si];
		}
	}

	// cout<<nums[0].size()<<' '<<go(0, s, nums[0][0])<<'\n';
	// pair<pair<ll, int>, int> manu{{MOD, 0}, 0};
	// fore(i, 0, nums[0].size())
	// 	manu = min(manu, {fin[0][i], nums[0][i]});
	// cout<<manu.f.f<<' '<<manu.f.s<<' '<<manu.s<<'\n';
	fore(i, 0, co)
	{
		// cout<<"shazzam   "<<i<<'\n';
		fore(j, 0, nums[i].size())
		{
			if(i == 0)
				fro[i][j] = {dis(nums[i][j], s), 0};
			else
			{
				fro[i][j] = {MOD, 0};
				fore(k, 0, nums[i - 1].size())
					fro[i][j] = min(fro[i][j], {fin[i - 1][k].f + dis(nums[i][j], nums[i - 1][k]), k});
				// cout<<fro[i][j].f<<' '<<fro[i][j].s<<'\n';
			}
		}
		fore(j, 0, nums[i].size())
		{
			fin[i][j] = {MOD, 0};
			fore(k, 0, nums[i].size())
				fin[i][j] = min(fin[i][j], {fro[i][k].f + go(i, nums[i][j], nums[i][k]), k});
			// cout<<fin[i][j].f<<','<<fin[i][j].s<<' ';
		}
		// cout<<'\n';
	}
	pair<pair<ll, int>, int> mani{{MOD, 0}, 0};
	fore(i, 0, nums[co - 1].size())
		mani = min(mani, {fin[co - 1][i], i});
	cout<<mani.f.f<<'\n';
	vector<string> res;
	string sa;
	int toto = mani.s, ir, tutu, satoto, topo;
	int rosa = 0;
	for(int titi = co - 1; titi > -1; titi--)
	{
		int resa = 0, resb = 0, add;
		ir = fin[titi][toto].s;
		if(nums[titi].size() > 1)
		{
			vector<string> va, vb;
			swap(ir, toto);
			satoto = toto;
			
			// if(n == 2000 && s == 41) cout<<" titi  ->  "<<titi<<' '<<nums[titi][toto]<<' '<<nums[titi][ir]<<'\n';
			// fore(i, 0, nums[titi].size())
			// 	cout<<"  -->  "<<nums[titi][i]<<' '<<le[nums[titi][i]]<<' '<<ri[nums[titi][i]]<<'\n';
			while(nums[titi][toto] != le[nums[titi][ir]])
			{
				// cout<<nums[titi][toto]<<' '<<le[ir]<<' '<<' '<<nums[titi][ir]<<'\n';;
				tutu = (toto + 1) % (int)nums[titi].size();
				if(tutu > toto)
					add = nums[titi][tutu] - nums[titi][toto];
				else
					add = nums[titi][tutu] + n - nums[titi][toto];
				resa += add;
				va.pb("+" + tost(add));
				toto = tutu;
			}
			toto = satoto;
			topo = resa;
			while(toto != ir)
			{
				tutu = (toto + (int)nums[titi].size() - 1) % (int)nums[titi].size();
				if(tutu < toto)
					add = nums[titi][toto] - nums[titi][tutu] + topo;
				else
					add = nums[titi][toto] + n - nums[titi][tutu] + topo;
				resa += add;
				topo = 0;
				va.pb("-" + tost(add));
				toto = tutu;	
			}
			toto = satoto;
			while(nums[titi][toto] != ri[nums[titi][ir]])
			{
				tutu = (toto + (int)nums[titi].size() - 1) % (int)nums[titi].size();
				if(tutu < toto)
					add = nums[titi][toto] - nums[titi][tutu];
				else
					add = nums[titi][toto] + n - nums[titi][tutu];
				resb += add;
				vb.pb("-" + tost(add));
				toto = tutu;	
			}
			topo = resb;
			toto = satoto;
			while(toto != ir)
			{
				tutu = (toto + 1) % (int)nums[titi].size();
				if(tutu > toto)
					add = nums[titi][tutu] - nums[titi][toto] + topo;
				else
					add = nums[titi][tutu] + n - nums[titi][toto] + topo;
				resb += add;
				topo = 0;
				vb.pb("+" + tost(add));
				toto = tutu;	
			}
			if(resa > resb)
			{
				swap(resa, resb);
				swap(va, vb);
			}
			rosa += resa;
			reverse(all(va));
			for(auto cat : va)
				res.pb(cat);
		}
		ir = fin[titi][toto].s;

			toto = fro[titi][ir].s;
			resa = nums[titi][ir];
			if(titi == 0)
				resb = s;
			else
				resb = nums[titi - 1][toto];
			if(resa < resb)
			{
				if(resb - resa < resa + n - resb)
				{
					rosa += resb - resa;
					res.pb("-" + tost(resb - resa));
				}
				else
				{
					rosa += resa + n - resb;
					res.pb("+" + tost(resa + n - resb));
				}
			}
			else
			{
				if(resa - resb < resb + n - resa)
				{
					rosa += resa - resb;
					res.pb("+" + tost(resa - resb));
				}
				else
				{
					rosa += resb + n - resa;
					res.pb("-" + tost(resb + n - resa));	
				}
			}
	}
	reverse(all(res));
	// cout<<rosa<<'\n';
	// if(n == 2000 && s == 41) cout<<rosa<<' '<<co<<'\n';	
	fore(i, 0, res.size())
		cout<<res[i]<<'\n';
	return 0;
}

// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2		