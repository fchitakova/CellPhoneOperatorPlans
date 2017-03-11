#include <iostream>
#include "Mentel.h"



bool isValid(const Date&d)
{
	if (d.day < 1 && (d.month <1 || d.month > 12) && (d.year<2000 || d.year>2025) &&
	 (d.month == 2 && (d.day != 28 || d.day != 29)) && ((d.month==4 || d.month==6 || d.month==9|| d.month==11) && d.day!=30 ))
		return false;
	return true;
}


void readDate(Date&d)
{
	do
	{
		char c;

		std::cout << "Please enter a valid start/end date: ";

		std::cin >> d.day >> c>>d.month>>c >> d.year;

		std::cout << '\n';

	} while (!isValid(d));
}



void printDate(const Date&d)
{

	std::cout << d.day << '.' << d.month << '.' << d.year << '\n';

}


void readTariffPlat(TariffPlan&tp)
{
	do
	{
		std::cout << "Please enter:\n";

		std::cout << "Name:";

		std::cin.sync();

		std::cin.clear();

		std::cin.getline(tp.name, MAX_NAMELEN, '\n');

		std::cout << '\n';

		std::cout << "Price: ";

		std::cin >> tp.price;

		std::cout << '\n' << "Minutes: ";

		std::cin >> tp.min;

		std::cout << '\n' << "Number of SMS: ";

		std::cin >> tp.SMS;

		std::cout << '\n' << "Number of MB : ";

		std::cin >> tp.MB;

		std::cout << '\n';

		readDate(tp.startDate);

		readDate(tp.endDate);

		std::cout << "Term of the contract: ";

		std::cin >> tp.term;

		std::cout << '\n';

		if ((tp.endDate.year < tp.startDate.year) || (tp.startDate.year == tp.endDate.year && tp.endDate.month < tp.startDate.month) ||
			(tp.startDate.year == tp.endDate.year && tp.startDate.month == tp.endDate.month && tp.endDate.day < tp.startDate.day))
		{
			std::cout << "The end date of the contract cannot be  before the start date of the contract!Please enter new dates! \n";
		}
	}  while ((tp.endDate.year  <  tp.startDate.year) || (tp.startDate.year == tp.endDate.year && tp.endDate.month  <  tp.startDate.month) ||
	(tp.startDate.year==tp.endDate.year && tp.startDate.month==tp.endDate.month && tp.endDate.day<tp.startDate.day));

}


void readArrayOfPlans(TariffPlan*plans, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		readTariffPlat(plans[i]);
	}

}

void printPlan(const TariffPlan&plan)
{
	std::cout << "Tariff name: " << plan.name << '\n'
		<< "Price: " << plan.price << '\n'
		<< "Included minutes: " << plan.min << '\n'
		<< "Included SMSs: " << plan.SMS << '\n'
		<< "Included MBs: " << plan.MB << '\n'
		<< "Term of the contract: " << plan.term
		<< ' ' << "from ";

	printDate(plan.startDate);

	std::cout << " to ";

	printDate(plan.endDate);

	std::cout << '\n';
}


TariffPlan* filterPlansByPreference(const TariffPlan*plans, const size_t size, unsigned wantedMins,unsigned wantedSMS,unsigned wantedMB,unsigned wantedTerm ,
double preferedPrice,size_t&newsize)
{

	for (size_t i = 0; i < size; i++)
	{
		if (!(plans[i].min >= wantedMins && plans[i].SMS >= wantedSMS &&
			plans[i].MB >= wantedMB && plans[i].term >= wantedTerm && plans[i].price <= preferedPrice))

		{
			newsize++;
		}
	}

	TariffPlan*Filtered = new TariffPlan[newsize];
	
	size_t j = 0;
	
	for (size_t i = 0; i < size; i++)
	{
		if (!(plans[i].min >= wantedMins && plans[i].SMS >= wantedSMS &&
			plans[i].MB >= wantedMB && plans[i].term >= wantedTerm && plans[i].price <= preferedPrice))

		{
			Filtered[j] = plans[i];
			j++;
		}
	}
	return Filtered;
}




void swap(TariffPlan&tp1, TariffPlan&tp2)
{
	TariffPlan temp;

	temp = tp1;
	tp1 = tp2;
	tp2 = temp;
}


void sortTarrifPlansByPrice(TariffPlan*plans, size_t size)
{

	bool swapped = true;

	size_t j = 0;

	while (swapped)
	{
		swapped = false;

		j++;

		for (size_t i = 0; i < size - j; i++)
		{
			if (plans[i].price>plans[i + 1].price)
			{
				swap(plans[i], plans[i + 1]);

				swapped = true;
			}
		}
	}


}


void printAllPlans(const TariffPlan*plans, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		printPlan(plans[i]);
	}
}
