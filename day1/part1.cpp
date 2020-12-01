#include <fstream>
#include <iostream>
using namespace std;
ifstream fi("in.in");
int main(){
    int i=0;
    int a[1001];
    while(fi>>a[i++]);
    int n = i-1;
    cout<<n<<"\n\n";
    bool ok = 0;
    for(int i = 0; i < n - 1 and !ok; i++)
        for(int j = i+1; j < n and !ok; j++){
            if(a[i] + a[j] == 2020){
                ok = 1;
                cout<<i<<" "<<j<<" "<<a[i]<<" "<<a[j]<<" "<<a[i]+a[j]<<" product is "<<a[i]*a[j]<<'\n';
            }
        }
    return 0;
}