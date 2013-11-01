import java.util.*;
import java.math.BigInteger;

class Main
{
	public static void main(String [] args)
	{
		BigInteger[] ans = new BigInteger[1001];
		ans[0] = BigInteger.ONE;
		ans[1] = BigInteger.ONE;

		BigInteger running = BigInteger.ONE;
		for (int i = 2; i < 1001; i++)
		{
			running = running.multiply(BigInteger.valueOf(i));
			BigInteger temp = running.add(BigInteger.ZERO);

			ans[i] = temp;
		}

		Scanner keyboard = new Scanner(System.in);

		while (keyboard.hasNextInt())
		{
			int n = keyboard.nextInt();

			BigInteger subans = ans[n];
			int sum = 0;
			while (subans.compareTo(BigInteger.ZERO) > 0)
			{
				sum = sum + subans.mod(BigInteger.TEN).intValue();
				subans = subans.divide(BigInteger.TEN);
			}

			System.out.println(sum);
		}
	}
}