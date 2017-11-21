## Read the Objectives

In this lab, you will learn the basics of Digital GPIO.

By the end of this module, you should be able to use the MRAA library to do the following:

* Write a program using the Arduino APIs to read the value of a rotary angle sensor
* Write a program using the MRAA APIs to read the value of a rotary angle sensor

## Analog GPIO: Rotary Angle Sensor Project

### Hardware Setup

Sensor | Pin
--- | ---
Rotary Angle Sensor | A2

:arrow_forward: Place the Rotary Angle Sensor on pin A2

### Software Setup - Arduino APIs for Rotary Angle Sensor

Programs in the Arduino Create environment can be build using the Arduino APIs or MRAA APIs.  In fact, the Arduino Create development team has implemented the Arduino APIs on top of the MRAA APIs. So when compiling a program written using the Arduino APIs on an Intel platform, you are actually using both sets of APIs.

```c
// A 512 offset is required for sub-platforms.
// 515 corresponds to analog pin 2 or A2.
#define SUBPLATFORM_OFFSET 512
#define PIN SUBPLATFORM_OFFSET + 2

// the setup function runs once when you start your sketch
void setup() {
  //add the Grove Pi+ sub-platform
  mraa_add_subplatform(MRAA_GROVEPI, "0");
  
  // Initialize the serial monitor
  DebugSerial.begin(115200);
}

// the loop function runs over and over again forever
void loop() {
  int sensorValue = analogRead(PIN);
  DebugSerial.println(sensorValue);
  delay(100);    // wait for a tenth of a second
}
```

### Build and Run your Analog GPIO Read Program

![](./images/action.png) Build and run your program

You should be able to go the serial monitor and view the values sampled from the rotary angle sensor.

![](./images/Grove-potential.png)

### MRAA Version of Rotary Angle Sensor Reader

```c
#include <unistd.h>
#include <signal.h>

#include "mraa/aio.h"

#define SUBPLATFORM_OFFSET 512
#define PIN 2 + SUBPLATFORM_OFFSET

int running = 0;

void
sig_handler(int signo)
{
    if (signo == SIGINT) {
        printf("closing down nicely\n");
        running = -1;
    }
}

int
main()
{
    mraa_add_subplatform(MRAA_GROVEPI, "0");
    mraa_aio_context adc_a0;
    uint16_t adc_value = 0;
    float adc_value_float = 0.0;
    mraa_result_t r = MRAA_SUCCESS;

    adc_a0 = mraa_aio_init(PIN);
    if (adc_a0 == NULL) {
        return 1;
    }

    signal(SIGINT, sig_handler);

    while (running == 0) {
        adc_value = mraa_aio_read(adc_a0);
        adc_value_float = mraa_aio_read_float(adc_a0);
        fprintf(
          stdout, 
          "A0 = %X - %d\n", 
          adc_value, 
          adc_value
        );
    }

    r = mraa_aio_close(adc_a0);
    if (r != MRAA_SUCCESS) {
        mraa_result_print(r);
    }

    return r;
}

```

## Sensors and Actuators APIs - UPM API Doxygen Reference

*   [C++ Sensor/Actuator API libmraa (v1.5.1) and UPM (v1.0.2)](https://iotdk.intel.com/docs/master/upm/)
*   [Java Sensor/Actuator API libmraa (v1.5.1) and UPM (v1.0.2)](https://iotdk.intel.com/docs/master/upm/java/)
*   [Python Sensor/Actuator API libmraa (v1.5.1) and UPM (v1.0.2)](https://iotdk.intel.com/docs/master/upm/python/)
*   [NodeJS Sensor/Actuator API libmraa (v1.5.1) and UPM (v1.0.2)](https://iotdk.intel.com/docs/master/upm/node/)

### Grove Temperature Sensor

*   [Seeed Studio Wiki: Grove Temperature Sensor](http://www.seeedstudio.com/wiki/Grove_-_Temperature_Sensor_V1.2)
*   [UPM API - GroveTemp](http://iotdk.intel.com/docs/master/upm/node/classes/grovetemp.html#methods)
*   [UPM C++ example: Grove Temperature Sensor](https://github.com/intel-iot-devkit/upm/blob/master/examples/c%2B%2B/grovetemp.cxx)
*   [UPM JavaScript example: Grove Temperature Sensor](https://github.com/intel-iot-devkit/upm/blob/master/examples/javascript/grovetemp.js)

### Grove LCD RGB Backlight

*   [Seeed Studio Wiki: LCD RGB Backlight](http://www.seeedstudio.com/wiki/Grove_-_LCD_RGB_Backlight)
*   [UPM API - i2clcd](http://iotdk.intel.com/docs/master/upm/node/classes/lcd.html#methods)
*   [UPM API Doxygen - Jhd1313m1](http://iotdk.intel.com/docs/master/upm/node/classes/jhd1313m1.html#methods)
*   [UPM API - Jhd1313m1](https://github.com/intel-iot-devkit/upm/blob/master/examples/c%2B%2B/jhd1313m1-lcd.cxx)
*   [C++ example: RGB LCD](https://github.com/intel-iot-devkit/upm/blob/master/examples/javascript/jhd1313m1-lcd.js)

### Grove Button

*   [UPM JavaScript example: Grove Button](https://github.com/intel-iot-devkit/upm/blob/master/examples/javascript/grovebutton.js)
*   [Seeed Studio Wiki: Grove Button](http://www.seeedstudio.com/wiki/Grove_-_Button)
