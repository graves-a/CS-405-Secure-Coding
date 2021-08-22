// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <exception>

// Custom exception
struct MyException : public std::exception
{
    const char* what() const throw ()
    {
        return "Alan's custom exception";
    }
};

bool do_even_more_custom_application_logic()
{
    class Polymorphic { virtual void member() {} };
    // TODO: Throw any standard exception
    try
    {
        Polymorphic* pb = 0;
        typeid(*pb);
    }
    catch (std::exception& e)
    {
        throw e;
    }
    
    return true;
}

void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try 
    {
        if (do_even_more_custom_application_logic())
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (std::exception& e) 
    {
        std::cout << "An error occured: " << e.what() << std::endl;
    }

    // TODO: Throw a custom exception derived from std::exception
    //  and catch it explictly in main    
    
    std::cout << "Leaving Custom Application Logic." << std::endl;

    int a = 0;
    if (a != 1) 
    {
        throw MyException();
    }
}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den== 0) 
    {
        throw std::overflow_error("Divide by zero exception");
        return (num / den);
    }    
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try 
    {
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (std::overflow_error& e) 
    {
        std::cout << e.what() << " -> ";
    }
    std::cout << numerator << " / " << denominator << std::endl;    
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
  
    do_division();
    try 
    {
        do_custom_application_logic();
    }
    catch (MyException& e)
    {
        std::cout << e.what() << std::endl;
    }    
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
//{"mode":"full", "isActive" : false}