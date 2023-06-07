#include <stdio.h>
#include <math.h>
#include "PASS_HASH.H"
#include <string.h>
#include <stdlib.h>
#define pf printf
#define ll long long
typedef struct
{
    char name[50];
    int dob;
    int roll;
    char eml[80];
    char cnm[40];
    char adrs[100];
    ll phno;
    int mks[3];
    float avg;
    int age;
    char pass[50];
    float ptile;
} cl;
int UPDT()
{
    {
        FILE *ptr = fopen("C:\\Users\\univa\\Desktop\\File Handling\\File Handling\\new.txt", "a+");
        // FILE *p1 = fopen("C:\\Users\\univa\\Desktop\\File Handling\\File Handling\\n1.txt", "a+");
        cl s1;
        int k, f = 0;
        int ff = 0;
        char pass[50];
        pf("Enter the Roll No. : ");
        scanf("%d", &k);
        while (fread(&s1, sizeof(cl), 1, ptr))
        {
            if (s1.roll == k)
            {
                pf("Record Present\n");
                f = 1;
                pf("Enter password  : ");
                fflush(stdin);
                IPT_PASS(pass);
                HASH_2(pass, strlen(pass));
                printf("pass is %s", s1.pass);
                printf("psss : %s\n", pass);
                for (int i = 0; i < strlen(pass); i++)
                {
                    if (pass[i] != s1.pass[i])
                    {
                        pf("Wrong Password\nExiting...");
                        f = 2;
                        fclose(ptr);
                        return 0;
                    }
                }
                break;
            }
        }
        if (f == 1)
        {
            while (1)
            {
                pf("What you wish to modify : \n");
                pf("1.Name \n");
                pf("2.Class Name \n");
                pf("3.Phone\n");
                pf("4.Email ID\n");
                pf("5.Marks \n");
                pf("6.Address\n");
                char ch;
                ch = getch();
                switch (ch)
                {
                case '1':
                {
                    pf("Enter New Name : ");
                    fflush(stdin);
                    gets(s1.name);
                    break;
                }
                case '2':
                {
                    pf("Enter New Class : ");
                    fflush(stdin);
                    gets(s1.cnm);
                    break;
                }
                case '3':
                {
                    pf("Enter New Phone Number : ");
                    scanf("%lld", &s1.phno);
                    break;
                }
                case '4':
                {
                    pf("Enter E-mail ID : ");
                    fflush(stdin);
                    gets(s1.eml);
                    break;
                }
                case '6':
                {
                    pf("Enter New Address : ");
                    fflush(stdin);
                    gets(s1.adrs);
                    break;
                }
                default:
                {
                    pf("Invalid Choice \nExiting\n");
                    ff = 1;
                    break;
                }
                  fclose(ptr);  
                }
                if(ff==1){
                    break;
                }
            }
            cl s;
            FILE *fp1 = fopen("C:\\Users\\univa\\Desktop\\File Handling\\File Handling\\new.txt", "a+");
            FILE *fp2 = fopen("C:\\Users\\univa\\Desktop\\File Handling\\File Handling\\n1.txt", "a+");
            rewind(fp1);
            while (fread(&s, sizeof(cl), 1, fp1))
            {
                if (k == s.roll)
                {
                    continue;
                }
                fwrite(&s, sizeof(cl), 1, fp2);
            }
            fwrite(&s1, sizeof(cl), 1, fp2);
            fclose(fp1);
            fclose(fp2);
            remove("new.txt");
            int v = rename("n1.txt", "new.txt");
            pf("v : %d\n", v);
            return 0;
        }
    }
}
int main()
{
    UPDT();
    return 0;
}