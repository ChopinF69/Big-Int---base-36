//
// Created by lazar on 26.01.2024.
//

#ifndef BIG_INT_FINAL_BIG_INT_GENERAL_H
#define BIG_INT_FINAL_BIG_INT_GENERAL_H
#include <cmath>
#include <algorithm>
#include <string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
#include <iostream>
#include <utility>
#include <vector>
/*
 * Summary:
 * The Big_Int_General class is a custom implementation capable of handling large integer arithmetic operations
 * up to base 36.
 * It offers a range of functionalities including arithmetic operations
 * (addition, subtraction, multiplication, division),
 * comparison operations, modulo operations, exponentiation, input/output operations, base conversion,
 * and various auxiliary functions like random number generation, primality testing, and more.

 * Licensed under free license:
 * This implementation of the Big_Int_General class, authored by Lazar Alexandru
 * from the University UBB FMI, provides a versatile solution for working with large integers in C++.
 * It offers a comprehensive set of features for mathematical computations and number manipulations.
 * This work is licensed under a free license, allowing users to modify,
 * distribute, and use the code for both personal and commercial purposes,
 * provided credit is given to the original author, Lazar Alexandru.
 */

class Big_Int_General
{
private:
    int base;
    std::string digits;
public:
    //------------------------------------------------------------------------CONSTRUCTORS
    Big_Int_General();
    Big_Int_General(std::string);
    Big_Int_General(Big_Int_General&);
    Big_Int_General(const Big_Int_General&);
    Big_Int_General(std::string , int );

    //--------------------------------------------------------------------------GET & SET
    std::string get_digits(){return digits;}
    int get_base(){return base;}
    int get_size(){return digits.size();}

    void set_digits(std::string s){digits = std::move(s);}
    void set_base(int new_base){base = new_base;}

    //--------------------------------------------------------------------------ASSIGNATION
    Big_Int_General &operator=(Big_Int_General);

    //--------------------------------------------------------------------------ARHITHMETIC OPERATIONS
    friend Big_Int_General operator+(Big_Int_General , Big_Int_General);
    friend Big_Int_General operator+(Big_Int_General , char);
    friend Big_Int_General operator+(Big_Int_General , int);
    friend Big_Int_General operator+(Big_Int_General , std::string);

    friend Big_Int_General operator-(Big_Int_General , Big_Int_General);
    friend Big_Int_General operator-(Big_Int_General , char);
    friend Big_Int_General operator-(Big_Int_General , int);
    friend Big_Int_General operator-(Big_Int_General , std::string);

    friend Big_Int_General &operator+=(Big_Int_General &, Big_Int_General);
    friend Big_Int_General &operator+=(Big_Int_General &, char);
    friend Big_Int_General &operator+=(Big_Int_General &, int);
    friend Big_Int_General &operator+=(Big_Int_General &, std::string);

    friend Big_Int_General &operator-=(Big_Int_General &, Big_Int_General);
    friend Big_Int_General &operator-=(Big_Int_General &, char);
    friend Big_Int_General &operator-=(Big_Int_General &, int);
    friend Big_Int_General &operator-=(Big_Int_General &, std::string);

    friend Big_Int_General operator*(Big_Int_General , Big_Int_General);
    friend Big_Int_General operator*(Big_Int_General , char);
    friend Big_Int_General operator*(Big_Int_General , int);
    friend Big_Int_General operator*(Big_Int_General , std::string);

    friend Big_Int_General operator/(Big_Int_General , Big_Int_General);
    friend Big_Int_General operator/(Big_Int_General , char);
    friend Big_Int_General operator/(Big_Int_General , int);
    friend Big_Int_General operator/(Big_Int_General , std::string);

    friend Big_Int_General &operator*=(Big_Int_General &, Big_Int_General);
    friend Big_Int_General &operator*=(Big_Int_General &, char);
    friend Big_Int_General &operator*=(Big_Int_General &, int);
    friend Big_Int_General &operator*=(Big_Int_General &, std::string);

    friend Big_Int_General &operator/=(Big_Int_General &, Big_Int_General);
    friend Big_Int_General &operator/=(Big_Int_General &, char);
    friend Big_Int_General &operator/=(Big_Int_General &, int);
    friend Big_Int_General &operator/=(Big_Int_General &, std::string);


    //--------------------------------------------------------------------------BOOL OPERATORS
    friend bool operator>(Big_Int_General , Big_Int_General);
    friend bool operator<(Big_Int_General , Big_Int_General);
    friend bool operator>=(Big_Int_General , Big_Int_General);
    friend bool operator<=(Big_Int_General ,Big_Int_General);

    friend bool operator==(Big_Int_General , Big_Int_General);
    friend bool operator!=(Big_Int_General , Big_Int_General);
    friend bool Null(Big_Int_General);
    char operator[](int index);

    //--------------------------------------------------------------------------------MODULO
    friend Big_Int_General operator%(Big_Int_General , Big_Int_General);
    friend Big_Int_General &operator%=(Big_Int_General & , Big_Int_General);

    friend Big_Int_General operator%(Big_Int_General , int);
    friend Big_Int_General &operator%=(Big_Int_General , int);

    //--------------------------------------------------------------------------------EXPONENTIATION
    friend Big_Int_General operator^(Big_Int_General , Big_Int_General);
    friend Big_Int_General &operator^=(Big_Int_General & , Big_Int_General);

    friend Big_Int_General operator^(Big_Int_General , int);
    friend Big_Int_General &operator^=(Big_Int_General & , int);

    //--------------------------------------------------------------------------------READING & WRITING
    friend std::istream &operator>>(std::istream & , Big_Int_General &);
    friend std::ostream &operator<<(std::ostream & , Big_Int_General &);

    //---------------------------------------------------------------------------------CONVERT BASES
    static Big_Int_General big_int_general_to_10(Big_Int_General);
    static Big_Int_General base_10_to_big_int_general(Big_Int_General , int);
    static Big_Int_General source_base_destination_base(Big_Int_General , int);

    //----------------------------------------------------------------------------------AUX FUNCTIONS
    static Big_Int_General pow(Big_Int_General , Big_Int_General);
    static void swap(Big_Int_General &, Big_Int_General &);

    static  Big_Int_General karatsuba(Big_Int_General , Big_Int_General);
    static Big_Int_General random_big_int(int , int);
    static Big_Int_General random_big_int(int , int , Big_Int_General);
    static bool is_prime(Big_Int_General);
    static bool is_palindrome(Big_Int_General);
    static Big_Int_General gcd(Big_Int_General , Big_Int_General);
    static Big_Int_General lcm(Big_Int_General , Big_Int_General);
    static Big_Int_General sqrt(Big_Int_General);
    static Big_Int_General binary_division(Big_Int_General , Big_Int_General);

    //neimplementat
    static Big_Int_General Burnikel_Ziegler(Big_Int_General , Big_Int_General);
    static Big_Int_General xorOperation(Big_Int_General , Big_Int_General);
};
/*
 * --------------------------------------------------------------First we will define the assign & constructors
 */

Big_Int_General & Big_Int_General::operator=(Big_Int_General __a){
            digits = __a.digits;
            base = __a.base;
            return *this;
}

Big_Int_General::Big_Int_General()
{
    digits = "0";
    base = 10;
}
Big_Int_General::Big_Int_General(std::string __s , int __base)
{
    base = __base;

    int contor = 0;
    for(int i = 0 ; __s[i] ; ++i)
        if(__s[i] == '0')++contor;
    if(contor == __s.size())__s = "0";
    else {
        int i = 0;
        while (__s[i] == '0')
            i++;

        // The erase function removes i characters
        // from given index (0 here)
        __s.erase(0, i);
    }
    for(int i = 0 ; i < __s.size() ; ++i)
    {
        if(__s[i] >= 'A' and __s[i] <= 'Z')
        {
            __s[i] = 'a' + (__s[i] - 'A');
        }
    }
    digits = __s;
}
Big_Int_General::Big_Int_General(std::string __s)
{
    //If s == '0' it will remain the same but if it __s.size() != 1 , then we remove the zeros
    // && Count leading zeros
    int contor = 0;
    for(int i = 0 ; __s[i] ; ++i)
        if(__s[i] == '0')++contor;
    if(contor == __s.size())__s = "0";
    else {
        int i = 0;
        while (__s[i] == '0')
            i++;

        // The erase function removes i characters
        // from given index (0 here)
        __s.erase(0, i);
    }
    for(int i = 0 ; i < __s.size() ; ++i)
    {
        if(__s[i] >= 'A' and __s[i] <= 'Z')
        {
            __s[i] = 'a' + (__s[i] - 'A');
        }
    }
    digits = __s;
    //The maximum base will be the maximum character + 1
    size_t size_of_array = __s.size();
    char max_char = '0';//'0' is 48   '9' is 57
    //'a' is 97   'z' is 122
    for(int i = 0 ; i < size_of_array ; ++i)
    {
        if(max_char < __s[i])
            max_char = __s[i];
    }
    //Here we find the base
    if(max_char >= '0' && max_char <= '9')
    {
        base = max_char - '0' + 1;
    }
    else
    {
        base = max_char - 'a' + 1;
        base += 10;
    }
}
Big_Int_General::Big_Int_General(Big_Int_General& __a)
{
    digits = __a.get_digits();
    base = __a.get_base();
}
Big_Int_General::Big_Int_General(const Big_Int_General& __a)
{
    *this = __a;
}

/*
 * -----------------------------------------------------------------------BOOL OPERATORS
 */
bool Null(Big_Int_General a)
{
    std::string digits = a.get_digits();
    if(a.get_size() == 0)return false;
    if(digits[0] == '0' && digits.size() == 1)return true;
    return false;
}
char Big_Int_General::operator[](int index)
{
    if(digits.size() <= index || index < 0)
        std::runtime_error("Error gresit index");
    return digits[index];
}

bool operator==(Big_Int_General B1 , Big_Int_General B2)
{
    std::string s_B1 = B1.get_digits();
    std::string s_B2 = B2.get_digits();

    int base_1 = B1.get_base();
    int base_2 = B2.get_base();

    if(base_1 != base_2)return false;
    else
    {
        size_t size_B1 = s_B1.size();
        size_t size_B2 = s_B2.size();

        if(size_B1 != size_B2)return false;
        else
        {
            for(int i = 0 ; i < size_B1 ; ++i)
                if(s_B1[i] != s_B2[i])return false;
            return true;
        }
    }
}
bool operator!=(Big_Int_General B1 , Big_Int_General B2)
{
    return !(B1 == B2);
}

bool operator>(Big_Int_General B1 , Big_Int_General B2)
{
    std::string s_B1 = B1.get_digits();
    std::string s_B2 = B2.get_digits();

    int base_1 = B1.get_base();
    int base_2 = B2.get_base();

    if(base_2 != base_1);
    else
    {
        size_t size_B1 = s_B1.size();
        size_t size_B2 = s_B2.size();

        if(size_B1 != size_B2)
        {
            if(size_B1 > size_B2)return true;
            return false;
        }
        else
        {
            for(int i = 0 ; i < size_B2 ; ++i)
            {
                char c_B1 = s_B1[i] , c_B2 = s_B2[i];
                int cifra_B1 , cifra_B2;

                if(c_B1 >= 'a')cifra_B1 = c_B1 - 'a' + 10;
                else cifra_B1 = c_B1 - '0';

                if(c_B2 >= 'a')cifra_B2 = c_B2 - 'a' + 10;
                else cifra_B2 = c_B2 - '0';

                if(cifra_B1 > cifra_B2)return true;
                else if(cifra_B1 < cifra_B2)return false;
            }
            return false; //if all the digits are equal it is not strict
        }
    }
}

bool operator<(Big_Int_General B1 , Big_Int_General B2)
{
    return !(B1 > B2) && (B1 != B2);
}

bool operator>=(Big_Int_General B1 , Big_Int_General B2)
{
    return (B1 > B2) || (B1 == B2);
}
bool operator<=(Big_Int_General B1 , Big_Int_General B2)
{
    return (B1 < B2) || (B1 == B2);
}

/*
 * --------------------------------------------------------------------ARITHMETIC OPERATORS
 */
//---------------------------------------------------------------------PLUS + & +=
Big_Int_General operator+(Big_Int_General a , Big_Int_General b)
{
    int t = 0, s;
    int base_1 = a.get_base(), base_2 = b.get_base(), base = std::max(base_1, base_2);
    if (base_1 != base_2)
        std::runtime_error("You can't sum 2 numbers with different bases");
    int l1 = a.get_size(), l2 = b.get_size();
    l1--; l2--;
    std::string s1 = a.get_digits(), s2 = b.get_digits();
    std::string s3 = "";

    while (l1 >= 0 || l2 >= 0 || t > 0)
    {
        int cifra_1 = 0, cifra_2 = 0;
        if(l1 >= 0)
        {
            //digit
            if(s1[l1] >= '0' && s1[l1] <= '9')cifra_1 = s1[l1] - '0';
            else //is letter 'a' , 'b'...
            {
                int c = s1[l1] - 'a';
                cifra_1 += c + 10;
            }
        }
        if(l2 >= 0)
        {
            //digit
            if(s2[l2] >= '0' && s2[l2] <= '9')cifra_2 = s2[l2] - '0';
            else //is letter 'a','b'...
            {
                int c = s2[l2] - 'a';
                cifra_2 += c + 10;
            }
        }
        int sum_cifre = cifra_1 + cifra_2 + t;
        t = sum_cifre / base;
        s = sum_cifre % base;

        // Convert the remainder to the appropriate character
        char digit = (s < 10) ? char(s + '0') : char(s - 10 + 'a');

        s3 = digit + s3;

        if (l1 >= 0) l1--;
        if (l2 >= 0) l2--;
    }

    Big_Int_General result(s3, base);
    return result;
}
Big_Int_General operator+(Big_Int_General a, char c)
{
    std::string str = {c};
    Big_Int_General new_big_int_general(str , a.get_base());
    a = a + new_big_int_general;

    return a;
}
Big_Int_General operator+(Big_Int_General a , std::string s)
{
    Big_Int_General new_a(s , a.get_base());
    a = a + new_a;
    return a;
}
Big_Int_General operator+(Big_Int_General a , int c)
{
    Big_Int_General new_a(std::to_string(c) , a.get_base());
    a = a + new_a;
    return a;
}
//----------------------------------------------------------------
Big_Int_General &operator+=(Big_Int_General& a , Big_Int_General b)
{
    a = a + b;
    return a;
}
Big_Int_General &operator+=(Big_Int_General& a, char c)
{
    std::string str = {c};
    Big_Int_General new_big_int_general(str , a.get_base());
    a = a + new_big_int_general;

    return a;
}
Big_Int_General &operator+=(Big_Int_General& a , std::string s)
{
    Big_Int_General new_a(s , a.get_base());
    a = a + new_a;
    return a;
}
Big_Int_General &operator+=(Big_Int_General& a , int c)
{
    Big_Int_General new_a(std::to_string(c) , a.get_base());
    a = a + new_a;
    return a;
}

//---------------------------------------------------------------------- MINUS SIGN - & -=
Big_Int_General operator-(Big_Int_General a , Big_Int_General b)
{
    int base_1 = a.get_base(), base_2 = b.get_base();
    if (base_2 != base_1)
        std::runtime_error("You cannot substract 2 numbers with different bases ! ");

    if (a < b);
    //throw std::runtime_error("UNDERFLOW");

    int l1 = a.get_size(), l2 = b.get_size();
    std::string s1 = a.get_digits(), s2 = b.get_digits(), s3 = "";
    int base = base_1, t = 0, s;

    // Adjusting the indices to be within valid range
    l1--; l2--;

    while (l1 >= 0 || l2 >= 0 || t > 0)
    {
        int cifra_1 = 0, cifra_2 = 0;
        char chr_1 , chr_2;
        if(l1 >= 0)
        {
            //digit
            if(s1[l1] >= '0' && s1[l1] <= '9')cifra_1 = s1[l1] - '0';
            else //este litera
            {
                int c = s1[l1] - 'a';
                cifra_1 += c + 10;
            }
        }
        if(l2 >= 0)
        {
            //digit
            if(s2[l2] >= '0' && s2[l2] <= '9')cifra_2 = s2[l2] - '0';
            else //is letter
            {
                int c = s2[l2] - 'a';
                cifra_2 += c + 10;
            }
        }
        // Adjusting for the borrow
        cifra_1 -= t;
        t = 0;

        // Borrow logic
        if (cifra_1 < cifra_2)
        {
            cifra_1 += base;
            t = 1;
        }

        // Actual subtraction
        s = cifra_1 - cifra_2;

        if (s >= 0 && s <= 9) {
            s3 = char(s + '0') + s3;
        } else {
            s -= 10;
            s3 = char(s + 'a') + s3;
        }
        // Move to the next digits
        l1--; l2--;
    }

    Big_Int_General result(s3, base);

    return result;
}
Big_Int_General operator-(Big_Int_General a , char c)
{
    std::string str = {c};
    Big_Int_General new_big_int_general(str , a.get_base());
    a = a - new_big_int_general;

    return a;
}
Big_Int_General operator-(Big_Int_General a , std::string s)
{
    Big_Int_General new_a(s , a.get_base());
    a = a - new_a;

    return a;
}
Big_Int_General operator-(Big_Int_General a , int c)
{
    Big_Int_General new_a(std::to_string(c) , a.get_base());
    a = a - new_a;

    return a;
}
//---------------------------------------------------------------
Big_Int_General &operator-=(Big_Int_General &a , Big_Int_General b)
{
    a = a - b;
    return a;
}
Big_Int_General &operator-=(Big_Int_General &a , char c)
{
    std::string str = {c};
    Big_Int_General new_big_int_general(str , a.get_base());
    a = a - new_big_int_general;

    return a;
}
Big_Int_General &operator-=(Big_Int_General& a , std::string s)
{
    Big_Int_General new_a(s , a.get_base());
    a = a - new_a;

    return a;
}
Big_Int_General &operator-=(Big_Int_General& a , int c)
{
    Big_Int_General new_a(std::to_string(c) , a.get_base());
    a = a - new_a;

    return a;
}
//-----------------------------------------------------------------------MULTIPLICATION * & *=
Big_Int_General operator*(Big_Int_General a ,int cifra_inmultire)
{
    int len = a.get_size();
    std::string ans = "", digits = a.get_digits();
    int t = 0, s, base = a.get_base();
    for (int i = len - 1; i >= 0; --i)
    {
        int cifra;
        if (digits[i] >= '0' && digits[i] <= '9')
            cifra = digits[i] - '0';
        else
        {
            int c = digits[i] - 'a';
            cifra = c + 10;
        }

        int rez = cifra * cifra_inmultire + t;  // Add the carry to the multiplication result
        t = rez / base;
        s = rez % base;

        // Convert the remainder to the appropriate character
        char digit = (s < 10) ? char(s + '0') : char(s - 10 + 'a');

        ans = digit + ans;
    }

    // If there's a carry left after the loop, add it as the most significant digit
    while (t > 0)
    {
        s = t % base;
        char digit = (s < 10) ? char(s + '0') : char(s - 10 + 'a');
        ans = digit + ans;
        t /= base;
    }

    Big_Int_General result(ans, base);
    return result;
}
Big_Int_General operator*(Big_Int_General a , Big_Int_General b)
{
    int base_a = a.get_base();
    int base_b = b.get_base();

    if (base_a != base_b)
        throw std::runtime_error("Cannot multiply numbers with different bases!");

    int base = base_a;
    Big_Int_General result("0", base);
    std::string digits_b = b.get_digits();
    int t = 0 ,s , len_b = b.get_size();
    for (int i = len_b - 1; i >= 0; --i)
    {
        int digit_b;
        if (digits_b[i] >= '0' && digits_b[i] <= '9')
        {
            digit_b = digits_b[i] - '0';
        }
        else
        {
            int c = digits_b[i] - 'a';
            digit_b = c + 10;
        }
        Big_Int_General partial_product = a * digit_b;

        //deplasam cu i pozitii la stanga
        for(int j = i + 1; j < len_b ; ++j)
            partial_product = partial_product * base;
        result += partial_product;
    }
    return result;
}
Big_Int_General operator*(Big_Int_General a , char c)
{
    std::string str = {c};
    Big_Int_General new_big_int_general(str , a.get_base());
    a = a * new_big_int_general;

    return a;
}
Big_Int_General operator*(Big_Int_General a , std::string s)
{
    Big_Int_General new_a(s , a.get_base());
    a = a * new_a;
    return a;
}

//------------------------------------------------------------------------------------
Big_Int_General &operator*=(Big_Int_General &a , Big_Int_General b)
{
    a = a * b;
    return a;
}
Big_Int_General &operator*=(Big_Int_General &a , char c)
{
    a = a * c;
    return a;
}
Big_Int_General &operator*=(Big_Int_General &a , int c)
{
    a = a * c;
    return a;
}
Big_Int_General &operator*=(Big_Int_General &a , std::string s)
{
    a = a * s;
    return a;
}

//-----------------------------------------------------------------------DIVISION / & /=

Big_Int_General operator/(Big_Int_General a , Big_Int_General b)
{
    int base_a = a.get_base();
    int base_b = b.get_base();
    int base = base_a;

    if (base_a != base_b)
        throw std::runtime_error("Cannot divide numbers with different bases!");

    int len_a = a.get_size(), len_b = b.get_size();
    std::string s_a = a.get_digits(), s_b = b.get_digits();

    //Big_Int_General cat("0", base);
    std::string cat = "";
    Big_Int_General rest("0", base);
    std::string numar_formare = "";

    for (int i = 0; i < len_a; ++i) {
        numar_formare += s_a[i];
        int index = 0;
        while(numar_formare[index] == '0'){
            numar_formare.erase(numar_formare.begin());
        }
        Big_Int_General numar_formare_b(numar_formare , base) , s_b_b(s_b , base);
        if (numar_formare_b >= s_b_b) {
            int j;
            for (j = 0; j < base; ++j) {
                Big_Int_General rezultat_inmultire = b * j;

                // Compare the result of multiplication directly with numar_formare
                Big_Int_General numar_formare_b(numar_formare , base);
                if (rezultat_inmultire > numar_formare_b) {
                    break;
                }
            }

            // Decrease j because it went one step too far
            j--;
            // Update the quotient
            if (j >= 0 && j <= 9) {
                char cifra = char(j + '0');
                cat += cifra;
            } else {
                char cifra = char(j - 10 + 'a');
                cat += cifra;
            }

            // Update the remainder
            Big_Int_General rezultat = b * j;
            Big_Int_General s1(numar_formare, base);
            s1 -= rezultat;

            numar_formare = s1.get_digits();

        }
        else
        {
            //We need to add '0'
            cat += '0';
        }
    }

    // The final cat contains the quotient, and numar_formare contains the remainder

    Big_Int_General rezultat(cat , base);
    return rezultat;
}
Big_Int_General operator/(Big_Int_General a , char c)
{
    std::string str = {c};
    Big_Int_General new_big_int_general(str , a.get_base());
    a = a / new_big_int_general;

    return a;
}
Big_Int_General operator/(Big_Int_General a , std::string s)
{
    Big_Int_General new_a(s , a.get_base());
    a = a / new_a;
    return a;
}
Big_Int_General operator/(Big_Int_General a , int c)
{
    Big_Int_General new_a(std::to_string(c) , a.get_base());
    a = a / new_a;
    return a;
}
//-----------------------------------------------------------------------------------
Big_Int_General &operator/=(Big_Int_General &a , Big_Int_General b)
{
    a = a / b;
    return a;
}
Big_Int_General &operator/=(Big_Int_General &a , char c)
{
    a = a / c;
    return a;
}
Big_Int_General &operator/=(Big_Int_General &a , int c)
{
    a = a / c;
    return a;
}
Big_Int_General &operator/=(Big_Int_General &a , std::string s)
{
    a = a / s;
    return a;
}
Big_Int_General divide_by_2(Big_Int_General a)
{
    Big_Int_General two("2" , a.get_base());
    a = a / 2;
    return a;
}
//-----------------------------------------------------------------------MODULO
Big_Int_General operator%(Big_Int_General a , Big_Int_General b)
{
    Big_Int_General cat;
    cat = a / b;
    b = cat * b;
    Big_Int_General rest;
    rest = a - b;
    return rest;
}
Big_Int_General &operator%=(Big_Int_General &a , Big_Int_General b)
{
    a = a % b;
    return a;
}
Big_Int_General operator%(Big_Int_General a , int c)
{
    Big_Int_General new_a(std::to_string(c) , a.get_base());
    a = a % new_a;
    return a;
}
Big_Int_General &operator%=(Big_Int_General &a , int c)
{
    Big_Int_General new_a(std::to_string(c) , a.get_base());
    a = a % new_a;
    return a;
}

//-------------------------------------------------------------------------EDXPONANTION ^ & ^=
Big_Int_General operator^(Big_Int_General a, Big_Int_General b)
{
    Big_Int_General exponent , baza(a);
    exponent = b;
    a.set_digits("1");
    int base = a.get_base();

    while(!Null(exponent))
    {
        int numar;
        if(exponent[0] >= '0' && exponent[0] <= '9')numar = exponent[0] - '0';
        else numar = exponent[0] - 'a' + 10;
        if(numar & 1)
        {
            a *= baza;
        }
        baza *= baza;

        Big_Int_General div_2("2" , base);
        exponent /= div_2;

    }
    Big_Int_General rez(a);
    return rez;
}
Big_Int_General &operator^=(Big_Int_General& a , Big_Int_General b)
{
    a = a ^ b;
    return a;
}
Big_Int_General operator^(Big_Int_General a , int c)
{
    Big_Int_General new_a(std::to_string(c) , a.get_base());
    a = a ^ new_a;
    return a;
}
Big_Int_General &operator^=(Big_Int_General& a , int c)
{
    Big_Int_General new_a(std::to_string(c) , a.get_base());
    a = a ^ new_a;
    return a;
}

//---------------------------------------------------------------------------READING WRITING >> <<
std::istream &operator>>(std::istream &in , Big_Int_General &a)
{
    std::string s;
    std::cout << "Digits of the number : ";
    in >> s;
    std::cout << "\n";
    size_t size_s = s.size();

    int base;
    std::cout << "The base is : ";
    in >> base;

    std::string s_a;
    for(int i = 0 ; i < size_s ; ++i)
    {
        char cifra = s[i];
        if(cifra >= '0' && cifra <= '9')
        {
            int cifra_b = cifra - '0';
            if(cifra_b >= base)
                std::runtime_error("Numarul contine cifre ce nu sunt din baza data !");
        }
        else
        {
            int cifra_b = cifra - 'a' + 10;
            if(cifra_b >= base)
                std::runtime_error("Numarul contine cifre ce nu sunt din baza data !");

        }
        s_a += cifra;
    }
    int index = 0;
    while(s_a[index] == '0')
    {
        s_a.erase(s_a.begin() + index);
        ++index;
    }
    a.set_digits(s_a);
    return in;
}
std::ostream &operator<<(std::ostream &out , Big_Int_General &a)
{
    size_t size_of_big_int = a.get_size();
    std::string s_a = a.get_digits();
    std::cout << "The number is : ";
    for(int i = 0 ; i < size_of_big_int ; ++i)
        std::cout << s_a[i];
    std::cout << "\n";
    std::cout << "The base is : " << a.get_base() << "\n";
    return out;
}



/*
 * CONVERTING BASES
 */
static Big_Int_General big_int_general_to_10(Big_Int_General num) {
    // Convert a number in any base to base 10
    int base = num.get_base();
    std::string digits = num.get_digits();
    int result_base = 10;

    // Initialize result to 0 in base 10
    Big_Int_General result("0", result_base);

    // Iterate through each digit in the original base and accumulate in base 10
    size_t size_num = digits.size();
    for (int i = 0; i < size_num ; ++i) {
        char digit = digits[i];

        // Multiply the current result by the original base and add the digit value
        result *= base;
        result += digit;
    }

    return result;
}
static Big_Int_General base_10_to_big_int_general(Big_Int_General a, int new_base) {
    std::string result = "";

    while (a.get_digits() != "0" && a.get_digits().size() != 0) {
        Big_Int_General aux_a;
        aux_a = a % new_base;

        std::string digits_aux_a = aux_a.get_digits();

        if (digits_aux_a.size() == 1) {
            result += digits_aux_a;
        } else if(digits_aux_a.size() >= 2){
            int num = std::stoi(digits_aux_a);
            char num2 = num - 10 + 'a';

            result += num2;
        }

        Big_Int_General aux_new_base(std::to_string(new_base), 10);
        a = a / aux_new_base;
    }
    std::reverse(result.begin(), result.end());
    Big_Int_General aux(result, new_base);
    return aux;
}
static Big_Int_General source_base_destination_base(Big_Int_General a , int end_base)
{
    int initial_base = a.get_base();
    //initial_base -> base 10
    //bas 10 -> end_base

    Big_Int_General aux;
    aux = big_int_general_to_10(a);
    aux = base_10_to_big_int_general(aux , end_base);

    return aux;
}
static Big_Int_General karatsuba(Big_Int_General x , Big_Int_General y)
{
    /*
     * POOR PERFOMANCE
     */
    int base1 =x.get_base() , base2 = y.get_base();
    if(base1 != base2)std::runtime_error("Nu se pot inmulti numere in baze diferite!");

    int base = base1;
    Big_Int_General zece("10" , base);
    if (x.get_size() <= 1 || y.get_size() <= 1)
        return (x * y);//simple case

    int len1 = x.get_size() , len2 = y.get_size();
    int n;
    if(len1 >= len2)n = len1;
    else n = len2;
    Big_Int_General n_B(std::to_string(n) , base);

    Big_Int_General unu("1" , base),doi("2" , base), rest;

    int m_n = std::ceil(n / 2);
    Big_Int_General m(std::to_string(m_n) , base);
    Big_Int_General zece_m;
    zece_m = zece ^ m;

    Big_Int_General x_H;
    x_H = x / zece_m;

    Big_Int_General x_L;
    x_L = x % zece_m;

    Big_Int_General y_H;
    y_H = y / zece_m;

    Big_Int_General y_L(y);
    y_L = y % zece_m;

    //recursive steps
    Big_Int_General sum1 , sum2;
    Big_Int_General a , d , e;
    a = karatsuba(x_H , y_H);
    d = karatsuba(x_L , y_L);

    sum1 = x_H + x_L;
    sum2 = y_H + y_L;

    e = karatsuba(sum1  , sum2);
    e -= a;
    e -= d;

    Big_Int_General rezultat;
    Big_Int_General m_2;
    m_2 = m * doi;

    Big_Int_General auxx , auxx2;
    auxx = zece ^ m_2;//10 **(m*2)
    auxx2 = zece ^ m;
    sum1 = a * auxx;
    sum2 = e * auxx2;

    rezultat = sum1 + sum2;
    rezultat += d;

    return rezultat;
}

static void swap(Big_Int_General &a , Big_Int_General &b)
{
    Big_Int_General aux;
    aux = a;
    a = b;
    b = aux;
}
Big_Int_General pow(Big_Int_General a, Big_Int_General b)
{
    return (a ^ b);
}


Big_Int_General random_big_int(int max_length, int base) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    auto getRandomElement = [](const std::vector<char>& vec) {
        int randomIndex = std::rand() % vec.size();
        return vec[randomIndex];
    };

    std::vector<char> possible_digits;
    for (int i = 0; i < base; ++i)
        possible_digits.push_back(i < 10 ? i + '0' : i + 'a' - 10);

    std::string final_random_big_int;
    for (int i = 0; i < max_length; ++i) {
        final_random_big_int += getRandomElement(possible_digits);
    }

    return Big_Int_General(final_random_big_int);
}

Big_Int_General random_big_int(int max_length, int base , Big_Int_General max_number) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    auto getRandomElement = [](const std::vector<char>& vec) {
        int randomIndex = std::rand() % vec.size();
        return vec[randomIndex];
    };

    std::vector<char> possible_digits;
    for (int i = 0; i < base; ++i)
        possible_digits.push_back(i < 10 ? i + '0' : i + 'a' - 10);

    std::string final_random_big_int;
    for (int i = 0; i < max_length; ++i) {
        final_random_big_int += getRandomElement(possible_digits);
    }

    return Big_Int_General(final_random_big_int) % max_number;
}
static bool is_prime(Big_Int_General a)
{
    if(a.get_base() < 10)
        a = big_int_general_to_10(a);

    Big_Int_General zero("0" , a.get_base());
    Big_Int_General trei("3" , a.get_base());
    Big_Int_General doi("2" , a.get_base());
    Big_Int_General cinci("5" , a.get_base());
    Big_Int_General sase("6" , a.get_base());

    if(a <= trei)return (a >= doi);
    if(a % doi == zero)return false;
    if(a % trei == zero)return false;

    Big_Int_General aux("0" , a.get_base());
    aux = cinci * cinci;
    for(cinci ; aux <= a ; cinci += sase)
    {
        if(a % cinci == zero)return false;
        cinci += 2;
        if(a % cinci == zero)return false;
        cinci -= 2;

        aux = cinci * cinci;
    }
    return true;
}

static bool is_palindrom(Big_Int_General a)
{
    std::string digits = a.get_digits();
    unsigned long long int beg = 0, end = digits.length() - 1;
    while(beg < end) {
        if(digits[beg] != digits[end])
            return false;
        beg++;
        end--;
    }
    return true;
}

static Big_Int_General gcd(Big_Int_General a , Big_Int_General b)
{
    if(b > a)swap(b , a);

    Big_Int_General zero("0" , a.get_base());
    Big_Int_General temp;
    while(b != zero)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
static Big_Int_General lcm(Big_Int_General a , Big_Int_General b)
{
    return Big_Int_General((a * b) / gcd(a,b));
}

static Big_Int_General sqrt(Big_Int_General a)
{
    Big_Int_General l("0" , a.get_base());
    Big_Int_General r(a);

    Big_Int_General ans;

    while(l <= r)
    {
        Big_Int_General mid;
        mid = (l + r) / 2;
        if(mid * mid <= a)
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    return ans;
}

static Big_Int_General binary_division(Big_Int_General a , Big_Int_General b)
{
    //POOR PERFOMANCE
    
    Big_Int_General ans("0" , 2);
    Big_Int_General one("1" , 2);
    int initial_base = a.get_base();
    if(a.get_base() != 2)
    {
        a = source_base_destination_base(a , 2);
    }
    if(b.get_base() != 2)
    {
        b = source_base_destination_base(b , 2);
    }

    int a_len = a.get_size();
    int b_len = b.get_size();

    while(a_len > b_len)
    {
        std::string aux_s = "1";
        for(int i = 1 ; i <= a_len - b_len - 1;++i)
            aux_s += "0";
        //aux = one << (xlen - ylen - 1)
        Big_Int_General aux(aux_s , 2);
        ans += aux;
        //x -= y << (xlen - ylen - 1)

        aux_s = b.get_digits();

        for(int i = 1 ; i <= a_len - b_len - 1; ++i)
        {
            aux_s += "0";
        }

        Big_Int_General aux_b(aux_s , 2);

        a -= aux_b;
        a_len = a.get_size();
    }
    if(a >= b) {
        ans = source_base_destination_base(ans , initial_base);
        return ans + 1;
    }
    return source_base_destination_base(ans , initial_base);
}
static Big_Int_General xorOperation(Big_Int_General a , Big_Int_General b)
{
    Big_Int_General zero("0" , a.get_base());
    Big_Int_General one("1" , a.get_base());
    Big_Int_General two("2" , a.get_base());
    //Big_Int_General rez("0" , a.get_base());
    std::string rez;
    Big_Int_General aux;
    while(a != zero || b != zero)
    {
        aux = a % two + b % two;
        if(aux == one)rez += "1";
        else rez += "0";
        a /= two;
        b /= two;
    }
    //Now i need to rotate
    std::reverse(rez.begin(), rez.end());
    Big_Int_General ans(rez , 2);
    return source_base_destination_base(ans , a.get_base());
}
#endif //BIG_INT_FINAL_BIG_INT_GENERAL_H

