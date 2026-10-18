#include <iostream> 
#include <string>
#include <bitset>
#include <vector>
using namespace std; 

// Globals

string DemoConversionMessage = "Here is a demonstration that I can convert from strings to binary";
char Plaintext = 'B';
char Key1 = 'C';
string SingleKeyDemo = "This is a message which I will encrypt using a single key repeated over the message.";

void DemoConversion(){
    for (char c : DemoConversionMessage){
        bitset<8> binary(c); 
        int conversion = binary.to_ullong();
        cout << binary << " is the binary version of: " << conversion << "\n";
        char newconversion = (char)conversion;
        cout << "and here is my character: " << (newconversion) << "\n";
    }
}

bitset<8> BasicXOREncrypt(){
    bitset<8> PlaintextBinary(Plaintext); 
    bitset<8> BinaryKey(Key1); 
    bitset<8> Ciphertext;  
    Ciphertext = PlaintextBinary ^ BinaryKey;

    cout << "XOR Encrypt function:" << "\n";
    cout << "Plaintext is: " << PlaintextBinary << "\n";
    cout << "Plaintext Key is: " << BinaryKey << "\n"; 
    cout << "Ciphertext is: " << Ciphertext << "\n";
    cout << "\n";
    
    return Ciphertext;
}

void BasicXORDecrypt(bitset<8> Ciphertext){
    bitset<8> BinaryKey(Key1); 
    bitset <8> Plaintext = Ciphertext ^ BinaryKey;
    cout << "XOR Decrypt function: " << "\n";
    cout << "Received ciphertext is: " << Ciphertext << "\n";
    cout << "Plaintext Binary is: " << Plaintext << "\n";
    char RecoveredBinary = static_cast<char>(Plaintext.to_ulong());
    cout << "Recovered Binary is: " << RecoveredBinary; 
}

void XORAttack(bitset<8> Ciphertext){
    for (int i = 0; i <256; i = i +1){
        bitset<8> Attack(i);
        bitset <8> attackattempt = Ciphertext ^ Attack; 
        char candidate = static_cast<char>(attackattempt.to_ulong());    
        cout << "Key: " << i << " produced: " << candidate << "\n";     
    } 
}

vector<bitset<8>> SingleKeyXORSetup(){
    bitset<8> SingleKeyC(Key1);
    vector<bitset<8>> SKciphertext;
    for (char c : SingleKeyDemo){
        bitset<8> SingleKeyMessage(c);
        bitset<8> XORResult = SingleKeyMessage ^ SingleKeyC;
        SKciphertext.push_back(XORResult);
    }
    return SKciphertext;
}

void SingleKeyXORAttack(const vector<bitset<8>>& SKciphertext) {
    for (int z = 0; z < 256; ++z) {
        bitset<8> converted(z);
        cout << "Key " << z << ": ";

        for (size_t index = 0; index < SKciphertext.size(); ++index) {
            bitset<8> binarytext = converted ^ SKciphertext[index];
            char candidate = static_cast<char>(binarytext.to_ulong());
            cout << candidate;
        }

        cout << '\n';
    }
}



int main(){ // Simply uncomment the parts which you would like to demonstrate
    //DemoConversion(); // Call the function
    //bitset<8> EncryptedMessage = BasicXOREncrypt();
    // BasicXORDecrypt(EncryptedMessage);
    // XORAttack(EncryptedMessage);
    SingleKeyXORSetup();
    vector<bitset<8>> SKciphertext = SingleKeyXORSetup();
    SingleKeyXORAttack(SKciphertext);
return 0;
}