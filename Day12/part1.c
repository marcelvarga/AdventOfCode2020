#include <stdio.h>
#include <stdlib.h>
enum {N,E,S,W,L,R,F};
const int coords[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
void values(char c[10], int *letter, int *number) {
    switch (c[0]) {
        case 'N': *letter = N; break;
        case 'E': *letter = E; break;
        case 'S': *letter = S; break;
        case 'W': *letter = W; break;
        case 'L': *letter = L; break;
        case 'R': *letter = R; break;
        case 'F': *letter = F; break;
    }
    *number = atoi(c+1);
}
void move(int *x, int *y, int *facing, int letter, int number){
    if(letter <= W) {
        *x += number * coords[letter][0];
        *y += number * coords[letter][1];
    }
    if(letter == F){
        *x += number * coords[*facing][0];
        *y += number * coords[*facing][1];
    }
    if(letter == L){
        number = number / 90;
        *facing -= number;
        if(*facing < 0) *facing += 4;
    }
    if(letter == R){
        number = number / 90;
        *facing += number;
        *facing %= 4;
    }
}
int ManDist(int x, int y){
    if (x < 0) x *= -1;
    if (y < 0) y *= -1;
    return x + y;
}
void solve(int *x, int *y) {
    *x = 0; *y = 0;
    int n = 0;
    int facing = E;
    FILE *in = fopen("in.in", "r");
    char c[10];
    fgets(c,10,in);
    while(! feof(in)) {
        n++;
        int letter,number;
        values(c, &letter, &number);
        move(x, y, &facing, letter, number);
        fgets(c,10,in);
    }
    fclose(in);
}

int main(){
    int x,y;
    solve(&x, &y);
    printf("%d\n",ManDist(x,y));
    return 0;
}
