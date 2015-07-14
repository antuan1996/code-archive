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
void fillPrime(int upBound){
  vector <bool> row(upBound+1,0);
  int i;
  for(i = 2; i*i <= upBound; ++i)
    if(row[i] == 0){
      prime.pb(i);
      for(int del = i*i; del <= upBound; del += i)
        row[del] = 1;
    }
  for(;i<= upBound; ++i)
    if(row[i] == 0) prime.pb(i);
}
int findDel(int n){
  forc(i,sz(prime))
    if( n % prime[i] == 0) return n/prime[i];
  return 1;
}
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  fillPrime(1000000);
  //  cout << sz(prime);
  int t;
  cin >> t;
  forc(p,t){
    
      int n;
      cin >> n;
      int step = findDel(n);
      //cout << step <<endl;
      cout << "0 1 ";
      for(llong i = step; i<n; i+= step){
          if(i*(i-1) % n == 0)
            cout << i <<" ";
          if(i*(i+1) %n == 0)
              cout << i+1 <<" ";
      }
      cout << "\n";
    }
  return 0;
}
