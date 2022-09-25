#include<bits/stdc++.h>

using namespace std;


int main() {
    int n;
    cin >> n;

    vector<int> sunflowerGrid[n];

    int smallestSunflower = pow(10, 9);
    int smallestCoords[2];

    for (int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int s;
            cin >> s;
            sunflowerGrid[i].push_back(s);
            if(s < smallestSunflower) {
                smallestSunflower = s;
                smallestCoords[0] = i;
                smallestCoords[1] = j;
            }
        }
    }

    if(smallestCoords[0] == 0) {
        for(int i = 0; i < n; i++) {
            if(smallestCoords[1] == 0) {
                for (int j = 0; j < n; j++) {
                    cout << sunflowerGrid[i][j] << " ";
                }
            } else {
                for (int j = 0; j < n; j++) {
                    cout << sunflowerGrid[j][n - i - 1] << " ";
                }
            }

            cout << endl;
        }
    }

    if(smallestCoords[0] > 0) {
        for(int i = n - 1; i >= 0; i--) {
            if(smallestCoords[1] == 0) {
                for (int j = 0; j < n; j++) {
                    cout << sunflowerGrid[n - 1 - j][n - 1 - i] << " ";
                }
            } else {
                for (int j = n - 1; j >= 0; j--) {
                    cout << sunflowerGrid[i][j] << " ";
                }
            }

            cout << endl;
        }
    }

    return 0;
}
