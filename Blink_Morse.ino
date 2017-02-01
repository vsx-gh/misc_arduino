/*
 Program:      Blink_Morse
 Author:       Jeff VanSickle
 Created:      20160107
 Modified:     20160118

 Program blinks an LED with Morse code patterns
 
 UPDATES
      20160118 JV - Code Mk I. Set up two-dimensional arrays for
                    Morse alphabet

 INSTRUCTIONS
      Define a string in inputPhrase[] below. Keep it to alpha only.

 TO DO
      - Add error handling for puncutation and digits
 */

const int LED = 13;          // Output pin on Arduino for LED
const int SHORT = 250;       // Delay in ms for "short" Morse pulse
const int LONG = 750;       // Delay in ms for "long" Morse pulse
const int BTWNPULSE = 150;   // Delay between pulses in a letter
const int BTWNLETTER = 1000;  // Delay between letters
const int ENDMSG = 5000;     // Delay in ms after message is over
const int MORSEALPH[26][4] = {
                                {0, 1, 2, 2}, {1, 0, 0, 0}, {1, 0, 1, 0}, {1, 0, 0, 2}, {0, 2, 2, 2},     // A, B, C, D, E
                                {0, 0, 1, 0}, {1, 1, 0, 2}, {0, 0, 0, 0}, {0, 0, 2, 2}, {0, 1, 1, 1},     // F, G, H, I, J
                                {1, 0, 1, 2}, {0, 1, 0, 0}, {1, 1, 2, 2}, {1, 0, 2, 2}, {1, 1, 1, 2},     // K, L, M, N, O
                                {0, 1, 1, 0}, {1, 1, 0, 1}, {0, 1, 0, 2}, {0, 0, 0, 2}, {1, 2, 2, 2},     // P, Q, R, S, T
                                {0, 0, 1, 2}, {0, 0, 0, 1}, {0, 1, 1, 2}, {1, 0, 0, 1}, {1, 0, 1, 1},     // U, V, W, X, Y
                                {1, 1, 0, 0}                                                              // Z
                             };

char inputPhrase[] = "KEEVAN";     // Change this to change message output
int strIndex = 0;                  // Use as index in MORSEALPH
int i = 0;
int k = 0;

void shortPulse() 
{
  // "DOT" Morse pulse
  digitalWrite(LED, HIGH);     // LED on
  delay(SHORT);
  digitalWrite(LED, LOW);      // LED off
  delay(BTWNPULSE);
}

void longPulse()
{
  // "DASH" Morse pluse
  digitalWrite(LED, HIGH);     // LED on
  delay(LONG);
  digitalWrite(LED, LOW);      // LED off
  delay(BTWNPULSE);
}

void setup()
{
  // Initialize Pin 13 as output
  pinMode(LED, OUTPUT);
}

void loop()
{
  // Convert each letter in inputPhrase to integer
  for (k = 0; k < (sizeof(inputPhrase) / sizeof(char) - 1); k++)
  {
    strIndex = inputPhrase[k] - 65;     // ASCII A starts at 65

    // Use strIndex in Morse alphabet
    for (i = 0; i < (sizeof(MORSEALPH[k]) / sizeof(int)); i++)
    {
      if (MORSEALPH[strIndex][i] == 0)
      {
        shortPulse();  
      }     // end if
      else if (MORSEALPH[strIndex][i] == 1)
      {
        longPulse();
      }     // end else if
      else     // item is 2; i.e., blank/non-existent
      {
        // do nothing
      }     // end else
    }     // end for
  delay(BTWNLETTER);
  }     // end for
  
  delay(ENDMSG);
}     // end void loop()
