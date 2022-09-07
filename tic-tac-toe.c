#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

char box[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int checkforwin();
void board();

void doit()
{

    int player = 1;
    int i;

    char  choice;

    char sign;
    do
    {


        board();
        player = (player % 2) ? 1 : 2;

        printf("\tPlayer %d, enter a number:  ", player);
        choice = getche();

        sign = (player == 1) ? 'X' : 'O';

           if (choice == '1' && box[1] == '1')
            box[1] = sign;

        else if (choice == '2' && box[2] == '2')
            box[2] = sign;

        else if (choice == '3'&& box[3] == '3')
            box[3] = sign;

        else if (choice == '4' && box[4] == '4')
            box[4] = sign;

        else if (choice == '5' && box[5] == '5')
            box[5] = sign;

        else if (choice == '6' && box[6] == '6')
            box[6] = sign;

        else if (choice == '7' && box[7] == '7')
            box[7] = sign;

        else if (choice == '8' && box[8] == '8')
            box[8] = sign;

        else if (choice == '9' && box[9] == '9')
            box[9] = sign;

        else
        {
            printf("Invalid move ");

            player--;
            getch(); //it holds screen until some key is entered
        }
        i = checkforwin();

        player++;


    }while (i ==  - 1);

    board();

    if (i == 1)
        printf("\tPlayer %d win ", --player);
    else
       {
           printf("\tGame draw");

       }
}

int goAgain() {

    char ch;



    printf("Again? (Y/N): ");

    scanf(" %c", &ch);

    return (ch=='Y' || ch=='y');

}

int main() {

    for(;;) { /* infinite loop */

        doit();

        if (!goAgain()) { break; }

    }

    return 0;
}


int checkforwin()
{
    if (box[1] == box[2] && box[2] == box[3])

        return 1;

    else if (box[4] == box[5] && box[5] == box[6])
        return 1;

    else if (box[7] == box[8] && box[8] == box[9])
        return 1;

    else if (box[1] == box[4] && box[4] == box[7])


        return 1;

    else if (box[2] == box[5] && box[5] == box[8])


        return 1;

    else if (box[3] == box[6] && box[6] == box[9])
        return 1;

    else if (box[1] == box[5] && box[5] == box[9])
        return 1;

    else if (box[3] == box[5] && box[5] == box[7])
        return 1;

    else if (box[1] != '1' && box[2] != '2' && box[3] != '3' &&box[4] != '4' && box[5] != '5'
             && box[6] != '6' && box[7]!= '7' && box[8] != '8' && box[9] != '9')

        return 0;
    else
        return  - 1;
}


void board()
{
    system("cls");
    printf("\n\n\t\t\tTic Tac Toe\n\n");

    printf("\t For Player 1 :-(X)  - For Player 2 :-(O)\n\n\n"); //"\t" works as Tab of keyboard


    printf("\t\t     |     |     \n");

    printf("\t\t  %c  |  %c  |  %c \n", box[1], box[2], box[3]);



    printf("\t\t_____|_____|_____\n");

    printf("\t\t     |     |     \n");

    printf("\t\t  %c  |  %c  |  %c \n", box[4], box[5], box[6]);



    printf("\t\t_____|_____|_____\n");
    printf("\t\t     |     |     \n");

    printf("\t\t  %c  |  %c  |  %c \n", box[7], box[8], box[9]);

    printf("\t\t     |     |     \n\n");
}

