import java.util.*;
import java.math.BigInteger;

class Main
{
	public static void main(String [] args)
	{
		int num;
		int temp = 1;
		int lowerlimit = 1;
		while (temp <= 10000)
		{
			lowerlimit++;
			temp = temp*lowerlimit;
		}

		BigInteger [] facs = new BigInteger[1000000];
		BigInteger bi = BigInteger.ONE;
		int inc = 1;
		BigInteger over = new BigInteger("6227020800");
		while (bi.compareTo(over) <= 0)
		{
			inc++;
			bi = bi.multiply(BigInteger.valueOf(inc));
			facs[inc] = bi;
		}

		Scanner keyboard = new Scanner(System.in);
		while (keyboard.hasNextInt())
		{
			num = keyboard.nextInt();
			if (num < lowerlimit)
				System.out.println("Underflow!");
			else if (num >= inc)
				System.out.println("Overflow!");
			else
				System.out.println(facs[num].toString());
		}
	}
}