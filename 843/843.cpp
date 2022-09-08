#include<bits/stdc++.h>

using namespace std;

const int N = 20;
int n;
bool h[N], dg[N], udg[N];
char g[N][N];
void dfs(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++){
            cout << g[i] << endl;
        }
        return ;
    }
    for (int i = 0; i < n; i++) {
        if (!h[i] && !dg[u + i] && !udg[n - u + i]) {
            g[u][i] = 'Q';
            h[i] = dg[u + i] = udg[n - u + i] = true;
            dfs(u + 1);
            g[u][i] = '.';
            h[i] = dg[u + i] = udg[n - u + i] = false;
        }
    }
}
int main(){
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
