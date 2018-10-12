#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll dp[250][250];
int solve(int rem,int xo)
{
	if(rem==0)
	{
		return xo!=0;
	}
	ll &ret=dp[rem][xo];
	if(ret!=-1)
		return ret;
	ret=0;
	for(int i=1;i<=rem;i++)
	{
		ret+=solve(rem-i,xo^i);
		ret%=mod;
	}
	return ret%mod;


}
int main() {
	int t;
	memset(dp,-1,sizeof dp);
	cin>>t;
	while(t--)
	{
		int n; cin>>n;
		cout<<solve(n,0)<<endl;
	}

	return 0;
}