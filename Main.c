#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StrList.h"

#define MAX 100

int main()
{
    int option = 0;
    int wordsamount = 0;
    int index;
    char word[MAX];

    StrList *list = StrList_alloc();


    do{
    // Get user input for option
    scanf("%d", &option);

    // Switch case for 14 options
    switch (option) 
    {
        case 0:
            exit(0);
            break;
        case 1:
            // Code for option 1
            scanf("%d", &wordsamount);
            for (size_t i = 0; i < wordsamount; i++)
            {
                scanf("%s", word);
                StrList_insertLast(list, word);
            }
            break;
        case 2:
            // Code for option 2
            scanf("%d", &index);
            scanf("%s", word);
            StrList_insertAt(list, word, index);
            break;
        case 3:
            // Code for option 3
            StrList_print(list);
            printf("\n");
            break;
        case 4:
            // Code for option 4
            printf("%zu \n", StrList_size(list));
            break;
        case 5:
            // Code for option 5
            scanf("%d", &index);
            StrList_printAt(list, index);
            break;
        case 6:
            // Code for option 6
            printf("%d \n", StrList_printLen(list));
            break;
        case 7:
            // Code for option 7
            scanf("%s", word);
            printf("%d \n", StrList_count(list, word));
            break;
        case 8:
            // Code for option 8
            scanf("%s", word);
            StrList_remove(list, word);
            break;
        case 9:
            // Code for option 9
            scanf("%d", &index);
            StrList_removeAt(list, index);
            break;
        case 10:
            // Code for option 10
            StrList_reverse(list);
            break;
        case 11:
            // Code for option 11
            StrList_free(list);
            break;
        case 12:
            // Code for option 12
            StrList_sort(list);
            break;
        case 13:
            // Code for option 13
            if (StrList_isSorted(list))
                printf("true\n");
            else
                printf("false\n");
            break;
        default:
            printf("Invalid option\n");
            break;
    }
    }
    while (option != 0);
    
    StrList_free(list);
    return 0;
}