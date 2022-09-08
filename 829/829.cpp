#include<iostream>
#include<string>
using namespace std;

const int N = 1000010;

int q[N];
int hh = 0; 
int tt = -1;

void push(int x) {
   q[++tt] = x; 
}

void pop() {
    hh++;
}

bool isEmpty() {
    if (hh <= tt) {
        return false;
    }
    return true;
}

int front(){
    return q[hh];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n--) {
        string op;
        cin >> op;
        if (op == "push") {
            int x;
            cin >> x;
            push(x);
        }
        if (op == "pop") {
            pop();
        }
        if (op == "empty") {
           if (isEmpty()) {
               cout << "YES" << endl; 
           } else {
               cout << "NO" << endl; 
           }
        }
        if (op == "query") {
           cout << front() << endl; 
        }
    }
    return 0;
}
