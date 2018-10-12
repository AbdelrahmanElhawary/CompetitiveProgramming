#include <bits/stdc++.h>
using namespace std;
typedef complex<double> point;
#define angle(a) ( atan2( (a).imag(), (a).real()) )
int main() {

	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	while(cin>>n)
	{
		char ch; cin>>ch;
		if(ch=='N')
		{
			if(n>=3)cout<<2<<endl;
			else cout<<1<<endl;
		}
		if(ch=='K')
		{
			if(n==1)cout<<1<<endl;
			else cout<<4<<endl;
		}
		if(ch=='B'||ch=='R')
		{
			cout<<n<<endl;
		}
	}


	return 0;
}