#include <bits/stdc++.h>

using namespace std;
int main() {
    vector<long long> arr(5);
    for(int arr_i = 0; arr_i < 5; arr_i++){
       cin >> arr[arr_i];
    }
   sort(arr.begin(),arr.end());
    long long mx=0,mn=0;
    for(int i=0;i<5;i++)
    {
        if(i)mx+=arr[i];
        if(i<4)mn+=arr[i];
    }
        cout<<mn<<" "<<mx<<endl;
    return 0;
}
