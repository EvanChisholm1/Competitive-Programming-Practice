#include<bits/stdc++.h>

using namespace std;

// vector<pair<int, int>> walkways;
unordered_map<int, vector<int>> walkways;
vector<int> stations;
int n, w, d;
vector<int> shortestDistances;

void findPath() {
    queue<int> q;
    int distance[n + 1];
    bool visited[n + 1];
    visited[1] = true;
    distance[1] = 0;
    q.push(1);
    bool foundFinal = false;
    int finalDistance;

    while(!foundFinal) {
        int s = q.front();
        q.pop();

        cout << "IS Q EMPT>Y" << q.empty() << endl;

        if(s == 0) continue;
        cout << s << endl;

        for(int i = 0; i < walkways[s].size(); i++) {
            int node = walkways[s][i];
            cout << node << endl;

            if(node == n) {
                foundFinal = true;
                finalDistance = distance[s] + 1;
                break;
            }

            if (visited[node]) continue;
            visited[node] = true;
            distance[node] = distance[s] + 1;
            cout << node << endl;
            q.push(node);
        }

        if(foundFinal) break;

        int nextI;
        for(int i = 0; i < stations.size(); i++) {
            if(stations[i] == s) {
                nextI = i + 1;
                cout << "NEXT I: " << nextI << endl;
            }
        }

        int next = stations[nextI];
        cout << "NEXT EQUALS " << next << endl;
        if(next == n) {
            cout << "NEXT IS EQUAL TO N " << n << endl;
            foundFinal = true;
            finalDistance = distance[s] + 1;
            break;
        }
        if(visited[next]) continue;
        visited[next] = true;
        distance[next] = distance[s] + 1;
        cout << next << endl;
        q.push(next);
    }

    shortestDistances.push_back(finalDistance);
}

int main() {
    cin >> n >> w >> d;

    for(int i = 0; i < w; i++) {
        int a, b;
        cin >> a >> b;

        if(walkways.find(a) == walkways.end()) {
            vector<int> a_walkways;
            walkways[a] = a_walkways;
        }

        walkways[a].push_back(b);
    }

    for (int i = 0; i < n; i++) {
        int stationNumber;
        cin >> stationNumber;
        stations.push_back(stationNumber);
    }

    for(int i = 0; i < d; i++) {
        int aIndex, bIndex;
        cin >> aIndex >> bIndex;

        int a = stations[aIndex - 1];
        int b = stations[bIndex - 1];

        stations[aIndex - 1] = b;
        stations[bIndex - 1] = a;

        for (int j = 0; j < stations.size(); j++){
            cout << stations[j] << " ";
        }
        cout << endl;

        findPath();
    }

    for (int i = 0; i < shortestDistances.size(); i++) {
        cout << shortestDistances[i] << endl;
    }

    return 0;
}

// plan:
// start by getting all walkways
// get the stations in list order
// attach walkways to stations list
