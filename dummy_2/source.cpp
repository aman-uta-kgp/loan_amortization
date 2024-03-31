#include <iostream>
#include "divisor.h"
#include "multiplier.h"
#include <cmath>
#include <iomanip>
#include "global.h"

using namespace std;

enum AmortEnum
{
	YR_OUT = 2,
	MN_OUT = 2,
	CUM_MN_OUT = 5,
	PAYMENT_OUT = 12,
	INTEREST_OUT = 12,
	PRINCIPAL_OUT = 12,
	BALANCE_OUT = 16
};

string AmortHeader[] =
{
	"Yr",
	"Mn",
	"CumMn",
	"Payment",
	"Interest",
	"Principal",
	"Balance"
};

void printAmortHeader()
{
	cout <<
		endl <<
		setw(YR_OUT) << AmortHeader[0] << " " <<
		setw(MN_OUT) << AmortHeader[1] << " " <<
		setw(CUM_MN_OUT) << AmortHeader[2] << " " <<
		setw(PAYMENT_OUT) << AmortHeader[3] << " " <<
		setw(INTEREST_OUT) << AmortHeader[4] << " " <<
		setw(PRINCIPAL_OUT) << AmortHeader[5] << " " <<
		setw(BALANCE_OUT) << AmortHeader[6] << endl;

}



int main(int argc, char* argv[])
{
	cout << "argc:" << argc << endl;

	int principal = 0.0;
	principal = atoi( argv[1]);
	
	double humaninterest = 0.0;
	humaninterest = atof(argv[2]);

	int yearsOfLoan = 0.0;
	yearsOfLoan = atoi(argv[3]);

	cout << "Principal " << principal << endl;
	cout << "interest " << humaninterest << endl;
	cout << "yearsOfLoan " << yearsOfLoan << endl;

	
	double interest = divisor(humaninterest, gpercentDenominator);

	double monthInterest = interest / gmonths_in_year;

	double monthsOfLoan = multiplier( yearsOfLoan , gmonths_in_year);
	
	double payment = 0.0;
	payment = principal *
		(monthInterest /
			(1 - pow((double)1 + monthInterest,
				(double) - monthsOfLoan))
			);
	cout << "Payment: "<< setiosflags(ios::fixed)<<
		 setprecision(2) << payment << endl;

	double currInterestPayment = 0.0;
	double currPrincipalPayment = 0.0;
	double currBalance = 0.0;

	currBalance = principal;

	double currLoanMonth = 1;

	int year = 1;
	int switchYear = 0;

	int yearMonth = 1;

	while (currLoanMonth <= monthsOfLoan) {

		if (switchYear != year) {

			switchYear = year;

			printAmortHeader();
		}

		gAmortizeMonth amortMonth;

		currInterestPayment = currBalance * monthInterest;
		currPrincipalPayment = payment - currInterestPayment;
		currBalance = currBalance - currPrincipalPayment;

		amortMonth.year = year;
		amortMonth.yearMonth = yearMonth;
		amortMonth.loanMonth = currLoanMonth;
		amortMonth.payment = payment;
		amortMonth.pureInterest = currInterestPayment;
		amortMonth.paidDownPrincipal = currPrincipalPayment;
		amortMonth.principalBalance = currBalance;

		cout <<
			setw(YR_OUT) << amortMonth.year << " " <<
			setw(MN_OUT) << amortMonth.yearMonth << " " <<
			setw(CUM_MN_OUT) << amortMonth.loanMonth << " " <<
			setw(PAYMENT_OUT) << amortMonth.payment << " " <<
			setw(INTEREST_OUT) << amortMonth.pureInterest << " " <<
			setw(PRINCIPAL_OUT) << amortMonth.paidDownPrincipal << " " <<
			setw(BALANCE_OUT) << amortMonth.principalBalance << endl;

		yearMonth++;

		if (yearMonth > gmonths_in_year)
		{
			yearMonth = 1;
			year++;
		}
		
		currLoanMonth++;



	}

	cout << "Loan payment complete." << endl;


	return 0;


}