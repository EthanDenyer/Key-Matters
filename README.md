# Key Matters: Exploring XOR Encryption in C++

An educational C++ project exploring binary representation, XOR encryption, and decryption. Built as my second C++ program, it makes the intermediate values visible to demonstrate how the operations work.

## Character-to-Binary Conversion

`DemoConversion()` loops through a demonstration string and represents each character using a `bitset<8>`.

For each character, it displays:

- Its eight-bit binary representation.
- Its numeric value.
- The character recovered from that numeric value.

This demonstrates reversible conversion between characters and their numeric representations. Conversion alone does not encrypt the data.

## Basic XOR Encryption

`BasicXOREncrypt()` encrypts a single plaintext character using a single-byte key.

The plaintext and key are represented as eight-bit bitsets and combined using the XOR operator, `^`. XOR produces `0` when two corresponding bits match and `1` when they differ.

With plaintext `'B'` and key `'C'`:

```text
Plaintext:  01000010
Key:        01000011
Ciphertext: 00000001
```

The function displays these values and returns the ciphertext to its caller.

## Returning and Passing Ciphertext

`main()` stores the value returned by `BasicXOREncrypt()` in `EncryptedMessage`.

That value can then be passed into another function, allowing encryption and decryption to remain separate. This demonstrates function return types, local variables, and parameters.

## Basic XOR Decryption

`BasicXORDecrypt()` receives the ciphertext as a parameter and applies XOR using the same key:

```text
Ciphertext: 00000001
Key:        01000011
Recovered:  01000010
```

The recovered bitset is converted into a numeric value using `.to_ulong()`, then into a character using `static_cast<char>()`. For this example, the recovered character is `'B'`.

Both encryption and decryption obtain their key from the global variable `Key1`.

## Why Decryption Works

Applying XOR with the same key twice restores the original value:

```text
Ciphertext = Plaintext XOR Key
Plaintext  = Ciphertext XOR Key
```

This demonstrates symmetric encryption: the same secret key is used to encrypt and decrypt.

## Running the Demonstrations

The calls in `main()` control which demonstrations run:

- `DemoConversion()` displays character conversion.
- `BasicXOREncrypt()` produces and returns ciphertext.
- `BasicXORDecrypt(EncryptedMessage)` recovers the original character.

Uncomment the relevant calls to enable each demonstration. Decryption requires the ciphertext returned by encryption.

