#include <bits/stdc++.h>
using namespace std;

struct node{
  pii p;
  node *left, *right;
  node(pii p, node* a=nullptr, node* b=nullptr):p(p), left(a), right(b){}
};
vector<function<bool(pii, pii)>> cmp{
  [](const pii& a, const pii& b){return a<b;},
  [](const pii& a, const pii& b){return mp(b.ss,b.ff)<mp(a.ss,a.ff);}
};
node* func(vector<pii>& v, int l, int r, int c){
  DD(l,r);
  if(l==r) {
    auto nw=new node(v[l], nullptr, nullptr);
    return nw;
  }
  else if(l>r) return nullptr;
  sort(v.begin()+l, v.begin()+r+1,cmp[c]);
  int mid=l+(r-l+1)/2;
  auto nw=new node(v[mid]);
  nw->left=func(v, l, mid-1,c^1);
  nw->right=func(v,mid+1,r,c^1);
  DD(nw->p.ff, nw->p.ss);
  return nw;
}
void print(node*& root){
  if(!root) return ;
  printf("(%d, %d)", root->p.ff, root->p.ss);
  cout<<'('; print(root->left); cout<<',';  print(root->right); cout<<')'; 
}

int main() {
    int n; cin>>n;
    vv<pii> v(n); for(int i=0;i<n;++i) cin>>v[i].ff>>v[i].ss;
    auto head=func(v,0,n-1,0);
    print(head);
}
