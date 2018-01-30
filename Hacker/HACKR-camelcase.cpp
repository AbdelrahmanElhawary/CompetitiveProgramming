#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; int ans = 1;
		cin >> s;
		for (int i = 1; i < s.size(); i++)
			if (s[i] >= 'A'&&s[i] <= 'Z'){ans++;}
		cout << ans << endl;
		
    return 0;
}
