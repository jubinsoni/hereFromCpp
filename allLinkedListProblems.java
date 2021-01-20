package learn;

public class Second 
{
	static int arr[] = {7,5,19,24,56};
	
	public static void main(String args[])
	{
		Nodez headptr = null;
		headptr = createList(headptr);
		System.out.print("linked list creation => ");
		printList(headptr);
		System.out.println("middleOfLinkedList => " + middleOfLinkedList(headptr));
		headptr = reverseList(headptr);
		System.out.print("reverse linked list => ");
		printList(headptr);
		
		System.out.println("loop creation and removal");
		createLoop(headptr);
		removeLoop(headptr);
		printList(headptr);
	}
	
	static Nodez createList(Nodez headptr)
	{
		Nodez head = headptr;
		Nodez last = headptr;
		
		for(int i=0;i<arr.length;i++)
		{
			Nodez temp = new Nodez();
			temp.data = arr[i];
			if(last == null)
			{
				head = temp;
				last = head;
			}
			else
			{
				last.next = temp;
				last = last.next;
			}
		}
		return head;
	}
	
	static void printList(Nodez headptr)
	{
		Nodez last = headptr;
		while(last != null)
		{
			System.out.print(last.data + " ");
			last = last.next;
		}
		System.out.println();
	}
	
	static int middleOfLinkedList(Nodez headptr)
	{
		Nodez fast = headptr;
		Nodez slow = headptr;
		
		while(fast != null && fast.next != null)
		{
			fast = fast.next.next;
			slow = slow.next;
		}
		
		return slow.data;
	}
	
	static Nodez reverseList(Nodez headptr)
	{
		Nodez backward = null;
		Nodez curr = headptr;
		Nodez forward = headptr;
		
		while(curr != null)
		{
			forward = forward.next;
			curr.next = backward;
			backward = curr;
			curr = forward;
		}
		
		return backward;
	}
	
	static void createLoop(Nodez headptr)
	{
		Nodez head = headptr;
		Nodez last = headptr;
		
		while(last.next != null)
		{
			last = last.next;
		}
		
		last.next = head.next;
	}
	
	static void removeLoop(Nodez headptr)
	{
		Nodez slow = headptr;
		Nodez fast = headptr;
		
		while(1 == 1)
		{
			slow = slow.next;
			fast = fast.next.next;
			
			if(slow == fast)
			{
				break;
			}
		}
		
		fast = headptr;
		
		while(slow.next != fast.next)
		{
			slow = slow.next;
			fast = fast.next;
		}
		
		slow.next = null;
		
	}
}

class Nodez
{
	int data;
	Nodez next;
	
	Nodez()
	{
		this.data = 0;
		this.next = null;
	}
}
