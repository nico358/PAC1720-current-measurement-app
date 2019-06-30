/*
 * adapter_PAC1720.h
 *
 */

/**
* @file	adapter_PAC1720.h
* @brief
*/
#pragma once

/** Includes **/
#include "lib/PAC1720_driver/PAC1720_driver.h"

/*! CPP guard */
#ifdef __cplusplus
extern "C"
{
#endif

/********************************************* Defines ************************************/
/** Defines the data direction (reading from I2C device) in i2c_start(),i2c_rep_start() */
#ifndef I2C_READ
#define I2C_READ    1
#endif
/** Defines the data direction (writing to I2C device) in i2c_start(),i2c_rep_start() */
#ifndef I2C_WRITE
#define I2C_WRITE   0
#endif

/** Defines the number of bits in address shift */
static const uint8_t BUS_ADDRESS_SHIFT   = 1;

/** Define max attempts to search for active sensors */
static const uint8_t max_search_attempts = 10;


/******************************** Platform dependendet implementation **********************/
/** Field- Bus communication struct interface define */
struct FIELD_BUS_INTERFACE
{
    void            (*init)     (void);
    void            (*stop)     (void);
    unsigned char   (*start)    (unsigned char address);
    unsigned char   (*repStart) (unsigned char address);
    void            (*startWait)(unsigned char address);
    unsigned char   (*write)    (unsigned char data);
    unsigned char   (*readAck)  (void);
    unsigned char   (*readNak)  (void);
};

/** Delay functionpointer define */
typedef void (*delay_function_ptr) (uint32_t period);


/******************************** Instances ***********************************************/
/** Sensor struct instances, i2c instance and assigned delay function  */
extern struct FIELD_BUS_INTERFACE   external_fieldbus_interface;
extern delay_function_ptr           external_delay_function;
extern struct PAC1720_device        dev_USB_MON;
extern struct PAC1720_device        dev_FPGA_VCC;
extern struct PAC1720_device        dev_WIREL_MCU;


/******************************** Function prototypes *************************************/

/*!
 * @fn 
 * @brief 
 *
 *
 * @return 
 */
int8_t adapter_init_PAC1720(struct PAC1720_device *dev_ptr, struct FIELD_BUS_INTERFACE *fieldbus_interface, delay_function_ptr delay_fptr);

// int8_t get_measurements(struct PAC1720_device *dev_ptr);

/* function prototypes */
/*!
 * @fn
 * @brief
 *
 * @return 
 */
uint8_t adapter_find_sensors(uint8_t *addresses, struct FIELD_BUS_INTERFACE *fieldbus_interface, delay_function_ptr delay_fptr);

/*!
 * @fn 
 * @brief 
 *
 *
 * @return 
 */
const void* get_ADAPTER_TEST_FPTR_FIELD(void);


#ifdef __cplusplus
}
#endif /* End of CPP guard */
/** @}*/