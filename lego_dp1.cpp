# include <iostream>

using namespace std;

int max(int a ,int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}

int knapSack(int W,int wt[],int val[],int n)
{
    if(W == 0 || n == 0)
    {
        return 0;
    }

    int lastIndex = n-1;

    if(wt[lastIndex] > W)
    {
        return 0 + knapSack(W-0,wt,val,n-1);
    }
    else //if(wt[lastIndex] <= W)
    {
        return max( val[lastIndex] + knapSack(W-wt[lastIndex],wt,val,n-1), 
                    0 + knapSack(W-0,wt,val,n-1));
    }
}

int unboundedKnapSack(int W,int wt[],int val[],int n)
{
    if(W == 0 || n == 0)
    {
        return 0;
    }

    int lastIndex = n-1;

    if(wt[lastIndex] > W)
    {
        return 0 + unboundedKnapSack(W-0, wt, val, n-1);
    }
    else //if(wt[lastIndex] <= W)
    {
        return max(val[lastIndex] + unboundedKnapSack(W-wt[lastIndex], wt, val, n)
                ,0 + unboundedKnapSack(W-0, wt, val, n-1)) ;
    }
}

bool isSubSetSum(int wt[],int W,int n)
{
    if(W < 0)
    {
        return false;
    }

    if(n == 0 && W > 0)
    {
        return false;
    }

    if(n == 0 && W == 0)
    {
        return true;
    }

    int lastIndex = n-1;

    if(wt[lastIndex] > W)
    {
        return isSubSetSum(wt,W-0,n-1);
    }
    else
    {
        return isSubSetSum(wt,W-wt[lastIndex],n-1) || isSubSetSum(wt,W-0,n-1);
    }
}

int maxWayCoin(int wt[],int W,int n)
{
    if(W < 0)
    {
        return 0;
    }

    if(n == 0 && W > 0)
    {
        return 0;
    }

    if(n == 0 && W == 0)
    {
        return 1;
    }

    int lastIndex = n-1;

    if(wt[lastIndex] > W)
    {
        return maxWayCoin(wt,W-0,n-1);
    }
    else
    {
        return maxWayCoin(wt,W-wt[lastIndex],n) + maxWayCoin(wt,W-0,n-1);
    }
}

int main()
{
    int wt1[] = { 15, 20, 30 };
    int val1[] = { 60, 100, 120 };
    int W1 = 60;
    int n1 = sizeof(wt1) / sizeof(wt1[0]);
    cout << knapSack(W1, wt1, val1, n1) << endl; // wt{30 + 20}
    cout << unboundedKnapSack(W1, wt1, val1, n1) << endl; // wt{20 + 20 + 20}

    int wt2[] = {3, 34, 4, 12, 5, 2}; 
    int n2 = sizeof(wt2) / sizeof(wt2[0]);
    int sum2 = 9;
    cout << "isSubSetSum => " << isSubSetSum(wt2,sum2,n2) << endl;

    int ch[] = {2, 5, 3, 6}; 
    int n3 = sizeof(ch) / sizeof(ch[0]);
    int sum3 = 10;
    cout << "maxWayCoin => " << maxWayCoin(ch,sum3,n3) << endl; //5 ways={2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}

    return 0;
}