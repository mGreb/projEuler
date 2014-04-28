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
			fillArrayWithDivisorsSum(dArr);
			countSum();
		}

		private void countSum()
		{

		}

		//private void countSum()
		//{
		//	Array.Sort(dArr);
		//	Array.Sort(dArr1);
		//	for (int i = 0; i < dArr.Length; i++)
		//	{
		//		if ()
		//	}
		//}

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
