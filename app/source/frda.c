/*
This file was originally taken from
https://github.com/devkitPro/libctru/blob/6360f4bdb1ca5f8131ffc92640c1dd16afb63083/libctru/source/services/frd.c
and modified to:
- Remove every command, except FRD_SetClientSdkVersion
- Add FRDA_CreateLocalAccount and FRDA_SetLocalAccountId
- Only allow frd:a to be used
*/

#include "./frda.h"
#include <3ds/ipc.h>
#include <3ds/result.h>
#include <3ds/srv.h>
#include <3ds/svc.h>
#include <3ds/synchronization.h>
#include <3ds/types.h>

static Handle frdHandle;
static int frdRefCount;

Result frdInit(bool forceUser)
{
	Result ret = 0;

	if (AtomicPostIncrement(&frdRefCount)) return 0;

	if (forceUser)
		ret = srvGetServiceHandle(&frdHandle, "frd:u");
	else
		ret = srvGetServiceHandle(&frdHandle, "frd:a");

	if (R_FAILED(ret))
		AtomicDecrement(&frdRefCount);

	return ret;
}

void frdExit(void)
{
	if (AtomicDecrement(&frdRefCount)) return;
	svcCloseHandle(frdHandle);
}

Result FRDA_DeleteLocalAccount(u8 localAccountId)
{
	Result ret = 0;
	u32 *cmdbuf = getThreadCommandBuffer();
	cmdbuf[0] = IPC_MakeHeader(0x402,1,0); // 0x4020040
	cmdbuf[1] = (u32)localAccountId;

	if (R_FAILED(ret = svcSendSyncRequest(frdHandle))) return ret;

	return (Result)cmdbuf[1];
}
