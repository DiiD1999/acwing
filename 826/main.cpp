#include<iostream>

using namespace std;

const int N = 1000010;

int e[N], ne[N], head, idx;

void init() {
    head = -1;
    idx = 0;
}

void insert(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}
void insert_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}
void remove(int k) {
    ne[k] = ne[ne[k]];
}

