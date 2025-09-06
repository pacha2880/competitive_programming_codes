// System Model

// The gallery page is represented as a rectangular checkered area, k
//  cells wide, that is completely paved with photos. In this rectangle, no blank spaces are allowed. The width k
//  is either 18
// , 24
// , 30
// , 48
// , or 60
//  cells.

// There are m
//  photos in the gallery. The i
// -th photo occupies a rectangular area of ai
//  cells wide and bi
//  cells high for some integers ai
//  and bi
// . The top left cell of a photo is called its key cell.

// All photos can be enumerated by their key cells in the natural order: from top to bottom, then from left to right. Photos are divided into g
//  groups (for example, by creation date). Groups should be placed in the gallery consequently according to the above numeration: each photo of an earlier group should appear before each photo of a later group. On the other hand, photos that belong to a single group can be reordered freely within that group for better aesthetics.

// Each photo Pi
//  has ti>1
//  possible sizes along with corresponding aesthetic scores. For each possible size a×b
//  of Pi
// , the aesthetic score is a real number denoted as sia,b
// . Other sizes are not allowed. All the possible sizes are selected from the size list L
//  with 16
//  elements: 6×6
// , 9×9
// , 12×12
// , 6×12
// , 12×6
// , 6×18
// , 18×6
// , 4×12
// , 12×4
// , 6×4
// , 4×6
// , 9×6
// , 6×9
// , 9×12
// , 12×9
// , 14×6
// .

// Task

// Given the width of the gallery page and a set of grouped photos along with possible sizes and their aesthetic scores, output a layout that has a high average aesthetic score. See details in the Scoring section.

// Input
// The first line contains two integers: g
// , the number of groups, and k
// , the width of the gallery page (1≤g≤5000
// ; k∈{18,24,30,48,60}
// ). Then follows the description of g
//  groups.

// For the i
// -th group, the first line contains an integer ni
//  that indicates the number of photos in this group (1≤ni≤10000
// ). Then follow ni
//  lines, each one describing a photo in this group. Photo description starts with an integer ti,j
// , the number of available sizes of this photo (2≤ti,j≤16
// ). It is followed by ti,j
//  number triplets: width, height, and aesthetic score. Width and height are integers forming distinct pairs from the size list L
// , whereas aesthetic score is a real number between 0.0
//  and 100.0
// , with at most 10
//  digits after the decimal point.

// The size 6×6
//  is available for every photo. The sum of ni
//  for all the groups is at most 10000
//  and is divisible by k/6
// .

// Output
// Let p=∑ini
//  be the total number of photos. Print p
//  lines. The i
// -th line should contain four integers: xi
// , yi
// , wi
// , and hi
// . Here, xi
//  and yi
//  indicate the coordinates of the key cell of the i
// -th photo in the input, while wi
//  and hi
//  are the selected width and height of the photo. The x
//  coordinates go from left to right, and the y
//  coordinates go from top to bottom.



#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
#define int ll
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
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

// #pragma GCC optimization ("O2")
// #pragma GCC optimize("Ofast") si el O3 no da
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef long long 		ll;
typedef long double ld;	
typedef unsigned long long 		ull;
typedef pair<int, int>  ii;
typedef pair<pair<int, int>, int> iii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
typedef vector<vector<int>> mat;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// find_by_order kth largest  order_of_key <
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
const double PI = acos(-1); 

#include <iostream>

using namespace std;

// const int tam = 1000;

int BIT[61][30001];
int n = 60, m = 30000;
int k, g;

void update(int row, int col, int val)
{
	row++; col++;
	for (int i = row; i <= n; i += (i & -i))
	{
		for (int j = col; j <= m; j += (j & -j))
		{
			BIT[i][j] += val;
		}
	}
}

int query(int row, int col)
{
	int res = 0;
	row++; col++;
	for (int i = row; i > 0; i -= (i & -i))
	{
		for (int j = col; j > 0; j -= (j & -j))
		{
			res += BIT[i][j];
		}
	}
	return res;
}

int query(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

struct ansStruct{
    int x, y, w, h;
};
vector<ansStruct> ans;

bool checkEmpty(int x, int y, int w, int h)
{
    return query(x, y, x + w - 1, y + h - 1) == 0;
}

bool fill(int x, int y, int w, int h)
{
    if(!checkEmpty(x, y, w, h))
        return false;
    fore(i, 0, w)
        fore(j, 0, h)
            update(x + i, y + j, 1);
    return true;
}

bool checkFilled(int x, int y, int w, int h)
{
    // cout<<"query "<<x<<' '<<y<<' '<<x + w - 1<<' '<<y + h - 1<<' '<<query(x, y, x + w - 1, y + h - 1)<<'\n';
    return query(x, y, x + w - 1, y + h - 1) == w * h;
}
stack<int> maxy({0});
bool checkFinished(){
    int x = ans.back().x + ans.back().w - 1;
    int y = ans.back().y + ans.back().h - 1;
    // cout<<y<<' '<<maxy.top()<<'\n';
    // cout<<x<<' '<<k<<'\n';
    if(x != k || y != maxy.top())
        return false;
    return checkFilled(1, 1, k, maxy.top());
}



void finish(){
    for(auto cat : ans){
        cout<<cat.x<<' '<<cat.y<<' '<<cat.w<<' '<<cat.h<<'\n';
    }
    exit(0);
}

bool push(int w, int h)
{
    // find first empty with two binary searches one for y in column k
    // to find the first 0 and one for x for find the first 0 in that row
    int lo = 1, hi = maxy.top() + 1, resx = -1, resy = -1;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(checkEmpty(k, mid, 1, 1))
            hi = mid - 1, resy = mid;
        else
            lo = mid + 1;
    }
    lo = 1, hi = k;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if(checkEmpty(mid, resy, 1, 1))
            hi = mid - 1, resx = mid;
        else
            lo = mid + 1;
    }
    // cout<<"pos "<<resx<<' '<<resy<<'\n';
    if(fill(resx, resy, w, h))
    {
        ans.pb({resx, resy, w, h});
        maxy.push(max(maxy.top(), resy + h - 1));
        // if(checkFinished())
        //     finish();
        return true;
    }
    return false;

}

void pop()
{
    int x = ans.back().x, y = ans.back().y, w = ans.back().w, h = ans.back().h;
    fore(i, 0, w)
        fore(j, 0, h)
            update(x + i, y + j, -1);
    ans.pop_back();
    maxy.pop();
}



struct photoChoice{
    int w, h, score;
};

struct photo{
    vector<photoChoice> choices;
};

struct group{
    vector<photo> photos;
};

vector<group> datatec;

vector<vi> usedPhotos;
int cana = 0;
bool f(int group)
{
    cout<<"group "<<group<<'\n';
    if(cana++ == 1000)
        finish();
    if(group == g)
    {
        if(checkFinished())
            finish();
        return false;
    }
    int n = sz(datatec[group].photos);
    fore(i, 0, n)
        cout<<usedPhotos[group][i]<<' ';
        cout<<'\n';
    int can = 0;
    fore(i, 0, n)
    {
        
        if(usedPhotos[group][i])
        {
            can++;
            continue;
        }
        fore(j, 0, sz(datatec[group].photos[i].choices))
        {
            cout<<'@'<<group<<' '<<i<<' '<<j<<'\n';
            auto cat = datatec[group].photos[i].choices[j];
            if(push(cat.w, cat.h))
            {
                // cout<<"asdf"<<'\n';
                usedPhotos[group][i] = 1;
                f(group);
                
                usedPhotos[group][i] = 0;
                pop();
            }
            else
                
        }
    }
    if(can == n)
        return f(group + 1);
    return false;
}
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
    cin>>g>>k;
    usedPhotos.assign(g, vi());
    fore(i, 0, g)
    {
        int n;
        cin>>n;
        group gro;
        usedPhotos[i].assign(n, 0);
        fore(j, 0, n)
        {
            int t;
            cin>>t;
            photo pho;
            fore(l, 0, t)
            {
                int w, h;
                double sc;
                cin>>w>>h>>sc;
                pho.choices.pb({w, h, sc});
            }
            // for(auto &cat : pho.choices)
            //     cout<<cat.w<<' '<<cat.h<<' '<<cat.score<<'\n';
            // cout<<'\n';
            sort(pho.choices.begin(), pho.choices.end(), [](const photoChoice &a, const photoChoice &b){
                return a.score > b.score;
            });
            // for(auto &cat : pho.choices)
            //     cout<<cat.w<<' '<<cat.h<<' '<<cat.score<<'\n';

            // cout<<"--------------\n";
            // shuffle(all(pho.choices), rng);
            gro.photos.pb(pho);
        }
        // shuffle(all(gro.photos), rng);
        datatec.pb(gro);
    }
    f(0);
    // place first size of photo always
    // for(auto &gro : datatec)
    //     for(auto &pho : gro.photos)
    //         push(pho.choices[0].w, pho.choices[0].h)<<'\n';
    // cout<<checkFinished()<<'\n';
    // finish();
    
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasandola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Cae 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad
// Take a sad song and make it better
