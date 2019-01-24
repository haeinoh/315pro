//cstack.h
#ifndef __CSTACK_H__
#define __CSTACK_H__

#define TRUE  1
#define FALSE 0

typedef double Value;

//create struct that represents linked list node
typedef struct _node
{
  Value m_value;
  struct _node *m_next;
} Node;

// create struct that represents linked list stack
typedef struct _linkedlist
{
  Node *m_head;
} Linkedlist;

typedef Linkedlist Stack;

//Initialize stack
void stack_init(Stack *cstack);

//push 
void push(Stack *cstack, Value m_value);
//pop
Value pop(Stack *cstack);
//peek
Value peek(Stack *cstack);

//check if stack is empty or not
int is_empty(Stack *cstack);

//calculate the given expression
//expression should be postfix notation in this case
double cal_expression(char value[]);

#endif

