#include "work_partition.h"


int main()
{
    int T, N, K, t, x;
    vector<int> A;
    cin >> T;
    for (t = 0; t < T; t++)
    {
        cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            cin >> x;
            A.push_back(x);
        }
        cout << partition(A, N, K) << endl;
        A.clear();
    }
    return 0;
}
