#include "sort.h"

/**
 * lomuto_partition - Partitionne le tableau selon le schéma de Lomuto
 * @array: Tableau à trier
 * @low: Indice de début de la partition
 * @high: Indice de fin de la partition (pivot)
 * @size: Taille du tableau
 *
 * Return: Indice du pivot après partitionnement
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                print_array(array, size);
            }
        }
    }
    if (array[i + 1] != array[high])
    {
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;
        print_array(array, size);
    }
    return (i + 1);
}

/**
 * quick_sort_helper - Fonction récursive pour appliquer le tri rapide
 * @array: Tableau à trier
 * @low: Indice de début de la partition
 * @high: Indice de fin de la partition
 * @size: Taille du tableau
 */
void quick_sort_helper(int *array, int low, int high, size_t size)
{
    if (low < high)
    {
        int pivot_index = lomuto_partition(array, low, high, size);

        quick_sort_helper(array, low, pivot_index - 1, size);
        quick_sort_helper(array, pivot_index + 1, high, size);
    }
}

/**
 * quick_sort - Fonction principale pour le tri rapide
 * @array: Tableau à trier
 * @size: Taille du tableau
 */
void quick_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    quick_sort_helper(array, 0, size - 1, size);
}
