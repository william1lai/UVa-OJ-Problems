import java.util.*;
import java.math.*;

class Main
{
	public static void main(String[] args)
	{
		Scanner keyboard = new Scanner(System.in);
		while(keyboard.hasNextBigInteger())
		{
			BigInteger first = keyboard.nextBigInteger();
			BigInteger second = keyboard.nextBigInteger();

			BigInteger result = first.multiply(second);

			System.out.println(result.toString());
		}
	}
}