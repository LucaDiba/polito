#include <stdio.h>
#include <stdlib.h>
#include "Item.h"
#include "ST.h"

int main(int argc, char *argv[]) {
  if (argc !=2) {
    printf("Error in command line, correct format: \n");
    printf("client <maximun number of data> \n");
    exit(1);
  }

  int i, j, cont;
  int maxN = atoi(argv[1]);
  Item data;
  Key k;
  ST st;
  st = STinit(maxN);

  cont = 1;
  while(cont) {
    printf("\nOperations on Symbol Tables \n");
    printf("===============\n");
    printf("1.Insert item \n");
    printf("2.Search for key \n");
    printf("3.Delete key \n");
    printf("4.Display Symbol Table \n");
    printf("5.Display Symbol Table Size \n");
    printf("6.Destroy Symbol Table \n");
    printf("7.Exit\n");
    printf("Enter your choice : ");
    if(scanf("%d",&i)<=0) {
      printf("Integers only!\n");
      exit(0);
    }
    else {
      switch(i) {
        case 1:     printf("\nEnter data: \n");
                    data = ITEMscan();
                    if (STsearch(st, KEYget(data))== -1)
                      j = STinsert(st, data);
                    break;
        case 2:     printf("\nEnter key: \n");
                    k = KEYscan();
                    j = STsearch(st, k);
                    if (j != -1)
                      printf("key found at index %d!\n", j);
                    else
                      printf("key not found!\n");
                    break;
        case 3:     printf("\nEnter key: \n");
                    k = KEYscan();
                    if (STsearch(st, k) == -1)
                      printf("data not found!\n");
                    else
                      STdelete(st, k);
                    break;
        case 4:     if (st==NULL)
                      printf("Symbol table doesn't exist!\n");
                    else
                      if (STcount(st)==0)
                        printf("\nSymbol Table empty!\n");
                      else
                        STdisplay(st);
                    break;
        case 5:     if (st==NULL)
                      printf("Symbol table doesn't exist!\n");
                    else if (STcount(st)==0)
                        printf("\nSymbol Table empty!\n");
                    else
                      printf("\nThe Symbol Table contains %d distinct data\n", STcount(st));
                    break;
        case 6:     printf("\nSymbol Table destroyed!\n");
                    STfree(st);
                    cont = 0;
                    break;
        case 7:     cont = 0;
                    break;
        default:    printf("\nInvalid option\n");
      }
    }
  }
  return 0;
}
