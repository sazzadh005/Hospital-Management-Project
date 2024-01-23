#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <time.h>
#include <string.h>

#define USERNAME_LENGHT 100
#define PASSWORD_LENGHT 100
#define SIZED 200
#define NAME_LENGHT 50
#define DESIGNATION_LENGHT 30
#define DEPARTMENT_LENGHT 50
#define MOBILE_LENGHT 15
#define ALL_LENGHT 100


void current_dateTime()
{
    time_t t;
    time(&t);

    struct tm*timeinfo=localtime(&t);
    struct tm local_time= *timeinfo;

    int date=local_time.tm_mday;
    int month=local_time.tm_mon+1;
    int year=local_time.tm_year+1900;
    int hour=local_time.tm_hour;
    int minute=local_time.tm_min;
    int second=local_time.tm_sec;

    printf("Admission Date & Time: %.2d-%.2d-%d  &  %.2d:%.2d:%.2d",date,month,year,hour,minute,second);
}

int administrator(char user[],char pass[])
{
    char set_user[][USERNAME_LENGHT]={"COMMON_USER","common_user","RECEPTION","reception","ADMIN","admin"};
    char set_pass[][PASSWORD_LENGHT]={"LOGIN","login","COMMON_USER","common_user","ADMINISTRATOR","administrator"};
    int size= sizeof(set_user)/sizeof(set_user[0]);

    for(int i=0; i<size;i++)
    {
        int user_match=1;                           //to compare is the username matched or not
        for(int j=0; set_user[i][j]!='\0';j++)
        {
            if(set_user[i][j]!=user[j])
            {
                user_match=0;                       //if user doesn't match value will be 0 and break will be executed
                break;
            }
        }

        int pass_match=1;                           //to compare is the password matched or not
        for(int k=0;set_pass[i][k]!='\0';k++)
        {
            if(set_pass[i][k]!=pass[k])
            {
                pass_match=0;                       //if password doesn't match value will be 0 and break will be executed
                break;
            }
        }
        if(user_match && pass_match)                //if user and password both matched then function will return value 1
        {
            return 1;
        }
    }
    return 0;

}

void input_login(char username[],char password[])
{
    printf("Enter Username: ");
    scanf("%s",username);
    printf("Enter Password: ");
    scanf("%s",password);
}


void login_pannel(char username[],char password[])
{
    bool login=false;
    while(!login)
    {
        input_login(username,password);
        login=administrator(username,password);
        if(login)
        {
            printf("Login Successful. Welcome to Hospital Management System,You are loggedIn as %s\n",username);
        }
        else
        {
            printf("Login Failed. Bad Password or Username. Try again or contact admin.\n");
        }
    }
}

//All staff database

void receptionist_database()
{
    printf("All Receptionist Information.\n\n");
    FILE *rdata;

    rdata=fopen("receptionist_database.csv","r");

    char rdetails[SIZED];

    while(fgets(rdetails,SIZED,rdata) !=NULL)
    {
        printf("%s",rdetails);
    }
}

void nurse_database()
{
    printf("All Nurse's Information.\n\n");
    FILE *fdata;

    fdata=fopen("nurses_database.csv","r");

    char fdetails[SIZED];

    while(fgets(fdetails,SIZED,fdata) !=NULL)
    {
        printf("%s",fdetails);
    }
    fclose(fdata);
    printf("\n");
}


void staff()
{
    printf("All Support Staff's Information\n\n");
    FILE *ndata;

    ndata=fopen("support_staff_database.csv","r");

    char ndetails[SIZED];

    while(fgets(ndetails,SIZED,ndata) !=NULL)
    {
        printf("%s",ndetails);
    }
    fclose(ndata);
    printf("\n");
}


void doctors_info()
{
    printf("All Doctor's Information\n\n");
    FILE *data;

    data=fopen("doctors_data_base.csv","r");

    char details[SIZED];

    while (fgets(details, SIZED, data) != NULL) {
        printf("%s", details);
    }
    fclose(data);
}


void searchDoctor(char* doctorName)
{
    FILE* data;
    data = fopen("doctors_data_base.csv", "r");

    char details[SIZED];
    bool found = false;

    while (fgets(details, SIZED, data) != NULL)
    {
        if (strstr(details, doctorName) != NULL)
        {
            printf("Doctor's Information:\n%s", details);
        }
}


void patient_information()
{
 char name[NAME_LENGHT];
 char gurdian_name[NAME_LENGHT];
 char gurdian_relation[NAME_LENGHT];
 int age;
 int mobile;
 char blood_grp[10];


}

int main()
{
    char username[USERNAME_LENGHT];
    char password[PASSWORD_LENGHT];

    login_pannel(username,password);

    receptionist_database();
    nurse_database();
    current_dateTime();

    return 0;
}
