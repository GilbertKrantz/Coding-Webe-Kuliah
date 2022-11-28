#include <stdio.h>

int main(){
  double number, sum;
  double multipler = 50;
 
 scanf("%lf", &number);
 sum = number/2*(200+(number-1)*multipler);
 
 printf("%.0lf\n",sum);
}