#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int ll
#define mp				make_pair
#define pb				push_back
#define all(a)			(a).begin(), (a).end()
#define sz(a)			(int)a.size()
#define eq(a, b)     	(fabs(a - b) < EPS)
#define md(a, b)		((a) % b + b) % b
#define mod(a)			md(a, MOD)
#define _max(a, b) ((a) > (b) ? (a) : (b))
#define srt(a)			sort(all(a))
#define mem(a, h)		memset(a, (h), sizeof(a))
#define f 				first
#define s 				second
#define forn(i, n)			for(int i = 0; i < n; i++)
#define fore(i, b, e)	for(int i = b; i < e; i++)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
#define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cerr<<"=============================="<<endl
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

int con[tam];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout);
    int t;
    cin>>t;
    vector<char> inverse(500);
    inverse['<'] = '>';
    inverse['>'] = '<';
    inverse['('] = ')';
    inverse[')'] = '(';
    inverse['\\'] = '/';
    inverse['/'] = '\\';
    inverse[' '] = ' ';
    while(t--)
    {
        string head = " o ";
        string torso = "/|\\";
        string legs = "/ \\";
        int n;
        cin>>n;
        int orientation = 1;
        while(n--)
        {
            string s;
            cin>>s;
            if(s == "right" && !orientation || s == "left" && orientation)
            {
                string part, ins;
                cin>>part;
                if(part == "hand")
                {
                    cin>>ins>>ins;
                    if(ins == "head")
                    {
                        head[2] = ')';
                        torso[2] = ' ';
                    }
                    if(ins == "hip")
                    {
                        head[2] = ' ';
                        torso[2] = '>';
                    }
                    if(ins == "start")
                    {
                        head[2] = ' ';
                        torso[2] = '\\';
                    }
                }
                if(part == "leg")
                {
                    cin>>ins;
                    if(ins == "in")
                        legs[2] = '>';
                    else
                        legs[2] = '\\';
                }
            }
            if(s == "left" && !orientation || s == "right" && orientation)
            {
                string part, ins;
                cin>>part;
                if(part == "hand")
                {
                    cin>>ins>>ins;
                    if(ins == "head")
                    {
                        head[0] = '(';
                        torso[0] = ' ';
                    }
                    if(ins == "hip")
                    {
                        head[0] = ' ';
                        torso[0] = '<';
                    }
                    if(ins == "start")
                    {
                        head[0] = ' ';
                        torso[0] = '/';
                    }
                }
                if(part == "leg")
                {
                    cin>>ins;
                    if(ins == "in")
                        legs[0] = '<';
                    else
                        legs[0] = '/';
                }
            }
            if(s == "turn")
            {
                orientation = !orientation;
                swap(head[0], head[2]);
                swap(torso[0], torso[2]);
                swap(legs[0], legs[2]);
                head[0] = inverse[head[0]];
                head[2] = inverse[head[2]];
                torso[0] = inverse[torso[0]];
                torso[2] = inverse[torso[2]];
                legs[0] = inverse[legs[0]];
                legs[2] = inverse[legs[2]];
            }
            if(s == "say")
            {
                // read rest of line
                string line;
                getline(cin, line);
                cout<<line<<endl;
            }
            else
            {
                cout<<head<<'\n'<<torso<<'\n'<<legs<<'\n';
            }
        }
    }
	return 0;
}

// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
