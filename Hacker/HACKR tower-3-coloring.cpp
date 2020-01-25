#include <bits/stdc++.h>
#define ll long long
const int mod=1e9+7;
using namespace std;
ll fast_power(ll base, ll power,ll md) {
    ll result = 1;
    base%=md;power%=md;
    while (power > 0) {

        if (power & 1) {
            result = (result*base) % md;
        }
        base = (base * base) % md;
        power >>= 1;
    }
    return result;
}
// Complete the towerColoring function below.
int towerColoring(int n) {
    return (int)fast_power(3,fast_power(3,n,mod-1),mod);

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int result = towerColoring(n);

    fout << result << "\n";

    fout.close();

    return 0;
}
