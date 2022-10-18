#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e4 + 50;
char s1[maxn << 1],s2[maxn];
int n ,ans,f[15],use[15];
vector < int > pos[5] , ano[5];

const double PI = acos(-1.0);
//复数结构体
struct Complex
{
    double r,i;
    Complex(double _r = 0.0,double _i = 0.0)
    {
        r = _r; i = _i;
    }
    Complex operator +(const Complex &b)
    {
        return Complex(r+b.r,i+b.i);
    }
    Complex operator -(const Complex &b)
    {
        return Complex(r-b.r,i-b.i);
    }
    Complex operator *(const Complex &b)
    {
        return Complex(r*b.r-i*b.i,r*b.i+i*b.r);
    }
};
/*
 * 进行FFT和IFFT前的反转变换。
 * 位置i和 （i二进制反转后位置）互换
 * len必须去2的幂
 */
void change(Complex y[],int len)
{
    int i,j,k;
    for(i = 1, j = len/2;i < len-1; i++)
    {
        if(i < j)swap(y[i],y[j]);
        //交换互为小标反转的元素，i<j保证交换一次
        //i做正常的+1，j左反转类型的+1,始终保持i和j是反转的
        k = len/2;
        while( j >= k)
        {
            j -= k;
            k /= 2;
        }
        if(j < k) j += k;
    }
}
/*
 * 做FFT
 * len必须为2^k形式，
 * on==1时是DFT，on==-1时是IDFT
 */
void fft(Complex y[],int len,int on)
{
    change(y,len);
    for(int h = 2; h <= len; h <<= 1)
    {
        Complex wn(cos(-on*2*PI/h),sin(-on*2*PI/h));
        for(int j = 0;j < len;j+=h)
        {
            Complex w(1,0);
            for(int k = j;k < j+h/2;k++)
            {
                Complex u = y[k];
                Complex t = w*y[k+h/2];
                y[k] = u+t;
                y[k+h/2] = u-t;
                w = w*wn;
            }
        }
    }
    if(on == -1)
        for(int i = 0;i < len;i++)
            y[i].r /= len;
}

int len = 131072;

Complex X[131075],Y[131075];

int ret[5][5][maxn];

void predeal(){
    for(int i = 0 ; i < 5 ; ++ i)
        for(int j = 0 ; j < 5 ; ++ j){
            memset( X , 0 , sizeof( X ) );
            memset( Y , 0 , sizeof( Y ) );
            int x = i , y = j;
            for(auto it : pos[i]) X[it+1].r++;
            for(auto it : ano[y]) Y[n-it].r++;
            fft( X , len , 1 );
            fft( Y , len , 1 );
            for(int j = 0 ; j < len ; ++ j) X[j] = X[j] * Y[j];
            fft( X , len , -1 );
            for(int k = n + 1 ; k <= 2 * n ; ++ k) ret[i][j][k - n] += (int)(X[k].r + 0.5);
        }
}

void cal_ans(){
    for(int i = 1 ; i <= n ; ++ i){
        int sum = 0;
        for(int j = 0 ; j < 5 ; ++ j)
            sum += ret[j][f[j]][i];
        ans = max( ans , sum );
    }
}

void DFS( int x ){
    if( x == 5 ){
        cal_ans();
    }else{
        for(int i = 0 ; i < 5 ; ++ i)
            if(!use[i]){
                f[x] = i;
                use[i] = 1;
                DFS( x + 1 );
                use[i] = 0;
            }
    }
}

int main( ){
  
    scanf("%s%s",s1,s2);
    n=strlen(s1);
    for(int i = 0 ; i < n ; ++ i) s1[i + n] = s1[i];
    for(int i = 0 ; i < (n * 2) ; ++ i) pos[s1[i] - 'A'].push_back( i );
    for(int i = 0 ; i < n ; ++ i) ano[s2[i] - 'a'].push_back( i );
    predeal();
    DFS( 0 );
    printf("%d\n",n-ans);
    return 0;
}