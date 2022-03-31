#include<stdio.h>
#include<stdlib.h>

int get_1st_weekDay(int year)  //to find first day of year//
{
    int day;
    day=(((year-1)*365) + ((year-1)/4) - ((year-1)/100) + ((year)/400)+1) % 7; //algorithm to calculate the first day of year//
    return day;
}

int main()
{
    system("color 3F"); //system is function used to pass the commands that can be executed in the command processor //
    //here system funtion is used to to change background colour//

    int year,month,day,daysOfmonth,weekDay=0,firstDay;  //declaratiom//

    printf("\nEnter the year: ");
    scanf("%d",&year); //taking year as input from user//

    char *months[]={"January","February","March","April","May","June","July","August","September","October", "November","December"};//declared variable month as array pointer//
    int numOfDays[]={31,28,31,30,31,30,31,31,30,31,30,31}; //number of days in each month//

    if((year%4==0 && year%100!=0) || year%400==0) // condition for leap year//
    {
        numOfDays[1]=29;//february//
    }

    firstDay=get_1st_weekDay(year); // delcaring first day by calling the funtion//

    for(month=0;month<12;month++)  //for loop used to print months and days //
    {
        daysOfmonth=numOfDays[month];  //days Of month is assinged value of number of days of a particular month//

        printf("\n\n            %s         \n ",months[month]);  //months of index month is printed//
        printf("\n  Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n"); 

        for(weekDay=0;weekDay<firstDay;weekDay++) 
        {
            printf("     ");
        }

        for(day=1;day<=daysOfmonth;day++) // for loop for days of month//
        {
            printf("%5d",day);  //5d to give space between each number//

            if(++weekDay>6) //if number of days in week exceeds 7, it will go to next line//
            {
                printf("\n");
                weekDay=0;  //this is to keep loop going//
            }

                firstDay=weekDay;
        }

    }
    return 0;
}