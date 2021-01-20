package learn;

import java.util.*;

public class Third 
{
	static int arr[] = {7,5,10,3,6,9,12};
	
	public static void main(String args[])
	{
		TreeNodez btree = createBtree();
		inorder(btree);
		System.out.println();
		preorder(btree);
		System.out.println();
		postorder(btree);
		System.out.println();
		levelorder(btree);
		System.out.println();
		System.out.println("----");
		System.out.println("max width of tree => " + maxWidth(btree));
		System.out.println("height of tree => " + heightOfTree(btree));
		System.out.println("dia of tree => " + diaOfTree(btree));
		printAtLevel(btree,1);
		System.out.println();
		System.out.println("distanceFromRoot => " + distanceFromRoot(btree,6));
		System.out.println("distanceBetweenNodes => " + distanceBetweenNodes(btree,6,12));
		System.out.println("isBalanced => " + isBalanced(btree));
		
		ArrayList<TreeNodez> path = new ArrayList<>();
		System.out.println("findPathToNode => " + findPathToNode(btree,path,12));
		System.out.println("findLCA => " + findLCA(btree,9,12));
		
		System.out.println("isChildrenSum => " + isChildrenSum(btree));
		leftView(btree);
		System.out.println();
		rightView(btree);
		System.out.println();
		mirrorTree(btree);
		levelorder(btree);
		System.out.println();
	}
	
	static TreeNodez createBtree()
	{
		TreeNodez btree = null;
		
		for(int i=0;i<arr.length;i++)
		{
			TreeNodez newnode = new TreeNodez();
			newnode.data = arr[i];
			btree = insertNode(btree,newnode);
		}
		
		return btree;
	}
	
	static TreeNodez insertNode(TreeNodez btree,TreeNodez newnode)
	{
		if(btree == null)
		{
			return newnode;
		}
		else if(newnode.data < btree.data)
		{
			btree.left = insertNode(btree.left,newnode);
		}
		else if(newnode.data > btree.data)
		{
			btree.right = insertNode(btree.right,newnode);
		}
		else if(newnode.data == btree.data)
		{
			System.out.println("data already there");
			return btree;
		}
		return btree;
	}
	
	static void inorder(TreeNodez newnode)
	{
		if(newnode != null)
		{
			inorder(newnode.left);
			System.out.print(newnode.data + " ");
			inorder(newnode.right);
		}
	}
	
	static void preorder(TreeNodez newnode)
	{
		if(newnode != null)
		{
			System.out.print(newnode.data + " ");
			preorder(newnode.left);
			preorder(newnode.right);
		}
	}
	
	static void postorder(TreeNodez newnode)
	{
		if(newnode != null)
		{
			preorder(newnode.left);
			preorder(newnode.right);
			System.out.print(newnode.data + " ");
		}
	}
	
	static void levelorder(TreeNodez root)
	{
		Queue<TreeNodez> q = new LinkedList<>();
		q.add(root);
		while(q.isEmpty() == false)
		{
			TreeNodez temp = q.peek();
			System.out.print(temp.data + " ");
			q.remove();
			
			if(temp.left != null)
			{
				q.add(temp.left);
			}
			
			if(temp.right != null)
			{
				q.add(temp.right);
			}
		}
	}
	
	static int maxWidth(TreeNodez root)
	{
		int x = 0;
		Queue<TreeNodez> q = new LinkedList<>();
		q.add(root);
		while(q.isEmpty() == false)
		{
			x = Math.max(q.size(), x);
			TreeNodez temp = q.peek();
			q.remove();
			
			if(temp.left != null)
			{
				q.add(temp.left);
			}
			
			if(temp.right != null)
			{
				q.add(temp.right);
			}
		}
		return x;
	}
	
	static int heightOfTree(TreeNodez root)
	{
		if(root == null)
		{
			return 0;
		}
		
		int lh = heightOfTree(root.left);
		int rh = heightOfTree(root.right);
		
		return 1 + Math.max(lh, rh);
	}
	
	static int diaOfTree(TreeNodez root)
	{
		if(root == null)
		{
			return 0;
		}
		
		int lh = heightOfTree(root.left);
		int rh = heightOfTree(root.right);
		
		int ldia = diaOfTree(root.left);
		int rdia = diaOfTree(root.right);
		
		return Math.max(1 + lh + rh , Math.max(ldia,rdia));
	}
	
	static void printAtLevel(TreeNodez root,int k)
	{
		if(root == null)
		{
			return;
		}
		
		if(k == 0)
		{
			System.out.print(root.data + " ");
		}
		printAtLevel(root.left,k-1);
		printAtLevel(root.right,k-1);
	}
	
	static int distanceFromRoot(TreeNodez btree,int x)
	{
		if(x < btree.data)
		{
			return 1 + distanceFromRoot(btree.left, x);
		}
		else if (x > btree.data)
		{
			return 1 + distanceFromRoot(btree.right, x);
		}
		
		return 0;
	}
	
	static int distanceBetweenNodes(TreeNodez btree,int a,int b)
	{
		if(a > b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
		
		if(a < btree.data && b < btree.data)
		{
			return distanceBetweenNodes(btree.left,a,b); 
		}
		
		if(a > btree.data && b > btree.data)
		{
			return distanceBetweenNodes(btree.right,a,b);
		}
		
		if (a <= btree.data && b >= btree.data)
		{
			return distanceFromRoot(btree,a) + distanceFromRoot(btree,b);
		}
		
		return 0;
	}
	
	static boolean isBalanced(TreeNodez root)
	{
		if(root == null)
		{
			return true;
		}
		
		int lh = heightOfTree(root.left);
		int rh = heightOfTree(root.right);
		
		if(Math.abs(lh-rh) <= 1 && isBalanced(root.left) && isBalanced(root.right))
		{
			return true;
		}
		return false;
	}
	
	static boolean findPathToNode(TreeNodez root,ArrayList<TreeNodez> path,int x)
	{
		if(root == null)
		{
			return false;
		}
		path.add(root);
		if(root.data == x)
		{
			return true;
		}
		
		if( ( root.left != null && findPathToNode(root.left,path,x) == true )|| 
				( root.right != null && findPathToNode(root.right,path,x) == true ) )
		{
			return true;
		}
		
		path.remove(path.size()-1);
		
		return false;
	}
	
	static int findLCA(TreeNodez root,int a,int b)
	{
		ArrayList<TreeNodez> path1 = new ArrayList<>();
		ArrayList<TreeNodez> path2 = new ArrayList<>();
		if(findPathToNode(root,path1,a) == false || findPathToNode(root,path2,b) == false)
		{
			return -1;
		}
		
		int i;
		for(i=0;i<path1.size() && i< path2.size();i++)
		{
			if(path1.get(i) != path2.get(i))
			{
				break;
			}
		}
		
		return path1.get(i-1).data;
	}
	
	static boolean isChildrenSum(TreeNodez root)
	{
		if(root == null)
		{
			return true;
		}
		
		int sum = 0;
		
		if(root.left != null)
		{
			sum = sum + root.left.data;
		}
		
		if(root.right != null)
		{
			sum = sum + root.right.data;
		}
		
		if(sum == root.data && isChildrenSum(root.left) == true && isChildrenSum(root.right) == true)
		{
			return true;
		}
		
		return false;
	}
	
	static void leftView(TreeNodez root)
	{
		Queue<TreeNodez> q = new LinkedList<>();
		q.add(root);
		while(q.isEmpty() == false)
		{
			int n = q.size();
			for(int i=0;i<n;i++)
			{
				TreeNodez temp = q.peek();
				if(i == 0)
				{
					System.out.print(temp.data + " ");
				}
				q.remove();
				
				if(temp.left != null)
				{
					q.add(temp.left);
				}
				
				if(temp.right != null)
				{
					q.add(temp.right);
				}
			}
		}
	}
	
	static void rightView(TreeNodez root)
	{
		Queue<TreeNodez> q = new LinkedList<>();
		q.add(root);
		while(q.isEmpty() == false)
		{
			int n = q.size();
			for(int i=0;i<n;i++)
			{
				TreeNodez temp = q.peek();
				if(i == n-1)
				{
					System.out.print(temp.data + " ");
				}
				q.remove();
				
				if(temp.left != null)
				{
					q.add(temp.left);
				}
				
				if(temp.right != null)
				{
					q.add(temp.right);
				}
			}
		}
	}
	
	static void mirrorTree(TreeNodez root)
	{
		Queue<TreeNodez> q = new LinkedList<>();
		q.add(root);
		while(q.isEmpty() == false)
		{
			TreeNodez temp = q.peek();
			q.remove();
			
			TreeNodez tempSwap = temp.left;
			temp.left = temp.right;
			temp.right = tempSwap;
			
			if(temp.left != null)
			{
				q.add(temp.left);
			}

			if(temp.right != null)
			{
				q.add(temp.right);
			}
		}
	}
}

class TreeNodez
{
	int data;
	TreeNodez left;
	TreeNodez right;
	
	TreeNodez()
	{
		this.data = 0;
		this.left = null;
		this.right = null;
	}
}
