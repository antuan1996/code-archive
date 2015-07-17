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

int getAmm(int n, int curdel, int mn){
  if(curdel > n) return 0;
  return n/curdel + getAmm(n, curdel*mn,mn); 
}
bool isPrime(int m){
    for(int i = 2; i*i <= m; ++i)
      if(m % i==0) return false;
    return true;  
}

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  int n;
  cin >> n;
  int res = 1;
  for(int i=2; i <= n; ++i)
    if(isPrime(i)){
       res*= getAmm(n,i,i)+1;
        cout << i<< getAmm(n,i,i)+1 << endl;
    }
  cout << res;  
  return 0;
}
