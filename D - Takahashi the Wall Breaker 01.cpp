#include<bits/stdc++.h>
#include <cmath>
#define clr(a,h) memset(a, (h), sizeof(a))
#define ll long long
using namespace std;

void init_code(){
    #ifndef ONLINE_JUDGE   
    freopen("in.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
const int N = 1010;
ll n,m;
char mat[N][N];
ll costo[N][N];
ll way[N][N];
ll vis[N][N];
ll x[4] = {1,0,-1,0};
ll y[4] = {0,1,0,-1};
bool ok(ll i, ll j){
 if(i < 0 or i >=n or j < 0 or j >= n){
  return false;
 }
 return true;
}
void bfs(ll xx, ll yy){
 vis[xx][yy] = 1;
 costo[xx][yy] = 0;
 way[xx][yy] = 0; //0 es gratis, 1 es patada
 deque<pair<ll,ll>>q;
 q.push_front({xx,yy});
 while(!q.empty()){
  pair<ll,ll> p = q.front();
  q.pop_front();
  vis[p.first][p.second] = 1;
  for (int i = 0; i < 4; ++i)
  {  
   ll ii = x[i] + p.first;
   ll jj = y[i] + p.second;
   if(ok(ii,jj)){ 
    if(mat[ii][jj] == '#'){
     if(mat[p.first][p.second] == '.'){
      if(costo[p.first][p.second]+1 < costo[ii][jj]){
       costo[ii][jj] = min(costo[ii][jj], costo[p.first][p.second]+1);
       q.push_back({ii,jj});
      }
      ii += x[i];
      jj += y[i];
      if(costo[p.first][p.second]+1 < costo[ii][jj]){
       costo[ii][jj] = min(costo[ii][jj], costo[p.first][p.second]+1);
       q.push_back({ii,jj});
      }
     }
    }
    else{
     if(costo[p.first][p.second] < costo[ii][jj]){
      costo[ii][jj] = min(costo[ii][jj], costo[p.first][p.second]);
      q.push_front({ii,jj});
     }
     
    }    
   }
  }
 }
 
}
int main() {
    init_code();
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    { 
     for (int j = 0; j < m; ++j)
     {
      cin >> mat[i][j];
      costo[i][j] = 1e9;
     }
   }

    for (int i = 0; i < n; ++i)
    { 
     for (int j = 0; j < m; ++j)
     {
      cout << mat[i][j];
     }
     cout <<"\n";
   }
   ll a,b,c,d;
   cin>>a>>b>>c>>d; 
   bfs(a,b);
   cout << costo[c][d]<< "\n";
   // for (int i = 0; i < n; ++i)
    // { 
    //  for (int j = 0; j < m; ++j)
    //  {
    //   if(costo[i][j] == 1e9){
    //    cout << "x ";
    //   }
    //   else{
    //    cout << costo[i][j] << " ";
    //   }
    //  }
    //  cout <<"\n";
   // }
    return 0;
}
/*
Un mono con un teclado, yo soy el mono.
Quien tiene un porqué para vivir puede soportar casi cualquier cómo.
Dios, si debo pasar frío, entonces, por favor, quítame el deseo de sentir calor.
*/