#include <iostream>

using namespace std;

int main()
{

    int n;
    cin>>n;
    string ars[2*n-2];
    int ma1=-1,ma2;
    for(int i = 0; i<2*n-2;i++)
    {
        cin>>ars[i];
        if(ars[i].size()==n-1)
        {
            if(ma1==-1)
                ma1=i;
            else ma2=i;
        }
    }
    bool pre=true,un;
    char ar[2*n-2];
    for(int i=0;i<2*n-2;i++)
        ar[i]='P';    
        ar[ma1]='S';
    for(int j=1;j<n-1;j++)
    {
        un = false;
        for(int i=0; i<2*n-2;i++)
        {
            if(i!=ma1){
            if(ars[i].size() == n-1-j )
            {
                if(ars[i]== ars[ma1].substr(j))
                {
                        ar[i]='S';
	                    i = 100000;
                }
	            else
	            {
	                if(un)
	                {
	                    pre = false;
	                    j = 10000000;
	                }
	                un =true;
	            }
            }
            }
        }
    }
    if(pre)
    {
        for(int i = 0; i<n; i++)
        {
            if(ar[i]=='P')
                if(ars[i]!=ars[ma2].substr(0,ars[i].size()))
                {
                    pre=false;
                    i=10000000;
                }
        }
    if(pre){
    for(int i=0;i<2*n-2;i++)
        cout<<ar[i];
}
    }
    if(!pre){
    for(int i=0;i<2*n-2;i++)
        ar[i]='P';
        ar[ma2]='S';
    for(int j=1;j<n-1;j++)
    {
        un = false;
        for(int i=0; i<2*n-2;i++)
        {
            if(i!=ma2){
            if(ars[i].size() == n-j-1)
            {
                if(ars[i]== ars[ma2].substr(j))
                {
                        ar[i]='S';
                	i=1000000;
                }
	            else
	            {
	                if(un)
	                {
	                    pre = false;
	                    i = 100000;
	                    j = 10000000;
	                }
	                un = true;
	            }
            }
            }
        }
    }
        
    for(int i=0;i<2*n -2;i++)
        cout<<ar[i];
    }
    return 0;
}