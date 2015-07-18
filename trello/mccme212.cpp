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
int n;
vi a,b,c;
vi row;
int getValue(int i){
  //debug << i << endl;
  
  if(i == n) return 0;
  if(i > n) return 100500;
  
  //debug << row[i] <<endl; 
  if(row[i] != -1) return row[i];
  int res = a[i] + getValue(i+1);
  res = min(res, b[i] + getValue(i+2));
  res = min(res, c[i] + getValue(i+3));
  //debug << i << "-" << res<<endl;
  return row[i] = res;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> n;
    a = vi(n, 0);
    b = vi(n, 0);
    c = vi(n, 0);
    row = vi(n, -1);
    forc(i,n)
      cin >> a[i] >> b[i] >> c[i];  
    cout << getValue(0);
  return 0;
}
