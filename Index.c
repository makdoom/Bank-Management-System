#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<string.h>

//All Functions Declarations
void menu(void);
void new_acc(void);
void update(void);
void erase(void);
void view_list(void);
void info_user(void);
int concat(int, int);
void delay(int);

//Global Variable Declarations
int i,j,main_exit;

//Structures
struct date
{
    int d,m,y;
}d1;
struct
{
    char name[15];
    int age,acc_no;
    char city[10],state[15],acc_type[8];
    struct date dob;
    double phone_no;
    float amt;
}info,upd,check,transac,rem;

//Functions Definations
int concat(int a, int b)
{

    char s1[5];
    char s2[5];
        // Convert both the integers to string
    sprintf(s1, "%d", a);
    sprintf(s2, "%d", b);

    // Concatenate both strings
    strcat(s1, s2);

    // Convert the concatenated string
    // to integer
    int c = atoi(s1);

    // return the formed integer
    return c;
}
//This Function will pause the program execution for a particular time
void delay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
//This functions will printf the information of user on the screen
void info_user()
{
    FILE *fp;
    int test=0,choice;
    fp = fopen("records.txt","r");
    if(fp==NULL)
    {
        printf("\n\n\t\tFILE NOT FOUND !!");
    }
    system("cls");
    system("color F");
    printf("\n\n\t\t\t\tEnter The Account Number: ");
    scanf("%d",&check.acc_no);
    system("cls");
    while(fscanf(fp," %d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f ",&info.acc_no,&d1.d,&d1.m,&d1.y,&info.name,&info.age,&info.dob.d,&info.dob.m,&info.dob.y,&info.city,&info.state,&info.acc_type,&info.phone_no,&info.amt)!= EOF)
    {
            if(check.acc_no == info.acc_no)
            {
                 test = 1;
                 printf("\t\t\t\t***** ACCOUNT INFORMATION *****\n\n");
                 printf("\n\tDate Of Joining:%d/%d/%d\n\tName:%s\n\tAccount No:%d\n\tAccount Type:%s\n\tAge:%d\n\tDate Of Birth:%d/%d/%d\n\tCity:%s\n\tState:%s\n\tPhone No:%0.lf\n\tBalance:Rs.%.2f\n",d1.d,d1.m,d1.y,info.name,info.acc_no,info.acc_type,info.age,info.dob.d,info.dob.m,info.dob.y,info.city,info.state,info.phone_no,info.amt);
            }
    }
    fclose(fp);
    if(test == 1)
    {
        up:
        printf("\n\n\t\t\t\t\tEnter 1 To Go To Main Menu And 0 To Exit: ");
        scanf("%d",&main_exit);
        if(main_exit==1)
            menu();
        else if(main_exit==0)
            close();
        else
            {printf("\n\n\t\t\t\tInvalid Entry !!!");
            goto up;}

    }
    else
    {
        system("cls");
        printf("\n\n\t\t\t\tNO RECORD FOUND !!");
        back:
        printf("\n\n\t\t\tEnter 1 To Try Again, 2 To Go To The Main Menu And 0 To Exit: ");
        scanf("%d",&choice);
        if(choice==1)
            info_user();
        else if(choice == 2)
            menu();
        else if(choice == 0)
            close();
        else
            {printf("\n\n\t\t\t\t\tInvalid Entry !!");
            delay(100000000);
            goto back;}
    }

}
//This function will Delete the information of particular user
void erase()
{
    FILE *old, *newrec;
    int choice,test=0;
    old=fopen("records.txt","r");
    newrec=fopen("new.txt","w");
    system("cls");
    system("color f");
    printf("\n\n\t\t\tEnter Account no. Of Customer You Want To Remove: ");
    scanf("%d",&rem.acc_no);
    while(fscanf(old," %d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f ",&info.acc_no,&d1.d,&d1.m,&d1.y,&info.name,&info.age,&info.dob.d,&info.dob.m,&info.dob.y,&info.city,&info.state,&info.acc_type,&info.phone_no,&info.amt)!= EOF)
    {
        if(info.acc_no != rem.acc_no)
        {
            fprintf(newrec," %d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f\n",info.acc_no,d1.d,d1.m,d1.y,info.name,info.age,info.dob.d,info.dob.m,info.dob.y,info.city,info.state,info.acc_type,info.phone_no,info.amt);
        }
        else{
            test++;
            system("cls");
            printf("\n\n\t\t\t\tRECORD DELETED SUCCESSFULLY !!");
        }

    }
    fclose(old);
    fclose(newrec);
    remove("records.txt");
    rename("new.txt","records.txt");
    if(test==0)
    {
        system("cls");
        printf("\n\n\t\t\t\t\tNO RECORD FOUND !!");
        invalid:
        printf("\n\n\t\t\tEnter 1 To Try Again, 2 To Go To Main Menu And 0 To Exit: ");
        scanf("%d",&main_exit);
        if(main_exit==1)
            erase();
        else if(main_exit==2)
            menu();
        else if(main_exit==0)
            close();
        else
            {
                printf("\n\n\t\t\t\tInavlid Entry !!");
                goto invalid;
            }
    }
    else
    {
        back:
        printf("\n\n\t\t\tEnter 1 To Go To Main Menu and 0 To Exit :");
        scanf("%d",&main_exit);
        if(main_exit==1)
        {
            menu();
        }
        else if(main_exit==0)
        {
            close();
        }
        else
            printf("\n\n\t\t\t\tInvalid Entry!! ");
            goto back;

    }

}

void trans()
{
    FILE *old,*newrec;
    int choice,test=0;
    old = fopen("records.txt","r");
    newrec = fopen("new.txt","w");
    system("cls");
    system("color a");
    printf("\n\t\t\t\t\t******** TRANSACTIONS ********\n\n");
    printf("\n\n\t\t\t\tEnter The Account no. Of The Customer: ");
    scanf("%d",&transac.acc_no);
    while(fscanf(old," %d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f ",&info.acc_no,&d1.d,&d1.m,&d1.y,&info.name,&info.age,&info.dob.d,&info.dob.m,&info.dob.y,&info.city,&info.state,&info.acc_type,&info.phone_no,&info.amt)!= EOF)
    {
        if(info.acc_no == transac.acc_no)
        {
            test =1;
            system("cls");
            printf("\n\n\t\t\t\tDo You Want To ? \n\n\t\t\t1.Deposite \n\t\t\t2.Withdraw\n\n\t\t\tEnter Your Choice: ");
            scanf("%d",&choice);
            if(choice == 1)
            {
                system("cls");
                printf("\n\n\t\t\t\tEnter The Amount You Want To Deposite(Rs.): ");
                scanf("%f",&transac.amt);
                info.amt+=transac.amt;
                fprintf(newrec,"%d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f\n ",info.acc_no,d1.d,d1.m,d1.y,info.name,info.age,info.dob.d,info.dob.m,info.dob.y,info.city,info.state,info.acc_type,info.phone_no,info.amt);
                system("cls");
                printf("\n\n\t\t\t\tYour Amount Deposited Successfully !!");
                printf("\n\n\t\t\t\t\t\tCurrent Balance:  Rs.%.2f/-",info.amt);
            }
            else if(choice==2)
                    {
                        system("cls");
                        printf("\n\n\t\t\t\tEnter The Amount You Want To Withdraw(Rs.): ");
                        scanf("%f",&transac.amt);
//                        if(info.amt < transac.amt)
//                           {    printf("\n\n\t\t\a\a\aInsufficient Balance!!!:");
//                                goto go_back;}
                        info.amt-=transac.amt;
                        fprintf(newrec,"%d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f\n ",info.acc_no,d1.d,d1.m,d1.y,info.name,info.age,info.dob.d,info.dob.m,info.dob.y,info.city,info.state,info.acc_type,info.phone_no,info.amt);
                        system("cls");
                        printf("\n\n\t\t\t\tWithdrawn Successfully !!");
                        printf("\n\n\t\t\t\t\tCurrent Balance:  Rs.%.2f/-",info.amt);
                    }
        }
        else
            fprintf(newrec,"%d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f\n ",info.acc_no,d1.d,d1.m,d1.y,info.name,info.age,info.dob.d,info.dob.m,info.dob.y,info.city,info.state,info.acc_type,info.phone_no,info.amt);

    }
    fclose(old);
    fclose(newrec);
    remove("records.txt");
    rename("new.txt","records.txt");
    if(test!=1)
    {
        printf("\n\n\t\t\t\tNO RECORD FOUND!!!!");
        invalid_transaction:
        printf("\n\n\t\t\t\tEnter 1 To Try Again, 2 To Return To Main Menu And 0 to Exit:");
        scanf("%d",&main_exit);
        if(main_exit==1)
            trans();
        else if(main_exit==2)
            menu();
        else if (main_exit==0)
            close();
        else
        {
            printf("\n\n\t\t\tInvalid Entry!!!!");
            goto invalid_transaction;
        }
    }
    else
   {
       printf("\n\n\t\t\t\tEnter 1 to go to the main menu and 0 to exit:");
        scanf("%d",&main_exit);
        if (main_exit==1)
            menu();
        else
            close();
   }

}
void close()
{
    printf("\n\t\t\tTHIS C PROJECT (BANK MANAGEMENT SYSTEM) IS DEVELOPED BY MAKDOOM SHAIKH !!\n");
    exit(1);
}
void update()
{
    FILE *old, *newrec;
    int choice,test = 0;
    old =fopen("records.txt","r");
    newrec = fopen("newrecords.txt","w");
    system("cls");
    system("color D");
    printf("\n\t\t\t\t\t******** UPDATE INFORMATION ********\n\n");
    printf("\n\n\t\t\t\tEnter The Account.no Whose Information You Want To Change:");
    scanf("%d",&upd.acc_no);
    while(fscanf(old," %d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f ",&info.acc_no,&d1.d,&d1.m,&d1.y,&info.name,&info.age,&info.dob.d,&info.dob.m,&info.dob.y,&info.city,&info.state,&info.acc_type,&info.phone_no,&info.amt)!= EOF)
    {
        if(info.acc_no == upd.acc_no)
        {
            system("cls");

            printf("\n\n\t\t\t\tWhich Information Do You Want To Change ?");
            printf("\n\n\t\t\t1.Name");
            printf("\n\n\t\t\t2.Address");
            printf("\n\n\t\t\t3.Phone Number");
            printf("\n\n\t\t\t\t\tEnter Your Choice: ");
            scanf("%d",&choice);
            if(choice==1)
            {
                test=1;
                printf("\n\n\t\t\tEnter New Name: ");
                scanf("%s",&upd.name);
                fprintf(newrec,"%d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f\n ",info.acc_no,d1.d,d1.m,d1.y,upd.name,info.age,info.dob.d,info.dob.m,info.dob.y,info.city,info.state,info.acc_type,info.phone_no,info.amt);
                system("cls");
                printf("\n\n\t\t\t\t\tCHANGES SAVED !!!!!\n");

            }
            else if(choice == 2)
                {
                    test=1;
                    printf("\n\n\t\t\tEnter City Name : ");
                    scanf("%s",&upd.city);
                    fprintf(newrec," %d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f\n ",info.acc_no,d1.d,d1.m,d1.y,info.name,info.age,info.dob.d,info.dob.m,info.dob.y,upd.city,info.state,info.acc_type,info.phone_no,info.amt);
                    system("cls");
                    printf("\n\n\t\t\t\t\t\tCHANGES SAVED !!!!!\n");

                }
               else if(choice == 3)
               {
                    test=1;
                    printf("\n\n\t\t\tEnter City Name : ");
                    scanf("%lf",&upd.phone_no);
                    fprintf(newrec," %d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f\n ",info.acc_no,d1.d,d1.m,d1.y,info.name,info.age,info.dob.d,info.dob.m,info.dob.y,upd.city,info.state,info.acc_type,upd.phone_no,info.amt);
                    system("cls");
                    printf("\n\n\t\t\t\t\t\tCHANGES SAVED !!!!!\n");
               }
        }
        else
            fprintf(newrec,"%d %d/%d/%d %s %d %d/%d/%d %s %s %s %.0lf %f\n",info.acc_no,d1.d,d1.m,d1.y,info.name,info.age,info.dob.d,info.dob.m,info.dob.y,info.city,info.state,info.acc_type,info.phone_no,info.amt);
    }
    fclose(old);
    fclose(newrec);
    remove("records.txt");
    rename("newrecords.txt","records.txt");
        if(test!=1)
        {
            printf("\n\n\t\t\t\tNO RECORD FOUND !!");
            BACK:
             printf("\n\n\t\tEnter 1 To Try Again, 2 To Go To Main Menu And 0 To Exit: ");
            scanf("%d",&main_exit);
            if(main_exit==1)
                update();
            else if(main_exit==2)
                {
                    menu();
                }
            else if(main_exit==0)
                close();
            else
                {
                    printf("\n\t\t\tInvalid Entry!!!!");
                    goto BACK;
                }
        }
        else
        {

            back:
           printf("\n\n\t\t\t\t\tEnter 1 To Go To Main Menu And 0 To Exit:");
            scanf("%d",&main_exit);
            if(main_exit==1)
                menu();
            else if(main_exit==0)
                close();
            else
                {printf("\n\n\t\t\t\tInvalid Entry !!");
                 system("cls");
                 goto back;
                }


        }
}
void new_acc()
{
    FILE *fp;
    int choice;
    system("cls");
    system("color b");
    fp = fopen("records.txt","a+");
    if(fp==NULL)
    {
        printf("\n\t\t\tFile Not Found !!!");
    }
    printf("\n\t\t\t\t******** NEW ACCOUNT CREATION********\n\n");
    DATE:
    printf("\n\t\t\tEnter Todays date: ");
    scanf("%d/%d/%d",&d1.d,&d1.m,&d1.y);
    if(d1.d>31 || d1.m>12){
        printf("\n\t\t\t\a\a\aPlease Enter a Valid Date!! \n!!");
        goto DATE;
    }
    printf("\n\t\t\tEnter Your Name: ");
    fflush(stdin);
    gets(info.name);
    printf("\n\t\t\tEnter Your Age: ");
    scanf("%d",&info.age);
    DOB:
    printf("\n\t\t\tEnter Your Date Of Birth:");
    scanf("%d/%d/%d",&info.dob.d,&info.dob.m,&info.dob.y);
    if(info.dob.d>31 || info.dob.m>12)
    {
        printf("\n\n\a\a\a\t\t\tPlease Enter a Valid DOB!!!\n");
        goto DOB;
    }
    info.acc_no = concat(info.dob.y, info.dob.m);
    fflush(stdin);
    printf("\n\t\t\tEnter City:");
    gets(info.city);
    printf("\n\t\t\tEnter State:");
    fflush(stdin);
    gets(info.state);
    printf("\n\t\t\tAccount Type: \n\t\t\t#.Saving Account(SB)\t\t#.Current Account(CA)\n\n\t\t\t");
    fflush(stdin);
    gets(info.acc_type);
    printf("\n\t\t\tEnter Your Phone Number: ");
    scanf("%lf",&info.phone_no);
    printf("\n\t\t\tEnter The Amount to Deposite :Rs.");
    scanf("%f",&info.amt);

//account no. date name age dob city state citizenship phone amount
    fprintf(fp," %d %d/%d/%d %s %d %d/%d/%d %s %s %s %.0lf %f\n",info.acc_no,d1.d,d1.m,d1.y,info.name,info.age,info.dob.d,info.dob.m,info.dob.y,info.city,info.state,info.acc_type,info.phone_no,info.amt);
    fclose(fp);
    printf("\n\n\t\t\t\tYOUR ACCOUNT CREATED SUCESSFULLY !!!!");
    printf("\n\n\t\t\t\tYOUR ACCOUNT NUMBER IS: %d",info.acc_no);
    go_back:
    printf("\n\n\n\t\t\tEnter 1 to go to the main menu and 0 to exit: ");
    scanf("%d",&choice);
    if(choice==0)
        close();

    else{
        if(choice == 1)
            menu();

        else
            {
                printf("\n\t\t\t\t\a\a\aInvalid Entry");
                goto go_back;
            }
        }
}
void view_list()
{
    FILE *view;
    int test = 0;
    system("color F");
    view=fopen("records.txt","r");
    system("cls");
    printf("\n\t\t\t\t******** LIST OF ACCOUNTS ********\n\n");
    printf("\nAccount.no.\tAccount Type\tDate\t\tName\t\t\tAge\t\tDOB\t\tPhone no.\t\tBalance\n");
    while(fscanf(view," %d %d/%d/%d %s %d %d/%d/%d %s %s %s %lf %f",&info.acc_no,&d1.d,&d1.m,&d1.y,&info.name,&info.age,&info.dob.d,&info.dob.m,&info.dob.y,&info.city,&info.state,info.acc_type,&info.phone_no,&info.amt)!= EOF)
        {
            printf("%d\t\t%s\t\t%d/%d/%d\t%s\t\t\t%d\t\t%d/%d/%d\t%.0lf\t\tRs.%.2f\n",info.acc_no,info.acc_type,d1.d,d1.m,d1.y,info.name,info.age,info.dob.d,info.dob.m,info.dob.y,info.phone_no,info.amt);
            test++;
        }
        fclose(view);
        if(test==0)
        {

            printf("\n\n\t\t\t\t\t\a\aNO RECORD FOUND !!");
        }
            go_back:
            printf("\n\n\t\t\tEnter 1 to go to main menu and 0 to exit: ");
            scanf("%d",&main_exit);
            if(main_exit==1)
                menu();
            else if (main_exit==0)
                    close();
                else
                    printf("\n\t\t\tInvalid Entry!!!!");
                    goto go_back;



}
void menu()
{
    int choice;
    int def;
    system("cls");
    system("color e");
    printf("\n\t\t\t\tCUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM\n\n");
    printf("\t\t\t\t***** WELCOME TO THE MAIN MENU *****\n\n");
    printf("\n\t\t\t1.Create New Account");
    printf("\n\t\t\t2.Update Information Of Existing Account");
    printf("\n\t\t\t3.For Transactions");
    printf("\n\t\t\t4.Check The Detail Of Existing Account");
    printf("\n\t\t\t5.Removing Existing Account");
    printf("\n\t\t\t6.View Customer's List");
    printf("\n\t\t\t7.Exit");
    printf("\n\n\n\t\tEnter Your Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        new_acc();
        break;
    case 2:
        update();
        break;
    case 3:
        trans();
        break;
    case 4:
        info_user();
        break;
    case 5:
        erase();
        break;
    case 6:
        view_list();
        break;
    case 7:
        close();
        break;
    default:
        printf("\n\t\t\tInvalid Entry");
        printf("\n\t\t\tEnter 1 to try again and 0 to exit: ");
        scanf("%d",&def);
        if(def==1){
            system("cls");
            menu();}
        else
            close();

    }
}

void main()
{
    system("color F");
    char pass[10],password[10]="makdoom";
  //  printf("\n\t\t\t\t********BANK MANAGEMENT SYSTEM ********\n\n");

    printf("\n\n\t\t\t\tEnter a password to login:");
    scanf("%s",pass);
    if(strcmp(pass,password)==0)
    {
        printf("\n\t\t\t\t\tPassword Match !!\n\n\t\t\t\tLOADING");
        for(i=0;i<6;i++)
        {
            delay(100000000);
            printf(".");
        }
        menu();
    }
    else
    {
        printf("\n\t\t\t\t\tWrong Password !!\a\a\a\n");
        go_back:
        printf("\n\n\t\t\t\tEnter 1 to try again and 0 to exit:");
        scanf("%d",&main_exit);
        if(main_exit==1){
            system("cls");
            main();}
        else if(main_exit==0)
        {
            close();
        }
        else
           {
             printf("\n\n\t\t\t\tInvalid Entry !!");
             goto go_back;
           }
    }
    getch();
}
