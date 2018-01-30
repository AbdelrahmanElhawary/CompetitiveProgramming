#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
#include<vector>
#include<string.h>
#define F first
#define S second
#define ll long long
using namespace std;
int arr[100001];
int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		ll mx = 1e18,ans=0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i] <= mx) { ans++; mx = arr[i]; }
		}
		cout << ans << endl;
	}
	
	
	//system("pause");
	return 0;
}