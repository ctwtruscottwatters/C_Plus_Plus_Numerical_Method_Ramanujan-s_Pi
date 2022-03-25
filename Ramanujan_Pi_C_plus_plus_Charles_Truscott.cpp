// I_love_MIT.cpp 
// Authored by Charles Thomas Wallace Truscott (Watters) Byron Bay NSW 2481
// Visual Studio 2019 compiler

#include <iostream>
#include <stdlib.h>
#include <math.h>

long int factorial(long int num);
long double find_square_root(long double number_squared);
long double return_pi_from_the_ramanujan_approx();
double calculate_sine();
double differentiate_value_to_find_cosine();
double differentiate_value_to_find_tangent();
using namespace std;
int main()
{
    long double squared = 2.0;
    long double square_root_of_two = find_square_root(squared);
    std::cout << "Two squared is: " << square_root_of_two * square_root_of_two << " via square root " << square_root_of_two << std::endl;
   //  cout >> "Enter a value to find the sine for (in degrees):\t";
    return_pi_from_the_ramanujan_approx();
    return 0;

}

long int factorial(long int num) {
    int i;
    int j = 1;
    int k;

    if (num <= 0) {
        return 1;
    }
    else {
        for (i = 1; i <= num; ++i) {
            j *= i;
        }
    }
    return j;
}
long double find_square_root(long double number_squared) {

    long double square = number_squared;
    long double high = square;
    long double low = 0.0;
    long double guess = (high - low) / 2.0;
    long double epsilon = 0.0000001;
        while (abs((guess * guess) - square) >= epsilon) {
            std::cout << "High: " << high << " Low: " << low << " Guess: " << guess << std::endl;
            if ((((((high + low) / 2.0)) * ((high + low) / 2.0))) > square) {
                high = guess;
            }
            else if ((((((high + low) / 2.0)) * ((high + low) / 2.0))) < square) {
                low = guess;
                }
            guess = ((high + low) / 2.0);
    }
    
    return guess;
}
// Integer overflow after 3 iterations, damn, Python does  this that much better
// Charles Truscott 5:56 P.M. 25/03/2022
// Ramanujan's infinite series for Pi in C++ and Python
// Niche aspects of Microsoft C++

long double return_pi_from_the_ramanujan_approx() {
    long double x = 2 * find_square_root(2);
    long double y = 9801;
    long double z = 0.00000000;
    long int summation = 1;
    for (long int i = 0; i <= 1; i++) {
        long int four_times_i = 4 * i;
        long int factorial_of_i = factorial(i);
        long int numerator_part_one = factorial(four_times_i);
        cout << "First part of numerator " <<  numerator_part_one << endl;
        long int numerator_part_two = 1103 + (26390 * i);
        cout << "Second part of numerator " << numerator_part_two << endl;
        long long numerator_together = (numerator_part_one) * (numerator_part_two);
        std::cout << numerator_together << std::endl;
        long int denominator_part_one = pow(factorial_of_i, 4);
        cout << "First part of denominator " << denominator_part_one << endl;
        int64_t denominator_part_two = abs(pow(396, four_times_i));
        cout << "Second part of denominator " << denominator_part_two << endl;
        long long denominator_together = (denominator_part_one) * (denominator_part_two);
        std::cout << denominator_together << std::endl;
        summation += abs((abs((numerator_together)) / abs((denominator_together))));
        //std::cout << summation << std::endl;

    }
    z = (x / y) * summation;
    std::cout << "z equals " << z << std::endl;
    z = 1.0 / z;
    std::cout << "Pi is approximately: " << z << std::endl;
    return z;

}
