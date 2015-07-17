#include <algorithm>
#include <cstdio>
#include <cstdint>
#include <deque>
#include <queue>
#include <string>
#include <map>
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

vi price;
map <int,int> len;
void pushNum(int mask, int l){
  int res = 0;
  int amm = 0;
  forc(i,l)
    if(mask & (1<<i)){
       res += price[i];
       ++amm;
    }
  //debug << amm << endl; 
  //(len.count(res))? min( amm,len[res]) :  
  if(len.count(res))
   len[res] = min( amm,len[res]);
  else
   len[ res ] =  amm;
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int n, m;
  cin >> n >> m;
  int sum = 0;
  price.resize(m,0);
  forc(i,m)
    cin >> price[i];
  forc(i,m)
    sum += price[i];
  for(int cur = 1; cur < pow(2, m); ++cur){
    pushNum(cur,m);
    //debug << getNum(cur,m)<<endl;
  }
  //debug << sums.size();
  bool f = 0;
  int res = 100500;
  if(2*sum < n) { cout<< -1; return 0;}
  len[0] = 0;
  for( auto it = len.begin(); it != len.end();++it){
    int sec = n - it->first;
    if(len.count(sec))
    {
        //debug << endl;
        res = min(res,it->second +len[sec]);
        f = 1;
        //break;
    }
  }
  if(f) cout << res;
    else cout << 0;
  return 0; 
}
