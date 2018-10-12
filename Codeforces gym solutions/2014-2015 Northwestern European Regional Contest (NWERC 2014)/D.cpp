#include <bits/stdc++.h>
using namespace std;

#define  ll long long
#define endl "\n"
const int N=5e5+5;
ll n;
vector<vector<int> >adj;
char state[N];
int in[N];
ll cur[N];
int main() {
std::ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
	cout<<setprecision(10)<<fixed;
	int m;
	 cin>>n>>m;
	 adj.resize(m+1);
	 for(int i=1;i<=m;i++)
	 {
		 char ch;
		 int l,r;
		 cin>>ch>>l>>r;
		 adj[i].push_back(l);
		 adj[i].push_back(r);
		 in[l]++; in[r]++;
		 state[i]=ch;
	 }
	 set<pair<int,int>>s;
	 for(int i=1;i<=m;i++)
		 s.insert({in[i],i});
	 pair<int,int> temp=*s.begin();
	 cur[temp.second]=n;
	 for(int ii=1;ii<=m;ii++)
	 {
		 temp=*s.begin();
		 s.erase(s.begin());
		 int i=temp.second;
		 int nodel=adj[i][0],noder=adj[i][1];
		 s.erase({in[nodel],nodel}); in[nodel]--;
		 s.erase({in[noder],noder}); in[noder]--;
		 s.insert({in[nodel],nodel});
		 s.insert({in[noder],noder});
		 if(cur[i]&1){
			 if(state[i]=='R'){
				 state[i]='L';
				 cur[nodel]+=(cur[i])/2;
				cur[noder]+=(cur[i]+1)/2;
			 }
			 else {
				 state[i]='R';
				 cur[noder]+=(cur[i])/2;
				 cur[nodel]+=(cur[i]+1)/2;
			 }
		 }else{
		 if(state[i]=='L')
		 {
			 cur[noder]+=(cur[i])/2;
			cur[nodel]+=(cur[i]+1)/2;
		 }
		 else {
			 cur[nodel]+=(cur[i])/2;
			 cur[noder]+=(cur[i]+1)/2;
		 }
		 }
	 }
	 	 for(int i=1;i<=m;i++)
	 {
		 cout<<state[i];
	 }
	 cout<<endl;
	return 0;
}