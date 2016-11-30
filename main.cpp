#include <Audio.h>
#include <SPI.h>

const unsigned char CS1 = 31;
const unsigned char SCK1 = 32;
const unsigned char MOSI1 = 0;

// GUItool: begin automatically generated code
AudioInputUSB            usb1;           //xy=105,92
AudioOutputI2S           i2s1;           //xy=270,87
AudioConnection          patchCord1(usb1, 0, i2s1, 0);
AudioConnection          patchCord2(usb1, 1, i2s1, 1);
// GUItool: end automatically generated code


void setup() {
  // put your setup code here, to run once:
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(24);
}

void writeReg(unsigned char address, unsigned char value) {
  SPI1.beginTransaction(SPISettings(400000, MSBFIRST, SPI_MODE3));
  // take the SS pin low to select the chip:
  digitalWrite(CS1, LOW);
  delay(5);
  //  send in the address and value via SPI:
  SPI1.transfer(address);
  SPI1.transfer(value);
  // take the SS pin high to de-select the chip:
  digitalWrite(CS1, HIGH);
  // release control of the SPI port
  SPI1.endTransaction();
  delay(5);
}

void loop() {
  // put your main code here, to run repeatedly:

  pinMode(CS1, OUTPUT);
  SPI1.begin();
  delay(100);
  writeReg(0b01100000, 0b10001110); //Reset
  writeReg(0b01100000, 0b10001111); //Enable I2S data format on AK4381
  //delay(1);
  //writeReg(0b11100000, 0b10010110); //Enable I2S data format on AK4355
  //writeReg(0b11100000, 0b10010111); //Enable I2S data format on AK4355

      writeReg(0b01100011, 40);
      writeReg(0b01100100, 40);


  while(1)
  {
//    if(AudioInputUSB::features.change==1)
//    {
//      AudioInputUSB::features.change=0;
//      writeReg(0b01100000 & 0x03, AudioInputUSB::features.volume);
//      writeReg(0b01100000 & 0x04, AudioInputUSB::features.volume);
//      delay(1);
//
//    }
  }


}


void abort() {
	while(1);
}
