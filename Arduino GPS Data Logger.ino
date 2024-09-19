// GPS Neo 6m Menampilkan Banyak Data
#include <TinyGPS++.h>
#include <TimeLib.h>

//Jika Menggunakan Software Serial
//#include <SoftwareSerial.h>
//SoftwareSerial serialGps(10, 11);

//Jika Menggunakan Hardware Serial
#define serialGps Serial1

TinyGPSPlus gps;
#define time_offset 25200 //tentukan jam offset 25200 detik (7 jam) ==> UTC +7
byte last_second, Second, Minute, Hour, Day, Month;
int Year, DayOfTheWeek, SatellitesValue;
float Latitude, Longitude, Altitude, Speed;

void setup(void) {
  serialGps.begin(9600);
  Serial.begin(9600);
}

void loop() {

  while (serialGps.available() > 0) { //KETIKA GPS TERSAMBUNG DENGAN ARDUINO....

    if (gps.encode(serialGps.read())) { //KETIKA GPS MENDAPATKAN DATA / SIGNAL...

      //Dapatkan Data Satellite.......................................
      if (gps.satellites.isValid()) {
        SatellitesValue = gps.satellites.value();
      }

      //Dapatkan Data Lokasi (Latitude & Longitude)...................
      if (gps.location.isValid()) {
        Latitude = gps.location.lat();
        Longitude = gps.location.lng();
        Altitude = gps.altitude.meters();
      }

      //Dapatkan Data Altitude........................................
      if (gps.altitude.isValid()) {
        Altitude = gps.altitude.meters();
      }

      //Dapatkan Data Kecepatan........................................
      if (gps.speed.isValid()) {
        Speed = gps.speed.kmph();
      }

      //Dapatkan Data Waktu...........................................
      if (gps.time.isValid()) {
        Minute = gps.time.minute();
        Second = gps.time.second();
        Hour   = gps.time.hour();
      }

      //Dapatkan Data Tanggal.........................................
      if (gps.date.isValid()) {
        Day   = gps.date.day();
        Month = gps.date.month();
        Year  = gps.date.year();
      }

      //Tampilkan Waktu dan Tanggal yang Sudah Sesuai Offset / UTC yang diatur...
      if (last_second != gps.time.second()) {
        last_second = gps.time.second();
        // set current UTC time
        setTime(Hour, Minute, Second, Day, Month, Year);
        // add the offset to get local time
        adjustTime(time_offset);
        Hour   = hour();
        Minute = minute();
        Second = second();
        Day   = day();
        Month = month();
        Year  = year();
        DayOfTheWeek = weekday();
        Serial.println("======= MENAMPILKAN DATA GPS =======");
        Serial.println("\tSatellites Value: " + String(SatellitesValue, 8));
        Serial.println("\tLatitude\t: " + String(Latitude, 8));
        Serial.println("\tLongitude\t: " + String(Longitude, 8));
        Serial.println("\tAltitude\t: " + String(Altitude, 5));
        Serial.println("\tSpeed\t\t: " + String(Speed, 5));
        Serial.println(String() + "\tTime\t\t: " + Hour + ":" + Minute + ":" + Second );
        Serial.println(String() + "\tDate\t\t: " + Day + "-" + Month + "-" + Year );
        Serial.println(String() + "\tDay\t\t: " + DayOfTheWeek);
        Serial.println();
      }

    } //END IF - KETIKA GPS MENDAPATKAN DATA / SIGNAL...

  } //END WHILE - KETIKA GPS TERSAMBUNG DENGAN ARDUINO....

}
