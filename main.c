
#include <stdio.h>
#include<stdarg.h>
#include <stdlib.h>
#include <math.h>



int sum(int NrNums,...){
int result=0;

va_list ap;
int i;

    va_start(ap,NrNums);

    for(i=0;i<NrNums;i++){
      result=result+va_arg(ap,int);
    }
    va_end(ap);

return result;

}

int main()
{
    //printf("Hello world!\n");
    //printf("1+2+3+4+5+6=%d\r\n",sum(6,1,2,3,4,5,6));
    int data[3]={0x00,0x00,0x10};
    float r = 0;
    float t = 0;
    long Data22Bits = 0;

    r = data[0]*256 + data[1];
    r = r*6800.0/(pow(2,21)-r);
    t += -242.02;
    t += 2.2228*r;
    t += 2.5859*pow(10,-3)*r*r;
    t += -4.8260*pow(10,-6)*r*r*r;
    t += -2.8183*pow(10,-8)*r*r*r*r;
    t += 1.5243*pow(10,-10)*r*r*r*r*r;

    //printf(" temperature is %f.\r\n",t);
    if((data[0] & 0x20) >> 5){//negative number
//           Data22Bits  = (~(data[0] && 0x1F)) << 16 ;
//           Data22Bits |= (~data[1]) << 8;
//           Data22Bits |= (~data[2]);
//           Data22Bits += 1;
 	Data22Bits = ((data[0] | 0xffff) << 16 )|
                                    (data[1] << 8)|
                                        (data[2]);

    }
    else{//positive number
			Data22Bits = ((data[0] & 0x3F) << 16 )|
                                    (data[1] << 8)|
                                        (data[2]);
    }

   printf(" Data22Bits is 0x%x  %d \r\n",Data22Bits, Data22Bits);

   if(data[3]>0)     printf("data[3]>0\r\n")

    return 0;
}
