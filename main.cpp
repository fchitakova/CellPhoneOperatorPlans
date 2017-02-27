#include <iostream>
#include "Header.h"


int main()
{
	int n;

	std::cout << "Number of plans: ";

	do
	{
		std::cin >> n;
	} while (n < 1);

	TariffPlan*plans = new TariffPlan[n];

	readArrayOfPlans(plans, n);

	sortTarrifPlansByPrice(plans, n);

	printAllPlans(plans, n);

	filterPlansByPreference(plans, n);






	delete[]plans;

	return 0;
}
