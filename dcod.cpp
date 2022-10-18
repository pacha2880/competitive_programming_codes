#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define SZ(a) ((int)a.size())
using namespace std;
const int N=2000+10;
const LL M=3e9;
const double eps=1e-6;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
//watch out LL
LL n,h;
int main(){Accel
	cin>>n>>h;
	LL l=0,r=2e9,t;
	while(l<=r){
		LL m=l+r>>1,s;
		s=m*(m+1)/2;
		if(m>h){
			LL d=m-h;
			if(d&1)	{
				s-=(d+1)*((d+1)/2)/2;
				
			}
			else s-=(d+2)*(d/2)/2;
		}
		if(s>=n)r=m-1,t=m;else l=m+1;
	}
	cout<<t<<endl;
}