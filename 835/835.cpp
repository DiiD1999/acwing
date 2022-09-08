#include<iostream>
#include<cstring>
#include<string>

using namespace std;

const int N = 100010;
int son[N][26], cnt[N], idx = 0;

void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) {
            idx ++;
            son[p][u] = idx;
        }
        p = son[p][u]; 
    }
    cnt[p]++;
}
int query(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!son[p][u]) {
            return 0;
        }
        p = son[p][u];
    } 
    return cnt[p];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        string op, s;
        cin >> op >> s;
        if (op == "I") {
            insert(s); 
        } 
        if (op == "Q") {
            cout << query(s) << endl;
        }
    }
    return 0;
}
