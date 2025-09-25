#pragma once

#include <iostream>
#include "clsDate.h"

class clsPeriod
{
public:
	clsDate StartDate;
	clsDate EndDate;

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		this->StartDate = StartDate;
		this->EndDate = EndDate;
	}

	void Print()
	{
		cout << "Period Start: ";
		StartDate.Print();

		cout << "Period End: ";
		EndDate.Print();
	}

	static bool AreOverlapPeriods(clsPeriod Period1, clsPeriod Period2)
	{
		return !(clsDate::CompareDates(Period2.EndDate, Period1.StartDate) == clsDate::enDateCompare::Before ||
			clsDate::CompareDates(Period2.StartDate, Period1.EndDate) == clsDate::enDateCompare::After);
	}

	bool IsOverlapWith(clsPeriod Period2)
	{
		return AreOverlapPeriods(*this, Period2);
	}

	static int PeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false)
	{
		return clsDate::GetDifferenceInDays(Period.StartDate, Period.EndDate, IncludeEndDay);
	}

	int LengthInDays(bool IncludeEndDay = false)
	{
		return PeriodLengthInDays(*this, IncludeEndDay);
	}

	static bool isDateInPeriod(clsDate Date, clsPeriod Period)
	{
		return !(clsDate::CompareDates(Date, Period.StartDate) == clsDate::enDateCompare::Before ||
			clsDate::CompareDates(Date, Period.EndDate) == clsDate::enDateCompare::After);
	}

	bool isDateInPeriod(clsDate Date)
	{
		return isDateInPeriod(Date, *this);
	}

};

