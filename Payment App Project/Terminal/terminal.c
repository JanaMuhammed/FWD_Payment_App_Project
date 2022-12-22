#include <stdio.h>
#include <stdint.h>
#include "../Card/card.h"
#include "terminal.h"
EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	EN_terminalError_t returnValueT = TERMINAL_OK;
	(void)gets(termData->transactionDate);
	uint8_t length = strlen(termData->transactionDate);
	if (length != 10)
	{
		returnValueT = WRONG_DATE;
	}
	else if
		(!isdigit(termData->transactionDate[0]) ||
			!isdigit(termData->transactionDate[1]) ||
			!isdigit(termData->transactionDate[3]) ||
			!isdigit(termData->transactionDate[4]) ||
			!isdigit(termData->transactionDate[6]) ||
			!isdigit(termData->transactionDate[7]) ||
			!isdigit(termData->transactionDate[8]) ||
			!isdigit(termData->transactionDate[9]) ||
			(termData->transactionDate[3] == '0' && termData->transactionDate[4] == '2'
				&& termData->transactionDate[0] > '2') ||
			termData->transactionDate[0] > '3' ||
			(termData->transactionDate[0] <= '3' && termData->transactionDate[4] > '2') ||
			termData->transactionDate[2] != '/' ||
			termData->transactionDate[5] != '/'
			)
	{
		returnValueT = WRONG_DATE;
	}
	return returnValueT;
}
/*.........................................................*/

EN_terminalError_t isCardExpired(ST_cardData_t* cardData, ST_terminalData_t* termData)
{
	EN_terminalError_t returnValueDate = TERMINAL_OK;
	/*CARD YEAR --> pos 3,4*/
	uint8_t expdateCardfirstYearpos = cardData->cardExpirationDate[3];
	uint8_t expdateCardlastYearpos = cardData->cardExpirationDate[4];
	uint8_t expirationYearofCard = 10 * expdateCardfirstYearpos + expdateCardlastYearpos; //convert to decimal

	/*CARD MONTH --> pos 0,1*/
	uint8_t expdateCardfirstMonthpos = cardData->cardExpirationDate[0];
	uint8_t expdateCardlastMothpos = cardData->cardExpirationDate[1];
	uint8_t expirationMonthofCard = 10 * expdateCardfirstMonthpos + expdateCardlastMothpos;

	/*TRANSACTION YEAR ONLY THE LAST TWO DIGITS WILL BE COMPARED TO MATCH THE CARD DATE --> pos8,9*/
	uint8_t transdatefirstYearpos = termData->transactionDate[8];
	uint8_t transdatelastYearpos = termData->transactionDate[9];
	uint8_t transdateYear = 10 * transdatefirstYearpos + transdatelastYearpos;

	/*TRANSACTION MONTH --> pos 3,4*/
	uint8_t transdatefirstMonthpos = termData->transactionDate[3];
	uint8_t transdatelastMonthpos = termData->transactionDate[4];
	uint8_t transdateMonth = 10 * transdatefirstMonthpos + transdatelastMonthpos;

	/*COMPARE THE DATES*/
	if ((expirationYearofCard < transdateYear) || (expirationMonthofCard < transdateMonth))
	{
		returnValueDate = EXPIRED_CARD;
	}
	return returnValueDate;
}
/*........................................................*/

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t returnValueTrans = TERMINAL_OK;
	scanf_s("%f",&termData->transAmount);
	if (termData->transAmount <= 0.0)
	{
		returnValueTrans = INVALID_AMOUNT;
	}
	return returnValueTrans;
}
/*.......................................................*/

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	EN_terminalError_t returnBmax = TERMINAL_OK;
	if (termData->transAmount > termData->maxTransAmount)
	{
		returnBmax = EXCEED_MAX_AMOUNT;
	}
	return returnBmax;
}

/*.......................................................*/

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData, float maxAmount)
{
	EN_terminalError_t returnSetmax = TERMINAL_OK;
	if (termData->maxTransAmount <= 0)
	{
		returnSetmax = INVALID_MAX_AMOUNT;
	}
	else
	{
		returnSetmax = TERMINAL_OK;
		termData->maxTransAmount = maxAmount;
	}
	return returnSetmax;
}