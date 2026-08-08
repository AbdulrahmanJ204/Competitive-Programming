#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define left 2*idx , lx , (lx+rx)/2
#define right 2*idx +1 ,(lx+rx)/2 +1 , rx

int seg_size;

template<typename T> struct SEG{
  vector<T> tree;
  T neutral  = 0;
  int size = 1;
  SEG(int n){
    seg_size = n;
    while (size<=n)  size*=2;
    tree.assign(2*size , neutral);  
  }

  T merge(T a , T b){
    return a+b;
  }
  T build (vector<int> &a , int idx =1, int lx =1 , int rx = seg_size){
    if(lx==rx) return tree[idx]=a[lx];
    return merge(build(a , left) , build(a , right));
  }
  T set(int index , int value , int idx = 1 , int lx = 1 ,int rx = seg_size){
    if(lx==rx){
      return tree[idx]=value;
    }
    int mid = (lx+rx)/2;
    if(index<= mid) set(index, value , left);
    else set(index , value , right);
    return tree[idx]= merge(tree[2*idx] , tree[2*idx+1]);
  }
  T query(int l , int r ,  int idx = 1 , int lx = 1 ,int rx = seg_size){
    if(lx > r || rx < l ) return neutral;
    if(lx>= l && rx <= r) return tree[idx];
    return merge(query(l , r ,left) , query(l , r , right));
  }
};