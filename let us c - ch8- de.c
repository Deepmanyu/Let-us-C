//function to write the prime factors of a number

#include <stdio.h> 

int prime (int);  // function called be main() - further calls power() and is_prime_num
int power (int, int); //function called by prime() - How many powers is the prime number raised to. Then print the prime                          number that many times 
int is_prime_num (int); //function called by prime() - to check if the number is prime. Only if the number is prime we                              would go and check what power is it raised to so as to print it that many number of times

int main()
{
    int a;
    printf("Number :");
    scanf(" %d", &a);

    printf("Prime fators of %d are: ", a); 
    prime(a);
    // just to write the number itself if its a prime number
    if (a==is_prime_num(a))
        printf("%d", a);
    printf("\n");
    return 0;
}


// function definations 

//prime 
int prime (int x)
{
    for(int i=2; i<x; i++)
    {
        int is_prime = is_prime_num(i); //prime(i) is a function that gives a prime number)
        //printf("%d", is_prime);
        if(i==is_prime)
        {
            if(x%i==0 )
            {
                //function for power
                power(x, i);
            }
            else
                continue;
        }
    }
    return 0;
}

//power
int power (int x, int y) // done 
{
    int x_n=x;
    for(int i=0; x_n%y==0 ;i++)
    {
        printf("%d ", y);
        x_n/= y;
    }
    return 0;
}

int is_prime_num (int x) // done
{
    if (x==2)
        return (x);
    else
    {
        for(int i=2; i<x; i++)
        {
            if(x%i==0)
            {    
                return 0;
                break;
            }
            else
                continue;
        }
        return (x);
    }
}

