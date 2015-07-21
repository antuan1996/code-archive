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
#define forn(i,n) for(int i = 0; i < (n); ++i)

using namespace std;
stringstream fakestream;

struct debug_t{
template <typename T> debug_t& operator <<(const T& value){
#ifdef LOCAL_PROJECT
  cout << value << flush;
#endif // LOCAL_PROJECT
  return *this;
  }
} debug;
typedef vector < int > vi;
typedef vector < vi > vvi;
typedef pair <int,int> pi;
typedef long long llong;
typedef unsigned long long ullong;

//eil(n) = n*(1-1/p1)*(1-1/p2)...

int getEil(int n){
  int res = n;
  for(int i = 2; i*i <= n; ++i)
    if(n % i == 0){
      res -= res/i;
      while(n % i == 0) n /= i;
    }
   if(n > 1) res -= res / n; 
  return res;
} 

int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n;
  while(cin >> n && n)
    cout << getEil(n) << "\n";
  return 0;
}
