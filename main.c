//main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cstack.h"
#include "convert.h"

int main(void)
{
  //get values
  char value[50];
  //store values in the temp array
  char temp[50];
  int count = 0;

  while(scanf("%s", value) == 1)
  {
    size_t length = strlen(value);

    //printf("counting the number : %d \n", count);

    for(int i = 0; i < length; i++)
    {
      temp[count] = value[0];
    }
    count = count + 1;
  }
    //Check if the last element is one of the math operaotrs
    char last_element = temp[count-1];

    // if it is postfix, then call calculate function 
    if(last_element == '+' || last_element == '-' || 
        last_element == '*' || last_element == '/' )
    {
      cal_expression(temp);
      printf("%.2f\n", cal_expression(temp));
    }
    else
    {
      //else then call convert_to_postifix function first
      convert_to_postfix(temp);
      printf("%.2f\n", cal_expression(temp));
    }

  return 0;
}
