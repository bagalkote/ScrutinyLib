/*
 *
 * Copyright (C) 2019 - 2020 Broadcom.
 * The term "Broadcom" refers to Broadcom Inc. and/or its subsidiaries.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1.Redistributions of source code must retain the above copyright notice, 
 *   this list of conditions and the following disclaimer.
 *
 * 2.Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * 3.Neither the name of the copyright holder nor the names of its contributors
 *   may be used to endorse or promote products derived from this software without
 *   specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES 
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 *
*/
#ifndef __SWITCH_PORT_COUNTERS__H__

#define __SWITCH_PORT_COUNTERS__H__

#define SET_32BIT_REGISTER_VALUE(REGISTER, MASK, VALUE) ((REGISTER & ~MASK) | (VALUE * (MASK & (U32) (0 - MASK))))


SCRUTINY_STATUS spciGetPciPortErrorStatistic (
    __IN__ PTR_SCRUTINY_DEVICE 	PtrDevice, 
    __IN__ U32 				  	Port, 
    __OUT__ PTR_SCRUTINY_SWITCH_ERROR_STATISTICS PtrPciePortErrStatistic
    );


BOOLEAN spcIsPortEnabled (
	__IN__ PTR_SCRUTINY_DEVICE  	PtrDevice,
	__IN__ U32						PortNum
	);

SCRUTINY_STATUS spcGetPciPortMaxLinkWidth (
	__IN__ PTR_SCRUTINY_DEVICE		PtrDevice,
	__IN__ U32						PortNum,
	__OUT__ PU32					PtrMaxLinkWidth
	);

SCRUTINY_STATUS spcGetPciPortNegLinkWidth (
	__IN__ PTR_SCRUTINY_DEVICE		PtrDevice,
	__IN__ U32						PortNum,
	__OUT__ PU32					PtrNegLinkWidth
	);

SCRUTINY_STATUS spcGetAdvancedErrorStatus  (
    __IN__ PTR_SCRUTINY_DEVICE PtrDevice, 
    __IN__ U32 PortNum, 
    __OUT__ PTR_SCRUTINY_SWITCH_ADVANCED_ERROR_STATUS PtrErrorStatus 
    );

SCRUTINY_STATUS spcGetErrorCounters (
    __IN__  PTR_SCRUTINY_DEVICE PtrDevice, 
    __IN__  U32 PortNum, 
    __OUT__ PTR_SCRUTINY_SWITCH_ERROR_COUNTERS PtrErrorCounters
);

SCRUTINY_STATUS atlasPCIeConfigurationSpaceRead (
    __IN__  PTR_SCRUTINY_DEVICE PtrDevice, 
    __IN__  U32 Port, 
    __IN__  U32 Offset, 
    __OUT__ PU32 PtrValue
);

SCRUTINY_STATUS atlasPCIeConfigurationSpaceWrite ( 
    __IN__  PTR_SCRUTINY_DEVICE PtrDevice, 
    __IN__  U32 Port, 
    __IN__  U32 Offset, 
    __IN__  U32 Value
);

#endif