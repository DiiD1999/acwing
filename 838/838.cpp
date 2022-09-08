#include<iostream>

using namespace std;

const int N = 100010;
int h[N], si;

void down(int u) {
    int t = u;
    if (u * 2 <= si && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= si && h[u * 2 + 1] < h[t]) t = u * 2 + 1;

    if (t != u) {
        swap(h[t], h[u]);
        down(t);
    }
}

void up(int u) {
    int t = u;
    while (u / 2 && h[u] < h[u / 2]) {
        swap(h[u], h[u / 2]);
        u = u / 2;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    si = n;
    // 第一个建堆方式，复杂度为O(N)
    // 初始化建堆采用
    // for (int i = n / 2; i >= 0; i--) {
    //     down(i);
    // }
    
    // 第二种建堆方式，复杂度为O(NlogN)
    // 插入时采用
    for (int i = 1; i <= n; i++) {
        down(i);
        up(i);
    }
    for(int i = 0; i < m; i++) {
        cout << h[1] << " ";
        h[1] = h[si];
        si--;
        down(1);
    }
    return 0;
}
