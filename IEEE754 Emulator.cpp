#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/rope>
// #define int 			long long
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
#define forev(i, e, b) for(int i = e; i > b; i--)
#define forg(i, b, e, m)	for(int i = b; i < e; i+=m)
// #define index	int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
#define DBG(x) cerr<<#x<<" = "<<(x)<<endl
#define RAYA cout<<"=============================="<<'\n'
// int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}


using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

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
// template<typename T>  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order kth largest  order_of_key <
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
// rng
const int tam = 200010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF=1e100;
const double EPS = 1e-9;
float ieee754_to_float(const string& hex_str) {
    uint32_t i;
    sscanf(hex_str.c_str(), "%x", &i);
    float f;
    memcpy(&f, &i, sizeof(f));
    return f;
}

string float_to_ieee754(float value) {
    uint32_t i;
    memcpy(&i, &value, sizeof(i));
    char hex_str[9];
    sprintf(hex_str, "%08x", i);
    return string(hex_str);
}

int parse_bits_as_int(const string& hex_str, int start, int length) {
    uint32_t num;
    sscanf(hex_str.c_str(), "%x", &num);
    uint32_t mask = (1 << length) - 1;
    return (num >> (31 - start - length + 1)) & mask;
}

float bitwise_nand(float a, float b) {
    uint32_t int_a, int_b;
    memcpy(&int_a, &a, sizeof(int_a));
    memcpy(&int_b, &b, sizeof(int_b));
    uint32_t nand_result = ~(int_a & int_b);
    float result;
    memcpy(&result, &nand_result, sizeof(result));
    return result;
}

float fused_multiply_add(float a, float b, float c) {
    return fma(a, b, c);
}

float C[200010];
signed main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("asd.txt", "r", stdin);
	// freopen("qwe.txt", "w", stdout); 
	 int T;
    cin >> T;
    vector<string> results;
    while (T--) {
        string C0;
        cin >> C0;
        
        C[0] = ieee754_to_float(C0);
        
        int L;
        cin >> L;
        vector<vector<float>> lut_tables(L);
        
        for (int i = 0; i < L; i++) {
            int ki;
            cin >> ki;
            int lut_size = (1 << ki);
            lut_tables[i].resize(lut_size);
            for (int j = 0; j < lut_size; j++) {
                string lut_hex;
                cin >> lut_hex;
                lut_tables[i][j] = ieee754_to_float(lut_hex);
            }
        }
        
        int Q;
        cin >> Q;
        int current_index = 1;
        
        for (int q = 0; q < Q; q++) {
            string command;
            cin >> command;
            
            if (command == "C") {
                string hex_value;
                cin >> hex_value;
                C[current_index++] = ieee754_to_float(hex_value);
            }
            else if (command == "L") {
                int i, j, b;
                cin >> i >> j >> b;
                int index = parse_bits_as_int(C0, j, b);
                C[current_index++] = lut_tables[i][index];
            }
            else if (command == "N") {
                int i, j;
                cin >> i >> j;
                C[current_index++] = bitwise_nand(C[i], C[j]);
            }
            else if (command == "F") {
                int i, j, k;
                cin >> i >> j >> k;
                C[current_index++] = fma(C[i], C[j], C[k]);
            }
        }
        
        results.push_back(float_to_ieee754(C[current_index - 1]));
    }
    
    for (const string& result : results) {
        cout << result << "\n";
    }
    
	return 0;
}
// Se vuelve más fácil,
// cada día es un poco más fácil, pero tienes que hacerlo cada día,
// es la parte difícil, pero se vuelve más fácil.
// Crecer duele.
// La única manera de pasar esa barrera es pasándola.
// No sirve de nada hacer sacrificios si no tienes disciplina.
// Si te caes 7 veces, levántate 8.
// LA DISCIPLINA es el puente entre tus metas y tus logros.
// Las indisciplinadas son mi debilidad.
// Take a sad song and make it better.
// Ya que no se tiene información perfecta, tomar riesgos.
// Si se decide trabajar en un problema grande, empezar a hacerlo lo antes posible.
// La suerte siempre tiene su rol en las competencias y hay que vivir con eso.
