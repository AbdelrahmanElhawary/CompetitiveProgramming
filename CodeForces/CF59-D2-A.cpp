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
	int c1 = 0, c2 = 0;
	int ans;
	for (int i = 0; i < s.size(); i++)
		if (s[i] >= 'a'&&s[i] <= 'z')c1++;
		else c2++;
		
		for (int i = 0; i < s.size(); i++)
			if (c2 > c1&&s[i] >= 'a'&&s[i] <= 'z')s[i] -= 32;
			else if (c1>=c2&&s[i] >= 'A'&&s[i] <= 'Z')s[i] += 32;
			cout << s << endl;
	//system("pause");
	return 0;
}