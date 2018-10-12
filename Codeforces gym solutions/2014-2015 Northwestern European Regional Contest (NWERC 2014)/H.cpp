#include <bits/stdc++.h>
using namespace std;

#define long long ll
#define endl "\n"
vector<vector<int> >adj;
pair<int,int>freq[10005];
int c=2;
bool vis[10005];
void dfs(int u,int par=-1,bool f=0)
{
	freq[u].second=c++;
	for(int i=0;i<adj[u].size();i++)
	{
		int e=adj[u][i];
		if(e==par)continue;
		if(!f)
		{
			f=1;
			freq[e].first=freq[u].first;
			dfs(e,u,1);
		}
		else {
			freq[e].first=freq[u].second;
			dfs(e,u,1);
		}
	}
}
int main() {
std::ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	int n; cin>>n;
	adj.resize(n+1);
	int root=-1;
	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		if(adj[u].size()>1&&root==-1)
			root=u;
		if(adj[v].size()>1&&root==-1)
			root=v;
	}
	if(root==-1)
	{
		cout<<"23 42\n";
		cout<<"42 23\n";
		return 0;
	}
	freq[root].first=1;
	dfs(root,-1);
	for(int i=1;i<=n;i++)
		cout<<freq[i].first<<" "<<freq[i].second<<endl;
	return 0;
}