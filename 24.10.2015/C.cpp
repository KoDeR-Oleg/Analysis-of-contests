#include<iostream>
#include<cstdio>
#include<vector>
#include<memory.h>
using namespace std;

const int N = 111;
const int V = N*N*2;

char s[N][N];
vector<int> g[V];
int d[V], q[V];

void add(int i, int j){
    g[i].push_back(j);
}

int main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    int n, m;
    
    scanf("%d%d",&n,&m);
    int ax,ay,bx,by;
    for(int i=0;i<n;++i){
        scanf("%s",&s[i]);
        for(int j=0;j<m;++j){
            if(s[i][j]=='S') ax=i,ay=j,s[i][j]='.';
            if(s[i][j]=='E') bx=i,by=j,s[i][j]='.';
        }
    }
    
    int dx[] = {0,1,0,-1};
    int dy[] = {-1,0,1,0};
    for(int i=0;i<n;++i)
    for(int j=0;j<m;++j) if(s[i][j]!='#'){
        for(int k=0;k<4;++k){
            int x = i+dx[k];
            int y = j+dy[k];
            if(x<0 || y<0 || x>=n || y>=m || s[x][y]=='#') continue;
            for(int h1=0; h1<=(s[i][j]=='B'); ++h1)
            for(int h2=0; h2<=(s[x][y]=='B'); ++h2){
                int v1 = (i*m+j)*2 + h1;
                int v2 = (x*m+y)*2 + h2;
                if(s[i][j]=='.' && s[x][y]=='.') add(v1,v2);
                if(s[i][j]=='.' && s[x][y]=='B') if(k%2!=h2) add(v1,v2);
                if(s[i][j]=='B' && s[x][y]=='.') if(k%2!=h1) add(v1,v2);
                if(s[i][j]=='B' && s[x][y]=='B') if(h1==h2 && k%2!=h2) add(v1,v2);
            }
        }
    }
    
    int qn = 0;
    q[qn++] = (ax*m+ay)*2;
    memset(d, 63, sizeof d);
    d[*q] = 0;
    for(int k=0;k<qn;++k){
        int i = q[k];
        for(int j : g[i]) if(d[j]>d[i]+1){
            d[j] = d[i]+1;
            q[qn++] = j;
        }
    }
    int b = (bx*m+by)*2;
    if(d[b]>1e9) cout<<-1; else cout<<d[b];
       
    return 0;
}

