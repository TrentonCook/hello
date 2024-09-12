/* Author: Trenton Cook
0224-09-05

air distance with lat and long
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv){

    double latA, latB, longA, longB, delta, rad , d;

 //printf("Please input Starting Latitude and Longitude: \n");
    scanf("%lf", &latA);
    scanf("%lf ", &longA);

 //printf("Please input the Destination Latitude and Longitude: \n");
    scanf("%lf", &latB);
    scanf("%lf", &longB);


 rad = 6371 ;
 delta = longB - longA ;
 d = acos((sin(latA/180 * M_PI)) * (sin(latB/180 * M_PI)) + ((cos(latA/180 * M_PI)) * (cos(latB/180 * M_PI)) * (cos(delta/180 * M_PI)))) * rad ;


 printf("Origin: (%lf , %lf ) \n", latA, longA);
 printf("Destination: (%lf , %lf ) \n",latB, longB );
 printf("Air distance is %lf kms \n",d );

}
