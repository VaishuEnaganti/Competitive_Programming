#include "work_partition.h"

// Finds the maximum of an array, here I am finding the task
// that takes highest amount of time to complete
int getmax(const vector<int>& A, int N)
{
    // Initializing the max to the smallest integer value
    int max = INT_MIN;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
}

// This function calculates the total time required to complete
// all tasks
int getsum(const vector<int>& A, int N)
{
    int total = 0;
    for (int i = 0; i < N; i++)
    {
        total = total + A[i];
    }
    return total;
}

// This function calculates the number of workers needed to
// complete the work
int getrequiredworkers(const vector<int>& A, int N, int mlp)
{
    int total = 0;
    int numworkers = 1;
    for (int i = 0; i < N; i++)
    {
        total = total + A[i];

        if (total > mlp)
        {
            numworkers++;
            total = A[i];
        }
    }
    return numworkers;
}

// This fuctin calculates the amount of work that can be
// alloted to a worker using Binary search algorithm
int partition(const vector<int>& A, int N, int K)
{
    int low = getmax(A, N);
    int high = getsum(A, N);
    while (low < high)
    {
        int middle = low + (high - low)/2;
        int workers = getrequiredworkers(A, N, middle);
        if (workers > K)
        {
            low = middle + 1;
        }
        else
        {
            high = middle;
        }
    }
    return low;
}
