#include <bits/stdc++.h>

using namespace std;

double sa,ot,poem;
double pro[22][22],emp[22][22];
bool t;
double empa(int i, int j)
{
    if(emp[i][j]!=-1.0) return emp[i][j];
    if(i == 21) return 0;
    if(j == 21) return 0;
    if(i == 20 && j == 20) return 1;
    double val = ((i+j-1)/5)&1 ? ot : sa;
    double bef = emp[i][j];
    emp[i][j] = empa(i+1,j)*val + empa(i,j+1)*(1.0-val);
    return emp[i][j];
}
double dp(int i, int j)
{
    if(pro[i][j] != -1.0) return pro[i][j];
    if(i == 21) return 1;
    if(j == 21) return 0;
    if(i == 20 && j == 20)
    {
        if(t)
        {
            t = false;
            double prob = dp(15,15);
            cout<<prob<<endl;
            pro[20][20] = prob;
            for(int i = 0; i < 100; i++)
            {
                prob*=poem;
                pro[20][20] += prob;   
            }
            cout<<pro[20][20]<<endl;
            return pro[20][20];
        }
        else
            return 0;
    }
    double val = ((i+j-1)/5)&1 ? ot : sa;
    pro[i][j] = dp(i+1,j)*val + dp(i,j+1)*(1.0-val);
    return pro[i][j];
}

int main()
{
    int n,w,l;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        cin>>sa>>ot;   
        w = l = 0;
        for(int j = 0; j < s.size(); j++)
        {
            if(s[j] == 'W')
                w++;
            else
                l++;
            if(w == 20 && l == 20)
            {
                w = 15; l = 15;
            }
            if(w == 22 || l == 22)
                break;
        }
        if(w>21 || l>21)
            cout<<"Case "<<i<<" -1.000000\n";
        else
            if(w == 21)
                cout<<"Case "<<i<<" 1.000000\n";
            else
                if(l == 21)
                    cout<<"Case "<<i<<" 0.000000\n";
                else
                {
                    for(int i = 0;i<22;i++)
                        for(int j = 0;j<22;j++)
                        {
                            emp[i][j]=-1;
                            pro[i][j]=-1;
                        }
                    poem = empa(15,15);
                    cout<<poem<<endl;
                    t = true; 
                    cout<<"Case "<<i<<" "<<dp(w,l)<<"\n";
                }
            
    }
    return 0;
}
