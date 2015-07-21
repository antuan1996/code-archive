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

struct BigInt{
  vector < short > data;
  void operator *= (int n);
  void print_out(); 
};

void BigInt::operator *=(int n){
  int buf =0;
  forn(i,sz(data)){
    buf += data[i] * n;
    data[i] = buf % 1000;
    buf /= 1000;
  }
  while(buf){
    data.pb(buf % 1000);
    buf /= 1000;
  }
}
void BigInt::print_out(){
  cout << data[sz(data)-1];
  for(int i =sz(data)-2; i>=0; --i)
  {
    if(data[i] < 100) cout << "0";
    if(data[i] < 10) cout << "0";
    cout << data[i]; 
  }
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int n;
  while(cin >> n){
    BigInt num;
    num.data.pb(1);
    for( int mn = 1; mn <= n; ++mn)
      num *= mn;
    cout << n <<"!\n";  
    num.print_out();
    cout << "\n";
  }
  return 0;
}
