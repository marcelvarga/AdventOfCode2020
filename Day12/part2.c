#include <stdio.h>
#include <stdlib.h>
enum {N,E,S,W,L,R,F};
const int coords[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
typedef struct position {
    int x, y;
}position;

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
void move(position *ship, position *waypoint, int letter, int number){
    if(letter <= W) {
        waypoint -> x += number * coords[letter][0];
        waypoint -> y += number * coords[letter][1];
    }
    if(letter == F){
        ship -> x += number * waypoint -> x;
        ship -> y += number * waypoint -> y;   
    }
    if(letter == L){
        number = number / 90;
        if(number == 2) {
            waypoint -> x *= -1;
            waypoint -> y *= -1;
        }
        if(number % 2 == 1) {
            int aux = waypoint -> x;
            waypoint -> x = waypoint -> y;
            waypoint -> y = aux;
            if (number == 1 ) waypoint -> y *= -1;
            if (number == 3 ) waypoint -> x *= -1;
        }

    }
    if(letter == R){
        number = number / 90;
        if(number == 2) {
            waypoint -> x *= -1;
            waypoint -> y *= -1;
        }
        if(number % 2 == 1) {
            int aux = waypoint -> x;
            waypoint -> x = waypoint -> y;
            waypoint -> y = aux;
            if (number == 1 ) waypoint -> x *= -1;
            if (number == 3 ) waypoint -> y *= -1;
        }
    }
}
int ManDist(int x, int y){
    if (x < 0) x *= -1;
    if (y < 0) y *= -1;
    return x + y;
}
void solve(position *ship, position *waypoint) {
    FILE *in = fopen("in.in", "r");
    char c[10];
    fgets(c,10,in);
    while(! feof(in)) {
        int letter,number;
        values(c, &letter, &number);
        move(ship, waypoint, letter, number);
        fgets(c,10,in);
    }
    fclose(in);
}

int main(){
    position ship={0,0};
    position waypoint = {1, 10};
    solve(&ship, &waypoint);
    printf("%d\n",ManDist(ship.x, ship.y));
    return 0;
}
