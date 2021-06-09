//Recursive approach.Time compleity is exponential

int solve(int arr[],int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=solve(arr,i,k),solve(arr,k+1,j)+arr[i-1]*arr[k]*rr[j];
        if(temp<min)
        {
            min=temp;
        }
    }
    return min;
}


//Memoization approach

int static t[1001][1001];

int solve(int arr[],int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(t[i][j]!=-1)
    {
        return t[i][j];
    }
    int min=INT_MAX;
    for(int k=i;k<=j-1;k++)
    {
        int temp=solve(arr,i,k),solve(arr,k+1,j)+arr[i-1]*arr[k]*rr[j];
        if(temp<min)
        {
            min=temp;
        }
    }
    return t[i][j]=min;
}
int main()
{
    memset(t,-1,sizeof(t));
}