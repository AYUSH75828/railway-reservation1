#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct Train

{

    char train_no[10];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;

};
struct passenger
{

    char p_name[20];
    char gender;
    char train_no[10];
    char p_class;
    char address[30];
    int age;
    int ticketno;
    char moblie_no[11];

};

typedef struct Train Train;
typedef struct passenger passenger;


int enterchoice();
void add_trains();
void view_trains();
int book_ticket(passenger);
int* get_ticket_number(char*);
void view_ticket(int);
void view_all_booking();
void view_booking(char *);
int cancle_ticket(int);
int cancle_train (char*);
passenger *get_passenger_detail();
int check_train_no(char*);
int get_booked_ticket_count(char *,char);
int last_ticket_no();
int check_mob_no(char*);
int accept_ticket_no();

char* accept_mob_no();
void view_all_tickets(char*,int*);
char* accept_train_no();



#endif // RLYRES_H_INCLUDED
