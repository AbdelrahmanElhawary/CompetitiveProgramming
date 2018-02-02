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
int main() {
	string s1, s2;
	cin >> s1 >> s2;
	//if (s2.size() > s1.size()) { cout << s1 << endl; return 0; }
	int ar1[26]{ 0 }, ar2[26]{ 0 }, ar3[26]{ 0 },c1 = 0;
	for (int i = 0; i < s1.size(); i++)
		if (s1[i] != '?') { ar1[s1[i] - 'a']++; ar3[s1[i] - 'a']--; }
		else c1++;
		for (int i = 0; i < s2.size(); i++)
			ar2[s2[i] - 'a']++;
		int mn= 1e9;
		for (int i = 0; i < 26; i++)
			if (ar1[i] < ar2[i]) { mn = 0; break; }
			else if (!ar2[i])continue;
			else mn = min(mn, ar1[i] / ar2[i]);
			for (int i = 0; i < 26; i++)
				if (ar2[i]) { ar3[i] += (ar2[i] * mn); ar1[i] -= (ar2[i] * mn); }
			while (c1)
			{
				for (int i = 0; i < 26; i++)
				{
					if (c1 == 0)break;
					if (!ar2[i])continue;
					if (ar1[i] < ar2[i])
					{
						for (int j = 0; j < (ar2[i] - ar1[i]); j++)
						{
							if (c1 == 0)break;
							if (!ar1[i]) c1--; else ar1[i]--;
							ar3[i]++;
						}
					}
					else
					{
						ar3[i] += ar2[i];
						ar1[i] -= ar2[i];
					}
				}
			}
			for (int i = 0; i < 26; i++)
				ar3[i] += ar1[i];
			for (int i = 0; i < s1.size(); i++)
			{
				if (s1[i] != '?') { cout << s1[i]; continue; }
				for (int j = 0; j < 26; j++)
					if (ar3[j]) { cout << (char)(j + 'a'); ar3[j]--; break; }
			}
			cout << endl;
	//	system("pause");
	return 0;
}