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


void searchNurse(const char *department)
{
    FILE *ndata;
    ndata =fopen("doctors_data_base.csv","r");

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


void searchNurse(const char *department)
{
    FILE *ndata;
    ndata =fopen("doctors_data_base.csv","r");

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


void searchSupport_staff(const char *department)
{
    FILE *sdata;
    sdata =fopen("doctors_data_base.csv", "r");
}


void doctors_info()
{
    printf("\nAll Doctor's Information\n\n");
    FILE *data;

    data=fopen("doctors_data_base.csv","r");

    char details[SIZED];

    while(fgets(details,SIZED,data) != NULL)
    {
        printf("%s", details);
    }
    fclose(data);
    printf("\n");
}

void searchDoctor(const char *doctorName)
{
    FILE *data;
    data=fopen("doctors_data_base.csv","r");

    char details[SIZED];
    bool found=false;

    while(fgets(details,SIZED,data) !=NULL)
    {
        char *n=strtok(details, " \n");
        while (n !=NULL)
        {
            if (strcmp(n,doctorName) ==0)
            {
                printf("\nDoctor's Information:\n\n%s", details);
                while(fgets(details,SIZED,data) !=NULL && strcmp(details,"\n") !=0)
                {
                    printf("%s",details);
                }
                found=true;
                break;
            }
            n=strtok(NULL," \n");
        }
        if(found)
        {
            break;
        }
    }

    if(!found)
    {
        printf("\nDoctor with name '%s' not found.\n",doctorName);
        printf("Please search again with correct name.\n");
    }

    fclose(data);
}


void addDoctor()
{
    char username[USERNAME_LENGHT], password[PASSWORD_LENGHT];

    printf("\nTo add a new Doctor varify your login.\n");
    input_login(username,password);

    if (isAdmin(username, password)) {
        if ((strcmp(username, "ADMIN") == 0 || strcmp(username, "admin") == 0) &&
            (strcmp(password, "ADMINISTRATOR") == 0 || strcmp(password, "administrator") == 0))
        {

            char name[NAME_LENGHT], designation[ALL_LENGHT];
            char department[ALL_LENGHT], qualification[ALL_LENGHT], speciality[ALL_LENGHT], chamberFloor[ALL_LENGHT];
            char chamberRoom[ALL_LENGHT], chamberTime[ALL_LENGHT], offDay[ALL_LENGHT], contact[ALL_LENGHT];

            printf("Enter name: ");
            scanf("%s", name);

            printf("Enter designation: ");
            scanf("%s", designation);

            printf("Enter department: ");
            scanf("%s", department);

            printf("Enter qualification: ");
            scanf("%s", qualification);

            printf("Enter speciality: ");
            scanf("%s", speciality);

            printf("Enter chamber floor: ");
            scanf("%s", chamberFloor);

            printf("Enter chamber room: ");
            scanf("%s", chamberRoom);

            printf("Enter chamber time: ");
            scanf("%s", chamberTime);

            printf("Enter off day: ");
            scanf("%s", offDay);

            printf("Enter contact: ");
            scanf("%s", contact);

            FILE *data;
            data = fopen("doctors_data_base.csv", "a");

            fprintf(data, "\nName: %s\nDesignation: %s\nDepartment: %s\nQualification: %s\nSpeciality: %s\nChamber Floor: %s\nChamber Room: %s\nChamber Time: %s\nOff Day: %s\nContact: %s\n", name, designation, department, qualification, speciality, chamberFloor, chamberRoom, chamberTime, offDay, contact);

            fclose(data);
            printf("Doctor '%s' added successfully.\n", name);
        }
        else
        {
            printf("Only admin can add a doctor. Contact the admin.\n");
        }
    }
}



void deleteDoctor()
{
    char username[USERNAME_LENGHT], password[PASSWORD_LENGHT];

    printf("\nTo delete a Doctor, verify your login.\n");
    input_login(username, password);

    if (isAdmin(username, password)) {
        char doctorName[NAME_LENGHT];
        printf("Enter the Full Name of the doctor to be deleted: ");
        scanf("%s", doctorName);

        FILE* data = fopen("doctors_data_base.csv", "r");
        if (data == NULL) {
            printf("No File Found Here.\n");
            return;
        }

        FILE* tempData = fopen("temp_data.csv", "w");
        if (tempData == NULL) {
            printf("No New File Found Here.\n");
            fclose(data);
            return;
        }

        char line[SIZED];
        bool found = false;
        bool deleteMode = false;

        while (fgets(line, SIZED, data) != NULL)
        {
            if (strstr(line, doctorName) != NULL)
            {
                found = true;
                deleteMode = true;
            }

            if (!deleteMode || (deleteMode && line[0]=='\n'))
            {
                fprintf(tempData, "%s", line);
                deleteMode = false;
            }
        }



        fclose(data);
        fclose(tempData);

        remove("doctors_data_base.csv");
        rename("temp_data.csv", "doctors_data_base.csv");

        if (found)
        {
            printf("Doctor '%s' deleted successfully.\n", doctorName);
        } else
        {
            printf("Doctor '%s' not found.\n", doctorName);
        }
    }
    else
    {
        printf("Only admin can delete a doctor. Contact with admin.\n");
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

    current_dateTime();

    return 0;
}
