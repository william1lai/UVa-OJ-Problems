import java.util.*;
import java.math.BigInteger;

class Main
{
	public static void main(String [] args)
	{
		BigInteger [] factorials = new BigInteger[1001];
		factorials[0] = BigInteger.ONE;
		BigInteger temp = BigInteger.ONE;
		int index = 1;
		for (BigInteger bi = BigInteger.ONE; bi.compareTo(new BigInteger(Integer.toString(1000))) <= 0; bi = bi.add(BigInteger.ONE))
		{
			temp = temp.multiply(bi);
			factorials[index] = temp;
			index++;
		}

		Scanner keyboard = new Scanner(System.in);
		while (keyboard.hasNextInt())
		{
			int n = keyboard.nextInt();
			
			System.out.println("" + n + "!");
			System.out.println(factorials[n].toString());
		}
	}
}