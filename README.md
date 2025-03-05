# Credit Card Validator

## Description
This program validates a credit card number based on two criteria:
1. **Length Check**: The card number must be 13, 15, or 16 digits long.
2. **Luhn Algorithm Check**: A checksum validation algorithm used to verify various identification numbers, including credit cards.
If valid, the program also identifies the card brand (Visa, MasterCard, AMEX) using the first two digits of the number.

---

## Usage
1. **Prerequisites**:
   - Install the [CS50 Library](https://github.com/cs50/cs50).
   - A C compiler (e.g., GCC).

2. **Compilation**:
   ```bash
   gcc -o credit_card_validator credit_card_validator.c -lcs50

Functions
Function	Description
get_card_nr()	Prompts the user for a non-negative credit card number.
count_digit(long card_num)	Counts the number of digits in the credit card number.
check_digits(int digits)	Validates if the card number length is 13, 15, or 16.
luhn_alg(long card_nr)	Implements the Luhn algorithm to validate the credit card checksum.
check_sum(int summ)	Checks if the Luhn checksum is divisible by 10.
get_first_2(long num, int num_len)


Examples
Valid Cases
Visa (16 digits):
Input: 4111 1111 1111 1111
Output: VISA
MasterCard (16 digits):
Input: 5555 5555 5555 5555
Output: MASTERCARD
AMEX (15 digits):
Input: 378282246310005
Output: AMEX
Invalid Cases
Invalid Length:
Input: 123 (3 digits)
Output: INVALID
Invalid Checksum:
Input: 4111 1111 1111 1112 (Checksum fails)
Output: INVALID
Notes
Luhn Algorithm:

Double every second digit from the right.
If doubling results in a number ≥10, subtract 9 from the product.
Sum all modified digits. If the total is divisible by 10, the number is valid.
Card Identification:

AMEX: Starts with 34 or 37 and has 15 digits.
MasterCard: Starts with 51-55 and has 16 digits.
Visa: Starts with 4 and has 13 or 16 digits.
Edge Cases:

Zero-length input is rejected by get_card_nr().
Non-digit characters are not handled (input is read as a numeric value).
