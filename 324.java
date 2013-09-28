import java.util.*;
import java.math.BigInteger;

class Main
{
	public static void main(String[] args)
	{
		BigInteger[] facs = new BigInteger[367];

		BigInteger temp = BigInteger.ONE;
		int index = 1;
		for (BigInteger b = BigInteger.ONE; b.compareTo(BigInteger.valueOf(366)) <= 0; b = b.add(BigInteger.ONE))
		{
			temp = temp.multiply(b);
			facs[index] = temp;
			index++;
		}

		Scanner keyboard = new Scanner(System.in);
		while (keyboard.hasNextInt())
		{
			int next = keyboard.nextInt();
			
			if (next == 0)
				return;

			System.out.println(next + "! --");
			
			int[] counts = new int[10];
			BigInteger factorial = facs[next];
			while (factorial.compareTo(BigInteger.ZERO) > 0)
			{
				int digit = factorial.mod(BigInteger.TEN).intValue();
				factorial = factorial.divide(BigInteger.TEN);
				counts[digit]++;
			}

			System.out.println("   (0)    " + counts[0] + "    (1)    " + counts[1] + "    (2)    " + counts[2] + "    (3)    " + counts[3] + "    (4)    " + counts[4]);
			System.out.println("   (5)    " + counts[5] + "    (6)    " + counts[6] + "    (7)    " + counts[7] + "    (8)    " + counts[8] + "    (9)    " + counts[9]);
		}
	}
}