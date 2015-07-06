#include <algorithm>
#include <cstdio>
#include <deque>
#include <queue>
#include <string>
#include <vector>

#include <iostream>
#include <sstream>

#define pb push_back;
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
typedef long long llong;
typedef unsigned long long ullong;

string stra, strb;
vvi mat;

int getVal(int posa, int posb){
  //cout << posa <<" "<< posb << endl;
  if( posa <0 && posb<0) return 0;
  if(posa < 0) return posb+1;
  if(posb < 0) return posa+1;
  if(mat[posa][posb] != -1) return mat[posa][posb];
  int res = 1e6;
  if(stra[posa] == strb[posb]) res = getVal(posa-1, posb-1);
  res = min(res,1 + getVal(posa -1, posb - 1)); // change
  res = min(res,1 + getVal(posa, posb - 1)); // insert
  res = min(res,1 + getVal(posa - 1, posb)); // delete
  return mat[posa][posb] = res;
}

int main(){
  //freopen(stdin,"input.txt","r");
  //freopen(stdout,"output.txt","w");
  cin >> stra >> strb;
  mat.resize(sz(stra),vi(sz(strb),-1));
  cout << getVal(sz(stra)-1,sz(strb)-1);
  return 0;
}
