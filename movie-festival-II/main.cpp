#include<bits/stdc++.h>

using namespace std;
int n, k;

bool endingTimeSort(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}


int countMovies(vector<pair<int, int>> m, vector<bool> v) {
    // pritority q
    // give everyone a movie
    // find the person with the earliest ending movie time
    // give them the next movie add 1 to the sum
    // repeat until you cannot get another movie
    int sum = k;
    priority_queue<int> q;
    for(int i = 0; i < k; i++) {
        v[i] = true;
        q.push(0 - m[i].second);
    }

    for(int i = 0; i < m.size(); i++) {
        pair<int, int> next = m[i];
        if(next.first > 0 - q.top() && !v[i]) {
            q.pop();
            sum++;
            q.push(0 - next.second);
            v[i] = true;
        }
    }

    return sum;
}

int main() {
    cin >> n >> k;

    vector<pair<int, int>> movies(n);
    vector<bool> visited(n);

    for(int i = 0; i < n; i++) {
        pair<int, int> movie;
        cin >> movie.first >> movie.second;
        movies[i] = movie;
        visited[i] = false;
    }

    sort(movies.begin(), movies.end(), endingTimeSort);
    cout << "printing order" << endl;
    for(auto x: movies) {
        cout << x.first << " " << x.second << endl;
    }

    cout << countMovies(movies, visited) << endl;
    return 0;
}
