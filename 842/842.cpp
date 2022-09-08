#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
const int N = 10;
void dfs(vector<int>& q, vector<int>& tmp, bool used[]) {
    if (q.size() == tmp.size()) {
        for (int i = 0; i < q.size(); i++) {
           cout << tmp[i] << " " ;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < q.size(); i++) {
        if (!used[i]) {
            used[i] = true;
            tmp.emplace_back(q[i]);
            dfs(q, tmp, used);
            used[i] = false;
            tmp.pop_back();
        }
    }
    return ;
}
int main() {
    int n;
    cin >> n;
    vector<int> q;
    for (int i = 0; i < n; i++) {
        q.emplace_back(i + 1);
    }
    vector<int> tmp;
    bool used[N];
    memset(used, 0, N);
    dfs(q, tmp, used);
    return 0;
}
