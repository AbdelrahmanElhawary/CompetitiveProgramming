#include <bits/stdc++.h>
using namespace std;

#define long long ll
#define endl "\n"
int n,k,arr[2005];
int cum[2005];
int dp[2005][21];
int modd(int sum)
{
	int j=sum%10;
	if(j<5)
		sum-=j;
	else sum+=10-j;
	return sum;
}
int solve(int d,int last)
{
	if(d<0)
		return 1e9;
	if(last>n)
	{
		return 0;
	}
	int &ret=dp[last][d];
	if(ret!=-1)
		return ret;
	ret=1e9;
	for(int i=last;i<=n;i++)
	{
		ret=min(ret,solve(d-1,i+1)+modd(cum[i]-cum[last-1]));
	}
	return ret;
}
int main() {
std::ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		cum[i]=arr[i];
		cum[i]+=cum[i-1];
	}
	memset(dp,-1,sizeof dp);
	cout<<solve(k+1,1)<<endl;
	return 0;
}