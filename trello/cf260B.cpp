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
typedef long long ll;
typedef unsigned long long ull;

vi num;

void dec(){
  int curpos = sz(num) - 1;
  if(curpos == 0 && num[curpos]==0) return;
  bool buf = 1;
  while(buf && curpos >= 0){ 
    if(num[curpos] > 0){
       --num[curpos];
       buf = 0;
     } 
     else{
       num[curpos] = 9;
       --curpos;
     } 
  }
}
int getSum(){
  int res = 0;
  forc(i,sz(num))
    res += num[i];
  return res;
}
int mod2[] = {6, 2, 4, 8};
int mod3[] = {1, 3, 9, 7};
int mod4[] = {6, 4, 6, 4};

int main(){
  //freopen(stdin,"input.txt","r");
  //freopen(stdout,"output.txt","w");
  string s;
  cin >> s;
  num.resize(sz(s),0);
  forc(i,sz(s))
    num[i] = s[i]-'0';
  int digital;
  if(sz(num)==1 && num[0]==0){
    digital = 4;
  }
  else{
    int last = sz(num) - 1;
    int mod = (last>0)? num[last-1]*10 + num[last] : num[last];
    mod %= 4;
    digital = 1+ mod2[mod] + mod3[mod] + mod4[mod];
  }
  cout << digital % 5; 
  return 0;
}
