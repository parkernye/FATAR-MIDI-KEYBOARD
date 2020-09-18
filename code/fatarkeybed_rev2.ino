/*
Parker Nye 
9-17-2020

CREDITS
Written by tttapa, 24/09/2017
https://github.com/tttapa/MIDI_controller
*/

#include "MIDI_Controller.h" // Include the library

USBDebugMIDI_Interface midiInterface(31250);


//debug
//auto &serial = Serial;
//HardwareSerialMIDI_Interface midi = {Serial1, MIDI_BAUD};


const uint8_t velocity = 0b1111111; // Maximum velocity (0b1111111 = 0x7F = 127)
const uint8_t addresses[5][8] = {   // the note numbers corresponding to the buttons in the matrix
  {57,58,59,60,61,62,63,64},
{65,66,67,68,69,70,71,72},
{73,74,75,76,77,78,79,80}, //why is this keybed offst by 3 notes? 
{81,82,83,84,85,86,87,88},
{89,90,91,92,93,94,95,96}
};

//scan matrix
ButtonMatrix<5, 8> buttonmatrix({18,15,14,16,10}, {2,3,4,5,6,7,8,9}, addresses, 1, velocity);

//pitch and mod wheel
//AnalogHiRes pitch(A0, 1);
//Analog mod(A1, MIDI_CC::Channel_Volume, 1);

void setup() {}

void loop() {
  // Refresh the buttons (check whether the states have changed since last time, if so, send it over MIDI)
  MIDI_Controller.refresh();
}

