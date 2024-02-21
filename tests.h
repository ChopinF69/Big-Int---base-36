//
// Created by lazar on 26.01.2024.
//

#ifndef BIG_INT_FINAL_TESTS_H
#define BIG_INT_FINAL_TESTS_H
#include "big_int_general.h"
#include <functional>
// Define a structure to represent a test case
struct TestCase {
    std::function<void()> testFunction;
    std::string testName;
};

// Define a structure to represent the test results
struct TestResults {
    int totalTests = 0;
    int passedTests = 0;
};

// Define a function to run a single test case
void runTest(const TestCase& testCase, TestResults& results) {
    std::cout << "Running test: " << testCase.testName << " ... ";
    try {
        testCase.testFunction();
        std::cout << "Passed" << std::endl;
        results.passedTests++;
    } catch (const std::exception& e) {
        std::cout << "Failed: " << e.what() << std::endl;
    } catch (...) {
        std::cout << "Failed: Unknown exception" << std::endl;
    }
    results.totalTests++;
}

// Define a macro for writing test cases
#define TEST(testName) \
    void testName(); \
    TestCase testName##TestCase{testName, #testName}; \
    void testName()

// Define an assertion macro
#define ASSERT(condition) \
    if (!(condition)) throw std::runtime_error("Assertion failed: " #condition);

// Example of using the testing framework
TEST(MyTest) {
    ASSERT(1 + 1 == 2)
    ASSERT(2 * 2 == 4)
}

TEST(AnotherTest) {
    ASSERT(3 - 1 == 2)
}
TEST(Constructor_gol)
{
    Big_Int_General a;
    std::string digits_a = a.get_digits();
    int base = a.get_base();

    ASSERT(digits_a == "0")
    ASSERT(base == 10)
}
TEST(Constructor_only_string)
{
    Big_Int_General a("1234");

    std::string digits = a.get_digits();
    int base = a.get_base();

    ASSERT(digits == "1234")
    ASSERT(base == 5)


    Big_Int_General b("abcdef");
    digits = b.get_digits();
    base = b.get_base();

    ASSERT(digits == "abcdef")
    ASSERT(base == 16)


    Big_Int_General c("01"); // asta merge
    ASSERT(c.get_digits() == "1")

    Big_Int_General d("010"); // merge
    ASSERT(d.get_digits() == "10")
}
TEST(Constructor_string_base)
{
    Big_Int_General a("1239" , 10);

    ASSERT(a.get_digits() == "1239")
    ASSERT(a.get_base() == 10)

    Big_Int_General b("010" , 10);

    ASSERT(b.get_digits() == "10")
    ASSERT(b.get_base() == 10)

    Big_Int_General c("0000" , 10);
    ASSERT(c.get_digits() == "0")
    ASSERT(c.get_base() == 10)
}
TEST(Constructor_another_Big_Int_General)
{
    Big_Int_General a("134" , 10);
    Big_Int_General b(a);

    std::string digits = b.get_digits();
    int base = b.get_base();

    ASSERT(digits == "134")
    ASSERT(base == 10)
}

TEST(Null_function)
{
    Big_Int_General a("0");

    bool ok = Null(a);

    ASSERT(ok == true)
}

TEST(Operator_paranthesis_index)
{
    Big_Int_General a("abcd");

    char c = a[2];

    ASSERT(c == 'c')
}

/*
 * ------------BOOL OPERATORS
 */

TEST(Operator_equal)
{
    Big_Int_General a("abcdef") , b("abcdef" , 16);

    bool ok = (a == b);

    ASSERT(ok == true)

    Big_Int_General c("00000" , 10) , d("0" , 10);

    ok = (c == d);

    ASSERT(ok == true)
}

TEST(Operator_not_equal)
{
    Big_Int_General a("abc" , 16) , b("abcdef");

    bool ok = (a != b);

    ASSERT(ok == true)
}

TEST(Operator_strictly_greater)
{
    Big_Int_General a("abc" , 16) , b("a01" , 16);

    bool ok = (a > b);

    ASSERT(ok == true)
}

TEST(Operator_strictly_smaller)
{
    Big_Int_General a("a01" , 16) , b("abc" , 16);

    bool ok = (a < b);

    ASSERT(ok == true)
}

TEST(Operator_bigger_or_equally)
{
    Big_Int_General a("101" , 16) , b("101" , 16);

    bool ok = (a >= b);

    ASSERT(ok == true)
}

TEST(Operator_smaller_or_equally)
{
    Big_Int_General a("abcdef") , b("abcdef" , 16);

    bool ok = (a <= b);

    ASSERT(ok == true)
}

/*
 * ----------ARHITMETIC OPERATORS
 */
TEST(Operator_plus)
{
    Big_Int_General a("123" , 10) , b("232" , 10);

    Big_Int_General sum;

    sum = a + b;

    ASSERT(sum.get_digits() == "355")
    ASSERT(sum.get_base() == 10)

    Big_Int_General c("adf2" , 16) , d("fbc" , 16);

    sum = c + d;

    ASSERT(sum.get_digits() == "bdae")
    ASSERT(sum.get_base() == 16)
}
TEST(Operator_plus_equal)
{
    Big_Int_General a("123" , 10) , b("232" , 10);

    a+= b;

    ASSERT(a.get_digits() == "355")
    ASSERT(a.get_base() == 10)

    Big_Int_General c("adf2" , 16) , d("fbc" , 16);

    c += d;

    ASSERT(c.get_digits() == "bdae")
    ASSERT(c.get_base() == 16)
}

TEST(Operator_minus)
{
    Big_Int_General a("100" , 10) , b("1" , 10);
    Big_Int_General difference;

    difference = a - b;

    ASSERT(difference.get_digits() == "99")
    ASSERT(difference.get_base() == 10)

    Big_Int_General c("bdae" , 16) , d("fbc" , 16);

    difference = c - d;

    ASSERT(difference.get_digits() == "adf2")
    ASSERT(difference.get_base() == 16)
}

TEST(Operator_minus_equal)
{
    Big_Int_General a("100" , 10) , b("1" , 10);
    a -= b;

    ASSERT(a.get_digits() == "99")
    ASSERT(a.get_base() == 10)

    Big_Int_General c("bdae" , 16) , d("fbc" , 16);

    c -= d;

    ASSERT(c.get_digits() == "adf2")
    ASSERT(c.get_base() == 16)
}

TEST(Operator_multiplication)
{
    Big_Int_General a("abcde" , 16) , b("a2" , 16);
    Big_Int_General mult;

    mult = a * b;

    ASSERT(mult.get_digits() == "6cb847c")
    ASSERT(mult.get_base() == 16)

    Big_Int_General a_1("3" , 10) , b_1("0" , 10);

    mult = a_1 * b_1;
    ASSERT(mult.get_digits() == "0")
    ASSERT(mult.get_base() == 10)
}

TEST(Operator_multiplication_equal)
{
    Big_Int_General a("abcde" , 16) , b("a2" , 16);

    a *= b;

    ASSERT(a.get_digits() == "6cb847c")
    ASSERT(a.get_base() == 16)
}

TEST(Operator_division)
{
    Big_Int_General a("6cb847c" , 16) , b("a2" , 16);
    Big_Int_General div;

    div = a / b;

    ASSERT(div.get_digits() == "abcde")
    ASSERT(div.get_base() == 16)

    Big_Int_General x("0000160" , 10) , y("16" , 10);

    div = x / y;
    ASSERT(div.get_digits() == "10")
    ASSERT(div.get_base() == 10)
}
TEST(Operator_division_equal)
{
    Big_Int_General a("6cb847c" , 16) , b("a2" , 16);

    a /= b;

    ASSERT(a.get_digits() == "abcde")
    ASSERT(a.get_base() == 16)
}
TEST(Operator_plus_with_char)
{
    Big_Int_General a("a" , 16);
    char c = '7';
    a = a + c;

    ASSERT(a.get_digits() == "11")
    ASSERT(a.get_base() == 16)
}
TEST(Operator_plus_equal_with_char)
{
    Big_Int_General a("a" , 16);
    char c = '7';
    a += c;

    ASSERT(a.get_digits() == "11")
    ASSERT(a.get_base() == 16)
}

TEST(Ridicare_putere)
{
    Big_Int_General a("10" , 10) , b("2" , 10);
    Big_Int_General rez;
    rez = a ^ b;
    ASSERT(rez.get_digits() == "100")
    ASSERT(rez.get_base() == 10)

    Big_Int_General a_1("10" , 10) , b_1("1" , 10);
    rez = a_1 ^ b_1;
    ASSERT(rez.get_digits() == "10")
    ASSERT(rez.get_base() == 10)
}

//SCHIMBARI BAZE ---------
TEST(Big_Int_General_to_10)
{
    Big_Int_General a("aef" , 16);

    Big_Int_General rez ;
    rez = big_int_general_to_10(a);

    ASSERT(rez.get_digits() == "2799")
    ASSERT(rez.get_base() == 10)

    Big_Int_General b("adfe23" , 16);

    rez = big_int_general_to_10(b);

    ASSERT(rez.get_digits() == "11402787")
    ASSERT(rez.get_base() == 10)
}
TEST(Base_10_to_Big_Int_General)
{
    Big_Int_General a("2799" , 10);
    Big_Int_General rez;
    rez = base_10_to_big_int_general(a , 16);
    ASSERT(rez.get_digits() == "aef")
    ASSERT(rez.get_base() == 16)
}

TEST(Operator_modulo)
{
    Big_Int_General a("a" , 16) , b("3" , 16);

    Big_Int_General rez;

    rez = a % b;

    ASSERT(rez.get_digits() == "1")
    ASSERT(rez.get_base() == 16)

    Big_Int_General c("10" , 10) , d("16" , 10);

    rez = c % d;

    ASSERT(rez.get_digits() == "10")
    ASSERT(rez.get_base() == 10)

    Big_Int_General x("10" , 10) , y("10" , 10);

    rez = x % y;

    ASSERT(rez.get_digits() == "0")
    ASSERT(rez.get_base() == 10)
}

TEST(Static_base_10_to_big_int_general)
{
    Big_Int_General a("11402787" , 10);
    Big_Int_General rez ;
    rez = base_10_to_big_int_general(a , 16);

    ASSERT(rez.get_digits() == "adfe23")
    ASSERT(rez.get_base() == 16)

}
TEST(Static_Big_Int_General_to_10)
{
    Big_Int_General a("adfe" , 16);
    Big_Int_General rez;
    rez = big_int_general_to_10(a);
    ASSERT(rez.get_digits() == "44542")
    ASSERT(rez.get_base() == 10)

    Big_Int_General a_1("abcf4325f");
    rez = big_int_general_to_10(a_1);

    ASSERT(rez.get_digits() == "46119793247")
    ASSERT(rez.get_base() == 10)
}

TEST(Static_one_base_to_another)
{
    Big_Int_General a("ff" , 16) , aux;
    aux = source_base_destination_base(a , 2);

    ASSERT(aux.get_digits() == "11111111")
    ASSERT(aux.get_base() == 2)

    Big_Int_General a_1("afd3" , 16);
    aux = source_base_destination_base(a_1 , 8);

    ASSERT(aux.get_digits() == "127723")
    ASSERT(aux.get_base() == 8)
}

TEST(Karatsuba)
{
    Big_Int_General a("1" , 10) , b("2" , 10);
    Big_Int_General rez;
    rez = karatsuba(a , b);
    ASSERT(rez.get_digits() == "2")
    ASSERT(rez.get_base() == 10)

    Big_Int_General a_1("123" , 10) , b_1("3" , 10);
    rez = karatsuba(a_1 , b_1);
    ASSERT(rez.get_digits() == "369")
    ASSERT(rez.get_base() == 10)

    Big_Int_General a_2("abc" , 16) , b_2("2" , 16);
    rez = karatsuba(a_2 , b_2);
    ASSERT(rez.get_digits() == "1578")
    ASSERT(rez.get_base() == 16)

    Big_Int_General a_3("0" , 10) , b_3("0" , 10);
    rez = karatsuba(a_3 , b_3);
    ASSERT(rez.get_digits() == "0")
    ASSERT(rez.get_base() == 10)

    Big_Int_General a_4("abc23" , 16) , b_4("df34" , 16);
    rez = karatsuba(a_4 , b_4);
    ASSERT(rez.get_digits() == "95c10b41c")
    ASSERT(rez.get_base() == 16)
}
TEST(Swap_void)
{
    Big_Int_General a("123" , 10) , b("12" , 10);
    swap(a , b);
    ASSERT(a.get_digits() == "12")
    ASSERT(a.get_base() == 10)
    ASSERT(b.get_digits() == "123")
    ASSERT(b.get_base() == 10)
}
TEST(Pow)
{
    Big_Int_General a_1("2" , 10) ,  b_1("3" , 10);
    Big_Int_General rez;
    rez = pow(a_1 , b_1);

    ASSERT(rez.get_digits() == "8")
    ASSERT(rez.get_base() == 10)

    Big_Int_General a_2("3" , 10) , b_2("0" , 10);
    rez = pow(a_2 , b_2);

    ASSERT(rez.get_digits() == "1")
    ASSERT(rez.get_base() == 10)

    //test puternic
    Big_Int_General a_3("abcd" , 16) , b_3("3" , 16);
    rez = pow(a_3 , b_3);
    ASSERT(rez.get_digits() == "4d5fc3689dd5")
    ASSERT(rez.get_base() == 16)
}
TEST(Prim)
{
    Big_Int_General a_1("2" , 10);
    bool ok = is_prime(a_1);
    ASSERT(ok == true) // merge

    Big_Int_General a_2("69" , 10);
    ok = is_prime(a_2);
    ASSERT(ok == false) //merge

    Big_Int_General a_4("67" , 10);
    ok = is_prime(a_4);
    ASSERT(ok == true)

    Big_Int_General a_3("3f1",16);
    ok = is_prime(a_3);
    ASSERT(ok==true)
}
TEST(Palindrom)
{
    Big_Int_General a("1221" , 10);
    bool ok = is_palindrom(a);

    ASSERT(ok == true)

    Big_Int_General b("1223" , 10);
    ok = is_palindrom(b);

    ASSERT(ok == false)

    Big_Int_General c("1ff4" );
    ok = is_palindrom(c);

    ASSERT(ok == false)


    Big_Int_General d("1ff1");
    ok = is_palindrom(d);

    ASSERT(ok == true)
}
TEST(Gcd)
{
    Big_Int_General a("6" , 10) , b("12" , 10);
    Big_Int_General GCD;

    GCD = gcd(a , b);

    ASSERT(GCD.get_digits() == "6")
    ASSERT(GCD.get_base() == 10)

    Big_Int_General a_2("168" , 10) , b_2("124" , 10);

    GCD = gcd(a_2 , b_2);

    ASSERT(GCD.get_digits() == "4")
    ASSERT(GCD.get_base() == 10)

    Big_Int_General a_3("400" , 16) , b_3("200" , 16);

    GCD = gcd(a_3 , b_3);

    ASSERT(GCD.get_digits() == "200")
    ASSERT(GCD.get_base() == 16)

    Big_Int_General a_4("20d7e" , 16) , b_4("fc7B8a" , 16);

    GCD = gcd(a_4 , b_4);

    ASSERT(GCD.get_digits() == "20d7e")
    ASSERT(GCD.get_base() == 16)
}
TEST(Lcm)
{
    Big_Int_General a("10" , 10) , b("4" , 10);
    Big_Int_General LCM;

    LCM = lcm(a , b);

    ASSERT(LCM.get_digits() == "20")
    ASSERT(LCM.get_base() == 10)

    Big_Int_General a_1("12D593" , 16) , b_1("A081D" , 16);

    LCM = lcm(a_1 , b_1);

    ASSERT(LCM.get_digits() == "bcf08cc9a7")
    ASSERT(LCM.get_base() == 16)
}
TEST(Sqrt)
{
    Big_Int_General a("25" , 10);

    ASSERT(sqrt(a).get_digits() == "5")
    ASSERT(sqrt(a).get_base() == 10)

    Big_Int_General a_1("100" , 10);
    ASSERT(sqrt(a_1).get_digits() == "10")

    Big_Int_General a_2("38de2a941" , 16);
    //1E2A1
    ASSERT(sqrt(a_2).get_digits() == "1e2a1")
}

TEST(Binary_division)
{
    Big_Int_General a_1("10" , 10) , b_1("2" , 10);
    Big_Int_General ans;
    ans = binary_division(a_1 , b_1);

    ASSERT(ans.get_digits() == "5")
    ASSERT(ans.get_base() == 10)

    Big_Int_General a_2("69" , 10) , b_2("3" , 10);

    ans = binary_division(a_2 , b_2);

    ASSERT(ans.get_digits() == "23")
    ASSERT(ans.get_base() == 10)

    Big_Int_General a_3("38C5326F0" , 16) , b_3("1E246" , 16);

    ans = binary_division(a_3 , b_3);

    ASSERT(ans.get_digits() == "1e228")
    ASSERT(ans.get_base() == 16)
}

TEST(XOR_Operation)
{
    Big_Int_General a_1("100" , 2) , b_1("101" , 2);
    Big_Int_General ans;
    ans = xorOperation(a_1 , b_1);

    ASSERT(ans.get_digits() == "1")
    ASSERT(ans.get_base() == 2)

    Big_Int_General a_2("aef" , 16) , b_2("fde" , 16);

    ans = xorOperation(a_2 , b_2);
    ASSERT(ans.get_digits() == "531")
    ASSERT(ans.get_base() == 16)

    Big_Int_General a_3("8ff86bc5f4e376d" , 16), b_3("aa74db28738fa97ca785" , 16);

    ans = xorOperation(a_3 , b_3);

    ASSERT(ans.get_digits() == "aa74d3d7f533f63290e8")
    ASSERT(ans.get_base() == 16)

}

// Define a function to run all test cases
TestResults runAllTests() {
    TestResults results;
    runTest(MyTestTestCase, results);
    runTest(AnotherTestTestCase, results);
    runTest(Constructor_golTestCase , results);
    runTest(Constructor_only_stringTestCase , results);
    runTest(Constructor_string_baseTestCase , results);
    runTest(Constructor_another_Big_Int_GeneralTestCase , results);


    runTest(Null_functionTestCase , results);
    runTest(Operator_paranthesis_indexTestCase , results);


    runTest(Operator_equalTestCase , results);
    runTest(Operator_not_equalTestCase , results);


    runTest(Operator_strictly_greaterTestCase , results);
    runTest(Operator_strictly_smallerTestCase , results);
    runTest(Operator_bigger_or_equallyTestCase, results);
    runTest(Operator_smaller_or_equallyTestCase , results);


    runTest(Operator_plusTestCase , results);
    runTest(Operator_plus_equalTestCase , results);
    runTest(Operator_plus_with_charTestCase , results);
    runTest(Operator_plus_equal_with_charTestCase,results);


    runTest(Operator_minusTestCase , results);
    runTest(Operator_multiplicationTestCase , results);
    runTest(Operator_multiplication_equalTestCase, results);
    runTest(Operator_division_equalTestCase ,results);
    runTest(Ridicare_putereTestCase , results);

    runTest(Big_Int_General_to_10TestCase ,results);
    runTest(Base_10_to_Big_Int_GeneralTestCase , results);

    runTest(Operator_moduloTestCase , results);

    runTest(Static_base_10_to_big_int_generalTestCase , results);
    runTest(Static_one_base_to_anotherTestCase , results);
    runTest(Static_Big_Int_General_to_10TestCase , results);
    runTest(KaratsubaTestCase ,results);

    //VOID
    runTest(Swap_voidTestCase,results);

    //Pow
    runTest(PowTestCase , results);

    //prim
    runTest(PrimTestCase , results);

    //palindrom
    runTest(PalindromTestCase , results);

    //gcd & lcm
    runTest(GcdTestCase ,results);
    runTest(LcmTestCase , results);

    //sqrt
    runTest(SqrtTestCase , results);

    //binary division
    runTest(Binary_divisionTestCase , results);

    //xor
    runTest(XOR_OperationTestCase , results);
    return results;
}

#endif //BIG_INT_FINAL_TESTS_H