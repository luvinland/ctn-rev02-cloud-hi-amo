/******************************************************************************
 * @file     descriptors.c
 * @brief    M480 series USBD driver source file
 * @version  1.0.0
 * @date     August, 2017
 *
 * @note
 * Copyright (C) 2017 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
/*!<Includes */
#include <string.h>
#include "I94100.h"
#include "usbd_audio.h"
#include "audioclass.h"


#define WBVAL(x) (x&0xFF), ((x >>8) & 0xFF) 
#define B3VAL(x) (x&0xFF), ((x >>8) & 0xFF), ((x >>16) & 0xFF)  

const uint8_t gu8HidReportDesc[] = 
{
    0x05, 0x01, // USAGE_PAGE (Generic Desktop)
    0x09, 0x00, // USAGE (0)
    0xA1, 0x01, // COLLECTION (Application)
    0x15, 0x00, // LOGICAL_MINIMUM (0)
    0x25, 0xFF, // LOGICAL_MAXIMUM (255)
    0x19, 0x01, // USAGE_MINIMUM (1)
    0x29, 0x08, // USAGE_MAXIMUM (8)
    0x95, 0x40, // REPORT_COUNT (64)
    0x75, 0x08, // REPORT_SIZE (8)
    0x81, 0x02, // INPUT (Data,Var,Abs)
    0x19, 0x01, // USAGE_MINIMUM (1)
    0x29, 0x08, // USAGE_MAXIMUM (8)
    0x91, 0x02, // OUTPUT (Data,Var,Abs)
    0xC0        // END_COLLECTION
};

/*----------------------------------------------------------------------------*/
/*!<USB Device Descriptor */
const uint8_t gu8DeviceDescriptor[] = 
{
    LEN_DEVICE,        /* bLength */
    DESC_DEVICE,       /* bDescriptorType */
	  WBVAL(0x0200),     /* bcdUSB */
    0x00,              /* bDeviceClass */
    0x00,              /* bDeviceSubClass */
    0x00,              /* bDeviceProtocol */
    EP0_MAX_PKT_SIZE,  /* bMaxPacketSize0 */
	  WBVAL(USBD_VID),   /* idVendor */
	  WBVAL(USBD_PID),   /* idProduct */ 
    0x00, 0x00,        /* bcdDevice */
    0x01,              /* iManufacture */
    0x02,              /* iProduct */
    0x03,              /* iSerialNumber */
    0x01               /* bNumConfigurations */
};

#define HID_REPORT_DESCRIPTOR_SIZE  sizeof(gu8HidReportDesc) 

/*!<USB Configure Descriptor */
const uint8_t gu8ConfigDescriptor[] = 
{
    LEN_CONFIG,     					// bLength
    DESC_CONFIG,    					// bDescriptorType
	WBVAL(110),                 	    // wTotalLength
	
    0x02,           					// bNumInterfaces   //Audio Class x2: control, stream out to host
    0x01,           				    // bConfigurationValue
    0x00,           					// iConfiguration
	(USB_CONFIG_BUS_POWERED | USB_CONFIG_REMOTE_WAKEUP),				// bmAttributes 
	USB_CONFIG_POWER_MA(100),			// Max power    // 100mA

	
//----------  AudioControl Interface Descriptors START----------
    // Standard AC Interface Descriptor
    LEN_INTERFACE,                 // bLength
    DESC_INTERFACE,                // bDescriptorType
    0x00,                          // bInterfaceNumber  // A zero-based value identifying the index in the array of concurrent interfaces supported by this configuration
    0x00,                          // bAlternateSetting
    0x00,                          // bNumEndpoints  // Number of endpoints used by this interface (excluding endpoint 0)
    USB_DEVICE_CLASS_AUDIO,        // bInterfaceClass:AUDIO
    AUDIO_SUBCLASS_AUDIOCONTROL,   // bInterfaceSubClass:AUDIOCONTROL
    0x00,                          // bInterfaceProtocol
    0x00,                          // iInterface

    // Class Specific AC Interface Descriptor
    0x09,                          // bLength
    0x24,                          // bDescriptorType:CS_INTERFACE
    0x01,                          // bDescriptorSubType:HEADER
    0x00, 0x01,                    // bcdADC:1.0
    WBVAL(40),                     // wTotalLength
    0x01,                          // bInCollection // 1 AudioStreaming: stream out to host
    0x01,                          // baInterfaceNr(1) // index for the first AudioStreaming interface

	// Input Terminal Descriptor for Microphone
    0x0C,               	// bLength
    0x24,               	// bDescriptorType:CS_INTERFACE
    0x02,               	// bDescriptorSubType:INPUT_TERMINAL
    0x04,            		// bTerminalID
    0x01, 0x02,         	// wTerminalType: 0x0201 microphone
    0x00,               	// bAssocTerminal
    0x02,                   // bNrChannels
    REC_CH_CFG, 0x00,   	// wChannelConfig

    0x00,               	// iChannelNames
    0x00,               	// iTerminal
		
		
    // Feature Unit Audio Class Descriptor
	
    0x0A,               	// bLength
    0x24,               	// bDescriptorType
    0x06,               	// bDescriptorSubType: FEATURE_UNIT
    REC_FEATURE_UNITID, 	// bUnitID  // This value is used in all requests to address this Unit
    0x04,            		// bSourceID  // Connect to Input Terminal Descriptor for Microphone
    0x01,               	// bControlSize
    0x01,               	// bmaControls(0) (master control)
    0x02,               	// bmaControls(1)
    0x02,               	// bmaControls(2)

    0x00,               	// iFeature 
		
	// Output Terminal Descriptor for USB Streaming
    0x09,               	// bLength
    0x24,               	// bDescriptorType:CS_INTERFACE
    0x03,               	// bDescriptorSubType:OUTPUT_TERMINAL
    0x02,            		// bTerminalID
	WBVAL(0x0101),          // wTerminalType: 0x0101 usb streaming
    0x00,               	// bAssocTerminal
    REC_FEATURE_UNITID, 	// bSourceID
    0x00,               	// iTerminal 
//----------  AudioControl Interface Descriptors END----------     
		 
//---------- AudioStreaming Interface Descriptors START----------
    // Standard AS Interface Descriptor, interface 1, alternate 0
    LEN_INTERFACE,                  // bLength
    DESC_INTERFACE,                 // bDescriptorType
    0x01,                           // bInterfaceNumber
    0x00,                           // bAlternateSetting
    0x00,                           // bNumEndpoints
    USB_DEVICE_CLASS_AUDIO,         // bInterfaceClass:AUDIO
    AUDIO_SUBCLASS_AUDIOSTREAMING,  // bInterfaceSubClass:AUDIOSTREAMING
    0x00,                           // bInterfaceProtocol
    0x00,                           // iInterface

    // Standard AS Interface Descriptor, interface 1, alternate 1
    LEN_INTERFACE,                  // bLength
    DESC_INTERFACE,                 // bDescriptorType
    0x01,                           // bInterfaceNumber
    0x01,                           // bAlternateSetting
    0x01,                           // bNumEndpoints
    USB_DEVICE_CLASS_AUDIO,         // bInterfaceClass:AUDIO
    AUDIO_SUBCLASS_AUDIOSTREAMING,  // bInterfaceSubClass:AUDIOSTREAMING
    0x00,                           // bInterfaceProtocol
    0x00,                           // iInterface

    // Class-Specific AS Interface Descriptor
    0x07,                           // bLength
    0x24,                           // bDescriptorType:CS_INTERFACE
    0x01,                           // bDescriptorSubType:AS_GENERAL
    0x02,                     		// bTernimalLink
    0x01,                           // bDelay
	WBVAL(0x0001),                  // wFormatTag:0x0001 PCM

     // Class-Specific AS Format Type Descriptor(Type I)
    0x0B,                           // bLength
    0x24,                           // bDescriptorType:CS_INTERFACE
    0x02,                           // bDescriptorSubType:FORMAT_TYPE
    0x01,                           // bFormatType:FORMAT_TYPE_I
    0x02,                           // bNrChannels
    0x03,                           // bSubFrameSize : 24bit
    0x18,                           // bBitResolution	
    0x01,                           // bSamFreqType : 0 continuous; 1 discrete
	B3VAL(REC_RATE),                // Sample Frequency 
//---------- AudioStreaming Interface Descriptors END----------
		
//---------- AudioStreaming Endpoint Descriptors START----------
    // Standard AS Isochronous Audio Data Endpoint Descriptor
    0x09,                           // bLength
    0x05,                           // bDescriptorType
    EP2 | EP_INPUT,       			// bEndpointAddress
    0x0d,                           // bmAttributes
    WBVAL(EP2_MAX_PKT_SIZE),        // wMaxPacketSize
    0x01,                           // bInterval
    0x00,                           // bRefresh
    0x00,                           // bSynchAddress

    // Class-Specific AS Isochronous Audio Data Endpoint Descriptor
    0x07,                           // bLength
    0x25,                           // bDescriptorType:CS_ENDPOINT
    0x01,                           // bDescriptorSubType:EP_GENERAL
    0x00,                           // bmAttributes
    0x00,                           // bLockDelayUnits
    0x00, 0x00,                     // wLockDelay
//---------- AudioStreaming Endpoint Descriptors END----------	
};

/*!<USB Language String Descriptor */
const uint8_t gu8StringLang[4] = 
{
    4,              /* bLength */
    DESC_STRING,    /* bDescriptorType */
    0x09, 0x04
};

/*!<USB Vendor String Descriptor */
const uint8_t gu8VendorStringDesc[16] = 
{
    16,
    DESC_STRING,
    'N', 0, 'u', 0, 'v', 0, 'o', 0, 't', 0, 'o', 0, 'n', 0
};

/*!<USB Product String Descriptor */
const uint8_t gu8ProductStringDesc[] = {
    38,             /* bLength          */
    DESC_STRING,    /* bDescriptorType  */
    'N', 0, 
    'u', 0, 
    'v', 0, 
    'o', 0, 
    't', 0, 
    'o', 0, 
    'n', 0,
    ' ', 0,
    'U', 0, 
	'A', 0, 
	'C', 0,  
    ' ', 0,
	'D', 0, 
	'e', 0, 
	'v', 0, 
	'i', 0, 
	'c', 0, 
	'e', 0
};


uint8_t gu8StringSerial[26] = 
{
    26,             // bLength
    DESC_STRING,    // bDescriptorType
    'A', 0, '0', 0, '0', 0, '0', 0, '0', 0, '8', 0, '0', 0, '4', 0, '0', 0, '1', 0, '1', 0, '5', 0

};

/*!<USB BOS Descriptor */
uint8_t gu8BOSDescriptor[] = 
{
    LEN_BOS,        /* bLength */
    DESC_BOS,       /* bDescriptorType */
    /* wTotalLength */
    0x0C & 0x00FF,
    (0x0C & 0xFF00) >> 8,
    0x01,           /* bNumDeviceCaps */

    /* Device Capability */
    0x7,            /* bLength */
    DESC_CAPABILITY,/* bDescriptorType */
    CAP_USB20_EXT,  /* bDevCapabilityType */
    0x02, 0x00, 0x00, 0x00  /* bmAttributes */
};


const uint8_t *gpu8UsbString[4] = {
    gu8StringLang,
    gu8VendorStringDesc,
    gu8ProductStringDesc,
    gu8StringSerial
};

const uint8_t *gu8UsbHidReport[6] = {
    NULL,
    NULL,
	gu8HidReportDesc,
	NULL,
    NULL,
	NULL 
};

const uint32_t gu32UsbHidReportLen[6] = {
    0,
    0,
    sizeof(gu8HidReportDesc),
    0,
    0,
    0
};

const uint32_t gu32ConfigHidDescIdx[4] = {
    0,
    0,
    0,
    (sizeof(gu8ConfigDescriptor) - LEN_ENDPOINT - LEN_HID)
};


const S_USBD_INFO_T gsInfo = 
{
    (uint8_t *)gu8DeviceDescriptor,
    (uint8_t *)gu8ConfigDescriptor,
    (const uint8_t **)gpu8UsbString,
    (const uint8_t **)gu8UsbHidReport,
    (uint8_t *)gu8BOSDescriptor,
    (uint32_t *)gu32UsbHidReportLen,
    (uint32_t *)gu32ConfigHidDescIdx
};

