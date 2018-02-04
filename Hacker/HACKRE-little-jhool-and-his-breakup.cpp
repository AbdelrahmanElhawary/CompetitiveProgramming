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
	string s; cin >> s;
	string l = "love";
	int j = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == l[j%4])j++;
	if (j >= 4)cout << "I love you, too!\n";
	else cout << "Let us breakup!\n";
	
//	system("pause");
	return 0;
}