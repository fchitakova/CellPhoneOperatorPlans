#include <iostream>
#include "Header.h"



bool isValid(const Date&d)
{
	if ((d.day<1 || d.day>31) && (d.month > 1 || d.month > 12) && (d.year<2000 || d.year>2025))
		return false;
	return true;
}


void readDate(Date&d)
{
	do
	{
		std::cout << "Please enter a valid start/end date: ";
		
		std::cin >> d.day >> d.month >> d.year;
		
		std::cout << '\n';
	
	} while (!isValid(d));
}



void printDate(const Date&d)
{

	std::cout << d.day << '.' << d.month << '.' << d.year << '\n';

}


void readTariffPlat(TariffPlan&tp)
{
	std::cout << "Please enter:\n";
		
	std::cout<< "Name:";

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



void filterPlansByPreference(const TariffPlan*plans, size_t size)
{
	unsigned wantedMins = 0, wantedSMS = 0, wantedMB = 0, wantedTerm = 0;
	double preferedPrice = 0;;
	
	std::cout << "Please enter how many minutes,SMSs and MBs you need at least: ";
	
	std::cin >> wantedMins >> wantedSMS >> wantedMB;

	std::cout << '\n';

	std::cout << "Please enter how long term do you prefer: ";

	std::cin >> wantedTerm;

	std::cout <<'\n'<< "Please enter the max price that satisfies you: ";

	std::cin >> preferedPrice;
	

	std::cout << '\n' << "The tariff plans which satisfies your preferences are: \n";

	int cnt = 0;

	for (size_t i = 0; i < size; i++)
	{
		
		if (plans[i].min >= wantedMins && plans[i].SMS >= wantedSMS && 
			plans[i].MB >= wantedMB && plans[i].term >= wantedTerm && plans[i].price<=preferedPrice)
		
		{
			cnt++;
			printPlan(plans[i]);
		}
		if (cnt == 0)
		{
			std::cout << "There are no plans that satisfies your preferences!\n";
		}
	
	}

}

void copyDate(Date&d1, const Date&d2)
{
	
		d1.day = d2.day;

		d1.month = d2.month;

		d1.year = d2.year;
}

void copyPlan(TariffPlan&tp1,const TariffPlan&tp2)
{
	if (&tp1 != &tp2)
	{

		strcpy(tp1.name, tp2.name);

		tp1.price = tp2.price;

		tp1.min = tp2.min;

		tp1.SMS = tp2.SMS;

		tp1.MB = tp2.MB;

		copyDate(tp1.startDate, tp2.startDate);

		copyDate(tp1.endDate, tp2.endDate);
	}
}


void swap(TariffPlan&tp1, TariffPlan&tp2)
{
	TariffPlan temp;

	copyPlan(temp, tp1);

	copyPlan(tp1, tp2);

	copyPlan(tp2, temp);

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
