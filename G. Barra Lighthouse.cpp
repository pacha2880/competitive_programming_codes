#include <bits/stdc++.h>
#define PI          acos(-1)
#define eps       1e-9
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cout<<fixed<<setprecision(20);
    long double x, al, t, d;
    cin>>n>>x>>al>>t>>d;
    al*=PI/180.0;
    long double rep = al/(2.0*PI)*t, med = al/2.0
            , ini = 0, in, fi,an;
    while(x > t - eps)
    {
        ini += 1.0;
        x -= t;
    }
    ini *= rep;
    x = x/t*2.0*PI;
    fi = x+med, in = x-med;
    long double a,b;
    for(int i = 0; i < n; i++)
    {
        cin>>a>>b;
        //cout<<'@';
        if(hypot(a,b) < d+eps)
        {
            an = atan2(b,a);
            if(an < -eps)
                an += 2.0*PI;
            if(an > med-eps)
            {
                if(an < in +eps)
                {
                    cout<<fabs((double)(ini+rep))<<'\n';
                }
                else
                    if(an < fi + eps)
                        cout<<fabs((double)(ini + (fi-an)*t/(2.0*PI)))<<'\n';
                    else
                        cout<<fabs((double)(ini))<<'\n';
            }
            else
            {
                cout<<fabs((double)(min(an+med, fi-med)*t/(2.0*PI)))<<'\n';
            }
        }
        else
            cout<<0<<'\n';
    }

    return 0;
}