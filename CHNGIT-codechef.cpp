#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;

		int a[n];
		int b[1000]={0};
		int max=0;

		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			b[a[i]]++;

			if(b[a[i]]>max)
			{
				max=b[a[i]];
			}
		}

		cout<<n-max<<"\n";

	}

	return 0;
}
