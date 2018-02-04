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
		string s1, s2;
		cin.ignore();
		getline(cin, s1);
		cin.ignore();
		getline(cin, s2);
		int c1 = s1.size(),c2=s2.size();
		int ar1[26]{ 0 };
		for (int i = 0; i <s1.size(); i++)
		{
			if (s1[i] == ' ') { c1--; continue; }
			ar1[s1[i] - 'a']++;
		}
		for (int i = 0; i < s2.size(); i++)
		{
			if (s2[i] == ' ') { c2--; continue; }
			if (ar1[s2[i] - 'a'] > 0) { ar1[s2[i] - 'a']--; c1--; c2--; }
		}
		//cout << c1 << " " << c2 << endl;
		if (c2 > 0 && !c1)cout << "You lose some.\n";
		else if (c1 > 0 && !c2)cout << "You win some.\n";
		else if (c1&&c2)cout << "You draw some.\n";
	}

	//system("pause");
	return 0;
}