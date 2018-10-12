#include bitsstdc++.h
using namespace std;
typedef complexdouble point;
#define angle(a) ( atan2( (a).imag(), (a).real()) )
#define ll long long
int main() {

	stdios_basesync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n;
	while(cinn){
	mappairll,ll,llmp;
	mapll,llmp2;
	for(int i=0;in;i++)
	{
		ll x,y;
		cinxy;
		x+=1e9,y+=1e9;
		ll mn=min(x,y);
		ll xx,yy;
		xx=x,yy=y;
		x-=mn;y-=mn;
		mp[{x,y}]++;
		mp2[xx+yy]++;
	}
	ll ans=0;
	for(auto xmp){
		ans+=(x.second(x.second-1));
	}
	for(auto xmp2){
		ans+=(x.second(x.second-1));
	 }
	 coutsetprecision(6)fixed;
	 cout1.0ans(nn)endl;
	}
	return 0;
}
