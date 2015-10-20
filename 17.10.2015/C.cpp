#include<iostream>
#include<string>
#include<memory.h>
using namespace std;

const int N = 3003;

char a[N], b[N];

short d[N][N];
short d2[N][N];

int main(){
    int n, m;

    gets(a);
    gets(b);
    n = strlen(a);
    m = strlen(b);

    for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			if(a[i]==b[j]){
				d[i][j] = 1;
				if(i && j) d[i][j]+=d[i-1][j-1];
			}

    for(int i=n-1;i>=0;--i)
		for(int j=m-1;j>=0;--j)
			if(a[i]==b[j]){
				d2[i][j] = 1;
				if(i+1<n && j+1<m) d2[i][j]+=d2[i+1][j+1];
			}

    for(int i=n-1;i>=0;--i)
		for(int j=m-1;j>=0;--j){
			if(i+1<n) {
				d2[i][j] = max(d2[i][j], d2[i+1][j]);
			}
			if(j+1<m) {
				d2[i][j] = max(d2[i][j], d2[i][j+1]);
			}
		}

    int ans=0, a1=0, a2=0, ai=0, aj=0;
    for(int i=0;i<n;++i)
		for(int j=0;j<m;++j){
			int res = d[i][j] + d2[i+1][j+1];
			if(ans<res){
				ans = res;
				a1 = d[i][j];
				a2 = d2[i+1][j+1];
				ai = i;
				aj = j;
			}
		}

    string s1 = string(a+ai-a1+1, a+ai+1);
    string s2;

    memset(d2, 0, sizeof d2);
    for(int i=n-1;i>=0;--i)
		for(int j=m-1;j>=0;--j)
			if(a[i]==b[j]){
				d2[i][j] = 1;
				if(i+1<n && j+1<m) d2[i][j]+=d2[i+1][j+1];
			}

    for(int x=ai+1;x<n;++x)
		for(int y=aj+1;y<m;++y)
			if(d2[x][y]==a2){
				s2 = string(a+x, a+x+a2);
				x=n;
				break;
			}

    cout<<s1<<endl<<s2<<endl;

    return 0;
}
