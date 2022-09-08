#include<iostream>
using namespace std;

const int N = 1000010;
int e[N], r[N], r[N], idx, head;

void init(){
    idx = 2;
    r[0] = 1;
    l[1] = 0;
}

void insert(int k, int x) {
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;
    idx++;
}

void remove(int k ){
    r[l[k]] = r[k];
    l[r[k]] = l[k];
}
