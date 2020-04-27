#ifndef OCCA_C_BASE_HEADER
#define OCCA_C_BASE_HEADER

#include <occa/c/defines.h>
#include <occa/c/types.h>

OCCA_START_EXTERN_C

//---[ Globals & Flags ]----------------
OCCA_LFUNC occaProperties OCCA_RFUNC occaSettings();

OCCA_LFUNC void OCCA_RFUNC occaPrintModeInfo();
//======================================

//---[ Device ]-------------------------
OCCA_LFUNC occaDevice OCCA_RFUNC occaHost();

OCCA_LFUNC occaDevice OCCA_RFUNC occaGetDevice();

OCCA_LFUNC void OCCA_RFUNC occaSetDevice(occaDevice device);

OCCA_LFUNC void OCCA_RFUNC occaSetDeviceFromString(const char *info);

OCCA_LFUNC occaProperties OCCA_RFUNC occaDeviceProperties();

OCCA_LFUNC void OCCA_RFUNC occaLoadKernels(const char *library);

OCCA_LFUNC void OCCA_RFUNC occaFinish();

OCCA_LFUNC occaStream OCCA_RFUNC occaCreateStream();

OCCA_LFUNC occaStream OCCA_RFUNC occaCreateStreamProps(occaProperties props);

OCCA_LFUNC occaStream OCCA_RFUNC occaGetStream();

OCCA_LFUNC void OCCA_RFUNC occaSetStream(occaStream stream);

OCCA_LFUNC occaStreamTag OCCA_RFUNC occaTagStream();

OCCA_LFUNC void OCCA_RFUNC occaWaitForTag(occaStreamTag tag);

OCCA_LFUNC double OCCA_RFUNC occaTimeBetweenTags(occaStreamTag startTag,
                                                 occaStreamTag endTag);
//======================================

//---[ Kernel ]-------------------------
OCCA_LFUNC occaKernel OCCA_RFUNC occaBuildKernel(const char *filename,
                                                 const char *kernelName);

OCCA_LFUNC occaKernel OCCA_RFUNC occaBuildKernelProps(const char *filename,
                                                      const char *kernelName,
                                                      const occaProperties props);

OCCA_LFUNC occaKernel OCCA_RFUNC occaBuildKernelFromString(const char *source,
                                                           const char *kernelName);

OCCA_LFUNC occaKernel OCCA_RFUNC occaBuildKernelFromStringProps(const char *source,
                                                                const char *kernelName,
                                                                const occaProperties props);

OCCA_LFUNC occaKernel OCCA_RFUNC occaBuildKernelFromBinary(const char *filename,
                                                           const char *kernelName);

OCCA_LFUNC occaKernel OCCA_RFUNC occaBuildKernelFromBinaryProps(const char *filename,
                                                                const char *kernelName,
                                                                const occaProperties props);
//======================================

//---[ Memory ]-------------------------
OCCA_LFUNC occaMemory OCCA_RFUNC occaMalloc(const occaUDim_t bytes,
                                            const void *src);

OCCA_LFUNC occaMemory OCCA_RFUNC occaMallocProps(const occaUDim_t bytes,
                                                 const void *src,
                                                 occaProperties props);

OCCA_LFUNC occaMemory OCCA_RFUNC occaTypedMalloc(const occaUDim_t entries,
                                                 const occaDtype type,
                                                 const void *src);

OCCA_LFUNC occaMemory OCCA_RFUNC occaTypedMallocProps(const occaUDim_t entries,
                                                      const occaDtype type,
                                                      const void *src,
                                                      occaProperties props);

OCCA_LFUNC void* OCCA_RFUNC occaUMalloc(const occaUDim_t bytes,
                                        const void *src);

OCCA_LFUNC void* OCCA_RFUNC occaUMallocProps(const occaUDim_t bytes,
                                             const void *src,
                                             occaProperties props);

OCCA_LFUNC void* OCCA_RFUNC occaTypedUMalloc(const occaUDim_t entries,
                                             const occaDtype type,
                                             const void *src);

OCCA_LFUNC void* OCCA_RFUNC occaTypedUMallocProps(const occaUDim_t entries,
                                                  const occaDtype type,
                                                  const void *src,
                                                  occaProperties props);
//======================================

OCCA_END_EXTERN_C

#endif
