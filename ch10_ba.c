// calculate sum of digits of a 5 digit number with and without
// recursion

#include <stdio.h>

//function without recursion
void without_rec (int);
//function with recursion
int with_rec (int);

int main ()
{
    unsigned short int number;
    printf("Enter the 5 digit number: ");
    scanf("%hu", &number);

    //function call for result of without recursion
    without_rec(number);

    //function call for result of with recursion
    int a = with_rec(number);
    printf("The sum with recursion is : %d\n", a);

    return 0;
}

// without_rec - function defination
void without_rec (int number)
{
    // to do
    int rem_of_num = 0 , progressive_sum = 0;
    while (number != 0)
    {
        rem_of_num = number % 10;
        progressive_sum += rem_of_num;
        number /= 10;
    }
    printf("The sum without recursion is : %d\n", progressive_sum);
}

//with_rec - function defination
int with_rec (int number)
{
    // to do
    int static rem_of_num = 0 ;
    static int progressive_sum = 0;


    if (number != 0)
    {
        rem_of_num = number % 10;
        progressive_sum = rem_of_num + with_rec(number/10);
    }
    return progressive_sum;

}