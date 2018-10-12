#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
int n,m;
map<string,int>mp;
vector< int >adj[10001];
int vis[10005];
int cnt=1;
void dfs(int u)
{
	vis[u]=cnt;
	for(int i=0;i<adj[u].size();i++){
		int e=adj[u][i];
		if(vis[e]!=cnt)
			dfs(e);
	}
}
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m;
	int tt=1;
	for(int i=0;i<n;i++)
	{
	string s1,s2,ss;
	cin>>s1>>ss>>ss>>ss>>s2;
	if(!mp[s1])
		mp[s1]=tt++;
	if(!mp[s2])
		mp[s2]=tt++;
	adj[mp[s1]].push_back(mp[s2]);
	}
	for(int i=0;i<m;i++)
	{
		string s1,ss,s2;
		cin>>s1>>ss>>ss>>ss>>s2;
		if(mp.find(s1)==mp.end()||mp.find(s2)==mp.end())
		{
			cout<<"Pants on Fire\n";
		}
		else
		{
			cnt++;
			dfs(mp[s1]);
			if(vis[mp[s2]]==cnt)
			{
				cout<<"Fact\n";
				continue;
			}
			cnt++;
			dfs(mp[s2]);
			if(vis[mp[s1]]==cnt)
			{
				cout<<"Alternative Fact\n";
				continue;
			}
			cout<<"Pants on Fire\n";
		}
	}

}