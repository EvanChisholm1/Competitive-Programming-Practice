#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> books;
    for(int i = 0; i < n; i++) {
        int book;
        cin >> book;
        books.push_back(book);
    }

    sort(books.begin(), books.end());

    int sum = 0;
    int numberOfBooks = 0;
    while(sum + books[numberOfBooks] <= x && numberOfBooks < books.size()) {
        sum += books[numberOfBooks];
        numberOfBooks++;
    }

    cout << numberOfBooks << endl;
    return 0;
}
