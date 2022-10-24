#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> cows;
int totalSwaps = 0;

bool checkSovled() {
    int last = 0;
    for(int c: cows){
        if(c < last) return false;
        last = c;
    }

    return true;
}

void solve() {
    if(checkSovled()) return;

    int lastNumber = -1;
    int lastNumberIndex = -1;
    

    for(int i = 0; i < n; i++) {
        if(cows[i] < lastNumber) {
            int currentI = i;

            for(int k = i; k < n; k++) {
                if(cows[k] != cows[i]) {
                    currentI = k - 1;
                    break;
                } else {
                    currentI = k;
                }
            }

            swap(cows[currentI], cows[lastNumberIndex]);
            totalSwaps++;
            return solve();
        }

        if(cows[i] != lastNumber){
            lastNumber = cows[i];
            lastNumberIndex = i;
        }
    }
}

int main() {
    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    cin >> n;

    for(int i = 0; i < n; i++) {
        int c;
        cin >> c;
        cows.push_back(c);
    }

    solve();
    cout << totalSwaps << endl;
}
