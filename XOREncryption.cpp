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

// This XOR function works by taking a plaintext character, converting into binary and then XORing with a key of the same
// length as the binary plaintext message to give its encrypted ciphertext. 

bitset<8> BasicXOREncrypt(){
    bitset<8> PlaintextBinary(Plaintext); // 8 bit plaintext 
    bitset<8> BinaryKey(Key1); // 8 bit key
    bitset<8> Ciphertext; // Storage for XOR 
    Ciphertext = PlaintextBinary ^ BinaryKey; // Ciphertext is the XOR of PlaintextBinary and PlaintextKey

    cout << "XOR Encrypt function:" << "\n";
    cout << "Plaintext is: " << PlaintextBinary << "\n"; // Debug binary length
    cout << "Plaintext Key is: " << BinaryKey << "\n"; // Debug binary length
    cout << "Ciphertext is: " << Ciphertext << "\n";
    cout << "\n";
    
    return Ciphertext;
}

// In keeping with the idea of a symmetric key, we do not pass the key over to the Decrypt function, nor do we use a global
// function, it is simply declared locally.

void BasicXORDecrypt(bitset<8> Ciphertext){
    bitset<8> BinaryKey(Key1); // 8 bit key
    bitset <8> Plaintext = Ciphertext ^ BinaryKey;
    cout << "XOR Decrypt function: " << "\n";
    cout << "Received ciphertext is: " << Ciphertext << "\n";
    cout << "Plaintext Binary is: " << Plaintext << "\n";
    char RecoveredBinary = static_cast<char>(Plaintext.to_ulong());
    cout << "Recovered Binary is: " << RecoveredBinary; 
}

int main(){
    // DemoConversion(); // Call the function
    bitset<8> EncryptedMessage = BasicXOREncrypt();
    BasicXORDecrypt(EncryptedMessage);

return 0;
}