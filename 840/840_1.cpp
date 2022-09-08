// 拉链法
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

// get
const int N = 100003;
int h[N], e[N], ne[N], idx = 0;

void insert(int x) {
    // C++ 负数取模是负数，所以需处理
    int k = (x % N + N) % N; 
    e[idx] = x;
    ne[idx] = h[k];
    h[k] = idx++;
}

bool find(int x) {
    int k = (x % N + N) % N;
    // h[k] 存储链表的指针值，e[i]才是实际的结果值
    for (int i = h[k]; i != -1; i = ne[i]) {
        if (e[i] == x) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;
    memset(h, -1, sizeof(h));
    while (n--) {
        string op;
        int x;
        cin >> op >> x;
        if ( op == "I") {
            insert(x);
        } else {
            if (find(x)) {
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
