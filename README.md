    print('MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM')
    print('MMMMMMMMMMMMMMWNXKOOONMMMMMMMMMMMMM')
    print('MMMMMMMMMMNkl:; .. ,,:lkWMMMMMMMMMM')
    print('MMMMMMMMXo' ',......... KMMMMMMMMM')
    print('MMMMMMMX..lkO0K0Okxdooc  ;NMMMMMMMM')
    print('MMMMMMMx.okkOO0KKK0Okxxd,.:XMMMMMMM')
    print('MMMMMMMx.oxkkOO0KK0Okxxo, .KMMMMMMM')
    print('MMMMMMM0.cxxdollddlllooo, .XMMMMMMM')
    print('MMMMMMMWdcoc:;;,ll,;;:cl:.xMMMMMMMM')
    print('MMMMMMMMNxxxxddokOldxxdoocXMMMMMMMM')
    print('MMMMMMMMWkddxddl:;;ooolllkWMMMMMMMM')
    print('MMMMMMMMMXdlllcc:::cclc:dWMMMMMMMMM')
    print('MMMMMMMMMMKlcoddooodoc;;KMMMMMMMMMM')
    print('MMMMMMMMMMWd:;:c::;;,'':co0NMMMMMMM')
    print('MMMMMN0xoc.:k:,,,.....ckc ...cdOXWM')
    print('XOkd:..... :KKkl;'';lk0Oo ........:')
    print('...........:NXNXc..;OXKKl  ...   ..')
    print('....  .....,NN0l,..,coKKo   ..     ')
    print('...    ....;NKO0:..0KOkXk   .....  ')
    print('    .......:WWW0...OWWWWO.  ....   ')
    print('    .......:WWWo...cWWWWK.. ....   ')
    print('     ......cWW0.....XWWWN.. ....   ')
    print('     ..... lWWc.....OWWWW,. ...   ')

# Big-Int---base-36
Class for Big Int - Base 36

DOCUMENTATION FOR Big_Int_General class
IT TAKES UP TO CLASS 36 (10 digits and 26 latin characters)

 HOW TO USE IT - CONSTRUCTORS
 Big_Int_General - first parameter is a string with the digits of a number
                 - second parameter is the base of that number
  ------- EXEMPLES:
  Big_Int_General a("123" , 10); - it is the number 123 in base 10
  Big_Int_General b("e3d" , 16); - it is the number e3d(3645) in base 16

-------------------------------------------------------------------------
--------------------------CLASS METHODS----------------------------------

Big_Int_General a("123" , 10);
std::string digits_of_a = a.get_digits();
int base_of_a = a.get_base();

a.set_digits("1234") - now a will have digits 1234
a.set_base(16) - now a will have base 16

---------------------------------------------------------------------------
-----------------------------OPERATORS-------------------------------------

1.Arithmetic operators
EVERY OPERATOR IS IMPLEMENTED - ( + , += , - , -= , * , *= , / , /= )

You can do :- Big_Int_General + Big_Int_General
            - Big_Int_General + char
            - Big_Int_General + int
            - Big_Int_General + std::string
    And by plus I mean every operation

2.Bool operathors
EVERY OPERATOR IS IMPLEMENTED - ( > , >= , < , <= , == , != )

You can do only between 2 Big_Int_General

3.Operathor []
Big_Int_General a("abcd");

char character = a[1]; -> character = 'b'

4.Operathor Null
Checks if it is empty or if it is equal to 0

5.Operator modulo
IMPLEMENTED % , %=

You can do :
            - Big_Int_General % Big_Int_General
            - Big_Int_General % int

6.Operator exponantiation
IMPLEMENTED ^ , ^=

You can do :
            - Big_Int_General % Big_Int_General
            - Big_Int_General % int

7.Operators for input and output
I would say to do it manually because it is more intuitvely for you , but i implemented it

IMPLEMENTED >> , <<

-------------------------------------------------------------------
--------------------------CONVERSIONS------------------------------

There are 3 functions implemented :
static Big_Int_General big_int_general_to_10(Big_Int_General);

This function takes a parameter of Big_Int_General and it converts its digits
to base 10

static Big_Int_General base_10_to_big_int_general(Big_Int_General , int);

This function takes a parameter of Big_Int_General that is in base 10 and
converts its digits to the new base

static Big_Int_General source_base_destination_base(Big_Int_General , int);

This function takes a parameter of Big_Int_General and a parameter NEW_BASE
and convert from the original base to the new base

--------------------------------------------------------------------------
----------------------------AUXILIARY FUNCTIONS---------------------------
1.Pow function
static Big_Int_General pow(Big_Int_General , Big_Int_General);

It just makes a ^ b

2.Swap function
static void swap(Big_Int_General &, Big_Int_General &);

Simple swap function

3.Karatsuba and Binary Division
They pass the tests but these are very inefficient in term of time

4.Function to check the primality
static bool is_prime(Big_Int_General);

It has a relatively fast implementation , i don't have the SIEVE YET

5.Function to check palindrome
static bool is_palindrome(Big_Int_General);

6.Functions for competitive programming i suppose
static Big_Int_General gcd(Big_Int_General , Big_Int_General);
It implements the greatest commond divisor

static Big_Int_General lcm(Big_Int_General , Big_Int_General);
It implements the least common multiplier

static Big_Int_General sqrt(Big_Int_General);
It implements the sqrt basicfunction

static Big_Int_General xorOperation(Big_Int_General a , Big_Int_General b);
It just makes them in base 2 and then xor's them
The result will be in the initial base
