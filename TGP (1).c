#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>
int menu();
int coderunner(int ,int);
int showrecord();
int clearrecord();
int recorddata(int,int);
int taxget(int);
void printbill(int*,int*,int,int);
void codebreaker(int);
int main()
{
    printf("\t\t\t\t\t\t\t\t\t\t WELCOME TO THE GRAND PIZZA \n");
    printf("\t\t\t\t\t\t\t\t\t\t ----------------------------\n\n\n");
    while(1)
    {
        int esc=1;
        menu();
        int code,qty;
        int sum=0;
        int tax=0;
        int *items=(int*)malloc(sizeof(int)*30);//array to store items purchased....................
        int *qntty=  (int*)malloc(sizeof(int)*30);//array to store their quantities...................
        int qit=0;     //as qit increases we fill items[qit]=item code ,,,like this.................
        int itemsit=0;  //as one item is purchased 17 in quantity then we put qty[itemsit]=17.......
        while(esc==1)
        {
            printf("\n ENTER THE CODE ::");
            scanf("%d",&code);
            if( code==1 || code==2 || code==3
               || code==11 || code==12 || code==13 || code==14 || code==15 || code==16 || code==17
                || code==21 || code==22 || code==23 || code==24  || code==25
                || code==31 || code==32 || code==33
                || code==41 || code==42  || code==43  || code==44 || code==45 || code==46
                || code==51 || code==52 || code==53  || code==54  || code==55
                || code==61 || code==62 || code==71 )
            {
                     if(code!=61 && code!=62 && code!=71)
            {
                printf("ENTER THE QUANTITY::\t");
                scanf("%d",&qty);
                items[qit]=code;
                qntty[itemsit]=qty;
                qit++;
                itemsit++;
                printf("\n");
            }
            if(code==61)
            {
                showrecord();
                esc=2;
            }
            if(code==62)
            {
                clearrecord();
                esc=2;
            }
            if(code==71 )
            {
                esc=2;
            }
            if(code!=61 && code!=71)
            {
                    sum=sum+coderunner(code,qty);
            }

            }
                 else
                 {
                     printf("ENTER A RIGHT CODE \n");
                 }

        }
        system("cls");
        printf("\n\n\n");
        sum=sum+tax;
        if(sum>4)
        {
            printbill(items,qntty,qit,itemsit);
            tax=tax+taxget(sum);
            printf("\n\n\n");
            printf("---------------------------------------------------------------------\n");
            printf("|| tax    =%54d |||\n",tax);
            printf("|| bill   =%54d |||\n",sum);
            printf("|| total  =%54d |||\n",tax+sum);
            printf("---------------------------------------------------------------------\n");
            recorddata(sum,tax);
            printf("\n");
            printf("press ennter to continue \n");
            getch();
        }
        free(items);
        free(qntty);
        system("cls");
    }
    return 0;
}

int menu()
{
char str[100];
FILE *fp;
fp=fopen("pizza.txt","r");
if(fp==NULL)
{
    printf("file not found\n");
}
while(fgets(str,6,fp)!=NULL)
{
    printf("%s",str);
}
fclose(fp);
return 0;
}

int coderunner(int choice,int quantity)
{
    switch(choice)
        {
        case 1:
            return 10*quantity;
            break;
        case 2:
            return 15*quantity;
            break;
        case 3:
            return 25*quantity;
            break;
        case 11:
            return 70*quantity;
            break;
        case 12:
            return 80*quantity;
            break;
        case 13:
            return 90*quantity;
            break;
        case 14:
            return 100*quantity;
            break;
        case 15:
            return 120*quantity;
            break;
        case 16:
            return 75*quantity;
            break;
        case 17:
            return 90*quantity;
            break;
        case 21:
            return 150*quantity;
            break;
        case 22:
            return 170*quantity;
            break;
        case 23:
            return 150*quantity;
            break;
        case 24:
            return 170*quantity;
            break;
        case 25:
            return 180*quantity;
            break;
        case 31:
            return 300*quantity;
            break;
        case 32:
            return 300*quantity;
            break;
        case 33:
            return 320*quantity;
            break;
        case 41:
            return 60*quantity;
            break;
        case 42:
            return 45*quantity;
            break;
        case 43:
            return 50*quantity;
            break;
        case 44:
            return 50*quantity;
            break;
        case 45:
            return 110*quantity;
            break;
        case 46:
            return 115*quantity;
            break;
        case 51:
            return 25*quantity;
            break;
        case 52:
            return 30*quantity;
            break;
        case 53:
            return 40*quantity;
            break;
        case 54:
            return 70*quantity;
            break;
        case 55:
            return 45*quantity;
            break;
        default:
            return 0;
            break;
        }
        return 0;
}
int taxget(int g)
{
    int tax;
    if(g<1000)
    {
        return 0;
    }
    if(g<1500 && g>1000)
    {
        return ((g*0.5)/100);
    }
    if(g>1500 && g<8000)
    {
        return ((g*(1.5))/100);
    }
    if(g>8000)
    {
        return ((g*3)/100);
    }
}
int recorddata(int val,int tax)
{
    FILE *fp;
    fp=fopen("finnal.dat","ab");
    if(fp==NULL)
    {
        printf("FILE IS UNABLE TO OPEN......\n\n");
        exit(1);
    }
    SYSTEMTIME stime;
    GetLocalTime(&stime);

    struct biller
    {
        int day,month,year,second,minute,hour;
        int gst;
        int total;
    }bill;
    bill.day=stime.wDay;
    bill.month=stime.wMonth;
    bill.year=stime.wYear;

    bill.second=stime.wSecond;
    bill.minute=stime.wMinute;
    bill.hour=stime.wHour;

    bill.total=val;
    bill.gst=tax;
    fwrite(&bill,sizeof(bill),1,fp);
    fclose(fp);
    return 0;
}
int showrecord()
{
    system("cls");
    fflush(stdin);
    int i;
    FILE *fp;
    struct biller
    {
        int day,month,year,second,minute,hour;
        int gst;
        int total;
    }bill;
    fp=fopen("finnal.dat","rb");
    if(fp==NULL)
    {
        printf("FILE NOT FOUND \n\n");
        exit(1);
    }
    else
    {
        i=1;
        printf("----------------------------------------------------------------------------------------------------------------------------------------\n");//table sanranchna----
        printf("|     RECORD no.||                      ||    TIME       ||          DATE      ||                   TAX          ||     TOTAL          |\n");
        printf("|---------------||----------------------||---------------||--------------------||--------------------------------||--------------------|\n");//table sanranchna----


        while(fread(&bill,sizeof(bill),1,fp)>0)
        {
            //printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");//table sanranchna----
            printf("||||    %5d   ||  \t\t\t|| %02d::%02d::%02d    ||       %2d/%2d/%2d   ||\t\t  %11d    ||  %11d     ||| ",i,bill.hour,bill.minute,bill.second,bill.day,bill.month,bill.year,bill.gst,bill.total);
            printf("\n");
            i++;
        }
         printf("|--------------------------------------------------------------------------------------------------------------------------------------|\n");//table sanranchna----
    }
     fclose(fp);
     printf("enter to continue\n");
     getch();
    return 0;
}
void printbill(int *a,int *b,int ai,int bi)
{
    printf("--****************|||********************************************************--\n");
    printf("||         ITEM.. |||                                 QUANTITY..             ||\n");
    printf("||****************|||********************************************************||\n");
    for(int i=0;i<ai;i++)
    {
        printf("||");
        codebreaker(a[i]);
        printf("||| %50d     ||",b[i]);
        printf("\n");
    }
    printf("--****************|||********************************************************--\n");
}
void codebreaker(int code)
{
    switch(code)
        {
        case 1:
            printf("cheese burst    ");
            break;
        case 2:
            printf("Black Olives    ");
            break;
        case 3:
            printf("Pepperon        ");
            break;
        case 11:
            printf("Capsicum        ");
            break;
        case 12:
            printf("onion           ");
            break;
        case 13:
            printf("corn            ");
            break;
        case 14:
            printf("PANNER          ");
            break;
        case 15:
            printf("Mix-Veg         ");
            break;
        case 16:
            printf("Tomato          ");
            break;
        case 17:
            printf("Cheese          ");
            break;
        case 21:
            printf("Regular panner  ");
            break;
        case 22:
            printf("margherita      ");
            break;
        case 23:
            printf("chhese          ");
            break;
        case 24:
            printf("regular corn    ");
            break;
        case 25:
            printf("mix-veg regular ");
            break;
        case 31:
            printf("Margherita      ");
            break;
        case 32:
            printf(" Cheese         ");
            break;
        case 33:
            printf("Mix-veg         ");
            break;
        case 41:
            printf("Coca Cola       ");
            break;
        case 42:
            printf("Spirite         ");
            break;
        case 43:
            printf("Frooti          ");
            break;
        case 44:
            printf("Mountain -Dew   ");
            break;
        case 45:
            printf("Monster         ");
            break;
        case 46:
            printf("Red Bull        ");
            break;
        case 51:
            printf("Tea             ");
            break;
        case 52:
            printf("Coffe           ");
            break;
        case 53:
            printf("Black Coffe     ");
            break;
        case 54:
            printf("Cold Coffe      ");
            break;
        case 55:
            printf("Ice Tea         ");
            break;
        default:
            printf("_________");
            break;
        }
}
int clearrecord()
{
    system("cls");
    FILE *fp;
    struct biller
    {
        int day,month,year,second,minute,hour;
        int gst;
        int total;
    }bill;
    fp=fopen("finnal.dat","wb");
    fclose(fp);
    printf("the records are clear now\n");
    printf("press eneter to continue \n\n");
    getch();
    return 0;
}
