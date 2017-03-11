#ifndef MENTEL_H
#define MENTEL_H

const int MAX_NAMELEN = 64;

struct Date
{
	unsigned day;
	unsigned month;
	unsigned year;
};

struct TariffPlan
{
	char name[MAX_NAMELEN];

	unsigned min;

	unsigned MB;

	unsigned SMS;

	Date startDate;

	Date endDate;

	unsigned term;

	double price;

};

bool isValid(const Date&d);

void readDate(Date&d);

void printDate(const Date&d);

void readTariffPlat(TariffPlan&tp);

void readArrayOfPlans(TariffPlan*plans, size_t size);

TariffPlan* filterPlansByPreference(const TariffPlan*plans, const size_t size, unsigned wantedMins, unsigned wantedSMS, unsigned wantedMB, unsigned wantedTerm, double preferedPrice,size_t&newsize);

void printPlan(const TariffPlan&plan);

void swap(TariffPlan&tp1, TariffPlan&tp2);

void sortTarrifPlansByPrice(TariffPlan*plans, size_t size);

void printAllPlans(const TariffPlan*plans, size_t size);


#endif
