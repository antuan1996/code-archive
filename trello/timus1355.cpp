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

vi prime;

void primeFill(int upBound){
  vector <bool> row(upBound,1);
  int del;                              //del += 2 
  for( del= 2; del*del <= upBound; ++del){
    if(row[del]){
      prime.pb(del);
      for(int i = del*del; i <= upBound; i+=del)
        row[i] = false;
    }
  }
  for(;del < upBound; ++del)
    if(row[del]) 
      prime.pb(del);
}

int main(){
  //freopen(stdin,"input.txt","r");
  //freopen("output.txt","w",stdout);
  //primeFill(1000000000);
  int t;
  cin >> t;
  int a,b;
  forc(testnum, t){
    cin >> a  >>  b;
    if(b % a) cout<< 0 << "\n";
    else{
      int res =1; 
      b /= a;
        for(int del = 2; del*del <= b;)
          if(b % del == 0){
            b /= del;
            ++res;
          }
          else
           ++del;
        if(b != 1) ++res;
      cout << res << "\n";
    }
  }
  return 0;
}
