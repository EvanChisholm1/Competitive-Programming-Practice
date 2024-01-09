#include<bits/stdc++.h>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    int cars[N];

    for(int i = 0; i < N; i++) {
        cin >> cars[i];
    }

    int total = 0;
    int current = 0;

    for (int i = 0; i < N; i++) {
        current += cars[i];
        if(i - 4 >= 0) current -= cars[i - 4];
        
        if(current > M) break;
        total++;
    }

    cout << total << endl;

    return 0;
}
