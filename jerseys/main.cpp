#include<bits/stdc++.h>

using namespace std;

int main() {
    int j, a;
    cin >> j >> a;

    int jerseys[j];
    bool used[j];
    memset(used, false, sizeof(used));

    for(int i = 0; i < j; i++) {
        char s;
        cin >> s;
        if(s == 'S') jerseys[i] = 0;
        if(s == 'M') jerseys[i] = 1;
        if(s == 'L') jerseys[i] = 2;
    }


    int total = 0;
    for(int i = 0; i < a; i++) {
        char c;
        int num;
        cin >> c >> num;

        int s;
        if(c == 'S') s = 0;
        if(c == 'M') s = 1;
        if(c == 'L') s = 2;

        if(jerseys[num - 1] >= s && !used[num-1]) {
            used[num-1] = true;
            total++;
        }

    }

    cout << total << endl;
    return 0;
}
