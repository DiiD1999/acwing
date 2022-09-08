#include<iostream>

using namespace std;

const int N = 100010;

bool isOperation(char c){
   if ( c == '+' || c == '/' || c == '-' || c == '*' ) {
       return true;
   }
   return false;
}
bool isBracket(char c) {
    if (c == '(' || c == ')') {
        return true;
    }
    return false;
}

int main() {
    string ex;
    cin >> ex;
    stack<char> num;
    stack<char> sym;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (isSym(ex[i])) {
            
        }
    }
}
