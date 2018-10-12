#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
const int mod=1e9+7;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		unordered_map<int,int>mp;
		int n; cin>>n;
		for(int i=0;i<n;i++)
		{
			int x; cin>>x;
			for(int j=2;j*j<=x;j++)
			{
				if(x%j==0)mp[j]++;
				while(x%j==0)
					x/=j;
			}
			if(x!=1)
				mp[x]++;
		}
		int ans=0;
		for(auto x:mp)
		{
			ans+=x.second/3;
			if(x.second%3)
				ans++;
		}
		cout<<ans<<endl;
	}

	return 0;
}