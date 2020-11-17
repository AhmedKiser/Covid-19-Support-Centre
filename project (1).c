#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct DOB {
    int day;
    int month;
    int year;
};
int i=0;
struct patient {
    char name[50];
    int age;
    int id;
    char bloodg[50];
    struct DOB db;
    char address[50];
    char traveller[50];
    int phn;
}s[100],upd,rem;
int num = 0,main_exit;
void menu()
{
    int choice;
    printf("\n\n\n\n");
    printf("\n\t\t\t===============================================================");
    printf("\n\t\t\t===============================================================");
    printf("\n\t\t\t||\t\tWelcome to Covid-19 Information Centre       ||");
    printf("\n\t\t\t||\t\t                                             ||");
    printf("\n\t\t\t||\t\t1.Enter your information                     ||");
    printf("\n\t\t\t||\t\t                                             ||");
    printf("\n\t\t\t||\t\t2.Read Information                           ||");
    printf("\n\t\t\t||\t\t                                             ||");
    printf("\n\t\t\t||\t\t3.Edit Information                           ||");
    printf("\n\t\t\t||\t\t                                             ||");
    printf("\n\t\t\t||\t\t4.Search Information                         ||");
    printf("\n\t\t\t||\t\t                                             ||");
    printf("\n\t\t\t||\t\t5.Erase Information                          ||");
    printf("\n\t\t\t||\t\t                                             ||");
    printf("\n\t\t\t||\t\t6.Plasma Information                         ||");
    printf("\n\t\t\t||\t\t                                             ||");
    printf("\n\t\t\t||\t\t7.Exit                                       ||");
    printf("\n\t\t\t||\t\t                                             ||");
    printf("\n\t\t\t===============================================================");
    printf("\n\t\t\t===============================================================");
    printf("\n\t\t\t\t\tEnter your choice  ");
    scanf("%d",&choice);
    system("cls");
    switch(choice){
    case 1:write();
    break;
    case 2:read();
    break;
    case 3:edit();
    break;
    case 4:search();
    break;
    case 5:erase();
    break;
    case 6:plasma();
    break;
    case 7:close();
    break;
    default:
        add_invalid:
printf("\n\nInvalid Choice\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}

    //break;
    }


//}
void write ()
{
FILE *file;
file = fopen ("records.dat","a");
if (file == NULL) {
fprintf(stderr, "\nError opening accounts.dat\n\n"); exit (1);
}
int i;
for(i=0; ; i++){
        fflush(stdin);
printf("Enter  name (or press enter to stop)\n");
      gets(s[i].name);
      if (strcmp(s[i].name, "") == 0)
        break;
      fflush(stdin);

      printf("Enter Age\n");
      scanf("%d", &s[i].age);
      fflush(stdin);
      printf("Enter Blood group\n");
      gets(s[i].bloodg);
      fflush(stdin);
      printf("Enter the date of birth(mm/dd/yyyy):");
      scanf("%d/%d/%d",&s[i].db.month,&s[i].db.day,&s[i].db.year);
      fflush(stdin);
      printf("Enter NID no.\n");
      scanf("%d", &s[i].id);
      fflush(stdin);
      printf("Phone \n");
      scanf("%d", &s[i].phn);
      fflush(stdin);
      printf("Address \n");
      gets(s[i].address);
      fflush(stdin);
      printf("Traveller or travelled recently (Yes/No)\n");
      gets(s[i].traveller);
fflush(stdin);
}
num = i;
fwrite(s, sizeof(struct patient), i, file);
fclose(file);
add_invalid:
printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void read ()
{
FILE *file;
file = fopen ("records.dat","r");
if (file == NULL)
{
fprintf(stderr, "\nError opening accounts.dat\n\n");
exit (1);
}
int i;
num = fread (s, sizeof(struct patient), 100, file);
printf("\n---------------------------------------------");
 printf("\nDisplaying the information:\n");
    for(i = 0; i <num; i++)
    {
      printf("\nPatient name      : ");
      puts(s[i].name);
      printf("Age               : %d", s[i].age);
      printf("\nBlood Group       : ");
      puts(s[i].bloodg);
      printf("Date of birth     : %d/%d/%d",s[i].db.month,s[i].db.day,s[i].db.year);
      printf("\nNID no.           : ");
      printf("%d", s[i].id);
      printf("\nPhone no          : 880%d", s[i].phn);
      printf("\nAddress           : ");
      puts(s[i].address);
      printf("Traveller or travelled recently : ");
      puts(s[i].traveller);
      printf("\n******************************************");
    }
fclose(file);
add_invalid:
printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
}
void close()
{
    printf("\n\n\n\nThis C Mini Project is developed by Ahmed,Raida and Putul!");
}
int avlrollno(int rno)
{
 FILE *file;
 int c = 0;
 file = fopen("records.dat", "r");
 while (!feof(file))
 {
  fread(&upd, sizeof(upd), 1, file);

  if (rno == upd.id)
  {
   fclose(file);
   return 1;
  }
 }
}
 void edit()
{
 int avl;
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter id number to update:");
 scanf("%d", &r);
 avl = avlrollno(r);

 if (avl == 1)
 {
  fpo = fopen("records.dat", "r");
  fpt = fopen("TempFile.dat", "w");
  while (fread(&upd, sizeof(upd), 1, fpo))
  {
   s = upd.id;
   if (s != r)
    fwrite(&upd, sizeof(upd), 1, fpt);

   else
   {
       againcome:
    printf("\n\t Update information of ID Number %d", r);
    printf("\n\t1. Update Name ");
    printf("\n\t2. Update Blood Group ");
    printf("\n\t3. Update Address ");
    printf("\n\t4. Update Phone ");
    printf("\nEnter your choice ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     printf("Enter Name : ");
     scanf("%s", &upd.name);
     break;
    case 2:
     printf("Blood Group : ");
     scanf("%s", &upd.bloodg);
     break;
    case 3:
     printf("Enter address : ");
     scanf("%s", &upd.address);
     break;
     case 4:
     printf("Enter phone no. : ");
     scanf("%d", &upd.phn);
     break;
    default:
     printf("Invalid Selection");
     break;
    }
    fwrite(&upd, sizeof(upd), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("records.dat", "w");
  fpt = fopen("TempFile.dat", "r");
  while (fread(&upd, sizeof(upd), 1, fpt))
  {
   fwrite(&upd, sizeof(upd), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
  add_invalid:
printf("\n\n\nEnter 1 to go to the main menu, 2 to edit another info and 0 to exit:");
    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if (main_exit==2)
        goto againcome;
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
 }
 else
 {

  printf("id number %d is not Available in the file", r);
  add__invalid:
printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
     system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add__invalid;
        }

 }
}
void search()
{
 FILE *fp2;
 int r, s, avl;
 printf("\nEnter the Roll no you want to search  :");
 scanf("%d", &r);
 avl = avlrollno(r);
 if (avl == 1)

 {
  fp2 = fopen("records.dat", "r");
  while (fread(&upd, sizeof(upd), 1, fp2))
  {
   s = upd.id;
   if (s == r)
   {
    printf("\nNID no        = %d", upd.id);
    printf("\nName          = %s", upd.name);
    printf("\nPhone no      = 880%d", upd.phn);
    printf("\nBlood Group   = %s", upd.bloodg);
    printf("\nAddress       = %s", upd.address);
   }
  }
  fclose(fp2);
  add_invalid:
printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
     system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
 }
 else
 {

  printf("id number %d is not Available in the file", r);
  add__invalid:
printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
     system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add__invalid;
        }

 }
}
void erase()
{
 FILE *fpo;
 FILE *fpt;
 int r, s;
 printf("Enter the ID no you want to delete :");
 scanf("%d", &r);
 if (avlrollno(r) == 1)
 {
  fpo = fopen("records.dat", "r");
  fpt = fopen("TempFile.dat", "w");
  while (fread(&rem, sizeof(rem), 1, fpo))
  {
   s = rem.id;
   if (s != r)
    fwrite(&rem, sizeof(rem), 1, fpt);
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("records.dat", "w");
  fpt = fopen("TempFile.dat", "r");
  while (fread(&rem, sizeof(rem), 1, fpt))
   fwrite(&rem, sizeof(rem), 1, fpo);
  printf("\nRECORD DELETED\n");
  fclose(fpo);
  fclose(fpt);
  add_invalid:
printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
     system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;
        }
 }
 else
 {

  printf("id number %d is not Available in the file", r);
  add__invalid:
printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");
    scanf("%d",&main_exit);
     system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add__invalid;
        }

 }
}
void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void main()
{
    char uname[10],username[10]="project",pass[10],password[10]="project";
    int u,main_exit,ch;
    int i=0;
    printf("\n\n\t\tCovid-19 Information Centre");
    printf("\n\n\t\tEnter username to log in : ");
    scanf("%s",uname);
    printf("\n\n\t\tEnter password : ");


    for(i=0;i<7;i++)
    {
        //scanf("%s",ch);
        ch=getch();
        pass[i]=ch;
        ch='*';
        printf("%c",ch);}
        for(i=0;i<=7;i++)
        {
            fordelay(100000000);
            //printf(".");
        }

    pass[i]='\0';

    i=0;
    if (strcmp(uname,username)==0 &&strcmp(pass,password)==0  )
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=7;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }

}
void plasma()
{
printf("\n\nHello Welcome to Plasma Donation\n");
printf("\nIn this pandemic if you want to contribute by giving us plasma from a recovered patient \nThen fill out the form from office\n\n");
printf("\nIf you want to collect plasma please bring your medical report and fill out the form\n");
printf("\nFor any other queries please call 01717554445");
printf("\nThank You \n");
add_invalid:
printf("\n\n\nEnter 1 to go to the main menu and 0 to exit:");

    scanf("%d",&main_exit);
    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto add_invalid;

}        }

