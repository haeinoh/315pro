//cstack.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cstack.h"

//Initialize stack 
void stack_init(Stack *cstack)
{
  // m_head intialize NULL
  cstack->m_head = NULL;  
}

//create new node and store the value into the new node
void push(Stack *cstack, Value m_value)
{
  //create new node
  Node *new_node = (Node*)malloc(sizeof(Node));

  //store the value into the new node
  new_node->m_value = m_value;
  //new node will point next node 
  new_node->m_next = cstack->m_head;

  //pointer m_head will point new node
  cstack->m_head = new_node;
}

//pop up the value from the node 
//return the value 
Value pop(Stack *cstack)
{
  Value data;
  Node *tmp;

  if(is_empty(cstack))
  {
    printf("Stack is empty");
    exit(-1);
  }

  //store node's value into the temp variable which I want to pop up
  data = cstack->m_head->m_value;
  //store node's head into the temp variable which I want to pop up
  tmp = cstack->m_head;

  //head will point to the next node
  cstack->m_head = cstack->m_head->m_next;

  //delete the tmp node
  free(tmp);

  //poped up the value 
  return data;
}

//peek
Value peek(Stack *cstack)
{
  if(is_empty(cstack))
  {
    printf("Stack is empty");
    exit(-1);
  }
  
  return cstack->m_head->m_value;
}

//check if the stack is empty or not
int is_empty(Stack *cstack)
{
   if(cstack->m_head == NULL)
     return TRUE;
   else return FALSE; 
}

//Calculate the expression 
double cal_expression(char value[])
{
  Stack stack;
  int length = strlen(value);

  double a, b, result;
  char ch, op1, op2; 

  stack_init(&stack);

  for(int i = 0; i < length; i++)
  {
    //store the each value into the 'ch' variable
    ch = value[i];

    //if the value is digit
    if(isdigit(ch))
    {
      //convert it to the number and push it into the stack
      push(&stack, ch - '0');
    }
    else  //else if it is operator 
    {
      //calculate and push the result into the stack
      if(ch == '+')
      {
        a = pop(&stack);
        b = pop(&stack);
        result = a + b;
        push(&stack, result);
      }
      else if(ch == '-')
      {
        a = pop(&stack);
        b = pop(&stack);
        result = b - a;
        push(&stack, result);
      }
      else if(ch == '*')
      {
        a = pop(&stack);
        b = pop(&stack);
        result = a * b;
        push(&stack, result);
      }
      else if(ch == '/')
      {
        a = pop(&stack);
        b = pop(&stack);
        //if a is 0, it cannot be calculated
        if(a == 0)
          printf("this is error \n");
        else
        {
          result = b / a;
          push(&stack, result);
        }
      }
    }
  }
  //pop up the result from the stack and return it 
  return pop(&stack);
}
