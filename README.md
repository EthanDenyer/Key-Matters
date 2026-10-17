# Key Matters: Exploring XOR Encryption in C++

An educational C++ project exploring binary representation, XOR encryption, and decryption. Built as my second C++ program, it makes the intermediate values visible to demonstrate how the operations work. This is entirely my own work. 

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

## Basic XOR Decryption

`BasicXORDecrypt()` receives the ciphertext as a parameter and applies XOR using the same key:

```text
Ciphertext: 00000001
Key:        01000011
Recovered:  01000010
```

The recovered bitset is converted into a numeric value using `.to_ulong()`, then into a character using `static_cast<char>()`. For this example, the recovered character is `'B'`.

Both encryption and decryption obtain their key from the global variable `Key1`.

## Brute-Force Attack on a Char Encrypted with Single-Byte XOR

`XORAttack()` receives the ciphertext as a parameter and tests all 256 possible eight-bit keys, from `0` to `255`.

Each candidate key is represented as a `bitset<8>` and XORed with the ciphertext:

```text
Ciphertext:    00000001
Candidate key: 01000011
Result:        01000010
```

The result is converted into a numeric value using `.to_ulong()`, then into a character using `static_cast<char>()`. Each candidate is displayed alongside its key:

```text
Key: 66 produced: C
Key: 67 produced: B
Key: 68 produced: E
```

Key `67` (`'C'`) recovers the original plaintext `'B'`. The attack does not access the original key; it tries every possibility.

This demonstrates that a single-byte key has a small, exhaustively searchable key space. However, every possible plaintext byte appears once, so the attack cannot identify the correct character without additional information.

## Brute-Force Attack on a Message Encrypted with Single-Byte XOR

A unique function converts a new example message "SingleKeyDemo" to binary and XOR's the result with a single character key:

```text
Candidate key: 01000011
```

This means that the ciphertext result consists of the same key being used to XOR each 8 bit section of the message. 

Each encrypted byte is stored in a `vector<bitset<8>>`. The function returns the complete ciphertext vector so it can be passed to a brute-force attack.
