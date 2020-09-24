#include <stdio.h> 
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

// function prototype declaration
bool check_arg(string); // to check if 2nd argument of the command line is a integer
int main(int argc, string argv[])
{

    // prompt user for the correct command line argument
    // there should be only 2 arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    // checking if 2nd argument is a integer
    else
    {
        // 2nd argument is not a integer
        if (check_arg(argv[1]) == false)
        {
            // print error message
            printf("Usage: ./caesar key\n");
            return 1;

        }
        // 2nd argument is a integer
        // write code here
        else
        {
            // start code for caesar
            // get plaintext to be in var pt
            string pt = get_string("plaintext: ");
            // declaring var k to store the key i.e. the command line argument
            int k = atoi(argv[1]);
            printf("ciphertext: ");

            // logic start
            for (int i = 0; i < strlen(pt); i++)
            {
                int x = 0;
                if (pt[i] > 64 && pt[i] < 91)
                {
                    x = ((int)(pt[i]) - 65 + k) % 26;
                    //x += k;
                    x += 65;
                    printf("%c", x);
                }
                else if (pt[i] > 96 && pt[i] < 123)
                {
                    x = ((int)(pt[i]) - 97 + k) % 26;
                    //x += k;
                    x += 97;
                    printf("%c", x);
                }
                else
                {
                    printf("%c", pt[i]);
                }
            }
            printf("\n");


        }

    }
}


// funnction defination
bool check_arg(string a)
{
    //int len_a = strlen(a); printf("String %s lenght is : %d\n", a, len_a);

    // for strlen > 1
    if (strlen(a) > 1)
    {
        for (int i = 0; i < strlen(a); i++)
        {
            if (a[i] > 47 && a[i] < 58)
            {
                continue;
            }
            else
            {
                return false;
                break;
            }
        }
        return true;

    }
    // for strlen = 1
    else
    {
        if (a[0] > 47 && a[0] < 58)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    return 0;
}