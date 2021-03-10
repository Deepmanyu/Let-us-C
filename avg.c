// calculating avg using function, array

#include <stdio.h> 

float avg1(int n , int avg_array[]); 

int main()
{
    int n;
    printf("Enter the number of scores:");
    scanf("%d", &n);
    int scores[n];
    
    for(int i = 0; i<n; i++) 
    {
        printf("Score%d : ", i + 1 );
        scanf("%d", &scores[i]);
    } 
    printf("The average is : %.1f\n", avg1(n , scores));
}

float avg1(int n , int avg_array[])
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += avg_array[i];
    }
    return (float) sum/n;
    
}

