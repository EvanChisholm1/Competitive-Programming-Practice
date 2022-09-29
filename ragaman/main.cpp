#include<bits/stdc++.h>

using namespace std;

int main() {
    string a;
    string b;

    cin >> a >> b;
    
    unordered_map<char, int> m;
    unordered_map<char, int> wildcard;
    for(auto x: a) {
        m[x] = 0;
        wildcard[x] = 0;
    }

    for(auto x: a) {
        m[x] += 1;
        wildcard[x] += 1;
    }

    int wilds = 0;

    for(auto x: b) {
        if(x == '*') {
            wilds += 1;
        }
    }

    bool isAnagram = true;

    for(auto x: b) {
        wildcard[x] -= 1;
    }

    for(auto x: a) {
        if(!isAnagram) break;
        if(wildcard[x] == 0) {
            continue;
        }

        if(wilds <= 0) {
            isAnagram = false;
        }

        if(wildcard[x] > 0) {
            if(wilds - wildcard[x] >= 0) {
                wildcard[x] = 0;
                wilds -= wildcard[x];
            } else {
                isAnagram = false;
            }
        }

        if(wildcard[x] < 0){
            isAnagram = false;
        }
    }

    for(auto x: b) {
        if(m.find(x) == m.end() && x != '*') {
            isAnagram = false;
        }
    }

    if(isAnagram) cout << "A" << endl;
    if(!isAnagram) cout << "N" << endl;

}
