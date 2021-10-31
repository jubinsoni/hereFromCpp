# include <iostream>
# include <unordered_set>

using namespace std;

int gcd(int a,int b)
{
    if(a == 0)
    {
        return b;
    }

    return gcd(b%a,a);
}

bool isPrime(int n)
{
    if(n == 2)
    {
        return true;
    }

    if(n == 0 || n == 1 || n%2 == 0)
    {
        return false;
    }

    for(int i=3;i*i<=n;i=i+2)
    {
        if(n%i == 0)
        {
            return false;
        }
    }

    return true;
}

bool binary_search(int arr[],int x,int left,int right)
{
    if(left <= right)
    {
        int mid = left + ((right-left)/2);

        if(x == arr[mid])
        {
            return true;
        }
        else if(x < arr[mid])
        {
            return binary_search(arr,x,left,mid-1);
        }
        else if(x > arr[mid])
        {
            return binary_search(arr,x,mid+1,right);
        }
    }

    return false;
}

void allPair(string str,string curr,int index)
{
    if(str.length() == index)
    {
        cout << curr << " ";
        return;
    }

    allPair(str,curr,index+1);
    allPair(str,curr+str[index],index+1);
}

void permute(string str,int l,int r)
{
    if(l == r)
    {
        cout << str << " ";
    }
    else
    {
        for(int i=l;i<=r;i++)
        {
            swap(str[l],str[i]);
            permute(str,l+1,r);
            swap(str[l],str[i]);
        }
    }
}

int kadanes_algo(int arr[],int n)
{
    int max_sum_here = 0;
    int max_sum = 0;

    for(int i=0;i<n;i++)
    {
        max_sum_here = max_sum_here + arr[i];

        if(max_sum < max_sum_here)
        {
            max_sum = max_sum_here;
        }

        if(max_sum < 0)
        {
            max_sum = 0;
        }
    }

    return max_sum;
}

bool subArrayContainsSum(int arr[],int x,int n)
{
    unordered_set<int> us;
    int prefix_sum = 0;
    for(int i=0;i<n;i++)
    {
        prefix_sum = prefix_sum + arr[i];
        if(us.find(prefix_sum - x) == us.end())
        {
            us.insert(prefix_sum);
        }
        else
        {
            return true;
        }
    }

    return false;
}

int containsPairSum(int arr[],int x,int n)
{
    unordered_set<int> us;
    int prefix_sum = 0;
    for(int i=0;i<n;i++)
    {
        if(us.find(x - arr[i]) == us.end())
        {
            us.insert(arr[i]);
        }
        else
        {
            return true;
        }
    }

    return false;
}

int main()
{
    cout << "gcd(3,9) => "<< gcd(3,9) << endl;
    cout << "isPrime(7) => " << isPrime(7) << endl;
    cout << "isPrime(27) => " << isPrime(27) << endl;
    int arr1[] = {1,7,9,13,24,45};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int x1 = 24;
    cout << "binary_search(arr1,x1,0,n1-1) => " << binary_search(arr1,x1,0,n1-1) << endl;

    int arr2[] = {1,7,9,13,24,45};
    int n2 = sizeof(arr1)/sizeof(arr1[0]);
    int x2 = 23;
    cout << "binary_search(arr2,x2,0,n2-1) => " << binary_search(arr2,x2,0,n2-1) << endl;

    string str3 = "abc";
    string curr3 = "";
    int index3 = 0;
    allPair(str3,curr3,index3);
    cout << endl;

    string str4 = "abc";
    int l4 = 0;
    int r4 = str4.length()-1;
    permute(str4,l4,r4);
    cout << endl;

    int arr5[] = {2,5,-3,5,-10,2};
    int n5 = sizeof(arr5)/sizeof(arr5[0]);
    cout << "max subbaray contigious sum__kadanes_algo(arr5,n5) => " << kadanes_algo(arr5,n5) << endl;

    int arr6[] = {2,5,5,10,2};
    int x6 = 20;
    int n6 = sizeof(arr6)/sizeof(arr6[0]);
    cout << "subArrayContainsSum : subArrayContainsSum(arr6,x6,n6) => " << subArrayContainsSum(arr6,x6,n6) << endl;

    int arr7[] = {2,5,5,10,2};
    int x7 = 21;
    int n7 = sizeof(arr7)/sizeof(arr7[0]);
    cout << "subArrayContainsSum : subArrayContainsSum(arr6,x6,n6) => " << subArrayContainsSum(arr7,x7,n7) << endl;


    int arr8[] = {1,5,5,10,2};
    int x8 = 12;
    int n8 = sizeof(arr6)/sizeof(arr6[0]);
    cout << "subArrayContainsSum : containsPairSum(arr8,x8,n8) => " << containsPairSum(arr8,x8,n8) << endl;

    int arr9[] = {2,5,5,10,2};
    int x9 = 13;
    int n9 = sizeof(arr9)/sizeof(arr9[0]);
    cout << "subArrayContainsSum : containsPairSum(arr9,x9,n9) => " << containsPairSum(arr9,x9,n9) << endl;

    return 0;
}