#include <iostream>
#include "Mentel.h"


int main()
{
	size_t n;
	unsigned wantedMins, wantedSMS, wantedMB, wantedTerm;
	double preferedPrice;

	std::cout << "Number of plans: ";

	do
	{
		std::cin >> n;
	} while (n < 1);



	TariffPlan*plans = new TariffPlan[n];

	readArrayOfPlans(plans, n);

	std::cout << "Please enter how many minutes,SMSs and MBs you need at least: ";

	std::cin >> wantedMins >> wantedSMS >> wantedMB;

	std::cout << '\n';

	std::cout << "Please enter how long term do you prefer: ";

	std::cin >> wantedTerm;

	std::cout << '\n' << "Please enter the max price that satisfies you: ";

	std::cin >> preferedPrice;

    TariffPlan*filteredPlans=filterPlansByPreference(plans,n, wantedMins, wantedSMS, wantedMB, wantedTerm, preferedPrice);

	sortTarrifPlansByPrice(filteredPlans, n);

	std::cout << '\n';

	std::cout << "The plans ,which satisfies your preferences are: ";

	std::cout << '\n';

	printAllPlans(filteredPlans, n);



	delete[]filteredPlans;
	delete[]plans;

	plans = 0;
	filteredPlans = 0;

	return 0;
}
