import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		//=======START STATE========================
		System.out.println("Enter the initial state");
//		String inp = sc.nextLine();
		String inp = "ON(B,A)^ONTABLE(A)^ONTABLE(C)^ONTABLE(D)";
		
		String[] inpt = inp.split("\\^");
		
		System.out.println(inpt.length);
		for(int i=0;i<inpt.length;i++)
		{
			System.out.println(inpt[i]+"\n");
		}
		
		
		//=======GOAL STATE========================
		System.out.println("Enter the goal state");
//		String goal = sc.nextLine();
		String goal = "ON(C,A)^ONTABLE(B)^ONTABLE(A)^ONTABLE(D)";
		
		String[] goalt = goal.split("\\^");
		
		System.out.println(goalt.length);
		for(int i=0;i<goalt.length;i++)
		{
			System.out.println(goalt[i]+"\n");
		}
		
		//=======GOAL STACK=====================
		Stack goalS = new Stack();
		
		//=======COMPARISON ====================
		int pushFlag=0;
		int count=1;
		for(int i=0;i<inpt.length;i++)
		{
			if(inpt[i].contains("ON"))
			{
				count=1;
				pushFlag=0;
				for(int j=0;j<goalt.length;j++)
				{
					if(inpt[i].equals(goalt[j]))
					{
						break;
					}
					else
					{
						count++;
						continue;
					}
				}
				if(count>goalt.length)
				{
					if(inpt[i].contains("ONTABLE"))
					{
						pushFlag = 1;
						System.out.println("push "+inpt[i].substring(8,9)+" on stack");
						goalS.push(inpt[i].substring(8,9));
					}
					else
					{
						pushFlag = 1;
						System.out.println("push "+inpt[i].substring(3,4)+" on stack");
						goalS.push(inpt[i].substring(3,4));
					}
				}
			}
			if(pushFlag == 1)
			System.out.println("The stack is :" +goalS+"\n");
		}
		
		while(!goalS.empty())
		{
			String top = (String)goalS.pop();
			
			for(int i=0;i<goalt.length;i++)
			{
				if(goalt[i].contains(top) && !goalt[i].contains("ONTABLE"))
				{
					System.out.println("Pop "+top+" and place on "+goalt[i].substring(5,6));
				}
				if(goalt[i].contains(top) && goalt[i].contains("ONTABLE("+top+")"))
				{
					System.out.println("Pop "+top+" and place on table" );
				}
			}
			
			System.out.println("The stack is :" +goalS+"\n");
		}
		
	}

}

//ON(B,A)^ONTABLE(A)^ONTABLE(C)^ONTABLE(D)
//ON(C,A)^ONTABLE(B)^ONTABLE(A)^ONTABLE(D)



