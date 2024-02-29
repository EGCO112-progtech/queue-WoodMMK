#include "learn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//start main function
void main(int argc, char **argv){//get counts(argc) and array of input(argv)
    
    //initialize queue
    Q orders; 
    orders.size = 0; //set size to 0
    orders.head = NULL; //create head pointer and point to NULL
    orders.tail = NULL; //create tail pointer and point to NULL

    while(1){
        int choice;
        print_current(&orders);
        printf("+----------------------+\n");
        printf("|    Select option     |\n");
        printf("+----------------------+\n");
        printf("1. NQ\n");
        printf("2. DQ\n");
        printf("3. last name\n");
        printf("0. exit\n");
        printf("------------------------\n");
        printf("input: ");
        scanf("%d", &choice);

    
        switch (choice)
        {
            case 1:
                printf("NQing\n");
                NQ(&orders);
                break ;
                
            case 2:
                printf("not implemented yet\n");
                //DQ(&orders);
                break;
            
            case 3:
                print_tail(&orders);
                printf("press Enter to continue...\n");
                getchar();
                break;

            case 0: 
                printf("exitting...\n");
                exit(1);
                break;
                
            default: 
                printf("input again\n");
                //system("clear");   
        }
        system("clear");
    }
        

    

    
    //print_tail(&orders);

    // print_size(&orders); // show number of orders
    
    /* //print all string input
    for(int i = 1; i < argc; i++ ){ 
        printf("%s ", argv[i]);
    }    
    */

    
}