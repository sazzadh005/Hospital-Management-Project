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

    printf("Admission Date & Time: %d-%d-%d  &  %d:%d:%2d",date,month,year,hour,minute,second);
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
    printf("\n");
    printf("Available in Day Shift (Saturday to Tuesday)");
    printf("Name: Shafiq.\t\t\tName: Aklima.\t\t\tName: Simi\n");
    printf("Designation: Receptionist.\tDesignation: Receptionist.\tDesignation: Receptionist.\n");
    printf("Mob: 01980-634850\t\tMob: 01980-634851\t\tMob: 01980-634852\n\n");
    printf("Available in Day Shift (Wednesday to Friday)");
    printf("Name: Hridoy.\t\t\tName: Chaity.\t\t\tName: Anu\n");
    printf("Designation: Receptionist.\tDesignation: Receptionist.\tDesignation: Receptionist.\n");
    printf("Mob: 01980-634853\t\tMob: 01980-634854\t\tMob: 01980-634855\n");

}

void nurse_database()
{

    printf("\n");

    printf("Available in Day Shift (Saturday to Tuesday). Rest of the day in night shift.\n\n");

    printf("Name: Barsha.\t\t\tName: Labiba.\t\t\tName: Muhaiminul\n");
    printf("Designation: Nurse.\t\tDesignation: Nurse.\t\tDesignation: Nurse.\n");
    printf("Department: Cardiology.\t\tDepartment: Gynecology.\t\tDepartment: Gastroenterology.\n");
    printf("Mob: 01880-634850\t\tMob: 01880-634851\t\tMob: 01880-634852\n\n");

    printf("Name: Nishad.\t\t\tName: Bibha.\t\t\tName: Shamim\n");
    printf("Designation: Nurse.\t\tDesignation: Nurse.\t\tDesignation: Nurse.\n");
    printf("Department: Cardiology.\t\tDepartment: Gynecology.\t\tDepartment: Gastroenterology.\n");
    printf("Mob: 01880-634853\t\tMob: 01880-634854\t\tMob: 01880-634855\n\n");

    printf("Name: Namrata.\t\t\tName: Saliha.\t\t\tName: Tahsin Ahmed\n");
    printf("Designation: Nurse.\t\tDesignation: Nurse.\t\tDesignation: Nurse.\n");
    printf("Department: General Surgery.\tDepartment: General Surgery.\tDepartment: Hematology.\n");
    printf("Mob: 01880-634856\t\tMob: 01880-634857\t\tMob: 01880-634858\n\n");

    printf("Available in Day Shift (Wednesday to Friday). Rest of the day in night shift.\n\n");

    printf("Name: Sadiya.\t\t\tName: Rodela\t\t\tName: Sadia Naznin Nisha.\n");
    printf("Designation: Nurse.\t\tDesignation: Nurse.\t\tDesignation: Nurse.\n");
    printf("Department: Cardiology.\t\tDepartment: Cardiology.\t\tDepartment: Gastroenterology.\n");
    printf("Mob: 01880-634859\t\tMob: 01880-634860\t\tMob: 01880-634861\n\n");

    printf("Name: Rafsan.\t\t\tName: Nawrin\t\t\tName: Jennifer.\n");
    printf("Designation: Nurse.\t\tDesignation: Nurse.\t\tDesignation: Nurse.\n");
    printf("Department: Cardiology.\t\tDepartment: Gynecology.\t\tDepartment: Gastroenterology.\n");
    printf("Mob: 01880-634862\t\tMob: 01880-634863\t\tMob: 01880-634864\n\n");

    printf("Name: Atif.\t\t\tName: Nazia\t\t\tName: Shompa.\n");
    printf("Designation: Nurse.\t\tDesignation: Nurse.\t\tDesignation: Nurse.\n");
    printf("Department: General Surgery.\tDepartment: General Surgery.\tDepartment: Hematology.\n");
    printf("Mob: 01880-634865\t\tMob: 01880-634866\t\tMob: 01880-634867\n\n");
}


void staff_info(char name[],char designation[],char department[],char mob[])
{
    printf("Name: %s\nDesignation: %s\nDepartment: %s\n",name,designation,department);
    printf("Mob: %s\n\n",mob);
}

void staff()
{
    char name[][NAME_LENGHT] ={"Rahima","Uma","Amena","Shilpi","Aman","Sokina","Asma","Bisas","Aklima",
                                "Moon","Mithee","Lisa","Saiful","Rasel","Munira","Rimon","Prihan","Mina"};

    char designation[][DESIGNATION_LENGHT] ={"Cleaner","Cleaner","Cleaner","Cleaner","Cleaner","Cleaner","Cleaner","Cleaner","Cleaner",
                                                "Cleaner","Cleaner","Cleaner", "Cleaner", "Cleaner","Cleaner","Cleaner","Cleaner","Cleaner"};

    char department[][DEPARTMENT_LENGHT] ={"Cardiology","Gynecology","All Dept.","General Surgery","General Surgery","All Dept.",
                                            "All Dept.","Ward & Cabin","Ward & Cabin","Cardiology","Gynecology","All Dept.","General Surgery",
                                            "General Surgery","All Dept.","All Dept.","Ward & Cabin","Ward & Cabin"};

    char mob[][MOBILE_LENGHT] ={"01480-634850","01480-634851","01480-634852","01480-634853","01480-634854","01480-634855",
                                    "01480-634856","01480-634856","01480-634857","01480-634858","01480-634859","01480-634860",
                                    "01480-634861","01480-634862","01480-634863","01480-634864","01480-634865","01480-634866"};

    int staff_cnt = sizeof(name) / sizeof(name[0]);

    printf("\nAvailabe in Day Shift(Saturday to Tuesday). Rest of the Days Evening Shift\n\n");
    for (int i=0; i<staff_cnt/2;i++)
    {
        staff_info(name[i],designation[i],department[i],mob[i]);
    }

    printf("\nAvailabe in Day Shift(Saturday to Tuesday). Rest of the Days Evening Shift\n\n");
    for (int i=staff_cnt/2;i<staff_cnt;i++)
    {
        staff_info(name[i],designation[i],department[i],mob[i]);
    }
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

    staff();

    doctors_info();

    current_dateTime();

    return 0;
}
