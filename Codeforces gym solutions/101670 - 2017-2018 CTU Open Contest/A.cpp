#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int a[200005];
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	while(cin>>n){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n ==1 ){
			cout<<1<<endl;
			continue;
		}
		int cur = a[1] - a[0];
		int last=0;
		for(int i=1;i<n;i++){
			if(a[i] - a[i-1] != cur){
				last = i-1;
				cur = a[i] - a[i-1];
			}
		}
		cout<<last + 1<<endl;
	}


	return 0;
}