#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


void my_mastermind()
{
    int number_of_attempts = 1;
    char code[] = "2153";
    char user_input[5];

    printf("Will you find the secret code? \nPlease enter a valid guess\n----\n");

    while(number_of_attempts <= 10)
    {
        printf("Round %d\n", number_of_attempts);
        scanf("%s", user_input);


        if(user_input == code)
        {
            printf("Congratz! You did it!");
            break;
        }
        else
        {
            int well_placed_pieces = 0;
            int misplaced_pieces = 0;

            if(!isdigit(user_input))
            {
                printf("Wrong input!");
                scanf("%s", user_input);
            }

            for(int i = 0; i < strlen(code); i++){
                if(user_input[i] == code[i])
                {
                    well_placed_pieces++;
                }
                else
                {
                    if(strstr(code, user_input[i]) && user_input[i] != code[i])
                    {
                        misplaced_pieces++;
                    }
                }
            }
            printf("Well placed pieces: %d", well_placed_pieces);
            printf("Misplaced pieces: %d", misplaced_pieces);

            number_of_attempts++;

        }
    }
    if(number_of_attempts > 10)
    {
        printf("Game Over!!!");
    }

}



int main()
{
    my_mastermind();
}