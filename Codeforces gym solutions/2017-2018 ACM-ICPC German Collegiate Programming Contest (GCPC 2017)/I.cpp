#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
int n,m;
vector<int>v;
ll dp[300005];
ll solve(int ind)
{
	if(ind>=n)
		return 0;
	ll &ret=dp[ind];
	if(ret!=-1)
		return ret;
	ret=solve(ind+m)+v[ind];
	for(int i=ind+1;i<min(n,ind+m);i++)
	{
		ret=max(ret,solve(i));
	}
	return ret;
}
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m;
	v.resize(n);
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;i++)
		cin>>v[i];
	cout<<solve(m)<<endl;
}