#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n,x,y=1e9; cin >> n;
		map<int, int>mp;
		for (int i = 0; i < n; i++)
		{
			cin >> x; y = min(x, y);
			mp[x]++;
		}
		if (mp[y] % 2)cout << "Lucky\n";
		else cout << "Unlucky\n";
	}
//	system("pause");
	return 0;

}