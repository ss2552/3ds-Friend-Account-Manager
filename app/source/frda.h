#pragma once

#include <3ds/types.h>

Result frdInit();
void frdExit();
Handle *frdAGetSessionHandle();
Result FRDA_DeleteLocalAccount(u8 localAccountId);
