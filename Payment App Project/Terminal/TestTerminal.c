#include<stdio.h>
#include<stdint.h>
#include "../Card/card.h"
#include "terminal.h"

void getTransactionDateTest(void)
{
	ST_terminalData_t term;
	EN_terminalError_t actual_result;
	uint8_t expectedresult[20];
	printf("Tester Name: Jana\n");
	printf("Function Name: getTransactionDate\n");
	printf("                 TEST CASE 1\n");
	/*NULL Test Case*/
	printf("Test Case 1: NULL Value\n");
	printf("Input Data: ");
	actual_result = getTransactionDate(&term);
	// array, null value , size
	memset(term.transactionDate, '\0', sizeof(term.transactionDate));
	printf("Expected Results: WRONG_DATE\n");
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");
	printf("............................................................................\n");
	printf("                 TEST CASE 2\n");
	/*More Than 10 characters*/
	printf("Test Case 2: More Than 10 Characters\n");
	printf("Input Data: ");
	actual_result = getTransactionDate(&term);
	// array, null value , size
	memset(term.transactionDate, '\0', sizeof(term.transactionDate));
	printf("Expected Results: WRONG_DATE\n");
	memset(expectedresult, '\0', sizeof(term.transactionDate));
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");
	printf("............................................................................\n");
	printf("                     TEST CASE 3 \n");
	/*Less Than 10 characters*/
	printf("Test Case 3: Less Than 10 Characters\n");
	printf("Input Data: ");
	actual_result = getTransactionDate(&term);
	// array, null value , size
	memset(term.transactionDate, '\0', sizeof(term.transactionDate));
	printf("Expected Results: WRONG_DATE\n");
	memset(expectedresult, '\0', sizeof(term.transactionDate));
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");
	printf("............................................................................\n");
	printf("                       TEST CASE 4\n");
	/*Invalid Input*/
	printf("Test Case 4: Invalid Format\n");
	printf("Input Data: ");
	actual_result = getTransactionDate(&term);
	// array, null value , size
	memset(term.transactionDate, '\0', sizeof(term.transactionDate));
	printf("Expected Results: WRONG_DATE\n");
	memset(expectedresult, '\0', sizeof(term.transactionDate));
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");
	printf("............................................................................\n");
	printf("                       TEST CASE 5\n");
	/*Valid Input*/
	printf("Test Case 5: Valid Input\n");
	printf("Input Data: ");
	actual_result = getTransactionDate(&term);
	printf("Expected Results: TERMINAL_OK\n");
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");
}
/*.................................................................................*/
void isCardExpriedTest(void)
{
	ST_cardData_t cardD;
	ST_terminalData_t termD;
	EN_terminalError_t actualResults;

	printf("Tester Name: Jana\n");
	printf("Function Name: isCardExpried\n");
	//EXPIRED CARD
	printf("                 TEST CASE 1\n");
	printf("Test Case 1: Expired Card\n");
	printf("Input Data --> Card Expiration Date: ");
	actualResults = getCardExpiryDate(&cardD);
	printf("Input Data --> Transaction Date : ");
	actualResults = getTransactionDate(&termD);
	actualResults = isCardExpired(&cardD, &termD);
	printf("Expected Results: EXPIRED_CARD\n");
	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXPIRED_CARD\n");
	/*....................................................................................*/
	printf("............................................................................\n");
	printf("                 TEST CASE 2\n");
	//NOT EXPIRED CARD
	printf("Test Case 2: Not Expired Card\n");
	printf("Input Data --> Card Expiration Date: ");
	actualResults = getCardExpiryDate(&cardD);
	printf("Input Data --> Transaction Date : ");
	actualResults = getTransactionDate(&termD);
	actualResults = isCardExpired(&cardD, &termD);
	printf("Expected Results: TERMINAL_OK\n");
	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXPIRED_CARD\n");
}
/*.................................................................................*/
void getTransactionAmountTest(void)
{
	ST_terminalData_t termA;
	EN_terminalError_t actual_result;
	uint8_t expectedresult[20];
	printf("Tester Name: Jana\n");
	printf("Function Name: getTransactionAmount\n");
	printf("                 TEST CASE 1\n");
	/*Less Than 0*/
	printf("Test Case 2: Value is Less Than 0\n");
	printf("Input Data: ");
	actual_result = getTransactionAmount(&termA);
	// array, null value , size
	printf("Expected Results: INVALID_AMOUNT\n");
	memset(expectedresult, '\0', sizeof(termA.transAmount));
	printf("Actual Results: ");
	actual_result == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_AMOUNT\n");
	/*.................................................................................*/
	printf("............................................................................\n");
	printf("                     TEST CASE 2 \n");
	/*Equal 0*/
	printf("Test Case 3: Value is 0\n");
	printf("Input Data: ");
	actual_result = getTransactionAmount(&termA);
	// array, null value , size
	printf("Expected Results: WRONG_NAME\n");
	memset(expectedresult, '\0', sizeof(termA.transAmount));
	printf("Actual Results: ");
	actual_result == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_AMOUNT\n");
	printf("............................................................................\n");
	printf("                     TEST CASE 3 \n");
	/* Valid Input */
	printf("Test Case 4: Valid Input\n");
	printf("Input Data: ");
	actual_result = getTransactionAmount(&termA);
	// array, null value , size
	printf("Expected Results: TERMINAL_OK\n");
	memset(expectedresult, '\0', sizeof(termA.transAmount));
	printf("Actual Results: ");
	actual_result == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_AMOUNT\n");
}
/*.................................................................................*/
void isBelowMaxAmountTest(void)
{
	ST_terminalData_t termBM;
	EN_terminalError_t actualResults;

	printf("Tester Name: Jana\n");
	printf("Function Name: isBelowMaxAmount\n");
	printf("                 TEST CASE 1\n");
	//EXCEED MAX AMOUNT
	printf("Test Case 1: Exceed Max Amount\n");

	printf("Input Data Where the Max Amount is 1000.0: 22000.0\n");
	termBM.maxTransAmount = 1000.0;
	termBM.transAmount = 2200.0;
	actualResults = isBelowMaxAmount(&termBM);
	printf("Expected Results: EXCEED_MAX_AMOUNT\n");
	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXCEED_MAX_AMOUNT\n");
	/*..................................................................................*/
	printf("............................................................................\n");
	printf("                 TEST CASE 1\n");
	printf("Test Case 2: Below Max Amount\n");
	printf("Input Data Where the Max Amount is 1000.0: 500.0\n");
	termBM.maxTransAmount = 1000.0;
	termBM.transAmount = 500.0;
	actualResults = isBelowMaxAmount(&termBM);
	printf("Expected Results: TERMINAL_OK\n");
	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXCEED_MAX_AMOUNT\n");
}
/*................................................................................*/
void setMaxAmountTest(void)
{
	ST_terminalData_t termSM;
	EN_terminalError_t actualResults;
	float maxAmount;
	printf("Tester Name: Jana\n");
	printf("Function Name: setMaxAmount\n");
	printf("                 TEST CASE 1\n");
	printf("Test Case 1: Value is Less Than 0 \n");
	printf("Input Data : -500.0\n");
	maxAmount = -500.0;
	actualResults = setMaxAmount(&termSM, maxAmount);
	printf("Expected Results: INVALID_MAX_AMOUNT\n");
	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXCEED_MAX_AMOUNT\n");
	/*.....................................................................................*/
	printf("                 TEST CASE 2\n");
	printf("Test Case 2: Value Equals 0 \n");
	printf("Input Data : 0.0\n");
	maxAmount = 0.0;
	actualResults = setMaxAmount(&termSM, maxAmount);
	printf("Expected Results: INVALID_MAX_AMOUNT\n");
	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_MAX_AMOUNT\n");
	/*......................................................................................*/
	printf("                 TEST CASE 3\n");
	printf("Test Case 3: Valid Data\n");
	printf("Input Data : 250.0\n");
	maxAmount = 250.0;
	actualResults = setMaxAmount(&termSM, maxAmount);
	printf("Expected Results: TERMINAL_OK\n");
	printf("Actual Results:");
	actualResults == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_MAX_AMOUNT\n");
}


/*................................................................................*/


void main(void) 
{
	getTransactionDateTest();
	//getTransactionAmountTest();
	//isBelowMaxAmountTest();
    //isCardExpriedTest();
	//setMaxAmountTest();
	/*...................................................................................................*/
	/*printf("Enter The Transaction Date: \n");
	ST_terminalData_t terminal;
	EN_terminalError_t term_date_state = getTransactionDate(&terminal);
	term_date_state == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("WRONG_DATE\n");*/
	/////*.....................................................................................*/
	////printf("Enter The Transaction Amount: \n");
	////ST_terminalData_t terminalAm;
	////EN_terminalError_t term_trans_amount = getTransactionAmount(&terminalAm);
	////term_trans_amount == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_AMOUNT");
	/////*....................................................................................*/
	////printf("Enter The Maximum Amount: \n");
	////ST_terminalData_t termMax;
	////float Maxamount = 0.0;
	////EN_terminalError_t termMaxstate = setMaxAmount(&termMax, Maxamount);
	////termMaxstate == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("INVALID_MAX_AMOUNT\n");
	///*....................................................................................*/
	/*printf("Enter The Card Expiration Date: ");
	ST_terminalData_t termdate;
	ST_cardData_t carddate;
	getCardExpiryDate(&carddate);
	printf("Enter The Transaction Date: ");
	getTransactionDate(&termdate);
	EN_terminalError_t termcarddatestate = isCardExpired(&carddate, &termdate);
	termcarddatestate == TERMINAL_OK ? printf("TERMINAL_OK\n") : printf("EXPIRED_CARD\n");*/
}