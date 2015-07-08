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

int n, p;
vector < vector <bool> > haveWay;
vi age;

int step;
int value;

int rdist;
vi rvec;
queue < int > nex; 
bool fillAge(){
  while(!nex.empty()){
    int curp =  nex.front();
    //debug << curp << endl;
    nex.pop();
    forc(i,p)
      if(haveWay[curp][i]){
        if(age[i] == -1){
          age[i] = age[curp] + step;
          nex.push(i);
        }
        else
          if(abs(age[i] - age[curp]) != 1) return false;
      }
  }
  step = -1;
  value = 50;
  return true;
}

void findWay(){
  bool f;
  forc(start,p){
      age.clear();
      age.resize(p , -1);
      f = 1;
      value = 1;
      step = 1;
      forc(i,p)
        if(age[(start+i)%p]==-1){
          age[(start+i)%p] = value;
          nex.push((start+i)%p);
          f = f && fillAge();
      }
      if(f){
        int least = 1;
        int greatest = 0;
        int curd;
        forc(i,p)
          greatest = max(greatest, age[i]);
        curd = greatest - least;
        if(curd > rdist){
          rdist = curd;
          rvec = age;
        }
      }
  }
}

int main(){
  //freopen(stdin,"input.txt","r");
  //freopen(stdout,"output.txt","w");
  value = 1;
  step = 1;
  rdist = -1;
  cin >> n >> p;
  age.resize(p , -1);
  haveWay.resize(p, vector< bool >(p,0));
  forc(i,n){
    int from, to;
    cin >> from >> to;
    --from;
    --to;
    haveWay[from][to] = 1;
    haveWay[to][from] = 1;
  }
  findWay();
  if(rdist >=0){
    cout << rdist <<"\n";
    forc(i,p)
      cout << rvec[i] << " ";
  }
  else
    cout << -1;
  return 0;
}
