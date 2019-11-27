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
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

    // store key
    string k = argv[1];
    int h = strlen(argv[1]);
    
    // iterate over argc for arguments
    for (int i = 0; i < argc; i++)
    {
        // iterate over command line argument to find char in string
        for (int j = 0, n = strlen(argv[i]); j < n; j++)
        {
            // iterate over command line argv1 string
            for (int key = 0; key < h; key++)
            {
                // validate command line is not alpha
                if (!isalpha(argv[1][key]) || k < 0)
                {
                    printf("Usage: ./vigenere keyword\n");
                    return 1;
                }
            }
        }
    }
    
    // prompt user for string
    string s = get_string("plaintext: ");
    printf("ciphertext: ");

    // iterate over plain text
    for (int i = 0, j = 0, n = strlen(s); i < n; i++)
    {
        // keep uppercase
        if (isalpha(s[i]))
        {
            // cipher only alpha characters
            if (islower(s[i]))
            {
                printf("%c", (s[i] - 'a' + toupper(k[j]) - 'A') % 26 + 'a');
            }
            
            // keep uppercase
            else if (isupper(s[i]))
            {
                printf("%c", (s[i] - 'A' + toupper(k[j]) - 'A') % 26 + 'A');
            }
            j = (j + 1) % h;
        }
        // non-alpha char
        else 
        {
            printf("%c", s[i]);
        } 
    }
    printf("\n");    
}
