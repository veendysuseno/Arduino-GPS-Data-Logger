# Arduino GPS Data Logger

## Description

This project uses an Arduino to interface with a GPS module to collect and display GPS data including latitude, longitude, altitude, speed, and time. The code reads data from the GPS module, processes it, and outputs the information to the serial monitor.

## Prerequisites

- **Arduino Board**: Any Arduino compatible board (e.g., Arduino Uno, Mega).
- **GPS Module**: Compatible GPS module (e.g., NEO-6M).
- **Libraries**:
  - **TinyGPS++**: For parsing GPS data.
  - **TimeLib**: For handling time operations.
- **Hardware Setup**: Connect the GPS module to the Arduino using the appropriate serial ports.

## Libraries Installation

1. **TinyGPS++**:

   - Open Arduino IDE.
   - Go to `Sketch` > `Include Library` > `Manage Libraries...`.
   - Search for `TinyGPS++` and install it.

2. **TimeLib**:
   - Follow the same steps as above and install the `TimeLib` library.

## Code Overview

1. **Include Libraries**:

   - The code includes the `TinyGPS++` and `TimeLib` libraries for GPS data parsing and time management.

2. **Define Serial Port**:

   - Uncomment `#include <SoftwareSerial.h>` and `SoftwareSerial serialGps(10, 11);` if using software serial. Otherwise, use hardware serial defined as `Serial1`.

3. **Global Variables**:

   - Variables to store GPS data including latitude, longitude, altitude, speed, and time.

4. **Setup Function**:

   - Initializes serial communication with the GPS module and the serial monitor.

5. **Loop Function**:

   - Continuously checks for GPS data, parses it, and updates the variables.
   - Displays the GPS data on the serial monitor including satellite count, latitude, longitude, altitude, speed, and adjusted time with an offset.

6. **Time Adjustment**:
   - Adds a time offset to convert UTC time to local time.

## Hardware Setup

1. **GPS Module Connection**:
   - Connect the GPS module's TX pin to the RX pin of the Arduino (e.g., RX1 for hardware serial).
   - Connect the GPS module's RX pin to the TX pin of the Arduino (e.g., TX1 for hardware serial).
   - Connect the GPS module's power and ground pins to the Arduino's power and ground.

## How to Use

1. **Upload the Code**:

   - Connect your Arduino to your computer.
   - Open the Arduino IDE, paste the provided code, and upload it to the Arduino.

2. **Open Serial Monitor**:
   - Open the Serial Monitor in the Arduino IDE (set baud rate to 9600).
   - You will see the GPS data being displayed including satellite count, latitude, longitude, altitude, speed, and local time.

## Notes

- Ensure that the GPS module has a clear view of the sky to receive satellite signals.
- Adjust the `time_offset` variable to match your local timezone offset from UTC.

## Author

- [Your Name] - [Your Email]

## License

- This project is licensed under [License Name] - see [LICENSE](LICENSE) for details.
