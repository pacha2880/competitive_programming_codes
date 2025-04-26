#include <bits/stdc++.h>
// comentar esto si no quieren usar ordered set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// comentar esto si no quieren usar ordered set
#define mp              make_pair
#define pb              push_back
#define all(a)          (a).begin(), (a).end()
#define sz(a)           (int)a.size()
#define eq(a, b)        (fabs(a - b) < EPS)
#define md(a, b)        ((a) % b + b) % b
#define mod(a)          md(a, MOD)
#define srt(a)          sort(all(a))
#define mem(a, h)       memset(a, (h), sizeof(a))
#define f               first
#define s               second
#define forn(i, n)          for(int i = 0, dfr = n; i < dfr; i++)
#define fore(i, b, e)   for(int i = b, asdz = e; i < asdz; i++)
#define forg(i, b, e, m)    for(int i = b, asdz = e, frz = m; i < asdz; i+=frz)
#define index   int mid = (b + e) / 2, l = node * 2 + 1, r = l + 1;
//int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}
//sort(all(v), [](int a, int b){ return a > b; });
 
 
using namespace std;
// comentar esto si no quieren usar ordered set
using namespace __gnu_pbds;
// comentar esto si no quieren usar ordered set
 
typedef long long       ll;
typedef long double ld; 
typedef unsigned long long      ull;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef vector<ll>      vll;
// comentar esto si no quieren usar ordered set
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
// comentar esto si no quieren usar ordered set
//find_by_order kth largest  order_of_key <
const int tam = 100010;
const int MOD = 1000000007;
const int MOD1 = 998244353;
const double EPS = 1e-9;
const double PI = acos(-1); 
 
int main()
{
    // ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //freopen("asd.txt", "r", stdin);
    //freopen("qwe.txt", "w", stdout);
 
    //pair
    cout<<"pair\n";
    pair<int, int> a(3, 4), b;
    b.first = 3;
    b.s = 5;
    b = make_pair(1, 100);
    b = {3, 4};
    b = mp(1, 4);
    pair<pair<int, int>, pair<int, int>> asdf;
    pair<string, int> ad = mp("asdf", 1);
    asdf = mp(mp(2, 3), mp(3, 4));
    asdf = {{2, 3}, {3, 4}};
    asdf.f.f = 1;
    cout<<(a == b)<<'\n';
 
    //vector
    cout<<"vector\n";
    vector<int> v({1,2,3});
    vi v1(v.begin(), v.begin() + 2);
    // set<int> st;
    // v1 = vector<int>(st.begin(), st.end());
    v.push_back(3);
    v.push_back(4);
    v[0] = -100;
    v.pb(5);
    v.pb(10);
    v.pop_back();
    for(int i = 0; i < (int)v.size(); i++)
        cout<<v[i]<<'\n';
    // for each
    for(int &x : v)
        cout<<++x<<'\n';
    for(int x : v)
        cout<<++x<<'\n';
    for(int x : v)
        cout<<x<<'\n';
 
    cout<<"tamanioo "<<v.size()<<' ';
    v.pop_back();
    cout<<v.size()<<'\n';
    cout<<v.back()<<'\n';
 
    pair<int, int> par[] = {mp(1, 2), mp(2, 3), mp(1, 1), mp(0, 5)};
    vii ar(par, par + 4);
    for(int i = 0; i < 4; i++)
        ar.pb(par[i]);
 
    sort(ar.begin(), ar.end());
    // sort(par, par + 4);
    reverse(all(ar));
    for(auto x : ar)
        cout<<x.f<<' '<<x.s<<'\n';
    cout<<"sort parcial de arreglo\n";
    sort(par + 1, par + 4);
    fore(i, 0, 4)
        cout<<par[i].f<<' '<<par[i].s<<'\n';
 
 
    // stack
    // FILO
    // First In Last Out
    cout<<"stack\n";
    stack<int> st;
    st.push(123);
    st.push(12);
    st.push(3);
    cout<<st.top()<<'\n';
    st.pop();
    cout<<st.top()<<'\n';
    // esto igual da con vector, solo que usar
    // back y pop_back
    while(!st.empty())
    {
        cout<<st.top()<<'\n';
        st.pop();
    }
 
    //queue
    // FIFO
    // First In First Out
    cout<<"queue\n";
    queue<int> que;
    que.push(123);
    que.push(12);
    que.push(3);
    cout<<que.front()<<'\n';
    que.pop();
    cout<<que.front()<<'\n';
    while(!que.empty())
    {
        cout<<que.front()<<'\n';
        que.pop();
    }
 
    //dequeue bicola
    cout<<"dequeue\n";
    deque<int> deq;
    // 6,3,123,12,5
    deq.push_front(123);
    deq.push_back(12);
    deq.push_front(3);
    deq.push_back(5);
    deq.push_front(6);
    fore(i, 0, deq.size())
        cout<<deq[i]<<',';
    cout<<'\n';
    cout<<deq.front()<<'\n';
    cout<<deq.back()<<'\n';
    deq.pop_front();
    cout<<deq.front()<<'\n';
    cout<<deq.back()<<'\n';
    deq.pop_back();
    cout<<deq.front()<<'\n';
    cout<<deq.back()<<'\n';
    fore(i, 0, deq.size())
        cout<<deq[i]<<',';
    cout<<'\n';
    while(!deq.empty())
    {
        cout<<deq.front()<<'\n';
        deq.pop_front();
    }
 
 
    // logaritmicos
    //queue
    cout<<"priority queue\n";
 
    //priority_queue<int, vector<int>, std::greater<int> > pque; orden inverso
    priority_queue<int> pque;
    pque.push(12);
    pque.push(4);
    pque.push(2);
    pque.push(1);
    pque.push(4);
    pque.push(13);
    pque.push(10);
    cout<<pque.top()<<'\n';
    pque.pop();
    cout<<pque.top()<<'\n';
    while(!pque.empty())
    {
        cout<<pque.top()<<'\n';
        pque.pop();
    }
 
    //set
    //representa un conjunto ordenado
    cout<<"set\n";
    set<int> st1;
    st1.insert(1);
    st1.insert(2);
    st1.insert(4);
    st1.insert(2);
    st1.insert(4);
    st1.insert(3);
    st1.insert(-123);
    st1.insert(23);
    cout<<st1.size()<<'\n';
    for(int x : st1)
        cout<<x<<',';
    cout<<'\n';
    cout<<st1.count(23)<<'\n';
    // cout<<st1.find(23) != st1.end()<<'\n';
    cout<<st1.count(0)<<'\n';
    st1.erase(4);
    // borrar en multiset
    // st.erase(st.find(4));
    st1.erase(st1.upper_bound(1));
    st1.erase(st1.begin());
    for(auto it = st1.begin(); it != st1.end(); it++)
        cout<<*it<<',';
    // ultimo elemento
    // auto it = st.end();
    // it--;
    // auto it1 = --st.end();
    cout<<'\n';
    cout<<(st1.find(3) == st1.end())<<'\n';
    cout<<(st1.find(123132) == st1.end())<<'\n';
    // upper_bound -> iterador(caminante) al primer elemento mayor a
    // lower_bound -> iterador(caminante) al primer elemento mayor o igual a
    cout<<*st1.upper_bound(3)<<'\n';
    cout<<*st1.lower_bound(3)<<'\n';
 
    //set
    // conjunto desordenado
    // no es logn este usa una tabla hash
    // complejidad es constante pero tiene su factor constate
    cout<<"unordered set\n";
    unordered_set<int> st2;
    st2.insert(1);
    st2.insert(2);
    st2.insert(4);
    st2.insert(2);
    st2.insert(4);
    st2.insert(3);
    st2.insert(-123);
    st2.insert(23);
    cout<<st2.size()<<'\n';
    for(int x : st2)
        cout<<x<<',';
    cout<<'\n';
    cout<<st2.count(23)<<'\n';
    cout<<st2.count(0)<<'\n';
    st2.erase(4);
    for(auto it1 = st2.begin(); it1 != st2.end(); it1++)
        cout<<*it1<<',';
    cout<<'\n';
    cout<<(st2.find(3) != st2.end())<<'\n';
    cout<<(st2.find(123132) != st2.end())<<'\n';
 
    // map
    cout<<"mapa\n";
    map<int, int> ma;
    ma[-1] = 2;
    ma[100000000] = 5;
    ma[3] = 4;
    for(ii cat : ma)
        cout<<cat.f<<' '<<cat.s<<'\n';
    // map<int, int>::iterator it2;
    auto it2 = ma.upper_bound(-1);
    cout<<it2->first<<' '<<it2->s<<'\n';
    for(it2 = ma.begin(); it2 != ma.end(); it2++)
        cout<<it2->first<<','<<(*it2).second<<' ';
    cout<<'\n';
 
    // unorderedmap
    cout<<"unordered ma1pa\n";
    unordered_map<int, int> ma1;
    ma1[-1] = 2;
    ma1[100000000] = 5;
    ma1[3] = 4;
    for(ii cat : ma1)
        cout<<cat.f<<' '<<cat.s<<'\n';
 
 
    //ordered set
    // un poco mas lento que el set
    // pero tiene 2 metodos bonitos
    cout<<"ordered set\n";
    ordered_set st3;
    st3.insert(1);
    st3.insert(2);
    st3.insert(4);
    st3.insert(2);
    st3.insert(4);
    st3.insert(3);
    st3.insert(-123);
    st3.insert(23);
    cout<<st3.size()<<'\n';
    for(int x : st3)
        cout<<x<<',';
    cout<<'\n';
    //find_by_order kth largest  order_of_key <
    cout<<*st3.find_by_order(0)<<'\n';
    cout<<*st3.find_by_order(4)<<'\n';
    cout<<*st3.find_by_order(3)<<'\n';
    cout<<*st3.find_by_order(2)<<'\n'<<'\n';;
    // cuantos valores hay menores a
    cout<<st3.order_of_key(-5)<<endl;
    cout<<st3.order_of_key(10)<<endl;
    cout<<st3.order_of_key(4)<<endl;
    cout<<st3.order_of_key(2)<<endl;
    return 0;
}
 
// read the question correctly (is y a vowel? what are the exact constraints?)
// look out for SPECIAL CASES (n=1?) and overflow (ll vs int?) ARRAY OUT OF BOUNDSS2    