#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main () {

    char name[50], course[50][50], buffer[50];
    int read_integer(int max), x, count = 0;
    FILE *pointer;

    printf("Welcome to the Student Grade Calculator!\nPlease enter your name: \n");
    fgets(name, 50, stdin);

    printf("How many subjects do you want to calculate grades for?\n");
    x = read_integer(50);

    int score[x], grade[x];

    while(count < x) {

        //reading user input

        printf("Enter subject %d name: ", (count+1));
        getchar();                          //remove newline from buffer
        fgets(buffer, 50, stdin);
        buffer[strcspn(buffer, "\n")] = 0;  //remove newline from fgets string end
        strcpy(course[count], buffer);

        printf("Enter your score for %s (0-100): ", course[count]);
        score[count] = read_integer(100);

        //assigning grades

        if(score[count]>=90){
            grade[count]=5;
        }else if(score[count]>=80){
            grade[count]=4;
        }else if(score[count]>=70){
            grade[count]=3;
        }else if(score[count]>=60){
            grade[count]=2;
        }else if(score[count]>=50){
            grade[count]=1;
        }else{
            grade[count]=0;
        }

        count++;

    }

    //printing arrays to a neat table and writing to file

    printf("\n----------------------------------------------------------\n");
    printf("Student: %s", name);
    printf("----------------------------------------------------------\n");
    printf("%-30s%11s%16s\n", "Subject", "Score", "Grade");
    printf("----------------------------------------------------------\n");

    pointer = fopen("grades.txt", "w");

    fprintf(pointer, "\n----------------------------------------------------------\n");
    fprintf(pointer, "Student: %s", name);
    fprintf(pointer, "----------------------------------------------------------\n");
    fprintf(pointer, "%-30s%11s%16s\n", "Subject", "Score", "Grade");
    fprintf(pointer, "----------------------------------------------------------\n");

    int sum=0;

    for(int i = 0; i<count; i++) {
        printf("%-30s%10d%%%16d\n", course[i], score[i], grade[i]);
        fprintf(pointer, "%-30s%10d%%%16d\n", course[i], score[i], grade[i]);
        sum += grade[i];
    }

    printf("\nAverage grade: %.2f\n", (sum*1.0 / count*1.0));
    printf("----------------------------------------------------------");

    fprintf(pointer, "\nAverage grade: %.2f\n", (sum*1.0 / count*1.0));
    fprintf(pointer, "----------------------------------------------------------");

    fclose(pointer);

    return 1;
}

//user input validation

int read_integer(int max) {

    int integer, selection = 0;

    while(selection == 0) {
        if (scanf("%d", &integer) != 1) {
            while(getchar() != '\n');
            printf("Invalid input!\n");
        } else if (integer < 0 || integer > max) {
            printf("Invalid input!\n");
        } else {
            selection = 1;
        }
    }

    return integer;

}

/* unused code

int get_int(void){

    int x, jatkuu=1;

    while(jatkuu==1){
        if(scanf("%d", &x)!=1){
            while(getchar()!='\n');
            printf("Invalid input!\n");
        }else{
            jatkuu=0;
        }
    }
    
    return x;
}
    
*/