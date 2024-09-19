/**
 *
 *Author: Trenton Cook
 *2024-09-19
 *
 *an amortization table for a 401(k) account.
 */


#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){

if(argc != 6) {
        printf("ERROR: invalid data\n");
        printf("Correct data Input: (starting balance) (monthly contribution) (annual rate of return) (annual rate of inflation) (years until retirement)\n");
                exit(1);
     } else if(atof(argv[1]) < 0 || atof(argv[2]) < 0 || atoi(argv[5]) < 0) {
        printf("Error: Inputs cannot be less than 0\n");
                exit(1);
        } else if(atof(argv[3]) < 0 || atof(argv[4]) < 0) {
        printf("Error: Inputs cannot be less than 0\n");
                exit(1);
        } else if(atof(argv[3]) > 1 || atof(argv[4]) > 1){
        printf("Error: Inputs (annual rate of return) (annual rate of inflation) cannot be less than 0 or greater than 1\n");
                exit(1);
        }

double startBal = atof(argv[1]) ;
double monthlyContrib = atof(argv[2]) ;
double annualRate = atof(argv[3]) ;
double annualInflate = atof(argv[4]) ;
int yearsUntil = atoi(argv[5]) ;
double monthlyRate = (((1 + annualRate)/(1 + annualInflate))-1)/12;



// after the start bal * monthly rate = next intrest next bal is + intrest+ monthlyContrib

printf("%lf , %lf, %lf, %lf, %d\n", startBal, monthlyContrib, annualRate, annualInflate, yearsUntil);
printf("%lf,\n", monthlyRate);

 return 0;
}
