#include <stdio.h>      //including standard input and output header
#include <stdlib.h>     //including standard library for memory allocation functions
#include <time.h>       //including standard library for time and date

int randomIndex(){          //Generates random number
    srand(time(NULL));
    int k=rand() %6;
    return k;
}

int captcha(){              //Recalls 'randomIndex' function to generate number for math question
    int x = randomIndex();
    return x;
}

struct contact{             //Declared player 'contact' variables using structure
    int number;
    char email[30];
};

struct player_info{         //Declared struct variable 'player_info' with nested struct variable 'contact'
    char name[10];
    struct contact a;
};

int players(){              //user input for struct values a.k.a player info
    struct player_info pl[1];
    int i;

    for(i=0;i<1;i++){
    printf("Enter name : ");
    scanf("%s",pl[0].name);
    printf("Enter mail : ");
    scanf("%s",pl[0].a.email);
    printf("Enter number : ");
    scanf("%d",&pl[0].a.number);
    }

}

int isCaptchaDone = 0;      //global variable

int main() {

    int math = captcha();  //recalling captcha() for random number generation
    int ans;

    if (isCaptchaDone == 0){
    printf("Before starting the game, answer this security question : \n");
    printf("2 x %d = ",math);
    scanf("%d",&ans);

    if(ans==2*math){
            isCaptchaDone = 1;
            printf("\n");
            players();
        }
    }

    char words[][16]={"horse","tiger","lion","zebra","elephant","donkey"};
    int random_num = randomIndex();
    int loop_Index = 0;
    int correct_num = 0;
    int old_correct = 0;
    int player_lives = 5;

    int length_word = strlen(words[random_num]);
    int letter_guessed[10] = {0,0,0,0,0,0,0,0,0,0};
    char guess[16];
    char letter_input;

    int restart = 0;
    int quit = 0;

    if(isCaptchaDone == 1){     //condition for the game to start if user answers the math correctly

        /*Introduction texts for the game with Title and game rules*/

        printf("\n!!WELCOME TO HANGMAN!!\n");
        printf("\n<To quit in the middle of game, simply type in 'quit' and to restart type 're'>\n");
        printf("\nAlso, you got 5 lives, don't screw up!!\n");

    while(correct_num < length_word){

        printf("\n\nHangman Word : ");

        for(loop_Index=0;loop_Index<length_word;loop_Index++){

            if(letter_guessed[loop_Index] == 1){
                    printf("%c",words[random_num][loop_Index]);
            }else{
                    printf("-");
            }

        }

        //Main game screen
        printf("\n");
        printf("Lives : %d\n",player_lives);
        printf("Letter Correct so far : %d\n",correct_num);
        printf("Enter a letter : ");
        scanf("%s",guess);

        if(strncmp(guess, "quit",4)==0){
            quit = 1;
            break;
        }else if(strncmp(guess, "re",2)==0){
            restart = 1;
            break;
        }

        letter_input = guess[0];

        printf("letter entered : %c\n",letter_input);

        old_correct = correct_num;

        //loop to check the letter from user input with characters of the word
        for(loop_Index=0;loop_Index<length_word;loop_Index++){

            if(letter_guessed[loop_Index] == 1){
                continue;
            }

            if(letter_input==words[random_num][loop_Index]){
                letter_guessed[loop_Index] = 1;
                correct_num++;
            }

        }

        //condition if the player inputs the same letter multiple times, they lose lives and if lives=0, game over
        if(old_correct==correct_num){
            player_lives--;
            printf("Wrong Guess -_- \n");
            if(player_lives==0){
                break;
            }
        }else{
            printf("Correct Guess :v \n");
        }

    }

    //game end conditions for user to quit in the middle of game, lose game, win game or to restart at any point
    if(quit==1){
        printf("\nUser quit early\n");
        printf("\nRestart? (y/n) = ");
        scanf("%s",guess);
        if(strncmp(guess, "y",1)==0){
            printf("\n\n");
            main();
        }
    }else if(restart==1){
        printf("\n\n");
        main();
    }else if(player_lives==0){
        printf("\nYou lost. The word was : %s\n",words[random_num]);
        printf("\nRestart? (y/n) = ");
        scanf("%s",guess);
        if(strncmp(guess, "y",1)==0){
            printf("\n\n");
            main();
        }
    }else{
        printf("\nYou guessed the word '%s' correctly. YOU WON!!!!",words[random_num]);
        printf("\nRestart? (y/n) = ");
        scanf("%s",guess);
        if(strncmp(guess, "y",1)==0){
            printf("\n\n");
            main();
        }
    }

    }else{
        printf("\nWrong!!! Try again?(y/n) - ");  //message if player gets starting math wrong
        scanf("%s",guess);
        if(strncmp(guess, "y",1)==0){
            printf("\n\n");
            isCaptchaDone=0;
            main();
        }

    }
}
