// #include "RECLIB.H"
#include<stdlib.h>
#include "RECLIB.H"
typedef struct roll{
    int r;
    struct roll *next;
}roll;
void LOADER(){
    roll *head=(roll*)(malloc(sizeof(roll)));
    cl s;
    FILE *fp=fopen("new.txt","a+");
    while(fread(&s,sizeof(s),1,fp)){
        head->r=s.roll;
        printf("Records added : %d\n",head->r);    
        head->next=(roll*)malloc(sizeof(roll));
        head=head->next;
    }
}
