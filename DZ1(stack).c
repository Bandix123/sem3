#include <stdio.h>
#include <stdlib.h>

 struct stack {
    struct stack* next;
    int value;
  } *stack_t;


struct stack* push(struct stack* head, int new_value){
    struct stack* add = (struct stack*)malloc(sizeof(struct stack));
    if (add == NULL) {
      exit(69);
    }
    add->value = new_value;
    add->next = head;
    return add;
}


struct stack* pop(struct stack* temp){
  if (temp == NULL){
    printf("stack is empty \n");
  } else{
    struct stack* delete = temp;
    temp = temp->next;
    free(delete);
}
  return temp;
}

void print_stack(struct stack* temp){
   if (temp == NULL){
    printf("stack is empty \n");
  }
  while (temp != NULL) {
    printf("%d ",temp->value);
    temp = temp->next;
  }

}


int  main(void) {
  struct stack* head = NULL;
  int choice = 0;
  int a = 0;
  while (choice != 4){
    printf("What do you want to do? \n 1- push \n 2- pop \n 3- view \n 4-exit \n");
    scanf("%d",&choice);
    switch (choice) {

      case 1: printf("Write the number \n");
              scanf("%d",&a);
              head = push(head, a);
              break;
      case 2: head = pop(head);
              break;
      case 3:
              print_stack(head);
              printf("\n");
              break;
      case 4:
              choice = 4;
              break;
    }

  }



  return 0;
}
