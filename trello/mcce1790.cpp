#include <algorithm>
#include <cstdio>
#include <deque>
#include <queue>
#include <string>
#include <vector>

#include <iostream>
#include <sstream>

#define pb(a) push_back(a);
#define mp make_pair
#define sz(x) ((int)(x.size()))
#define forc(i,n) for(int i = 0; i < n; ++i)

using namespace std;
stringstream fakestream;

#ifdef LOCAL_PROJECT
  #define debug cerr
#else
  #define debug fakestream
#endif // LOCAL_PROJECT

typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair <int,int> pi;
typedef long long ll;
typedef unsigned long long ull;
int n,m;
vi rowa, rowb;
vvi mat;
vvi sh;
vi res;
int getVal(int posa, int posb){
  if(posa < 0 || posb < 0) return 0;
  if (mat[posa][posb]!= -1) return mat[posa][posb];
  int res = 0;
  int cur;
  if(rowa[posa ] != rowb[posb ]){
     cur = getVal(posa-1,posb);
     if(cur > res){
          res = cur;
          sh[posa][posb] = -1;
      }
     cur = getVal(posa,posb-1);
     if(cur > res){
          res = cur;
          sh[posa][posb] = 1;
      }
  }
  else{
    sh[posa][posb] = 0;
    res = 1 + getVal(posa-1, posb-1);
  }
  return mat[posa][posb] = res;
}
void show(int posa, int posb){
  if(posa < 0 || posb < 0) return;
  if(sh[posa][posb] == 0){
     res.pb(rowa[posa]);
     show(posa-1, posb-1);
  }
    else{
      if(sh[posa][posb] == -1)
        show(posa-1,posb);
      else 
        show(posa,posb-1);
  }
}
int main(){
  //freopen(stdin,"input.txt","r");
  //freopen(stdout,"output.txt","w");
  cin >> n;
  rowa.resize(n,0);
  forc(i,n)
    cin >> rowa[i];
  cin >> m;
  rowb.resize(m,0);
  forc(i,m)
    cin >> rowb[i];
  mat.resize(n, vi(m,-1));
  sh.resize(n, vi(m,-1));
  getVal(sz(rowa)-1,sz(rowb)-1);
  show(sz(rowa)-1,sz(rowb)-1);
  for(int i = sz(res)-1; i>=0; --i)
    cout << res[i] << " ";
  return 0;
}
