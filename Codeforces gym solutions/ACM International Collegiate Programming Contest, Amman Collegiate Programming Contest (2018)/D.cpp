#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		if(n>m){
			swap(n,m);
		}
		if(n%2==0 && m%2==0){
			ll f = n/2 * (m/2);
			ll s = n/2 * (m/2 + 1);
			cout<<f+s<<endl;
			continue;
		}
		if(n%2==0&& m%2!=0){
			ll ans = n * (m/2 +1);
			cout<<ans<<endl;
			continue;
		}
		if(n%2 !=0&&m%2!=0){
			ll ans = n * (m/2 +1);
			cout<<ans<<endl;
			continue;
		}
		if(n%2!=0&&m%2==0){
			ll ans = (n/2 + 1) * (m/2);
			ll ans2 = (n/2) * (m/2+1);
 			cout<<ans + ans2<<endl;
			continue;
		}
	}
	return 0;
}