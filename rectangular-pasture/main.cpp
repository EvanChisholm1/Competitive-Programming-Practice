#include<bits/stdc++.h>

using namespace std;
vector<pair<int, int>> coords;

bool compY(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        pair<int, int> c;
        cin >> c.first >> c.second;

        coords.push_back(c);
    }

    sort(coords.begin(), coords.end());
    for(int i = 0; i < n; i++) coords[i].first = i;

    sort(coords.begin(), coords.end(), compY);
    for(int i = 0; i < n; i++) coords[i].second = i;

    sort(coords.begin(), coords.end());
    vector<vector<int>> aboveY(n, vector<int>(n + 1));
    vector<vector<int>> bellowY(n, vector<int>(n + 1));
    
    for(int i = 0; i < n; i++) {
        int currentY = coords[i].second;

        for(int x = 1; x < n + 1; x++) {
            bellowY[currentY][x] = bellowY[currentY][x-1] + (coords[x-1].second < currentY);
            aboveY[currentY][x] = aboveY[currentY][x-1] + (coords[x-1].second > currentY);
        }
    }

    long long total = 0;
    for(int i = 0; i < n; i++) {
        auto a = coords[i];
        for(int j = i + 1; j < n; j++) {
            auto b = coords[j];
            int top = max(a.second, b.second);
            int bottom = min(a.second, b.second);

            int aboveTop = aboveY[top][b.first] - aboveY[top][a.first];
            int bellowBottom = bellowY[bottom][b.first] - bellowY[bottom][a.first];
            long long iterations = (aboveTop + 1) * (bellowBottom + 1);
            
            total += iterations;
        }
    }

    total += n + 1;

    cout << total << endl;
    return 0;
}
