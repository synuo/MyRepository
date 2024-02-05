#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <cstdio>
#define INF 1000000001
using namespace std;
vector<long long> tree_min;
vector<int> v;
long long init(int node,int start,int end){
    if(start == end){tree_min[node] = v[start]; return tree_min[node];}
    return tree_min[node] = min(init(node*2,start,(start+end)/2),init(node*2+1,(start+end)/2+1,end));
}
long long update(int node,int start,int end,int idx,int val){
    if(start>idx || end<idx){return tree_min[node];}
    if(start == end){return tree_min[node] = val;}
    else{
        return tree_min[node] = min(update(node*2,start,(start+end)/2,idx,val),update(node*2+1,(start+end)/2+1,end,idx,val));
    }
}
long long query(int node,int start,int end,int left,int right){
    if(left>end||right<start){return INF;}
    if(left<=start&&right>=end){
        return tree_min[node];
    }
    else{
        return min(query(node*2,start,(start+end)/2,left,right),query(node*2+1,(start+end)/2+1,end,left,right));
    }
}
int main(void){
    int N,M;
    cin >> N;
    v.resize(N);
    for(int i = 0;i<N;i++){scanf("%d",&v[i]);}
    int tree_size = (1<<((int)ceil(log2(N))+1));
    tree_min.resize(tree_size);
    init(1,0,N-1);
    cin >> M;
    for(int i = 0;i<M;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        if(a == 1){
            v[b-1] = c;
            update(1,0,N-1,b-1,c);
        }
        else{
            printf("%lld\n",query(1,0,N-1,b-1,c-1));
        }
    }
}