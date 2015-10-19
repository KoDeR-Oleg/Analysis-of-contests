#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<assert.h>

using namespace std;

const int N = 111111;

int x[N], y[N];

set<int> h[N], v[N], d1[N], d2[N];
vector<int> uh, uv, ud1, ud2;
int ph[N], pv[N], pd1[N], pd2[N];

void un(vector<int> &a){
    sort(a.begin(),a.end());
    auto it = unique(a.begin(),a.end());
    a.resize(it-a.begin());
}

int main(){
    int n, m;

    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",&x[i],&y[i]);
        uh.push_back(y[i]);
        uv.push_back(x[i]);
        ud1.push_back(x[i]+y[i]);
        ud2.push_back(x[i]-y[i]);
    }
    un(uh);
    un(uv);
    un(ud1);
    un(ud2);

    for(int i=0;i<n;++i){
        ph[i] = lower_bound(uh.begin(), uh.end(), y[i]) - uh.begin();
        h[ph[i]].insert(x[i]);
        pv[i] = lower_bound(uv.begin(), uv.end(), x[i]) - uv.begin();
        v[pv[i]].insert(y[i]);
        pd1[i] = lower_bound(ud1.begin(), ud1.end(), x[i]+y[i]) - ud1.begin();
        d1[pd1[i]].insert(x[i]);
        pd2[i] = lower_bound(ud2.begin(), ud2.end(), x[i]-y[i]) - ud2.begin();
        d2[pd2[i]].insert(x[i]);
    }

    int ans = 0;
    for(int i=0;i<n;++i){
        int ax = i ? x[i-1] : 0;
        int ay = i ? y[i-1] : 0;
        int bx = x[i];
        int by = y[i];
        if(ay==by){
            if(ax>bx) swap(ax,bx);
            set<int> &q = h[ph[i]];
            auto k = q.upper_bound(ax);
            if(k==q.end() || *k>=bx) ++ans; else break;
        }else
        if(ax==bx){
            if(ay>by) swap(ay,by);
            set<int> &q = v[pv[i]];
            auto k = q.upper_bound(ay);
            if(k==q.end() || *k>=by) ++ans; else break;
        }else
        if(ax+ay==bx+by){
            if(ax>bx){
                swap(ax,bx);
                swap(ay,by);
            }
            set<int> &q = d1[pd1[i]];
            auto k = q.upper_bound(ax);
            if(k==q.end() || *k>=bx) ++ans; else break;
        }else
        if(ax-ay==bx-by){
            if(ax>bx){
                swap(ax,bx);
                swap(ay,by);
            }
            set<int> &q = d2[pd2[i]];
            auto k = q.upper_bound(ax);
            if(k==q.end() || *k>=bx) ++ans; else break;
        }else break;

        h[ph[i]].erase(x[i]);
        v[pv[i]].erase(y[i]);
        d1[pd1[i]].erase(x[i]);
        d2[pd2[i]].erase(x[i]);
    }

    cout<<ans<<endl;

    return 0;
}
