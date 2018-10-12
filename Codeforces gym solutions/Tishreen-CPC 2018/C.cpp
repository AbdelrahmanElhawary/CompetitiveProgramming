#include <bits/stdc++.h>
using namespace std;
int grid[102][102];
int main() {
	int t; cin>>t;
	while(t--)
	{
		memset(grid,0,sizeof grid);
		int n,m,k;
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>grid[i][j];
				grid[i][j]+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				for(int ii=n;ii>=i;ii--)
				{
					for(int jj=m;jj>=j;jj--)
					{
						if(grid[ii][jj]-grid[i-1][jj]-grid[ii][j-1]+grid[i-1][j-1]>k)
							continue;
						int area=(ii-i+1)*(jj-j+1);
						ans=max(ans,area);
						break;
					}
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}