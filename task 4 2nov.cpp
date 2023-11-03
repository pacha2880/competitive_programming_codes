#include <bits/stdc++.h>
using namespace std;

long long getMinDifference(int n, int e1, int t1, int e2, int c) {
    long long dif = 0;
    long long e = 0;
    long long cand = 100000000000ll;
    while(n--)
    {
        if(e >= e2)
        {
            cand = min(abs(dif - (c + e - 1) / e + n * t1), cand);
            if(abs(dif - (c + e - 1) / e) < abs(dif + t1))
            {
                dif -= (c + e - 1) / e;
                e -= e2;
            }
            else
            {
                e += e1;
                dif += t1;
            }
        }
        else
        {
            e += e1;
            dif += t1;
        }
    }
    return min(abs(dif), cand);
}

int main()
{
    cout<<getMinDifference(6, 20, 20, 4, 5)<<'\n';
    cout<<getMinDifference(5, 2, 3, 4, 5)<<'\n';
    cout<<getMinDifference(4, 1, 2, 1, 100)<<'\n';
    cout<<getMinDifference(6, 20, 2, 2, 100)<<'\n';
    cout<<getMinDifference(6, 2, 10, 2, 100)<<'\n';
	return 0;
}
