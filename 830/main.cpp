#include<iostream>

using namespace std;

const int N = 1000010;
int stk[N], tt = 0;
int main(){
    int n;
    cin >> n;
    while (n--) {
        int m;
        cin >> m;
        while (tt > 0 && stk[tt] >= m) {
            tt--;
        }
        if (tt > 0) {
            cout << stk[tt] << " ";
        } else {
            cout << "-1" << " ";
        }
        tt++;
        stk[tt] = m; 
    }
    return 0;
}
