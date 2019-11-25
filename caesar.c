#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

// Start by getting command line argument
int main(int argc, string argv[])
{
    // check if argc is only 2
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // store interger in key
    int k = atoi(argv[1]);

    // iterate over argc for arguments
    for (int i = 0; i < argc; i++)
    {
        // iterate over command line argument to find char in string
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            // iterate over command line argv1 string
            for (int key = 0, h = strlen(argv[1]); key < h; key++)
            {
                // validate command line is not alpha
                if (!isdigit(argv[1][key]) || k < 0)
                {
                    printf("Usage: ./caesar key\n");
                    return 1;
                }
            }
        }
    }

    // prompt user for string
    string s = get_string("plaintext: ");
    printf("ciphertext: ");

    // iterate over plain text
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // keep uppercase
        if (!islower(s[i]))
        {
            // cipher only alpha characters
            if (isalpha(s[i]))
            {
                char c = (s[i] + k - 65) % 26;
                
                printf("%c", c + 65);
            }
            
            // non-alpha char
            else 
            {
                printf("%c", s[i]);
            }
        }

        // keep lowercase
        else if (!isupper(s[i]))
        {
            // cipher only alpha characters
            if (isalpha(s[i]))
            {
                char c = (s[i] + k - 97) % 26;
                
                printf("%c", c + 97);                       
            }
            
            // non-alpha char
            else 
            {
                printf("%c", s[i]);
            }
        }
    }
    printf("\n");    
}
