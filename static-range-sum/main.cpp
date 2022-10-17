#include<bits/stdc++.h>

using namespace std;

vector<long long> A;

int main() {
    int n, q;
    cin >> n >> q;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        sum += a;
        A.push_back(sum);
    }

    vector<long long> sums;

    for (int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
    
        if(l == 0) {
            printf("%lld\n", A[r - 1]);
        } else {
            printf("%lld\n", A[r - 1] - A[l - 1]);
        }
    }
}
