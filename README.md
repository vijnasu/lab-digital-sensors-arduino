## Read the Objectives

<<<<<<< HEAD
To learn how to build stand alone IoT devices with UP Squared board*. Learn to use sensors and actuators to gather and respond to data. The devices built during this lab will be extended in later labs to send their data to the Intel® IoT Gateway and to the cloud

By the end of this module, you should be able to:

*   Connect Grove* IoT Commercial Developer Kit sensors and actuators to your Up Squared.
=======
To learn how to build stand alone IoT devices with Arduino 101*. Learn to use sensors and actuators to gather and respond to data. The devices built during this lab will be extended in later labs to send their data to the Intel® IoT Gateway and to the cloud

By the end of this module, you should be able to:

*   Connect Grove* IoT Commercial Developer Kit sensors and actuators to your Arduino 101*.
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9
*   Use the C UPM libraries to control actuators and read data from sensors.

## Deploy Your First App to the Intel® IoT Gateway

### Create a LED blink project
<<<<<<< HEAD
Go to (create-intel.arduino.cc) and log in to your account or create a new account.
![](./images/arduino-create-main.png)

Click on My Devices to set up the UP Squared board.
![](./images/arduino-create-new-device.png)

Click on Set up a generic Intel® IoT Platform.
![](./images/arduino-create-set-up-IoT.png)
:Note the Set up UP2 Grove IoT Development Kit button is still in Development and is not reliable to connect to the Up Squared board.

 Follow the instructions to set up the UP Squared board and click My device is ready.
 ![](./images/arduino-create-device-ready.png)

 The UP Squared was preloaded with UBlinux. Click on option 1 I have already installed the an OS on my device.
 ![](./images/arduino-create-device-os.png)

Click on option A I know my Intel IoT Platform IP ADDRESS.
![](./images/arduino-create-device-ip.png)

Enter the IP ADDRESS that is shown on the LCD screen and click NEXT.
![](./images/arduino-create-device-ip-addr.png)

Enter in the username "nuc-user" and password "root" for the UP Squared board and click DONE.
![](./images/arduino-create-device-passwd.png)

Connecting to device.
![](./images/arduino-create-device-connecting.png)

Enter a name for your device and click SAVE.
![](./images/arduino-create-device-name.png)

You have successfully connected the UP Squared board to Arduino-Create. Click on GO TO MY DEVICES.
![](./images/arduino-create-device-done.png)

Click on the squares in the upper left corner.
![](./images/arduino-create-device-status.png)

Click on Arduino Web Editor.
![](./images/arduino-create-editor.png)

Set up the LED for the Grove Shield.
Find the LED module and plug in an LED. Make sure that the cathode is plugged into the negative (-) socket. You can tell the cathode of an LED by the flat side of the led case, or by the larger “anvil” inside the LED. Refer to the diagram below:
![](./images/Grove-LED.jpg)

Once the LED is in the socket plug in the module into the D4 socket on the sensor shield:

 Click on drop down menu on the sketch_monthDaya and select Rename Sketch.*
![](./images/arduino-create-editor-sketch.png)

 Rename the sketch to **blinky-LED** and click OK. Now we will write the LED blink program to it.
![](./images/arduino-create-editor-sketch-rename.png)

### Write LED blink program
Delete the void setup() and void loop() functions in the sketch to create a blank sketch. Select the up2 via cloud board under -- Select Board or Port --
![](./images/arduino-create-editor-empty.png)

Update **blinky-LED** with following changes
=======

In your home directory (/home/{user}) on your Intel® IoT Gateway create a **labs** directory. We will put all our labs program here.

Under lab directory create another directory and name it **sensors**

Similarly create **LEDBlink** directory under sensors and finally create file **blinky-LED.c** in it. We will write the LED blink program to it

### Write LED blink program

Update **blinky-LED.c** with following changes
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9

1.  Include the following C headers in your program

    ```c
    #include <stdio.h>
    #include <unistd.h>
    #include <errno.h>
    #include <signal.h>
    #include <stdlib.h>

    #include "mraa.h"
    ```

<<<<<<< HEAD
2.  Create the default LED GPIO pin macro. Here the pin value is 13\.

    ``` c
    #define DEFAULT_IOPIN 13 //LED GPIO pin 13
=======
2.  Create the default LED GPIO pin macro. Here the pin value is 13 and offset value of 512\. This offset is required since we use Firmata to connect Arduino 101* with Intel® IoT Gateway which needs this conversion for all the I/O pins

    ``` c
    #define DEFAULT_IOPIN 525 //LED GPIO pin 13 + offset of 512
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9
    ```

3.  Write the signal handler function to handle termination of the program which will continuously toggle the LED

    ```c
    void sig_handler(int signo)
    {
        if (signo == SIGINT) {
            printf("closing IO%d nicely\n", iopin);
            running = -1;
        }
    }
    ```

4.  In the main function of the program first initialize mraa then initialize the gpio pin and finally set the direction for the pin (MRAA_GPIO_OUT in our case)

5.  Finally write a while loop that will continuously write a 1 & 0 to the LED at periodic intervals for it to blink

6.  The final code should look like the below one:

    ``` c
    #include <stdio.h>
    #include <unistd.h>
    #include <errno.h>
    #include <signal.h>
    #include <stdlib.h>

    #include "mraa.h"

<<<<<<< HEAD
    #define DEFAULT_IOPIN 13
=======
    #define DEFAULT_IOPIN 525
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9

    int running = 0;
    static int iopin;

    void
    sig_handler(int signo)
    {
        if (signo == SIGINT) {
            printf("closing IO%d nicely\n", iopin);
            running = -1;
        }
    }

<<<<<<< HEAD
    int main(void)
=======
    int main(int argc, char** argv)
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9
    {
        mraa_result_t r = MRAA_SUCCESS;
        iopin = DEFAULT_IOPIN;

<<<<<<< HEAD
=======
        if (argc < 2) {
            printf("Provide an int arg if you want to flash on something other than %d\n", DEFAULT_IOPIN);
        } else {
            iopin = strtol(argv[1], NULL, 10);
        }

>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9
        mraa_init();
        fprintf(stdout, "MRAA Version: %s\nStarting Blinking on IO%d\n", mraa_get_version(), iopin);

        mraa_gpio_context gpio;
        gpio = mraa_gpio_init(iopin);
        if (gpio == NULL) {
            fprintf(stderr, "Are you sure that pin%d you requested is valid on your platform?", iopin);
            exit(1);
        }
        printf("Initialised pin%d\n", iopin);

        // set direction to OUT
        r = mraa_gpio_dir(gpio, MRAA_GPIO_OUT);
        if (r != MRAA_SUCCESS) {
            mraa_result_print(r);
        }

        signal(SIGINT, sig_handler);

        while (running == 0) {
            r = mraa_gpio_write(gpio, 0);
            if (r != MRAA_SUCCESS) {
                mraa_result_print(r);
            } else {
                printf("off\n");
            }

            sleep(1);

            r = mraa_gpio_write(gpio, 1);
            if (r != MRAA_SUCCESS) {
                mraa_result_print(r);
            } else {
                printf("on\n");
            }

            sleep(1);
        }

        r = mraa_gpio_close(gpio);
        if (r != MRAA_SUCCESS) {
            mraa_result_print(r);
        }

        return r;
    }
    ```
<<<<<<< HEAD
=======

>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9
### Disable Node-Red service

** Please be sure to disable the Node-Red service running on your Gateway!**

*   The IP address that you see on the LCD screen is a Node-Red flow running on boot, since Node-Red uses the device resources through ttyACM0 node it is required to stop it before we run our C programs

*   Open a ssh terminal to your Gateway and give following command:

    `sudo systemctl stop node-red-experience`

*   Check that service has stopped

    `sudo systemctl status node-red-experience`

## Build and Run your LED blink program
<<<<<<< HEAD
Click the check mark to compile/verify the program.
![](./images/arduino-create-editor-verify.png)

Click the arrow to upload the sketch to the UP Squared board
![](./images/arduino-create-editor-upload.png)

You should now see the LED blinking once a second. If the LED doesn’t appear to be blinking or is blinking very dimly turn the potentiometer counter-clockwise:

![](./images/Grove-potential.png)

You should see successful upload at the bottom of the screen.
![](./images/arduino-create-editor-blink-success.png)

Click on the Monitor button to the left.
![](./images/arduino-create-editor-blink-monitor.png)
You should see on/off being sent back from the UP Squared

## Setup the temperature sensor and LCD screen

### Plug into the Grove shield, temperature sensor
![temperature sensor](./images/temperature-sensors.jpg)

 Write code in C and measure temperature in Celsius using upm library, convert it to Fahrenheit, then display it on the LCD.

Connect **Grove Temperature Sensor** to analog pin **A0** of the Grove Base Shield.

## Create a temperature sensor project
Click on the NEW SKETCH button
![](./images/arduino-create-editor-upload.png)

Rename the sketch to temperature and delete the void setup() and void loop() functions like before to create and empty sketch.
 ![](./images/arduino-create-editor-temp-blank.png)

## Write the Code to Read the Temperature Sensor.

Update <span class="icon file">temperature</span> to read the temperature sensor on program start up and log it to the console.
=======

![](./images/image_arduino_led.png)

Open a SSH terminal to your Intel® IoT Gateway and go to your **LEDBlink** folder. Type the following command to build your C application

`gcc blinky-LED.c -o blinky-LED -lmraa`

To run the program give following command:

`./blinky-LED`

This should execute your program and you should see LED blinking on your Arduino 101* board.The LED is located near the center of the board as shown in the figure

## Setup the temperature sensor and LCD screen

### Plug in the Grove shield, temperature sensor and the LCD

![temperature sensor](./images/temperature-sensors.jpg)

Connect the Temperature sensor (Analog) and LCD display (I<sup>2</sup>C) to your Arduino 101*. Write code in C and measure temperature in Celsius using upm library, convert it to Fahrenheit, then display it on the LCD.

1.  Install the Grove Base Shield onto the Arduino 101* Arduino expansion board.

2.  Connect **Grove Temperature Sensor** to analog pin **A0** of the Grove Base Shield.

3.  Connect **Grove LCD** display to one of the **I<sup>2</sup>C** pins.

## Create a temperature sensor project

*   On your Intel® IoT Gateway under **labs/sensors** folder create another folder **temperature-sensor**

*   In the labs/sensors/temperature-sensor folder create a **temperature.c** file

## Write the Code to Read the Temperature Sensor.

Update <span class="icon file">temperature.c</span> to read the temperature sensor on program start up and log it to the console.
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9

1.  Include the following headers in your C program

  	```c
	#include <stdio.h>
	#include <stdlib.h>

    #include "jhd1313m1.h"
    #include "temperature.h"
    #include "upm.h"
    #include "upm_utilities.h"
    #include "signal.h"
    #include "string.h"
    ```

2.  Write the signal handler function to handle termination of the program which will continuously read and display temperature

	```c
    void sig_handler(int signo)
    {
        if (signo == SIGINT) {
            printf("closing IO%d nicely\n", iopin);
            running = -1;
        }
    }
	```

<<<<<<< HEAD
3.  Make sure to initialize LCD and Temperature modules using the right library calls. I2C it is bus 0 and for temperature sensor it is pin A0.

    ```c
    jhd1313m1_context lcd = jhd1313m1_init(0, 0x3e, 0x62);
    temperature_context temp = temperature_init(0);
=======
3.  Make sure to initialize LCD and Temperature modules using the right library calls. Here 512 is the FIRMATA offset which means for I2C it is bus 0 and for temperature sensor it is pin A0.

    ```c
    jhd1313m1_context lcd = jhd1313m1_init(512, 0x3e, 0x62);
    temperature_context temp = temperature_init(512);
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9
    ```

4.  Finally create a while loop that will continuously read the temperature value from sensor in celsius, convert it to fahrenheit and then display this on LCD by setting the cursor position and then writing the string. Also you can continuously change the LCD display color as done in the code.


5.  The final code should look like this:

    ``` c
    #include <stdio.h>
    #include <stdlib.h>

    #include "jhd1313m1.h"
    #include "temperature.h"
    #include "upm.h"
    #include "upm_utilities.h"
    #include "signal.h"
    #include "string.h"

    bool shouldRun = true;

    void sig_handler(int signo)
    {
        if (signo == SIGINT)
            shouldRun = false;
    }

<<<<<<< HEAD
    int main()
=======
    int main(int argc, char **argv)
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9
    {
        signal(SIGINT, sig_handler);
        int fahrenheit;
        float celsius;
        //! [Interesting]
        // initialize a JHD1313m1 on I2C bus 0, LCD address 0x3e, RGB
        // address 0x62
<<<<<<< HEAD
        jhd1313m1_context lcd = jhd1313m1_init(0, 0x3e, 0x62);
        temperature_context temp = temperature_init(0);
=======
        jhd1313m1_context lcd = jhd1313m1_init(512, 0x3e, 0x62);
        temperature_context temp = temperature_init(512);
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9

        if (!lcd)
        {
            printf("jhd1313m1_i2c_init() failed\n");
            return 1;
        }

        int ndx = 0;
        char str1[20];
        char str2[20];
        uint8_t rgb[7][3] = {
            {0xd1, 0x00, 0x00},
            {0xff, 0x66, 0x22},
            {0xff, 0xda, 0x21},
            {0x33, 0xdd, 0x00},
            {0x11, 0x33, 0xcc},
            {0x22, 0x00, 0x66},
            {0x33, 0x00, 0x44}};


        while (shouldRun)
        {
            temperature_get_value(temp, &celsius);
            celsius = celsius * 0.6; //Arduino factor for 5V
            fahrenheit = (int) (celsius * 9.0/5.0 + 32.0);
            printf("%d degrees Celsius, or %d degrees Fahrenheit\n",
                    (int)celsius, fahrenheit);

            snprintf(str1, sizeof(str1), "Temperature: ");
            snprintf(str2, sizeof(str2), "F: %d & C: %d", fahrenheit, (int)celsius);
            // Alternate rows on the LCD
            jhd1313m1_set_cursor(lcd, 0, 0);
            jhd1313m1_write(lcd, str1, strlen(str1));
            jhd1313m1_set_cursor(lcd, 1, 0);
            jhd1313m1_write(lcd, str2, strlen(str2));
            // Change the color
            uint8_t r = rgb[ndx%7][0];
            uint8_t g = rgb[ndx%7][1];
            uint8_t b = rgb[ndx%7][2];
            ndx++;
            jhd1313m1_set_color(lcd, r, g, b);

            upm_delay(1);
        }
        temperature_close(temp);

        return 0;
	}
    ```
<<<<<<< HEAD
## Build and Upload your program
Click on the arrow again to upload the sketch.
![](./images/arduino-create-editor-upload-temp.png)

You should see the temperature value on your LCD in both celsius and Fahrenheit.
=======
## Build and Run your program

Make sure your changes to <span class="icon file">temperature.c</span> have been saved and now from a ssh terminal go to the temperature-sensor folder and type following to build your C program:

`gcc temperature.c -o lcd_temp_sensor -I/usr/include/upm -lupmc-temperature -lupmc-utilities -lmraa -lm -lupm-jhd1313m1 -lupmc-jhd1313m1 -lupm-lcm1602 -lupmc-lcm1602`

Run your program with following command:

`./lcd_temp_sensor`


You should see the temperature value on your LCD in both celsius and Fahrenheit. To stop the program simply do a Ctrl+C
>>>>>>> 0ef6ee650e1b2d55fe8dbbd1ed4f78dd55e772d9

There are a number of additional examples available for reference as [how-to-code-samples](https://github.com/intel-iot-devkit/how-to-code-samples) on git hub

## Additional resources

Information, community forums, articles, tutorials and more can be found at the [Intel Developer Zone](https://software.intel.com/iot).

For reference code for any sensor/actuator from the Grove* IoT Commercial Developer Kit, visit [https://software.intel.com/en-us/iot/hardware/sensors](https://software.intel.com/en-us/iot/hardware/sensors)

#### Sensors and Actuators APIs - UPM API Doxygen Reference

*   [C++ Sensor/Actuator API libmraa (v1.5.1) and UPM (v1.0.2)](https://iotdk.intel.com/docs/master/upm/)
*   [Java Sensor/Actuator API libmraa (v1.5.1) and UPM (v1.0.2)](https://iotdk.intel.com/docs/master/upm/java/)
*   [Python Sensor/Actuator API libmraa (v1.5.1) and UPM (v1.0.2)](https://iotdk.intel.com/docs/master/upm/python/)
*   [NodeJS Sensor/Actuator API libmraa (v1.5.1) and UPM (v1.0.2)](https://iotdk.intel.com/docs/master/upm/node/)

#### Grove Temperature Sensor

*   [Seeed Studio Wiki: Grove Temperature Sensor](http://www.seeedstudio.com/wiki/Grove_-_Temperature_Sensor_V1.2)
*   [UPM API - GroveTemp](http://iotdk.intel.com/docs/master/upm/node/classes/grovetemp.html#methods)
*   [UPM C++ example: Grove Temperature Sensor](https://github.com/intel-iot-devkit/upm/blob/master/examples/c%2B%2B/grovetemp.cxx)
*   [UPM JavaScript example: Grove Temperature Sensor](https://github.com/intel-iot-devkit/upm/blob/master/examples/javascript/grovetemp.js)

#### Grove LCD RGB Backlight

*   [Seeed Studio Wiki: LCD RGB Backlight](http://www.seeedstudio.com/wiki/Grove_-_LCD_RGB_Backlight)
*   [UPM API - i2clcd](http://iotdk.intel.com/docs/master/upm/node/classes/lcd.html#methods)
*   [UPM API Doxygen - Jhd1313m1](http://iotdk.intel.com/docs/master/upm/node/classes/jhd1313m1.html#methods)
*   [UPM API - Jhd1313m1](https://github.com/intel-iot-devkit/upm/blob/master/examples/c%2B%2B/jhd1313m1-lcd.cxx)
*   [C++ example: RGB LCD](https://github.com/intel-iot-devkit/upm/blob/master/examples/javascript/jhd1313m1-lcd.js)

#### Grove Button

*   [UPM JavaScript example: Grove Button](https://github.com/intel-iot-devkit/upm/blob/master/examples/javascript/grovebutton.js)
*   [Seeed Studio Wiki: Grove Button](http://www.seeedstudio.com/wiki/Grove_-_Button)
