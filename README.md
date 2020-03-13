# CTN (Cloud Type Nuvoton) Rev02
Embedded hi-amo and Cloud amazon alexa.

## Overview
Nuvoton I94124 project for Embedded VR with Espressif's amazon alexa app based on Nuvoton I94100 Series BSP_CMSIS_V3.05.003 SDK.


## Block diagram
![Block Diagram](https://user-images.githubusercontent.com/26864945/69035559-4bcdc400-0a27-11ea-9897-cf64581c2f14.png)


## Hardware
* Preprocessing MCU with DSP SoC : [Nuvoton I94124](http://www.nuvoton.com/hq/products/application-specific-socs/arm-based-audio/?__locale=en)
* WiFi & BT SoC : [Espressif ESP32](https://www.espressif.com/en/products/hardware/esp32/overview)


## Revision
* **[Rev02: 2020-03-13](https://github.com/luvinland/ctn-rev02-cloud-hi-amo)**
  * Apply esp-va-sdk [v1.2](https://github.com/espressif/esp-va-sdk/releases/tag/1.2).
  * Apply BSP_CMSIS_V3.05.003 SDK.
  * Run BLYNK Application.
  * Add Factory reset function.
