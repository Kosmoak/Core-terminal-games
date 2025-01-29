#include<stdio.h>
void displayboard(char board[3][3]);
int checkwinner(char board[3][3]);
int isfull(char board[3][3]);
int main()
{
    char board[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    int row,col;
    int player=1,winner=0;
    printf("Welcome to Tic Tac Toe board...!");
    while(!winner && !isfull(board))
    {
        displayboard(board);
        printf("Player %d, enter row(0-2) and column (0-2) to place your symbol::",player);
        scanf("%d %d",&row,&col);
        if(row < 0 || row>2 || col<0 || col>2|| board[row][col] !=' ')
        {
            printf("Invalid move. Try again.\n");
            continue;
        }
        if(player ==1)
        {
            board[row][col]='X';
        }
        else
        {
            board[row][col]='O';
        }
        winner= checkwinner(board);
        player=(player ==1)? 2:1;
    }
    displayboard(board);
    if(winner ==1)
    {
        printf("Player 1 (X) wins !\n");
    }
    else if(winner ==2)
    {
        printf("Player 2{O} wins\n");
    }
    else
    {
        printf("It's a draw\n");
    }
    return 0;
}
void displayboard(char board[3][3])
{
    printf("\n    0   1   2\n");
    for(int i=0;i<3;i++)
    {
        printf("%d  ",i);
        for(int j=0;j<3;j++)
        {
            printf("%c  ",board[i][j]);
            if(j<2)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i<2)
        {
            printf(" --------------\n");
        }
    }
    printf("\n");
}

int checkwinner(char board[3][3])
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0]==board[i][1] && board[i][1] == board[i][2] && board[i][0] !=' ')
        {
            return (board[i][0] =='X') ? 1:2;
        }
        if(board[0][i]==board[1][i] && board[1][i] == board[2][i] && board[0][i] !=' ')
        {
            return (board[0][i] =='X') ? 1:2;
        }
    }
    if((board[0][0]==board[1][1] && board[1][1] == board[2][2] && board[0][0] !=' ')||(board[0][2]==board[1][1] && board[1][1] == board[2][0] && board[0][2] !=' '))
    {
        return (board[1][1] =='X') ? 1:2;
    }
    return 0;
}
int isfull(char board[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(board[i][j] ==' ')
            {
                return 0;
            }
        }
    }
    return 1;
}