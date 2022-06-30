
int canReach(int A[], int N)
{

    int jumps[N];
    jumps[N - 1] = 0;
    for (int i = N - 2; i >= 0; i--)
    {
        if (A[i] == 0)
        {
            jumps[i] = INT_MAX;
        }
        else if (i + A[i] >= N - 1)
        {
            jumps[i] = 1;
        }
        else
        {
            int mini = INT_MAX;
            for (int j = i + 1; j < N && j <= A[i] + i; j++)
            {
                if (mini > jumps[j])
                {
                    mini = jumps[j];
                }
            }
            if (mini != INT_MAX)
            {
                jumps[i] = mini + 1;
            }
            else
            {
                jumps[i] = INT_MAX;
            }
        }
    }
    if (jumps[0] != INT_MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
}