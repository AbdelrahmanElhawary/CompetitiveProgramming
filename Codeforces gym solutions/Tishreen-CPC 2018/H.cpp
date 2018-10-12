#include <bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int n,a,b;
int lvl[100005];
ll sub[100005];
vector<vector<int>>adj;
ll dfs1(int u=a,int lv=1,int par=-1)
{
	lvl[u]=lv;
	sub[u]=1;
	for(auto v:adj[u])
	{
		if(v!=par)
			sub[u]+=dfs1(v,lv+1,u);
	}
	return sub[u];
}
ll dfs2(int u=b,int e=b,int par=-1)
{
	int x;
	if(lvl[u]<lvl[e])
		x=u; else x=e;
	ll ret=n-sub[x];
	for(auto v:adj[u])
	{
		if(v!=par&&v!=a)
			ret+=dfs2(v,x,u);
	}
	return ret;
}
int main() {
      std::ios_base::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);
     int t; cin>>t;
     while(t--)
     {
    	 adj.clear();
    	 cin>>n>>a>>b;
    	 adj.resize(n+10);
    	 for(int i=1;i<n;i++)
    	 {
    		 int u,v;
    		 cin>>u>>v;
    		 adj[u].push_back(v);
    		 adj[v].push_back(u);
    	 }
    	 dfs1();
    	 cout<<dfs2()<<endl;
     }
      

	return 0;
}