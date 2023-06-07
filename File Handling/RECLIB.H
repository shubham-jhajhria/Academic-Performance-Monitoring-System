// Defining out Class
#include "PASS_HASH.H"
#include <stdio.h>
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

// Function for adding a record
int REC_ADD()
{
    // system("cls");
    cl s1, s;
    int f = 1;
    float sum;
    FILE *ptr = fopen("C:\\Users\\univa\\Desktop\\File Handling\\File Handling\\new.txt", "a+");
    pf("Enter the data in following format \n1.Roll No. : ");
    scanf("%d", &s.roll);
    while (fread(&s1, sizeof(s1), 1, ptr))
    {
        if (s.roll == s1.roll)
        {
            pf("Record Already present \n");
            return 0;
        }
    }
    s1.roll = s.roll;
    pf("2.Name :");
    fflush(stdin);
    gets(s1.name);
    pf("3.E-mail id : ");
    fflush(stdin);
    gets(s1.eml);
    pf("4.Address : ");
    fflush(stdin);
    gets(s1.adrs);
    pf("5.Create a password : ");
    fflush(stdin);
    // scanf("%s",s1.pass);
    IPT_PASS(s1.pass);
    HASH_2(s1.pass, strlen(s1.pass));
    pf("the hashed password is %s\n", s1.pass);
    pf("6.Class Name : ");
    fflush(stdin);
    gets(s1.cnm);
    pf("7.Date of Birth(DDMMYYYY) : ");
    scanf("%d", &s1.dob);
    pf("8.Phone mumber : ");
    scanf("%lld", &s1.phno);
    // fpf(ptr,"%d\t%s\t%s\t%d\t",s1.roll,s1.name,s1.cnm,s1.dob);
    pf("9.Marks of 5 subjects : \n");
    for (int i = 0; i < 5; i++)
    {
        pf("Subject[%d] : ", i + 1);
        scanf("%d", &s1.mks[i]);
        sum += s1.mks[i];
        // fpf(ptr,"%d\t",s1.mks[i]);
    }
    s1.avg = sum / 5;
    // fpf(ptr,"%f\n",s1.avg);
    fwrite(&s1, sizeof(s1), 1, ptr);
    fclose(ptr);
    if (f == 1)
    {
        pf("Record added Successfully\n");
    }
    pf("--------------------------------------------");
    pf("Enter a key to continue\n");
    getch();
    return 0;
}
// Function for Reading a Record
void READ_REC()
{
    int c = 0;
    FILE *f1 = fopen("C:\\Users\\univa\\Desktop\\File Handling\\File Handling\\new.txt", "r+");
    cl s;
    if (f1 == NULL)
    {
        pf("Unable to open file\n");
    }
    system("cls");
    // fscanf(f1,"%d %[^\t] %[^\t] %d %d %d %d %f",&s.roll,s.name,s.cnm,&s.dob,&s.mks[0],&s.mks[1],&s.mks[2],&s.avg);

    while (fread(&s, sizeof(s), 1, f1))
    {
        pf("Record : %d\n", ++c);
        pf("----------------------------------------------------------------------------------------------\n");
        pf("Name %18s\t", "");
        pf("Roll No. %20\t");
        pf("E-mail id%12s\t", "");
        pf("Class Name %20\n");
        pf("----------------------------------------------------------------------------------------------\n");
        pf("%18s\t", s.name);
        pf("%d\t", s.roll);
        pf("%25s\t", s.eml);
        pf("%s\n", s.cnm);
    }
    fclose(f1);
    pf("Enter a key to continue\n");
    getch();
}
void REC_SER()
{
    system("cls");
    FILE *ptr = fopen("C:\\Users\\univa\\Desktop\\File Handling\\File Handling\\new.txt", "a+");
    cl s;
    int k, f = 0;
    char pass[50];
    pf("Enter the Roll No. : ");
    scanf("%d", &k);
    while (fread(&s, sizeof(cl), 1, ptr))
    {
        if (s.roll == k)
        {
            pf("Record Present\n");
            f = 1;
            pf("Enter password  : ");
            fflush(stdin);
            IPT_PASS(pass);
            HASH_2(pass, strlen(pass));
            printf("pass is %s", s.pass);
            printf("psss : %s\n", pass);
            for (int i = 0; i < strlen(pass); i++)
            {
                if (pass[i] != s.pass[i])
                {
                    pf("Wrong Password\nExiting...");
                    f = 2;
                    fclose(ptr);
                    exit(0);
                }
            }
            if (f == 1)
            {
                pf("Roll No. : %d\n", s.roll);
                pf("Name : %s\n", s.name);
                pf("E-mail id : %s\n", s.eml);
                pf("Class Name : %s\n", s.cnm);
                pf("Date Of Birth : %d/%d/%d\n", s.dob / 1000000, (s.dob % 1000000) / 10000, s.dob % 10000);
                pf("Phone number : %u \n", s.phno);
                pf("Address : %s \n", s.adrs);
                pf("------------------------------------------------------------------------------------------------------------\n");
                for (int i = 0; i < 5; i++)
                {
                    pf("Marks in Subject[%d] : %d\n", i + 1, s.mks[i]);
                }
                pf("Average : %.2f\n", s.avg);
                fclose(ptr);
                f = 1;
                break;
            }
        }
    }
    if (f == 0)
    {
        pf("Record Absent\n");
        fclose(ptr);
    }
    pf("enter a key to continue \n");
    getch();
    getch();
}
int UPDT()
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
            if (ff == 1)
            {
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
void delete ()
{
    int r;
    cl s;
    int flag = 0;
    // FILE *fp1,*fp2;
    FILE *fp1 = fopen("new.txt", "a+");
    FILE *fp2 = fopen("n1.txt", "a+");
    rewind(fp1);
    pf("Enter the Roll No. to Delete \n");
    scanf("%d", &r);
    while (fread(&s, sizeof(cl), 1, fp1))
    {
        if (r == s.roll)
        {
            flag = 1;
            continue;
        }
        fwrite(&s, sizeof(cl), 1, fp2);
    }
    fclose(fp1);
    fclose(fp2);
    if (flag == 0)
    {
        printf("Record not Present\n");
        remove("n1.txt");
    }
    else
    {
        pf("Record Deleted\n");
        remove("new.txt");
        int v = rename("n1.txt", "new.txt");
        pf("%d is v : \n", v);
    }
}
// }