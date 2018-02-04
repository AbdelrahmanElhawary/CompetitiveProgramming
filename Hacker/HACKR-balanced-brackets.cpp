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
	int t; cin >> t;
	while (t--)
	{
		string s,str=""; cin >> s;
		bool f = 1;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')str += s[i];
			else
			{
				
				if (!str.size()) { f = 0; break; }
				if (s[i] == ')'&&str[str.size() - 1] == '(') { str.pop_back(); continue; }
				if (s[i] == '}'&&str[str.size() - 1] == '{') { str.pop_back(); continue; }
				if (s[i] == ']'&&str[str.size() - 1] == '[') { str.pop_back(); continue; }
				f = 0; break;
				
			}
		}
		
		if (f&&!str.size())cout << "YES\n"; else cout << "NO\n";
		
	}
	//	system("pause");
		return 0;
}