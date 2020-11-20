/*  
 * Example of an LED blinking as SOS pattern in morse code.
 */

#include <Morse.h>

Morse morse(2);

void setup()
{
  // Do nothing
}

void loop()
{
  morse.dot(); morse.dot(); morse.dot();
  morse.dash(); morse.dash(); morse.dash();
  morse.dot(); morse.dot(); morse.dot();
  delay(3000);
}
