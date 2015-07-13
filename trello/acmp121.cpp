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
vi coord;
vvi dp;
int getVal(int i, int type){
  if(i == n-1 && type == 0) return 100500;
  if(i == n-1 && type == 1) return 0;
  if(dp[i][type] != -1) return dp[i][type];
  int res;
  int dist = coord[i+1] - coord[i];
  res = dist + getVal(i+1,1);
  if(type == 1) res = min(res, getVal(i+1,0));
  return dp[i][type] = res;
}
int main(){
  freopen("INPUT.TXT","r",stdin);
  freopen("OUTPUT.TXT","w",stdout);
  cin >> n;
  coord.resize(n,0);
  dp.resize(n,vi(2,-1));
  forc(i,n)
    cin >> coord[i];
  sort(coord.begin(),coord.end());
  cout << getVal(0,0);  
  return 0;
}
