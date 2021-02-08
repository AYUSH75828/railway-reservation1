#include<stdio.h>
#include"conio2.h"
#include<stdlib.h>
#include"rlyres.h"
int main()
{
int choice,ticket_no,result;
char *pmob_no,*train_no;
passenger *ptr;
add_trains();
int *pticket_no;
while(1)
{
    choice=enterchoice();
    if(choice==9)
       exit(0);

      switch(choice)
        {
case 1:
view_trains();
getch();
clrscr();
break;
case 2:
ptr=get_passenger_detail();
clrscr();
if(ptr!=NULL)
{
    ticket_no=book_ticket(*ptr);
    if(ticket_no==-1)
    {
        textcolor(LIGHTRED);
        printf("Booking failed");
    }
    else
    {

        textcolor(LIGHTCYAN);
        printf("Ticket successfully book\nyour ticket no is %d",ticket_no);

    }

    textcolor(WHITE);
    printf("\nEnter any key to go back to main screen");
    getch();
    clrscr();

}
break;
case 3:
    clrscr();
    ticket_no=accept_ticket_no();
    if(ticket_no!=0)
    view_ticket(ticket_no);
    textcolor(WHITE);
    printf("\npress any key to go back to main screen");
    getch();
    clrscr();
    //view_ticket();
    break;
case 4:
    clrscr();
    pmob_no=accept_mob_no();
    if(pmob_no!=NULL)

    {
      pticket_no=get_ticket_number(pmob_no);
      view_all_tickets(pmob_no,pticket_no);
    }
    clrscr();
break;
case 5:
    clrscr();
view_all_booking();

textcolor(LIGHTMAGENTA);
printf("\n\n\tPress any key to go back to main screen!!!!!!");
getch();
clrscr();
break;

case 6:
    clrscr();
train_no=accept_train_no();
if(train_no!=NULL)
{
    view_booking(train_no);
}
clrscr();
break;
case 7:
    clrscr();
    ticket_no=accept_ticket_no();
    if(ticket_no!=0)
    {
        result=cancle_ticket(ticket_no);
        if(result==0)
        {
            textcolor(LIGHTRED);
            printf("Sorry!No tickets booked against ticket no %d",ticket_no);
        }
        else
        {
            textcolor(LIGHTMAGENTA);
            printf("Ticket has been successfully deleted!!!");
            textcolor(YELLOW);

        }
    }
    getch();
//cancel_ticket();
break;
case 8:
 clrscr();
    train_no=accept_train_no();
    if(train_no!= NULL)
    {
        result=cancle_train(train_no);
        if(result==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,3);
            printf("Sorry!No ticket has been booked aganist %s no!!",train_no);
        }
        else if(result==1)
        {
            textcolor(GREEN);
            gotoxy(1,3);
            printf("Train has been cancelled");
        }
         else if(result==2)
        {
            textcolor(GREEN);
            gotoxy(1,3);
            printf("Error contact application provider");
        }
        textcolor(WHITE);
        printf("\nPress any key to go back to main screen");
        getch();
        clrscr();
    }

//cancel_ticket();
break;
default:
   textcolor(LIGHTRED);
   printf("Wromg Choice! Try Again\n");
   getch();
   clrscr();
//clrscr();


}
}

    return 0;
}
