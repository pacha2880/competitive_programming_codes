#include <bits/stdc++.h>

using namespace std;
typedef complex<double> cd;
double mul;
vector<cd> fft(vector<cd> a)
{
    int n = a.size();
    if(n == 1) return a;
    double theta = 2.0*acos(-1)/(double)n;
    cd w = 1, wn = cd(cos(theta), mul*sin(theta));
    vector<cd> aEven(n/2), aOdd(n/2);
    for(int i=0;i<n/2;i++)
    {
        aEven[i] = a[i*2];
        aOdd[i] = a[i*2+1];
    }
    aEven = fft(aEven);
    aOdd = fft(aOdd);
    for(int i=0;i<n/2;i++)
    {
        a[i] = aEven[i] + w*aOdd[i];
        a[n/2+i] = aEven[i] - w*aOdd[i];
        w*=wn;
    }
    return a;
}
vector<cd> ffMul(string s, char ch)
{
    int n = s.size()*2, m = s.size();
    while(__builtin_popcount(n)>1) n+= (n& -n);
    vector<cd> a(n,0);
    vector<cd> b(n,0);
    for(int i=0;i<m;i++)
    {
        if(s[i]==ch)
        {
            a[i]=1;
            b[m-i-1]=1;
        }
    }
    mul = 1;
    a = fft(a);
    b= fft(b);
    for(int i=0;i<n;i++)
        a[i]=a[i]*b[i];
    mul = -1;
    a = fft(a);
    for(int i=0;i<n;i++)
        a[i]/=n;
    return a;
}
int main()
{
    string a;
    cin>>a;
    vector<cd> fa;
    vector<cd> fb;
    vector<cd> fc;
    fa = ffMul(a,'a');
    fb = ffMul(a,'b');
    fc = ffMul(a,'c');
    int n = a.size();
    long long sum[n],maxi = 0;
    for(int i = n;i < 2*n; i++)
    {
        sum[i-n]= (long)round(real(fa[i]))+(long)round(real(fb[i]))+(long)round(real(fc[i]));
        maxi = max(maxi,sum[i-n]);
    }
    cout<<maxi<<endl;
    bool t = false;
    for(int i=n;i<2*n;i++)
        if(sum[i-n]==maxi)
        {
            if(t) cout<<" ";
            t=true;
            cout<<i-n+1;
        }
    return 0;
}