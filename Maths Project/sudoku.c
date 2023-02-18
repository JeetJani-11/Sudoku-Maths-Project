#include<stdio.h>
#include<stdbool.h>

bool ifsafe(int a[9][9], int row, int col, int dig) {
    for(int y = 0; y <= 8; y++) {
        if(a[y][col] == dig) {
            return false;
        }
    }
    for(int j = 0; j <=8; j++) {
        if(a[row][j] == dig) {
            return false;
        }
    }
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    for(int y = sr; y < sr + 3; y++) {
        for(int i = sc; i < sc + 3; i++) {
            if(a[y][i] == dig) {
                return false;
            }
        }
    }
    return true; 
}

void printsudoku(int a[9][9]) {
    printf("                        ____________\n");
    for(int i = 0; i < 9; i++) {
        printf("                                                    ");
        for(int j = 0; j < 9; j++) {
            if(j % 3 == 0) {
                printf(" |");
            }
            
            if(j == 8) {
                if(a[i][j] == 0) {
                    printf(" . |" );
                } else {
                    printf(" %d |", a[i][j]);
                }
            } else {
                if(a[i][j] == 0) {
                    printf(" . " );
                } else {
                    printf(" %d ", a[i][j]);
                }
            }
        }
       
        if((i+1) % 3 == 0) {
            printf("\n                                                     ____________\n");
        } else {
            printf("\n");
        }
    }
    printf("\n\n\n\n");
}

bool sudoku(int a[9][9], int row, int col) {
    if(row == 9 && col == 0) {
        return true;
    }
    int newrow = row;
    int newcol = col + 1;
    if(col + 1 == 9) {
        newcol = 0; 
        newrow = row + 1;
    }
    if(a[row][col] != 0) {
        return sudoku(a, newrow, newcol);
    }
    for( int dig = 1; dig <= 9 ; dig++) {
        if(ifsafe(a , row , col , dig)) {
            a[row][col] = dig;
            if(sudoku(a , newrow ,newcol)) {
                return true;
            }
            a[row][col] = 0;
        }
    }

    return false;
}

int main() {
    printf("\x1B[35m"  "\n\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
    printf("\x1B[34m" "                                                          Sudoku Solver" "\x1B[0m");
    printf("\x1B[35m" "\n\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n" "\x1B[0m");

    int a[9][9] = {{ 0, 0, 8, 0, 0, 0, 0, 0, 0 },
                   { 4, 9, 0, 1, 5, 7, 0, 0, 2 },
                   { 0, 0, 3, 0, 0, 4, 1, 9, 0 },
                   { 1, 8, 5, 0, 6, 0, 0, 2, 0 },
                   { 0, 0, 0, 0, 2, 0, 0, 6, 0 },
                   { 9, 6, 0, 4, 0, 5, 3, 0, 0 },
                   { 0, 3, 0, 0, 7, 2, 0, 0, 4 },
                   { 0, 4, 9, 0, 3, 0, 0, 5, 7 },
                   { 8, 2, 7, 0, 0, 9, 0, 1, 3 }};
    
    printf("The question is as follows : \n");
    printsudoku(a);

    int count = 0;
    int input[9][9];
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            input[i][j] = a[i][j];
            if(a[i][j] == 0) {
                count++;
            }
        }
    }
    
    sudoku(a, 0, 0);

    while(count--) {
        int ui, uj;
        printf("Enter row between 1 to 9 : ");
        scanf("%d", &ui);
        printf("Enter column between 1 to 9 : ");
        scanf("%d", &uj);
        if((ui >= 10 || uj >= 10) || (input[ui - 1][uj - 1] != 0)) {
            printf("Invalid Input! Please try again! :(\n");
            count++;
            continue;
        }

        int ans;
        printf("Enter your choioce : ");
        scanf("%d", &ans);

        if(a[ui - 1][uj - 1] == ans) {
            input[ui - 1][uj - 1] = ans;
            printf("Correct Input! :)\n");
            printsudoku(input);
        } else {
            printf("Wrong Answer! :(");
            count++;
        }
        printf("\n");
    }
}
