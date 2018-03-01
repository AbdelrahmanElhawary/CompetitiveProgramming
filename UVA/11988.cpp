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
list<char>l;
int main() {
	string s,str = "",strr="";
	while (cin >> s)
	{
		str = "";
		int c = 0; bool f=0;
	 list<char>::iterator it=l.begin();
	 //cout << it << endl;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '[') { it = l.begin(); continue; }
			if (s[i] == ']') { it = l.end(); continue; }
			l.insert(it, s[i]);
 
			//cout << str << endl;
 
		}
		while (l.size())
		{
			cout << *l.begin();
			l.erase(l.begin());
		}
		cout << endl;
 
	}
	//cout << endl;
	//system("pause");
	return 0;
}