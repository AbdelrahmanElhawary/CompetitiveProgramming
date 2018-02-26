#include <iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
pair<long long,long long> arr[200001];
long long arr2[200002];
vector<long long>ans;
int main()
{
//cout<<fixed<<setprecision(2);
int n; cin>>n;
for(int i=0;i<n;i++)
{
    cin>>arr[i].first;

}

    int q;cin>>q;
    for(int i=0;i<q;i++)
    {
        int x,y; cin>>x>>y;
        x--;
        arr[x].second-=1;
        arr[y].second+=1;
    }
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i].second>=0){ans.push_back(arr[i].first);c++;};
        arr[i+1].second+=arr[i].second;
    }
    cout<<c<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
