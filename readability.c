#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(void)
{
    // declaring variables
    int l = 0, w = 1, s = 0;
    float index = 0.0;
    //Getting the string from the user
    string text = get_string("Text: ");

    // setting up a for loop to go through each of the character in the string
    // we would compare this with the ascii characters
    for (int i = 0; i <= strlen(text); i++)
    {
        // counting the letters in the variable l
        if((text[i] > 64 && text[i] < 91) || (text[i] > 96 && text[i] < 123))
        {    
            l += 1;
        }
        // counting the words in variable w
        if(text[i] == 32)
        {
            w += 1;
        }
        // counting the sentences in the variable s
        if(text[i] == 63 || text[i] == 33 || text[i] == 46)
        {
            s += 1;
        }

    }
    // printing all the 3
    //printf("%d letter(s)\n", l);
    //printf("%d word(s)\n", (w+1) );
    //printf("%d sentence(s)\n", s);

    // calculating the index value for grade determination
    index = (0.0588 * ((float)l/(float)w*100.0)) - (0.296 * ((float)s/(float)w*100.0)) - 15.8;

    // giving print statement for grades
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %.f\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
    

}