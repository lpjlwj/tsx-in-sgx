#include <stdarg.h>
#include <stdio.h>

#include "Enclave.h"
#include "Enclave_t.h"
#include "rtm.h"

void PrintDebugInfo(const char *fmt, ...)
{
	char buf[BUFSIZ] = {'\0'};
	va_list ap;
	va_start(ap, fmt);
	vsnprintf(buf, BUFSIZ, fmt, ap);
	va_end(ap);
	Ocall_PrintString(buf);
}
void rtm_test(){
	int status;
	int nonce = 0;
	int mutex = 0;

	PrintDebugInfo("--- test 1 ---\n");
	if ((status = _xbegin()) == _XBEGIN_STARTED) {
		mutex = 1;
		_xend();
	} else {
		PrintDebugInfo("trans failed...\n");
	}
	PrintDebugInfo("aborted status %x, # %d\n", status, _XABORT_CODE(status));

	PrintDebugInfo("--- test 2 ---\n");
	if ((status = _xbegin()) == _XBEGIN_STARTED) {
		mutex = 2;
		_xabort(1);
		_xend();
	}
	else {
		PrintDebugInfo("entering fallback:\n");
		PrintDebugInfo("aborted status %x, # %d\n", status, _XABORT_CODE(status));
	}

	PrintDebugInfo("--- test 3 ---\n");
	if ((status = _xbegin()) == _XBEGIN_STARTED) {
		if (_xtest()) {
		}
		_xend();
	} else
		PrintDebugInfo("aborted status %x, # %d\n", status, _XABORT_CODE(status));

}
