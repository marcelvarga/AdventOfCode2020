#include <iostream>
#include <fstream>
#include <cstring>
#define N 93
#define M 97
using namespace std;

const int coords[9][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

void border(char a[100][100]){
    for(int i = 0; i <= N +1; i++){
        a[i][0] = '.';
        a[i][M+1] = '.';
    }
    for(int j = 0; j <= M +1; j++){
        a[0][j] = '.';
        a[N+1][j] = '.';
    }
}

void read(char a[100][100]){
    ifstream fi("in.in");
    char c[100];

    int n = 0;
    while(fi.getline(c,100)){
        n++;
        strcpy(a[n]+1,c);
    }
    fi.close();
}

bool swap(char a[100][100], char b[100][100], int i, int j){
    int AdjOccupied = 0;
    for (int k = 0; k <=7; k++)
        if(a[i+coords[k][0]][j+coords[k][1]] == '#') AdjOccupied++;
    if (a[i][j] == 'L' && !AdjOccupied) {b[i][j] = '#'; return 1;}
    if (a[i][j] == '#' && AdjOccupied >= 4) {b[i][j] = 'L'; return 1;}
    b[i][j] = a[i][j];
    return 0;
}

bool ChangeSeats(char a[100][100]){
    char b[100][100];
    bool changed = 0;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++){
            bool ok = swap(a, b, i, j);
            changed = changed || ok;
        }
    for(int i = 0; i <= N+1; i++)
        for(int j = 0; j <= M+1; j++)
            a[i][j] = b[i][j];
    return changed;
}

int main(){
    char a[100][100];
    read(a);
    border(a);
    while(ChangeSeats(a));
    int ANS = 0;

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(a[i][j] == '#') ANS++;
    
    cout <<ANS<<'\n';
    return 0;
}
