#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void drawBoard();
void markBoard(char);
int checkForWin();
void reset();

const int true =1;
const int false = 0;
char matrix[3][3] = {{'1','2','3'},
                    {'4','5','6'},
                    {'7','8','9'}};
int choice, player;
int score1, score2;
int main()
{
    int flag = -1;
    char mark;
    score1 = 0,score2 = 0;
    player = 1;

    while(flag == -1 || (score1 !=3 && score2!=3)){
    // draw the board
    drawBoard();

    //take input from the player
    player = (player % 2) ? 1:2;
    printf("\n\nPlayer %d please enter a number.\n", player);
    scanf("%d",&choice);

    //mark the board
    mark = (player == 1) ? 'X':'O';
    markBoard(mark);

    flag = checkForWin();
    player++;
    if(flag == 2){
        if( --player % 2 == 1){
            score1++;
        }else{
        --player;
        score2++;
        }
    reset();
    }
    drawBoard();
   }
    player =  (score1>score2) ? 1:2;
    if(flag == 2){
        printf("\n\nPlayer %d wins!\n", player);
    }else{
   printf("Draw!\n");
   }

}

void drawBoard(){
  system("cls");
  printf("\tTicTacToe\n\n");
  printf("Player 1('X') -  Player 2('O')\n\n\n");
  printf("Score:  %d -  %d\n", score1, score2);
  printf("      |       |       \n");
  printf("  %c   |   %c   |   %c   \n", matrix[0][0],matrix[0][1],matrix[0][2]);
  printf("______ _______ _______\n");
  printf("      |       |       \n");
  printf("  %c   |   %c   |   %c   \n", matrix[1][0],matrix[1][1],matrix[1][2]);
  printf("______ _______ _______\n");
  printf("      |       |       \n");
  printf("  %c   |   %c   |   %c   \n", matrix[2][0],matrix[2][1],matrix[2][2]);

}

void markBoard(char mark){
    if(choice == 1 && matrix[0][0]=='1') matrix[0][0] = mark;
    else if(choice == 2 && matrix[0][1]=='2') matrix[0][1] = mark;
    else if(choice == 3 && matrix[0][2]=='3') matrix[0][2] = mark;
    else if(choice == 4 && matrix[1][0]=='4') matrix[1][0] = mark;
    else if(choice == 5 && matrix[1][1]=='5') matrix[1][1] = mark;
    else if(choice == 6 && matrix[1][2]=='6') matrix[1][2] = mark;
    else if(choice == 7 && matrix[2][0]=='7') matrix[2][0] = mark;
    else if(choice == 8 && matrix[2][1]=='8') matrix[2][1] = mark;
    else if(choice == 9 && matrix[2][2]=='9') matrix[2][2] = mark;
    else{
        printf("Invalid Move. Please press enter and choose a number again!");
        --player;
        getch();
    }

}


int checkForWin(){
    int result = -1;
    if(matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix [0][2]) result = 2;
    else if(matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix [1][2]) result= 2;
    else if(matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix [2][2]) result = 2;
    else if(matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix [2][0]) result = 2;
    else if(matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix [2][1]) result = 2;
    else if(matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix [2][2]) result = 2;
    else if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix [2][2]) result = 2;
    else if(matrix[2][0] == matrix[1][1] && matrix[1][1] == matrix [0][2]) result = 2;
    else if(matrix[0][0] != '1' && matrix[0][1] != '2'&& matrix[0][2] != '3' &&
            matrix[1][0] != '4' && matrix[1][1] != '5'&& matrix[1][2] != '6' &&
            matrix[2][0] != '7' && matrix[2][1] != '8'&& matrix[2][2] != '9'){
                result = 0;
            }
    else{
        result = -1;
            }

    if(score1==3 || score2==3){
        result = 1;
    }

    return result;

}

void reset(){
    matrix[0][0]='1';
    matrix[0][1]='2';
    matrix[0][2]='3';
    matrix[1][0]='4';
    matrix[1][1]='5';
    matrix[1][2]='6';
    matrix[2][0]='7';
    matrix[2][1]='8';
    matrix[2][2]='9';
}

