using System;
//using System.Array;

namespace _21
{
	class sumClass
	{
		private int bord;
		private int amicableSum;
		private Array dArr;
		private Array dArr1;
		private int result;

		public sumClass(int bbord = 10000, int aamicableSum = 0)
		{
			bord = bbord;
			amicableSum = aamicableSum;
			dArr = new int[bord];
			dArr1 = new int[bord];
			result = 0;
			result = countSum();
		}

		private int countSum()
		{
			int temp1 = 0;
			int temp2 = 0;
			int sum = 0;

			for(int i = 1; i <= bord; i++)
			{
				temp1 = getDivisorsSum(i);
				temp2 = getDivisorsSum(temp1);
				if (temp2 == i)
				{
					sum += temp1;
					sum += temp2;
					Console.WriteLine(i + " " + temp1 + " " + temp2 + " " + sum);
				}
			}
			return sum;
		}

		private int getDivisorsSum(int input)
		{
			int sum = 0;
			for (int i = 1; i < input; i++)
			{
				if (input % i == 0)
				{
					sum += i;
				}
			}
			return sum;
		}

		private void fillArrayWithDivisorsSum(Array dArr)
		{
			for (int i = 0; i < dArr.Length; i++)
			{
				dArr.SetValue(getDivisorsSum(i), i);
			}
		}

		public int getResult()
		{
			return result;
		}
	}
}
