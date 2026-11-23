#include <stdio.h>
#define MAX_SIZE 50


int main(void) {
    int row, col;
    char chess_board[MAX_SIZE][MAX_SIZE];
    char input;

    scanf("%d %d", &row, &col);

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            input = getchar();
            if(input == '\n')
                input = getchar();
            chess_board[i][j] = input;
        }
    }

    char std;
    int min1 = 2500;
    int case1;

    for(int std_row = 0; std_row <= row - 8; std_row++)  {
        for(int std_col = 0; std_col <= col - 8; std_col++) {
            case1 = 0;
            for(int i = 0 + std_row; i < std_row + 8; i++) {
                for(int j = 0 + std_col; j < std_col + 8; j++) {
                    if((i + j) % 2 == 0) 
                        std = 'W';
                    else
                        std = 'B';
                    if(chess_board[i][j] != std)
                        case1 += 1;
                }
            }            
            min1 = (min1 > case1) ? case1 : min1;
            
            case1 = 0;
            for(int i = 0 + std_row; i < std_row + 8; i++) {
                for(int j = 0 + std_col; j < std_col + 8; j++) {
                    if((i + j) % 2 == 1) 
                        std = 'W';
                    else
                        std = 'B';
                    if(chess_board[i][j] != std)
                        case1 += 1;
                }
            }
            min1 = (min1 > case1) ? case1 : min1;         
        }
    }

    printf("%d", min1);

    return 0;
}