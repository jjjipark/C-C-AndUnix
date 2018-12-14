#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


char* user(){

        char *item = malloc(100);

        printf("Enter rock, paper, or scissors:");
        scanf("%s",item);

        if (strcmp(item, "rock")==0 ){
		return item;
        }
        if (strcmp(item, "paper")==0 ){
                return item;
        }
        if (strcmp(item, "scissors")==0 ){
                return item;
        } else{
                printf("Invalid user choice, you must enter rock, paper, or scissors.\n");		}	
	return "Error_user";
}

char* computer(){

        srand (time(NULL));
        int random = rand() % 3;

        if (random==0){
                return "rock";
        }
        if (random ==1){
                return "paper";
        }if (random == 2) {
                return "scissors";
        }
        return "Error_computer";
}        

char* compare(char* choice1, char* choice2){

        if (strcmp(choice1, choice2) ==0 ){
                return "This game is a tie.";
	}


        if (strcmp(choice1,"rock")==0){
                if (strcmp(choice2,"paper")==0){
                        return "Paper wins";
                }
                if (strcmp(choice2, "scissors")==0){
                        return "Rock wins";
                }
        }
        if (strcmp(choice1, "paper")==0){
                if (strcmp(choice2, "rock")==0){
                        return "Paper wins";
                }
                if (strcmp(choice2 , "scissors") ==0){
                        return "Scissors win";
                }
        }
        if (strcmp(choice1, "scissors")==0){
                if (strcmp(choice2, "rock")==0){
                        return "Rock wins";
                }
                if (strcmp(choice2 , "paper")==0){
                        return "Scissors win";
                }

                return "Error";
        }
}


int main(int argc, char** argv){

        char* UserItem = NULL, *ComputerItem = NULL, *result = NULL;
	
	//char item;
	
	
	UserItem = user();
        //ComputerItem = computer();

        //result = compare(UserItem, ComputerItem);
	//UserItem = user();
        while (strcmp(UserItem, "Error_user")==0){
               //printf("Invalid user choice, you must enter rock, paper, or scissors.\n");
        	UserItem = user();
		
	}

	//UserItem = user();
	ComputerItem = computer();

	result = compare(UserItem, ComputerItem);
       // else{
	printf("You picked %s.\n", UserItem);
        printf("Computer picked %s.\n", ComputerItem);
        printf("%s.\n", result);

	return 0;
       // }
}
