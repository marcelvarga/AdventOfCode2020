#include <fstream>
#include <iostream>
using namespace std;
ifstream fi("in.in");
int main(){
    int n=0, a[1001];;
    while(fi>>a[n++]);
    n--;
    bool ok = 0;
    for(int i = 0; i < n - 2 and !ok; i++)
        for(int j = i+1; j < n - 1 and !ok; j++)
            for(int k = j + 1; k < n and !ok; k++)
            if(a[i] + a[j] + a[k] == 2020){
                ok = 1;
                cout<<"Product is "<<a[i] * a[j] * a[k]<<'\n';
            }
	fi.close();        
    return 0;
}
