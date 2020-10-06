#include <stdio.h>
#include <stdlib.h>

#define N 1000

struct nodes{
  int number;
  int value;
}nodes[N];

void remember_nodes(int number, int value){
  int i = 0;
  for (i = 1; i <= number; i++) {
    if (nodes[i].value == value){
      break;} else {
    if (nodes[i].value == 0) {
      nodes[i].value = value;
      nodes[i].number = i;
      break;
    }
}
  }
}

int check_node(int number,int value){
  int i = 0;
  for (i = 1; i <= number; i++) {
    if (nodes[i].value == value){
      return 1;
      break;
    } else {      return 0;    }
  }

}

void print_nodes_and_values(int number){
  int i = 0;
  FILE *fp;


  fp = fopen("gr.txt","a");
  for ( i = 1; i <= number; i++) {
  fprintf(fp, "node%d [label = \" %d \" ];\n",nodes[i].number,nodes[i].value );
  }

fclose(fp);
}


void print_connection(int count,int number1, int number2){
  int i = 0;
  int j = 0;
  FILE *fp;

  fp = fopen("gr.txt","a");
  for (i = 1; i <= count; i++) {
    for (j = 1; j <= count; j++)
  if ((number1 == nodes[i].number)&&(number2 == nodes[j].number)){
    fprintf(fp, "node%d -> node%d; \n",number1,number2 );
    }
  }
}


int main(void) {
  int value;
  int connection1 = 1;
  int i = 0;
  int connection2;
  int number;
  int k = 0;
  FILE *fp;
  fp = fopen("gr.txt","w");
  fprintf(fp, "%s\n","digraph G {" );
  fclose(fp);
  fp = fopen("gr.txt","a");

  //fprintf(fp, "%s\n","digraph G {" );

  printf("Write number of nodes \n");

  scanf("%d",&number);
  printf("Write node's values: \n");
while (k < number-1) {
//    printf("Write nodes connection \n");
    scanf("%d",&value);
    remember_nodes(number, value);
    if (check_node(number,value) == 0) {
      k++;
    }
}


    print_nodes_and_values(number);
    printf("\n Here Are you node's values: \n \n" );
    printf("|number|value| \n");
    for (i = 1; i <= number; i++) {
      printf("|  %d  |  %d  | \n",(nodes[i].number), nodes[i].value);
    }
printf("\n Write connections (write 0 to end)\n");
 while (connection1 != 0){
  scanf("%d %d\n",&connection1,&connection2);
  print_connection(number,connection1,connection2);
}

 fprintf(fp, "\n }" );
  return 0;
}
