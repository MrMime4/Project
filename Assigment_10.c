#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct courier
{
    char se_name[25],re_name[25],re_address[40],se_mobile[20],re_mobile[20];
	int pkg_n,pkg_chrg,cost,dist,pkg_time,re_pin,user_id,user_id1;
	float pkg_wt;
    struct courier *service;
} *start ;
int id1=1;
int id =1,error;
int isvalidmo(char mobile[], int n);
struct courier *create(struct courier *start);
void display (struct courier *start);
struct courier *sort(struct courier *start);
void *search(struct  courier*start,char account[]);
struct Courier *insert(struct courier *start);
struct courier *del(struct courier *start,char account[]);
struct courier *modify(struct courier *start,char account[]);
void del_queue();
struct courier *front=NULL;
struct courier *rear=NULL;
void create_queue();
void display_queue();
void insert_queue() ;
void graph(struct courier *start ,char account[20]);
struct courier *p,*q,*temp;
char account [50],a[20];
int n, j,i,user_id,pos,choice,ch,tempqty ;
int flag =0,chw=0,j=0;
struct courier* getNewNode()
{
    struct courier* temp = (struct courier*)malloc(sizeof(struct courier));
    temp->service = NULL;
    return temp;
}
char password[30]="9975563164";
char pass[30],name[20];
void login()
{
printf("Enter Your Name\n");
scanf("%s",name);
printf("Enter the password:");
 for(i=0;i<=9;i++)
{
    ch=getch();
    pass[i]=ch;
    ch='*';

printf("%c",ch);
}
pass[i]='\0';
if(strcmp(password,pass)==0)
    {          printf("\n\n");
    }
    else
    {printf("\nYour system has been locked\n");
 login();
    }}

void main ()
{
    login();
    system("COLOR F1") ;
    struct courier *start = NULL;
   printf ("\n\n\n\n") ;
    printf ("\n\n\n\n") ;
    printf("\t**********************************************************");
    printf("\n\t<<<<<<<<  WELCOME to the Courier Management system >>>>>>>>");
    printf("\n\t**********************************************************\n\n\n\n");
 while(1)
    {
        printf(" \n Menu :");
        printf("\n1.Create");
        printf("\n2.Display details") ;
        printf("\n3.Sort") ;
        printf("\n4.Search") ;
        printf("\n5.Insert") ;
        printf("\n6.Delete") ;
        printf("\n7.Modify") ;
        printf("\n8.create using queue") ;
        printf("\n9.Display details using queue") ;
        printf("\n10. Delete using queue") ;
        printf("\n11. Insert using queue") ;
        printf("\n12. To check in profit or in Loss");
        printf(" \n Enter your choice :");
        scanf ("%d",&ch ) ;
        switch (ch)
        {
            case 1:
                start=create(start);
                break;
            case 2:
                printf("\n Display details\n\n");
                display(start);
                break;
            case 3 :
                printf("\n After Sort : ");
                display(start);
                break;
            case 4:
                printf("\n Enter the senders mobile Number you want you search : ");
                scanf("%s",account);
                search(start,account);
                break;
            case 5:
                start=insert(start);
                break;
            case 6:
                printf("\n -------------------------------------------------------");
                printf("\n Enter the Order you want to delete(senders Mobile No.): ");
                scanf("%s",&account);
                printf("\n -------------------------------------------------------");
                start=del(start,account);
                break;
            case 7:
                printf("\n Enter Order you want to modify :");
                scanf("%s",account );
                start=modify(start,account);
                break;
            case 8:
                 create_queue();
                 break;
            case 9:
                  display_queue();
                  break;
            case 10:
                  del_queue();
                  break;
            case 11 :
                  insert_queue() ;
                  break ;
            case 12:
                  printf("\n\t\t\t***|||*** represent PROFIT");
                  printf("\n\n\t\t\t***||*** represent LOSS");
                  printf("\nEnter senders mobile No. for it's profit / loss graph:\t");
                  scanf("%s",account);
                  graph(start,account);
                  break;
             default:
                printf("wrong choice");
                exit(0);
        }
    }
}
struct courier* create(struct courier* start)
        {
            struct courier *p, *temp;
            printf ("Enter the number of orders you want to create : \n ");
            scanf ("%d",&n) ;
            for(int j=0; j<n; j++)
            {
               temp = getNewNode();
                printf("\n--------------------------------------------------------------------------------");
            	printf("\n  Fill  the senders details");
            	printf("\n--------------------------------------------------------------------------------");
            	printf("\n Enter  Senders NAME:-");
            	scanf("%c", &temp); //For clearing buffer
            	scanf("%s",(temp->se_name));
                error = 0;
                while(1)
                {
                    if(error==1)
                    {
                        printf("Theres something went wrong");
                    }
                    printf("\nEnter senders Mobile:\n");
                    scanf("%s",temp->se_mobile);
                    if(strlen(temp->se_mobile)<=10 && isvalidmo(temp->se_mobile, strlen(temp->se_mobile)))
                      break;
                    error=1;
                }
                printf("\n--------------------------------------------------------------------------------");
            	printf("ENTER RECIVER DETAILS");
            	printf("\n--------------------------------------------------------------------------------");
            	printf("\n Enter receiver NAME:-");
            	scanf("%c", &temp); //For clearing buffer
            	scanf("%s",(temp->re_name));
            	printf("\nEnter Address:-");
            	scanf("%c", &temp); //For clearing buffer
            	scanf("%s",(temp->re_address));
            	fflush(stdin);
            	printf("\nEnter Pincode:-");
            	scanf("%d",&(temp->re_pin));
                error = 0;
                while(1)
                {
                    if(error==1)
                    {
                        printf("Theres something went wrong");
                    }
                    printf("\nEnter receiver Mobile:\n");
                    scanf("%s",temp->re_mobile);
                    if(strlen(temp->re_mobile)<=10 && isvalidmo(temp->re_mobile, strlen(temp->re_mobile)))
                      break;
                    error=1;
                }
                printf("\n--------------------------------------------------------------------------------");
                printf("\n Fill the package details");
                printf("\n--------------------------------------------------------------------------------");
                printf("\n\n No Of Quantities:-");
                scanf("%d",&(temp->pkg_n));
                printf("\nTotal Package Weight(in Kg):-");
                scanf("%f",&(temp->pkg_wt));
                printf("\nEnter The Number Of Days :-");
                scanf("%d",&(temp->pkg_time));
                printf("\n Enter the distance : ");
                scanf("%d",&(temp->dist));
                if(temp->pkg_wt<=50)
                {
                    temp->cost=temp->dist*5;
                    printf("\nCost for delivery : %d",temp->cost);
                }
                else if(temp->pkg_wt>50&&temp->pkg_wt<=100)
                {
                    temp->cost=temp->dist*10;
                    printf("\nCost for delivery : %d",temp->cost);
                }
                else
                {
                    temp->cost=temp->dist*15;
                    printf("\nCost for delivery : %d",temp->cost);
                }
                printf("\n\nUser ID :- %d\n", id);
                temp->user_id = id++;
                if(start == NULL)
                {
                    start = temp;
                    temp->service = NULL;
                }
                else
                {
                    p=start;
                    while(p->service!=NULL)
                        p=p->service;
                    p->service=temp;
                    temp->service =NULL;
                }
        }
        return start;
}
  void display(struct courier*start)
    {
        struct courier *p;
        printf("\n \t welcome to the Courier Management system");
        printf("USER\nID\tSENDER_NAME\t\tSENDER_MOBILE\tRECIVER_NAME\t\tRECIVER_ADDRESS\t\tRECIVER_MOBILE\tPACKAGE_DETAILS\t\tCOST\n\n");
        printf("\n");

        p = start;
        while(p!=NULL)
      {
          printf("\n\%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t%s\t\tQUANTITY:-%d\t\t%d\n\n",p->user_id,p->se_name,p->se_mobile,p->re_name,p->re_address,p->re_mobile,p->pkg_n,p->cost);
          printf("\t\t\t\t\t\t\t\t\t%d\t\t\t\t\tWEIGHT:-%f\n",p->re_pin,p->pkg_wt);
          printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\tTIME:-%d\n\n",p->pkg_time);
          p=p->service;
      }
  }
 struct courier *sort(struct courier*start)
  {

      struct courier *p, *q, *temp;
      temp=(struct courier*)malloc(sizeof(struct courier)*1000);
      for(p=start;p->service!=NULL;p=p->service)
      {
          for(q=p->service; q!=NULL; q=q->service)
          {

             if(p->pkg_n > q->pkg_n)
            {
                temp->pkg_n=p->pkg_n;
                p->pkg_n=q->pkg_n;
                q->pkg_n=temp->pkg_n;
                strcpy(temp->se_name,p->se_name);
                strcpy(p->se_name,q->se_name);
                strcpy(q->se_name,temp->se_name);

                strcpy(temp->re_name,p->re_name);
                strcpy(p->re_name,q->re_name);
                strcpy(q->re_name,temp->re_name);
            }
          }
      }
  }

  void display1(struct courier*start)  //sorting display
    {
        struct courier *p;
        printf("\n \t welcome to the Courier Management system");
        printf("\n\tSENDER_NAME\tRECIVER_NAME\tQUANTITY\n\n");
        printf("\n");

        p = start;
        while(p!=NULL)
      {
          printf("\n\t%s\t%s\t\t%d\n\n",p->se_name,p->re_name,p->pkg_n);

          p=p->service;
      }
  }

void *search(struct courier *start,char account[])
 {
     struct courier *p;
     if(strcmp(start ->se_mobile,account)==0)
     {
         printf("\n Order Found ....!");
         printf("\n -------------------------------------------------------------------------");
         printf("\nUSER\nID\t\tSENDER_NAME\t\tSENDER_MOBILE\t\tRECIVER_NAME\t\tRECIVER_ADDRESS\t\tRECIVER_MOBILE\t\tPACKAGE_DETAILS\t\tCOST\n\n");
         printf("\n\n%d\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\tQUANTITY:-%d\t\t%d\n\n",start->user_id,start->se_name,start->se_mobile,start->re_name,start->re_address,start->re_mobile,start->pkg_n,start->cost);
         printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWEIGHT:-%d\n\n",start->pkg_wt);
         printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTIME:-%d\n\n",start->pkg_time);
         flag++;
         return;
         }
         p=start;
         while (p->service!=NULL)
         {
             if(strcmp(p->service->se_mobile,account)==0)
             {
                 printf("\n Order Found ....!");
                 printf("\n ------------------------------------------------------------------------------");
                 printf("\nUSER\nID\t\tSENDER_NAME\t\tSENDER_MOBILE\t\tRECIVER_NAME\t\tRECIVER_ADDRESS\t\tRECIVER_MOBILE\t\tPACKAGE_DETAILS\t\tCOST\n\n");
                 printf("\n\n%d\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\tQUANTITY:-%d\t\t%d\n\n",p->service->user_id,p->service->se_name,p->service->se_mobile,p->service->re_name,p->service->re_address,p->service->re_mobile,p->service->pkg_n,p->service->cost);
                 printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWEIGHT:-%d\n\n",p->service->pkg_wt);
                 printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTIME:-%d\n\n",p->service->pkg_time);
                 return;
             }
             p=p->service;
             flag++;
         }
     if(flag==0)
     printf("\n Not Found !");
}
struct Courier *insert(struct courier *start)
{
    struct courier *p,*temp;
    temp=(struct courier*)malloc(sizeof(struct courier )*1);
    printf("\n Enter order no. you want to insert");
    scanf("%d",&pos);
    if(pos==1)
    {
        printf("\n--------------------------------------------------------------------------------");
        printf("\n  Fill  the senders details");
        printf("\n--------------------------------------------------------------------------------");
        printf("\n Enter  Senders NAME:-");
        scanf("%c", &temp); //For clearing buffer
        scanf("%s",(temp->se_name));
        error = 0;
        while(1)
        {
            if(error==1)
            {
                printf("Theres something went wrong");
            }
            printf("\nEnter senders Mobile:\n");
            scanf("%s",temp->se_mobile);
            if(strlen(temp->se_mobile)<=10 && isvalidmo(temp->se_mobile, strlen(temp->se_mobile)))
              break;
            error=1;
        }
        printf("\n--------------------------------------------------------------------------------");
        printf("ENTER RECIVER DETAILS");
        printf("\n--------------------------------------------------------------------------------");
        printf("\n Enter receiver NAME:-");
        scanf("%c", &temp); //For clearing buffer
        scanf("%s",(temp->re_name));
        printf("\nEnter Address:-");
        scanf("%c", &temp); //For clearing buffer
        scanf("%s",(temp->re_address));
        fflush(stdin);
        printf("\nEnter Pincode:-");
        scanf("%d",&(temp->re_pin));
        error = 0;
        while(1)
        {
            if(error==1)
            {
                printf("Theres something went wrong");
            }
            printf("\nEnter receivers Mobile:\n");
            scanf("%s",temp->re_mobile);
            if(strlen(temp->re_mobile)<=10 && isvalidmo(temp->re_mobile, strlen(temp->re_mobile)))
              break;
            error=1;
        }        printf("\n--------------------------------------------------------------------------------");
        printf("\n Fill the package details");
        printf("\n--------------------------------------------------------------------------------");
        printf("\n\n No Of Quantities:-");
        scanf("%d",&(temp->pkg_n));
        printf("\nTotal Package Weight(in Kg):-");
        scanf("%f",&(temp->pkg_wt));
        printf("\nEnter The Number Of Days :-");
        scanf("%d",&(temp->pkg_time));
        printf("\n Enter the distance : ");
        scanf("%d",&(temp->dist));
        if(temp->pkg_wt<=50)
        {
            temp->cost=temp->dist*5;
            printf("\nCost for delivery : %d",temp->cost);
        }
        else if(temp->pkg_wt>50&&temp->pkg_wt<=100)
        {
            temp->cost=temp->dist*10;
            printf("\nCost for delivery : %d",temp->cost);
        }
        else
        {
            temp->cost=temp->dist*15;
            printf("\nCost for delivery : %d",temp->cost);
        }
        printf("\n\nUser ID :- %d\n", id);
        temp->user_id = id++;
        temp->service=start;
        start=temp;
        return start;
    }
    p= start;
    for(int i=1; i<pos -1 && p!=NULL;i++)
     p=p->service;
     if(p==NULL)
     printf("\n Less NO. of Orders");
     else
      {
        printf("\n--------------------------------------------------------------------------------");
        printf("\n  Fill  the senders details");
        printf("\n--------------------------------------------------------------------------------");
        printf("\n Enter  Senders NAME:-");
        scanf("%c", &temp); //For clearing buffer
        scanf("%s",(temp->se_name));
        error = 0;
        while(1)
        {
            if(error==1)
            {
                printf("Theres something went wrong");
            }
            printf("\nEnter senders Mobile:\n");
            scanf("%s",temp->se_mobile);
            if(strlen(temp->se_mobile)<=10 && isvalidmo(temp->se_mobile, strlen(temp->se_mobile)))
              break;
            error=1;
        }
        printf("\n--------------------------------------------------------------------------------");
        printf("ENTER RECIVER DETAILS");
        printf("\n--------------------------------------------------------------------------------");
        printf("\n Enter receiver NAME:-");
        scanf("%c", &temp); //For clearing buffer
        scanf("%s",(temp->re_name));
        printf("\nEnter Address:-");
        scanf("%c", &temp); //For clearing buffer
        scanf("%s",(temp->re_address));
        fflush(stdin);
        printf("\nEnter Pincode:-");
        scanf("%d",&(temp->re_pin));
        error = 0;
        while(1)
        {
            if(error==1)
            {
                printf("Theres something went wrong");
            }
            printf("\nEnter receivers Mobile:\n");
            scanf("%s",temp->re_mobile);
            if(strlen(temp->re_mobile)<=10 && isvalidmo(temp->re_mobile, strlen(temp->re_mobile)))
              break;
            error=1;
        }          printf("\n--------------------------------------------------------------------------------");
          printf("\n Fill the package details");
          printf("\n--------------------------------------------------------------------------------");
          printf("\n\n No Of Quantities:-");
          scanf("%d",&(temp->pkg_n));
          printf("\nTotal Package Weight(in Kg):-");
          scanf("%f",&(temp->pkg_wt));
          printf("\nEnter The Number Of Days :-");
          scanf("%d",&(temp->pkg_time));
          printf("\n Enter the distance : ");
          scanf("%d",&(temp->dist));
          if(temp->pkg_wt<=50)
          {
              temp->cost=temp->dist*5;
              printf("\nCost for delivery : %d",temp->cost);
          }
          else if(temp->pkg_wt>50&&temp->pkg_wt<=100)
          {
              temp->cost=temp->dist*10;
              printf("\nCost for delivery : %d",temp->cost);
          }
          else
          {
              p->cost=p->dist*15;
              printf("\nCost for delivery : %d",temp->cost);
          }
          printf("\n\nUser ID :- %d\n", id);
          temp->user_id = id++;
           temp->service=p->service;
           p->service=temp;
      }
     return start;
}
struct courier *del(struct courier *start, char account[])
{
    struct courier *temp ,*p;
    if(strcmp(start->se_name,account)==0)
    {
        temp=start;
        start=temp->service;
        free(temp);
        return start;
    }
        p=start;
        while(p->service!=NULL)
        { if(strcmp(p->service->se_name,account)==0)
            {
              temp=p->service;
              p->service=temp->service;
              free(temp);
              return start;
        }
       p=p->service;
       }
       }
       struct courier *modify(struct courier *start,char account[])
              {
                    if(strcmp(start->se_mobile,account)==0)
                   {
                     printf("\nITEM FOUND\n");
                     printf("\n Order ID :",user_id);
                     printf("\nUSER\nID\t\tSENDER_NAME\t\tSENDER_MOBILE\t\tRECIVER_NAME\t\tRECIVER_ADDRESS\t\tRECIVER_MOBILE\t\tPACKAGE_DETAILS\t\tCOST\n\n");

                        {
                   printf("\n\n%d\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\tQUANTITY:-%d\t\t%d\n\n",start->user_id,start->se_name,start->se_mobile,start->re_name,start->re_address,start->re_mobile,start->pkg_n,start->cost);
                   printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWEIGHT:-%d\n\n",start->pkg_wt);
                   printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTIME:-%d\n\n",start->pkg_time);
                        }

                   do
                   {
                       printf("\nYou Want To Update:\n 1:SENDER NAME\n 2:SENDER MOBILE\n 3:RECIVER NAME\n4:RECIVER MOBILE");
                       printf("\n5:RECIVER ADDRESS\n6:RECIVER PINCODE\n 7:PACKGE WEIGHT\n 8:PACKGE QUANTITY\n 9:PACKGE TIME");
                       printf("\n10:PACKGE DISTANCE\nEnter Choice:-");
                       scanf("%d",&choice);
                       switch (choice)
          {
               case 1:
                      printf("Enter new Name:-");
                      scanf("%s",start->se_name);
                      break;
               case 2:
                      printf("Enter new Mobile:-");
                      scanf("%s",start->se_mobile);
                      break;
                case 3:
                       printf("Enter new Name:-");
                       scanf("%s",start->re_name);
                       break;
                case 4:
                       printf("Enter new Mobile:-");
                       scanf("%s",start->re_mobile);
                       break;
                case 5:
                       printf("Enter new Address:-");
                       scanf("%s",start->re_address);
                       break;
                case 6:
                       printf("Enter new PinCode:-");
                       scanf("%d",&start->re_pin);
                       break;

                 case 7:
                        printf("Enter new Weight-");
                        scanf("%f",&start->pkg_wt);
                        break;
                 case 8:
                        printf("Enter new Quantity-");
                        scanf("%d",&start->pkg_n);
                        break;
                 case 9:
                        printf("Enter no of Days-");
                        scanf("%d",&start->pkg_time);
                        break;
                 case 10:
                        printf("Enter new Distance-");
                        scanf("%d",&start->dist);
                        break;
                  default:
                          printf("Wrong Choice!");
                          break;
                     }
                     printf("press 1 to continue modifying:");
                     scanf("%d",&chw);
                   }
                   while(chw==1);
                          flag++;
                          return start;
                    }
                     p=start;
                     while(p->service!=NULL)
                       {
                          if(strcmp(p->service->se_mobile,account)==0)
                        {
                         printf("\n*order FOUND\n");
                         printf("\nOrder ID :",user_id);
                         printf("\nUSER\nID\t\tSENDER_NAME\t\tSENDER_MOBILE\t\tRECIVER_NAME\t\tRECIVER_ADDRESS\t\tRECIVER_MOBILE\t\tPACKAGE_DETAILS\t\tCOST\n\n");
                             {
                          printf("\n\n%d\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\tQUANTITY:-%d\t\t%d\n\n",p->service->user_id,p->service->se_name,p->service->se_mobile,p->service->re_name,p->service->re_address,p->service->re_mobile,p->service->pkg_n,p->service->cost);
                          printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWEIGHT:-%d\n\n",p->service->pkg_wt);
                          printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTIME:-%d\n\n",p->service->pkg_time);

                             }
                          do
                          {
                              printf("You Want To Update: 1:SENDER NAME\n 2:SENDER MOBILE\n 3:RECIVER NAME\n4:RECIVER MOBILE\n");
                              printf("5:RECIVER ADDRESS\n 6:RECIVER PINCODE\n 7:PACKGE WEIGHT\n 8:PACKGE QUANTITY\n 9:PACKGE TIME\n");
                              printf(" 10:PACKGE DISTANCE\nEnter Choice:-");
                              scanf("%d",&choice);
                              switch (choice)

                        {
                            case 1:
                                   printf("Enter new Name:-");
                                   scanf("%s",p->service->se_name);
                                   break;
                            case 2:
                                  printf("Enter new Mobile:-");
                                  scanf("%s",p->service->se_mobile);
                                  break;
                          case 3:
                                 printf("Enter new name:-");
                                 scanf("%s",p->service->re_name);
                                 break;
                         case 4:
                                printf("Enter new Mobile:-");
                                scanf("%s",p->service->re_mobile);
                                break;
                         case 5:
                                printf("Enter new Address:-");
                                scanf("%s",p->service->re_address);
                                break;
                         case 6:
                                printf("Enter new PinCode:-");
                                scanf("%d",p->service->re_pin);
                                break;
                          case 7:
                                 printf("Enter new Weight-");
                                 scanf("%f",p->service->pkg_wt);
                                 break;
                          case 8:
                                 printf("Enter new Quantity-");
                                 scanf("%d",p->service->pkg_n);
                                 break;
                          case 9:
                                 printf("Enter no of Days-");
                                 scanf("%d",p->service->pkg_time);
                                 break;
                          case 10:
                                  printf("Enter new Distance-");
                                  scanf("%d",p->service->dist);
                                  break;
                           default:
                                   printf("Wrong Choice!");
                                   return;
                         }printf("press 1 to continue modifying:");
                          scanf("%d",&chw);
                        }
                         while(chw==1);
                     }
                             p=p->service;
                             flag++;
                             return start;
                      }

                      if(flag==0)
                      printf("\n\nnot found\n\n");

              }
       void create_queue()
       {
           struct courier *temp,*p;
            int n;
            printf("Enter no. of orders :");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
              if (rear==NULL)
           {
               rear=(struct courier*)malloc(sizeof(struct courier)*1000);
               printf("\n--------------------------------------------------------------------------------");
               printf("\n  Fill  the senders details");
               printf("\n--------------------------------------------------------------------------------");
               printf("\n Enter  Senders NAME:-");

               scanf("%s",rear->se_name);
               fflush(stdin);

               printf("\nEnter Mobile NO :-");

               scanf("%s",(rear->se_mobile));
               fflush(stdin);


               printf("\n--------------------------------------------------------------------------------");
               printf("ENTER RECIVER DETAILS");
               printf("\n--------------------------------------------------------------------------------");

               printf("\n Enter receiver NAME:-");

               scanf("%s",(rear->re_name));
               fflush(stdin);

               printf("\nEnter Address:-");

               scanf("%s",(rear->re_address));
               fflush(stdin);

               printf("\nEnter Pincode:-");
               scanf("%d",&(rear->re_pin));

               printf("\nEnter Mobile NO :-");

               scanf("%s",(rear->re_mobile));

                 printf("\n--------------------------------------------------------------------------------");
                 printf("\n Fill the package details");
                 printf("\n--------------------------------------------------------------------------------");
                 printf("\n\n No Of Quantities:-");
                 scanf("%d",&(rear->pkg_n));

                 printf("\nTotal Package Weight(in Kg):-");
                 scanf("%f",&(rear->pkg_wt));

                 printf("\nEnter The Number Of Days :-");
                 scanf("%d",&(rear->pkg_time));

                 printf("\n Enter the distance : ");
                 scanf("%d",&(rear->dist));
                 if(rear->pkg_wt<=50)
                 {
                     rear->cost=rear->dist*5;
                     printf("\nCost for delivery : %d",rear->cost);
                 }
                 else if(rear->pkg_wt>50&&rear->pkg_wt<=100)
                 {
                     rear->cost=rear->dist*10;
                     printf("\nCost for delivery : %d",rear->cost);
                 }
                 else
                 {
                     p->cost=p->dist*15;
                     printf("\nCost for delivery : %d",rear->cost);
                 }


                 printf("\n\nUser ID :- %d\n",id1);
                 rear->user_id1 = id1++;

               rear->service=NULL;
               front=rear;


           }

           else

           {
               temp=(struct courier*)malloc(sizeof(struct courier)*100);
               printf("\n--------------------------------------------------------------------------------");
               printf("\n  Fill  the senders details");
               printf("\n--------------------------------------------------------------------------------");
               printf("\n Enter  Senders NAME:-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->se_name));

               printf("\nEnter Mobile NO :-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->se_mobile));

                 printf("\n--------------------------------------------------------------------------------");
               printf("ENTER RECIVER DETAILS");
               printf("\n--------------------------------------------------------------------------------");

               printf("\n Enter receiver NAME:-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->re_name));


               printf("\nEnter Address:-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->re_address));
               fflush(stdin);

               printf("\nEnter Pincode:-");
               scanf("%d",&(temp->re_pin));

               printf("\nEnter Mobile NO :-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->re_mobile));

                 printf("\n--------------------------------------------------------------------------------");
                 printf("\n Fill the package details");
                 printf("\n--------------------------------------------------------------------------------");
                 printf("\n\n No Of Quantities:-");
                 scanf("%d",&(temp->pkg_n));

                 printf("\nTotal Package Weight(in Kg):-");
                 scanf("%f",&(temp->pkg_wt));

                 printf("\nEnter The Number Of Days :-");
                 scanf("%d",&(temp->pkg_time));

                 printf("\n Enter the distance : ");
                 scanf("%d",&(temp->dist));
                 if(temp->pkg_wt<=50)
                 {
                     temp->cost=temp->dist*5;
                     printf("\nCost for delivery : %d",temp->cost);
                 }
                 else if(temp->pkg_wt>50&&temp->pkg_wt<=100)
                 {
                     temp->cost=temp->dist*10;
                     printf("\nCost for delivery : %d",temp->cost);
                 }
                 else
                 {
                     p->cost=p->dist*15;
                     printf("\nCost for delivery : %d",temp->cost);
                 }


                 printf("\n\nUser ID :- %d\n", id1);
                 temp->user_id1 = id1++;

               rear->service=temp;
               rear=temp;
           }
     }
 }
 void display_queue()
       {
           struct courier *p;


           if(front==NULL)
           {
               printf("\n No Order created yet\n");
           }
           else
           {    p=front;
                  printf("\nUSER\nID\t\tSENDER_NAME\t\tSENDER_MOBILE\t\tRECIVER_NAME\t\tRECIVER_ADDRESS\t\tRECIVER_MOBILE\t\tPACKAGE_DETAILS\t\tCOST\n\n");
               while(p!=NULL)
                  {
                      printf("\n\n%d\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%s\t\tQUANTITY:-%d\t\t%d\n\n",p->user_id1,p->se_name,p->se_mobile,p->re_name,p->re_address,p->re_mobile,p->pkg_n,p->cost);
                      printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tWEIGHT:-%d\n\n",p->pkg_wt);
                      printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTIME:-%d\n\n",p->pkg_time);
                       p=p->service;
                  }
           }
       }
    void del_queue()
       {
           struct courier *temp;
           if(front==NULL)
           {
               printf("\n*Queue Underflow*\n");
           }
           else
           {
           temp=front;
           front=front->service;
           free(temp);
           }
       }
  void insert_queue()
       {
           struct courier *temp,*p;
            int n;
            printf("Enter no. of orders :");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
              if (rear==NULL)
           {
               rear=(struct courier*)malloc(sizeof(struct courier)*1000);
               printf("\n--------------------------------------------------------------------------------");
               printf("\n  Fill  the senders details");
               printf("\n--------------------------------------------------------------------------------");
               printf("\n Enter  Senders NAME:-");

               scanf("%s",rear->se_name);
               fflush(stdin);

               printf("\nEnter Mobile NO :-");

               scanf("%s",(rear->se_mobile));
               fflush(stdin);


               printf("\n--------------------------------------------------------------------------------");
               printf("ENTER RECIVER DETAILS");
               printf("\n--------------------------------------------------------------------------------");

               printf("\n Enter receiver NAME:-");

               scanf("%s",(rear->re_name));
               fflush(stdin);

               printf("\nEnter Address:-");

               scanf("%s",(rear->re_address));
               fflush(stdin);

               printf("\nEnter Pincode:-");
               scanf("%d",&(rear->re_pin));

               printf("\nEnter Mobile NO :-");

               scanf("%s",(rear->re_mobile));

                 printf("\n--------------------------------------------------------------------------------");
                 printf("\n Fill the package details");
                 printf("\n--------------------------------------------------------------------------------");
                 printf("\n\n No Of Quantities:-");
                 scanf("%d",&(rear->pkg_n));

                 printf("\nTotal Package Weight(in Kg):-");
                 scanf("%f",&(rear->pkg_wt));

                 printf("\nEnter The Number Of Days :-");
                 scanf("%d",&(rear->pkg_time));

                 printf("\n Enter the distance : ");
                 scanf("%d",&(rear->dist));
                 if(rear->pkg_wt<=50)
                 {
                     rear->cost=rear->dist*5;
                     printf("\nCost for delivery : %d",rear->cost);
                 }
                 else if(rear->pkg_wt>50&&rear->pkg_wt<=100)
                 {
                     rear->cost=rear->dist*10;
                     printf("\nCost for delivery : %d",rear->cost);
                 }
                 else
                 {
                     p->cost=p->dist*15;
                     printf("\nCost for delivery : %d",rear->cost);
                 }


                 printf("\n\nUser ID :- %d\n", id1);
                 rear->user_id1 = id1++;

               rear->service=NULL;
               front=rear;


           }

           else

           {
               temp=(struct courier*)malloc(sizeof(struct courier)*100);
               printf("\n--------------------------------------------------------------------------------");
               printf("\n  Fill  the senders details");
               printf("\n--------------------------------------------------------------------------------");
               printf("\n Enter  Senders NAME:-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->se_name));

               printf("\nEnter Mobile NO :-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->se_mobile));

                 printf("\n--------------------------------------------------------------------------------");
               printf("ENTER RECIVER DETAILS");
               printf("\n--------------------------------------------------------------------------------");

               printf("\n Enter receiver NAME:-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->re_name));


               printf("\nEnter Address:-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->re_address));
               fflush(stdin);

               printf("\nEnter Pincode:-");
               scanf("%d",&(temp->re_pin));

               printf("\nEnter Mobile NO :-");
               scanf("%c", &temp); //For clearing buffer
               scanf("%s",(temp->re_mobile));

                 printf("\n--------------------------------------------------------------------------------");
                 printf("\n Fill the package details");
                 printf("\n--------------------------------------------------------------------------------");
                 printf("\n\n No Of Quantities:-");
                 scanf("%d",&(temp->pkg_n));

                 printf("\nTotal Package Weight(in Kg):-");
                 scanf("%f",&(temp->pkg_wt));

                 printf("\nEnter The Number Of Days :-");
                 scanf("%d",&(temp->pkg_time));

                 printf("\n Enter the distance : ");
                 scanf("%d",&(temp->dist));
                 if(temp->pkg_wt<=50)
                 {
                     temp->cost=temp->dist*5;
                     printf("\nCost for delivery : %d",temp->cost);
                 }
                 else if(temp->pkg_wt>50&&temp->pkg_wt<=100)
                 {
                     temp->cost=temp->dist*10;
                     printf("\nCost for delivery : %d",temp->cost);
                 }
                 else
                 {
                     p->cost=p->dist*15;
                     printf("\nCost for delivery : %d",temp->cost);
                 }


                 printf("\n\nUser ID :- %d\n", id1);
                 temp->user_id1 = id1++;

               rear->service=temp;
               rear=temp;
           }
     }
 }
  void graph(struct courier *start,char account[20])
  {
      if(strcmp(start->se_mobile,account)==0)
      {
        printf("\n Order ID :%d",user_id);
        printf("\nQuantity of Order is %d :",start->pkg_n);
        tempqty=start->pkg_n;
        if((tempqty)>=5)
        {
          printf("\n\n***In Profit !!!***");
          for(i=0; i<tempqty; i++)
          {
              printf("\n \t|| \n");
          }
          printf("\n \t\t%s",start->se_mobile);
        }
       else
       {
          printf("\n\n***In Loss !!!***");
          for(i=0; i<tempqty; i++)
          {
              printf("\n \t|| \n");
          }
          printf("\n \t\t%s",start->se_mobile);
       }
       flag++;
       }
       p=start;
       while(p->service!=NULL)
       {
          if(strcmp(p->service->se_mobile,account)==0)
          {
            printf("\nOrder ID :%d",user_id);
            printf("\nQunatity of order is %d :",p->service->pkg_n);
            tempqty=p->service->pkg_n;
            if((tempqty)>=5)
            {
              printf("\n\n***In Profit !!!***");
              for(i=0; i<tempqty; i++)
              {
                printf("\n\t||| \n");
              }
              printf("\n \t\t%s",p->service->se_mobile);
            }
            else
            {
               printf("\n\n***In Loss !!!***");
               for(i=0; i<tempqty; i++)
               {
                 printf("\n\t|| \n");
               }
               printf("\n \t\t%s",p->service->se_mobile);
            }
            flag++;
        }  p=p->service;
          }
          if(flag==0)
          printf("\n\n**No order found**\n\n");
  }
 int isvalidmo(char *mobile,int n)
  {
     for(int i=0;i<n;i++)
      {
          if(!isdigit(mobile[i]))
              return 0;
      }

      if (mobile[0] == '9' || mobile[0] == '8' || mobile[0] == '7' || mobile[0] == '6')
        return 1;
       return 0;
  }
