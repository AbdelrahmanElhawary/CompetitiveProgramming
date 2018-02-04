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
#define F first
#define S second
#define ll long long
using namespace std;
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(0);
	string s,str=""; cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (str.size() >= 2 && str[str.size() - 1] == s[i] && str[str.size() - 1] == str[str.size() - 2])
			continue;
		if (str.size() >= 3 && str[str.size() - 1] == s[i] && str[str.size() - 2] == str[str.size() - 3])
			continue;
		str += s[i];
	}
	cout << str << endl;


	//system("pause");
		return 0;
}