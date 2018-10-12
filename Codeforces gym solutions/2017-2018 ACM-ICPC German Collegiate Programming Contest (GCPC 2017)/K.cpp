#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);

int n,d,k;
cin>>n>>d>>k;
vector<pair< int,string > >v(n);
for(int i=0;i<n;i++)
{
	cin>>v[i].second>>v[i].first;
}
sort(v.rbegin(),v.rend());
ll sav=0;int c=0;
for(int i=0; i<k;i++){
sav+=v[i].first;
c++; if(sav>=d)break;
}
if(sav>=d)
{
	cout<<c<<endl;
	for(int i=0;i<c;i++)
		cout<<v[i].second<<", YOU ARE FIRED!\n";
}
else cout<<"impossible\n";

}