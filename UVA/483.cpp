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
	while (getline(cin, s))
	{
		string str = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != ' ') { str += s[i]; continue; }
			reverse(str.begin(), str.end());
			cout << str << " ";
			str = "";

		}
		reverse(str.begin(), str.end());
		cout << str << "\n";
	}

	//system("pause");
	return 0;
}