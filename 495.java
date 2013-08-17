import java.util.*;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args)
	{
		BigInteger[] fib = new BigInteger[5001];

		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;
		
		for (int i = 2; i < 5001; i++)
		{
			fib[i] = fib[i-1].add(fib[i-2]);
		}

		Scanner keyboard = new Scanner(System.in);
		while (keyboard.hasNextInt())
		{
			int query = keyboard.nextInt();
			System.out.println("The Fibonacci number for " + query + " is " + fib[query].toString());
		}
	}
}