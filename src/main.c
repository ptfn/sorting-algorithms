#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "sort.h"

#define LENGTH 5000

void generate_array(uint64_t array[], uint64_t length)
{
    srand(time(0));
    for (uint64_t i = 0; i < length; i++)
        array[i] = rand() % length + 1;
}

void print_array(uint64_t array[], uint64_t length)
{
    for (uint64_t i = 0; i < length; i++)
        if (i % 20 != 0)
            printf("%ld\t", array[i]);
        else
            putchar('\n');
    putchar('\n');
}

void timer_function(uint64_t array[], uint64_t length, const char* name, void(*f)(int64_t[], uint64_t))
{
    double time;
    time_t start, end;

    generate_array(array, length);
    start = clock();
    if (strcmp(name, "Quick") == 0)
        quick_sort(array, 0, length);
    else
        (*f)(array, length);
    end = clock();
    time = (double)(end-start)/CLOCKS_PER_SEC;
    printf("%s\t%lf\n", name, time);
}

int main()
{
    uint64_t array[LENGTH];
    
    printf("Length - %d\n\n", LENGTH);
    
    timer_function(array, LENGTH, "Bubble", bubble_sort);
    timer_function(array, LENGTH, "Choice", choice_sort);
    timer_function(array, LENGTH, "Insert", insert_sort);
    timer_function(array, LENGTH, "Quick", bubble_sort);
    timer_function(array, LENGTH, "Shell", shell_sort);

    return 0;
}