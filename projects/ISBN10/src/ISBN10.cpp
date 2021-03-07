/* PROJECT 2 - ISBN-10 Checksum
 * ----------------------------
 * The last digit of a ISBN-10 code contains the check digit. For ISBN 10,
 * each number is multiplied by a integer weight (a value from 10 to 2) in
 * descending order, which is multiplied with the digit of the ISBN code. The
 * value is valid if the check digit is between 0 and 10 and when added together
 * is a multiple of 11 (including the check digit). If the value of the check
 * digit is 10 a X should be used instead.
 * 
 * Example
 * -------
 * Suppose your incoming ISBN-10 string is "0-306-40615-?". Then
 * (0x10) + (3x9) + (0x8) + (6x7) + (4x6) + (0x5) + (6x4) + (1x3) + (5x2) = 130
 * So find the value of y such that
 * y = 130 + x
 * where x satisfies
 * y % 11 = 0
 * which means that the checksum is x=2. Hence, "0-306-40615-?" is "0-306-40615-2".
 */

#include <iostream>
#include <string>
#include <vector>

int isbn10_checksum(std::string isbn)
{
    int x = 0;
    int tmp = 0;

    isbn.erase(remove(isbn.begin(), isbn.end(), '-'), isbn.end());
    std::vector<char> digits(isbn.begin(), isbn.end());
    
    for (int i = digits.size() - 1; i > 0; i--)
    {
        tmp += (11 - i) * (static_cast<int>(digits[i-1]) - 48);
    }

    for (int i = 0; i < 11; i++)
    {
        if ((tmp + i) % 11 == 0)
        {
            x = i;
            break;
        }
    }
    
    return x;
}

int main()
{
    std::vector<std::string> test_data = { "0-306-40615-?", "0-19-852663-?", "1-86197-271-?", "1-85798-218-?" };

    for (std::string isbn : test_data)
    {
        int checksum = isbn10_checksum(isbn);
        std::cout << isbn.replace(isbn.find('?'), 1, std::to_string(checksum)) << '\n';
    }
}
