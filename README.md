# CTN (Cloud Type Nuvoton) Rev02
- Embedded hi-amo and Cloud amazon alexa.
<br><br>
## Overview
- Nuvoton I94124 project for Embedded VR with Espressif's amazon alexa app based on Nuvoton I94100 Series BSP_CMSIS_V3.05.003 SDK.
<br><br>
## Embedded voice command set & Amazon Alexa & Blynk (for IoT service)
<a href="https://drive.google.com/file/d/1gKAe7uNhStRsHU9hVC3noCOwbrFDVajo/view?usp=sharing">![Embedded voice command set & Amazon Alexa & Blynk (for IoT service)](https://github.com/luvinland/ctn-rev02-cloud-hi-amo/assets/26864945/f7a7b4fd-3481-424e-afdd-15922706ffb5)</a>
- <a href="https://developer.amazon.com/en-US/alexa/alexa-skills-kit">ASK (Alexa Skills Kit)</a>
<br><br>
## Block diagram
![Block Diagram](https://user-images.githubusercontent.com/26864945/69035559-4bcdc400-0a27-11ea-9897-cf64581c2f14.png)
<br><br>
## Hardware
* Preprocessing MCU with DSP SoC : [Nuvoton I94124](http://www.nuvoton.com/hq/products/application-specific-socs/arm-based-audio/?__locale=en)
* WiFi & BT SoC : [Espressif ESP32](https://www.espressif.com/en/products/hardware/esp32/overview)
<br><br>
## Revision
* **[Rev02: 2020-03-13](https://github.com/luvinland/ctn-rev02-cloud-hi-amo)**
  * Apply esp-va-sdk [v1.2](https://github.com/espressif/esp-va-sdk/releases/tag/1.2).
  * Apply BSP_CMSIS_V3.05.003 SDK.
  * Run BLYNK Application.
  * Add Factory reset function.
