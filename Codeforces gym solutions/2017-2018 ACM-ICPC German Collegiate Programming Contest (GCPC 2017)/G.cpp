#include <bits/stdc++.h>
#include<complex>
using namespace std;

#define ll long long
#define endl "\n"
typedef complex<long double> point;
#define cross(a,b) ((conj(a)*(b)).imag())
#define len(v) ((long double) hypot((v).imag(),(v).real()))
int n;

int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n;
	vector<point> v;
	for(int i=0;i<n;i++){
		ll x,y;
		cin>>x>>y;
		point a(x,y);
		v.push_back(a);
	}
	long double res = 0;
	ll bound =0;
	for(int i=0;i<n;i++){
		ll j = (i+1) % n;
		res+=cross(v[i],v[j]);
		point vv = v[j] - v[i];
		bound +=abs(__gcd((ll)vv.real() , (ll)vv.imag()));
	}
	cout<<(ll)(fabs(res/2)  - bound/2+1)<<endl;

}