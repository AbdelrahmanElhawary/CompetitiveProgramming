#include<iostream>
#include<map>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<sstream>
using namespace std;
int arr[100001];
int main()
{
	string s; cin >> s;
	if (s == "h8" || s == "h1" || s == "a8" || s == "a1")cout << 3 << endl;
	else if (s[0] == 'h' || s[0] == 'a' || s[1] == '1' || s[1] == '8')cout << 5 << endl;
	else cout << 8 << endl;
	//system("pause");
	return 0;
}