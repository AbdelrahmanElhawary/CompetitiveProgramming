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
map<string, int>mp;
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		if (!mp[s]) { mp[s]=1; cout << "OK\n"; continue; }
		cout << s << mp[s]<<endl;
		mp[s]++;
	}
	//system("pause");
	return 0;
}