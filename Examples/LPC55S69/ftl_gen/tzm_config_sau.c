/*
 * Copyright 2019 Arm Limited
 *
 * SPDX-License-Identifier: Apache 2.0
 */

#include "tzm_config.h" 
#include "fsl_common.h"

void TZM_Config_SAU(void)
{
    /* Disable SAU */
    SAU->CTRL = 0U;
    
    /* Configure SAU region 0 - CODE_NS */
    /* Set SAU region number */
    SAU->RNR = 0;
    /* Region base address */   
    SAU->RBAR = 0x10000;
    /* Region end address */
    SAU->RLAR = (0x81FFF & SAU_RLAR_LADDR_Msk) | 
                 /* Region memory attribute index */
                 ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                 /* Enable region */
                 ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);
    /* Configure SAU region 1 - Veneer */
    /* Set SAU region number */
    SAU->RNR = 1;
    /* Region base address */   
    SAU->RBAR = 0x1000FE00;
    /* Region end address */
    SAU->RLAR = (0x1000FFFF & SAU_RLAR_LADDR_Msk) | 
                 /* Region memory attribute index */
                 ((1U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                 /* Enable region */
                 ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);
    /* Configure SAU region 2 - DATA_NS */
    /* Set SAU region number */
    SAU->RNR = 2;
    /* Region base address */   
    SAU->RBAR = 0x20008000;
    /* Region end address */
    SAU->RLAR = (0x20043FFF & SAU_RLAR_LADDR_Msk) | 
                 /* Region memory attribute index */
                 ((0U << SAU_RLAR_NSC_Pos) & SAU_RLAR_NSC_Msk) |
                 /* Enable region */
                 ((1U << SAU_RLAR_ENABLE_Pos) & SAU_RLAR_ENABLE_Msk);
                 
     /* Force memory writes before continuing */
    __DSB();
    /* Flush and refill pipeline with updated permissions */
    __ISB();     
    /* Enable SAU */
    SAU->CTRL = 1U;                    
}
