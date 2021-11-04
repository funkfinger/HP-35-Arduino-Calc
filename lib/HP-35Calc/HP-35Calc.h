#include <Arduino.h>

#ifndef __hp35Calc__
#define __hp35Calc__

// HP-35 info - http://home.citycable.ch/pierrefleur/Jacques-Laporte/HP35%20ROM.htm
// HP-35 calculator keys...

#define F_X_TO_Y      6
#define F_LOG         4
#define F_LN          3
#define F_E_TO_X      2
#define F_CLR         0

#define F_SQR_X       46
#define F_ARC         44
#define F_SIN         43
#define F_COS         42
#define F_TAN         40

#define F_ONE_OVER_X  14
#define F_X_SWAP_Y    12
#define F_ROLL_DOWN   11
#define F_STO         10
#define F_RCL         8

#define F_ENTER       62
#define F_CHS         59
#define F_EEX         58
#define F_CLX         56

#define F_MINUS       54
#define F_SEVEN       52
#define F_EIGHT       51
#define F_NINE        50

#define F_PLUS        22
#define F_FOUR        20
#define F_FIVE        19
#define F_SIX         18

#define F_TIMES       30
#define F_ONE         28
#define F_TWO         27
#define F_THREE       26

#define F_DIVIDED     38
#define F_ZERO        36
#define F_DECIMAL     35
#define F_PI          34

#define NUMBER_OF_AUTO_ENTER_COMMANDS 18

class HPCalc {
  public:
    HPCalc();
    char * getResultString();
    void enterCommand(int command);
    void tick();
  private:
    byte key_code = 255;
    void buildResultString();
    char resultString[20];
    byte a[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // A register
    byte b[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // B register
    byte c[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // C register
    byte d[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // D register
    byte e[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // E register
    byte f[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // F register
    byte m[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // M Scratchpad
    byte t[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // Temporary
    byte s[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0} ; // Status
    byte p = 0, pc = 0, ret = 0; // Pointer
    byte offset = 0; // ROM offset
    byte first, last; // Register loop boundaries
    byte carry = 0, prevCarry = 0; // Carry bits
    byte fetch_h, fetch_l, op_code = 0; // ROM fetch and operation code
    byte key_rom = 0; // Key variables
    boolean display_enable = true, update_display = true; // Display control
    boolean isError = false; // True if error
    unsigned char chr_prtd=0;
    byte key; // Holds entered key

    byte autoEnterList[NUMBER_OF_AUTO_ENTER_COMMANDS] = {
      F_ROLL_DOWN,
      F_X_SWAP_Y,
      F_RCL,
      F_PI,
      F_PLUS,
      F_MINUS,
      F_TIMES,
      F_DIVIDED,
      F_SQR_X,
      F_E_TO_X,
      F_LN,
      F_LOG,
      F_ONE_OVER_X,
      F_ARC,
      F_SIN,
      F_COS,
      F_TAN,
      F_EEX
    };


    byte do_add(byte x, byte y);
    byte do_sub(byte x, byte y);
    void process_rom(void);
};

#endif

/*
// original copyright info...

source modified from https://www.instructables.com/HP-35-Scientific-Calculator-Emulator-With-Arduino-/

Copyright (c) 2011 DE LUCA Pietro, Italy 
$Id:hp35_lcd.pde 11-06-2011 Pietro $

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
    The name of the author may not be used to endorse or promote products derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE AUTHOR â€œAS ISâ€ AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
