#include<iostream>
#include<string>
#include<cstring>

using namespace std;

const int N = 1000010;

int p[N], si[N];

int find(int x) {
    if (p[x] != x) {
        p[x] = find(p[x]);       
    } 
    return p[x];
}

int main() {
    ios::sync_with_stdio();
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        p[i] = i;
        si[i] = 1;
    }

    while (m--) {
        string op;
        int a, b;
        cin >> op >> a;
        if ( op == "C" ) {
            cin >> b;
            if (find(a) == find(b)) continue;
            si[find(b)] += si[find(a)];
            p[find(a)] = find(b);
        }        
        if ( op == "Q1") {
            cin >> b;
            if (find(a) == find(b)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
        if ( op == "Q2" ) {
            cout << si[find(a)] << endl; 
        }
    }
    return 0;
}
