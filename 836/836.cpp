#include<iostream>
#include<string>
#include<cstring>

using namespace std;
const int N = 100010;
int p[N];
int find(int x) {
   if (p[x] != x) {
       p[x] = find(p[x]);
   } 
   return p[x];
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
    while (m--) {
        string op;
        int a, b;
        cin >> op >> a >> b;
        if (op == "M") {
            if (find(a) == find(b)) continue;          
            p[find(a)] = find(b);
        }
        if (op == "Q") {
           if (find(a) == find(b)) {
               cout << "Yes" << endl;
           } else {
               cout << "No" << endl;
           }
        }
    }
    return 0;
}
