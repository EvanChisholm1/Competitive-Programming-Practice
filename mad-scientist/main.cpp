#include<bits/stdc++.h>

using namespace std;

string a;
string b;

int flips = 0;

void flip(int start, int end) {
    flips++;
    for(int i = start; i <= end; i++) {
        if (a[i] == 'G') a[i] = 'H';
        else if (a[i] == 'H') a[i] = 'G';
    }
}

void solve() {
    bool foundStart = false;
    int start = 0;
    int end = a.length() - 1;

    for(int i = 0; i < a.length(); i++) {
        if(a[i] != b[i] && !foundStart) {
            foundStart = true;
            start = i;
        }
        if(a[i] == b[i] && foundStart) {
            end = i - 1;
            break;
        }
    }


    if(a != b) {
        flip(start, end);
    }
    if(a != b) {
        solve();
    }
    return;
}

int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int n;
    cin >> n;

    cin >> a >> b;

    solve();

    cout << flips << endl;
}
