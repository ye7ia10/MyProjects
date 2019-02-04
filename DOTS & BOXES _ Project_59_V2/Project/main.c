#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
int I=0;
int J=0;
int I1=0;
void gready(int c[60][4]);
void chl1(int q,int w,int e,int r,int a,int A[12][5]);
void arr_e(char array[9][9]);
int error_first(int z);
int error_second(int z);
int error_third(int z);
void print_arr_e(char array[9][9]);
void turn_in_e(int *a,int *b,int *c,int*d);
void print_e( char c[9][9]);
int score1(char c[9][9],int k,int q,int w,int e,int r,int h);
int error_easy (int q,int w,int e,int r,int A[12][5]);
int error_hard (int q,int w,int e,int r,int A[60][5]);
void chl(int q,int w,int e,int r,int a,int A[60][5]);
int score(char c[21][21],int k,int q,int w,int e,int r,int h);
void puti(int q,int w,int e,int r);
void arr_h(char array[21][21]);
void print_arr_h(char array[21][21]);
void turn_in_h(int *a,int *b,int *c,int*d);
void gotoxy (int x, int y){
    COORD coord; // coordinates
    coord.X = x; coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void color(int ForgC, int BackC){
     WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
     return;
}
void hoba(int q,int w,int e,int r){ //function to print the shape of grid 2x2


if(q==w){
gotoxy(6+e,9+q);
printf("---");
    }

    if(e==r){
        gotoxy(5+e,10+q);
        printf("|");
        gotoxy(5+e,10+q+1);
        printf("|");
        gotoxy(5+e,10+q+2);
        printf("|");
    }
    }
struct top_score{ //take name and score of player
char name[200];
int scor;

}best[10];
int main()
{
    int oop; //to check the computer did not find move to get point
    int gread[60][4]; //to make greedy
    gready(gread);
    while(1){
 I=0;//number of moves
 J=0;//number of undo
 I1=0;  //check if it is the first play after using gets
    int k=0,s=0,y1=0; //k score of player one & s score of player two & y1 to check error of mode

    FILE *top; // file contain names of top score
  time_t start_t, end_t; // to make timer
   int diff_t;
    char H[200]; // take player one name
    char P[200];// take player two name
    char T1[200];
    char T2[200];
    char T3[200];          //T1 & T2 & T3 & T4 TO TAKE INPUTS
    char T4[200];
    char T5[200];
    strcpy(P,"Computer"); // make name for computer
FILE *f;
FILE *f2;    //three files to  save in
FILE *f3;
int N=0,M=0,V=0,F=0; //N for choose mode easy or hard & M to choose from menu & v to play one vs one or computer & f choose for file
while(1){
        system("cls");
int x0=0; //check the existence of file
while(1){
        system("cls");
        color(10,0);
        gotoxy(40,0);
        printf("Menu \n");
        color(14,0);
printf("1-New game\n2-Load game\n3-Show high scores\n4-How to play \n5-Exit game\n");
while(1)
{
gets(T1);
M=atoi(T1);     // atoi to convert string to int
y1=error_third(M);
if(y1==0)
{
    break;
}
else
{
    printf("error\n");
}
}
system("cls");
if(M==4){
    gotoxy(30,0);
    color(4,14);
    printf("How to play \n");
    color(14,5);
    printf("\nTo gain point  : you should close a square . \n");
    printf("When you get a point you will have an extra move .\n");
    printf("\n\nHow to input : \n");
    color(14,3);
    printf("\n1-you enter the number of the row where you start you move ,then press Enter.\n");
    printf("2-you enter the number of the row where you end your move ,press Enter.\n");
    printf("3-you enter the number of the column where you start you move ,then press Enter.\n");
    printf("4-you enter the number of the column where you end your move ,then press Enter.\n");
    color(14,1);
    printf("\n\nSome notes for playing : \n");
    printf("\n1-To undo a play , you should enter '100' in the first input.\n");
    printf("2-To redo a play , you should enter '200' in the first input.\n");
    printf("3-To save the game , you should enter '300' in the first input.\n");
    printf("4-To load the game , choose 'Load game' from the menu and choose the file.\n");
    gotoxy(30,27);
    color(4,14);
    printf("Enjoy the game . ^_^ \n");
    color(7,0);
    printf("\nPress enter to return to menu . :) \n");
    getchar();
    color(7,0);
}

if(M==3){    //to show top score
        gotoxy(40,0);
color(14,0);
printf("Top Score\n");
color(10,1);
        int y,temp=0; //temp for reading top score & y variable to read values
top=fopen("top.txt","r");
while( fscanf(top, "%d", & y ) == 1 ){
best[temp].scor=y;
fscanf(top,"%s",best[temp].name);
printf("%d- %s : %d \n\n",temp+1,best[temp].name,best[temp].scor);
temp++;

}
fclose(top);
getchar();
color(7,0);
}
if(M==2){ //load
    printf("Load\n1-file one\n2-file two\n3-file three");
        while(1)
{
gets(T4);
F=atoi(T4);
y1=error_second(F);
if(y1==0)
{
    break;
}
else
{
    printf("error\n");
}
}

}
if(M==1){
printf("1-Easy\n2-hard\n");
while(1)
{
gets(T2);
N=atoi(T2);
y1=error_first(N);
if(y1==0)
{
    break;
}
else
{
    printf("error\n");
}
}
system("cls");
printf("1-Player VS Player\n2-Player VS Computer\n");
while(1)
{
gets(T3);
V=atoi(T3);
y1=error_first(V);
if(y1==0)
{
    break;
}
else
{
    printf("error\n");
}
}
system("cls");
if(M==1&&V==2){
    printf("Enter your name\n");
    scanf("%s",H);

}
if(M==1&&V==1){
    printf("Enter player 1 name\n");
    scanf("%s",H);
    printf("Enter player 2 name\n");
    scanf("%s",P);

}
}
if(M==1){
    break;
}
if(M==2){
    break;
}
if(M==5){ // to end game

    break;
}

}
if(M==2){ //check the existence
if(F==1){
     f=fopen("save.txt","r");
    if(f==NULL){
        x0=1;
    }
    else{

      int y;


         if( fscanf(f, "%1d", & y ) == 1 )
          {
              N=y;
          }
     fclose(f);

     }}
     if(F==2){
         f2=fopen("save2.txt","r");
            if(f2==NULL){
        x0=1;
    }
    else{

      int y;


         if( fscanf(f2, "%1d", & y ) == 1 )
          {
              N=y;
          }
     fclose(f2);

     }}
          if(F==3){
              f3=fopen("save3.txt","r");
                if(f3==NULL){
        x0=1;
    }
    else{

      int y;


         if( fscanf(f3, "%1d", & y ) == 1 )
          {
              N=y;
          }
     fclose(f3);

     }}

}
if(x0==0){
    break;
}
}

time(&start_t); // start timer


if(N==1){ //mode 2x2
    int B[12][5]; //for redo plays
    int l1,l2; //moves for each player
    int Y,X;
    for(Y=0;Y<12;Y++){
        for(X=0;X<5;X++){
            B[Y][X]=0;
        }
    }
    int A[12][5]; //contains played moves
    for(Y=0;Y<12;Y++){
        for(X=0;X<5;X++){
            A[Y][X]=0;
        }
    }

      if(M==2){ //load in 2x2
if(F==1){
            f=fopen("save.txt","r");
      int y;
      int j,i;


         if( fscanf(f, "%1d", & y ) == 1 )
          {
              y=y;
          }

      for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f, "%1d", & y ) == 1 )
          {
              A[i][j]=y;
          }


         }
     }
      for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f, "%1d", & y ) == 1 )
          {
              B[i][j]=y;
          }


         }
     }
     if( fscanf(f, "%d", & y ) == 1 )
          {
              I=y;
          }
          if( fscanf(f, "%d", & y ) == 1 )
          {
              J=y;
          }


           if( fscanf(f, "%d", & y ) == 1 )
          {
              V=y;
          }




          fscanf(f,"%s",H);
          if(V==1){
          fscanf(f,"%s",P);
          }
     fclose(f);

     }
          if(F==2){
            f2=fopen("save2.txt","r");
      int y;
      int j,i;


         if( fscanf(f2, "%1d", & y ) == 1 )
          {
              y=y;
          }

      for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f2, "%1d", & y ) == 1 )
          {
              A[i][j]=y;
          }


         }
     }
     for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f2, "%1d", & y ) == 1 )
          {
              B[i][j]=y;
          }


         }
     }
     if( fscanf(f2, "%d", & y ) == 1 )
          {
              I=y;
          }
          if( fscanf(f2, "%d", & y ) == 1 )
          {
              J=y;
          }


           if( fscanf(f2, "%d", & y ) == 1 )
          {
              V=y;
          }




          fscanf(f2,"%s",H);
          if(V==1){
          fscanf(f2,"%s",P);
          }
     fclose(f2);

     }

     if(F==3){
            f3=fopen("save3.txt","r");
      int y;
      int j,i;


         if( fscanf(f3, "%1d", & y ) == 1 )
          {
              y=y;
          }

      for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f3, "%1d", & y ) == 1 )
          {
              A[i][j]=y;
          }


         }
     }
     for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f3, "%1d", & y ) == 1 )
          {
              B[i][j]=y;
          }


         }
     }
     if( fscanf(f3, "%d", & y ) == 1 )
          {
              I=y;
          }
          if( fscanf(f3, "%d", & y ) == 1 )
          {
              J=y;
          }


           if( fscanf(f3, "%d", & y ) == 1 )
          {
              V=y;
          }




          fscanf(f3,"%s",H);
          if(V==1){
          fscanf(f3,"%s",P);
          }
     fclose(f3);

     }

     // file tow
     }
    int q,w,e,r,i,d,p;
    char  Q[200],W[200],E[200],R[200]; // to take the inputs for play moves
    k=0;
    p=2; // for turns
    s=0;
    l1=l2=0;
    char easy[9][9]; //contain the shape
    color(7,0);
        system("cls");
    gotoxy(5,6);
    printf("1   2   3");
    gotoxy(5,9);
    printf("%c   %c   %c   1",178,178,178);
    gotoxy(5,13);
    printf("%c   %c   %c   2",178,178,178);
    gotoxy(5,17);
    printf("%c   %c   %c   3",178,178,178);
    int S; //to put moves in A
    k=0;
    s=0;

    int o; //to know who played the move
    arr_e(easy); // to read the array
    for(S=0;S<I;S++){
        q=A[S][0];
        w=A[S][1];
        e=A[S][2];
        r=A[S][3];
        o=A[S][4];
        turn_in_e(&q,&w,&e,&r);
        if(q==w){
                for(i=(e+1);i<r;i++){
                    easy[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                easy[i][e]='|';
    }
}

        if(o==1){ // player one move
                int c=k; // to return the turn to player if won
        l1++;
            color(11,0);
            hoba(q,w,e,r); // print the grid
       k=score1(easy,k,q,w,e,r,1);
       if(S==I-1){
        if(c!=k){
            p=2;
        }
        else{
            p=3;
        }
       }

        }
        if(o==2){
                int c=s;
            color(12,0);
    l2++;
       s=score1(easy,s,q,w,e,r,1);
    if(S==I-1){
        if(c!=s){
            p=3;
        }
         else{
            p=2;
        }
       }
       hoba(q,w,e,r);
        }

    }
    if(I==0){
        p=0;
    }
    color(14,0);
    gotoxy(40,9);
    printf("Remaining moves : %d",12-I);
    gotoxy(40,11);
    color(11,0);
    printf("Player one , %s : ",H);
    gotoxy(40,13);
    printf("Moves : %d",l1);
    gotoxy(40,14);
    printf("Score : %d",k);
    gotoxy(40,16);
    color(12,0);
    printf("Player two , %s : ",P);
    gotoxy(40,18);
    printf("Moves : %d",l2);
    gotoxy(40,19);
    printf("score : %d",s);
     gotoxy(40,7);
   color(14,0);
       int mins=0,secn=0;
    printf("Execution time is mins : sec = %d : %d\n", mins,secn);
    gotoxy(0,25);

    while(I<12){
            int flag4; // check the score for greedy
        if(p%2==0){
         gotoxy(0,25);
         color(11,0);
         printf("now player1 , enter your move:\n");
         gotoxy(0,26);
         if(I1==0&&M!=2){
         getchar();
         I1=1;
         }

         gets(Q);
         q=atoi(Q);


         if(q==200){
                if(V==1){
            J--;
            if(J<0){
                J=0;
                continue;
            }


    A[I][0]=B[J][0];
    A[I][1]=B[J][1];
    A[I][2]=B[J][2];
    A[I][3]=B[J][3];
    A[I][4]=B[J][4];
    B[J][0]=0;
    B[J][1]=0;
    B[J][2]=0;
    B[J][3]=0;
    B[J][4]=0;

    I++;
                }
                if(V==2){
                            if(J>0){ //check nom of plays for redo

            J--;


     A[I][0]=B[J][0];
     A[I][1]=B[J][1];
     A[I][2]=B[J][2];
     A[I][3]=B[J][3];
     A[I][4]=B[J][4];
    B[J][0]=0;
    B[J][1]=0;
    B[J][2]=0;
    B[J][3]=0;
    B[J][4]=0;

    I++;

                }
                int g=B[J-1][4]; //to check if computer make the last move to help in undo
                while(g==2){
            J--;
            g=B[J-1][4];
            if(J<0){
                J=0;
                break;
            }
     A[I][0]=B[J][0];
     A[I][1]=B[J][1];
     A[I][2]=B[J][2];
     A[I][3]=B[J][3];
     A[I][4]=B[J][4];
    B[J][0]=0;
    B[J][1]=0;
    B[J][2]=0;
    B[J][3]=0;
    B[J][4]=0;

    I++;
                }




                }
       }
              if(q==300){ //save
            system("cls");
    printf("Save\n1-File one\n2-File two\n3-File three");
    printf("\n");
            while(1)
{
scanf("%s",&T5);
F=atoi(T5);
y1=error_second(F);
if(y1==0)
{
    break;
}
else
{
    printf("error\n");
}
}
    if(F==1){
        int j;

        f=fopen("save.txt","w");
        fprintf(f, "%d",N);
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f, "%d", A[i][j]);
         }
     }
     fprintf(f,"\n");
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f, "%d", B[i][j]);
         }
     }

     fprintf(f,"\n");
     fprintf(f, "%d",I);
     fprintf(f,"\n");
     fprintf(f, "%d",J);
     fprintf(f,"\n");
     fprintf(f, "%d",V);
     fprintf(f,"\n");
     fprintf(f, "%s",H);
     fprintf(f,"\n");
     if(V==1){
     fprintf(f, "%s",P);

     }
     fclose(f);
       }
           if(F==2){
        int j;

        f2=fopen("save2.txt","w");
        fprintf(f2, "%d",N);
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f2, "%d", A[i][j]);
         }
     }
          fprintf(f2,"\n");
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f2, "%d", B[i][j]);
         }
     }
     fprintf(f2,"\n");
     fprintf(f2, "%d",I);
     fprintf(f2,"\n");
     fprintf(f2, "%d",J);
     fprintf(f,"\n");
     fprintf(f2, "%d",V);
     fprintf(f2,"\n");
     fprintf(f2, "%s",H);
fprintf(f2,"\n");
     if(V==1){
     fprintf(f2, "%s",P);

     }
     fclose(f2);
       }

           if(F==3){
        int j;

        f3=fopen("save3.txt","w");
        fprintf(f3, "%d",N);
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f3, "%d", A[i][j]);
         }
     }
          fprintf(f3,"\n");
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f3, "%d", B[i][j]);
         }
     }
     fprintf(f3,"\n");
     fprintf(f3, "%d",I);
     fprintf(f3,"\n");
     fprintf(f3, "%d",J);
     fprintf(f3,"\n");
     fprintf(f3, "%d",V);
     fprintf(f3,"\n");
     fprintf(f3, "%s",H);
fprintf(f3,"\n");
     if(V==1){
     fprintf(f3, "%s",P);

     }
     fclose(f3);
       }
        I1=0;
        if(M==2){
            getchar();
        }
       }
         if(q==100){ //undo
             if(V==1){
             if(I==0){
                continue;
            }

            I--;


    B[J][0]=A[I][0];
    B[J][1]=A[I][1];
    B[J][2]=A[I][2];
    B[J][3]=A[I][3];
    B[J][4]=A[I][4];
    A[I][0]=0;
    A[I][1]=0;
    A[I][2]=0;
    A[I][3]=0;
    A[I][4]=0;
    J++;
    if (q==0){
        continue;
    }

         }

         int L=A[I-1][4]; //to check who plays the last move to help in undo
         if(V==2){
                while(L==2){
             if(I==0){
                break;
            }

            I--;
    L=A[I-1][4];
    int cho=A[I][4];
    B[J][0]=A[I][0];
    B[J][1]=A[I][1];
    B[J][2]=A[I][2];
    B[J][3]=A[I][3];
    B[J][4]=A[I][4];
    A[I][0]=0;
    A[I][1]=0;
    A[I][2]=0;
    A[I][3]=0;
    A[I][4]=0;
    J++;



         }


    if(I!=0){

            I--;
    B[J][0]=A[I][0];
    B[J][1]=A[I][1];
    B[J][2]=A[I][2];
    B[J][3]=A[I][3];
    B[J][4]=A[I][4];
    A[I][0]=0;
    A[I][1]=0;
    A[I][2]=0;
    A[I][3]=0;
    A[I][4]=0;
    J++;

         }
}


         }
         if(q!=100&&q!=200&&q!=300){


         gets(W);

         gets(E);

         gets(R);
         w=atoi(W);
         e=atoi(E);
         r=atoi(R);



         int u; //to swap
         if(q>w){
            u=w;
            w=q;
            q=u;
         }
         if(e>r){
            u=e;
            e=r;
            r=u;
         }
         d=error_easy (q,w,e,r,A);
         if(d==0)
        {
             chl1(q,w,e,r,1,A); //to put move in A
         p++;

     for(Y=0;Y<12;Y++){
        for(X=0;X<5;X++){
            B[Y][X]=0;
            J=0;
        }
    }
    turn_in_e(&q,&w,&e,&r);

        if(q==w){
                for(i=(e+1);i<r;i++){
                    easy[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                easy[i][e]='|';
    }
}
        int a=0; // to score
        a=score1(easy,0,q,w,e,r,1);
        if(a!=0){
            p--;
        }
        }



        }
        }
        else if(p%2!=0){
            gotoxy(0,25);
            color(12,0);
         printf("now player2 , enter your move:\n");
         gotoxy(0,26);
        if(I1==0&&M!=2){
         getchar();
         I1=1;
         }
         if(V==1){
         gets(Q);
         q=atoi(Q);
         }
         if(q==200){
            J--;
            if(J<0){
                J=0;
                continue;
            }


     A[I][0]=B[J][0];
     A[I][1]=B[J][1];
     A[I][2]=B[J][2];
     A[I][3]=B[J][3];
     A[I][4]=B[J][4];
    B[J][0]=0;
    B[J][1]=0;
    B[J][2]=0;
    B[J][3]=0;
    B[J][4]=0;
    I++;
         }
         if(q==100){
            if(I==0){
                continue;
            }

            I--;


    B[J][0]=A[I][0];
    B[J][1]=A[I][1];
    B[J][2]=A[I][2];
    B[J][3]=A[I][3];
    B[J][4]=A[I][4];
    A[I][0]=0;
    A[I][1]=0;
        A[I][2]=0;
         A[I][3]=0;
         A[I][4]=0;
    J++;

    if (q==0){
        continue;
    }

         }
                             if(q==300){
            system("cls");
    printf("Save\n1-File one\n2-File two\n3-File three");
    printf("\n");
while(1)
{
scanf("%s",&T5);
F=atoi(T5);
y1=error_second(F);
if(y1==0)
{
    break;
}
else
{
    printf("error\n");
}
}
    if(F==1){
        int j;

        f=fopen("save.txt","w");
        fprintf(f, "%d",N);
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f, "%d", A[i][j]);
         }
     }
          fprintf(f,"\n");
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f, "%d", B[i][j]);
         }
     }
     fprintf(f,"\n");
     fprintf(f, "%d",I);
     fprintf(f,"\n");
     fprintf(f, "%d",J);
     fprintf(f,"\n");
     fprintf(f, "%d",V);
     fprintf(f,"\n");
     fprintf(f, "%s",H);
fprintf(f,"\n");
     if(V==1){
     fprintf(f, "%s",P);

     }
     fclose(f);
       }
           if(F==2){
        int j;

        f2=fopen("save2.txt","w");
        fprintf(f2, "%d",N);
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f2, "%d", A[i][j]);
         }
     }
          fprintf(f2,"\n");
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f2, "%d", B[i][j]);
         }
     }
     fprintf(f2,"\n");
     fprintf(f2, "%d",I);
     fprintf(f2,"\n");
     fprintf(f2, "%d",J);
     fprintf(f2,"\n");
     fprintf(f2, "%d",V);
     fprintf(f2,"\n");
     fprintf(f2, "%s",H);
     fprintf(f2,"\n");
     if(V==1){
     fprintf(f2, "%s",P);

     }
     fclose(f2);
       }

           if(F==3){
        int j;

        f3=fopen("save3.txt","w");
        fprintf(f3, "%d",N);
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f3, "%d", A[i][j]);
         }
     }
          fprintf(f3,"\n");
         for(i=0;i<12;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f3, "%d", B[i][j]);
         }
     }
     fprintf(f3,"\n");
     fprintf(f3, "%d",I);
     fprintf(f3,"\n");
     fprintf(f3, "%d",J);
     fprintf(f3,"\n");
     fprintf(f3, "%d",V);
     fprintf(f3,"\n");
     fprintf(f3, "%s",H);
     fprintf(f3,"\n");
     if(V==1){
     fprintf(f3, "%s",P);

     }
     fclose(f3);
       }
        I1=0;
        if(M==2){
            getchar();
        }
       }

         if(q!=100&&q!=200&&q!=300){
                if(V==1){

         gets(W);

         gets(E);

         gets(R);
         w=atoi(W);
         e=atoi(E);
         r=atoi(R);
                }
                if(V==2){
                int count=0;
                flag4=0;
            for(count=0;count<12;count++){
            q=gread[count][0];
            w=gread[count][1];
            e=gread[count][2];
            r=gread[count][3];
            d=error_easy (q,w,e,r,A);
                if(d!=1){
            chl1(q,w,e,r,2,A);
            turn_in_e(&q,&w,&e,&r);

                flag4=score1(easy,s,q,w,e,r,0);
                if(flag4!=s){


                    break;
                }
                else{I--;}


            }
            }
int flag6=0; //check if player has a chance to get point

int count1=0;
int q_1,w_1,e_1,r_1; // take q,w,e,r and return them if player 1 will not get point
int hoh=I; // number of played moves
int ro=0; // number for checked moves to get point

if(flag4==s){
        while(1){
for(count=ro;count<12;count++){
            q=gread[count][0];
            w=gread[count][1];
            e=gread[count][2];
            r=gread[count][3];

            d=error_easy (q,w,e,r,A);
                if(d!=1){
            chl1(q,w,e,r,2,A);
            turn_in_e(&q,&w,&e,&r);
            q_1=q;
            w_1=w;
            e_1=e;
            r_1=r;
            ro=count;
            break;
            }
            }
            ro++;
if(q==w){
                for(i=(e+1);i<r;i++){
                    easy[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                easy[i][e]='|';
    }
}
flag6=0;

for(count1=0;count1<12;count1++){
            q=gread[count1][0];
            w=gread[count1][1];
            e=gread[count1][2];
            r=gread[count1][3];
            d=error_easy (q,w,e,r,A);
                if(d!=1){
            chl1(q,w,e,r,2,A);
            turn_in_e(&q,&w,&e,&r);

                flag6=score1(easy,flag6,q,w,e,r,0);
                if(flag6==0){
                    I--;
                }
                else{
                    I--;
                }
            }
            }



if(flag6==0){
I=hoh+1;
        if(q_1==w_1){
                for(i=(e_1+1);i<r_1;i++){
                    easy[w_1][i]='\0';
    }
}
        if(e_1==r_1){
            for(i=(q_1+1);i<w_1;i++){
                easy[i][e_1]='\0';
    }
}
q=q_1;
w=w_1;
e=e_1;
r=r_1;
A[I][0]=0;
A[I][1]=0;
A[I][2]=0;
A[I][3]=0;
A[I][4]=0;



    break;
}
else{
if(q_1==w_1){
                for(i=(e_1+1);i<r_1;i++){
                    easy[w_1][i]='\0';
    }
}
        if(e_1==r_1){
            for(i=(q_1+1);i<w_1;i++){
                easy[i][e_1]='\0';
    }
}
I=hoh;


flag6=0;
}

if(count==12){
oop=1;
                   while(1){
q=rand()%3+1;
w=q;
e=rand()%3+1;
r=e+1;
d=error_easy (q,w,e,r,A);
if(d==1){

    w=q+1;
    r=e;

d=error_easy (q,w,e,r,A);
}
if(d==1){

    w=q-1;
    r=e;

d=error_easy (q,w,e,r,A);
}
if(d==1){

    e=r-1;
    w=q;

d=error_easy (q,w,e,r,A);
}

if(d!=1){
    break;
}




         }

    I=hoh+1;
        if(q_1==w_1){
                for(i=(e_1+1);i<r_1;i++){
                    easy[w_1][i]='\0';
    }
}
        if(e_1==r_1){
            for(i=(q_1+1);i<w_1;i++){
                easy[i][e_1]='\0';
    }
}

A[I][0]=0;
A[I][1]=0;
A[I][2]=0;
A[I][3]=0;
A[I][4]=0;



    break;


}



}
                }


                }
         int u;
         if(q>w){
            u=w;
            w=q;
            q=u;
         }
         if(e>r){
            u=e;
            e=r;
            r=u;
         }
            if(V==1||oop==1){
         d=error_easy (q,w,e,r,A);
            }
         if(d==0)
         {
            if(V==1||oop==1){
                  chl1(q,w,e,r,2,A);
            }
        p++;
        for(Y=0;Y<12;Y++){
        for(X=0;X<5;X++){
            B[Y][X]=0;
            J=0;
        }
    }
if(V==1||oop==1){
        turn_in_e(&q,&w,&e,&r);
}
        if(q==w){
                for(i=(e+1);i<r;i++){
                    easy[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                easy[i][e]='|';
    }
}
        int a=0;
        a=score1(easy,0,q,w,e,r,1);
        if(a!=0){
            p--;
        }
         }

    }

        }
        color(7,0);
        system("cls");
    gotoxy(5,6);
    printf("1   2   3");
    gotoxy(5,9);
    printf("%c   %c   %c   1",178,178,178);
    gotoxy(5,13);
    printf("%c   %c   %c   2",178,178,178);
    gotoxy(5,17);
    printf("%c   %c   %c   3",178,178,178);
    int S;
    k=0;
    s=0;

l1=0;
l2=0;
    int o;
    arr_e(easy);
    for(S=0;S<I;S++){
        q=A[S][0];
        w=A[S][1];
        e=A[S][2];
        r=A[S][3];
        o=A[S][4];
        turn_in_e(&q,&w,&e,&r);
        if(q==w){
                for(i=(e+1);i<r;i++){
                    easy[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                easy[i][e]='|';
    }
}

        if(o==1){
                int c=k;
    l1++;
            color(11,0);
            hoba(q,w,e,r);
       k=score1(easy,k,q,w,e,r,1);
       if(S==I-1){
        if(c!=k){
            p=2;
        }
        else{
            p=3;
        }
       }

        }
        if(o==2){
                int c=s;
            color(12,0);
    l2++;
       s=score1(easy,s,q,w,e,r,1);
    if(S==I-1){
        if(c!=s){
            p=3;
        }
         else{
            p=2;
        }
       }
       hoba(q,w,e,r);
        }

    }
    if(I==0){
        p=0;
    }
    color(14,0);
    gotoxy(40,9);
    printf("Remaining moves : %d",12-I);
    gotoxy(40,11);
    color(11,0);
    printf("Player one , %s : ",H);
    gotoxy(40,13);
    printf("Moves : %d",l1);
    gotoxy(40,14);
    printf("Score : %d",k);
    gotoxy(40,16);
    color(12,0);
    printf("Player two , %s : ",P);
    gotoxy(40,18);
    printf("Moves : %d",l2);
    gotoxy(40,19);
    printf("score : %d",s);
    time(&end_t);
   diff_t = difftime(end_t, start_t);
   gotoxy(40,7);
   color(14,0);
       int mins,secn;
       mins=diff_t/60;
       secn=diff_t%60;
    printf("Execution time is mins : sec = %d : %d\n", mins,secn);
    gotoxy(0,25);

    }


}

if(N==2){
    int l1,l2;
    int mins=0,secn=0;
    l1=0;
    l2=0;
    int d;
    char Q[200],W[200],E[200],R[200];
    int B[60][5];
    int Y,X;
    for(Y=0;Y<60;Y++){
        for(X=0;X<5;X++){
            B[Y][X]=0;
        }
    }
    int A[60][5];
    for(Y=0;Y<60;Y++){
        for(X=0;X<5;X++){
            A[Y][X]=0;
        }

    }
    int q,w,e,r,i,p;
    k=0;
    p=2;
    s=0;

    char hard[21][21];
    arr_h(hard);
    gotoxy(0,1);
    print_arr_h(hard);
         if(M==2){
if(F==1){
            f=fopen("save.txt","r");
      int y;
      int j,i;


         if( fscanf(f, "%1d", & y ) == 1 )
          {
              y=y;
          }

      for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f, "%1d", & y ) == 1 )
          {
              A[i][j]=y;
          }


         }
     }

      for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f, "%1d", & y ) == 1 )
          {
              B[i][j]=y;
          }


         }
     }
     if( fscanf(f, "%d", & y ) == 1 )
          {
              I=y;
          }
          if( fscanf(f, "%d", & y ) == 1 )
          {
              J=y;
          }


           if( fscanf(f, "%d", & y ) == 1 )
          {
              V=y;
          }




          fscanf(f,"%s",H);
          if(V==1){
          fscanf(f,"%s",P);
          }
     fclose(f);

     }
          if(F==2){
            f2=fopen("save2.txt","r");
      int y;
      int j,i;


         if( fscanf(f2, "%1d", & y ) == 1 )
          {
              y=y;
          }

      for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f2, "%1d", & y ) == 1 )
          {
              A[i][j]=y;
          }


         }
     }

      for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f2, "%1d", & y ) == 1 )
          {
              B[i][j]=y;
          }


         }
     }
     if( fscanf(f2, "%d", & y ) == 1 )
          {
              I=y;
          }
          if( fscanf(f2, "%d", & y ) == 1 )
          {
              J=y;
          }


           if( fscanf(f2, "%d", & y ) == 1 )
          {
              V=y;
          }




          fscanf(f2,"%s",H);
          if(V==1){
          fscanf(f2,"%s",P);
          }
     fclose(f2);

     }

     if(F==3){
            f3=fopen("save3.txt","r");
      int y;
      int j,i;


         if( fscanf(f3, "%1d", & y ) == 1 )
          {
              y=y;
          }

      for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f3, "%1d", & y ) == 1 )
          {
              A[i][j]=y;
          }


         }
     }

      for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
            if( fscanf(f3, "%1d", & y ) == 1 )
          {
              B[i][j]=y;
          }


         }
     }
     if( fscanf(f3, "%d", & y ) == 1 )
          {
              I=y;
          }
          if( fscanf(f3, "%d", & y ) == 1 )
          {
              J=y;
          }


           if( fscanf(f3, "%d", & y ) == 1 )
          {
              V=y;
          }




          fscanf(f3,"%s",H);
          if(V==1){
          fscanf(f3,"%s",P);
          }
     fclose(f3);

     }
     // file tow
     }
    while(I<60){
        int o;
    int S;
    l1=0;
    l2=0;
    color(7,0);
        system("cls");
        gotoxy(0,1);
        print_arr_h(hard);

    k=0;
    s=0;


    arr_h(hard);
    for(S=0;S<I;S++){
        q=A[S][0];
        w=A[S][1];
        e=A[S][2];
        r=A[S][3];
        o=A[S][4];
        turn_in_h(&q,&w,&e,&r);
        if(q==w){
                for(i=(e+1);i<r;i++){
                    hard[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                hard[i][e]='|';
    }
}
        if(o==1){
                int c=k;
            color(11,0);
            puti(q,w,e,r);
       k=score(hard,k,q,w,e,r,1);
       l1++;
        if(S==I-1){
        if(c!=k){
            p=2;
        }
        else{
            p=3;
        }
       }


        }
        if(o==2){
            color(12,0);
        int c=s;
        l2++;
       s=score(hard,s,q,w,e,r,1);
        if(S==I-1){
        if(c!=s){
            p=3;
        }
         else{
            p=2;
        }
       }
       puti(q,w,e,r);
        }

    }
    color(14,0);
    gotoxy(40,9);
    printf("Remaining moves : %d",60-I);
    gotoxy(40,11);
    color(11,0);
    printf("player one , %s :",H);
    gotoxy(40,13);
    printf("moves : %d",l1);
    gotoxy(40,14);
    printf("score : %d",k);
    gotoxy(40,16);
    color(12,0);
    printf("player two , %s :",P);
    gotoxy(40,18);
    printf("moves : %d",l2);
    gotoxy(40,19);
    printf("score : %d",s);
    gotoxy(40,7);
    color(14,0);
    printf("Execution time is mins : sec = %d : %d",mins,secn);
    gotoxy(0,26);
        if(p%2==0){
            gotoxy(0,26);
            color(11,0);
         printf("now player1 , enter your move : \n");
         gotoxy(0,27);
         if(I1==0&&M!=2){
         getchar();
         I1=1;
         }

         gets(Q);
         q=atoi(Q);
       if(q==300){
            system("cls");
    printf("Save\n1-File one\n2-File two\n3-File three");
    printf("\n");
while(1)
{
scanf("%s",&T5);
F=atoi(T5);
y1=error_second(F);
if(y1==0)
{
    break;
}
else
{
    printf("error\n");
}

}
    if(F==1){
        int j;

        f=fopen("save.txt","w");
        fprintf(f, "%d",N);
         for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f, "%d", A[i][j]);
         }
     }
     fprintf(f,"\n");
        for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f, "%d", B[i][j]);
         }
     }

     fprintf(f,"\n");
     fprintf(f, "%d",I);
     fprintf(f,"\n");
     fprintf(f, "%d",J);
     fprintf(f,"\n");
     fprintf(f, "%d",V);
     fprintf(f,"\n");
     fprintf(f, "%s",H);
fprintf(f,"\n");
     if(V==1){
     fprintf(f, "%s",P);

     }
     fclose(f);
       }
           if(F==2){
        int j;

        f2=fopen("save2.txt","w");
        fprintf(f2, "%d",N);
         for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f2, "%d", A[i][j]);
         }
     }
      fprintf(f2,"\n");
        for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f2, "%d", B[i][j]);
         }
     }
     fprintf(f2,"\n");
     fprintf(f2, "%d",I);
     fprintf(f2,"\n");
     fprintf(f2, "%d",J);
     fprintf(f2,"\n");
     fprintf(f2, "%d",V);
     fprintf(f2,"\n");
     fprintf(f2, "%s",H);
fprintf(f2,"\n");
     if(V==1){
     fprintf(f2, "%s",P);

     }
     fclose(f2);
       }

           if(F==3){
        int j;

        f3=fopen("save3.txt","w");
        fprintf(f3, "%d",N);
         for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f3, "%d", A[i][j]);
         }
     }
      fprintf(f3,"\n");
        for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f3, "%d", B[i][j]);
         }
     }
     fprintf(f3,"\n");
     fprintf(f3, "%d",I);
     fprintf(f3,"\n");
     fprintf(f3, "%d",J);
     fprintf(f3,"\n");
     fprintf(f3, "%d",V);
     fprintf(f3,"\n");
     fprintf(f3, "%s",H);
fprintf(f3,"\n");
     if(V==1){
     fprintf(f3, "%s",P);

     }
     fclose(f3);
       }
        I1=0;
        if(M==2){
            getchar();
        }
       }
                 if(q==200){
                if(V==1){
            J--;
            if(J<0){
                J=0;
                continue;
            }


     A[I][0]=B[J][0];
     A[I][1]=B[J][1];
     A[I][2]=B[J][2];
     A[I][3]=B[J][3];
     A[I][4]=B[J][4];
    B[J][0]=0;
    B[J][1]=0;
    B[J][2]=0;
    B[J][3]=0;
    B[J][4]=0;

    I++;
                }
                if(V==2){
                            if(J>0){

            J--;


     A[I][0]=B[J][0];
     A[I][1]=B[J][1];
     A[I][2]=B[J][2];
     A[I][3]=B[J][3];
     A[I][4]=B[J][4];
    B[J][0]=0;
    B[J][1]=0;
    B[J][2]=0;
    B[J][3]=0;
    B[J][4]=0;

    I++;

                }
                int g=B[J-1][4];
                while(g==2){
            J--;
            g=B[J-1][4];
            if(J<0){
                J=0;
                break;
            }
     A[I][0]=B[J][0];
     A[I][1]=B[J][1];
     A[I][2]=B[J][2];
     A[I][3]=B[J][3];
     A[I][4]=B[J][4];
    B[J][0]=0;
    B[J][1]=0;
    B[J][2]=0;
    B[J][3]=0;
    B[J][4]=0;

    I++;
                }




                }
       }
        if(q==100){
             if(V==1){
             if(I==0){
                continue;
            }

            I--;


    B[J][0]=A[I][0];
    B[J][1]=A[I][1];
    B[J][2]=A[I][2];
    B[J][3]=A[I][3];
    B[J][4]=A[I][4];
    A[I][0]=0;
    A[I][1]=0;
        A[I][2]=0;
         A[I][3]=0;
         A[I][4]=0;
    J++;
    if (q==0){
        continue;
    }

         }
         int G=0;
         int ss=0;
         int L=A[I-1][4];
         if(V==2){
                while(L==2){
             if(I==0){
                break;
            }

            I--;
    L=A[I-1][4];
    int cho=A[I][4];
    B[J][0]=A[I][0];
    B[J][1]=A[I][1];
    B[J][2]=A[I][2];
    B[J][3]=A[I][3];
    B[J][4]=A[I][4];
    A[I][0]=0;
    A[I][1]=0;
        A[I][2]=0;
         A[I][3]=0;
         A[I][4]=0;
    J++;



         }


    if(I!=0){

            I--;
    B[J][0]=A[I][0];
    B[J][1]=A[I][1];
    B[J][2]=A[I][2];
    B[J][3]=A[I][3];
    B[J][4]=A[I][4];
    A[I][0]=0;
    A[I][1]=0;
    A[I][2]=0;
    A[I][3]=0;
    A[I][4]=0;
    J++;

         }
}


         }

        if(q!=100&&q!=200&&q!=300){

         gets(W);

         gets(E);

         gets(R);
         w=atoi(W);
         e=atoi(E);
         r=atoi(R);
         int u;
         if(q>w){
            u=w;
            w=q;
            q=u;
         }
         if(e>r){
            u=e;
            e=r;
            r=u;
         }
         d=error_hard (q,w,e,r,A);
         if(d==0)
         {


         chl(q,w,e,r,1,A);
        p++;

     for(Y=0;Y<60;Y++){
        for(X=0;X<5;X++){
            B[Y][X]=0;
            J=0;
        }
    }
        turn_in_h(&q,&w,&e,&r);
        if(q==w){
                for(i=(e+1);i<r;i++){
                    hard[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                hard[i][e]='|';
    }
}
        int a=0;
        a=score(hard,0,q,w,e,r,1);
        if(a!=0){
            p--;
        }



        }
        }}
       else if(p%2!=0){
            gotoxy(0,26);
            color(12,0);
         printf("now player2 , enter your move : \n");
         gotoxy(0,27);
         if(I1==0&&M!=2){
         getchar();
         I1=1;
         }
         if(V==1){
         gets(Q);
         q=atoi(Q);
         }
       if(q==300){
            system("cls");
    printf("Save\n1-File one\n2-File two\n3-File three");
    printf("\n");
while(1)
{
scanf("%s",&T5);
F=atoi(T5);
y1=error_second(F);
if(y1==0)
{
    break;
}
else
{
    printf("error\n");
}
}
    if(F==1){
        int j;

        f=fopen("save.txt","w");
        fprintf(f, "%d",N);
         for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f, "%d", A[i][j]);
         }
     }
      fprintf(f,"\n");
        for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f, "%d", B[i][j]);
         }
     }
     fprintf(f,"\n");
     fprintf(f, "%d",I);
     fprintf(f,"\n");
     fprintf(f, "%d",J);
     fprintf(f,"\n");
     fprintf(f, "%d",V);
     fprintf(f,"\n");
     fprintf(f, "%s",H);
fprintf(f,"\n");
     if(V==1){
     fprintf(f, "%s",P);

     }
     fclose(f);
       }
           if(F==2){
        int j;

        f2=fopen("save2.txt","w");
        fprintf(f2, "%d",N);
         for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f2, "%d", A[i][j]);
         }
     }
      fprintf(f2,"\n");
        for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f2, "%d", B[i][j]);
         }
     }
     fprintf(f2,"\n");
     fprintf(f2, "%d",I);
     fprintf(f2,"\n");
     fprintf(f2, "%d",J);
     fprintf(f2,"\n");
     fprintf(f2, "%d",V);
     fprintf(f2,"\n");
     fprintf(f2, "%s",H);
fprintf(f2,"\n");
     if(V==1){
     fprintf(f2, "%s",P);

     }
     fclose(f2);
       }

           if(F==3){
        int j;

        f3=fopen("save3.txt","w");
        fprintf(f3, "%d",N);
         for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f3, "%d", A[i][j]);
         }
     }
      fprintf(f3,"\n");
        for(i=0;i<60;i++)
     {
         for(j=0;j<5;j++)
         {
             fprintf(f3, "%d", B[i][j]);
         }
     }
     fprintf(f3,"\n");
     fprintf(f3, "%d",I);
     fprintf(f3,"\n");
     fprintf(f3, "%d",J);
     fprintf(f3,"\n");
     fprintf(f3, "%d",V);
     fprintf(f3,"\n");
     fprintf(f3, "%s",H);
     fprintf(f3,"\n");
     if(V==1){
     fprintf(f3, "%s",P);

     }
     fclose(f3);
       }
        I1=0;
        if(M==2){
            getchar();
        }
       }

                  if(q==200){
            J--;
            if(J<0){
                J=0;
                continue;
            }


     A[I][0]=B[J][0];
     A[I][1]=B[J][1];
     A[I][2]=B[J][2];
     A[I][3]=B[J][3];
     A[I][4]=B[J][4];
    B[J][0]=0;
    B[J][1]=0;
    B[J][2]=0;
    B[J][3]=0;
    B[J][4]=0;

    I++;
       }

         if(q==100){
            if(I==0){
                continue;
            }

            I--;


    B[J][0]=A[I][0];
    B[J][1]=A[I][1];
    B[J][2]=A[I][2];
    B[J][3]=A[I][3];
    B[J][4]=A[I][4];
    A[I][0]=0;
    A[I][1]=0;
        A[I][2]=0;
         A[I][3]=0;
         A[I][4]=0;
    J++;
    if (q==0){
        continue;
    }


        }
        if(q!=100&&q!=200&&q!=300){
                if(V==1){

         gets(W);

         gets(E);

         gets(R);
         w=atoi(W);
         e=atoi(E);
         r=atoi(R);
                }
                int flag4;
                if(V==2){
 int count=0;
 flag4=0;
            for(count=0;count<60;count++){
            q=gread[count][0];
            w=gread[count][1];
            e=gread[count][2];
            r=gread[count][3];
            d=error_hard(q,w,e,r,A);
                if(d!=1){
            chl(q,w,e,r,2,A);
            turn_in_h(&q,&w,&e,&r);

                flag4=score(hard,s,q,w,e,r,0);
                if(flag4!=s){


                    break;
                }
                else{I--;}


            }
            }
int flag6=0;

int count1=0;
int q_1,w_1,e_1,r_1;
int hoh=I;
int ro=0;

if(flag4==s){
        while(1){
for(count=ro;count<60;count++){
            q=gread[count][0];
            w=gread[count][1];
            e=gread[count][2];
            r=gread[count][3];

            d=error_hard(q,w,e,r,A);
                if(d!=1){
            chl(q,w,e,r,2,A);
            turn_in_h(&q,&w,&e,&r);
            q_1=q;
            w_1=w;
            e_1=e;
            r_1=r;
            ro=count;
            break;
            }
            }
            ro++;
if(q==w){
                for(i=(e+1);i<r;i++){
                    hard[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                hard[i][e]='|';
    }
}
flag6=0;

for(count1=0;count1<60;count1++){
            q=gread[count1][0];
            w=gread[count1][1];
            e=gread[count1][2];
            r=gread[count1][3];
            d=error_hard(q,w,e,r,A);
                if(d!=1){
            chl(q,w,e,r,2,A);
            turn_in_h(&q,&w,&e,&r);

                flag6=score(hard,flag6,q,w,e,r,0);
                if(flag6==0){
                    I--;
                }
                else{
                    I--;
                }
            }
            }



if(flag6==0){
I=hoh+1;
        if(q_1==w_1){
                for(i=(e_1+1);i<r_1;i++){
                    hard[w_1][i]='\0';
    }
}
        if(e_1==r_1){
            for(i=(q_1+1);i<w_1;i++){
                hard[i][e_1]='\0';
    }
}
q=q_1;
w=w_1;
e=e_1;
r=r_1;
A[I][0]=0;
A[I][1]=0;
A[I][2]=0;
A[I][3]=0;
A[I][4]=0;



    break;
}
else{
if(q_1==w_1){
                for(i=(e_1+1);i<r_1;i++){
                    hard[w_1][i]='\0';
    }
}
        if(e_1==r_1){
            for(i=(q_1+1);i<w_1;i++){
                hard[i][e_1]='\0';
    }
}
I=hoh;


flag6=0;
}

if(count==60){
oop=1;
                   while(1){
q=rand()%5+1;
w=q;
e=rand()%5+1;
r=e+1;
d=error_hard(q,w,e,r,A);
if(d==1){

    w=q+1;
    r=e;

d=error_hard(q,w,e,r,A);
}
if(d==1){

    w=q-1;
    r=e;

d=error_hard(q,w,e,r,A);
}
if(d==1){

    e=r-1;
    w=q;

d=error_hard(q,w,e,r,A);
}

if(d!=1){
    break;
}




         }

    I=hoh+1;
        if(q_1==w_1){
                for(i=(e_1+1);i<r_1;i++){
                    hard[w_1][i]='\0';
    }
}
        if(e_1==r_1){
            for(i=(q_1+1);i<w_1;i++){
                hard[i][e_1]='\0';
    }
}

A[I][0]=0;
A[I][1]=0;
A[I][2]=0;
A[I][3]=0;
A[I][4]=0;



    break;


}



}
                }


                }
         int u;
         if(q>w){
            u=w;
            w=q;
            q=u;
         }
         if(e>r){
            u=e;
            e=r;
            r=u;
         }if(flag4==s||V==1){
         d=error_hard (q,w,e,r,A);
         }
         if(d==0)
         {

if(flag4==s||V==1){
         chl(q,w,e,r,2,A);
}
        p++;

     for(Y=0;Y<60;Y++){
        for(X=0;X<5;X++){
            B[Y][X]=0;
            J=0;
        }
    }
    if(flag4==s||V==1){
        turn_in_h(&q,&w,&e,&r);
    }
        if(q==w){
                for(i=(e+1);i<r;i++){
                    hard[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                hard[i][e]='|';
    }
}
        int a=0;
        a=score(hard,0,q,w,e,r,1);
        if(a!=0){
            p--;
        }


        }



        }

        }
        color(7,0);
        system("cls");
        gotoxy(0,1);
        print_arr_h(hard);

    k=0;
    s=0;


    arr_h(hard);
    l1=l2=0;
    for(S=0;S<I;S++){
        q=A[S][0];
        w=A[S][1];
        e=A[S][2];
        r=A[S][3];
        o=A[S][4];
        turn_in_h(&q,&w,&e,&r);
        if(q==w){
                for(i=(e+1);i<r;i++){
                    hard[w][i]='-';
    }
}
        if(e==r){
            for(i=(q+1);i<w;i++){
                hard[i][e]='|';
    }
}
        if(o==1){
                int c=k;
                l1++;
            color(11,0);
            puti(q,w,e,r);
       k=score(hard,k,q,w,e,r,1);
        if(S==I-1){
        if(c!=k){
            p=2;
        }
        else{
            p=3;
        }
       }


        }

        if(o==2){
            color(12,0);
        int c=s;
        l2++;
       s=score(hard,s,q,w,e,r,1);
        if(S==I-1){
        if(c!=s){
            p=3;
        }
         else{
            p=2;
        }
       }
       puti(q,w,e,r);
        }


    }
    time(&end_t);
    diff_t = difftime(end_t, start_t);
    color(14,0);
    gotoxy(40,13);
    printf("Remaining moves : %d",60-I);
    gotoxy(40,15);
    color(11,0);
    printf("player one , %s :",H);
    gotoxy(40,17);
    printf("moves : %d",l1);
    gotoxy(40,18);
    printf("score : %d",k);
    gotoxy(40,20);
    color(12,0);
    printf("player two , %s :",P);
    gotoxy(40,22);
    printf("moves : %d",l2);
    gotoxy(40,23);
    printf("score : %d",s);
    gotoxy(40,11);
    color(14,0);
       mins=diff_t/60;
       secn=diff_t%60;
    printf("Execution time is mins : sec = %d : %d",mins,secn);
    time(&end_t);


    if(I==0){
        p=0;
    }
    }


    }
if(M==4)
{
    break;
}
if(k>s||V==1){
    int i, temp=0;
int y;
top=fopen("top.txt","r");
while( fscanf(top, "%d", & y ) == 1 ){
best[temp].scor=y;
fscanf(top,"%s",best[temp].name);
temp++;
}
fclose(top);
int s12=temp;// 3dd eli fi el file
int ch; // score for winner
int co=temp; // number of names in file
char name1[200];
int m1=0; //minum score
if(k>s){
    ch=k;
    strcpy(name1,H);
}
if(s>k){
    ch=s;
    strcpy(name1,P);
}
int flag3=0; //check if the winner is exist
int j,swap,c=0,d,flag2=0; // take number of chars
int nomb=0;
char qwer[200];
 for(i=0;i<co;i++){
    while(best[i].name[c]==name1[c]){

        c++;
        flag2=c;
        nomb=i;
    if(c==strlen(name1) && strlen(name1)==strlen(best[i].name)){
      flag3=1;
      break;
    }
    if(flag3==1){
        break;
    }
    }

    c=0;
 }
 int flag=0;
 if(strlen(name1)==flag2){
    flag=1;
    if(best[nomb].scor<ch){
        best[nomb].scor=ch;
    }
 }
 if(flag!=1){
 if(flag !=1){
if(temp==10){
    for(i=0;i<9;i++){

        if(best[m1].scor<best[i+1].scor){

        }
        else{
            m1=i+1;
        }
    }
}
 }
 if(flag !=1){
if(temp<10){
if(k>s){
    strcpy(best[temp].name,H);
    best[temp].scor=k;
}
if(s>k){
    strcpy(best[temp].name,P);
    best[temp].scor=s;
}
}
 }
int sh=temp;
if(s12<10&&flag!=1){
    s12++;
}
char cha[200];
if(flag!=1){
if(temp==10){
    temp=m1;
    if(ch>best[temp].scor){
    strcpy(best[temp].name,name1);
    best[temp].scor=ch;
}}
}
 }
  for (c = 0 ; c < ( s12 ); c++)
  {
    for (d = 0 ; d < s12 - c ; d++)
    {
      if (best[d].scor < best[d+1].scor) /* For decreasing order use < */
      {
        swap       = best[d].scor;
        strcpy(qwer,best[d].name);
        best[d].scor   = best[d+1].scor;
        strcpy(best[d].name,best[d+1].name);
        best[d+1].scor = swap;
        strcpy(best[d+1].name,qwer);
      }
    }
  }
top=fopen("top.txt","w");
for(i=0;i<s12;i++){
fprintf(top,"%d",best[i].scor);
fprintf(top,"\n");
fprintf(top,"%s",best[i].name);
fprintf(top,"\n");
}
fclose(top);
gotoxy(0,27);
color(4,7);
if(k==s)
{
    printf("Game is drawn");
}
if(k>s){
    printf("%s won the game",H);
}
if(s>k){
    printf("%s won the game",P);
}
color(7,0);
printf("\nPress enter to return to menu :\n");
}
getchar();
N=M=F=V=0;

    }
    return 0;
}
int score1(char c[9][9],int k,int q,int w,int e,int r,int h){


if(q==w)
    {
        if(w==4)
        {
            if(c[w+1][e]!='\0' && c[w+1][r]!='\0' && c[w+4][r-1]!='\0')
            {
                k++;
                    if (h==1){
                    gotoxy(6+e,14);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6+e,15);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6+e,16);
                    printf("%c%c%c",219,219,219);
            }}
            if(c[w-1][e]!='\0' && c[w-1][r]!='\0' && c[w-4][r-1]!='\0')
            {
                k++;
                if (h==1){
                    gotoxy(6+e,10);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6+e,11);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6+e,12);
                    printf("%c%c%c",219,219,219);
            }}
        }
        if(w==0){
            if(c[w+1][e]!='\0' && c[w+1][r]!='\0' && c[w+4][r-1]!='\0')
            {
                if (h==1){
                    gotoxy(6+e,10);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6+e,11);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6+e,12);
                    printf("%c%c%c",219,219,219);
                }
                k++;
            }
        }
        if(w==8){
                if(c[w-1][e]!='\0' && c[w-1][r]!='\0' && c[w-4][r-1]!='\0')
            {
                k++;
                    if (h==1){
                    gotoxy(6+e,14);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6+e,15);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6+e,16);
                    printf("%c%c%c",219,219,219);
            }}

        }
    }
    if(e==r){
        if(e==4){
            if(c[q][r+1]!='\0' && c[w][r+1]!='\0' && c[w-1][r+4]!='\0')
            {
                k++;
if (h==1){
                    gotoxy(10,10+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(10,11+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(10,12+q);
                    printf("%c%c%c",219,219,219);
            }}
            if(c[q][r-1]!='\0' && c[w][r-1]!='\0' && c[w-1][r-4]!='\0')
            {
                k++;
                if (h==1){
                    gotoxy(6,10+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6,11+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6,12+q);
                    printf("%c%c%c",219,219,219);
            }}
        }
        if(e==0){
              if(c[q][r+1]!='\0' && c[w][r+1]!='\0' && c[w-1][r+4]!='\0')
            {
                k++;
                if (h==1){
                    gotoxy(6,10+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6,11+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(6,12+q);
                    printf("%c%c%c",219,219,219);
            }}

            }
        if(e==8){
           if(c[q][r-1]!='\0' && c[w][r-1]!='\0' && c[w-1][r-4]!='\0')
            {
                k++;
                if (h==1){

                    gotoxy(10,10+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(10,11+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(10,12+q);
                    printf("%c%c%c",219,219,219);
            }}
        }
    }
    return k;
}
void arr_e(char array[9][9]){
        int i,j;
for(i=0;i<9;i++){
        for(j=0;j<9;j++){
        array[i][j]='\0';
        }
    }
    array[0][0]='*';
    array[0][4]='*';
    array[0][8]='*';
    array[4][0]='*';
    array[4][4]='*';
    array[4][8]='*';
    array[8][0]='*';
    array[8][4]='*';
    array[8][8]='*';


}
void turn_in_e(int *a,int *b,int *c,int*d){
        if(*b==1){
        *b=0;
    }
    if(*a==1){
        *a=0;
    }
    if(*c==1){
        *c=0;
    }
    if(*d==1){
        *d=0;
    }
    if(*b==2){
        *b=4;
    }
    if(*a==2){
        *a=4;
    }
    if(*c==2){
        *c=4;
    }
    if(*d==2){
        *d=4;
    }
    if(*b==3){
        *b=8;
    }
    if(*a==3){
        *a=8;
    }
    if(*c==3){
        *c=8;
    }
    if(*d==3){
        *d=8;
    }

}
void chl1(int q,int w,int e,int r,int a,int A[12][5]){

    A[I][0]=q;
    A[I][1]=w;
    A[I][2]=e;
    A[I][3]=r;
    A[I][4]=a;
    I++;
}
int error_easy (int q,int w,int e,int r,int A[12][5]){

int n;
int x;
n=0;

         if(q==w){
            if(r-e!=1){
         n=1;
            return n;
            }
         }
         if(e==r){
            if(w-q!=1){
         n=1;
            return n;
            }
         }
         if(q>3||q<1||w>3||w<1||e>3||e<1||r>3||r<1){
         n=1;
            return n;
         }
         if(q!=w&&e!=r){
                 n=1;
            return n;
         }
         for(x=0;x<12;x++){
            if(A[x][0]==q&&A[x][1]==w&&A[x][2]==e&&A[x][3]==r){
                n=1;
            }
         }
         if(n==1){

         return n;
         }
         if(q!=1&&q!=2&&q!=3){
         n=1;
            return n;
         }
         if(w!=1&&w!=2&&w!=3){
         n=1;
            return n;
         }
         if(e!=1&&e!=2&&e!=3){
         n=1;
            return n;
         }
         if(r!=1&&r!=2&&r!=3){
         n=1;
            return n;
         }
         return n;
}
void turn_in_h(int *a,int *b,int *c,int*d){
    if(*b==1){
    *b=0;
    }
    if(*a==1){
        *a=0;
    }
    if(*c==1){
        *c=0;
    }
    if(*d==1){
        *d=0;
    }

    if(*b==3){
        *b=8;
    }
    if(*a==3){
        *a=8;
    }
    if(*c==3){
        *c=8;
    }
    if(*d==3){
        *d=8;
    }
    if(*b==4){
        *b=12;
    }
    if(*a==4){
        *a=12;
    }
    if(*c==4){
        *c=12;
    }
    if(*d==4){
        *d=12;
    }
    if(*b==5){
        *b=16;
    }
    if(*a==5){
        *a=16;
    }
    if(*c==5){
        *c=16;
    }
    if(*d==5){
        *d=16;
    }
    if(*b==6){
        *b=20;
    }
    if(*a==6){
        *a=20;
    }
    if(*c==6){
        *c=20;
    }
    if(*d==6){
        *d=20;
    }
    if(*b==2){
        *b=4;
    }
    if(*a==2){
        *a=4;
    }
    if(*c==2){
        *c=4;
    }
    if(*d==2){
        *d=4;
    }

}
void arr_h(char array[21][21]){
        int i,j;
for(i=0;i<21;i++){
        for(j=0;j<21;j++){
        array[i][j]='\0';
        }
    }
for(i=0;i<21;i=i+4)
{
    for(j=0;j<21;j=j+4)
    {
        array[i][j]=178;
    }
}
}
void print_arr_h(char array[21][21]){

    int i,j;
     for(i=0;i<21;i++){
            if(i==0){
        printf("1   2   3   4   5   6\n");
            }
        for(j=0;j<21;j++){
            printf("%c",array[i][j]);
            if(j==20){
                if(i==0){
                    printf(" 1");
                 }
                    if(i==4){
                    printf(" 2");
                 }
                 if(i==8){
                    printf(" 3");
                 }
                 if(i==12){
                    printf(" 4");
                 }
                 if(i==16){
                    printf(" 5");
                 }
                 if(i==20){
                    printf(" 6");
                 }

                printf("\n");
            }
        }
    }

}

void puti(int q,int w,int e,int r){
   if(q==w){
        gotoxy(1+e,2+q);
        printf("---");

   }
   if(e==r){
                gotoxy(0+e,3+q);
                printf("|");
                gotoxy(0+e,4+q);
                printf("|");
                gotoxy(0+e,5+q);
                printf("|");

   }

}
int score(char c[21][21],int k,int q,int w,int e,int r,int h){

if(q==w){

        if(w==4||w==8||w==12||w==16)
        {
            if(c[w+1][e]!='\0' && c[w+1][r]!='\0' && c[w+4][r-1]!='\0')
            {
                k++;
if (h==1){
                gotoxy(1+e,w+3);
                printf("%c%c%c",219,219,219);
                gotoxy(1+e,w+4);
                printf("%c%c%c",219,219,219);
                gotoxy(1+e,w+5);
                printf("%c%c%c",219,219,219);
                }
            }

            if(c[w-1][e]!='\0' && c[w-1][r]!='\0' && c[w-4][r-1]!='\0')
            {
                k++;
if (h==1){
                gotoxy(1+e,w-1);
                printf("%c%c%c",219,219,219);
                gotoxy(1+e,w);
                printf("%c%c%c",219,219,219);
                gotoxy(1+e,w+1);
                printf("%c%c%c",219,219,219);
                }
          }  }

                if(w==0){
            if(c[w+1][e]!='\0' && c[w+1][r]!='\0' && c[w+4][r-1]!='\0')
            {
                k++;
                if (h==1){
                gotoxy(1+e,w+3);
                printf("%c%c%c",219,219,219);
                gotoxy(1+e,w+4);
                printf("%c%c%c",219,219,219);
                gotoxy(1+e,w+5);
                printf("%c%c%c",219,219,219);
            }}
        }
                if(w==20){
                if(c[w-1][e]!='\0' && c[w-1][r]!='\0' && c[w-4][r-1]!='\0')
            {
                k++;
                if (h==1){
                gotoxy(1+e,w-1);
                printf("%c%c%c",219,219,219);
                gotoxy(1+e,w);
                printf("%c%c%c",219,219,219);
                gotoxy(1+e,w+1);
                printf("%c%c%c",219,219,219);

                }

            }

        }


        }


     if(e==r){
            if(e==4||e==8||e==12||e==16){
            if(c[q][r+1]!='\0' && c[w][r+1]!='\0' && c[w-1][r+4]!='\0')
            {
                k++;
if (h==1){
                    gotoxy(e+1,q+3);
                    printf("%c%c%c",219,219,219);
                    gotoxy(e+1,q+4);
                    printf("%c%c%c",219,219,219);
                    gotoxy(e+1,q+5);
                    printf("%c%c%c",219,219,219);

          }  }
            if(c[q][r-1]!='\0' && c[w][r-1]!='\0' && c[w-1][r-4]!='\0')
            {
                k++;
if (h==1){
                    gotoxy(e-3,3+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(e-3,4+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(e-3,5+q);
                    printf("%c%c%c",219,219,219);
            }
        }}

                if(e==0){
              if(c[q][r+1]!='\0' && c[w][r+1]!='\0' && c[w-1][r+4]!='\0')
            {
                k++;
                if (h==1){
                 gotoxy(e+1,q+3);
                    printf("%c%c%c",219,219,219);
                    gotoxy(e+1,q+4);
                    printf("%c%c%c",219,219,219);
                    gotoxy(e+1,q+5);
                    printf("%c%c%c",219,219,219);
            }}
            }
                    if(e==20){
           if(c[q][r-1]!='\0' && c[w][r-1]!='\0' && c[w-1][r-4]!='\0')
            {
                k++;
if (h==1){
                    gotoxy(e-3,3+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(e-3,4+q);
                    printf("%c%c%c",219,219,219);
                    gotoxy(e-3,5+q);
                    printf("%c%c%c",219,219,219);
            }
        }}
        }
return k;
}

void chl(int q,int w,int e,int r,int a,int A[60][5]){

    A[I][0]=q;
    A[I][1]=w;
    A[I][2]=e;
    A[I][3]=r;
    A[I][4]=a;
    I++;

}
int error_hard (int q,int w,int e,int r,int A[60][5]){

int n;
int x;
n=0;

         if(q==w){
            if(r-e!=1){
         n=1;
            return n;
            }
         }
         if(e==r){
            if(w-q!=1){
         n=1;
            return n;
            }
         }
         if(q>6||q<1||w>6||w<1||e>6||e<1||r>6||r<1){
         n=1;
            return n;
         }
         if(q!=w&&e!=r){
                 n=1;
            return n;
         }
         for(x=0;x<60;x++){
            if(A[x][0]==q&&A[x][1]==w&&A[x][2]==e&&A[x][3]==r){
                n=1;
            }
         }
         if(n==1){

         return n;
         }
         if(q!=1&&q!=2&&q!=3&&q!=4&&q!=5&&q!=6){
         n=1;
            return n;
         }
         if(w!=1&&w!=2&&w!=3&&w!=4&&w!=5&&w!=6){
         n=1;
            return n;
         }
         if(e!=1&&e!=2&&e!=3&&e!=4&&e!=5&&e!=6){
         n=1;
            return n;
         }
         if(r!=1&&r!=2&&r!=3&&r!=4&&r!=5&&r!=6){
         n=1;
            return n;
         }
         return n;
}
int error_first(int z){
if(z==0)
{
    return 1;
}
if(z!=1 && z!=2)
{
    return 1;
}
else
{
    return 0;
}

}

int error_second(int z){
if(z==0)
{
    return 1;
}
if(z!=1 && z!=2 && z!=3)
{
    return 1;
}
else
{
    return 0;
}

}
int error_third(int z){
if(z==0)
{
    return 1;
}
if(z!=1 && z!=2 && z!=3 && z!=4 && z!=5)
{
    return 1;
}
else
{
    return 0;
}

}

void gready(int c[60][4]){
c[0][0]=1;
c[0][1]=1;
c[0][2]=1;
c[0][3]=2;
c[1][0]=1;
c[1][1]=1;
c[1][2]=2;
c[1][3]=3;

c[2][0]=2;
c[2][1]=2;
c[2][2]=1;
c[2][3]=2;

c[3][0]=2;
c[3][1]=2;
c[3][2]=2;
c[3][3]=3;

c[4][0]=3;
c[4][1]=3;
c[4][2]=1;
c[4][3]=2;

c[5][0]=3;
c[5][1]=3;
c[5][2]=2;
c[5][3]=3;

c[6][0]=1;
c[6][1]=2;
c[6][2]=1;
c[6][3]=1;

c[7][0]=1;
c[7][1]=2;
c[7][2]=2;
c[7][3]=2;

c[8][0]=1;
c[8][1]=2;
c[8][2]=3;
c[8][3]=3;

c[9][0]=2;
c[9][1]=3;
c[9][2]=1;
c[9][3]=1;

c[10][0]=2;
c[10][1]=3;
c[10][2]=2;
c[10][3]=2;

c[11][0]=2;
c[11][1]=3;
c[11][2]=3;
c[11][3]=3;

c[12][0]=1;
c[12][1]=1;
c[12][2]=3;
c[12][3]=4;

c[13][0]=1;
c[13][1]=1;
c[13][2]=4;
c[13][3]=5;

c[14][0]=2;
c[14][1]=2;
c[14][2]=3;
c[14][3]=4;

c[15][0]=2;
c[15][1]=2;
c[15][2]=4;
c[15][3]=5;

c[16][0]=3;
c[16][1]=3;
c[16][2]=3;
c[16][3]=4;

c[17][0]=3;
c[17][1]=3;
c[17][2]=4;
c[17][3]=5;

c[18][0]=4;
c[18][1]=4;
c[18][2]=1;
c[18][3]=2;

c[19][0]=4;
c[19][1]=4;
c[19][2]=2;
c[19][3]=3;

c[20][0]=4;
c[20][1]=4;
c[20][2]=3;
c[20][3]=4;

c[21][0]=4;
c[21][1]=4;
c[21][2]=4;
c[21][3]=5;

c[22][0]=5;
c[22][1]=5;
c[22][2]=1;
c[22][3]=2;

c[23][0]=5;
c[23][1]=5;
c[23][2]=2;
c[23][3]=3;

c[24][0]=5;
c[24][1]=5;
c[24][2]=3;
c[24][3]=4;

c[25][0]=5;
c[25][1]=5;
c[25][2]=4;
c[25][3]=5;

c[26][0]=6;
c[26][1]=6;
c[26][2]=1;
c[26][3]=2;

c[27][0]=6;
c[27][1]=6;
c[27][2]=2;
c[27][3]=3;

c[28][0]=6;
c[28][1]=6;
c[28][2]=3;
c[28][3]=4;

c[29][0]=6;
c[29][1]=6;
c[29][2]=4;
c[29][3]=5;

c[30][0]=3;
c[30][1]=4;
c[30][2]=1;
c[30][3]=1;

c[31][0]=3;
c[31][1]=4;
c[31][2]=2;
c[31][3]=2;

c[32][0]=3;
c[32][1]=4;
c[32][2]=3;
c[32][3]=3;

c[33][0]=3;
c[33][1]=4;
c[33][2]=4;
c[33][3]=4;

c[34][0]=3;
c[34][1]=4;
c[34][2]=5;
c[34][3]=5;

c[35][0]=3;
c[35][1]=4;
c[35][2]=6;
c[35][3]=6;

c[36][0]=4;
c[36][1]=5;
c[36][2]=1;
c[36][3]=1;

c[37][0]=4;
c[37][1]=5;
c[37][2]=2;
c[37][3]=2;

c[38][0]=4;
c[38][1]=5;
c[38][2]=3;
c[38][3]=3;

c[39][0]=4;
c[39][1]=5;
c[39][2]=4;
c[39][3]=4;

c[40][0]=4;
c[40][1]=5;
c[40][2]=5;
c[40][3]=5;

c[41][0]=4;
c[41][1]=5;
c[41][2]=6;
c[41][3]=6;

c[42][0]=5;
c[42][1]=6;
c[42][2]=1;
c[42][3]=1;

c[43][0]=5;
c[43][1]=6;
c[43][2]=2;
c[43][3]=2;

c[44][0]=5;
c[44][1]=6;
c[44][2]=3;
c[44][3]=3;

c[45][0]=5;
c[45][1]=6;
c[45][2]=4;
c[45][3]=4;

c[46][0]=5;
c[46][1]=6;
c[46][2]=5;
c[46][3]=5;

c[47][0]=5;
c[47][1]=6;
c[47][2]=6;
c[47][3]=6;

c[48][0]=2;
c[48][1]=3;
c[48][2]=4;
c[48][3]=4;

c[49][0]=2;
c[49][1]=3;
c[49][2]=5;
c[49][3]=5;

c[50][0]=2;
c[50][1]=3;
c[50][2]=6;
c[50][3]=6;

c[51][0]=1;
c[51][1]=2;
c[51][2]=6;
c[51][3]=6;

c[52][0]=1;
c[52][1]=1;
c[52][2]=5;
c[52][3]=6;

c[53][0]=2;
c[53][1]=2;
c[53][2]=5;
c[53][3]=6;

c[54][0]=3;
c[54][1]=3;
c[54][2]=5;
c[54][3]=6;

c[55][0]=4;
c[55][1]=4;
c[55][2]=5;
c[55][3]=6;

c[56][0]=5;
c[56][1]=5;
c[56][2]=5;
c[56][3]=6;

c[57][0]=6;
c[57][1]=6;
c[57][2]=5;
c[57][3]=6;

c[58][0]=1;
c[58][1]=2;
c[58][2]=5;
c[58][3]=5;

c[59][0]=1;
c[59][1]=2;
c[59][2]=4;
c[59][3]=4;
}
