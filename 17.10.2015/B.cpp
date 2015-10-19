#include<iostream>

using namespace std;

const int N = 1e6+6;
int a[N];

int main(){
    int n, m;

    cin >> n;
    n = (n*n-n)/2;

    m = 0;
    a[m++] = 1;
    for(int k=1;k<=n;++k)
        for(int i=0, o=0;i<m || o;++i){
            o = a[i] * 3 + o;
            a[i] = o % 10;
            o /= 10;
            m = max(m, i+1);
        }
    for(int i=m-1;i>=0;--i) cout<<a[i];

    return 0;
}

