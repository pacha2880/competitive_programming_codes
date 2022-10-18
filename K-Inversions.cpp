	#include <bits/stdc++.h>
#define PI 			acos(-1)
#define mp			make_pair
#define pb			push_back
#define all(a)		(a).begin(), (a).end()
#define srt(a)			sort(all(a))
#define mem(a, h)	memset(a, (h), sizeof(a))
#define f 			first
#define s 			second
#define MOD			1000000007
int in(){int r=0,c;for(c=getchar();c<=32;c=getchar());if(c=='-') return -in();for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar());return r;}

using namespace std;

typedef long long 		ll;
typedef pair<int, int>  ii;
typedef vector<int>     vi;
typedef vector<ii>      vii;
typedef complex<double> cd;
typedef vector<ll>      vll;
double mul;
vector<cd> fft(vector<cd> a)
{
	int n = a.size();
	if(n == 1) return a;
	cd w = 1;
	double theta = 2.0 * acos(-1) / (double)n;
	cd wn = cd(cos(theta), mul*sin(theta));
	vector<cd> aEven(n/2), aOdd(n/2), y(n);
	for(int i = 0; i<n/2;i++)
	{
		aEven[i] = a[i*2];
		aOdd[i] = a[i*2+1];
	}
	aEven = fft(aEven);
	aOdd = fft(aOdd);
	for(int i=0;i<n/2;i++)
	{
		y[i] = aEven[i] + w*aOdd[i];
		y[n/2+i] = aEven[i] -w*aOdd[i] ;
		w*=wn;
	}
	return y;

}
vector<cd> fftMul(vector<cd> A, vector<cd> B)
{
	int n = 2*A.size();
	while(__builtin_popcount(n) > 1) n+=(n&-n);
	while(A.size()<n) {A.push_back(0); B.push_back(0);}

	mul = 1;
	A = fft(A);
	B = fft(B);
	for(int i=0;i<n;i++)
		A[i] = B[i]*A[i];
	mul = -1;
	A = fft(A);
	for(int i=0;i<n;i++)
		A[i]/=(cd)n;
	return A;
}
int main()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	string a;
	cin>>a;
	int n = a.size();
	vector<cd> A,B;
	A.assign(n,0);
	B.assign(n,0);
	for(int i=0;i<n;i++)
	{
		if(a[i]=='A')
			A[i]=1;
		else
			B[n-i-1]=1;
	}
	A = fftMul(A,B);
	for(int i=n;i<2*n-1;i++)
		cout<<(int)round(real(A[i]))<<'\n';
	return 0;
}