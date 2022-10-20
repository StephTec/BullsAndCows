#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h> // ספריית מחרוזת
#define LEN 4 // מס ספרות המקסימלי במערך
int main()
{
    int turn=0; //משתנה בוליאני אשר מייצג את תור השחקן 0-שקר 1-אמת
    int flag1 =0; // 0-failed    1 -success
    int flag2=0;
    char arr1[LEN+1]={0},arr2[LEN+1]={0},ch,arrGue1[LEN+1]={0},arrGue2[LEN+1]={0};
	int i,j,bull,pgia,counter=0,n=4,q,k,numGuess1=0,numGuess2=0;

	printf("Welcome to a game called 'Bull Pgia'\n-'Pgia' means: the sum of the digits that exist, BUT NOT in the same position.\n-'Bull Pgia' means: the sum of the digits that exist AND in the same position.\n");
    system("cls");
    printf("\n PLAYER1- Enter a %d digit number:\n",n);
    scanf("%s",arr1);
    printf(" PLAYER2- Enter a %d digit number:\n",n);
    scanf("%s",arr2);
    // check if scanf is valid:
    while(1)
    {
        flag1=1; // success
        flag2=1;
        i=strlen(arr1); // אורך של המערכים
        j=strlen(arr2);
        if ((j<n|| j>n)&&(i<n|| i>n)){
            flag1 = 0; flag2=0;}
        if((arr1[0]=='0')&&(arr2[0]=='0')){
            flag1 =0; flag2=0;}    // אסור שהראשון יהיה 0

        for(i=0;i<n && flag1 == 1;i++)// for player 1
            {
                if(arr1[i]>'9'|| arr1[i]<'0') {
                    flag1 = 0; break; };
                for(q=i+1;q<n;q++){
            if(arr1[i]==arr1[q]) flag1 = 0;
            }
            }
        for(j=0;j<n && flag2 == 1;j++)// for player 2
            {
                if(arr2[j]>'9'|| arr2[j]<'0') {
                    flag2 = 0; break; };
                for(k=j+1;k<n;k++){
            if(arr2[j]==arr2[k]) flag2 = 0;
            }
            }
            if (flag1==0){
                printf("invalid input for player1, enter legal numbers:\n");
                //system("clr");
                gets(arr1);
            }
            if(flag2=0){
                    printf("invalid input for player1, enter legal numbers:\n");
                    gets(arr2);}
                    else break;
    }
    // guesses:
    while(1){
        counter++;
        bull=0;
        pgia=0;
         printf("\n %d.PLAYER1 Guess the %d numbers:  ", counter,n);
         //system("clr");
         gets(arrGue1);
         while(1){ // בדיקת ניחוש האם חוקי
            flag1=1;
            flag2=1;
            i=strlen(arrGue1);
            j=strlen(arrGue2);
            if(i<n || i>n) flag1= 0; //קטן או גדול ממספר הספרות הרצוי
            if(arrGue1[0]== '0') flag1=0;
            for(i=0;i<n&&flag1==1;i++)
            {
                if(arrGue1[i]>'9' || arrGue1[i]<'0')// בדיקה שהתווים בתחום הרצוי
                {
                    flag1=0;
                    break;
                }
                 for (q = i + 1; q < n; q++){ //בדיקה שאין כפילות של ספרה
                  if(arrGue1[i]==arrGue1[q])
                        flag1=0; //failed
                 }
            }
            if(flag1==0)
            {
                printf("Invalid guess input, please enter legal numbers:\n");
                //system("clr");
                gets(arrGue1);
            }
            else break;
         }
         // the guess was valid then count it as a guess:
         numGuess1+=1;

           flag1=1;
             for (i = 0; i < n; i++) {
            for (q = 0; q < n; q++) {
                if((arr1[q]==arrGue1[i])&& (q!=i))
                {
                    pgia++;
                    break;
                }
                 if ((arrGue1[i] == arr1[q]) && (q == i))
                    {
                        bull++;
                        break;
                    }
            }
               if ((q == n) || (q != i)) flag1=0; // אם הגענו לסוף המערך בלי התאמה או אם ההתאמה היא לא באותו מקום
             }
             if(flag1==1)
             {
                 printf("\n PLAYER 1 GUESSED RIGHT!\n times guessed: %d\n",numGuess1);
                 break;
             }
             for (i = 0; i < pgia; i++) printf("Pgia!\n");
            for (i = 0; i < bull; i++) printf("bull Pgia!\n");
            if((bull==0)&& (pgia==0)) printf("Wrong guess! passing the turn to player 2...\n");
         }
        scanf("%s",arr1);
    }

