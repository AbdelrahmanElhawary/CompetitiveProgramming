#include <bits/stdc++.h>

using namespace std;
int arr[1000][1000];
int main() {
   int n,d1=0,d2=0; cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
            if(i==j)d1+=arr[i][j];
            if(i==n-j-1)d2+=arr[i][j];
        }
    cout<<abs(d1-d2);
    return 0;
}
