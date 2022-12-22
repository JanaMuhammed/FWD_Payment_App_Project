#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "../Card/card.h"
#include "../Terminal/terminal.h"
#include "server.h"

ST_accountsDB_t accountsDB[255] =
{
	{8000.0,    RUNNING, "8989374615436851"},
	{9000.0,    RUNNING, "1934826479225623"},
	{7000.0,    RUNNING, "1289746321598745"},
	{6000.0,    RUNNING, "1297523469723458"},
	{1000.0,    BLOCKED, "4297853278521964"},
	{2000.0,    RUNNING, "1593258793269745"},
	{3000.0,    RUNNING, "3976378254197267"},
	{5000.0,    RUNNING, "2659542157876545"},
	{4000.0,    RUNNING, "4543543534543567"},
	{7000.0,    BLOCKED, "2135448353457898"},
};

ST_transaction_t transactionsDB[255] = {0};


