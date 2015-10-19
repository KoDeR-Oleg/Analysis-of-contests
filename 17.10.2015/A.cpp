#include<iostream>

using namespace std;

int main(){
    int n, m, a, b;
    cin >> n >> m;
    a = n;
    b = m;
    while(n && m) n>m ? n%=m : m%=n;
    cout << a * b / (n + m) << endl;
    return 0;
}
