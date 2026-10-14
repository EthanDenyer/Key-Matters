#include <iostream> 
#include <string>
#include <bitset>
using namespace std; 

// XOR Encryption with keys od different lengths. I will demonstrate that the key decides whether the encryption is weak or unbreakable.
// There are XOR operations, but this a demonstratonn and therefore it makes more sense in my opinion to demonstrate this physically by 
// converting and showing the XOR.

// Globals

string DemoConversionMessage = "Here is a demonstration that I can convert from strings to binary";
string Plaintext = "B";
string Key1 = "C";

// Basic exercise to demonstrate reversible conversion for string to binary.
void DemoConversion(){
    for (char c : DemoConversionMessage){
        bitset<8> binary(c); // 8 Bits per character, the bitset stores the bits
        int conversion = binary.to_ullong();
        cout << binary << "is the binary version of: " << conversion << "\n";
        char newconversion = (char)conversion;
        cout << "and here is my character: " << (newconversion) << "\n";
    }
}

int main(){
    DemoConversion(); // Call the function

return 0;
}