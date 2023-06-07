#include<conio.h>
#define ENTER 13
#define BKSC 8
// #include<stdio.h>
// #include<stdlib.h>
void HASH_1(char * s,size_t n){
    for(int i=0;i<n;i++){
        if(i%2==0){
            s[i]+=5;
        }
        else{
            s[i]-=5;
        }
    }
}
void HASH_2(char *s,size_t n){
    for(int i=0;i<n;i++){
        if(i%2==0){
            s[i]+=i+n;
        }
        else{
            s[i]+=(n+15)%(i+1);
        }
    }
}
void UNHASH_1(char * s,size_t n){
    for(int i=0;i<n;i++){
        if(i%2==0){
            s[i]-=5;
        }
        else{
            s[i]+=5;
        }
    }
}
void IPT_PASS(char* s){
    
    int i=0;
    char ch;
    while(1){
        ch=getch();
        if(ch==ENTER){
            s[i]=='\0';
            break;
        }
        else if(ch== BKSC){
            if(i>0){
                i--;
                printf("\b \b"); 
            }
        }
        else{
            s[i++]=ch;
            printf("* \b");
        }
    }
    printf("\n");
}