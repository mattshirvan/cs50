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
        // print error
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    // store key
    string k = argv[1];
    int h = strlen(k);
    
    // iterate over argc for arguments
    for (int i = 0; i < h ; i++)
    {
        // validate command line is alpha
        if (!isalpha(k[i]))
        {
            // print error
            printf("Usage: ./vigenere keyword\n");
            return 1;
        }
    }
   
    // prompt user for string
    string s = get_string("plaintext: ");
    printf("ciphertext: ");

    // iterate over plain text
    for (int i = 0, n = 0, j = strlen(s); i < j; i++)
    {
        // keep uppercase
        if (isalpha(s[i]))
        {
            // cipher only alpha characters
            if (islower(s[i]))
            {
                printf("%c", (s[i] - 'a' + toupper(k[n]) - 'A') % 26 + 'a');
            }
            
            // keep uppercase
            else if (isupper(s[i]))
            {
                printf("%c", (s[i] - 'A' + toupper(k[n]) - 'A') % 26 + 'A');
            }
            n = (n + 1) % h;
        }
        // non-alpha char
        else 
        {
            printf("%c", s[i]);
        }                     
    }
    printf("\n");    
}
