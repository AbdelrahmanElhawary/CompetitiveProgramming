#include<iostream>
#include<string>
using namespace std;
int main() {
	string s1, s2; bool f = 0; int ans = 0;
	cin >> s1 >> s2;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] < 'a') s1[i] += 32;
		if (s2[i] < 'a') s2[i] += 32;
		if (s1[i] == s2[i])continue;
		if (s1[i] > s2[i]) { ans = 1; f = 1; break; }
		else { ans = -1; f = 1; break; }
	}
	/*if(!f)
		for (int i = 0; i < s1.size(); i++)
		{
			if (s1[i] + 32 == s2[i]) { ans = -1; break; }
			if (s1[i] - 32 == s2[i]) { ans = 0; break; }
		}*/
	cout << ans << endl;
	//system("pause");
	return 0;
}