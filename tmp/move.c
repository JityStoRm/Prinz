#include <stdio.h>
#include <stdlib.h>
#include "Fpga.h"
#include <math.h>

#define Gear (57.2*600)

int main(int argc, char *argv[])
{
int i;
double PosL, PosR;
double VcL, VcR;
double Kp = 1.0;
double targetL = 10, targetR = 10;

FpgaStop();
FpgaInit(23);
for(i=1; i<=4; i++) FpgaPutDuty(i, 0.0);

printf("%f %f\n", PosL,PosR);
/*.
 PosL = FpgaGetCounter(2)/1.0;
 PosR = FpgaGetCounter(3)/1.0;
 printf("%8f %8f\n", PosL, PosR);

FpgaPutDuty(2, atof(argv[1]));
FpgaPutDuty(3, atof(argv[2]));
.*/
for(i=0; i<10*1000; i++)
{
PosL=FpgaGetCounter(2)*(2.0*M_PI/Gear);
PosR=-FpgaGetCounter(3)*(2.0*M_PI/Gear);

VcL=Kp*(targetL-PosL);
VcR=Kp*(targetR-PosR);

FpgaPutDuty(2,-VcL);
FpgaPutDuty(3,VcR);
usleep(500);

}
printf("%f %f\n",PosL,PosR);
for(i=1; i<=4; i++) FpgaPutDuty(i, 0.0);

usleep(1000);

FpgaStop();

return 0;
}
