#include<bits/stdc++.h>
using namespace std;
int findDamagedToy(int N,int T,int D)
{
    if(T>N)
    {
      T=T-N;
    }
  return D+T-1;
}
int main()
{
    int N=5,T=2,D=1;
    cout<<findDamagedToy(N,T,D)<<endl;
    return 0;
}