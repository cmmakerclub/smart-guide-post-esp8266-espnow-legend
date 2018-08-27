# SmartPost
## Project CMMC

### ฟังก์ชันการใช้งาน
#### 1. ATtiny 
* เมื่อมีการชน Pin 3 จะ High 2 นาทีเพื่อบอก ESP ว่ามีการชน
* เมื่อ Pin 2 (มี Internal_Pullup) HIGH >>> LOW จะเริ่มทำการกระพริบไฟสีแดงจนกว่าจะเปลี่ยนสถานะเป็น HIGH
* เมื่อ Pin 2 เปลี่ยนสถานะจาก LOW >>> HIGH (มี Internal_Pullup) กลับมากระพริบไฟสีเขียวปกติ

#### 2. ESP8266 
* มีหน้าที่ สื่อสารผ่านโปรโตคอล ESP_NOW
* ใช้ Pin 12 รับ High LOW จาก ATtiny ว่ามีการชนหรือไม่
* ใช้ Pin 14 ส่ง High LOW ไปยัง ATtiny ให้กระพริบไปสีแดง หรือสีเขียว
* ใช้ Pin A0 เพื่อวัดแบตเตอรี่

 ATTiny 85 Core for Arduino (1.8.x recommended)
============

### Supported clock speeds:

Internal:
* 8 MHz

### ATtiny 25/45/85
![x5 pin mapping](http://drazzy.com/e/img/PinoutT85a.jpg "Arduino Pin Mapping for ATtiny 85/45/25")


Hardware
============

* ATtiny pin 0 use for Blink LED_red && mosfet drive x3 LED
* ATtiny pin 1 use for Blink LED_green && mosfet drive x3 LED
* ATtiny pin 2 use for Input ESP_in (Input_Pullup)
* ATtiny pin 3 use for Output ESP_out
* ATtiny pin 4 use for Input Vibration sensor (Input_Pullup)
* 0.1uf capacitor between Reset and Gnd
* 4.7k resistor between reset and Vcc (required)
