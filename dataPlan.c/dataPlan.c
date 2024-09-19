/* Author: Trenton Cook
0224-09-12

data Plans for phones to see limits
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){


 if(argc != 4) {
        printf("ERROR: invalid data\n");
        printf(" Correct data Input: (total gb for the plan) (current day of your plan) (gb used so far)\n");
                exit(1);
     } else if(atof(argv[1]) < 0 || atoi(argv[2]) < 0 || atof(argv[3]) < 0) {
        printf("Error: Inputs cannot be less than 0\n");
                exit(1);
     }


double gbTotal = atof(argv[1]) ;
int dayCurrent = atoi(argv[2]) ;
double gbUsed = atof(argv[3]) ;
double dayAllowance, gbLeft, gbEstimate, gbCurrentUsage , currentExpectedTotal ;
int daysLeft ;

dayAllowance = gbTotal / 30 ;  //what your allowed to do with your plan a day
gbLeft = gbTotal - gbUsed ;    //how many GB are left in this current month
daysLeft = 30 - dayCurrent ;   // how many days are left in your current plan
gbEstimate = gbLeft / daysLeft ;  // usage a day with what is left to stay in your plan
gbCurrentUsage = gbUsed / dayCurrent ;  //current usage a day
currentExpectedTotal = (gbCurrentUsage * 30) - gbTotal ; //total GB over your alloted ammount if you dont change your daily usage

 if(gbUsed >= gbTotal) {   // exceedede aloowance laready
    printf("%d days used, %d days remaining\n", dayCurrent, daysLeft) ;
    printf("Average daily use: %.2lf GB/day\n", gbCurrentUsage) ;
    printf("You have already met your limit for this month.  Looks like you're getting some overage charges...\n") ;
 }else if(dayAllowance < gbCurrentUsage){ // over your daily usage
    printf("%d days used, %d days remaining\n", dayCurrent, daysLeft) ;
    printf("Average daily use: %.2lf GB/day\n", gbCurrentUsage) ;
    printf("\nYou are EXCEEDING your average daily use (%.2lf GB/day).\n", dayAllowance) ;
    printf("Continuing this high usage, you'll exceed your data plan by %.2lf GB.\n", currentExpectedTotal) ;
    printf("To stay below your data plan, use no more than %.2lf GB/day.\n", gbEstimate) ;
 }else if(dayAllowance >= gbCurrentUsage) {    //under daily usage
    printf("%d days used, %d days remaining\n", dayCurrent, daysLeft) ;
    printf("Average daily use: %.2lf GB/day\n", gbCurrentUsage) ;
    printf("\nYou are at or below your average daily use (%.2lf GB/day).\n", dayAllowance);
    printf("You can use up to %.2lf GB/day and stay below your data plan limit\n", gbEstimate) ;
 }

 return 0;
}
