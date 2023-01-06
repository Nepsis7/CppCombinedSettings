#include "Windows.h"
#include <iostream>

//booleans occupating different bits in a single byte
#define PARAM1 0b00000001
#define PARAM2 0b00000010
#define PARAM3 0b00000100
#define PARAM4 0b00001000
#define PARAM5 0b00010000
#define PARAM6 0b00100000
#define PARAM7 0b01000000
#define PARAM8 0b10000000

void DoStuff(byte _settings)
{
	/* in order to get the value of every single bit (corresponding to a boolean),
	* we :
	* get the bit we're working on to the last bit of the byte using a bitwise right shift operator '>>'
	* for example PARAM4 (0b1000) will become 0b0001
	* we then isolate the bit from other potential bits on the left using the bitwise operator and '&' thisway :
	* result & 0b00000001
	* this will make every non-last byte be zero (since they're 0 in the compared byte above),
	* and the last byte 1 if 'result' (being the result of the previous step) is 1
	* we can now use the result of this whole operation as a boolean
	*/
	for (int i = 0; i < 8; i++)
	{
		const bool _result = (_settings >> i) & 0b1;
		printf("param %d : %d (%s)\n", i+1, _result, (_result ? "true" : "false"));
	}
}

int main()
{
	/* by combining the byte values of every parameter (line 5),
	* we can create a new byte contaning a boolean value for every single one.
	* every param passed this way will be true, the rest is false*/
	DoStuff(PARAM1 | PARAM4 | PARAM3 | PARAM7);
}
