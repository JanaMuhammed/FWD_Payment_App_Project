#include <stdio.h>
#include <stdint.h>
#include "card.h"

EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	EN_cardError_t returnVal = CARD_OK;
	(void)gets(cardData->cardHolderName);
	uint8_t length = strlen(cardData->cardHolderName);
	if (length > 24 || length < 20)
	{
		returnVal = WRONG_NAME;
	}
	return returnVal;
}

/*............................................................................................*/

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	EN_cardError_t returnValue = CARD_OK;
	(void)gets(cardData->cardExpirationDate);
	uint8_t length = strlen(cardData->cardExpirationDate);
	//max length = 5
	if (length != 5)
	{
		returnValue = WRONG_EXP_DATE;
	}

	else if (
		!isdigit(cardData->cardExpirationDate[0]) ||
		!isdigit(cardData->cardExpirationDate[1]) ||
		!isdigit(cardData->cardExpirationDate[3]) ||
		!isdigit(cardData->cardExpirationDate[4]) ||
		cardData->cardExpirationDate[0] > '1' ||
		(cardData->cardExpirationDate[0] > '1' && cardData->cardExpirationDate[1] > '2') 
		|| (cardData->cardExpirationDate[0] == '1' && cardData->cardExpirationDate[1] > '2')
		|| cardData->cardExpirationDate[2] != '/')
	{
		returnValue = WRONG_EXP_DATE;
	}
	
	return returnValue;
	
}

/*............................................................................................*/

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	EN_cardError_t returnVal = CARD_OK;
	(void)gets(cardData->primaryAccountNumber);
	uint8_t length = strlen(cardData->primaryAccountNumber);
	if (length > 19 || length < 16)
	{
		returnVal = WRONG_PAN;
	}
	return returnVal;
}

/*............................................................................................*/