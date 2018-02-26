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
string ss = ".!?,";
bool chk(char ch)
{
	for (int i = 0; i < ss.size(); i++)
		if (ch == ss[i])return 1;
	return 0;
}
int main()
{
	fast_in_out();
	string s, s1;
	getline(cin, s);
	int l; bool f = 0, f1 = 0, f2 = 0;
	for (int i = 0; i < s.size(); i++)
	{
		//cout << s1 <<" "<<f1<<" "<<f2<< endl;
		if (!f1 && !f2&&s[i] != ' '&&!chk(s[i])) { s1 += s[i]; continue; }
		if (!f1&&s[i] == ' ') { f1 = 1; l = i; continue; }
		if (!f2 && !f1&&chk(s[i])) { s1 += s[i]; s1 += ' '; f2 = 1; continue; }
		if (f1&&f2 && !chk(s[i]) && s[i] != ' ') { f1 = 0; f2 = 0; s1 += s[i]; continue; }
		if (f2&&s[i] != ' ') { s1 += s[i]; f2 = 0; continue; }
		if (f1&&chk(s[i])) { s1 += s[i]; s1 += ' '; f2 = 1; f1 = 0; continue; }
		if (f1&&!chk(s[i])&&s[i] != ' ') { s1 += ' '; s1 += s[i]; f1 = 0; continue; }

	}
	cout << s1 << endl;



	//system("pause");
	return 0;
}