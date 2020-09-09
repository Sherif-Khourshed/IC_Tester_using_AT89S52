#define P0 0
#define P1 1
#define P2 2
#define P3 3

extern "C" bool OpenCom(unsigned int ComPortNumber, int BAUDRATE = 115200);
extern "C" void CloseCom();
extern "C" void setb(unsigned int portnum, unsigned char bit);
extern "C" void clr(unsigned int portnum, unsigned char bit);
extern "C" unsigned int SerialInput(unsigned int portnum);
extern "C" void SerialOutput(unsigned int portnum, unsigned char data);
extern "C" bool GetBit(unsigned int portnum, unsigned char bit);

