/*
for:
Hussien , Ayman , Emad
Abanob , George , Genawy
Ka8eem , Mosta7il , Stawro
ICPC DREAM
*/
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define ld long double
#define ull unsigned ll 
#define endl '\n'
#define mk make_pair
const double PI = acos(-1.0);
void fast_in_out() {
	std::ios_base::sync_with_stdio(NULL);
	cin.tie(NULL); cout.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

}
int dx[] = { 0,0,-1,1,-1,1,-1,1,0 };
int dy[] = { -1,1,0,0,-1,-1,1,1,0 };
const int N = 2e3 + 3, M = 1e4 + 5, mod = 10056;
int c1, c2, n;
struct node {
	int a, b, op;
};
node vis[N][N];
string prnt(int op) {
	if (!op)return "fill A";
	if (op == 1)return "fill B";
	if (op == 2)return "empty A";
	if (op == 3)return "empty B";
	if (op == 4)return "pour A B";
	if (op == 5)return "pour B A";
	if (op == 6)return "success";
}
int main() {
	fast_in_out();
	//cout << fixed << setprecision(6);
	//kolo ray7 , ya 5raby
	while (cin >> c1 >> c2 >> n) {
		for (int i = 0; i <= c1; i++)
			for (int j = 0; j <= c2; j++)
				vis[i][j].op = -1;
		queue<pair<int,int>>q;
		vector<string>v;
		q.push({ 0,0 });
		vis[0][0] = { 0,0,-2 };
		while (q.size()) {
			int a = q.front().first, b = q.front().second;
			q.pop();
			if (b == n)
			{
				while (a || b) {
					v.push_back(prnt(vis[a][b].op));
					int x = vis[a][b].a, y = vis[a][b].b;
					a = x, b = y;
				}
				break;
			}
			if (a < c1&&vis[c1][b].op == -1)
				vis[c1][b] = { a,b,0 }, q.push({ c1,b });
			if (b < c2&&vis[a][c2].op == -1)
				vis[a][c2] = { a,b,1 }, q.push({ a,c2 });
			if (a&&vis[0][b].op == -1)
				vis[0][b] = { a,b,2 }, q.push({ 0,b });
			if (b&&vis[a][0].op == -1)
				vis[a][0] = { a,b,3 }, q.push({ a,0 });
			int add = min(a, c2 - b);
			if (add&&vis[a - add][b + add].op == -1)
				vis[a - add][b + add] = { a,b,4 }, q.push({ a - add,b + add });
			add = min(b, c1 - a);
			if (add&&vis[a + add][b - add].op == -1)
				vis[a + add][b - add] = { a,b,5 }, q.push({ a + add,b - add });
		}
		reverse(v.begin(), v.end());
		for (auto e : v)
			cout << e << endl;
		cout<<prnt(6)<<endl;
	}
	return 0;
}