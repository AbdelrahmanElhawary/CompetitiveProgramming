#include <bits/stdc++.h>
using namespace std;
int ar[5001];
int dp[5001][5001];
int n;
int solve(int cur,int end)
{
	if(end <=cur ){
		return 0;
	}
//	cout<<cur<<" "<<end<<endl;
	int &ret=dp[cur][end];
	if(ret!=-1)
		return ret;
	ret =0;
    if(ar[cur] == ar[end]){
		ret =max(ret,1 + solve(cur+1,end-1));
	}
	ret=max(ret,solve(cur+1,end));
	ret = max(ret,solve(cur,end-1));
	
	return ret;
}
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//cin>>n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dp,-1,sizeof dp);
		for(int i=0;i<n;i++){
			scanf("%d",&ar[i]);
		}
		printf("%d\n",solve(0,n-1));
	}

	return 0;
}