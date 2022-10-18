#include <iostream>
#include <set>
#include <map>
#include <vector>
 
using namespace std;
 
 
int main()
{
    vector <map <int, int > > v;
    set<int> se;
    set<int>::iterator ii=se.begin();
    map<string,int> mp;
    int n,q;
    cin>>n>>q;
    int m[n],a=1;;
    string a1;
    for(int i=0;i<n;i++)
    {
        
        cin>>a1;
        if(mp[a1])
        {
            m[i]=mp[a1];
            se.insert(mp[a1]);
        }
        else
        {
            mp[a1]=a;
            m[i]=a;
            se.insert(a);
            a++;
        }
    }
    map<int, int>aux;
    aux[m[0]]=1;
    v.push_back(aux);
    aux.clear();
   for(int i=1;i<n;i++)
    {
    v.push_back(v[i-1]);
        v[i][m[i]]++;
 
    }
 
    while(q>0)
    {
        int a,b;
        cin>>a>>b;
        ii=se.begin();
        int k=0;
        if(a==1)
        {
            while(ii!=se.end())
            {
                if(v[b-1][*ii]>0)k++;
                ii++;
            }
        }
        else {
        while(ii!=se.end())
        {
            if(v[b-1][*ii]-v[a-2][*ii]>0)k++;
            ii++;
        }
        }
        cout<<k<<endl;
 
        q--;
    }
    se.clear();
    v.clear();
    return 0;
}