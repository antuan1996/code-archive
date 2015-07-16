#include <algorithm>
#include <cctype>
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

  string str;

int getMod(int base, int div){
  int curn = 0 ;
  forc(i,sz(str)){
    int dig = (isalpha(str[i]))? 10 + str[i] - 'A' : str[i] - '0';  
    curn = curn * base + dig;
    curn %= div; 
  }
  return curn;
    
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  cin >> str;
  int minbase = 2;
  forc(i,sz(str)){
    int dig = (isalpha(str[i]))? 10 + str[i] - 'A' : str[i] - '0';  
    minbase = max(dig + 1, minbase);
  }
  
  int f = 0;
  for(int k = minbase; k <= 36; ++k)
    if(getMod(k,k-1) == 0)
    { 
      cout << k;
      ++f;
      break;
    }
  if(!f) cout << "No solution."; 
  return 0;
}
