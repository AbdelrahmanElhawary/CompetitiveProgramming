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
#include<queue>
#include<list>
#include <iterator>
#include <functional> 
#include<iomanip>
#define F first
#define S second
#define ll long long
#define ld long double
#define dong long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
bool punc(char ch)
{
	if (ch == '.' || ch == '!' || ch == ' ' || ch == '?' || ch == ',')
		return 1;
	return 0;
}
int main() {
	string s;
	while (1)
	{
		//cin.ignore();
		getline(cin, s);
		if (s == "DONE")break;
		string str = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (punc(s[i]))continue;
			if (s[i] >= 'A'&&s[i] <= 'Z') s[i] += 32;
			str += s[i];
		}
		string str2 =str;
		//cout << str << endl;
		reverse(str2.begin(), str2.end());
		if (str2 == str)cout << "You won't be eaten!\n";
		else cout << "Uh oh..\n";
	}

	//system("pause");
	return 0;
}