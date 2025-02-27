/*
 * Copyright (c) 2009-2018 Arm Limited. All rights reserved.
 * Copyright (c) 2019 Nuclei Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*******************************************************************************
 * @file     system_NUCLEI_N.h
 * @brief    NMSIS Nuclei Device Peripheral Access Layer Header File for
 *           Nuclei N Device
 * @version  V1.00
 * @date     18. Dec 2019
 ******************************************************************************/

#ifndef __SYSTEM_NUCLEI_N_H__
#define __SYSTEM_NUCLEI_N_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

extern uint32_t SystemCoreClock;     /*!< System Clock Frequency (Core Clock)  */

/**
 * \brief Setup the microcontroller system.
 * \details
 *  Initialize the System and update the SystemCoreClock variable.
 */
extern void SystemInit(void);

/**
 * \brief  Update SystemCoreClock variable.
 * \details
 *  Updates the SystemCoreClock with current core Clock retrieved from cpu registers.
 */
extern void SystemCoreClockUpdate(void);

/** 
 * \brief Register an exception handler for exception code EXCn
 */
extern void Exception_Register_EXC(uint32_t EXCn, unsigned long exc_handler);

/** 
 * \brief Get current exception handler for exception code EXCn
 */
extern unsigned long Exception_Get_EXC(uint32_t EXCn);

/**
 * \brief Initialize eclic config
 */
extern void ECLIC_Init(void);

/**
 * \brief  initialize a specific IRQ and register the handler
 * \details
 * This function set vector mode, trigger mode and polarity, interrupt level and priority,
 * assign handler for specific IRQn.
 * \param [in]  IRQn        NMI interrupt handler address
 * \param [in]  shv         \ref ECLIC_NON_VECTOR_INTERRUPT means non-vector mode, and \ref ECLIC_VECTOR_INTERRUPT is vector mode
 * \param [in]  trig_mode   see \ref ECLIC_TRIGGER_Type
 * \param [in]  lvl         interupt level
 * \param [in]  priority    interrupt priority
 * \param [in]  handler     interrupt handler
 * return       -1 means invalid input parameter. 0 means successful.
 * \remarks
 * - This function use to configure specific eclic interrupt and register its interrupt handler and enable its interrupt.
 */
extern int32_t ECLIC_Register_IRQ(IRQn_Type IRQn, uint8_t shv, ECLIC_TRIGGER_Type trig_mode, uint8_t lvl, uint8_t priority, void *handler);

#ifdef __cplusplus
}
#endif

#endif /* __SYSTEM_NUCLEI_N_H__ */
