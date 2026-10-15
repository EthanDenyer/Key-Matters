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

## Basic XOR Decryption

`BasicXORDecrypt()` receives the ciphertext as a parameter and applies XOR using the same key:

```text
Ciphertext: 00000001
Key:        01000011
Recovered:  01000010
```

The recovered bitset is converted into a numeric value using `.to_ulong()`, then into a character using `static_cast<char>()`. For this example, the recovered character is `'B'`.

Both encryption and decryption obtain their key from the global variable `Key1`.

## Brute-Force Attack on Single-Byte XOR

XORAttack() tests all 256 possible eight-bit keys against a ciphertext byte. For each candidate key, it performs XOR, converts the result into a character, and displays the candidate plaintext alongside the key value.

In the demonstration, key 67 ('C') recovers the original plaintext 'B'. However, every possible plaintext byte appears once, so the ciphertext alone cannot identify the correct answer without additional information.

The next experiment will use a longer message encrypted with the same single-byte key. The search still requires only 256 candidate keys, but meaningful text should make the correct result easier to recognise. Later experiments will investigate longer keys and their effect on cryptanalysis.


