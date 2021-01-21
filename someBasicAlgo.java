package learn;

import java.util.*;

public class Fifth 
{
	public static void main(String args[])
	{
		int arr1[] = {2,10,6,8,9};
		System.out.println("subArrayContainSum => " + subArrayContainSum(arr1,24));
		System.out.println("arrayContainsPairSum => " + arrayContainsPairSum(arr1,12));
		int arr2[] = {-2,10,-6,8,-1};
		System.out.println("maxSubArraySum => " + maxSubArraySum(arr2));
		int arr3[] = {1,6,7,8,10};
		int x3 = 8;
		System.out.println("binarySearch => " + binarySearch(arr3,x3,0,arr3.length-1));
		System.out.println("----");
		int value1[] = {60,100,120};
		int weight1[] = {10,20,30};
		int W1 = 50;
		System.out.println("knapsack =>" + knapsack(value1,weight1,W1,value1.length));
		
		int value2[] = {10, 40, 50, 70};
		int weight2[] = {1, 3, 4, 5};
		int W2 = 8;
		System.out.println("unboundedKnapsack => " + unboundedKnapsack(value2,weight2,W2,value2.length));
		System.out.println("----");
		
		String str11 = "AGGTAB";
		String str21 = "GXTXAYB";
		System.out.println(lengthLongestCommonSubsequence(str11,str21,str11.length(),str21.length()));
		
		String str12 = "lead";
		String str22 = "pea";
		int lengthLcs = lengthLongestCommonSubsequence(str12,str22,str12.length(),str22.length());
		System.out.println("#deletion to convert str1 to str2 => " + (str12.length() - lengthLcs));
		System.out.println("#insertion to convert str1 to str2 => " + (str22.length() - lengthLcs));
	}
	
	static boolean subArrayContainSum(int arr[],int x)
	{
		HashSet<Integer> hs = new HashSet<>();
		
		int prefix_sum = 0;
		for(int i=0;i<arr.length;i++)
		{
			prefix_sum = prefix_sum + arr[i];
			if(hs.contains(prefix_sum-x) == false)
			{
				hs.add(prefix_sum);
			}
			else
			{
				return true;
			}
			
		}
		
		return false;
	}
	
	static boolean arrayContainsPairSum(int arr[],int x)
	{
		HashSet<Integer> hs = new HashSet<>();
		
		for(int i=0;i<arr.length;i++)
		{
			if(hs.contains(x-arr[i]) == false)
			{
				hs.add(arr[i]);
			}
			else
			{
				return true;
			}
		}
		
		return false;
	}
	
	static int maxSubArraySum(int arr[])
	{
		int prefix_sum_here = 0;
		int prefix_sum_so_far = 0;
		for(int i=0;i<arr.length;i++)
		{
			prefix_sum_here = prefix_sum_here + arr[i];
			
			if(prefix_sum_here < 0)
			{
				prefix_sum_here = 0;
			}
			
			if(prefix_sum_here > prefix_sum_so_far)
			{
				prefix_sum_so_far = prefix_sum_here;
			}
		}
		
		return prefix_sum_so_far;
	}
	
	static boolean binarySearch(int arr[],int x,int left,int right)
	{
		if(left < right)
		{
			int mid = left + ((right - left) / 2);
			if(arr[mid] == x)
			{
				return true;
			}
			else if(x < arr[mid])
			{
				return binarySearch(arr,x,left,mid-1);
			}
			else if(x > arr[mid])
			{
				return binarySearch(arr,x,mid+1,right);
			}
		}
		
		return false;
	}
	
	static int knapsack(int value[],int weight[],int W,int n)
	{
		if(n == 0 || W == 0)
		{
			return 0;
		}
		
		int lastIndex = n-1;
		
		if(weight[lastIndex] > W)
		{
			return knapsack(value,weight,W-0,n-1);
		}
		else //if(weight[lastIndex] >= W)
		{
			return Math.max(value[lastIndex] + knapsack(value,weight,W-weight[lastIndex],n-1),
					0 + knapsack(value,weight,W-0,n-1));
		}
	}
	
	static int unboundedKnapsack(int value[],int weight[],int W,int n)
	{
		if(W == 0 || n == 0)
		{
			return 0;
		}
		
		int lastIndex = n-1;
		
		if(weight[lastIndex] > W)
		{
			return unboundedKnapsack(value,weight,W-0,n-1);
		}
		else// if(weight[lastIndex] <= W)
		{
			return Math.max(value[lastIndex] + unboundedKnapsack(value,weight,W-weight[lastIndex],n),
					0 + unboundedKnapsack(value,weight,W-0,n-1));
		}
	}
	
	static int lengthLongestCommonSubsequence(String str1,String str2,int m,int n)
	{
		if(m == 0 || n == 0)
		{
			return 0;
		}
		
		if(str1.charAt(m-1) == str2.charAt(n-1))
		{
			return 1 + lengthLongestCommonSubsequence(str1,str2,m-1,n-1);
		}
		else
		{
			return Math.max(lengthLongestCommonSubsequence(str1,str2,m-1,n),
					lengthLongestCommonSubsequence(str1,str2,m,n-1));
		}
	}
	
	
}
