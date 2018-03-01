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
ll po(int k,int f)
{
	if (!f)return 1;
	for (int i = 1; i < f; i++)
		k *= 2;
	return k;
}
char stk[401];
int main() {
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int stk_cnt=0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'a'&&s[i] <= 'z') { cout << s[i]; continue; }
			if (s[i] == ')') cout << stk[--stk_cnt];
			else if(s[i]=='+'|| s[i] == '-' || s[i] == '/' || s[i] == '*' || s[i] == '^' )
				stk[stk_cnt++] = s[i];
		}
		cout << endl;
	}
//system("pause");
	return 0;
}