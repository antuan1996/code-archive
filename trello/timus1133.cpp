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
typedef long long llong;
typedef unsigned long long ullong;
typedef vector < llong > vi;
typedef vector < vi > vvi;
typedef pair <int,int> pi;

int  l, r;
llong rigVal;
vi row(2000+1,0);
int goRight(int start, int finish){
  for(int cur = start; cur <= finish; ++cur){
    row[cur] = row[cur-1] + row[cur-2];
    if(row[cur] > 2e9) return 1;
    if(row[cur] < -2e9) return -1;
  }
  return 0;
}
void goLeft(int start, int finish){
  for(int cur = start; cur >= finish; --cur)
    row[cur] = row[cur+2] - row[cur+1];
}

void getFib(){
  llong lowBound = -2e9;
  llong upBound = 2e9+1;
  forc(i,10000){
  int sep = (upBound + lowBound)/2;
  row[l+1] = sep;
  if(goRight(l+2, r) > 0 || row[r] > rigVal) upBound = sep;
    else lowBound = sep;
  }
  row[l+1] = lowBound;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int i,j;
  int fi, fj;
  cin >> i >> fi >> j >> fj;
  i += 1000;
  j += 1000;
  if(j < i) {swap(i,j); swap(fi,fj);}
  l = i;
  row[l] = fi;
  r = j;
  rigVal = fj;
  getFib();
  int n;
  cin >> n;
  n += 1000; 
  if(n < l) goLeft(l-1,n);
    else goRight(l+2,n);
  cout << row[n];
  return 0;
}
