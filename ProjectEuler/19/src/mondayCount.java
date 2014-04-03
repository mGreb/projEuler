
class sundaysCount 
{
	private static int[] daysInMonths = new int [12];
	private static int startYear;
	private static int endYear;
	private int sundaysQuantity;
	public sundaysCount()
	{
		startYear = 1900;
		endYear = 2000;
		sundaysQuantity = 0;
		daysInMonths[0] = 31; //January
		daysInMonths[1] = 28; //February
		daysInMonths[2] = 31; //March
		daysInMonths[3] = 30; //April
		daysInMonths[4] = 31; //May
		daysInMonths[5] = 30; //June
		daysInMonths[6] = 31; //July
		daysInMonths[7] = 31; //August
		daysInMonths[8] = 30; //September
		daysInMonths[9] = 31; //October
		daysInMonths[10] = 30; //November
		daysInMonths[11] = 31; //December
	}
	private boolean isRegular(int x)
	{
		boolean res = false;
		if (x % 4 == 0)
		{
			res = true;
		}
		if ((x % 4 == 0)&&(x % 100 == 0))
		{
			res = false;
		}
		if ((x % 400 == 0)&&(x % 4 == 0)&&(x % 100 == 0))
		{
			res = true;
		}
		return res;
	}
	public boolean getIsRegular(int i)
	{
		return isRegular(i);
	}
	public int cnt()
	{
		int temp = 7;
		for (int i = startYear; i <= endYear; i++)
		{
			if (isRegular(i) == true)
			{
				daysInMonths[1] = 29;
			}else{
				daysInMonths[1] = 28;
			}
			for (int j = 0; j < daysInMonths.length; j++)
			{
				for (;;)
				{
					if ((i != startYear) && (temp == 1))
					{
						sundaysQuantity++;
						System.out.printf("year: %d month: %d, day: %d\n", i, j, temp);
					}
					temp += 7;
					if (temp > daysInMonths[j])
					{
						temp = temp - daysInMonths[j];
						break;
					}
				}
				
			}
		}
		return 0;
	}
	public int getSundaysQuantity()
	{
		return sundaysQuantity;
	}
}
