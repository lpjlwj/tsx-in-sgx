#ifndef ENCLAVE_U_H__
#define ENCLAVE_U_H__

#include <stdint.h>
#include <wchar.h>
#include <stddef.h>
#include <string.h>
#include "sgx_edger8r.h" /* for sgx_status_t etc. */

#include "user_types.h"

#include <stdlib.h> /* for size_t */

#define SGX_CAST(type, item) ((type)(item))

#ifdef __cplusplus
extern "C" {
#endif

#ifndef OCALL_PRINTSTRING_DEFINED__
#define OCALL_PRINTSTRING_DEFINED__
void SGX_UBRIDGE(SGX_NOCONVENTION, Ocall_PrintString, (const char* str));
#endif

sgx_status_t rtm_test1(sgx_enclave_id_t eid);
sgx_status_t rtm_test2(sgx_enclave_id_t eid);
sgx_status_t rtm_test3(sgx_enclave_id_t eid);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
