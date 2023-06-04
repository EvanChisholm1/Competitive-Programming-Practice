#include<bits/stdc++.h>

using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    long long r = ceil(double(n) / double(a));
    long long c = ceil(double(m) / double(a));

    long long s = r * c;

    cout << s << endl;
    return 0;
}
