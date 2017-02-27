#ifndef HEADER_H
#define HEADER_H

const int MAX_NAMELEN = 63;

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

void copyDate(Date&d1, const Date&d2);

void readTariffPlat(TariffPlan&tp);

void readArrayOfPlans(TariffPlan*plans, size_t size);

void filterPlansByPreference(const TariffPlan*plans, size_t size);

void printPlan(const TariffPlan&plan);

void copyPlan(TariffPlan&tp1,const TariffPlan&tp2);

void swap(TariffPlan&tp1, TariffPlan&tp2);

void sortTarrifPlansByPrice(TariffPlan*plans,size_t size);

void printAllPlans(const TariffPlan*plans, size_t size);



#endif
