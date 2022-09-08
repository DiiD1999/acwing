//#include<iostream>
//#include<queue>
//#include<vector>
#include<bits/stdc++.h>

using namespace std;
const int N = 110;
int nums[N][N];
int dis[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> nums[i][j];
            dis[i][j] = 0;
        }
    }

    queue<pair<int,int>> q;
    q.push(pair<int, int>(0, 0));
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while(!q.empty()) {
        pair<int, int> pa = q.front();
        q.pop();
        if (pa.first == n - 1 && pa.second == m - 1) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int x = pa.first + dx[i];
            int y = pa.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && dis[x][y] == 0 && nums[x][y] == 0) {
                q.push(pair<int, int>(x, y));
                dis[x][y] = dis[pa.first][pa.second] + 1;
            }
        }

    }
   /* 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << dis[n - 1][m - 1] << endl; 
    return 0;
}
