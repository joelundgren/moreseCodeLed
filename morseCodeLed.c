
// program to blink an LED based on string input. blink pattern
// is morse code based. 
// author: Joe Lundgren
#include <iostream>
#include <wiringPi.h>
using namespace std;

const int ledPin = 14;

// function takes character input and then returns the morse code as
// '.' or '-''s
string morseEncode(char x)
{
    switch (x) {
    case 'a':
        return ".-";
    case 'b':
        return "-...";
    case 'c':
        return "-.-.";
    case 'd':
        return "-..";
    case 'e':
        return ".";
    case 'f':
        return "..-.";
    case 'g':
        return "--.";
    case 'h':
        return "....";
    case 'i':
        return "..";
    case 'j':
        return ".---";
    case 'k':
        return "-.-";
    case 'l':
        return ".-..";
    case 'm':
        return "--";
    case 'n':
        return "-.";
    case 'o':
        return "---";
    case 'p':
        return ".--.";
    case 'q':
        return "--.-";
    case 'r':
        return ".-.";
    case 's':
        return "...";
    case 't':
        return "-";
    case 'u':
        return "..-";
    case 'v':
        return "...-";
    case 'w':
        return ".--";
    case 'x':
        return "-..-";
    case 'y':
        return "-.--";
    case 'z':
        return "--..";
    default:
        cerr << "Found invalid character: " << x << ' '
             << std::endl;
        exit(0);
    }
}
 
void morseCode(string s)
{
   string returnedMmorseEncode;
 
    // print the morse code of each character. then blink the LED
    for (int i = 0; s[i]; i++)
    {
        cout << s[i] << " : " << morseEncode(s[i]);
        cout << endl;
        
        returnedMmorseEncode = morseEncode(s[i]);
        
        for (int x = 0; x < returnedMmorseEncode.length(); x++)
        {
           // if a '.' blink for a short time else for '-' blink longer
           if (returnedMmorseEncode[x] == '.')
           {
               digitalWrite(ledPin, HIGH);
               delay(500);
               digitalWrite(ledPin, LOW);
               delay(500);
           }
           else
           {
               digitalWrite(ledPin, HIGH);
               delay(1500);
               digitalWrite(ledPin, LOW);
               delay(1500);
            }
         }
     }
}


int main()
{
    string wordsToBlink;
    bool endProgram = false;
    
    wiringPiSetupGpio(); // initialize WiringPi with Broadcom GPIO pins
        
    while (!endProgram) 
    {
       cout << "Type your string ($ to exit): ";
       cin >> wordsToBlink;
       
       if (wordsToBlink == "$")
         endProgram = true;
       else 
         morseCode(wordsToBlink);
    }
        
    return 0;
}
