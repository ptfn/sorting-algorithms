#include <stdint.h>
#include "sort.h"

void swap(int64_t *x, int64_t *y)
{
    uint64_t temp = *x;
    *x = *y;
    *y = temp;
}

uint64_t minimum(int64_t array[], uint64_t length, uint64_t index)
{
    uint64_t min = index;
    for (uint64_t i = index; i < length; i++)
        if (array[i] < array[min])
            min = i;
    return min;
}

void bubble_sort(int64_t array[], uint64_t length)
{
    for (uint64_t i = 0; i < length-1; i++)
        for (uint64_t j = 0; j < length-1; j++)
            if (array[j] > array[j+1])
                swap(&array[j], &array[j+1]);
}

void choice_sort(int64_t array[], uint64_t length)
{
    for (uint64_t i = 0; i < length; i++) {
        uint64_t index = minimum(array, length, i);
        swap(&array[i], &array[index]);
    }
}

void insert_sort(int64_t array[], uint64_t length)
{
    for (uint64_t i = 1; i < length; i++) {
        for (uint64_t j = i; array[j-1] > array[j] && j > 0; j--)
            swap(&array[j-1], &array[j]);
    }
}

void quick_sort(int64_t array[], uint64_t left, uint64_t right)
{
    uint64_t i = left, j = right;
    uint64_t pivot = array[(left + right) / 2];

    while (i <= j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            swap(&array[i], &array[j]);
            i++; j--;
        }
    }

    if (left < j)
        quick_sort(array, left, j);
    if (i < right)
        quick_sort(array, i, right);
}

void shell_sort(int64_t array[], uint64_t length) 
{
    for (uint64_t s = length / 2; s > 0; s /= 2)
        for (uint64_t i = s; i < length; ++i)
            for (uint64_t j = i - s; j >= s && array[j] > array[j+s]; j -= s)
                swap(&array[j+s], &array[j]);
}
