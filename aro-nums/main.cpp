#include<bits/stdc++.h>

using namespace std;

int main() {
    string sequence;
    cin >> sequence;
    map<char, int> symbols;
    symbols['I'] = 1;
    symbols['V'] = 5;
    symbols['X'] = 10;
    symbols['L'] = 50;
    symbols['C'] = 100;
    symbols['D'] = 500;
    symbols['M'] = 1000;

    int total = 0;
    for(int i = 0; i < sequence.length(); i += 2) {
        char cA = sequence[i];
        int a = cA - '0';
        int r = symbols[sequence[i + 1]];
        int nextR = 0;

        if(i + 1 + 2 < sequence.length()) {
            nextR = symbols[sequence[i + 1 + 2]];
        }

        if(nextR > r) total -= a * r;
        else total += a * r;
    }

    cout << total << endl;
    return 0;
}