#include <iostream> 
#include <string>
#include <bitset>
using namespace std; 

// XOR Encryption with keys od different lengths. I will demonstrate that the key decides whether the encryption is weak or unbreakable.
// There are XOR operations, but this a demonstratonn and therefore it makes more sense in my opinion to demonstrate this physically by 
// converting and showing the XOR.

// Globals

string DemoConversionMessage = "Here is a demonstration that I can convert from strings to binary";
char Plaintext = 'B';
char Key1 = 'C';

// Basic exercise to demonstrate reversible conversion for string to binary.
void DemoConversion(){
    for (char c : DemoConversionMessage){
        bitset<8> binary(c); // 8 Bits per character, the bitset stores the bits
        int conversion = binary.to_ullong();
        cout << binary << " is the binary version of: " << conversion << "\n";
        char newconversion = (char)conversion;
        cout << "and here is my character: " << (newconversion) << "\n";
    }
}

// This XOR function works by taking a plaintext message, converting into binary and then XORing with a key of the same
// length as the binary plaintext message to give its encrypted ciphertext. 

void XOR(){
    bitset<8> PlaintextBinary(Plaintext); // 8 bit plaintext 
    bitset<8> PlaintextKey(Key1); // 8 bit key
    bitset<8> Ciphertext; // Storage for XOR 
    Ciphertext = PlaintextBinary ^ PlaintextKey; // Ciphertext is the XOR of PlaintextBinary and PlaintextKey

    cout << "Plaintext is: " << PlaintextBinary << "\n"; // Debug binary length
    cout << "Plaintext Key is: " << PlaintextKey << "\n"; // Debug binary length
    cout << "Ciphertext is: " << Ciphertext << "\n";
}

int main(){
    // DemoConversion(); // Call the function
    XOR();
return 0;
}