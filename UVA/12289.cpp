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
int main() {
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		if (s.size() > 3)cout << 3 << endl;
		else
		{
			string s1 = "one", s2 = "two";
			int c1 = 0, c2 = 0;
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == s1[i])c1++;
				if (s[i] == s2[i])c2++;
			}
			if (c1 > c2)cout << 1 << endl;
			else cout << 2 << endl;
		}
	}
	
	//system("pause");
	return 0;
}