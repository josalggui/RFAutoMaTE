/*
Code to control the RFAutoMaTE with arduino.
Ph.D. José Miguel Algarín Guisado
mriLab, i3M, CSIC, Valencia, Spain
RFAutoMaTE is able to change the impedance by de/activating relays that adds c
apacitance to a T circuit. The T circuit include a series capacitor, tuning and
matching.

|---------||-------------||-------*
|         Cs     |       Cm
c                |
c Coil          | | Ct
c                |
|                |
|---------------------------------*

Each capacitance has up to 5 capacitors, giving a total of 15 pins. An additional
digital signal (TTL) allow the user to switch the tuning matching between the
Tx/Rx switch to run MRI experiments or to the VNA to measure the coil impedance.

User can control the status by sending a set of 16 digits to de/activate the
capacitance.
0->Capacitor activated
1->Capacitor deactivated

Last digit correspond the switching between VNA and TxRx switch:
0->TxRx switch
1->VNA

For example, if the user wants to activate all capcitors and connect to TxRx switch:
0000000000000000

For the momento, the code does not check the number of digits. So make sure that
the number of digits is 16, otherwise, arduino can look frozen.

*/

// Code to control the autotuning circuit with python.
//  cPins[] = {S1, S2, S3, S4, S5, T1, T2, T3, T4, T5, M1, M2, M3, M4, M5, TTL}
int cPins[] = {23, 31, 29, 27, 25, 41, 39, 37, 35, 33, 43, 51, 49, 47, 45, 53};
int nPins = 16;

void setup() {
  // Start the Serial communication
  Serial.begin(115200);
  Serial.setTimeout(100);
  // Set the pins for tuning, matching and series capacitors
  for (int c=0; c<nPins; c++) {
    pinMode(cPins[c], OUTPUT);
  }
}

void loop() {
  // Wait until there are any data available into the serial port
  if (Serial.available()>0) {
    delay(10);
    String state = Serial.readString();
    for (int c=0; c<nPins; c++) {
      digitalWrite(cPins[c], String(state[c]).toInt());
    }
    Serial.write("Ready!\n");
  }

}
