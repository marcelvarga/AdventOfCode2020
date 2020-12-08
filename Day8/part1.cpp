#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
enum {NOP, ACC, JMP};

void GetOperation(const char *s, int *op, int *value){
    if(strstr(s,"nop")) *op = NOP;
    if(strstr(s,"acc")) *op = ACC;
    if(strstr(s,"jmp")) *op = JMP;
    *value = atoi(s+4);
}

void solve(char input[1000][10], bool run[1000], int n, int PC, int *acc,  int *operations, int *values ){
    if(run[PC]) return;
    run[PC] = 1;
    switch (operations[PC]){
        case NOP : PC ++; break;
        case ACC : *acc += values[PC]; PC++; break;
        case JMP : PC += values[PC]; if(PC != n) PC %= n; if(PC < 0) PC += n; break;
    }
    solve(input,run,n,PC,acc, operations, values);
}
int read(char lines[1000][10], ifstream &fi){
    char s[10];
    int n = 0;
    while(fi.getline(s,10)){
        strcpy(lines[n], s);
        n++;
    }
    fi.close();
    return n;
}
int main(){
    char lines[1000][10];
    ifstream fi ("in.in");
    
    int n = read(lines, fi);
    bool run[1000];
    int operations[1000], values[1000];
    for (int i = 0; i < n; i++) {
        run[i] = 0;
        GetOperation(lines[i], &operations[i], &values[i]);
        }
    int ANS = 0;
    solve(lines, run, n, 0, &ANS, operations, values);
    cout<<ANS<<'\n';
    return 0;
}
