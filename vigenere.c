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
        // validate command line is not alpha
        if (!isalpha(k[i]))
        {
            printf("Usage: ./vigenere keyword\n");
            return 1;
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
