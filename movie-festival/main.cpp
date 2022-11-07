#include<bits/stdc++.h>

using namespace std;

bool endingTimeSort(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int countMovies(vector<pair<int, int>> m) {
    int sum = 1;
    int currentTime = m[0].second;
    int lastI = 0;
    for(int i = lastI; i < m.size(); i++) {
        pair<int, int> next = m[i];
        if(next.first >= currentTime && lastI != i) {
            // sum += countMovies(m, int(next.second), i);
            sum++;
            lastI = i;
            currentTime = next.second;
        }
    }

    return sum;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> movies(n);

    for(int i = 0; i < n; i++) {
        pair<int, int> movie;
        cin >> movie.first >> movie.second;
        movies[i] = movie;
    }

    sort(movies.begin(), movies.end(), endingTimeSort);

    cout << countMovies(movies) << endl;
    return 0;
}
