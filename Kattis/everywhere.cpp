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

int main()
{
	int t; cin >> t;
	while (t--)
	{
		map < string, bool>mp;
		int n; cin >> n;
		for(int i=0;i<n;i++)
		{
			string s; cin >> s; mp[s] = 1;
		}
		cout << mp.size() << endl;
	}

	//system("pause");
	return 0;
}