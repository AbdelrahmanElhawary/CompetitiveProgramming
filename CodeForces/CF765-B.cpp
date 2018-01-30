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
#define F first
#define S second
#define ll long long
using namespace std;
int main()
{
	string s; char ch = 'a'; cin >> s; bool f = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] < ch)continue;
		if (s[i] == ch)ch++;
		else f = 0;
	}
	if (f)cout << "YES\n"; else cout << "NO\n";
	
	//system("pause");
	return 0;
}