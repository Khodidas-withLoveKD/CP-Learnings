#include <stdio.h>

int main()
{
    int row,space,star,i,j;

    row=4;  //Define no. of row with respect to i; i=1 means 1 row.

    //The upper half of the star pyramid + middlemost row
    for(i=1;i<=row;i++)  //starting row from 1. Because what matters is ans and not value of i.
    {
        space=row-i;     //On proper observation there is a relation between no. of space, no. of stars and row no.
        for(j=0;j<space;j++)
            printf(" ");    //print appropriate space
        for(j=0;j<( ( 2*i ) -1);j++)
            printf("*");    //priint stars as per row i.e. i=1-> 1 star, i=2-> 2*i-1=3 stars and so on

        printf("\n");
    }
    //Making the lower half of the pyramid
    for(i=row-1;i>=1;i--)  //just made some changes here. Try to discover.
    {
        space=row-i;
        for(j=0;j<space;j++)
            printf(" ");
        for(j=0;j<( ( 2*i ) -1);j++)
            printf("*");

        printf("\n");
    }
    //And DONE.
    // You can make this program interactive by taking user input for rows. Try to do it as an exercise.
    return 0;
}
