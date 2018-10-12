#include <bits/stdc++.h>
using namespace std;

#define long long ll
#define endl "\n"

int main() {
std::ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	int n; cin>>n;
	map<string,int>mp;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		mp[s]++;
	}
	int ans=0;
	for(int i=0;i<n;i++)
	{
		string s; cin>>s;
		if(mp[s])
			ans++,mp[s]--;
	}
	cout<<ans<<endl;
	return 0;
}