#include<stdio.h>
#include<stdint.h>
#include "card.h"
/*TEST THE NAME*/
void getCardHolderNameTest(void) 
{
	ST_cardData_t card;
	EN_cardError_t actual_result;
	uint8_t expectedresult[20];
	printf("Tester Name: Jana\n");
	printf("Function Name: getCardHolderName\n");
	printf("                 TEST CASE 1\n");
	/*NULL Test Case*/
	printf("Test Case 1: NULL Value\n");
	printf("Input Data: ");
	actual_result = getCardHolderName(&card);
	// array, null value , size
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));
	printf("Expected Results: WRONG_NAME\n");
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");
	/*.................................................................................*/
	printf("                 TEST CASE 2\n");
	/*More Than 24*/
	printf("Test Case 2: Value is Greater Than 24\n");
	printf("Input Data: ");
	actual_result = getCardHolderName(&card);
	// array, null value , size
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));
	printf("Expected Results: WRONG_NAME\n");
	memset(expectedresult, '\0', sizeof(card.cardHolderName));
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");
	/*.................................................................................*/
	printf("                     TEST CASE 3 \n");
	/*Less Than 20*/
	printf("Test Case 3: Value is Less Than 20\n");
	printf("Input Data: ");
	actual_result = getCardHolderName(&card);
	// array, null value , size
	memset(card.cardHolderName, '\0', sizeof(card.cardHolderName));
	printf("Expected Results: WRONG_NAME\n");
	memset(expectedresult, '\0', sizeof(card.cardHolderName));
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");
	/*............................................................................*/
	printf("                       TEST CASE 4\n");
	/*Valid Input*/
	printf("Test Case 4: Valid Input\n");
	printf("Input Data: ");
	actual_result = getCardHolderName(&card);
	printf("Expected Results: CARD_OK\n");
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");
}
/*TEST THE DATE*/
void getCardExpiryDateTest(void)
{
	ST_cardData_t card;
	EN_cardError_t actual_result;
	uint8_t expectedresult[20];
	printf("Tester Name: Jana\n");
	printf("Function Name: getCardExpiryDate\n");
	printf("                 TEST CASE 1\n");
	/*NULL Test Case*/
	printf("Test Case 1: NULL Value\n");
	printf("Input Data: ");
	actual_result = getCardExpiryDate(&card);
	// array, null value , size
	memset(card.cardExpirationDate, '\0', sizeof(card.cardExpirationDate));
	printf("Expected Results: WRONG_EXP_DATE\n");
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("Wrong_EXP_DATE\n");
	printf("............................................................................\n");
	printf("                 TEST CASE 2\n");
	/*More Than 5 characters*/
	printf("Test Case 2: More Than 5 Characters\n");
	printf("Input Data: ");
	actual_result = getCardExpiryDate(&card);
	// array, null value , size
	memset(card.cardExpirationDate, '\0', sizeof(card.cardExpirationDate));
	printf("Expected Results: WRONG_EXP_DATE\n");
	memset(expectedresult, '\0', sizeof(card.cardExpirationDate));
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");
	printf("............................................................................\n");
	printf("                     TEST CASE 3 \n");
	/*Less Than 5 characters*/
	printf("Test Case 3: Less Than 5 Characters\n");
	printf("Input Data: ");
	actual_result = getCardExpiryDate(&card);
	// array, null value , size
	memset(card.cardExpirationDate, '\0', sizeof(card.cardExpirationDate));
	printf("Expected Results: WRONG_EXP_DATE\n");
	memset(expectedresult, '\0', sizeof(card.cardExpirationDate));
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");
	printf("............................................................................\n");
	printf("                       TEST CASE 4\n");
	/*Invalid Format*/
	printf("Test Case 4: Invalid Format\n");
	printf("Input Data: ");
	actual_result = getCardExpiryDate(&card);
	// array, null value , size
	memset(card.cardExpirationDate, '\0', sizeof(card.cardExpirationDate));
	printf("Expected Results: WRONG_EXP_DATE\n");
	memset(expectedresult, '\0', sizeof(card.cardExpirationDate));

	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");
	printf("............................................................................\n");
	printf("                       TEST CASE 5\n");
	/*Valid Input*/
	printf("Test Case 5: Valid Input\n");
	printf("Input Data: ");
	actual_result = getCardExpiryDate(&card);
	printf("Expected Results: CARD_OK\n");
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");
}
/*TEST PAN*/
void getCardPanTest(void)
{
	ST_cardData_t card;
	EN_cardError_t actual_result;
	uint8_t expectedresult[20];
	printf("Tester Name: Jana\n");
	printf("Function Name: getCardPAN\n");
	printf("                 TEST CASE 1\n");
	/*NULL Test Case*/
	printf("Test Case 1: NULL Value\n");
	printf("Input Data: ");
	actual_result = getCardPAN(&card);
	// array, null value , size
	memset(card.primaryAccountNumber, '\0', sizeof(card.primaryAccountNumber));
	printf("Expected Results: WRONG_PAN\n");
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_PAN\n");
	/*.................................................................................*/
	printf("                 TEST CASE 2\n");
	/*More Than 19*/
	printf("Test Case 2: Value is Greater Than 19\n");
	printf("Input Data: ");
	actual_result = getCardPAN(&card);
	// array, null value , size
	memset(card.primaryAccountNumber, '\0', sizeof(card.primaryAccountNumber));
	printf("Expected Results: WRONG_PAN\n");
	memset(expectedresult, '\0', sizeof(card.primaryAccountNumber));
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_PAN\n");
	/*.................................................................................*/
	printf("                     TEST CASE 3 \n");
	/*Less Than 20*/
	printf("Test Case 3: Value is Less Than 16\n");
	printf("Input Data: ");
	actual_result = getCardPAN(&card);
	// array, null value , size
	memset(card.primaryAccountNumber, '\0', sizeof(card.primaryAccountNumber));
	printf("Expected Results: WRONG_NAME\n");
	memset(expectedresult, '\0', sizeof(card.primaryAccountNumber));
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_PAN\n");
	/*............................................................................*/
	printf("                       TEST CASE 5\n");
	/*Valid Input*/
	printf("Test Case 4: Valid Input\n");
	printf("Input Data: ");
	actual_result = getCardPAN(&card);
	printf("Expected Results: CARD_OK\n");
	printf("Actual Results: ");
	actual_result == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_PAN\n");
}





void main(void)
{
	getCardHolderNameTest();
	/*..........................................................................*/
	//getCardExpiryDateTest();
	/*..........................................................................*/
	getCardPanTest();
	/*..........................................................................*/
	//ST_cardData_t card;
		//EN_cardError_t state = getCardHolderName(&card);
		//state == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_NAME\n");
		/*..........................................................................*/

		//EN_cardError_t datestate = getCardExpiryDate(&card);
		//datestate == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_EXP_DATE\n");
		/*..........................................................................*/
		//EN_cardError_t panstate = getCardPAN(&card);
		//panstate == CARD_OK ? printf("CARD_OK\n") : printf("WRONG_PAN");
}
