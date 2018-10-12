#include <iostream>
using namespace std;

int main() {
int t; cin>>t;
while(t--)
{

	int n;
	cin>>n;
	int x,cnt;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		if(!i)cnt=x;
		else cnt^=x;
	}
	if(!cnt)cout<<1<<endl;else cout<<0<<endl;

}

	return 0;
}