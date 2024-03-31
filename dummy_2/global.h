#pragma once
const int gmonths_in_year = 12;

double gpercentDenominator = 100;

/// <summary>
/// structure
/// </summary>
struct gAmortizeMonth {
	int year;
	int yearMonth;
	int loanMonth;
	double payment;
	double pureInterest;
	double paidDownPrincipal;
	double principalBalance;
};