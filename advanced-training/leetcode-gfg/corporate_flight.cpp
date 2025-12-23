#include<bits/stdc++.h>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> answer(n);
    for (auto &index : bookings) {
        answer[index[0] - 1] += index[2];
        if (index[1] < n) answer[index[1]] -= index[2];
    }
    for (auto i = 1; i < n; ++i) 
        answer[i] += answer[i - 1];
    return answer;
}

void main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> bookings(m, vector<int>(3));
    for (int i = 0; i < m; ++i) {
        cin >> bookings[i][0] >> bookings[i][1] >> bookings[i][2];
    }
    vector<int> result = corpFlightBookings(bookings, n);
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
}