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


void current_dateTime();
int administrator(char user[],char pass[]);
void input_login(char username[],char password[]);
void login_pannel(char username[],char password[]);
void receptionist_database();
void searchReceptionist(const char *receptionistName);
void nurse_database();
void searchNurse(const char *department);
void support_staff();
void searchSupport_staff(const char *department);
void doctors_info();
void searchDoctor(const char *doctorName);
void addDoctor();
void deleteDoctor();
void admitPatient();
void viewPatients();
bool isAdmin(char *user, char *pass);


int administrator(char user[],char pass[])
{
    char set_user[][USERNAME_LENGHT]={"COMMON_USER","common_user","RECEPTION","reception","ADMIN","admin"};
    char set_pass[][PASSWORD_LENGHT]={"LOGIN","login","COMMON_USER","common_user","ADMINISTRATOR","administrator"};
    int size= sizeof(set_user)/sizeof(set_user[0]);

    int i,j,k;
    for(i=0;i<size;i++)
    {
        int user_match=1;                           //to compare is the username matched or not
        for(j=0;set_user[i][j]!='\0';j++)
        {
            if(set_user[i][j]!=user[j])
            {
                user_match=0;                       //if user doesn't match value will be 0 and break will be executed
                break;
            }
        }

        int pass_match=1;                           //to compare is the password matched or not
        for(k=0;set_pass[i][k]!='\0';k++)
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
    printf("\nAll Receptionist Information.\n\n");
    FILE *rdata;

    rdata=fopen("receptionist_database.csv","r");

    char rdetails[SIZED];

    while(fgets(rdetails,SIZED,rdata) !=NULL)
    {
        printf("%s",rdetails);
    }
}


void searchReceptionist(const char *receptionistName)
{
    FILE *rdata;
    rdata=fopen("receptionist_database.csv","r");

    char details[SIZED];
    bool found=false;

    while(fgets(details,SIZED,rdata) !=NULL)
    {
        char *n=strtok(details," \n");
        while(n !=NULL)
        {
            if(strcmp(n,receptionistName)==0)
            {
                printf("\nReceptionist's Information:\n\n%s",details);
                printf("%s\n",n);
                while (fgets(details,SIZED,rdata) !=NULL && strcmp(details,"\n") !=0)
                {
                    printf("%s",details);
                }
                found =true;
                break;
            }
            n = strtok(NULL," \n");
        }
        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        printf("\nReceptionist with name '%s' not found.\n", receptionistName);
        printf("Please search again with the correct name.\n");
    }

    fclose(rdata);
}


void nurse_database()
{
    printf("\nAll Nurse's Information.\n\n");
    FILE *ndata;

    ndata=fopen("nurses_database.csv","r");

    char fdetails[SIZED];

    while(fgets(fdetails,SIZED,ndata) !=NULL)
    {
        printf("%s",fdetails);
    }
    fclose(ndata);
    printf("\n");
}


void searchNurse(const char *department)
{
    FILE *ndata;
    ndata =fopen("nurses_database.csv","r");

    char ndetails[SIZED];
    bool found =false;

    while(fgets(ndetails,SIZED,ndata) !=NULL)
    {
        if(strstr(ndetails, department) !=NULL)
        {
            printf("\nNurse's Information:\n\n%s",ndetails);
            found = true;
        }
    }

    if(!found)
    {
        printf("\nNurse in department '%s' not found.\n",department);
        printf("Please search again.\n");
    }

    fclose(ndata);
}


void support_staff()
{
    printf("\nAll Support Staff's Information\n\n");
    FILE *sdata;

    sdata=fopen("support_staff_database.csv","r");

    char sdetails[SIZED];

    while(fgets(sdetails,SIZED,sdata) !=NULL)
    {
        printf("%s",sdetails);
    }
    fclose(sdata);
    printf("\n");
}

//need to be updated
void searchSupport_staff(const char *department)
{
    FILE *sdata;
    sdata = fopen("support_staff_database.csv","r");

    char name[NAME_LENGHT],designation[DESIGNATION_LENGHT],contact[MOBILE_LENGHT],availableTime[ALL_LENGHT],offDay[ALL_LENGHT];
    bool found =false;

    while (fscanf(sdata, "Name: %[^\n]\nDesignation: %[^\n]\nDepartment: %[^\n]\nContact: %[^\n]\nAvailable Time: %[^\n]\nOff Day: %[^\n]\n",
                  name, designation, department, contact, availableTime, offDay) ==6)
    {
        printf("\nSupport Staff's Information of '%s':\n\n",department);
        printf("Name: %s\n",name);
        printf("Designation: %s\n",designation);
        printf("Department: %s\n",department);
        printf("Contact: %s\n",contact);
        printf("Available Time: %s\n",availableTime);
        printf("Off Day: %s\n",offDay);
        found =true;
    }

    if (!found)
    {
        printf("\nSupport Staff in department '%s' not found.\nPlease search again.\n", department);
    }

    fclose(sdata);
}



void doctors_info()
{
    printf("\nAll Doctor's Information\n\n");
    FILE *data;

    data=fopen("doctors_data_base.csv","r");

    char details[SIZED];

    while(fgets(details,SIZED,data) != NULL)
    {
        printf("%s",details);
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
        char temp[SIZED];
        strcpy(temp,details);

        char *x=strtok(temp," \n");
        while (x !=NULL) {

            if (strcmp(x, doctorName) ==0)
            {
                printf("Doctor's Information:\n%s",details);


                while (fgets(details, SIZED, data) !=NULL && strcmp(details, "\n") !=0)
                {
                    printf("%s",details);
                }
                found = true;
                break;
            }
            x=strtok(NULL," \n");
        }
        if (found)
        {
            break;
        }
    }

    if (!found)
    {
        printf("Doctor with name '%s' not found.\nPlease search again.\n", doctorName);
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

            fprintf(data,"\nName: %s\nDesignation: %s\nDepartment: %s\nQualification: %s\nSpeciality: %s\nChamber Floor: %s\nChamber Room: %s\nChamber Time: %s\nOff Day: %s\nContact: %s\n", name, designation, department, qualification, speciality, chamberFloor, chamberRoom, chamberTime, offDay, contact);

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


//patient admission
void current_dateTime(char *date_time)
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

    sprintf(date_time,"%.2d-%.2d-%d  &  %.2d:%.2d:%.2d",date,month,year,hour,minute,second);
}


struct Patient
{
    int id;
    char name[NAME_LENGHT];
    int age;
    char blood_grp[10];
    char guardian_name[NAME_LENGHT];
    char guardian_relation[NAME_LENGHT];
    char mobile[ALL_LENGHT];
    char problem[ALL_LENGHT];
    char refDoctor[ALL_LENGHT];
    char date_time[SIZED];
    struct Patient* next;
};
struct Patient *head1=NULL;


int getLastPatientId()
{
    FILE *patientsFile = fopen("patients.csv", "r");
    if (patientsFile == NULL)
    {
        return 1;
    }

    int lastId=0;
    int currentId;
    while (fscanf(patientsFile, "ID: %d", &lastId) ==1)
    {
        lastId=currentId;
    }

    fclose(patientsFile);
    return lastId++;
}

struct Patient *createPatient()
{
    struct Patient *newPatient = (struct Patient *)malloc(sizeof(struct Patient));
    newPatient->id =getLastPatientId();
    newPatient->next = NULL;
    return newPatient;
}

void admitPatient(struct Patient *head1)
{
    struct Patient *newPatient=createPatient();

    printf("Enter patient details:\n");
    printf("Name: ");
    scanf("%s",newPatient->name);
    printf("Age: ");
    scanf("%d",&newPatient->age);
    printf("Blood Group: ");
    scanf("%s",newPatient->blood_grp);
    printf("Guardian Name: ");
    scanf("%s",newPatient->guardian_name);
    printf("Guardian Relation: ");
    scanf("%s",newPatient->guardian_relation);
    printf("Mobile: ");
    scanf("%s",newPatient->mobile);
    printf("Problem: ");
    scanf("%s",newPatient->problem);
    printf("Referred By: ");
    scanf("%s",newPatient->refDoctor);

    current_dateTime(newPatient->date_time);

    newPatient->id=getLastPatientId();
    newPatient->next = head1;
    head1 = newPatient;

    FILE *patientsFile = fopen("patients.csv", "a");
    fprintf(patientsFile, "ID: %d\nName: %s\nAge: %d\nBlood Group: %s\nGuardian Name: %s\nGuardian Relation: %s\nContact: %s\nProblem Details: %s\nAdmitting Date & Time: %s\nReferred Doctor: %s\n\n",
            newPatient->id, newPatient->name, newPatient->age, newPatient->blood_grp, newPatient->guardian_name, newPatient->guardian_relation,
            newPatient->mobile, newPatient->problem,newPatient->refDoctor,newPatient->date_time);

    fclose(patientsFile);

    printf("Patient admitted successfully. Patient ID: %d\nAdmission Date & Time: %s\n\n", newPatient->id, newPatient->date_time);
}


void freeMemory()
{
    struct Patient *current = head1;
    struct Patient *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void patientDatabase()
{
    printf("\nAll Admitted Patient Information\n\n");
    FILE* patientsFile;

    patientsFile=fopen("patients.csv","r");

    char pdetails[SIZED];

    while(fgets(pdetails,SIZED,patientsFile) !=NULL)
    {
        printf("%s",pdetails);
    }
    fclose(patientsFile);
    printf("\n");
}


bool isAdmin(char *user, char *pass)
{
    char username[][USERNAME_LENGHT]={"COMMON_USER","common_user","RECEPTION","reception","ADMIN","admin"};
    char password[][PASSWORD_LENGHT]={"LOGIN","login","COMMON_USER","common_user","ADMINISTRATOR","administrator"};
    int size =sizeof(username)/sizeof(username[0]);
    int i;
    for (i=0; i<size;i++)
    {
        if(strcmp(username[i],user)==0 && strcmp(password[i],pass)==0)
        {
            return true;
        }
    }
    return false;
}

int main() {
    char username[USERNAME_LENGHT];
    char password[PASSWORD_LENGHT];

    login_pannel(username, password);

    int choice;
    do {
        printf("\nHospital Management System\n");
        printf("1. Admit Patient\n");
        printf("2. View Admitted Patients\n");
        printf("3. Receptionist\n");
        printf("4. Search Receptionist\n");
        printf("5. Doctors\n");
        printf("6. Search Doctors\n");
        printf("7. Add Doctors\n");
        printf("8. Delete Doctors\n");
        printf("9. Nurse's\n");
        printf("10. Search Nurse's\n");
        printf("11. Support Staff\n");
        printf("12. Search Support Staff\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

    switch (choice)
    {
        case 1:
            admitPatient(head1);
            freeMemory();
            break;
        case 2:
            patientDatabase();
            break;
        case 3:
            receptionist_database();
            char option;
            printf("Do you want to search any Receptionist?\tIf yes press 'Y' if no press 'N'\n");
            scanf(" %c", &option);
            if (option=='Y' || option=='y')
            {
                char name[NAME_LENGHT];
                printf("Enter Receptionist Name: ");
                scanf("%s", name);
                searchReceptionist(name);
                printf("\n");
            }
            break;
        case 4:
            {
                char name1[NAME_LENGHT];
                printf("Enter Receptionist Name: ");
                scanf("%s",name1);
                searchReceptionist(name1);
                getchar();
                char option1;
                printf("\nDo you want to search another?\tIf yes press 'Y' if no press 'N'\n");
                scanf(" %c",&option1);

                if (option1=='Y' || option1=='y')
                {
                    char name2[NAME_LENGHT];
                    printf("Enter Receptionist Name: ");
                    scanf("%s",name2);
                    searchReceptionist(name2);
                    printf("\n");
                }
                break;
            }
        case 5:
            {
                doctors_info();
                getchar();

                char option2;
                printf("Do you want to search any Doctor? If yes press 'Y', if no press 'N'\n");
                scanf(" %c", &option2);

                if (option2=='Y' || option2=='y') {
                    char name[NAME_LENGHT];
                    printf("Enter Doctor Name: ");
                    scanf("%s",name);
                    searchDoctor(name);
                    getchar();
                    printf("\n");
                }
                break;
            }
        case 6:
        {
            char name3[NAME_LENGHT];
            char option3;
            printf("Enter Doctor Name: ");
            scanf("%s",name3);
            searchDoctor(name3);
            printf("\nDo you want to search another?\tIf yes press 'Y' if no press 'N'\n");
            scanf("%c",&option3);
            if (option3=='Y' || option3=='y')
            {
                char name4[NAME_LENGHT];
                printf("Enter Doctor Name: ");
                scanf("%s", name4);
                searchDoctor(name4);
                printf("\n");
            }
            break;
        }
        case 7:
        {
            addDoctor();
            char option4;
            if(isAdmin)
            {
                printf("\nDo you want to Try Again?\tIf yes press 'Y' if no press 'N'\n");
                scanf(" %c", &option4);
                if (option4=='Y' || option4=='y')
                {
                    addDoctor();
                }
            }
            break;
        }
        case 8:
            deleteDoctor();
            break;
        case 9:
        {
            nurse_database();
            char option5;
            printf("Do you want to search any Nurse?\tIf yes press 'Y' if no press 'N'\n");
            scanf(" %c", &option5);
            if (option5=='Y' || option5=='y') {
                char department[DEPARTMENT_LENGHT];
                printf("Enter Nurse Department: ");
                scanf("%s", department);
                searchNurse(department);
                printf("\n");
            }
            break;
        }
        case 10:
        {
            char department[DEPARTMENT_LENGHT];
            char option6;
            printf("Enter Nurse Department: ");
            scanf("%s", department);
            searchNurse(department);
            printf("\nDo you want to search another?\tIf yes press 'Y' if no press 'N'\n");
            scanf(" %c", &option6);
            if (option6 == 'Y' || option6 == 'y')
            {
                char department2[DEPARTMENT_LENGHT];
                printf("Enter Nurse Department: ");
                scanf("%s", department2);
                searchNurse(department2);
                printf("\n");
            }
                break;
        }
        case 11:
        {
            support_staff();
            char option7;
            printf("Do you want to search any Support Staff?\tIf yes press 'Y' if no press 'N'\n");
            scanf("%c",&option7);
            if (option7=='Y' || option7=='y')
            {
                char department3[DEPARTMENT_LENGHT];
                printf("Enter Support Staff Department: ");
                scanf("%s",department3);
                searchSupport_staff(department3);
                printf("\n");
            }
            break;
        }
        case 12:
        {
            char department4[DEPARTMENT_LENGHT];
            char option8;
            printf("Enter Support Staff Department: ");
            scanf("%s", department4);
            searchSupport_staff(department4);
            printf("\nDo you want to search another?\tIf yes press 'Y' if no press 'N'\n");
            scanf(" %c",&option8);
            if (option8=='Y' || option8=='y')
            {
                char department5[DEPARTMENT_LENGHT];
                printf("Enter Support Staff Department: ");
                scanf("%s", department5);
                searchSupport_staff(department5);
                printf("\n");
            }
            break;
        }
        case 13:
            printf("\n\nLoggin Out the Hospital Management System. Thank you. Have a nice day.\n\n");
            break;
        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }
    while (choice != 13);


    return 0;
}
