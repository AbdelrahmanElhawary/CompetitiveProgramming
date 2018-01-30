#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
string s[8];
int main()
{
	int t; cin >> t;
	while (t--) {
		bool f = 1;
		for (int i = 0; i < 8; i++)
			cin >> s[i];
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
				if (i == j)continue;
				if (s[i][1] == s[j][1] || s[i][0] == s[j][0])f = 0;
				string t1 = s[i], t2 = s[j];
				for (int k = 0; k < 8; k++)
				{
					if (t1[1] == '8')break;
					t1[0]+= 1;
					t1[1]+= 1;
					//cout << t1 << endl;
					if (t1 == t2)f = 0;
				}
			}
		}
		if (f)cout << "Valid\n";
		else cout << "Invalid\n";
	}
	//system("pause");
	return 0;

}