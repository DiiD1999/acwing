// 开放寻址法
#include<iostream>
#include<cstring>

using namespace std;
// 开启2倍到3倍的空间比较合适
const int N = 200003;
const int pnull = 0x3f3f3f3f;

int h[N];

int find(int x) {
    int k = (x % N + N ) % N;
    while ( h[k] != pnull && h[k] != x) {
        k++;
        if (k == N) {
            k = 0;
        }
    }
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    // memset 字节赋值，int的4位字节, 分别赋值
    memset(h, 0x3f, sizeof(h));
    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        int k = find(x);
        if ( op == "I") {
            h[k] = x;
        } else {
            if ( h[k] != pnull) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
