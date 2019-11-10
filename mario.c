#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    
    do 
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    
   
    
    if (n == 1)
    {
        printf("#\n");
    }
            
        
    else if (n == 2)
    {
        printf(" "); printf("#\n");
        printf("##\n");
    }
    
    else if (n == 3)
    {
        printf(" "); printf(" "); printf("#\n");
        printf(" "); printf("##\n");
        printf("###\n");
    }
    
    else if (n == 4)
    {
        printf(" "); printf(" "); printf(" "); printf(" #\n");
        printf(" "); printf(" "); printf("##\n");
        printf(" "); printf("###\n");
        printf("####\n");
    }
    
    else if (n == 5)
    {
        printf(" "); printf(" "); printf(" "); printf(" "); printf("#\n");
        printf(" "); printf(" "); printf(" "); printf("##\n");
        printf(" "); printf(" "); printf("###\n");
        printf(" "); printf("####\n");
        printf("#####\n");
    }
    
    else if (n == 6)
    {
        printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf("#\n");
        printf(" "); printf(" "); printf(" "); printf(" "); printf("##\n");
        printf(" "); printf(" "); printf(" "); printf("###\n");
        printf(" "); printf(" "); printf("####\n");
        printf(" "); printf("#####");
        printf("######\n");
    }
    
    else if (n == 7)
    {
        printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf(" #\n");
        printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf("##\n");
        printf(" "); printf(" "); printf(" "); printf(" "); printf("###\n");
        printf(" "); printf(" "); printf(" "); printf("####\n");
        printf(" "); printf(" "); printf("#####\n");
        printf(" "); printf("######\n");
        printf("#######\n");
    }
    
    else if (n == 8)
    {
        printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf("#\n");
        printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf("##\n");
        printf(" "); printf(" "); printf(" "); printf(" "); printf(" "); printf("###\n");
        printf(" "); printf(" "); printf(" "); printf(" "); printf("####\n");
        printf(" "); printf(" "); printf(" "); printf("#####\n");
        printf(" "); printf(" "); printf("######\n");
        printf(" "); printf("#######\n");
        printf("########\n");
    }
    
}


 
