#include<bits/stdc++.h>

using namespace std;

const int MAX = 200001;

int n;

int speed[MAX];
int range[MAX];
int pos[MAX];

long long getTime(int c) {
    long long leftTime = 0;
    long long rightTime = 0;
    for(int i = 0; i < n; i++) {
        long long distance = abs(c - pos[i]) - range[i];
        if(distance <= 0) continue;
        else if(pos[i] < c) leftTime += speed[i] * distance;
        else if(pos[i] > c) rightTime += speed[i] * distance;
    }

    // pair<int, int> ret;
    // ret.first = leftTime;
    // ret.second = rightTime;

    return leftTime + rightTime;
}

int main() {
    cin >> n;

    int maxPos = 0;

    for(int i = 0; i < n; i++) {
        int p, w, d;
        cin >> p >> w >> d;

        pos[i] = p;
        speed[i] = w;
        range[i] = d;

        maxPos = max(p, maxPos);
    }

    // while(true) {
    //     int c;
    //     cin >> c;
    //     cout << endl;
        
    //     pair<int, int> times = getTime(c);
    //     cout << times.first << " " << times.second << endl;
    // }

    long long shortest = INT64_MAX;

    int minPos = 0;
    while(true) {

        int midPoint = minPos + (maxPos - minPos + 1) / 2;

        if(getTime(midPoint + 1) < getTime(midPoint)) minPos = midPoint;
        else if(getTime(midPoint - 1) < getTime(midPoint)) maxPos = midPoint - 1;
        else {
            shortest = getTime(midPoint);
            break;
        }

    }

    // cout << shortest << endl;

    cout << min(min(getTime(minPos), getTime(maxPos)), shortest) << endl;

    // cout << minPos << " " << maxPos << endl;
    // pair<int, int> minTimes = getTime(minPos);
    // shortest = min(shortest, minTimes.first + minTimes.second);
    // cout << shortest << endl;

    // cout << minPos << " " << maxPos << endl;
    // pair<int, int> minTimes = getTime(minPos);
    // pair<int, int> maxTimes = getTime(maxPos);
    // int totalTime = min(maxTimes.first + maxTimes.second, minTimes.first + minTimes.second);

    // // cout << finalTimes.first + finalTimes.second << endl;
    // cout << totalTime << endl;

    return 0;
}
