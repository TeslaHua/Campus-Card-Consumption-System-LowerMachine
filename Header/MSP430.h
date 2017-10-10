#ifndef __MSP340_H
#define __MSP340_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long uint32;



//#define _EINT()        __enable_interrupt()

/* ----------------------------------------------------------------------------
   -- GPIO
   ---------------------------------------------------------------------------- */
/** P1_2 - Peripheral register structure */
typedef struct P1_2_MemMap {
  uint8 PIN;
  uint8 POUT;
  uint8 PDIR;
  uint8 PIFG;
  uint8 PIES;
  uint8 PIE;
  uint8 PSEL;
} volatile *P1_2_MemMapPtr;

/** P3_6 - Peripheral register structure */
typedef struct P3_6_MemMap {
  uint8 PIN;
  uint8 POUT;
  uint8 PDIR;
  uint8 PSEL;
} volatile *P3_6_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */
/* GPIO - Register accessors */
#define GPIO_PIN_REG(base)                       ((base)->PIN)
#define GPIO_POUT_REG(base)                      ((base)->POUT)
#define GPIO_PDIR_REG(base)                      ((base)->PDIR)
#define GPIO_PIFG_REG(base)                      ((base)->PIFG)
#define GPIO_PIES_REG(base)                      ((base)->PIES)
#define GPIO_PIE_REG(base)                       ((base)->PIE)
#define GPIO_PSEL_REG(base)                      ((base)->PSEL)

/**
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- GPIO Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Register_Masks GPIO Register Masks
 * @{
 */

/* PIN Bit Fields */
#define GPIO_PIN_MASK                         0xFFu
#define GPIO_PIN_SHIFT                        0
#define GPIO_PIN(x)                           (((uint8)(((uint8)(x))<<GPIO_PIN_SHIFT))&GPIO_PIN_MASK)

/* POUT Bit Fields */
#define GPIO_POUT_MASK                        0xFFu
#define GPIO_POUT_SHIFT                       0
#define GPIO_POUT(x)                          (((uint8)(((uint8)(x))<<GPIO_POUT_SHIFT))&GPIO_POUT_MASK)

/* PDIR Bit Fields */
#define GPIO_PDIR_MASK                        0xFFu
#define GPIO_PDIR_SHIFT                       0
#define GPIO_PDIR(x)                          (((uint8)(((uint8)(x))<<GPIO_PDIR_SHIFT))&GPIO_PDIR_MASK)

/* PIFG Bit Fields */
#define GPIO_PIFG_MASK                        0xFFu
#define GPIO_PIFG_SHIFT                       0
#define GPIO_PIFG(x)                          (((uint8)(((uint8)(x))<<GPIO_PIFG_SHIFT))&GPIO_PIFG_MASK)

/* PIES Bit Fields */
#define GPIO_PIES_MASK                        0xFFu
#define GPIO_PIES_SHIFT                       0
#define GPIO_PIES(x)                          (((uint8)(((uint8)(x))<<GPIO_PIES_SHIFT))&GPIO_PIES_MASK)

/* PIE Bit Fields */
#define GPIO_PIE_MASK                         0xFFu
#define GPIO_PIE_SHIFT                        0
#define GPIO_PIE(x)                           (((uint8)(((uint8)(x))<<GPIO_PIE_SHIFT))&GPIO_PIE_MASK)

/* PSEL Bit Fields */
#define GPIO_PSEL_MASK                        0xFFu
#define GPIO_PSEL_SHIFT                       0
#define GPIO_PSEL(x)                          (((uint8)(((uint8)(x))<<GPIO_PSEL_SHIFT))&GPIO_PSEL_MASK) 
/**
 * @}
 */ /* end of group GPIO_Register_Masks */
 

/* GPIO - Peripheral instance base addresses */
/** Peripheral P1 base pointer */
#define P1_BASE_PTR                             ((P1_2_MemMapPtr)0x0020u)
/** Peripheral P2 base pointer */
#define P2_BASE_PTR                             ((P1_2_MemMapPtr)0x0028u)
/** Peripheral P3 base pointer */
#define P3_BASE_PTR                             ((P3_6_MemMapPtr)0x0018u)
/** Peripheral P4 base pointer */
#define P4_BASE_PTR                             ((P3_6_MemMapPtr)0x001Cu)
/** Peripheral P5 base pointer */
#define P5_BASE_PTR                             ((P3_6_MemMapPtr)0x0030u)
/** Peripheral P6 base pointer */
#define P6_BASE_PTR                             ((P3_6_MemMapPtr)0x0034u)

/* ----------------------------------------------------------------------------
   -- GPIO - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup GPIO_Register_Accessor_Macros GPIO - Register accessor macros
 * @{
 */


/* GPIO - Register instance definitions */
/* P1 */
#define P1_PIN                                   GPIO_PIN_REG(P1_BASE_PTR)
#define P1_POUT                                  GPIO_POUT_REG(P1_BASE_PTR)
#define P1_PDIR                                  GPIO_PDIR_REG(P1_BASE_PTR)
#define P1_PIFG                                  GPIO_PIFG_REG(P1_BASE_PTR)
#define P1_PIES                                  GPIO_PIES_REG(P1_BASE_PTR)                      
#define P1_PIE                                   GPIO_PIE_REG(P1_BASE_PTR)                       
#define P1_PSEL                                  GPIO_PSEL_REG(P1_BASE_PTR)                      
/* P2 */
#define P2_PIN                                   GPIO_PIN_REG(P2_BASE_PTR)
#define P2_POUT                                  GPIO_POUT_REG(P2_BASE_PTR)
#define P2_PDIR                                  GPIO_PDIR_REG(P2_BASE_PTR)
#define P2_PIFG                                  GPIO_PIFG_REG(P2_BASE_PTR)
#define P2_PIES                                  GPIO_PIES_REG(P2_BASE_PTR)                      
#define P2_PIE                                   GPIO_PIE_REG(P2_BASE_PTR)                       
#define P2_PSEL                                  GPIO_PSEL_REG(P2_BASE_PTR)     
/* P3 */
#define P3_PIN                                   GPIO_PIN_REG(P3_BASE_PTR)
#define P3_POUT                                  GPIO_POUT_REG(P3_BASE_PTR)
#define P3_PDIR                                  GPIO_PDIR_REG(P3_BASE_PTR)
#define P3_PSEL                                  GPIO_PSEL_REG(P3_BASE_PTR)
/* P4 */
#define P4_PIN                                   GPIO_PIN_REG(P4_BASE_PTR)
#define P4_POUT                                  GPIO_POUT_REG(P4_BASE_PTR)
#define P4_PDIR                                  GPIO_PDIR_REG(P4_BASE_PTR)
#define P4_PSEL                                  GPIO_PSEL_REG(P4_BASE_PTR)
/* P5 */
#define P5_PIN                                   GPIO_PIN_REG(P5_BASE_PTR)
#define P5_POUT                                  GPIO_POUT_REG(P5_BASE_PTR)
#define P5_PDIR                                  GPIO_PDIR_REG(P5_BASE_PTR)
#define P5_PSEL                                  GPIO_PSEL_REG(P5_BASE_PTR)
/* P6 */
#define P6_PIN                                   GPIO_PIN_REG(P6_BASE_PTR)
#define P6_POUT                                  GPIO_POUT_REG(P6_BASE_PTR)
#define P6_PDIR                                  GPIO_PDIR_REG(P6_BASE_PTR)
#define P6_PSEL                                  GPIO_PSEL_REG(P6_BASE_PTR)

/**
 * @}
 */ /* end of group GPIO_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group GPIO_Peripheral */



/* ----------------------------------------------------------------------------
   --Clock
   ---------------------------------------------------------------------------- */
/** CLK - Peripheral register structure */
typedef struct CLK_MemMap {
  uint8 DCOCTL;
  uint8 BCSCTL1;
  uint8 BCSCTL2;
} volatile *CLK_MemMapPtr;
/* ----------------------------------------------------------------------------
   -- CLK- Register accessor macros
   ---------------------------------------------------------------------------- */
/* CLK - Register accessors */
#define CLK_DCOCTL_REG(base)                       ((base)->DCOCTL)
#define CLK_BCSCTL1_REG(base)                      ((base)->BCSCTL1)
#define CLK_BCSCTL2_REG(base)                      ((base)->BCSCTL2)
/**
 * @}
 */ /* end of group CLK_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- CLK Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CLK_Register_Masks CLK Register Masks
 * @{
 */

/* DCOCTL Bit Fields */
#define CLK_DCOCTL_DCOx_MASK                         0xE0u
#define CLK_DCOCTL_DCOx_SHIFT                        5
#define CLK_DCOCTL_DCOx(x)                           (((uint8)(((uint8)(x))<<CLK_DCOCTL_DCOx_SHIFT))&CLK_DCOCTL_DCOx_MASK)

#define CLK_DCOCTL_MODx_MASK                         0x1Fu
#define CLK_DCOCTL_MODx_SHIFT                        0
#define CLK_DCOCTL_MODx(x)                           (((uint8)(((uint8)(x))<<CLK_DCOCTL_MODx_SHIFT))&CLK_DCOCTL_MODx_MASK)

/* BCSCTL1 Bit Fields */
#define CLK_BCSCTL1_XT2OFF_MASK                      0x80u
#define CLK_BCSCTL1_XT2OFF_SHIFT                     7
#define CLK_BCSCTL1_XT2OFF(x)                        (((uint8)(((uint8)(x))<<CLK_BCSCTL1_XT2OFF_SHIFT))&CLK_BCSCTL1_XT2OFF_MASK)

#define CLK_BCSCTL1_XTS_MASK                         0x40u
#define CLK_BCSCTL1_XTS_SHIFT                        6
#define CLK_BCSCTL1_XTS(x)                           (((uint8)(((uint8)(x))<<CLK_BCSCTL1_XTS_SHIFT))&CLK_BCSCTL1_XTS_MASK)

#define CLK_BCSCTL1_DIVAx_MASK                       0x30u
#define CLK_BCSCTL1_DIVAx_SHIFT                      4
#define CLK_BCSCTL1_DIVAx(x)                         (((uint8)(((uint8)(x))<<CLK_BCSCTL1_DIVAx_SHIFT))&CLK_BCSCTL1_DIVAx_MASK)

#define CLK_BCSCTL1_XT5V_MASK                        0x08u
#define CLK_BCSCTL1_XT5V_SHIFT                       3
#define CLK_BCSCTL1_XT5V(x)                          (((uint8)(((uint8)(x))<<CLK_BCSCTL1_XT5V_SHIFT))&CLK_BCSCTL1_XT5V_MASK)

#define CLK_BCSCTL1_RSELx_MASK                       0x07u
#define CLK_BCSCTL1_RSELx_SHIFT                      0
#define CLK_BCSCTL1_RSELx(x)                         (((uint8)(((uint8)(x))<<CLK_BCSCTL1_RSELx_SHIFT))&CLK_BCSCTL1_RSELx_MASK)

/* BCSCTL2 Bit Fields */
#define CLK_BCSCTL2_SELMx_MASK                       0xC0u
#define CLK_BCSCTL2_SELMx_SHIFT                      6
#define CLK_BCSCTL2_SELMx(x)                         (((uint8)(((uint8)(x))<<CLK_BCSCTL2_SELMx_SHIFT))&CLK_BCSCTL2_SELMx_MASK)

#define CLK_BCSCTL2_DIVMx_MASK                       0x30u
#define CLK_BCSCTL2_DIVMx_SHIFT                      4
#define CLK_BCSCTL2_DIVMx(x)                         (((uint8)(((uint8)(x))<<CLK_BCSCTL2_DIVMx_SHIFT))&CLK_BCSCTL2_DIVMx_MASK)

#define CLK_BCSCTL2_SELS_MASK                        0x08u
#define CLK_BCSCTL2_SELS_SHIFT                       3
#define CLK_BCSCTL2_SELS(x)                          (((uint8)(((uint8)(x))<<CLK_BCSCTL2_SELS_SHIFT))&CLK_BCSCTL2_SELS_MASK)

#define CLK_BCSCTL2_DIVSx_MASK                       0x06u
#define CLK_BCSCTL2_DIVSx_SHIFT                      1
#define CLK_BCSCTL2_DIVSx(x)                         (((uint8)(((uint8)(x))<<CLK_BCSCTL2_DIVSx_SHIFT))&CLK_BCSCTL2_DIVSx_MASK)

#define CLK_BCSCTL2_DCOR_MASK                        0x01u
#define CLK_BCSCTL2_DCOR_SHIFT                       0
#define CLK_BCSCTL2_DCOR(x)                          (((uint8)(((uint8)(x))<<CLK_BCSCTL2_DCOR_SHIFT))&CLK_BCSCTL2_DCOR_MASK)
/**
 * @}
 */ /* end of group CLK_Register_Masks */
 

/* CLK - Peripheral instance base addresses */
/** Peripheral CLK base pointer */
#define CLK_BASE_PTR                             ((CLK_MemMapPtr)0x0056u)

/* ----------------------------------------------------------------------------
   -- CLK - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CLK_Register_Accessor_Macros CLK - Register accessor macros
 * @{
 */


/* CLK - Register instance definitions */
/* CLK */
#define CLK_DCOCTL                               CLK_DCOCTL_REG(CLK_BASE_PTR)
#define CLK_BCSCTL1                              CLK_BCSCTL1_REG(CLK_BASE_PTR)
#define CLK_BCSCTL2                              CLK_BCSCTL2_REG(CLK_BASE_PTR)
/**
 * @}
 */ /* end of group CLK_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CLK_Peripheral */




/* ----------------------------------------------------------------------------
   --Flash Memory
   ---------------------------------------------------------------------------- */
	/** FMR - Peripheral register structure */
typedef struct FMR_MemMap {
  uint16 FCTL1;
  uint16 FCTL2;
  uint16 FCTL3;
} volatile *FMR_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- FMR Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMR_Register_Masks FMR Register Masks
 * @{
 */

/* FCTL1 Bit Fields */
#define FMR_FCTL1_FRKEY_FWKEY_MASK                0xFF00u
#define FMR_FCTL1_FRKEY_FWKEY_SHIFT               8
#define FMR_FCTL1_FRKEY_FWKEY(x)                  (((uint16)(((uint16)(x))<<FMR_FCTL1_FRKEY_FWKEY_SHIFT))&FMR_FCTL1_FRKEY_FWKEY_MASK)

#define FMR_FCTL1_BLKWRT_MASK                     0x0080u
#define FMR_FCTL1_BLKWRT_SHIFT                    7
#define FMR_FCTL1_BLKWRT(x)                       (((uint16)(((uint16)(x))<<FMR_FCTL1_BLKWRT_SHIFT))&FMR_FCTL1_BLKWRT_MASK)

#define FMR_FCTL1_WRT_MASK                        0x0040u
#define FMR_FCTL1_WRT_SHIFT                       6
#define FMR_FCTL1_WRT(x)                          (((uint16)(((uint16)(x))<<FMR_FCTL1_WRT_SHIFT))&FMR_FCTL1_WRT_MASK)

#define FMR_FCTL1_MERAS_MASK                      0x0004u
#define FMR_FCTL1_MERAS_SHIFT                     2
#define FMR_FCTL1_MERAS(x)                        (((uint16)(((uint16)(x))<<FMR_FCTL1_MERAS_SHIFT))&FMR_FCTL1_MERAS_MASK)

#define FMR_FCTL1_ERASE_MASK                      0x0002u
#define FMR_FCTL1_ERASE_SHIFT                     1
#define FMR_FCTL1_ERASE(x)                        (((uint16)(((uint16)(x))<<FMR_FCTL1_ERASE_SHIFT))&FMR_FCTL1_ERASE_MASK)

/* FCTL2 Bit Fields */
#define FMR_FCTL2_FWKEYx_MASK                     0xFF00u
#define FMR_FCTL2_FWKEYx_SHIFT                    8
#define FMR_FCTL2_FWKEYx(x)                       (((uint16)(((uint16)(x))<<FMR_FCTL2_FWKEYx_SHIFT))&FMR_FCTL2_FWKEYx_MASK)
 
#define FMR_FCTL2_FSSELx_MASK                     0x00C0u
#define FMR_FCTL2_FSSELx_SHIFT                    6
#define FMR_FCTL2_FSSELx(x)                       (((uint16)(((uint16)(x))<<FMR_FCTL2_FSSELx_SHIFT))&FMR_FCTL2_FSSELx_MASK)

#define FMR_FCTL2_FNx_MASK                        0x003Fu
#define FMR_FCTL2_FNx_SHIFT                       0
#define FMR_FCTL2_FNx(x)                          (((uint16)(((uint16)(x))<<FMR_FCTL2_FNx_SHIFT))&FMR_FCTL2_FNx_MASK)

/* FCTL3 Bit Fields */
#define FMR_FCTL3_FWKEYx_MASK                     0xFF00u
#define FMR_FCTL3_FWKEYx_SHIFT                    8
#define FMR_FCTL3_FWKEYx(x)                       (((uint16)(((uint16)(x))<<FMR_FCTL3_FWKEYx_SHIFT))&FMR_FCTL3_FWKEYx_MASK)

#define FMR_FCTL3_EMEX_MASK                       0x0020u
#define FMR_FCTL3_EMEX_SHIFT                      5
#define FMR_FCTL3_EMEX(x)                         (((uint16)(((uint16)(x))<<FMR_FCTL3_EMEX_SHIFT))&FMR_FCTL3_EMEX_MASK)

#define FMR_FCTL3_LOCK_MASK                       0x0010u
#define FMR_FCTL3_LOCK_SHIFT                      4
#define FMR_FCTL3_LOCK(x)                         (((uint16)(((uint16)(x))<<FMR_FCTL3_LOCK_SHIFT))&FMR_FCTL3_LOCK_MASK)

#define FMR_FCTL3_WAIT_MASK                       0x0008u
#define FMR_FCTL3_WAIT_SHIFT                      3
#define FMR_FCTL3_WAIT(x)                         (((uint16)(((uint16)(x))<<FMR_FCTL3_WAIT_SHIFT))&FMR_FCTL3_WAIT_MASK)

#define FMR_FCTL3_ACCVIFG_MASK                    0x0004u
#define FMR_FCTL3_ACCVIFG_SHIFT                   2
#define FMR_FCTL3_ACCVIFG(x)                      (((uint16)(((uint16)(x))<<FMR_FCTL3_ACCVIFG_SHIFT))&FMR_FCTL3_ACCVIFG_MASK)

#define FMR_FCTL3_KEYV_MASK                       0x0002u
#define FMR_FCTL3_KEYV_SHIFT                      1
#define FMR_FCTL3_KEYV(x)                         (((uint16)(((uint16)(x))<<FMR_FCTL3_KEYV_SHIFT))&FMR_FCTL3_KEYV_MASK)

#define FMR_FCTL3_BUSY_MASK                       0x0001u
#define FMR_FCTL3_BUSY_SHIFT                      0
#define FMR_FCTL3_BUSY(x)                         (((uint16)(((uint16)(x))<<FMR_FCTL3_BUSY_SHIFT))&FMR_FCTL3_BUSY_MASK)
/**
 * @}
 */ /* end of group FMR_Register_Masks */
 

/* FMR - Peripheral instance base addresses */
/** Peripheral FMR base pointer */
#define FMR_BASE_PTR                             ((FMR_MemMapPtr)0x0128u)

/* ----------------------------------------------------------------------------
   -- FMR - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup FMR_Register_Accessor_Macros FMR - Register accessor macros
 * @{
 */


/* FMR - Register instance definitions */
/* FMR */
#define FMR_FCTL1                                  (FMR_BASE_PTR->FCTL1)
#define FMR_FCTL2                                  (FMR_BASE_PTR->FCTL2)
#define FMR_FCTL3                                  (FMR_BASE_PTR->FCTL3)
/**
 * @}
 */ /* end of group FMR_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group FMR_Peripheral */


/* ----------------------------------------------------------------------------
   -- WDT
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
-- WDT Register Masks
 ---------------------------------------------------------------------------- */
	
/**
 * @addtogroup WDT_Register_Masks WDT Register Masks
* @{
 */
	
/* WDTCTL Bit Fields */
#define WDT_WDTCTL_WDTPW_MASK                      0xFF00u
#define WDT_WDTCTL_WDTPW_SHIFT                     8
#define WDT_WDTCTL_WDTPW(x)                        (((uint16)(((uint16)(x))<<WDT_WDTCTL_WDTPW_SHIFT))&WDT_WDTCTL_WDTPW_MASK)

#define WDT_WDTCTL_WDTHOLD_MASK                    0x0080u
#define WDT_WDTCTL_WDTHOLD_SHIFT                   7
#define WDT_WDTCTL_WDTHOLD(x)                      (((uint16)(((uint16)(x))<<WDT_WDTCTL_WDTHOLD_SHIFT))&WDT_WDTCTL_WDTHOLD_MASK)

#define WDT_WDTCTL_WDTNMIES_MASK                   0x0040u
#define WDT_WDTCTL_WDTNMIES_SHIFT                  6
#define WDT_WDTCTL_WDTNMIES(x)                     (((uint16)(((uint16)(x))<<WDT_WDTCTL_WDTNMIES_SHIFT))&WDT_WDTCTL_WDTNMIES_MASK)

#define WDT_WDTCTL_WDTNMI_MASK                     0x0020u
#define WDT_WDTCTL_WDTNMI_SHIFT                    5
#define WDT_WDTCTL_WDTNMI(x)                       (((uint16)(((uint16)(x))<<WDT_WDTCTL_WDTNMI_SHIFT))&WDT_WDTCTL_WDTNMI_MASK)

#define WDT_WDTCTL_WDTTMSEL_MASK                   0x0010u
#define WDT_WDTCTL_WDTTMSEL_SHIFT                  4
#define WDT_WDTCTL_WDTTMSEL(x)                     (((uint16)(((uint16)(x))<<WDT_WDTCTL_WDTTMSEL_SHIFT))&WDT_WDTCTL_WDTTMSEL_MASK)

#define WDT_WDTCTL_WDTCNTCL_MASK                   0x0008u
#define WDT_WDTCTL_WDTCNTCL_SHIFT                  3
#define WDT_WDTCTL_WDTCNTCL(x)                     (((uint16)(((uint16)(x))<<WDT_WDTCTL_WDTCNTCL_SHIFT))&WDT_WDTCTL_WDTCNTCL_MASK)

#define WDT_WDTCTL_WDTSSEL_MASK                    0x0004u
#define WDT_WDTCTL_WDTSSEL_SHIFT                   2
#define WDT_WDTCTL_WDTSSEL(x)                      (((uint16)(((uint16)(x))<<WDT_WDTCTL_WDTSSEL_SHIFT))&WDT_WDTCTL_WDTSSEL_MASK)

#define WDT_WDTCTL_WDTISx_MASK                     0x0003u
#define WDT_WDTCTL_WDTISx_SHIFT                    0
#define WDT_WDTCTL_WDTISx(x)                       (((uint16)(((uint16)(x))<<WDT_WDTCTL_WDTISx_SHIFT))&WDT_WDTCTL_WDTISx_MASK)
/**
 * @}
 */ /* end of group WDT_Register_Masks */

#define WDT_WDTCTL                                 (*((uint16*)(0x0120u)))

/**
 * @}
 */ /* end of group WDT_Peripheral */



/* ----------------------------------------------------------------------------
   -- Timer_A
   ---------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------
-- Timer_A Register Masks
 ---------------------------------------------------------------------------- */
	
/**
 * @addtogroup Timer_A_Register_Masks Timer_A Register Masks
* @{
 */
	
/* TACTL Bit Fields */
#define TA_TACTL_TASSELx_MASK                       0x0300u
#define TA_TACTL_TASSELx_SHIFT                      8
#define TA_TACTL_TASSELx(x)                         (((uint16)(((uint16)(x))<<TA_TACTL_TASSELx_SHIFT))&TA_TACTL_TASSELx_MASK)

#define TA_TACTL_IDx_MASK                           0x00C0u
#define TA_TACTL_IDx_SHIFT                          6
#define TA_TACTL_IDx(x)                             (((uint16)(((uint16)(x))<<TA_TACTL_IDx_SHIFT))&TA_TACTL_IDx_MASK)

#define TA_TACTL_MCx_MASK                           0x0030u
#define TA_TACTL_MCx_SHIFT                          4
#define TA_TACTL_MCx(x)                             (((uint16)(((uint16)(x))<<TA_TACTL_MCx_SHIFT))&TA_TACTL_MCx_MASK)

#define TA_TACTL_TACLR_MASK                         0x0004u
#define TA_TACTL_TACLR_SHIFT                        2
#define TA_TACTL_TACLR(x)                           (((uint16)(((uint16)(x))<<TA_TACTL_TACLR_SHIFT))&TA_TACTL_TACLR_MASK)

#define TA_TACTL_TAIE_MASK                          0x0002u
#define TA_TACTL_TAIE_SHIFT                         1
#define TA_TACTL_TAIE(x)                            (((uint16)(((uint16)(x))<<TA_TACTL_TAIE_SHIFT))&TA_TACTL_TAIE_MASK)

#define TA_TACTL_TAIFG_MASK                         0x0001u
#define TA_TACTL_TAIFG_SHIFT                        0
#define TA_TACTL_TAIFG(x)                           (((uint16)(((uint16)(x))<<TA_TACTL_TAIFG_SHIFT))&TA_TACTL_TAIFG_MASK)

/* TAR Bit Fields */
#define TA_TAR_TARx_MASK                            0xFFFFu
#define TA_TAR_TARx_SHIFT                           0
#define TA_TAR_TARx(x)                              (((uint16)(((uint16)(x))<<TA_TAR_TARx_SHIFT))&TA_TAR_TARx_MASK)

/* TACCTLx Bit Fields */
#define TA_TACCTLx_CMx_MASK                         0xC000u
#define TA_TACCTLx_CMx_SHIFT                        14
#define TA_TACCTLx_CMx(x)                           (((uint16)(((uint16)(x))<<TA_TACCTLx_CMx_SHIFT))&TA_TACCTLx_CMx_MASK)

#define TA_TACCTLx_CCISx_MASK                       0x3000u
#define TA_TACCTLx_CCISx_SHIFT                      12
#define TA_TACCTLx_CCISx(x)                         (((uint16)(((uint16)(x))<<TA_TACCTLx_CCISx_SHIFT))&TA_TACCTLx_CCISx_MASK)

#define TA_TACCTLx_SCS_MASK                         0x0800u
#define TA_TACCTLx_SCS_SHIFT                        11
#define TA_TACCTLx_SCS(x)                           (((uint16)(((uint16)(x))<<TA_TACCTLx_SCS_SHIFT))&TA_TACCTLx_SCS_MASK)

#define TA_TACCTLx_SCCI_MASK                        0x0400u
#define TA_TACCTLx_SCCI_SHIFT                       10
#define TA_TACCTLx_SCCI(x)                          (((uint16)(((uint16)(x))<<TA_TACCTLx_SCCI_SHIFT))&TA_TACCTLx_SCCI_MASK)

#define TA_TACCTLx_CAP_MASK                         0x0100u
#define TA_TACCTLx_CAP_SHIFT                        8
#define TA_TACCTLx_CAP(x)                           (((uint16)(((uint16)(x))<<TA_TACCTLx_CAP_SHIFT))&TA_TACCTLx_CAP_MASK)

#define TA_TACCTLx_OUTMODx_MASK                     0x00E0u
#define TA_TACCTLx_OUTMODx_SHIFT                    5
#define TA_TACCTLx_OUTMODx(x)                       (((uint16)(((uint16)(x))<<TA_TACCTLx_OUTMODx_SHIFT))&TA_TACCTLx_OUTMODx_MASK)

#define TA_TACCTLx_CCIE_MASK                        0x0010u
#define TA_TACCTLx_CCIE_SHIFT                       4
#define TA_TACCTLx_CCIE(x)                          (((uint16)(((uint16)(x))<<TA_TACCTLx_CCIE_SHIFT))&TA_TACCTLx_CCIE_MASK)

#define TA_TACCTLx_CCI_MASK                         0x0008u
#define TA_TACCTLx_CCI_SHIFT                        3
#define TA_TACCTLx_CCI(x)                           (((uint16)(((uint16)(x))<<TA_TACCTLx_CCI_SHIFT))&TA_TACCTLx_CCI_MASK)

#define TA_TACCTLx_OUT_MASK                         0x0004u
#define TA_TACCTLx_OUT_SHIFT                        2
#define TA_TACCTLx_OUT(x)                           (((uint16)(((uint16)(x))<<TA_TACCTLx_OUT_SHIFT))&TA_TACCTLx_OUT_MASK)

#define TA_TACCTLx_COV_MASK                         0x0002u
#define TA_TACCTLx_COV_SHIFT                        1
#define TA_TACCTLx_COV(x)                           (((uint16)(((uint16)(x))<<TA_TACCTLx_COV_SHIFT))&TA_TACCTLx_COV_MASK)

#define TA_TACCTLx_CCIFG_MASK                       0x0001u
#define TA_TACCTLx_CCIFG_SHIFT                      0
#define TA_TACCTLx_CCIFG(x)                         (((uint16)(((uint16)(x))<<TA_TACCTLx_CCIFG_SHIFT))&TA_TACCTLx_CCIFG_MASK)

/* TAIV Bit Fields */
#define TA_TAIV_TAIVx_MASK                          0x000Eu
#define TA_TAIV_TAIVx_SHIFT                         1
#define TA_TAIV_TAIVx(x)                            (((uint16)(((uint16)(x))<<TA_TAIV_TAIVx_SHIFT))&TA_TAIV_TAIVx_MASK)


#define TA_TACTL                                    (*((uint16*)(0x0160u)))
#define TA_TAR                                      (*((uint16*)(0x0170u)))
#define TA_TACCTL0                                  (*((uint16*)(0x0162u)))
#define TA_TACCR0                                   (*((uint16*)(0x0172u)))
#define TA_TACCTL1                                  (*((uint16*)(0x0164u)))
#define TA_TACCR1                                   (*((uint16*)(0x0174u)))
#define TA_TACCTL2                                  (*((uint16*)(0x0166u)))
#define TA_TACCR2                                   (*((uint16*)(0x0176u)))
#define TA_TAIV                                     (*((uint16*)(0x012Eu)))
/**
 * @}
 */ /* end of group WDT_Peripheral */


/* ----------------------------------------------------------------------------
   -- Timer_B
   ---------------------------------------------------------------------------- */
typedef struct TB_MemMap {
  uint16 TBCTL;
  uint16 TBCCTL0;
  uint16 TBCCTL1;
  uint16 TBCCTL2;
  uint16 TBCCTL3;
  uint16 TBCCTL4;
  uint16 TBCCTL5;
  uint16 TBCCTL6;
  uint16 TBR;
  uint16 TBCCR0;
  uint16 TBCCR1;
  uint16 TBCCR2;
  uint16 TBCCR3;
  uint16 TBCCR4;
  uint16 TBCCR5;
  uint16 TBCCR6;
} volatile *TB_MemMapPtr;


/* ----------------------------------------------------------------------------
-- Timer_B Register Masks
 ---------------------------------------------------------------------------- */
	
/**
 * @addtogroup Timer_B_Register_Masks Timer_B Register Masks
* @{
 */
	
/* TBCTL Bit Fields */
#define TB_TBCTL_TBCLGRP_MASK                       0x6000u
#define TB_TBCTL_TBCLGRP_SHIFT                      13
#define TB_TBCTL_TBCLGRP(x)                         (((uint16)(((uint16)(x))<<TB_TBCTL_TBCLGRP_SHIFT))&TB_TBCTL_TBCLGRP_MASK)

#define TB_TBCTL_CNTLx_MASK                         0x1800u
#define TB_TBCTL_CNTLx_SHIFT                        11
#define TB_TBCTL_CNTLx(x)                           (((uint16)(((uint16)(x))<<TB_TBCTL_CNTLx_SHIFT))&TB_TBCTL_CNTLx_MASK)

#define TB_TBCTL_TBSSELx_MASK                       0x0300u
#define TB_TBCTL_TBSSELx_SHIFT                      8
#define TB_TBCTL_TBSSELx(x)                         (((uint16)(((uint16)(x))<<TB_TBCTL_TBSSELx_SHIFT))&TB_TBCTL_TBSSELx_MASK)

#define TB_TBCTL_IDx_MASK                           0x00C0u
#define TB_TBCTL_IDx_SHIFT                          6
#define TB_TBCTL_IDx(x)                             (((uint16)(((uint16)(x))<<TB_TBCTL_IDx_SHIFT))&TB_TBCTL_IDx_MASK)

#define TB_TBCTL_MCx_MASK                           0x0030u
#define TB_TBCTL_MCx_SHIFT                          4
#define TB_TBCTL_MCx(x)                             (((uint16)(((uint16)(x))<<TB_TBCTL_MCx_SHIFT))&TB_TBCTL_MCx_MASK)

#define TB_TBCTL_TBCLR_MASK                         0x0004u
#define TB_TBCTL_TBCLR_SHIFT                        2
#define TB_TBCTL_TBCLR(x)                           (((uint16)(((uint16)(x))<<TB_TBCTL_TBCLR_SHIFT))&TB_TBCTL_TBCLR_MASK)

#define TB_TBCTL_TBIE_MASK                          0x0002u
#define TB_TBCTL_TBIE_SHIFT                         1
#define TB_TBCTL_TBIE(x)                            (((uint16)(((uint16)(x))<<TB_TBCTL_TBIE_SHIFT))&TB_TBCTL_TBIE_MASK)

#define TB_TBCTL_TBIFG_MASK                         0x0001u
#define TB_TBCTL_TBIFG_SHIFT                        0
#define TB_TBCTL_TBIFG(x)                           (((uint16)(((uint16)(x))<<TB_TBCTL_TBIFG_SHIFT))&TB_TBCTL_TBIFG_MASK)

/* TBR Bit Fields */
#define TB_TBR_TBRx_MASK                            0xFFFFu
#define TB_TBR_TBRx_SHIFT                           0
#define TB_TBR_TBRx(x)                              (((uint16)(((uint16)(x))<<TB_TBR_TBRx_SHIFT))&TB_TBR_TBRx_MASK)

/* TBCCTLx Bit Fields */
#define TB_TBCCTLx_CMx_MASK                         0xC000u
#define TB_TBCCTLx_CMx_SHIFT                        14
#define TB_TBCCTLx_CMx(x)                           (((uint16)(((uint16)(x))<<TB_TBCCTLx_CMx_SHIFT))&TB_TBCCTLx_CMx_MASK)

#define TB_TBCCTLx_CCISx_MASK                       0x3000u
#define TB_TBCCTLx_CCISx_SHIFT                      12
#define TB_TBCCTLx_CCISx(x)                         (((uint16)(((uint16)(x))<<TB_TBCCTLx_CCISx_SHIFT))&TB_TBCCTLx_CCISx_MASK)

#define TB_TBCCTLx_SCS_MASK                         0x0800u
#define TB_TBCCTLx_SCS_SHIFT                        11
#define TB_TBCCTLx_SCS(x)                           (((uint16)(((uint16)(x))<<TB_TBCCTLx_SCS_SHIFT))&TB_TBCCTLx_SCS_MASK)

#define TB_TBCCTLx_CLLDx_MASK                       0x0600u
#define TB_TBCCTLx_CLLDx_SHIFT                      9
#define TB_TBCCTLx_CLLDx(x)                         (((uint16)(((uint16)(x))<<TB_TBCCTLx_CLLDx_SHIFT))&TB_TBCCTLx_CLLDx_MASK)

#define TB_TBCCTLx_CAP_MASK                         0x0100u
#define TB_TBCCTLx_CAP_SHIFT                        8
#define TB_TBCCTLx_CAP(x)                           (((uint16)(((uint16)(x))<<TB_TBCCTLx_CAP_SHIFT))&TB_TBCCTLx_CAP_MASK)

#define TB_TBCCTLx_OUTMODx_MASK                     0x00E0u
#define TB_TBCCTLx_OUTMODx_SHIFT                    5
#define TB_TBCCTLx_OUTMODx(x)                       (((uint16)(((uint16)(x))<<TB_TBCCTLx_OUTMODx_SHIFT))&TB_TBCCTLx_OUTMODx_MASK)

#define TB_TBCCTLx_CCIE_MASK                        0x0010u
#define TB_TBCCTLx_CCIE_SHIFT                       4
#define TB_TBCCTLx_CCIE(x)                          (((uint16)(((uint16)(x))<<TB_TBCCTLx_CCIE_SHIFT))&TB_TBCCTLx_CCIE_MASK)

#define TB_TBCCTLx_CCI_MASK                         0x0008u
#define TB_TBCCTLx_CCI_SHIFT                        3
#define TB_TBCCTLx_CCI(x)                           (((uint16)(((uint16)(x))<<TB_TBCCTLx_CCI_SHIFT))&TB_TBCCTLx_CCI_MASK)

#define TB_TBCCTLx_OUT_MASK                         0x0004u
#define TB_TBCCTLx_OUT_SHIFT                        2
#define TB_TBCCTLx_OUT(x)                           (((uint16)(((uint16)(x))<<TB_TBCCTLx_OUT_SHIFT))&TB_TBCCTLx_OUT_MASK)

#define TB_TBCCTLx_COV_MASK                         0x0002u
#define TB_TBCCTLx_COV_SHIFT                        1
#define TB_TBCCTLx_COV(x)                           (((uint16)(((uint16)(x))<<TB_TBCCTLx_COV_SHIFT))&TB_TBCCTLx_COV_MASK)

#define TB_TBCCTLx_CCIFG_MASK                       0x0001u
#define TB_TBCCTLx_CCIFG_SHIFT                      0
#define TB_TBCCTLx_CCIFG(x)                         (((uint16)(((uint16)(x))<<TB_TBCCTLx_CCIFG_SHIFT))&TB_TBCCTLx_CCIFG_MASK)

/* TBIV Bit Fields */
#define TB_TBIV_TBIVx_MASK                          0xFFFFu
#define TB_TBIV_TBIVx_SHIFT                         0
#define TB_TBIV_TBIVx(x)                            (((uint16)(((uint16)(x))<<TB_TBIV_TBIVx_SHIFT))&TB_TBIV_TBIVx_MASK)
/**
 * @}
 */ /* end of group TB_Register_Masks */
 

/* TB - Peripheral instance base addresses */
/** Peripheral TB base pointer */
#define TB_BASE_PTR                             ((TB_MemMapPtr)0x0180u)

/* ----------------------------------------------------------------------------
   -- TB - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup TB_Register_Accessor_Macros TB - Register accessor macros
 * @{
 */


/* TB - Register instance definitions */
/* TB */
#define TB_TBIV                                 (*((uint16*)(0x011Eu)))
#define TB_TBCTL                                (TB_BASE_PTR->TBCTL)  
#define TB_TBR                                  (TB_BASE_PTR->TBR)  
#define TB_TBCCTL0                              (TB_BASE_PTR->TBCCTL0)  
#define TB_TBCCR0                               (TB_BASE_PTR->TBCCR0)  
#define TB_TBCCTL1                              (TB_BASE_PTR->TBCCTL1)  
#define TB_TBCCR1                               (TB_BASE_PTR->TBCCR1)  
#define TB_TBCCTL2                              (TB_BASE_PTR->TBCCTL2)  
#define TB_TBCCR2                               (TB_BASE_PTR->TBCCR2)  
#define TB_TBCCTL3                              (TB_BASE_PTR->TBCCTL3)  
#define TB_TBCCR3                               (TB_BASE_PTR->TBCCR3)  
#define TB_TBCCTL4                              (TB_BASE_PTR->TBCCTL4)  
#define TB_TBCCR4                               (TB_BASE_PTR->TBCCR4)  
#define TB_TBCCTL5                              (TB_BASE_PTR->TBCCTL5)  
#define TB_TBCCR5                               (TB_BASE_PTR->TBCCR5)  
#define TB_TBCCTL6                              (TB_BASE_PTR->TBCCTL6)  
#define TB_TBCCR6                               (TB_BASE_PTR->TBCCR6)  
/**
 * @}
 */ /* end of group TB_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group TB_Peripheral */


/* ----------------------------------------------------------------------------
   -- USART
   ---------------------------------------------------------------------------- */
/** USART - Peripheral register structure */
typedef struct USART_MemMap {
  uint8 UxCTL;
  uint8 UxTCTL;
  uint8 UxRCTL;
  uint8 UxMCTL;
  uint8 UxBR0;
  uint8 UxBR1;
  uint8 UxRXBUF;
  uint8 UxTXBUF;
} volatile *USART_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- USART - Register accessor macros
   ---------------------------------------------------------------------------- */
/* USART - Register accessors */
#define USART_UxCTL_REG(base)                       ((base)->UxCTL)
#define USART_UxTCTL_REG(base)                      ((base)->UxTCTL)
#define USART_UxRCTL_REG(base)                      ((base)->UxRCTL)
#define USART_UxMCTL_REG(base)                      ((base)->UxMCTL)
#define USART_UxBR0_REG(base)                       ((base)->UxBR0)
#define USART_UxBR1_REG(base)                       ((base)->UxBR1)
#define USART_UxRXBUF_REG(base)                     ((base)->UxRXBUF)
#define USART_UxTXBUF_REG(base)                     ((base)->UxTXBUF)
/**
 * @}
 */ /* end of group USART_Register_Accessor_Macros */


/* ----------------------------------------------------------------------------
   -- USART Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USART_Register_Masks USART Register Masks
 * @{
 */

/* UxCTL Bit Fields */
#define UART_UxCTL_PENA_MASK                      0x80u
#define UART_UxCTL_PENA_SHIFT                     7
#define UART_UxCTL_PENA(x)                        (((uint8)(((uint8)(x))<<UART_UxCTL_PENA_SHIFT))&UART_UxCTL_PENA_MASK)

#define UART_UxCTL_PEV_MASK                       0x40u
#define UART_UxCTL_PEV_SHIFT                      6
#define UART_UxCTL_PEV(x)                         (((uint8)(((uint8)(x))<<UART_UxCTL_PEV_SHIFT))&UART_UxCTL_PEV_MASK)

#define UART_UxCTL_SPB_MASK                       0x20u
#define UART_UxCTL_SPB_SHIFT                      5
#define UART_UxCTL_SPB(x)                         (((uint8)(((uint8)(x))<<UART_UxCTL_SPB_SHIFT))&UART_UxCTL_SPB_MASK)

#define UART_UxCTL_CHAR_MASK                      0x10u
#define UART_UxCTL_CHAR_SHIFT                     4
#define UART_UxCTL_CHAR(x)                        (((uint8)(((uint8)(x))<<UART_UxCTL_CHAR_SHIFT))&UART_UxCTL_CHAR_MASK)

#define UART_UxCTL_LISTEN_MASK                    0x08u
#define UART_UxCTL_LISTEN_SHIFT                   3
#define UART_UxCTL_LISTEN(x)                      (((uint8)(((uint8)(x))<<UART_UxCTL_LISTEN_SHIFT))&UART_UxCTL_LISTEN_MASK)

#define UART_UxCTL_SYNC_MASK                      0x04u
#define UART_UxCTL_SYNC_SHIFT                     2
#define UART_UxCTL_SYNC(x)                        (((uint8)(((uint8)(x))<<UART_UxCTL_SYNC_SHIFT))&UART_UxCTL_SYNC_MASK)

#define UART_UxCTL_MM_MASK                        0x02u
#define UART_UxCTL_MM_SHIFT                       1
#define UART_UxCTL_MM(x)                          (((uint8)(((uint8)(x))<<UART_UxCTL_MM_SHIFT))&UART_UxCTL_MM_MASK)

#define UART_UxCTL_SWRST_MASK                     0x01u
#define UART_UxCTL_SWRST_SHIFT                    0
#define UART_UxCTL_SWRST(x)                       (((uint8)(((uint8)(x))<<UART_UxCTL_SWRST_SHIFT))&UART_UxCTL_SWRST_MASK)

/* UxTCTL Bit Fields */
#define UART_UxTCTL_CKPL_MASK                     0x40u
#define UART_UxTCTL_CKPL_SHIFT                    6
#define UART_UxTCTL_CKPL(x)                       (((uint8)(((uint8)(x))<<UART_UxTCTL_CKPL_SHIFT))&UART_UxTCTL_CKPL_MASK)

#define UART_UxTCTL_SSELx_MASK                    0x30u
#define UART_UxTCTL_SSELx_SHIFT                   4
#define UART_UxTCTL_SSELx(x)                      (((uint8)(((uint8)(x))<<UART_UxTCTL_SSELx_SHIFT))&UART_UxTCTL_SSELx_MASK)

#define UART_UxTCTL_URXSE_MASK                    0x08u
#define UART_UxTCTL_URXSE_SHIFT                   3
#define UART_UxTCTL_URXSE(x)                      (((uint8)(((uint8)(x))<<UART_UxTCTL_URXSE_SHIFT))&UART_UxTCTL_URXSE_MASK)

#define UART_UxTCTL_TXWAKE_MASK                   0x04u
#define UART_UxTCTL_TXWAKE_SHIFT                  2
#define UART_UxTCTL_TXWAKE(x)                     (((uint8)(((uint8)(x))<<UART_UxTCTL_TXWAKE_SHIFT))&UART_UxTCTL_TXWAKE_MASK)

#define UART_UxTCTL_TXEPT_MASK                    0x01u
#define UART_UxTCTL_TXEPT_SHIFT                   0
#define UART_UxTCTL_TXEPT(x)                      (((uint8)(((uint8)(x))<<UART_UxTCTL_TXEPT_SHIFT))&UART_UxTCTL_TXEPT_MASK)

/* UxRCTL Bit Fields */
#define UART_UxRCTL_FE_MASK                       0x80u
#define UART_UxRCTL_FE_SHIFT                      7
#define UART_UxRCTL_FE(x)                         (((uint8)(((uint8)(x))<<UART_UxRCTL_FE_SHIFT))&UART_UxRCTL_FE_MASK)

#define UART_UxRCTL_PE_MASK                       0x40u
#define UART_UxRCTL_PE_SHIFT                      6
#define UART_UxRCTL_PE(x)                         (((uint8)(((uint8)(x))<<UART_UxRCTL_PE_SHIFT))&UART_UxRCTL_PE_MASK)

#define UART_UxRCTL_OE_MASK                       0x20u
#define UART_UxRCTL_OE_SHIFT                      5
#define UART_UxRCTL_OE(x)                         (((uint8)(((uint8)(x))<<UART_UxRCTL_OE_SHIFT))&UART_UxRCTL_OE_MASK)

#define UART_UxRCTL_BRK_MASK                      0x10u
#define UART_UxRCTL_BRK_SHIFT                     4
#define UART_UxRCTL_BRK(x)                        (((uint8)(((uint8)(x))<<UART_UxRCTL_BRK_SHIFT))&UART_UxRCTL_BRK_MASK)

#define UART_UxRCTL_URXEIE_MASK                   0x08u
#define UART_UxRCTL_URXEIE_SHIFT                  3
#define UART_UxRCTL_URXEIE(x)                     (((uint8)(((uint8)(x))<<UART_UxRCTL_URXEIE_SHIFT))&UART_UxRCTL_URXEIE_MASK)

#define UART_UxRCTL_URXWIE_MASK                   0x04u
#define UART_UxRCTL_URXWIE_SHIFT                  2
#define UART_UxRCTL_URXWIE(x)                     (((uint8)(((uint8)(x))<<UART_UxRCTL_URXWIE_SHIFT))&UART_UxRCTL_URXWIE_MASK)

#define UART_UxRCTL_RXWAKE_MASK                   0x02u
#define UART_UxRCTL_RXWAKE_SHIFT                  1
#define UART_UxRCTL_RXWAKE(x)                     (((uint8)(((uint8)(x))<<UART_UxRCTL_RXWAKE_SHIFT))&UART_UxRCTL_RXWAKE_MASK)

#define UART_UxRCTL_RXERR_MASK                    0x01u
#define UART_UxRCTL_RXERR_SHIFT                   0
#define UART_UxRCTL_RXERR(x)                      (((uint8)(((uint8)(x))<<UART_UxRCTL_RXERR_SHIFT))&UART_UxRCTL_RXERR_MASK)

/* UxBR0 Bit Fields */
#define UART_UxBR0_MASK                           0xFFu
#define UART_UxBR0_SHIFT                          0
#define UART_UxBR0(x)                             (((uint8)(((uint8)(x))<<UART_UxBR0_SHIFT))&UART_UxBR0_MASK)

/* UxBR1 Bit Fields */
#define UART_UxBR1_MASK                           0xFFu
#define UART_UxBR1_SHIFT                          0
#define UART_UxBR1(x)                             (((uint8)(((uint8)(x))<<UART_UxBR1_SHIFT))&UART_UxBR1_MASK)

/* UxMCTL Bit Fields */
#define UART_UxMCTL_MASK                          0xFFu
#define UART_UxMCTL_SHIFT                         0
#define UART_UxMCTL(x)                            (((uint8)(((uint8)(x))<<UART_UxMCTL_SHIFT))&UART_UxMCTL_MASK)

/* UxRXBUF Bit Fields */
#define UART_UxRXBUF_MASK                         0xFFu
#define UART_UxRXBUF_SHIFT                        0
#define UART_UxRXBUF(x)                           (((uint8)(((uint8)(x))<<UART_UxRXBUF_SHIFT))&UART_UxRXBUF_MASK)

/* UxTXBUF Bit Fields */
#define UART_UxTXBUF_MASK                         0xFFu
#define UART_UxTXBUF_SHIFT                        0
#define UART_UxTXBUF(x)                           (((uint8)(((uint8)(x))<<UART_UxTXBUF_SHIFT))&UART_UxTXBUF_MASK)
/**
 * @}
 */ /* end of group USART_Register_Masks */

/* ----------------------------------------------------------------------------
   -- SPI Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SPI_Register_Masks SPI Register Masks
 * @{
 */

/* UxCTL Bit Fields */
#define SPI_UxCTL_I2C_MASK                         0x20u
#define SPI_UxCTL_I2C_SHIFT                        5
#define SPI_UxCTL_I2C(x)                           (((uint8)(((uint8)(x))<<SPI_UxCTL_I2C_SHIFT))&SPI_UxCTL_I2C_MASK)

#define SPI_UxCTL_CHAR_MASK                        0x10u
#define SPI_UxCTL_CHAR_SHIFT                       4
#define SPI_UxCTL_CHAR(x)                          (((uint8)(((uint8)(x))<<SPI_UxCTL_CHAR_SHIFT))&SPI_UxCTL_CHAR_MASK)

#define SPI_UxCTL_LISTEN_MASK                      0x08u
#define SPI_UxCTL_LISTEN_SHIFT                     3
#define SPI_UxCTL_LISTEN(x)                        (((uint8)(((uint8)(x))<<SPI_UxCTL_LISTEN_SHIFT))&SPI_UxCTL_LISTEN_MASK)

#define SPI_UxCTL_SYNC_MASK                        0x04u
#define SPI_UxCTL_SYNC_SHIFT                       2
#define SPI_UxCTL_SYNC(x)                          (((uint8)(((uint8)(x))<<SPI_UxCTL_SYNC_SHIFT))&SPI_UxCTL_SYNC_MASK)
 
#define SPI_UxCTL_MM_MASK                          0x02u
#define SPI_UxCTL_MM_SHIFT                         1
#define SPI_UxCTL_MM(x)                            (((uint8)(((uint8)(x))<<SPI_UxCTL_MM_SHIFT))&SPI_UxCTL_MM_MASK)

#define SPI_UxCTL_SWRST_MASK                       0x01u
#define SPI_UxCTL_SWRST_SHIFT                      0
#define SPI_UxCTL_SWRST(x)                         (((uint8)(((uint8)(x))<<SPI_UxCTL_SWRST_SHIFT))&SPI_UxCTL_SWRST_MASK)

/* UxTCTL Bit Fields */
#define SPI_UxTCTL_CKPH_MASK                       0x80u
#define SPI_UxTCTL_CKPH_SHIFT                      7
#define SPI_UxTCTL_CKPH(x)                         (((uint8)(((uint8)(x))<<SPI_UxTCTL_CKPH_SHIFT))&SPI_UxTCTL_CKPH_MASK)

#define SPI_UxTCTL_CKPL_MASK                       0x40u
#define SPI_UxTCTL_CKPL_SHIFT                      6
#define SPI_UxTCTL_CKPL(x)                         (((uint8)(((uint8)(x))<<SPI_UxTCTL_CKPL_SHIFT))&SPI_UxTCTL_CKPL_MASK)

#define SPI_UxTCTL_SSELx_MASK                      0x30u
#define SPI_UxTCTL_SSELx_SHIFT                     4
#define SPI_UxTCTL_SSELx(x)                        (((uint8)(((uint8)(x))<<SPI_UxTCTL_SSELx_SHIFT))&SPI_UxTCTL_SSELx_MASK)

#define SPI_UxTCTL_STC_MASK                        0x02u
#define SPI_UxTCTL_STC_SHIFT                       1
#define SPI_UxTCTL_STC(x)                          (((uint8)(((uint8)(x))<<SPI_UxTCTL_STC_SHIFT))&SPI_UxTCTL_STC_MASK)

#define SPI_UxTCTL_TXEPT_MASK                      0x01u
#define SPI_UxTCTL_TXEPT_SHIFT                     0
#define SPI_UxTCTL_TXEPT(x)                        (((uint8)(((uint8)(x))<<SPI_UxTCTL_TXEPT_SHIFT))&SPI_UxTCTL_TXEPT_MASK)

/* UxRCTL Bit Fields */
#define SPI_UxRCTL_FE_MASK                         0x80u
#define SPI_UxRCTL_FE_SHIFT                        7
#define SPI_UxRCTL_FE(x)                           (((uint8)(((uint8)(x))<<SPI_UxRCTL_FE_SHIFT))&SPI_UxRCTL_FE_MASK)

#define SPI_UxRCTL_OE_MASK                         0x20u
#define SPI_UxRCTL_OE_SHIFT                        5
#define SPI_UxRCTL_OE(x)                           (((uint8)(((uint8)(x))<<SPI_UxRCTL_OE_SHIFT))&SPI_UxRCTL_OE_MASK)

/* UxBR0 Bit Fields */
#define SPI_UxBR0_MASK                             0xFFu
#define SPI_UxBR0_SHIFT                            0
#define SPI_UxBR0(x)                               (((uint8)(((uint8)(x))<<SPI_UxBR0_SHIFT))&SPI_UxBR0_MASK)

/* UxBR1 Bit Fields */
#define SPI_UxBR1_MASK                             0xFFu
#define SPI_UxBR1_SHIFT                            0
#define SPI_UxBR1(x)                               (((uint8)(((uint8)(x))<<SPI_UxBR1_SHIFT))&SPI_UxBR1_MASK)

/* UxMCTL Bit Fields */
#define SPI_UxMCTL_MASK                            0xFFu
#define SPI_UxMCTL_SHIFT                           0
#define SPI_UxMCTL(x)                              (((uint8)(((uint8)(x))<<SPI_UxMCTL_SHIFT))&SPI_UxMCTL_MASK)

/* UxRXBUF Bit Fields */
#define SPI_UxRXBUF_MASK                           0xFFu
#define SPI_UxRXBUF_SHIFT                          0
#define SPI_UxRXBUF(x)                             (((uint8)(((uint8)(x))<<SPI_UxRXBUF_SHIFT))&SPI_UxRXBUF_MASK)

/* UxTXBUF Bit Fields */
#define SPI_UxTXBUF_MASK                           0xFFu
#define SPI_UxTXBUF_SHIFT                          0
#define SPI_UxTXBUF(x)                             (((uint8)(((uint8)(x))<<SPI_UxTXBUF_SHIFT))&SPI_UxTXBUF_MASK)
/**
 * @}
 */ /* end of group SPI_Register_Masks */


/* USART - Peripheral instance base addresses */
/** Peripheral USART0 base pointer */
#define USART0_BASE_PTR                             ((USART_MemMapPtr)0x0070u)
/** Peripheral USART1 base pointer */
#define USART1_BASE_PTR                             ((USART_MemMapPtr)0x0078u)
/* ----------------------------------------------------------------------------
   -- USART - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup USART_Register_Accessor_Macros USART - Register accessor macros
 * @{
 */


/* USART - Register instance definitions */
/* USART0 */
#define USART0_U0CTL                                   USART_UxCTL_REG(USART0_BASE_PTR)
#define USART0_U0TCTL                                  USART_UxTCTL_REG(USART0_BASE_PTR)
#define USART0_U0RCTL                                  USART_UxRCTL_REG(USART0_BASE_PTR)
#define USART0_U0MCTL                                  USART_UxMCTL_REG(USART0_BASE_PTR)
#define USART0_U0BR0                                   USART_UxBR0_REG(USART0_BASE_PTR)
#define USART0_U0BR1                                   USART_UxBR1_REG(USART0_BASE_PTR)
#define USART0_U0RXBUF                                 USART_UxRXBUF_REG(USART0_BASE_PTR)
#define USART0_U0TXBUF                                 USART_UxTXBUF_REG(USART0_BASE_PTR)

/* USART1 */
#define USART1_U1CTL                                   USART_UxCTL_REG(USART1_BASE_PTR)
#define USART1_U1TCTL                                  USART_UxTCTL_REG(USART1_BASE_PTR)
#define USART1_U1RCTL                                  USART_UxRCTL_REG(USART1_BASE_PTR)
#define USART1_U1MCTL                                  USART_UxMCTL_REG(USART1_BASE_PTR)
#define USART1_U1BR0                                   USART_UxBR0_REG(USART1_BASE_PTR)
#define USART1_U1BR1                                   USART_UxBR1_REG(USART1_BASE_PTR)
#define USART1_U1RXBUF                                 USART_UxRXBUF_REG(USART1_BASE_PTR)
#define USART1_U1TXBUF                                 USART_UxTXBUF_REG(USART1_BASE_PTR)
/**
 * @}
 */ /* end of group USART_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group USART_Peripheral */


/* ----------------------------------------------------------------------------
   -- I2C
   ---------------------------------------------------------------------------- */
/** I2C - Peripheral register structure */
typedef struct I2C_MemMap {
  uint8 I2CIE;
  uint8 I2CIFG;
  uint8 I2CNDAT;
  uint8 RESERVED_0[29];
  uint8 U0CTL;
  uint8 I2CTCTL;
  uint8 I2CDCTL;
  uint8 I2CPSC;
  uint8 I2CSCLH;
  uint8 I2CSCLL;
  uint8 I2CDRW_B;
  uint8 I2CDRW;
  uint8 RESERVED_1[160];
  uint16 I2COA;
  uint16 I2CSA;
  uint16 I2CIV;
} volatile *I2C_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- I2C Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Register_Masks I2C Register Masks
 * @{
 */

/* I2CIE Bit Fields */
#define I2C_I2CIE_STTIE_MASK                       0x80u
#define I2C_I2CIE_STTIE_SHIFT                      7
#define I2C_I2CIE_STTIE(x)                         (((uint8)(((uint8)(x))<<I2C_I2CIE_STTIE_SHIFT))&I2C_I2CIE_STTIE_MASK)

#define I2C_I2CIE_GCIE_MASK                        0x40u
#define I2C_I2CIE_GCIE_SHIFT                       6
#define I2C_I2CIE_GCIE(x)                          (((uint8)(((uint8)(x))<<I2C_I2CIE_GCIE_SHIFT))&I2C_I2CIE_GCIE_MASK)

#define I2C_I2CIE_TXRDYIE_MASK                     0x20u
#define I2C_I2CIE_TXRDYIE_SHIFT                    5
#define I2C_I2CIE_TXRDYIE(x)                       (((uint8)(((uint8)(x))<<I2C_I2CIE_TXRDYIE_SHIFT))&I2C_I2CIE_TXRDYIE_MASK)

#define I2C_I2CIE_RXRDYIE_MASK                     0x10u
#define I2C_I2CIE_RXRDYIE_SHIFT                    4
#define I2C_I2CIE_RXRDYIE(x)                       (((uint8)(((uint8)(x))<<I2C_I2CIE_RXRDYIE_SHIFT))&I2C_I2CIE_RXRDYIE_MASK)

#define I2C_I2CIE_ARDYIE_MASK                      0x08u
#define I2C_I2CIE_ARDYIE_SHIFT                     3
#define I2C_I2CIE_ARDYIE(x)                        (((uint8)(((uint8)(x))<<I2C_I2CIE_ARDYIE_SHIFT))&I2C_I2CIE_ARDYIE_MASK)

#define I2C_I2CIE_OAIE_MASK                        0x04u
#define I2C_I2CIE_OAIE_SHIFT                       2
#define I2C_I2CIE_OAIE(x)                          (((uint8)(((uint8)(x))<<I2C_I2CIE_OAIE_SHIFT))&I2C_I2CIE_OAIE_MASK)

#define I2C_I2CIE_NACKIE_MASK                      0x02u
#define I2C_I2CIE_NACKIE_SHIFT                     1
#define I2C_I2CIE_NACKIE(x)                        (((uint8)(((uint8)(x))<<I2C_I2CIE_NACKIE_SHIFT))&I2C_I2CIE_NACKIE_MASK)

#define I2C_I2CIE_ALIE_MASK                        0x01u
#define I2C_I2CIE_ALIE_SHIFT                       0
#define I2C_I2CIE_ALIE(x)                          (((uint8)(((uint8)(x))<<I2C_I2CIE_ALIE_SHIFT))&I2C_I2CIE_ALIE_MASK)

/* I2CIFG Bit Fields */
#define I2C_I2CIFG_STTIFG_MASK                     0x80u
#define I2C_I2CIFG_STTIFG_SHIFT                    7
#define I2C_I2CIFG_STTIFG(x)                       (((uint8)(((uint8)(x))<<I2C_I2CIFG_STTIFG_SHIFT))&I2C_I2CIFG_STTIFG_MASK)

#define I2C_I2CIFG_GCIFG_MASK                      0x40u
#define I2C_I2CIFG_GCIFG_SHIFT                     6
#define I2C_I2CIFG_GCIFG(x)                        (((uint8)(((uint8)(x))<<I2C_I2CIFG_GCIFG_SHIFT))&I2C_I2CIFG_GCIFG_MASK)

#define I2C_I2CIFG_TXRDYIFG_MASK                   0x20u
#define I2C_I2CIFG_TXRDYIFG_SHIFT                  5
#define I2C_I2CIFG_TXRDYIFG(x)                     (((uint8)(((uint8)(x))<<I2C_I2CIFG_TXRDYIFG_SHIFT))&I2C_I2CIFG_TXRDYIFG_MASK)

#define I2C_I2CIFG_RXRDYIFG_MASK                   0x10u
#define I2C_I2CIFG_RXRDYIFG_SHIFT                  4
#define I2C_I2CIFG_RXRDYIFG(x)                     (((uint8)(((uint8)(x))<<I2C_I2CIFG_RXRDYIFG_SHIFT))&I2C_I2CIFG_RXRDYIFG_MASK)

#define I2C_I2CIFG_ARDYIFG_MASK                    0x08u
#define I2C_I2CIFG_ARDYIFG_SHIFT                   3
#define I2C_I2CIFG_ARDYIFG(x)                      (((uint8)(((uint8)(x))<<I2C_I2CIFG_ARDYIFG_SHIFT))&I2C_I2CIFG_ARDYIFG_MASK)

#define I2C_I2CIFG_OAIFG_MASK                      0x04u
#define I2C_I2CIFG_OAIFG_SHIFT                     2
#define I2C_I2CIFG_OAIFG(x)                        (((uint8)(((uint8)(x))<<I2C_I2CIFG_OAIFG_SHIFT))&I2C_I2CIFG_OAIFG_MASK)

#define I2C_I2CIFG_NACKIFG_MASK                    0x02u
#define I2C_I2CIFG_NACKIFG_SHIFT                   1
#define I2C_I2CIFG_NACKIFG(x)                      (((uint8)(((uint8)(x))<<I2C_I2CIFG_NACKIFG_SHIFT))&I2C_I2CIFG_NACKIFG_MASK)

#define I2C_I2CIFG_ALIFG_MASK                      0x01u
#define I2C_I2CIFG_ALIFG_SHIFT                     0
#define I2C_I2CIFG_ALIFG(x)                        (((uint8)(((uint8)(x))<<I2C_I2CIFG_ALIFG_SHIFT))&I2C_I2CIFG_ALIFG_MASK)
 
/* I2CNDAT Bit Fields */
#define I2C_I2CNDAT_I2CNDATx_MASK                  0xFFu
#define I2C_I2CNDAT_I2CNDATx_SHIFT                 0
#define I2C_I2CNDAT_I2CNDATx(x)                    (((uint8)(((uint8)(x))<<I2C_I2CNDAT_I2CNDATx_SHIFT))&I2C_I2CNDAT_I2CNDATx_MASK)

/* U0CTL Bit Fields */
#define I2C_U0CTL_RXDMAEN_MASK                     0x80u
#define I2C_U0CTL_RXDMAEN_SHIFT                    7
#define I2C_U0CTL_RXDMAEN(x)                       (((uint8)(((uint8)(x))<<I2C_U0CTL_RXDMAEN_SHIFT))&I2C_U0CTL_RXDMAEN_MASK)

#define I2C_U0CTL_TXDMAEN_MASK                     0x40u
#define I2C_U0CTL_TXDMAEN_SHIFT                    6
#define I2C_U0CTL_TXDMAEN(x)                       (((uint8)(((uint8)(x))<<I2C_U0CTL_TXDMAEN_SHIFT))&I2C_U0CTL_TXDMAEN_MASK)

#define I2C_U0CTL_I2C_MASK                         0x20u
#define I2C_U0CTL_I2C_SHIFT                        5
#define I2C_U0CTL_I2C(x)                           (((uint8)(((uint8)(x))<<I2C_U0CTL_I2C_SHIFT))&I2C_U0CTL_I2C_MASK)

#define I2C_U0CTL_XA_MASK                          0x10u
#define I2C_U0CTL_XA_SHIFT                         4
#define I2C_U0CTL_XA(x)                            (((uint8)(((uint8)(x))<<I2C_U0CTL_XA_SHIFT))&I2C_U0CTL_XA_MASK)

#define I2C_U0CTL_LISTEN_MASK                      0x08u
#define I2C_U0CTL_LISTEN_SHIFT                     3
#define I2C_U0CTL_LISTEN(x)                        (((uint8)(((uint8)(x))<<I2C_U0CTL_LISTEN_SHIFT))&I2C_U0CTL_LISTEN_MASK)
 
#define I2C_U0CTL_SYNC_MASK                        0x04u
#define I2C_U0CTL_SYNC_SHIFT                       2
#define I2C_U0CTL_SYNC(x)                          (((uint8)(((uint8)(x))<<I2C_U0CTL_SYNC_SHIFT))&I2C_U0CTL_SYNC_MASK)

#define I2C_U0CTL_MST_MASK                         0x02u
#define I2C_U0CTL_MST_SHIFT                        1
#define I2C_U0CTL_MST(x)                           (((uint8)(((uint8)(x))<<I2C_U0CTL_MST_SHIFT))&I2C_U0CTL_MST_MASK)

#define I2C_U0CTL_I2CEN_MASK                       0x01u
#define I2C_U0CTL_I2CEN_SHIFT                      0
#define I2C_U0CTL_I2CEN(x)                         (((uint8)(((uint8)(x))<<I2C_U0CTL_RXDMAEN_SHIFT))&I2C_U0CTL_RXDMAEN_MASK)

/* I2CTCTL Bit Fields */
#define I2C_I2CTCTL_I2CWORD_MASK                   0x80u
#define I2C_I2CTCTL_I2CWORD_SHIFT                  7
#define I2C_I2CTCTL_I2CWORD(x)                     (((uint8)(((uint8)(x))<<I2C_I2CTCTL_I2CWORD_SHIFT))&I2C_I2CTCTL_I2CWORD_MASK)

#define I2C_I2CTCTL_I2CRM_MASK                     0x40u
#define I2C_I2CTCTL_I2CRM_SHIFT                    6
#define I2C_I2CTCTL_I2CRM(x)                       (((uint8)(((uint8)(x))<<I2C_I2CTCTL_I2CRM_SHIFT))&I2C_I2CTCTL_I2CRM_MASK)

#define I2C_I2CTCTL_I2CSSELx_MASK                  0x30u
#define I2C_I2CTCTL_I2CSSELx_SHIFT                 4
#define I2C_I2CTCTL_I2CSSELx(x)                    (((uint8)(((uint8)(x))<<I2C_I2CTCTL_I2CSSELx_SHIFT))&I2C_I2CTCTL_I2CSSELx_MASK)

#define I2C_I2CTCTL_I2CTRX_MASK                    0x08u
#define I2C_I2CTCTL_I2CTRX_SHIFT                   3
#define I2C_I2CTCTL_I2CTRX(x)                      (((uint8)(((uint8)(x))<<I2C_I2CTCTL_I2CTRX_SHIFT))&I2C_I2CTCTL_I2CTRX_MASK)

#define I2C_I2CTCTL_I2CSTB_MASK                    0x04u
#define I2C_I2CTCTL_I2CSTB_SHIFT                   2
#define I2C_I2CTCTL_I2CSTB(x)                      (((uint8)(((uint8)(x))<<I2C_I2CTCTL_I2CSTB_SHIFT))&I2C_I2CTCTL_I2CSTB_MASK)

#define I2C_I2CTCTL_I2CSTP_MASK                    0x02u
#define I2C_I2CTCTL_I2CSTP_SHIFT                   1
#define I2C_I2CTCTL_I2CSTP(x)                      (((uint8)(((uint8)(x))<<I2C_I2CTCTL_I2CSTP_SHIFT))&I2C_I2CTCTL_I2CSTP_MASK)

#define I2C_I2CTCTL_I2CSTT_MASK                    0x01u
#define I2C_I2CTCTL_I2CSTT_SHIFT                   0
#define I2C_I2CTCTL_I2CSTT(x)                      (((uint8)(((uint8)(x))<<I2C_I2CTCTL_I2CSTT_SHIFT))&I2C_I2CTCTL_I2CSTT_MASK)

/* I2CDCTL Bit Fields */
#define I2C_I2CDCTL_I2CBUSY_MASK                   0x20u
#define I2C_I2CDCTL_I2CBUSY_SHIFT                  5
#define I2C_I2CDCTL_I2CBUSY(x)                     (((uint8)(((uint8)(x))<<I2C_I2CDCTL_I2CBUSY_SHIFT))&I2C_I2CDCTL_I2CBUSY_MASK)

#define I2C_I2CDCTL_I2CSCLLOW_MASK                 0x10u
#define I2C_I2CDCTL_I2CSCLLOW_SHIFT                4
#define I2C_I2CDCTL_I2CSCLLOW(x)                   (((uint8)(((uint8)(x))<<I2C_I2CDCTL_I2CSCLLOW_SHIFT))&I2C_I2CDCTL_I2CSCLLOW_MASK)

#define I2C_I2CDCTL_I2CSBD_MASK                    0x08u
#define I2C_I2CDCTL_I2CSBD_SHIFT                   3
#define I2C_I2CDCTL_I2CSBD(x)                      (((uint8)(((uint8)(x))<<I2C_I2CDCTL_I2CSBD_SHIFT))&I2C_I2CDCTL_I2CSBD_MASK)

#define I2C_I2CDCTL_I2CTXUDF_MASK                  0x04u
#define I2C_I2CDCTL_I2CTXUDF_SHIFT                 2
#define I2C_I2CDCTL_I2CTXUDF(x)                    (((uint8)(((uint8)(x))<<I2C_I2CDCTL_I2CTXUDF_SHIFT))&I2C_I2CDCTL_I2CTXUDF_MASK)

#define I2C_I2CDCTL_I2CRXOVR_MASK                  0x02u
#define I2C_I2CDCTL_I2CRXOVR_SHIFT                 1
#define I2C_I2CDCTL_I2CRXOVR(x)                    (((uint8)(((uint8)(x))<<I2C_I2CDCTL_I2CRXOVR_SHIFT))&I2C_I2CDCTL_I2CRXOVR_MASK)

#define I2C_I2CDCTL_I2CBB_MASK                     0x01u
#define I2C_I2CDCTL_I2CBB_SHIFT                    0
#define I2C_I2CDCTL_I2CBB(x)                       (((uint8)(((uint8)(x))<<I2C_I2CDCTL_I2CBB_SHIFT))&I2C_I2CDCTL_I2CBB_MASK)

/* I2CPSC Bit Fields */
#define I2C_I2CPSC_I2CPSCx_MASK                    0xFFu
#define I2C_I2CPSC_I2CPSCx_SHIFT                   0
#define I2C_I2CPSC_I2CPSCx(x)                      (((uint8)(((uint8)(x))<<I2C_I2CPSC_I2CPSCx_SHIFT))&I2C_I2CPSC_I2CPSCx_MASK)

/* I2CSCLH Bit Fields */
#define I2C_I2CSCLH_I2CSCLHx_MASK                  0xFFu
#define I2C_I2CSCLH_I2CSCLHx_SHIFT                 0
#define I2C_I2CSCLH_I2CSCLHx(x)                    (((uint8)(((uint8)(x))<<I2C_I2CSCLH_I2CSCLHx_SHIFT))&I2C_I2CSCLH_I2CSCLHx_MASK)

/* I2CSCLL Bit Fields */
#define I2C_I2CSCLL_I2CSCLLx_MASK                  0xFFu
#define I2C_I2CSCLL_I2CSCLLx_SHIFT                 0
#define I2C_I2CSCLL_I2CSCLLx(x)                    (((uint8)(((uint8)(x))<<I2C_I2CSCLL_I2CSCLLx_SHIFT))&I2C_I2CSCLL_I2CSCLLx_MASK)

/* I2CDRW_B Bit Fields */
#define I2C_I2CDRW_B_I2CDRW_Bx_MASK                0xFFu
#define I2C_I2CDRW_B_I2CDRW_Bx_SHIFT               0
#define I2C_I2CDRW_B_I2CDRW_Bx(x)                  (((uint8)(((uint8)(x))<<I2C_I2CDRW_B_I2CDRW_Bx_SHIFT))&I2C_I2CDRW_B_I2CDRW_Bx_MASK)

/* I2CDRW Bit Fields */
#define I2C_I2CDRW_I2CDRWx_MASK                    0xFFu
#define I2C_I2CDRW_I2CDRWx_SHIFT                   0
#define I2C_I2CDRW_I2CDRWx(x)                      (((uint8)(((uint8)(x))<<I2C_I2CDRW_SHIFT))&I2C_I2CDRW_MASK)

/* I2COA7 Bit Fields */
#define I2C_I2COA7_I2COAx_MASK                     0x007Fu
#define I2C_I2COA7_I2COAx_SHIFT                    0
#define I2C_I2COA7_I2COAx(x)                       (((uint16)(((uint16)(x))<<I2C_I2COA7_I2COAx_SHIFT))&I2C_I2COA7_I2COAx_MASK)

/* I2COA10 Bit Fields */
#define I2C_I2COA10_I2COAx_MASK                    0x03FFu
#define I2C_I2COA10_I2COAx_SHIFT                   0
#define I2C_I2COA10_I2COAx(x)                      (((uint16)(((uint16)(x))<<I2C_I2COA10_I2COAx_SHIFT))&I2C_I2COA10_I2COAx_MASK)

/* I2CSA7 Bit Fields */
#define I2C_I2CSA7_I2CSAx_MASK                     0x007Fu
#define I2C_I2CSA7_I2CSAx_SHIFT                    0
#define I2C_I2CSA7_I2CSAx(x)                       (((uint16)(((uint16)(x))<<I2C_I2CSA7_I2CSAx_SHIFT))&I2C_I2CSA7_I2CSAx_MASK)

/* I2CSA10 Bit Fields */
#define I2C_I2CSA10_I2CSAx_MASK                    0x03FFu
#define I2C_I2CSA10_I2CSAx_SHIFT                   0
#define I2C_I2CSA10_I2CSAx(x)                      (((uint16)(((uint16)(x))<<I2C_I2CSA10_I2CSAx_SHIFT))&I2C_I2CSA10_I2CSAx_MASK)

/* I2CIV Bit Fields */
#define I2C_I2CIV_I2CIVx_MASK                      0xFFFFu
#define I2C_I2CIV_I2CIVx_SHIFT                     0
#define I2C_I2CIV_I2CIVx(x)                        (((uint16)(((uint16)(x))<<I2C_I2CIV_I2CIVx_SHIFT))&I2C_I2CIV_I2CIVx_MASK)
/**
 * @}
 */ /* end of group I2C_Register_Masks */

/* I2C - Peripheral instance base addresses */
/** Peripheral I2C base pointer */
#define I2C_BASE_PTR                               ((I2C_MemMapPtr)0x0050u)
/* ----------------------------------------------------------------------------
   -- I2C - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup I2C_Register_Accessor_Macros I2C - Register accessor macros
 * @{
 */


/* I2C - Register instance definitions */
/* I2C */
#define I2C_I2CIE                                   (I2C_BASE_PTR->I2CIE)
#define I2C_I2CIFG                                  (I2C_BASE_PTR->I2CIFG)
#define I2C_I2CNDAT                                 (I2C_BASE_PTR->I2CNDAT)
#define I2C_U0CTL                                   (I2C_BASE_PTR->U0CTL)
#define I2C_I2CTCTL                                 (I2C_BASE_PTR->I2CTCTL)
#define I2C_I2CDCTL                                 (I2C_BASE_PTR->I2CDCTL)
#define I2C_I2CPSC                                  (I2C_BASE_PTR->I2CPSC)
#define I2C_I2CSCLH                                 (I2C_BASE_PTR->I2CSCLH)
#define I2C_I2CSCLL                                 (I2C_BASE_PTR->I2CSCLL)
#define I2C_I2CDRW_B                                (I2C_BASE_PTR->I2CDRW_B)
#define I2C_I2CDRW                                  (I2C_BASE_PTR->I2CDRW)
#define I2C_I2COA                                   (I2C_BASE_PTR->I2COA)
#define I2C_I2CSA                                   (I2C_BASE_PTR->I2CSA)
#define I2C_I2CIV                                   (I2C_BASE_PTR->I2CIV)
/**
 * @}
 */ /* end of group I2C_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group I2C_Peripheral */


/* ----------------------------------------------------------------------------
   -- CMPA
   ---------------------------------------------------------------------------- */
/** CMPA - Peripheral register structure */
typedef struct CMPA_MemMap {
  uint8 CACTL1;
  uint8 CACTL2;
  uint8 CAPD;
} volatile *CMPA_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- CMPA Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMPA_Register_Masks CMPA Register Masks
 * @{
 */

/* CACTL1 Bit Fields */
#define CMPA_CACTL1_CAEX_MASK                         0x80u
#define CMPA_CACTL1_CAEX_SHIFT                        7
#define CMPA_CACTL1_CAEX(x)                           (((uint8)(((uint8)(x))<<CMPA_CACTL1_CAEX_SHIFT))&CMPA_CACTL1_CAEX_MASK)

#define CMPA_CACTL1_CARSEL_MASK                       0x40u
#define CMPA_CACTL1_CARSEL_SHIFT                      6
#define CMPA_CACTL1_CARSEL(x)                         (((uint8)(((uint8)(x))<<CMPA_CACTL1_CARSEL_SHIFT))&CMPA_CACTL1_CARSEL_MASK)

#define CMPA_CACTL1_CAREFx_MASK                       0x30u
#define CMPA_CACTL1_CAREFx_SHIFT                      4
#define CMPA_CACTL1_CAREFx(x)                         (((uint8)(((uint8)(x))<<CMPA_CACTL1_CAREFx_SHIFT))&CMPA_CACTL1_CAREFx_MASK)

#define CMPA_CACTL1_CAON_MASK                         0x08u
#define CMPA_CACTL1_CAON_SHIFT                        3
#define CMPA_CACTL1_CAON(x)                           (((uint8)(((uint8)(x))<<CMPA_CACTL1_CAON_SHIFT))&CMPA_CACTL1_CAON_MASK)

#define CMPA_CACTL1_CAIES_MASK                        0x04u
#define CMPA_CACTL1_CAIES_SHIFT                       2
#define CMPA_CACTL1_CAIES(x)                          (((uint8)(((uint8)(x))<<CMPA_CACTL1_CAIES_SHIFT))&CMPA_CACTL1_CAIES_MASK)

#define CMPA_CACTL1_CAIE_MASK                         0x02u
#define CMPA_CACTL1_CAIE_SHIFT                        1
#define CMPA_CACTL1_CAIE(x)                           (((uint8)(((uint8)(x))<<CMPA_CACTL1_CAIE_SHIFT))&CMPA_CACTL1_CAIE_MASK)

#define CMPA_CACTL1_CAIFG_MASK                        0x01u
#define CMPA_CACTL1_CAIFG_SHIFT                       0
#define CMPA_CACTL1_CAIFG(x)                          (((uint8)(((uint8)(x))<<CMPA_CACTL1_CAIFG_SHIFT))&CMPA_CACTL1_CAIFG_MASK)

/* CACTL2 Bit Fields */
#define CMPA_CACTL2_P2CA1_MASK                        0x08u
#define CMPA_CACTL2_P2CA1_SHIFT                       3
#define CMPA_CACTL2_P2CA1(x)                          (((uint8)(((uint8)(x))<<CMPA_CACTL2_P2CA1_SHIFT))&CMPA_CACTL2_P2CA1_MASK)

#define CMPA_CACTL2_P2CA0_MASK                        0x04u
#define CMPA_CACTL2_P2CA0_SHIFT                       2
#define CMPA_CACTL2_P2CA0(x)                          (((uint8)(((uint8)(x))<<CMPA_CACTL2_P2CA0_SHIFT))&CMPA_CACTL2_P2CA0_MASK)

#define CMPA_CACTL2_CAF_MASK                          0x02u
#define CMPA_CACTL2_CAF_SHIFT                         1
#define CMPA_CACTL2_CAF(x)                            (((uint8)(((uint8)(x))<<CMPA_CACTL2_CAF_SHIFT))&CMPA_CACTL2_CAF_MASK)

#define CMPA_CACTL2_CAOUT_MASK                        0x01u
#define CMPA_CACTL2_CAOUT_SHIFT                       0
#define CMPA_CACTL2_CAOUT(x)                          (((uint8)(((uint8)(x))<<CMPA_CACTL2_CAOUT_SHIFT))&CMPA_CACTL2_CAOUT_MASK)

/* CAPD Bit Fields */
#define CMPA_CAPD_CAPD7_MASK                          0x80u
#define CMPA_CAPD_CAPD7_SHIFT                         7
#define CMPA_CAPD_CAPD7(x)                            (((uint8)(((uint8)(x))<<CMPA_CAPD_CAPD7_SHIFT))&CMPA_CAPD_CAPD7_MASK)

#define CMPA_CAPD_CAPD6_MASK                          0x40u
#define CMPA_CAPD_CAPD6_SHIFT                         6
#define CMPA_CAPD_CAPD6(x)                            (((uint8)(((uint8)(x))<<CMPA_CAPD_CAPD6_SHIFT))&CMPA_CAPD_CAPD6_MASK)

#define CMPA_CAPD_CAPD5_MASK                          0x20u
#define CMPA_CAPD_CAPD5_SHIFT                         5
#define CMPA_CAPD_CAPD5(x)                            (((uint8)(((uint8)(x))<<CMPA_CAPD_CAPD5_SHIFT))&CMPA_CAPD_CAPD5_MASK)

#define CMPA_CAPD_CAPD4_MASK                          0x10u
#define CMPA_CAPD_CAPD4_SHIFT                         4
#define CMPA_CAPD_CAPD4(x)                            (((uint8)(((uint8)(x))<<CMPA_CAPD_CAPD4_SHIFT))&CMPA_CAPD_CAPD4_MASK)

#define CMPA_CAPD_CAPD3_MASK                          0x08u
#define CMPA_CAPD_CAPD3_SHIFT                         3
#define CMPA_CAPD_CAPD3(x)                            (((uint8)(((uint8)(x))<<CMPA_CAPD_CAPD3_SHIFT))&CMPA_CAPD_CAPD3_MASK)

#define CMPA_CAPD_CAPD2_MASK                          0x04u
#define CMPA_CAPD_CAPD2_SHIFT                         2
#define CMPA_CAPD_CAPD2(x)                            (((uint8)(((uint8)(x))<<CMPA_CAPD_CAPD2_SHIFT))&CMPA_CAPD_CAPD2_MASK)

#define CMPA_CAPD_CAPD1_MASK                          0x02u
#define CMPA_CAPD_CAPD1_SHIFT                         1
#define CMPA_CAPD_CAPD1(x)                            (((uint8)(((uint8)(x))<<CMPA_CAPD_CAPD1_SHIFT))&CMPA_CAPD_CAPD1_MASK)

#define CMPA_CAPD_CAPD0_MASK                          0x01u
#define CMPA_CAPD_CAPD0_SHIFT                         0
#define CMPA_CAPD_CAPD0(x)                            (((uint8)(((uint8)(x))<<CMPA_CAPD_CAPD0_SHIFT))&CMPA_CAPD_CAPD0_MASK)
/**
 * @}
 */ /* end of group CMPA_Register_Masks */
 

/* CMPA - Peripheral instance base addresses */
/** Peripheral CMPA base pointer */
#define CMPA_BASE_PTR                             ((CMPA_MemMapPtr)0x0059u)
/* ----------------------------------------------------------------------------
   -- CMPA - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup CMPA_Register_Accessor_Macros CMPA - Register accessor macros
 * @{
 */


/* CMPA - Register instance definitions */
/* CMPA */
#define CMPA_CACTL1                                (CMPA_BASE_PTR->CACTL1)
#define CMPA_CACTL2                                (CMPA_BASE_PTR->CACTL2)
#define CMPA_CAPD                                  (CMPA_BASE_PTR->CAPD)
/**
 * @}
 */ /* end of group CMPA_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group CMPA_Peripheral */




/* ----------------------------------------------------------------------------
   -- ADC12
   ---------------------------------------------------------------------------- */
/** ADC12 - Peripheral register structure */
typedef struct ADC12_MemMap {
  uint8 ADC12MCTL[16];
  uint8 RESERVED_0[176];
  uint16 ADC12MEM[16];
  uint8 RESERVED_1[64];
  uint16 ADC12CTL0;
  uint16 ADC12CTL1;
  uint16 ADC12IFG;
  uint16 ADC12IE;
  uint16 ADC12IV;
} volatile *ADC12_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- ADC12 Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC12_Register_Masks ADC12 Register Masks
 * @{
 */

/* ADC12CTL0 Bit Fields */
#define ADC12_ADC12CTL0_SHT1x_MASK                         0xF000u
#define ADC12_ADC12CTL0_SHT1x_SHIFT                        12
#define ADC12_ADC12CTL0_SHT1x(x)                           (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_SHT1x_SHIFT))&ADC12_ADC12CTL0_SHT1x_MASK)

#define ADC12_ADC12CTL0_SHT0x_MASK                         0x0F00u
#define ADC12_ADC12CTL0_SHT0x_SHIFT                        8
#define ADC12_ADC12CTL0_SHT0x(x)                           (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_SHT0x_SHIFT))&ADC12_ADC12CTL0_SHT0x_MASK)

#define ADC12_ADC12CTL0_MSC_MASK                           0x0080u
#define ADC12_ADC12CTL0_MSC_SHIFT                          7
#define ADC12_ADC12CTL0_MSC(x)                             (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_SHT1x_SHIFT))&ADC12_ADC12CTL0_SHT1x_MASK)

#define ADC12_ADC12CTL0_REF2_5V_MASK                       0x0040u
#define ADC12_ADC12CTL0_REF2_5V_SHIFT                      6
#define ADC12_ADC12CTL0_REF2_5V(x)                         (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_REF2_5V_SHIFT))&ADC12_ADC12CTL0_REF2_5V_MASK)

#define ADC12_ADC12CTL0_REFON_MASK                         0x0020u
#define ADC12_ADC12CTL0_REFON_SHIFT                        5
#define ADC12_ADC12CTL0_REFON(x)                           (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_REFON_SHIFT))&ADC12_ADC12CTL0_REFON_MASK)

#define ADC12_ADC12CTL0_ADC12ON_MASK                       0x0010u
#define ADC12_ADC12CTL0_ADC12ON_SHIFT                      4
#define ADC12_ADC12CTL0_ADC12ON(x)                         (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_ADC12ON_SHIFT))&ADC12_ADC12CTL0_ADC12ON_MASK)

#define ADC12_ADC12CTL0_ADC12OVIE_MASK                     0x0008u
#define ADC12_ADC12CTL0_ADC12OVIE_SHIFT                    3
#define ADC12_ADC12CTL0_ADC12OVIE(x)                       (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_ADC12OVIE_SHIFT))&ADC12_ADC12CTL0_ADC12OVIE_MASK)

#define ADC12_ADC12CTL0_ADC12TOVIE_MASK                    0x0004u
#define ADC12_ADC12CTL0_ADC12TOVIE_SHIFT                   2
#define ADC12_ADC12CTL0_ADC12TOVIE(x)                      (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_ADC12TOVIE_SHIFT))&ADC12_ADC12CTL0_ADC12TOVIE_MASK)

#define ADC12_ADC12CTL0_ENC_MASK                           0x0002u
#define ADC12_ADC12CTL0_ENC_SHIFT                          1
#define ADC12_ADC12CTL0_ENC(x)                             (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_ENC_SHIFT))&ADC12_ADC12CTL0_ENC_MASK)

#define ADC12_ADC12CTL0_ADC12SC_MASK                       0x0001u
#define ADC12_ADC12CTL0_ADC12SC_SHIFT                      0
#define ADC12_ADC12CTL0_ADC12SC(x)                         (((uint16)(((uint16)(x))<<ADC12_ADC12CTL0_ADC12SC_SHIFT))&ADC12_ADC12CTL0_ADC12SC_MASK)

/* ADC12CTL1 Bit Fields */
#define ADC12_ADC12CTL1_CSTARTADDx_MASK                    0xF000u
#define ADC12_ADC12CTL1_CSTARTADDx_SHIFT                   12
#define ADC12_ADC12CTL1_CSTARTADDx(x)                      (((uint16)(((uint16)(x))<<ADC12_ADC12CTL1_CSTARTADDx_SHIFT))&ADC12_ADC12CTL1_CSTARTADDx_MASK)

#define ADC12_ADC12CTL1_SHSx_MASK                          0x0C00u
#define ADC12_ADC12CTL1_SHSx_SHIFT                         10
#define ADC12_ADC12CTL1_SHSx(x)                            (((uint16)(((uint16)(x))<<ADC12_ADC12CTL1_SHSx_SHIFT))&ADC12_ADC12CTL1_SHSx_MASK)

#define ADC12_ADC12CTL1_SHP_MASK                           0x0200u
#define ADC12_ADC12CTL1_SHP_SHIFT                          9
#define ADC12_ADC12CTL1_SHP(x)                             (((uint16)(((uint16)(x))<<ADC12_ADC12CTL1_SHP_SHIFT))&ADC12_ADC12CTL1_SHP_MASK)

#define ADC12_ADC12CTL1_ISSH_MASK                          0x0100u
#define ADC12_ADC12CTL1_ISSH_SHIFT                         8
#define ADC12_ADC12CTL1_ISSH(x)                            (((uint16)(((uint16)(x))<<ADC12_ADC12CTL1_ISSH_SHIFT))&ADC12_ADC12CTL1_ISSH_MASK)

#define ADC12_ADC12CTL1_ADC12DIVx_MASK                     0x00E0u
#define ADC12_ADC12CTL1_ADC12DIVx_SHIFT                    5
#define ADC12_ADC12CTL1_ADC12DIVx(x)                       (((uint16)(((uint16)(x))<<ADC12_ADC12CTL1_ADC12DIVx_SHIFT))&ADC12_ADC12CTL1_ADC12DIVx_MASK)

#define ADC12_ADC12CTL1_ADC12SSELx_MASK                    0x0018u
#define ADC12_ADC12CTL1_ADC12SSELx_SHIFT                   3
#define ADC12_ADC12CTL1_ADC12SSELx(x)                      (((uint16)(((uint16)(x))<<ADC12_ADC12CTL1_ADC12SSELx_SHIFT))&ADC12_ADC12CTL1_ADC12SSELx_MASK)

#define ADC12_ADC12CTL1_CONSEQx_MASK                       0x0006u
#define ADC12_ADC12CTL1_CONSEQx_SHIFT                      1
#define ADC12_ADC12CTL1_CONSEQx(x)                         (((uint16)(((uint16)(x))<<ADC12_ADC12CTL1_CONSEQx_SHIFT))&ADC12_ADC12CTL1_CONSEQx_MASK)

#define ADC12_ADC12CTL1_ADC12BUSY_MASK                     0x0001u
#define ADC12_ADC12CTL1_ADC12BUSY_SHIFT                    0
#define ADC12_ADC12CTL1_ADC12BUSY(x)                       (((uint16)(((uint16)(x))<<ADC12_ADC12CTL1_ADC12BUSY_SHIFT))&ADC12_ADC12CTL1_ADC12BUSY_MASK)

/* ADC12MEMx Bit Fields */
#define ADC12_ADC12MEMx_CR_MASK                            0xFFFFu
#define ADC12_ADC12MEMx_CR_SHIFT                           0
#define ADC12_ADC12MEMx_CR(x)                              (((uint16)(((uint16)(x))<<ADC12_ADC12MEMx_CR_SHIFT))&ADC12_ADC12MEMx_CR_MASK)

/* ADC12MCTLx Bit Fields */
#define ADC12_ADC12MCTLx_EOS_MASK                          0x80u
#define ADC12_ADC12MCTLx_EOS_SHIFT                         7
#define ADC12_ADC12MCTLx_EOS(x)                            (((uint8)(((uint8)(x))<<ADC12_ADC12MCTLx_EOS_SHIFT))&ADC12_ADC12MCTLx_EOS_MASK)

#define ADC12_ADC12MCTLx_SREFx_MASK                        0x70u
#define ADC12_ADC12MCTLx_SREFx_SHIFT                       4
#define ADC12_ADC12MCTLx_SREFx(x)                          (((uint8)(((uint8)(x))<<ADC12_ADC12MCTLx_SREFx_SHIFT))&ADC12_ADC12MCTLx_SREFx_MASK)

#define ADC12_ADC12MCTLx_INCHx_MASK                        0x0Fu
#define ADC12_ADC12MCTLx_INCHx_SHIFT                       0
#define ADC12_ADC12MCTLx_INCHx(x)                          (((uint8)(((uint8)(x))<<ADC12_ADC12MCTLx_INCHx_SHIFT))&ADC12_ADC12MCTLx_INCHx_MASK)

/* ADC12IE Bit Fields */
#define ADC12_ADC12IE_ADC12IEx_MASK                        0xFFFFu
#define ADC12_ADC12IE_ADC12IEx_SHIFT                       0
#define ADC12_ADC12IE_ADC12IEx(x)                          (((uint16)(((uint16)(x))<<ADC12_ADC12IE_ADC12IEx_SHIFT))&ADC12_ADC12IE_ADC12IEx_MASK)

/* ADC12IFG Bit Fields */
#define ADC12_ADC12IFG_ADC12IFGx_MASK                      0xFFFFu
#define ADC12_ADC12IFG_ADC12IFGx_SHIFT                     0
#define ADC12_ADC12IFG_ADC12IFGx(x)                        (((uint16)(((uint16)(x))<<ADC12_ADC12IFG_ADC12IFGx_SHIFT))&ADC12_ADC12IFG_ADC12IFGx_MASK)

/* ADC12IV Bit Fields */
#define ADC12_ADC12IV_ADC12IVx_MASK                        0x003Eu
#define ADC12_ADC12IV_ADC12IVx_SHIFT                       0
#define ADC12_ADC12IV_ADC12IVx(x)                          (((uint16)(((uint16)(x))<<ADC12_ADC12IV_ADC12IVx_SHIFT))&ADC12_ADC12IV_ADC12IVx_MASK)
/**
 * @}
 */ /* end of group ADC12_Register_Masks */
 

/* ADC12 - Peripheral instance base addresses */
/** Peripheral ADC12 base pointer */
#define ADC12_BASE_PTR                                    ((ADC12_MemMapPtr)0x0080u)
/* ----------------------------------------------------------------------------
   -- ADC12 - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC12_Register_Accessor_Macros ADC12 - Register accessor macros
 * @{
 */


/* ADC12 - Register instance definitions */
/* ADC12 */
#define ADC12_ADC12MCTL(x)                                   (ADC12_BASE_PTR->ADC12MCTL[x])
#define ADC12_ADC12MEM(x)                                    (ADC12_BASE_PTR->ADC12MEM[x])
#define ADC12_ADC12CTL0                                      (ADC12_BASE_PTR->ADC12CTL0)
#define ADC12_ADC12CTL1                                      (ADC12_BASE_PTR->ADC12CTL1)
#define ADC12_ADC12IFG                                       (ADC12_BASE_PTR->ADC12IFG)
#define ADC12_ADC12IE                                        (ADC12_BASE_PTR->ADC12IE)
#define ADC12_ADC12IV                                        (ADC12_BASE_PTR->ADC12IV)
/**
 * @}
 */ /* end of group ADC12_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ADC12_Peripheral */





/* ----------------------------------------------------------------------------
   -- ADC10
   ---------------------------------------------------------------------------- */
/** ADC10 - Peripheral register structure */
typedef struct ADC10_MemMap {
  uint8 ADC10DTC0;
  uint8 ADC10DTC1;
  uint8 ADC10AE;
  uint8 RESERVED_0[357];
  uint16 ADC10CTL0;
  uint16 ADC10CTL1;
  uint16 ADC10MEM;
  uint8 RESERVED_1[6];
  uint16 ADC10SA;
} volatile *ADC10_MemMapPtr;
	
/* ----------------------------------------------------------------------------
   -- ADC10 Register Masks
   ---------------------------------------------------------------------------- */
	
/**
 * @addtogroup ADC10_Register_Masks ADC10 Register Masks
 * @{
 */
	
/* ADC10CTL0 Bit Fields */
#define ADC10_ADC10CTL0_SREFx_MASK                         0xE000u
#define ADC10_ADC10CTL0_SREFx_SHIFT                        13
#define ADC10_ADC10CTL0_SREFx(x)                           (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_SREFx_SHIFT))&ADC10_ADC10CTL0_SREFx_MASK)

#define ADC10_ADC10CTL0_ADC10SHTx_MASK                     0x1800u
#define ADC10_ADC10CTL0_ADC10SHTx_SHIFT                    11
#define ADC10_ADC10CTL0_ADC10SHTx(x)                       (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_ADC10SHTx_SHIFT))&ADC10_ADC10CTL0_ADC10SHTx_MASK)

#define ADC10_ADC10CTL0_ADC10SR_MASK                       0x0400u
#define ADC10_ADC10CTL0_ADC10SR_SHIFT                      10
#define ADC10_ADC10CTL0_ADC10SR(x)                         (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_ADC10SR_SHIFT))&ADC10_ADC10CTL0_ADC10SR_MASK)

#define ADC10_ADC10CTL0_REFOUT_MASK                        0x0200u
#define ADC10_ADC10CTL0_REFOUT_SHIFT                       9
#define ADC10_ADC10CTL0_REFOUT(x)                          (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_REFOUT_SHIFT))&ADC10_ADC10CTL0_REFOUT_MASK)

#define ADC10_ADC10CTL0_REFBURST_MASK                      0x0100u
#define ADC10_ADC10CTL0_REFBURST_SHIFT                     8
#define ADC10_ADC10CTL0_REFBURST(x)                        (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_REFBURST_SHIFT))&ADC10_ADC10CTL0_REFBURST_MASK)

#define ADC10_ADC10CTL0_MSC_MASK                           0x0080u
#define ADC10_ADC10CTL0_MSC_SHIFT                          7
#define ADC10_ADC10CTL0_MSC(x)                             (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_MSC_SHIFT))&ADC10_ADC10CTL0_MSC_MASK)

#define ADC10_ADC10CTL0_REF2_5V_MASK                       0x0040u
#define ADC10_ADC10CTL0_REF2_5V_SHIFT                      6
#define ADC10_ADC10CTL0_REF2_5V(x)                         (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_REF2_5V_SHIFT))&ADC10_ADC10CTL0_REF2_5V_MASK)

#define ADC10_ADC10CTL0_REFON_MASK                         0x0020u
#define ADC10_ADC10CTL0_REFON_SHIFT                        5
#define ADC10_ADC10CTL0_REFON(x)                           (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_REFON_SHIFT))&ADC10_ADC10CTL0_REFON_MASK)

#define ADC10_ADC10CTL0_ADC10ON_MASK                       0x0010u
#define ADC10_ADC10CTL0_ADC10ON_SHIFT                      4
#define ADC10_ADC10CTL0_ADC10ON(x)                         (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_ADC10ON_SHIFT))&ADC10_ADC10CTL0_ADC10ON_MASK)

#define ADC10_ADC10CTL0_ADC10IE_MASK                       0x0008u
#define ADC10_ADC10CTL0_ADC10IE_SHIFT                      3
#define ADC10_ADC10CTL0_ADC10IE(x)                         (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_ADC10IE_SHIFT))&ADC10_ADC10CTL0_ADC10IE_MASK)

#define ADC10_ADC10CTL0_ADC10IFG_MASK                      0x0004u
#define ADC10_ADC10CTL0_ADC10IFG_SHIFT                     2
#define ADC10_ADC10CTL0_ADC10IFG(x)                        (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_ADC10IFG_SHIFT))&ADC10_ADC10CTL0_ADC10IFG_MASK)

#define ADC10_ADC10CTL0_ENC_MASK                           0x0002u
#define ADC10_ADC10CTL0_ENC_SHIFT                          1
#define ADC10_ADC10CTL0_ENC(x)                             (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_ENC_SHIFT))&ADC10_ADC10CTL0_ENC_MASK)

#define ADC10_ADC10CTL0_ADC10SC_MASK                       0x0001u
#define ADC10_ADC10CTL0_ADC10SC_SHIFT                      0
#define ADC10_ADC10CTL0_ADC10SC(x)                         (((uint16)(((uint16)(x))<<ADC10_ADC10CTL0_ADC10SC_SHIFT))&ADC10_ADC10CTL0_ADC10SC_MASK)

/* ADC10CTL1 Bit Fields */
#define ADC10_ADC10CTL1_INCHx_MASK                         0xF000u
#define ADC10_ADC10CTL1_INCHx_SHIFT                        12
#define ADC10_ADC10CTL1_INCHx(x)                           (((uint16)(((uint16)(x))<<ADC10_ADC10CTL1_INCHx_SHIFT))&ADC10_ADC10CTL1_INCHx_MASK)

#define ADC10_ADC10CTL1_SHSx_MASK                          0x0C00u
#define ADC10_ADC10CTL1_SHSx_SHIFT                         10
#define ADC10_ADC10CTL1_SHSx(x)                            (((uint16)(((uint16)(x))<<ADC10_ADC10CTL1_SHSx_SHIFT))&ADC10_ADC10CTL1_SHSx_MASK)

#define ADC10_ADC10CTL1_ADC10DF_MASK                       0x0200u
#define ADC10_ADC10CTL1_ADC10DF_SHIFT                      9
#define ADC10_ADC10CTL1_ADC10DF(x)                         (((uint16)(((uint16)(x))<<ADC10_ADC10CTL1_ADC10DF_SHIFT))&ADC10_ADC10CTL1_ADC10DF_MASK)

#define ADC10_ADC10CTL1_ISSH_MASK                          0x0100u
#define ADC10_ADC10CTL1_ISSH_SHIFT                         8
#define ADC10_ADC10CTL1_ISSH(x)                            (((uint16)(((uint16)(x))<<ADC10_ADC10CTL1_ISSH_SHIFT))&ADC10_ADC10CTL1_ISSH_MASK)

#define ADC10_ADC10CTL1_ADC10DIVx_MASK                     0x00E0u
#define ADC10_ADC10CTL1_ADC10DIVx_SHIFT                    5
#define ADC10_ADC10CTL1_ADC10DIVx(x)                       (((uint16)(((uint16)(x))<<ADC10_ADC10CTL1_ADC10DIVx_SHIFT))&ADC10_ADC10CTL1_ADC10DIVx_MASK)

#define ADC10_ADC10CTL1_ADC10SSELx_MASK                    0x0018u
#define ADC10_ADC10CTL1_ADC10SSELx_SHIFT                   3
#define ADC10_ADC10CTL1_ADC10SSELx(x)                      (((uint16)(((uint16)(x))<<ADC10_ADC10CTL1_ADC10SSELx_SHIFT))&ADC10_ADC10CTL1_ADC10SSELx_MASK)

#define ADC10_ADC10CTL1_CONSEQx_MASK                       0x0006u
#define ADC10_ADC10CTL1_CONSEQx_SHIFT                      1
#define ADC10_ADC10CTL1_CONSEQx(x)                         (((uint16)(((uint16)(x))<<ADC10_ADC10CTL1_CONSEQx_SHIFT))&ADC10_ADC10CTL1_CONSEQx_MASK)

#define ADC10_ADC10CTL1_ADC10BUSY_MASK                     0x0001u
#define ADC10_ADC10CTL1_ADC10BUSY_SHIFT                    0
#define ADC10_ADC10CTL1_ADC10BUSY(x)                       (((uint16)(((uint16)(x))<<ADC10_ADC10CTL1_ADC10BUSY_SHIFT))&ADC10_ADC10CTL1_ADC10BUSY_MASK)

/* ADC10AE Bit Fields */
#define ADC10_ADC10AE_ADC10AEx_MASK                        0xFFu
#define ADC10_ADC10AE_ADC10AEx_SHIFT                       0
#define ADC10_ADC10AE_ADC10AEx(x)                          (((uint8)(((uint8)(x))<<ADC10_ADC10AE_ADC10AEx_SHIFT))&ADC10_ADC10AE_ADC10AEx_MASK)

/* ADC10MEMB Bit Fields */
#define ADC10_ADC10MEMB_CR_MASK                            0x03FFu
#define ADC10_ADC10MEMB_CR_SHIFT                           0
#define ADC10_ADC10MEMB_CR(x)                              (((uint16)(((uint16)(x))<<ADC10_ADC10MEMB_CR_SHIFT))&ADC10_ADC10MEMB_CR_MASK)

/* ADC10MEMC Bit Fields */
#define ADC10_ADC10MEMC_CR_MASK                            0xFFC0u
#define ADC10_ADC10MEMC_CR_SHIFT                           0
#define ADC10_ADC10MEMC_CR(x)                              (((uint16)(((uint16)(x))<<ADC10_ADC10MEMC_CR_SHIFT))&ADC10_ADC10MEMC_CR_MASK)

/* ADC10DTC0 Bit Fields */
#define ADC10_ADC10DTC0_ADC10TB_MASK                       0x08u
#define ADC10_ADC10DTC0_ADC10TB_SHIFT                      3
#define ADC10_ADC10DTC0_ADC10TB(x)                         (((uint8)(((uint8)(x))<<ADC10_ADC10DTC0_ADC10TB_SHIFT))&ADC10_ADC10DTC0_ADC10TB_MASK)

#define ADC10_ADC10DTC0_ADC10CT_MASK                       0x04u
#define ADC10_ADC10DTC0_ADC10CT_SHIFT                      2
#define ADC10_ADC10DTC0_ADC10CT(x)                         (((uint8)(((uint8)(x))<<ADC10_ADC10DTC0_ADC10CT_SHIFT))&ADC10_ADC10DTC0_ADC10CT_MASK)

#define ADC10_ADC10DTC0_ADC10B1_MASK                       0x02u
#define ADC10_ADC10DTC0_ADC10B1_SHIFT                      1
#define ADC10_ADC10DTC0_ADC10B1(x)                         (((uint8)(((uint8)(x))<<ADC10_ADC10DTC0_ADC10B1_SHIFT))&ADC10_ADC10DTC0_ADC10B1_MASK)

#define ADC10_ADC10DTC0_ADC10FETCH_MASK                    0x01u
#define ADC10_ADC10DTC0_ADC10FETCH_SHIFT                   0
#define ADC10_ADC10DTC0_ADC10FETCH(x)                      (((uint8)(((uint8)(x))<<ADC10_ADC10DTC0_ADC10FETCH_SHIFT))&ADC10_ADC10DTC0_ADC10FETCH_MASK)

/* ADC10DTC1 Bit Fields */
#define ADC10_ADC10DTC1_DTCT_MASK                          0xFFu
#define ADC10_ADC10DTC1_DTCT_SHIFT                         0
#define ADC10_ADC10DTC1_DTCT(x)                            (((uint8)(((uint8)(x))<<ADC10_ADC10DTC1_DTCT_SHIFT))&ADC10_ADC10DTC1_DTCT_MASK)

/* ADC10SA Bit Fields */
#define ADC10_ADC10SA_ADC10SAx_MASK                        0xFFFEu
#define ADC10_ADC10SA_ADC10SAx_SHIFT                       1
#define ADC10_ADC10SA_ADC10SAx(x)                          (((uint16)(((uint16)(x))<<ADC10_ADC10SA_ADC10SAx_SHIFT))&ADC10_ADC10SA_ADC10SAx_MASK)
/**
 * @}
 */ /* end of group ADC10_Register_Masks */
 

/* ADC10 - Peripheral instance base addresses */
/** Peripheral ADC10 base pointer */
#define ADC10_BASE_PTR                                    ((ADC10_MemMapPtr)0x0080u)
/* ----------------------------------------------------------------------------
   -- ADC10 - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup ADC10_Register_Accessor_Macros ADC10 - Register accessor macros
 * @{
 */


/* ADC10 - Register instance definitions */
/* ADC10 */
#define ADC10_ADC10DTC0                                   (ADC10_BASE_PTR->ADC10DTC0)
#define ADC10_ADC10DTC1                                   (ADC10_BASE_PTR->ADC10DTC1)
#define ADC10_ADC10AE                                     (ADC10_BASE_PTR->ADC10AE)
#define ADC10_ADC10CTL0                                   (ADC10_BASE_PTR->ADC10CTL0)
#define ADC10_ADC10CTL1                                   (ADC10_BASE_PTR->ADC10CTL1)
#define ADC10_ADC10MEM                                    (ADC10_BASE_PTR->ADC10MEM)
#define ADC10_ADC10SA                                     (ADC10_BASE_PTR->ADC10SA)

/**
 * @}
 */ /* end of group ADC12_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group ADC12_Peripheral */





/* ----------------------------------------------------------------------------
   -- DAC12
   ---------------------------------------------------------------------------- */
/** DAC12 - Peripheral register structure */
typedef struct DAC12_MemMap {
  uint16 DAC12_xCTL;
  uint8 RESERVED_0[6];
  uint16 DAC12_xDAT;
} volatile *DAC12_MemMapPtr;

/* ----------------------------------------------------------------------------
   -- DAC12 - Register accessor macros
   ---------------------------------------------------------------------------- */
/* DAC12 - Register accessors */
#define DAC12_DAC12_xCTL_REG(base)                       ((base)->DAC12_xCTL)
#define DAC12_DAC12_xDAT_REG(base)                       ((base)->DAC12_xDAT)

/**
 * @}
 */ /* end of group DAC12_Register_Accessor_Macros */

	
/* ----------------------------------------------------------------------------
   -- DAC12 Register Masks
   ---------------------------------------------------------------------------- */
	
/**
 * @addtogroup DAC12_Register_Masks DAC12 Register Masks
 * @{
 */
	
/* DAC12_xCTL Bit Fields */
#define DAC12_DAC12_xCTL_DAC12SREFx_MASK                         0x6000u
#define DAC12_DAC12_xCTL_DAC12SREFx_SHIFT                        13
#define DAC12_DAC12_xCTL_DAC12SREFx(x)                           (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12SREFx_SHIFT))&DAC12_DAC12_xCTL_DAC12SREFx_MASK)

#define DAC12_DAC12_xCTL_DAC12RES_MASK                           0x1000u
#define DAC12_DAC12_xCTL_DAC12RES_SHIFT                          12
#define DAC12_DAC12_xCTL_DAC12RES(x)                             (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12RES_SHIFT))&DAC12_DAC12_xCTL_DAC12RES_MASK)

#define DAC12_DAC12_xCTL_DAC12LSELx_MASK                         0x0C00u
#define DAC12_DAC12_xCTL_DAC12LSELx_SHIFT                        10
#define DAC12_DAC12_xCTL_DAC12LSELx(x)                           (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12LSELx_SHIFT))&DAC12_DAC12_xCTL_DAC12LSELx_MASK)

#define DAC12_DAC12_xCTL_DAC12CALON_MASK                         0x0200u
#define DAC12_DAC12_xCTL_DAC12CALON_SHIFT                        9
#define DAC12_DAC12_xCTL_DAC12CALON(x)                           (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12CALON_SHIFT))&DAC12_DAC12_xCTL_DAC12CALON_MASK)

#define DAC12_DAC12_xCTL_DAC12IR_MASK                            0x0100u
#define DAC12_DAC12_xCTL_DAC12IR_SHIFT                           8
#define DAC12_DAC12_xCTL_DAC12IR(x)                              (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12IR_SHIFT))&DAC12_DAC12_xCTL_DAC12IR_MASK)

#define DAC12_DAC12_xCTL_DAC12AMPx_MASK                          0x00E0u
#define DAC12_DAC12_xCTL_DAC12AMPx_SHIFT                         5
#define DAC12_DAC12_xCTL_DAC12AMPx(x)                            (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12AMPx_SHIFT))&DAC12_DAC12_xCTL_DAC12AMPx_MASK)

#define DAC12_DAC12_xCTL_DAC12DF_MASK                            0x0010u
#define DAC12_DAC12_xCTL_DAC12DF_SHIFT                           4
#define DAC12_DAC12_xCTL_DAC12DF(x)                              (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12DF_SHIFT))&DAC12_DAC12_xCTL_DAC12DF_MASK)

#define DAC12_DAC12_xCTL_DAC12IE_MASK                            0x0008u
#define DAC12_DAC12_xCTL_DAC12IE_SHIFT                           3
#define DAC12_DAC12_xCTL_DAC12IE(x)                              (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12IE_SHIFT))&DAC12_DAC12_xCTL_DAC12IE_MASK)

#define DAC12_DAC12_xCTL_DAC12IFG_MASK                           0x0004u
#define DAC12_DAC12_xCTL_DAC12IFG_SHIFT                          2
#define DAC12_DAC12_xCTL_DAC12IFG(x)                             (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12IFG_SHIFT))&DAC12_DAC12_xCTL_DAC12IFG_MASK)

#define DAC12_DAC12_xCTL_DAC12ENC_MASK                           0x0002u
#define DAC12_DAC12_xCTL_DAC12ENC_SHIFT                          1
#define DAC12_DAC12_xCTL_DAC12ENC(x)                             (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12ENC_SHIFT))&DAC12_DAC12_xCTL_DAC12ENC_MASK)

#define DAC12_DAC12_xCTL_DAC12GRP_MASK                           0x0001u
#define DAC12_DAC12_xCTL_DAC12GRP_SHIFT                          0
#define DAC12_DAC12_xCTL_DAC12GRP(x)                             (((uint16)(((uint16)(x))<<DAC12_DAC12_xCTL_DAC12GRP_SHIFT))&DAC12_DAC12_xCTL_DAC12GRP_MASK)

/* DAC12_xDAT Bit Fields */
#define DAC12_DAC12_xDAT_DAC12D_MASK                             0x0FFFu
#define DAC12_DAC12_xDAT_DAC12D_SHIFT                            0
#define DAC12_DAC12_xDAT_DAC12D(x)                               (((uint16)(((uint16)(x))<<DAC12_DAC12_xDAT_DAC12D_SHIFT))&DAC12_DAC12_xDAT_DAC12D_MASK)
/**
 * @}
 */ /* end of group DAC12_Register_Masks */
 

/* DAC12 - Peripheral instance base addresses */
/** Peripheral DAC12 base pointer */
#define DAC12_0_BASE_PTR                                    ((DAC12_MemMapPtr)0x01C0u)
#define DAC12_1_BASE_PTR                                    ((DAC12_MemMapPtr)0x01C2u)

/* ----------------------------------------------------------------------------
   -- DAC12 - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup DAC12_Register_Accessor_Macros DAC12 - Register accessor macros
 * @{
 */


/* DAC12 - Register instance definitions */
/* DAC12_0 */
#define DAC12_0_DAC12_0CTL                                   DAC12_DAC12_xCTL_REG(DAC12_0_BASE_PTR)
#define DAC12_0_DAC12_0DAT                                   DAC12_DAC12_xDAT_REG(DAC12_0_BASE_PTR)
/* DAC12_1 */
#define DAC12_1_DAC12_1CTL                                   DAC12_DAC12_xCTL_REG(DAC12_1_BASE_PTR)
#define DAC12_1_DAC12_1DAT                                   DAC12_DAC12_xDAT_REG(DAC12_1_BASE_PTR)
/**
 * @}
 */ /* end of group DAC12_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group DAC12_Peripheral */



/* ----------------------------------------------------------------------------
   -- SFR
   ---------------------------------------------------------------------------- */
/** SFR - Peripheral register structure */
typedef struct SFR_MemMap {
  uint8 IE1;
  uint8 IE2;
  uint8 IFG1;
  uint8 IFG2;
  uint8 ME1;
  uint8 ME2;
} volatile *SFR_MemMapPtr;
/* ----------------------------------------------------------------------------
   -- SFR Register Masks
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SFR_Register_Masks SFR Register Masks
 * @{
 */

/* IE1 Bit Fields */
#define SFR_IE1_OFIE_MASK                           0x02u
#define SFR_IE1_OFIE_SHIFT                          1
#define SFR_IE1_OFIE(x)                             (((uint8)(((uint8)(x))<<SFR_IE1_OFIE_SHIFT))&SFR_IE1_OFIE_MASK)

#define SFR_IE1_UTXIE0_MASK                         0x80u
#define SFR_IE1_UTXIE0_SHIFT                        7
#define SFR_IE1_UTXIE0(x)                           (((uint8)(((uint8)(x))<<SFR_IE1_UTXIE0_SHIFT))&SFR_IE1_UTXIE0_MASK)

#define SFR_IE1_URXIE0_MASK                         0x40u
#define SFR_IE1_URXIE0_SHIFT                        6
#define SFR_IE1_URXIE0(x)                           (((uint8)(((uint8)(x))<<SFR_IE1_URXIE0_SHIFT))&SFR_IE1_URXIE0_MASK)

/* IE2 Bit Fields */
#define SFR_IE2_UTXIE1_MASK                         0x20u
#define SFR_IE2_UTXIE1_SHIFT                        5
#define SFR_IE2_UTXIE1(x)                           (((uint8)(((uint8)(x))<<SFR_IE2_UTXIE1_SHIFT))&SFR_IE2_UTXIE1_MASK)

#define SFR_IE2_URXIE1_MASK                         0x10u
#define SFR_IE2_URXIE1_SHIFT                        4
#define SFR_IE2_URXIE1(x)                           (((uint8)(((uint8)(x))<<SFR_IE2_URXIE1_SHIFT))&SFR_IE2_URXIE1_MASK)

#define SFR_IE2_UTXIE0_MASK                         0x02u
#define SFR_IE2_UTXIE0_SHIFT                        1
#define SFR_IE2_UTXIE0(x)                           (((uint8)(((uint8)(x))<<SFR_IE2_UTXIE0_SHIFT))&SFR_IE2_UTXIE0_MASK)

#define SFR_IE2_URXIE0_MASK                         0x01u
#define SFR_IE2_URXIE0_SHIFT                        0
#define SFR_IE2_URXIE0(x)                           (((uint8)(((uint8)(x))<<SFR_IE2_URXIE0_SHIFT))&SFR_IE2_URXIE0_MASK)


/* IFG1 Bit Fields */
#define SFR_IFG1_OFIFG_MASK                         0x02u
#define SFR_IFG1_OFIFG_SHIFT                        1
#define SFR_IFG1_OFIFG(x)                           (((uint8)(((uint8)(x))<<SFR_IFG1_OFIFG_SHIFT))&SFR_IFG1_OFIFG_MASK)

#define SFR_IFG1_UTXIFG0_MASK                       0x80u
#define SFR_IFG1_UTXIFG0_SHIFT                      7
#define SFR_IFG1_UTXIFG0(x)                         (((uint8)(((uint8)(x))<<SFR_IFG1_UTXIFG0_SHIFT))&SFR_IFG1_UTXIFG0_MASK)

#define SFR_IFG1_URXIFG0_MASK                       0x40u
#define SFR_IFG1_URXIFG0_SHIFT                      6
#define SFR_IFG1_URXIFG0(x)                         (((uint8)(((uint8)(x))<<SFR_IFG1_URXIFG0_SHIFT))&SFR_IFG1_URXIFG0_MASK)


/* IFG2 Bit Fields */
#define SFR_IFG2_UTXIFG1_MASK                       0x20u
#define SFR_IFG2_UTXIFG1_SHIFT                      5
#define SFR_IFG2_UTXIFG1(x)                         (((uint8)(((uint8)(x))<<SFR_IFG2_UTXIFG1_SHIFT))&SFR_IFG2_UTXIFG1_MASK)

#define SFR_IFG2_URXIFG1_MASK                       0x10u
#define SFR_IFG2_URXIFG1_SHIFT                      4
#define SFR_IFG2_URXIFG1(x)                         (((uint8)(((uint8)(x))<<SFR_IFG2_URXIFG1_SHIFT))&SFR_IFG2_URXIFG1_MASK)

#define SFR_IFG2_UTXIFG0_MASK                       0x02u
#define SFR_IFG2_UTXIFG0_SHIFT                      1
#define SFR_IFG2_UTXIFG0(x)                         (((uint8)(((uint8)(x))<<SFR_IFG2_UTXIFG0_SHIFT))&SFR_IFG2_UTXIFG0_MASK)

#define SFR_IFG2_URXIFG0_MASK                       0x01u
#define SFR_IFG2_URXIFG0_SHIFT                      0
#define SFR_IFG2_URXIFG0(x)                         (((uint8)(((uint8)(x))<<SFR_IFG2_URXIFG0_SHIFT))&SFR_IFG2_URXIFG0_MASK)


/* ME1 Bit Fields */
#define SFR_ME1_UTXE0_MASK                          0x80u
#define SFR_ME1_UTXE0_SHIFT                         7
#define SFR_ME1_UTXE0(x)                            (((uint8)(((uint8)(x))<<SFR_ME1_UTXE0_SHIFT))&SFR_ME1_UTXE0_MASK)

#define SFR_ME1_URXE0_MASK                          0x40u
#define SFR_ME1_URXE0_SHIFT                         6
#define SFR_ME1_URXE0(x)                            (((uint8)(((uint8)(x))<<SFR_ME1_URXE0_SHIFT))&SFR_ME1_URXE0_MASK)


/* ME2 Bit Fields */
#define SFR_ME2_UTXE1_MASK                           0x20u
#define SFR_ME2_UTXE1_SHIFT                          5
#define SFR_ME2_UTXE1(x)                             (((uint8)(((uint8)(x))<<SFR_ME2_UTXE1_SHIFT))&SFR_ME2_UTXE1_MASK)

#define SFR_ME2_URXE1_MASK                           0x10u
#define SFR_ME2_URXE1_SHIFT                          4
#define SFR_ME2_URXE1(x)                             (((uint8)(((uint8)(x))<<SFR_ME2_URXE1_SHIFT))&SFR_ME2_URXE1_MASK)

#define SFR_ME2_UTXE0_MASK                           0x02u
#define SFR_ME2_UTXE0_SHIFT                          1
#define SFR_ME2_UTXE0(x)                             (((uint8)(((uint8)(x))<<SFR_ME2_UTXE0_SHIFT))&SFR_ME2_UTXE0_MASK)

#define SFR_ME2_URXE0_MASK                           0x01u
#define SFR_ME2_URXE0_SHIFT                          0
#define SFR_ME2_URXE0(x)                             (((uint8)(((uint8)(x))<<SFR_ME2_URXE0_SHIFT))&SFR_ME2_URXE0_MASK)


/**
 * @}
 */ /* end of group SFR_Register_Masks */
 

/* SFR - Peripheral instance base addresses */
/** Peripheral SFR base pointer */
#define SFR_BASE_PTR                             ((SFR_MemMapPtr)0x0000u)
/* ----------------------------------------------------------------------------
   -- SFR - Register accessor macros
   ---------------------------------------------------------------------------- */

/**
 * @addtogroup SFR_Register_Accessor_Macros SFR - Register accessor macros
 * @{
 */


/* SFR - Register instance definitions */
/* SFR */
#define SFR_IE1                                   (SFR_BASE_PTR->IE1)
#define SFR_IE2                                   (SFR_BASE_PTR->IE2)
#define SFR_IFG1                                  (SFR_BASE_PTR->IFG1)
#define SFR_IFG2                                  (SFR_BASE_PTR->IFG2)
#define SFR_ME1                                   (SFR_BASE_PTR->ME1)
#define SFR_ME2                                   (SFR_BASE_PTR->ME2)

/**
 * @}
 */ /* end of group SFR_Register_Accessor_Macros */


/**
 * @}
 */ /* end of group SFR_Peripheral */

/* ----------------------------------------------------------------------------
   -- Flash
   ---------------------------------------------------------------------------- */
/** Flash - Peripheral register structure */
typedef struct Flash_MemMap {
  uint16 FCTL1;
  uint16 FCTL2;
  uint16 FCTL3;
} volatile *Flash_MemMapPtr;

/* Flash - Peripheral instance base addresses */
/** Peripheral Flash base pointer */
#define Flash_BASE_PTR                             ((Flash_MemMapPtr)0x0128u)

/* Flash - Register instance definitions */
/* Flash */
#define Flash_FCTL1                                (Flash_BASE_PTR->FCTL1)
#define Flash_FCTL2                                (Flash_BASE_PTR->FCTL2)
#define Flash_FCTL3                                (Flash_BASE_PTR->FCTL3)






/************************************************************
* Interrupt Vectors (offset from 0xFFE0)
************************************************************/

#define PORT2_VECTOR        (1 * 2u)  /* 0xFFE2 Port 2 */
#define USART1TX_VECTOR     (2 * 2u)  /* 0xFFE4 USART 1 Transmit */
#define USART1RX_VECTOR     (3 * 2u)  /* 0xFFE6 USART 1 Receive */
#define PORT1_VECTOR        (4 * 2u)  /* 0xFFE8 Port 1 */
#define TIMERA1_VECTOR      (5 * 2u)  /* 0xFFEA Timer A CC1-2, TA */
#define TIMERA0_VECTOR      (6 * 2u)  /* 0xFFEC Timer A CC0 */
#define ADC12_VECTOR        (7 * 2u)  /* 0xFFEE ADC */
#define USART0TX_VECTOR     (8 * 2u)  /* 0xFFF0 USART 0 Transmit */
#define USART0RX_VECTOR     (9 * 2u)  /* 0xFFF2 USART 0 Receive */
#define WDT_VECTOR          (10 * 2u) /* 0xFFF4 Watchdog Timer */
#define COMPARATORA_VECTOR  (11 * 2u) /* 0xFFF6 Comparator A */
#define TIMERB1_VECTOR      (12 * 2u) /* 0xFFF8 Timer B CC1-6, TB */
#define TIMERB0_VECTOR      (13 * 2u) /* 0xFFFA Timer B CC0 */
#define NMI_VECTOR          (14 * 2u) /* 0xFFFC Non-maskable */
#define RESET_VECTOR        (15 * 2u) /* 0xFFFE Reset [Highest Priority] */

#define UART1TX_VECTOR      USART1TX_VECTOR
#define UART1RX_VECTOR      USART1RX_VECTOR
#define UART0TX_VECTOR      USART0TX_VECTOR
#define UART0RX_VECTOR      USART0RX_VECTOR
#define ADC_VECTOR          ADC12_VECTOR






#endif



