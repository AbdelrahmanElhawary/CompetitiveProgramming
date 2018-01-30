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
using namespace std;
int arr[100001];
void file() {
	freopen("A-large-practice(1).in", "r", stdin);
	freopen("X2", "w", stdout);
}
int main()
{
	file();
	int t,tt=1; cin >> t;

	while (t--)
	{
		string s; int k,ans=0;
		cin >> s >> k;
		for (int i = 0; i + k - 1 < s.size(); i++)
			if (s[i] == '-')
			{
				for (int j = 0; j < k; j++)
					if (s[i + j] == '-')s[i + j] = '+'; else s[i + j] = '-';
				ans++;
			}
		for (int i = 0; i < s.size(); i++)
			if (s[i] == '-')ans = -1;
		cout << "Case #" << tt++ << ": ";
		if (ans == -1)cout << "IMPOSSIBLE\n"; else cout << ans << endl;
	}
	//system("pause");
	return 0;
}
