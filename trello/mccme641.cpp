#include <algorithm>
#include <cstdio>
#include <deque>
#include <queue>
#include <string>
#include <vector>

#include <iostream>
#include <sstream>

#define pb push_back
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

struct label{
  llong point;
  int type; // 1 - begin; (-1) - end
};
bool comp(label a, label b){
  if(a.point == b.point) return a.type < b.type;
  return a.point < b.point;
}
vector <label> row;
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int n;
  cin >> n;
  forc(i,n){
    label curLabel;
    int l,r;
    cin >> l >> r;
    
    curLabel.point = l;
    curLabel.type = 1;
    row.pb(curLabel);
    
    curLabel.point = r;
    curLabel.type = -1;
    row.pb(curLabel);
    
  }
  sort(row.begin(), row.end(),comp);
  llong num = 0;
  llong last = 0;
  llong res = 0;
  forc(i,sz(row)){
    label curLabel = row[i];
    if(num == 1 && curLabel.type == -1) res += curLabel.point - last;
    if(num == 0 && curLabel.type == 1) last = curLabel.point;  
    num += curLabel.type;
  }
  cout << res;
  return 0;
}
