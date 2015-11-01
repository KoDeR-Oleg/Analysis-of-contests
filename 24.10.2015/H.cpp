#include<cstdio>
#include<algorithm>
#include<memory.h>
using namespace std;

char a[1111];
 
int main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
     
    scanf("%s",&a);
    int n = strlen(a);
    reverse(a,a+n);
    a[n++] = '0';
    for(int i=0;i<n;++i) if(a[i]!='9'){
        ++a[i];
        for(int j=0;j<i;++j) a[j] = '0';
        break;
    }
    while(n&& a[n-1]=='0') --n;
    a[n]=0;
    reverse(a,a+n);
    puts(a);
     
     
    return 0;
}
