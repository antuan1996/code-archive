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
  int upBound = 1000000;
  vi sum(upBound+1,1);

  void findPrimes(){
    int i;
    for(i = 2; i <= upBound; ++i)
      for(int cur = 2*i; cur <= upBound ;cur += i)
          sum[cur] += i;
  }
  int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    findPrimes();
    sum[1] = 0;
    //cout<<"go"<<endl;
    int low, up;
    cin >> low >> up;
    double mintr = 1e8;
    int res = 0;
    for(int curn = low; curn <= up; ++curn){
      double tr = 1.* sum[curn] / curn ;
      //cout << tr <<endl;
      if(tr < mintr){
        mintr = tr;
        res=  curn;
      }
    }
    cout << res;
    return 0;
  }
   
