#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "RECLIB.H"
// #include "PASS_HASH.H"
#define pf printf
#define fpf fprintf
#define ll long long
int main()
{
    unsigned int ch;
    while (1)
    {
        system("cls");
        pf("Enter Your Choice User \n");
        pf("1. Add a Record\n");
        pf("2. List the Records\n");
        pf("3. Search a Record\n");
        pf("4. Modify a Record\n");
        pf("5. Delete a Record\n");
        pf("6. Exit \n");
        // fflush(stdin);
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            REC_ADD();
            break;
        }
        case 2:
        {
            pf("Processing Student Record List\n");
            READ_REC();
            break;
        }
        case 3:
        {
            REC_SER();
            break;
        }
        case 4:
        {
            UPDT();
            break;
        }
        case 5:
        {
            delete ();
            break;
        }
        case 6:
        {
            exit(0); // termination of program - normally
        }
        default:
        {
            pf("Invalid Choice\n");
            // fflush(stdin);
            abort(); // causes an abnormal termination
            break;
        }
        }
    }
    getch();
}