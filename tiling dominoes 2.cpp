#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector < ll > vl;
typedef vector< vector < ll > > mat;
const int mod=1000000007;
mat I;
mat operator*(mat X, mat Y){
	mat A;
	A.assign(4,vl());
	A[0].assign(4,0LL);
	A[1].assign(4,0LL);
	A[2].assign(4,0LL);
	A[3].assign(4,0LL);
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				A[i][j]+=(X[i][k]*Y[k][j])%mod;
				A[i][j]%=mod;
			}				
		}
	return A;
}
mat POW (mat A, ll n){
	if(n==0LL)return I;
	return POW( A*A , n/2LL) * (n%2LL==1LL?A:I);
}
int main(){
	ll n;
	while(cin>>n){
		vl B(4);
		n++;
		B[3]=5LL;B[2]=1LL;B[1]=1LL;B[0]=0LL;	
		mat A;
		A.assign(4,vl());
		A[0].assign(4,0LL);
		A[1].assign(4,0LL);
		A[2].assign(4,0LL);
		A[3].assign(4,0LL);
		I.assign(4,vl());
		I[0].assign(4,0LL);
		I[1].assign(4,0LL);
		I[2].assign(4,0LL);
		I[3].assign(4,0LL);
		I[0][0]=I[1][1]=I[2][2]=I[3][3]=1LL;
		A[0][0]=1LL;A[0][1]=5LL;
		A[0][2]=1LL;A[0][3]=mod-1LL;
		A[1][0]=A[2][1]=A[3][2]=1LL;
		mat U=POW(A,n);
		ll r=0LL;
		for(int i=0;i<4;i++){
			r+=(U[0][i]*B[i])%mod;
			r%=mod;
		}
		cout<<r<<endl;
	}
	return 0;
}