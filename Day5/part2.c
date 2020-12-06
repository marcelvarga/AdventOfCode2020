#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX(X, Y) ((X > Y) ? (X) : (Y))
#define MIN(X, Y) ((X < Y) ? (X) : (Y))

const int rows = 127, columns = 7;
const int maxlen = 12;
int seat(char *s){
    int rmin = 0, rmax = rows;
    int cmin = 0, cmax = columns;
    for (int i = 0; i <= 6; i++){
        if (s[i] == 'F') rmax -= (rmax - rmin + 1) / 2;
        if (s[i] == 'B') rmin += (rmax - rmin + 1) / 2;
    }
    for (int i = 7; i <= 9; i++){
        if (s[i] == 'R') cmin += (cmax - cmin + 1) / 2;
        if (s[i] == 'L') cmax -= (cmax - cmin + 1) / 2;
    }
    return (rmin * 8 + cmin);
}

int main(){
    FILE *in = fopen("in.in", "r");
    char s[maxlen];
    int mi = 1000;
    bool present[830];
    for(int i = 0; i < 830; i++) 
        present[i] = 0;

    fgets(s,maxlen,in);
    while (! feof(in)){
        int x = seat(s);
        mi = MIN(mi,x);
        present[x] = 1;
        fgets(s,maxlen,in);
    }
    fclose(in);

    bool ok = 0;
    for(int i = mi; i < 830 && !ok; i++)
        if(!present[i]){
            printf("%d\n",i);
            ok = 1;
        }
    
}
