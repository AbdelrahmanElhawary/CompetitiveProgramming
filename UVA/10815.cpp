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
set<string>st;
int main()
{
	string s;
	while (cin >> s)
	{
		//if (s == "100")break;
		string str = "";
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] >= 'A'&&s[i] <= 'Z')
				s[i] += 32;
			if (s[i] >= 'a'&&s[i] <= 'z')str += s[i];
			else if (str != "") { st.insert(str); str = ""; }
		}
		if (str.size()==0)continue;
		st.insert(str);
	}
		while (st.size())
		{
			s = *st.begin();
			cout << s << endl;
			st.erase(st.begin());
		}
//	system("pause");
	return 0;
}