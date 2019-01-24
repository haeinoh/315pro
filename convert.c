#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "cstack.h"

int get_operator(char op)
{
  //check each operator's precedence
  switch(op)
  {
    case '*':
    case '/':
      return 5; //the highest precedence
    case '+':
    case '-':
      return 3; //middle
    case '(':
      return 1; //the lowest precedence operator
  }
  //it is not proper operator 
  return -1;
}

//compare two operator's precedence
int compare_operator(char op1, char op2)
{
  int op1_pre = get_operator(op1);
  int op2_pre = get_operator(op2);

  if(op1_pre > op2_pre)
    return 1;
  else if(op1_pre < op2_pre)
    return -1;
  else 
    return 0;
}

void convert_to_postfix(char value[])
{
  Stack stack;
  int length = strlen(value);
 
  //create new char array to store the convert things
  char *convert_exp = (char*)malloc(length+1);

  int index = 0;
  char ch, pop_op;

  //make new array initialize as 0
  memset(convert_exp, 0 , sizeof(char)*length+1);
  //initialize the stack
  stack_init(&stack);
 
  for(int i = 0; i < length; i++)
  {
    //store each value into the 'ch' variable
    ch = value[i];

    //check if it is number or not
    if(isdigit(ch))
    {
      //store the value into the new array 
      convert_exp[index++] = ch;
    }
    else
    {
      switch(ch)
      {
        //push it to the stack
        case '(':
          push(&stack, ch);
          break;
        //recursive
        case ')':
          while(1)
          {
            //pop up the operator until meet '(' operator
            pop_op = pop(&stack);
            if(pop_op == '(')
              break;
            //store it into the new array 
            convert_exp[index++] = pop_op;
          }
          break;
        case '+': case '-':
        case '*': case '/':
          while(!is_empty(&stack) && compare_operator(peek(&stack), ch) >= 0)
            convert_exp[index++] = pop(&stack);
          push(&stack, ch);
          break;
      }
    }
  }

  while(!is_empty(&stack))
    convert_exp[index++] = pop(&stack);

  strcpy(value, convert_exp);
  free(convert_exp);
}
