# Loan Amortization Scheduler

## Project Overview

Fixed income products such as loans (or bonds) often require the debtor (or the issuer in case of bonds) to make regular repayments (coupons). In an amortization structure, a part of the repayment contributes towards accrued interest and the rest towards settling the outstanding principal. Loan amortization structures are quite common, and almost anyone who has engaged with a loan product by a traditional lender must have encountered such structures in some form or the other. The repayments are popularly referred to as EMIs - Equated Monthly Installments. EMI structures allow the borrowers to easily budget the amount they need to repay their lender each month.

If one reviews a loan amortization schedule, they would observe that while in the early repayment installments a large share goes towards interest payment, with time, as the principal reduces, a higher share of repayment goes towards settling the principal until the outstanding reduces to zero.

## File Structure

- `loan_amortization.cpp`: Implementation file for the loan amortization scheduler.
- `loan_amortization.h`: Header file for the loan amortization scheduler.
- `main.cpp`: Main file containing the entry point for running the scheduler.
- `Makefile`: Script to compile the project.
