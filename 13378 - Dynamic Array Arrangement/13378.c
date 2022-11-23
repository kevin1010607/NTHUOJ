#include <stdio.h>

#include "function.h"

void InsertValuesInArray(int **ary, int size);

int main()
{
    int *m_ary;

    int m_ary_size;
    scanf("%d", &m_ary_size);

    DynamicallySetArraySize(&m_ary, m_ary_size);
    InsertValuesInArray(&m_ary, m_ary_size);
    PrintArray(m_ary, m_ary_size);

    return 0;
}

void InsertValuesInArray(int **ary, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &(*ary)[i]);
    }
}