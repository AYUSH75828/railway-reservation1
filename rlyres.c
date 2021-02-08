#include<stdio.h>
#include<string.h>
#include"conio2.h"
#include"rlyres.h"
#include<ctype.h>
int enterchoice()
{

    int choice,i;
    gotoxy(28,1);
    textcolor(YELLOW);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=0;i<80;i++)
        printf("-");
    printf("\nEnter choice");
    printf("\n1- view trains");
    printf("\n2- book tickets");
    printf("\n3- view tickets");
    printf("\n4- search ticket no");
    printf("\n5- view all booking");
    printf("\n6- view train bookings");
    printf("\n7- cancle ticket");
    printf("\n8- cancle train");
    printf("\n9- Quit");
    printf("\n\n\nenter chooice-");
    scanf("%d",&choice);
    return choice;


}
void add_trains()
{
Train alltrains[4]={
              {"123","BPL","GWA",2100,1500},
              {"546","BPL","DEL",3500,2240},
              {"345","HBJ","AGR",1560,1135},
              {"896","HBJ","MUM",4500,3360},
              };
FILE *fp=fopen("e:\\c project\\railwayreservation\\alltrains.dat","rb");
if(fp==NULL)
{
    fp=fopen("e:\\c project\\railwayreservation\\alltrains.dat","wb");
    fwrite(alltrains,4*sizeof(Train),1,fp);
    printf("file created and saved\n");
}
else
    printf("file already present");
fclose(fp);


}
void view_trains()
{
    int i;
    printf("TRAIN NO\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\n");
    for(i=0;i<80;i++)
        printf("-");
FILE *fp=fopen("e:\\c project\\railwayreservation\\alltrains.dat","rb");
        Train tr;
while(fread(&tr,sizeof(tr),1,fp)==1)
{


    printf("\n%s\t\t%s\t%s\t\t%d\t\t%d",tr.train_no,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
}

 printf("\n\n\n");
 fclose(fp);
}

int check_train_no(char *trainno)
{

    FILE *fp=fopen("e:\\c project\\railwayreservation\\alltrains.dat","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp))
    {


        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}

int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
    {
        return 0;
    }
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
    }
    return 1;
}


passenger * get_passenger_detail()
{
 clrscr();
 gotoxy(60,1);
 textcolor(LIGHTGREEN);
 printf("press 0 to exit");
 gotoxy(1,1);
 textcolor(YELLOW);
 static passenger psn;
 printf("Enter passenger name:");
 fflush(stdin);
 fgets(psn.p_name,20,stdin);//fgets add new line so we have to remove it by /o

 char *pos;
 pos=strchr(psn.p_name,'\n');
 *pos='\0';
 if(strcmp(psn.p_name,"0")==0)
 {

     textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("Rservation Cancelled");
     getch();
     textcolor(YELLOW);
     clrscr();
     return NULL;

 }
int valid;
printf("Enter Gender(M/F):");
do
{

valid=1;
fflush(stdin);
scanf("%c",&psn.gender);
if(psn.gender=='0')
{
    textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t\t");
     gotoxy(1,25);
     printf("Reservation Cancelled");
     getch();
     textcolor(YELLOW);
     clrscr();
     return NULL;


}
if(psn.gender!='M'&&psn.gender!='F')
{

    textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("Error!Gender should be M or F(in uppercase)!");
     valid=0;
     getch();
     gotoxy(19,2);
     printf("\t");
     gotoxy(19,2);
     textcolor(YELLOW);



}
} while(valid==0);
gotoxy(1,25);
printf("\t\t\t\t\t\t\t\t");
gotoxy(1,3);
printf("Enter train number:");
do
{

    fflush(stdin);
    scanf("%s",psn.train_no);
 if(strcmp(psn.train_no,"0")==0)
{
    textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t\t");
     gotoxy(1,25);
     printf("Reservation Cancelled");
     getch();
     textcolor(YELLOW);
     clrscr();
     return NULL;


}
  valid=check_train_no(psn.train_no);


   if(valid==0)
{
    textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("Error!invalid Train No!");
     getch();
     gotoxy(20,3);
     printf("\t\t\t\t\t");
     gotoxy(20,3);
     textcolor(YELLOW);


}
}while(valid==0);

gotoxy(1,25);
printf("\t\t\t\t\t\t");
gotoxy(1,4);
printf("Enter travelling class(First AC:F,Second AC:S):");

do
{

valid=1;
fflush(stdin);
scanf("%c",&psn.p_class);
if(psn.p_class=='0')
{
    textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t\t");
     gotoxy(1,25);
     printf("Reservation Cancelled");
     getch();
     textcolor(YELLOW);
     clrscr();
     return NULL;


}
if(psn.p_class!='F'&&psn.p_class!='S')
{

    textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("Error!Travelling class should be F or S");
     valid=0;
     getch();
     gotoxy(48,4);
     printf("\t");
     gotoxy(48,4);
     textcolor(YELLOW);

}
} while(valid==0);
gotoxy(1,25);
printf("\t\t\t\t\t\t\t");
gotoxy(1,5);
printf("Enter address:");
fflush(stdin);
fgets(psn.address,20,stdin);

pos=strchr(psn.address,'\n');
 *pos='\0';
 if(strcmp(psn.address,"0")==0)
 {

     textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t");
     gotoxy(1,25);
     printf("Rservation Cancelled");
     getch();
     textcolor(YELLOW);
     clrscr();
     return NULL;

 }
 printf("Enter age:");
 do
 {

     valid=1;
     fflush(stdin);
     scanf("%d",&psn.age);
     if(psn.age==0)
     {

         textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t\t");
     gotoxy(1,25);
     printf("Reservation Cancelled");
     getch();
     textcolor(YELLOW);
     clrscr();
     return NULL;
     }
     if(psn.age<0 )
     {
         textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("Error!Age should be positive");
     valid=0;
     getch();
     gotoxy(11,6);
     printf("\t\t\t\t\t\t");
     gotoxy(11,6);
     textcolor(YELLOW);

     }
 }while(valid==0);

gotoxy(1,25);
printf("\t\t\t\t\t\t\t\t");
gotoxy(1,7);
printf("Enter moblie number:");
do
{
    fflush(stdin);
    fgets(psn.moblie_no,20,stdin);
    pos=strchr(psn.moblie_no,'\n');
    if(pos!=NULL)
      *pos='\0';
    if(strcmp(psn.moblie_no,"0")==0)
    {
    textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t\t");
     gotoxy(1,25);
     printf("Reservation Cancelled");
     getch();
     textcolor(YELLOW);
     clrscr();
     return NULL;
    }
    valid=check_mob_no(psn.moblie_no);
    if(valid==0)
    {
      textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("Error!Invalid Moblie No!");
     getch();
     gotoxy(21,7);
     printf("\t\t\t\t\t\t");
     gotoxy(21,7);
     textcolor(YELLOW);
    }
}while(valid==0);
return &psn;
}
int get_booked_ticket_count(char *train_no,char tc)
{

FILE *fp=fopen("e:\\c project\\railwayreservation\\allbooking.dat","rb");//FILE *fp=fopen("e:\\c project\\railwayreservation\\alltrains.dat","rb");
if(fp==NULL)
    return 0;
passenger pr;
int count=0;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
    if((strcmp(pr.train_no,train_no)==0) && pr.p_class==tc)

        ++count;
}
fclose(fp);
return count;
}
int last_ticket_no()
{
    FILE *fp=fopen("e:\\c project\\railwayreservation\\allbooking.dat","rb");
if(fp==NULL)
    return 0;
    passenger pr;
    fseek(fp,-1L*sizeof(pr),SEEK_END);
    fread(&pr,sizeof(pr),1,fp);
    fclose(fp);
    return pr.ticketno;

}


int book_ticket(passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
if(ticket_count ==2)//in our project it is 30 but for testing purpose we set it to 2
{
    textcolor(LIGHTRED);
    printf("All seat in train no %s in class %c are full",p.train_no,p.p_class);
    return -1;

}

int ticket_no=last_ticket_no()+1;
p.ticketno=ticket_no;
FILE *fp=fopen("e:\\c project\\railwayreservation\\allbooking.dat","ab");
if(fp==NULL)
{
    textcolor(LIGHTRED);
    printf("Server Down please try after some time");
    return -1;
}
fwrite(&p,sizeof(p),1,fp);
fclose(fp);
return ticket_no;


}

int accept_ticket_no()
{
    printf("Enter a valid ticket no");
    int valid;
    int ticket_no;
    do
    {
        valid=1;
        scanf("%d",&ticket_no);
        if(ticket_no==0)
 {

     textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("\t\t\t\t\t\t\t");
     gotoxy(1,25);
     printf("Cancelling Input....");
     getch();
     textcolor(YELLOW);
     clrscr();
     return 0;

 }
 if(ticket_no<0)
 {
    textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("Error!Ticket Number should be positive");
     getch();
     valid=0;
     gotoxy(24,7);
     printf("\t\t\t\t\t");
     gotoxy(24,7);
     getch();
     textcolor(YELLOW);
 }

    }while(valid==0);
    return ticket_no;
}
void view_ticket(int ticket_no)
{
int i;
FILE *fp=fopen("e:\\c project\\railwayreservation\\allbooking.dat","rb");
if(fp==NULL)
{

    textcolor(LIGHTRED);
    printf("Sorry!File Cannot be opened");
    return;
}
passenger pr;
int found=0;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
    if(pr.ticketno==ticket_no)
    {
        printf("\nName:%s\nGender:%c\nTrain No:%s\nClass:%c\nAddress:%s\nAge:%d\nMobile No:%s\nTicket no:%d",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.moblie_no,pr.ticketno);
     found=1;
     break;
    }
}if(!found)
{
    textcolor(LIGHTRED);
    printf("\nNo  details of the ticket no %d found",ticket_no);

}
    fclose(fp);
}

char* accept_mob_no()
{
    static char mob_no[12];
    char *pos;
    int valid;
    printf("Enter valid Mobile Number:");
    do
    {
        fflush(stdin);
        fgets(mob_no,12,stdin);
        pos=strchr(mob_no,'\n');
        if(pos!=NULL)
            *pos='\0';
        if(strcmp(mob_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling input!...");
            getch();
            textcolor(YELLOW);
            clrscr();
            return NULL;

        }

     valid=check_mob_no(mob_no);
    if(valid==0)
    {
      textcolor(LIGHTRED);
     gotoxy(1,25);
     printf("Error!Invalid Moblie No!");
     getch();
     gotoxy(27,1);
     printf("\t\t\t\t\t\t");
     gotoxy(27,1);
     textcolor(YELLOW);
     }
}
while(valid==0);
    clrscr();
    return mob_no;
}
int* get_ticket_number(char* p_mob_no)
{
    int count=0;
    FILE *fp=fopen("e:\\c project\\railwayreservation\\allbooking.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!File can not be opened");
        return NULL;
    }


    passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.moblie_no,p_mob_no)==0)
            count++;
    }
    if(!count)
    {
        fclose(fp);
        return NULL;
    }
    int *p=(int*)malloc((count+1)*sizeof(int));
    rewind(fp);
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.moblie_no,p_mob_no)==0)
            {
                *(p+i)=pr.ticketno;
                i++;

            }
    }
    *(p+i)=-1;
    fclose(fp);

    return p;

}
void view_all_tickets(char*pmob_no,int *pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("Sorry!NO tickets booked against moblie no. %s",pmob_no);
        textcolor(WHITE);
        printf("\nEnter any key to go back to main screen");
        textcolor(YELLOW);
        getch();



    }
    printf("Following are ticket booked for the mobile number %s",pmob_no);
     int i;
    printf("\n\n TICKET NUMBER\n");
    printf("-------------------------------------------------------------------\n");
    textcolor(LIGHTMAGENTA);
    for(i=0;*(pticket_no+i)!=-1;i++)
        printf("\n\t%d",*(pticket_no+i));
    textcolor(YELLOW);
    printf("\nPress any key to go back to main screen");
    textcolor(YELLOW);
    getch();


free(pticket_no);
}

char* accept_train_no()
{

static char train_no[10];
int valid;
gotoxy(60,1);
textcolor(LIGHTGREEN);
printf("Press 0 to stop");
gotoxy(1,1);
textcolor(YELLOW);
printf("Enter train number:");
do
{
    fflush(stdin);
    scanf("%s",train_no);

    if(strcmp(train_no,"0")==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Cancelling input!...");
            getch();
            textcolor(YELLOW);
            return NULL;

        }
    valid=check_train_no(train_no);
    if(valid==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("Error!Invalid Train NO!");
        getch();
        gotoxy(20,1);
        printf("\t\t\t\t\t\t");
        gotoxy(20,1);
        textcolor(YELLOW);
    }
}
while(valid==0);
clrscr();
return train_no;
}
void view_booking(char* train_no)
{
int found=0;
int i,row;
FILE *fp=fopen("e:\\c project\\railwayreservation\\allbooking.dat","rb");
if(fp==NULL)
{
    textcolor(LIGHTRED);
    printf("Sorry!File cannot be opened");
    return;
}
passenger pr;
printf("Ticket NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
for(i=1;i<=80;i++)
    printf("-");
row=3;
while(fread(&pr,sizeof(pr),1,fp)==1)
{
    if(strcmp(pr.train_no,train_no)==0)
    {
        printf("%d\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
        gotoxy(41,row);
        printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.moblie_no);
        row++;

        found=1;
    }
}
if(!found)
{
    clrscr();
    textcolor(LIGHTRED);
    printf("\nNo details of the booking in train no %s found",train_no);

}
textcolor(WHITE);
printf("\n\nPress any key to continue....");
textcolor(YELLOW);
getch();
fclose(fp);

}

int cancle_ticket(int ticket_no)
{
    FILE *fp1=fopen("e:\\c project\\railwayreservation\\allbooking.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNO booking done yet");
        return -1;
    }
    FILE *fp2=fopen("e:\\c project\\railwayreservation\\temp.dat","wb");
    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno==ticket_no)
        {
            found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }

    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("e:\\c project\\railwayreservation\\temp.dat");
    }
    else
    {
        remove("e:\\c project\\railwayreservation\\allbooking.dat");
        rename("e:\\c project\\railwayreservation\\temp.dat","e:\\c project\\railwayreservation\\allbooking.dat");

    }
    return found;
}
void view_all_booking()
{
    int row=2;
    FILE *fp=fopen("e:\\c project\\railwayreservation\\allbooking.dat","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("File can not be opened try after some time");
        getch();
        textcolor(YELLOW);
    }

    else
    {
        passenger pr;
    printf("Ticket NO\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    while(fread(&pr,sizeof(pr),1,fp)==1)
        {

        printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
        gotoxy(41,row);
        printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.moblie_no);
        row++;

          }

    }

    fclose(fp);


}





int cancle_train(char*train_no)
{
    int result;
    FILE *fp1=fopen("e:\\c project\\railwayreservation\\allbooking.dat","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNO booking done yet");
        return -1;
    }


 FILE *fp2=fopen("e:\\c project\\railwayreservation\\temp.dat","wb");
    passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            found=1;
        }
        else
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }

    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("e:\\c project\\railwayreservation\\temp.dat");
    }
    else
    {
        result=remove("e:\\c project\\railwayreservation\\allbooking.dat");
        if(result!=0)
            return 2;
        result=rename("e:\\c project\\railwayreservation\\temp.dat","e:\\c project\\railwayreservation\\allbooking.dat");
        if(result!=0)
            return 2;

    }

    return found;
}








