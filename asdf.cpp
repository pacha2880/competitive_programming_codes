#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> ar(n);
	for(int i = 0; i < n; i++) cin>>ar[i];
	int m;
	cin>>m;
	vector<int> br(m);
	for(int i = 0; i < m; i++) cin>>br[i];
	int con = 0;
	for(int i = 0; i < n; i++)
	{
		if(ar[i] == br[i])
		{
			bool bo = false;
			for(int j = 0; j < n; j++)
			{
				if(j != i && br[j] != ar[i] && br[i] != ar[j])
				{
					swap(ar[i], ar[j]), con += i + j;
					bo = true;
					break;
				}
			}
			if(!bo)
			{
				cout<<-1<<'\n';
				return 0;
			}
		}
	}
	cout<<con<<'\n';
	return 0;
}
