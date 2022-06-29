#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>



void printHighlighted(char*str)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    ///* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    SetConsoleTextAttribute(hConsole, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | BACKGROUND_INTENSITY);
    \
    printf("%s", str);
    consoleInfo.wAttributes = saved_attributes;
    SetConsoleTextAttribute(hConsole, 0 | FOREGROUND_INTENSITY);
}

void arrow(int cur, int next,char arr[])
{

    if (cur == next)
    {
        printHighlighted(arr);
    }
    else
    {
        printf(arr);
    }
}
struct emp
{
    char name[20];
    int salary;
};

void menu(struct emp p[])
{
    int choice = 0,index=0;
    int n=0;
    while(1)
    {
        int pos =1,press=0;

        while(press!=13)
        {

            char arr[5][100]= {"Add new Employee","Add Employee by Index","Display Employee by index","Display All Employees","Exit"};

            if(choice != 3 && choice != 4)
            {
                system("cls");
            }
            else
            {
                printf("\n\n\n");
            }

            arrow(1,pos,arr);
            printf("\n");
            arrow(2,pos,arr+1);
            printf("\n");
            arrow(3,pos,arr+2);
            printf("\n");
            arrow(4,pos,arr+3);
            printf("\n");
            arrow(5,pos,arr+4);
            printf("\n");
            press= getch();

            if(press == 80 && pos != 5)
            {
                pos++;
            }
            else if (press == 72 && pos != 1)
            {
                pos--;
            }
            else if (press == 75 )
            {
                pos=4;
            }
            else if (press == 47 )
            {
                pos=1;
            }
            else
            {
                pos = pos;
            }
        }

        switch(pos)
        {
        case(1):
            choice = 1;
            printf("Enter Emp Name: ");
            scanf("%s",&p[n].name);
            printf("Enter Emp Salary: ");
            scanf("%d",&p[n].salary);
            n++;
            break;
        case(2):
            choice = 2;
            printf("Enter Index\n");
            scanf("%d",&index);

            if(n==0)
            {
                printf("No Emp so will add name at start: ");
                scanf("%s",&p[0].name);
                printf("No Emp so will add salary at start: ");
                scanf("%d",&p[0].salary);
            }
            else
            {

                if (index <=n)
                {
                    printf("will add at the location \n");

                    printf("Enter Emp Name: ");
                    scanf("%s",&p[index].name);
                    printf("Enter Emp Salary: ");
                    scanf("%d",&p[index].salary);
                    n--;
                }
                else if (index >= n )
                {
                    printf("index out of range will add at last spot \n");

                    printf("Enter Emp Name: ");
                    scanf("%s",&p[n].name);
                    printf("Enter Emp Salary: ");
                    scanf("%d",&p[n].salary);

                }
                else if (index ==0 && n ==0)
                {
                    printf("Array empty will add at the start \n");
                    printf("Enter Emp Name: ");
                    scanf("%s",&p[index].name);
                    printf("Enter Emp Salary: ");
                    scanf("%d",&p[index].salary);
                }


            }
            n++;
            break;
        case(3):
            choice = 3;
            printf("Enter Index\n");
            scanf("%d",&index);
            if (index > n )
            {
                printf("no emp with that index\n");
            }
            else
            {
                printf("Name: %s\n",&p[index].name);
                printf("Salary: %d\n",p[index].salary);

            }
            break;
        case(4):
            choice = 4;
            if(n==0)
            {
                printf("No Emp\n");
            }
            else
            {
                for(int i =0 ; i <= n-1; i++)
                {
                    printf("Name: %s\n",&p[i].name);
                    printf("Salary: %d\n",p[i].salary);
                }
            }

            break;
        case(5):
            choice = 5;
            return;
            break;
        }
    }
}


int main()
{
    struct emp p[100];
    struct emp* ptr=&p;
    strcpy(p[0].name,"khaled");
    p[0].salary=100000;

    menu(&p);

}
