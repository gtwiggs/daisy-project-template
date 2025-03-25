//////////////////////////////////////////////
////// SIMPLE X DAISY PINOUT CHEATSHEET //////

// 3v3           29  |       |   20    AGND
// D15 / A0      30  |       |   19    OUT 01
// D16 / A1      31  |       |   18    OUT 00
// D17 / A2      32  |       |   17    IN 01
// D18 / A3      33  |       |   16    IN 00
// D19 / A4      34  |       |   15    D14
// D20 / A5      35  |       |   14    D13
// D21 / A6      36  |       |   13    D12
// D22 / A7      37  |       |   12    D11
// D23 / A8      38  |       |   11    D10
// D24 / A9      39  |       |   10    D9
// D25 / A10     40  |       |   09    D8
// D26           41  |       |   08    D7
// D27           42  |       |   07    D6
// D28 / A11     43  |       |   06    D5
// D29           44  |       |   05    D4
// D30           45  |       |   04    D3
// 3v3 Digital   46  |       |   03    D2
// VIN           47  |       |   02    D1
// DGND          48  |       |   01    D0

#include "Template.h"

using namespace daisy;
using namespace daisysp;

// Declare a DaisySeed object called hardware
DaisySeed         hardware;
static Oscillator osc;
static bool       ledState = false;

// Audio callback function
void AudioCallback(AudioHandle::InterleavingInputBuffer  in,
                   AudioHandle::InterleavingOutputBuffer out,
                   size_t                                size)
{
  bool newLedState;

  for(size_t i = 0; i < size; i++)
  {
    newLedState = osc.Process() > 0.0f;
    if(ledState != newLedState)
    {
      ledState = newLedState;
      hardware.SetLed(ledState);
    }
  }
}

int main(void)
{
  // Configure and Initialize the Daisy Seed
  // These are separate to allow reconfiguration of any of the internal
  // components before initialization.
  hardware.Configure();
  hardware.Init();
  hardware.SetAudioBlockSize(4);

  // Initialize the oscillator.
  osc.Init(hardware.AudioSampleRate());
  osc.SetAmp(1.f);
  osc.SetFreq(0.5f);

  hardware.StartAudio(AudioCallback);

  // Loop forever
  while(1) {}
}
