#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int arr[200005];
int mp[200005];
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while(cin>>n){
	for(int i=1;i<=n;i++)
	{
		cin>>arr[i];
		mp[arr[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(arr[i]!=i)
		{
			int temp=arr[i];
			swap(arr[i],arr[mp[i]]);
			mp[temp]=mp[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	}

	return 0;
}