// Statistician.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// The statistician is a class that is designed to keep track of simple statistics about a 
// sequence of real numbers.  There are two member functions; 
//          next: is used to give a sequence of numbers that have been given to the statistician
//      one at a time.
//          mean: is a constant member funct that returns the mean/avg of all the numbers that
//      have been given to the statistician.

// We are using namespace main_savitch_2c

#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "stats.h"

using namespace std;

namespace main_savitch_2C
{
    /*
    // CONSTRUCTOR
        statistician();
        // MODIFICATION MEMBER FUNCTIONS
        void next(double r);
        void reset();
        // CONSTANT MEMBER FUNCTIONS
        int length() const;
        double sum() const;
        double mean() const;
        double minimum() const;
        double maximum() const;
        // FRIEND FUNCTIONS
        friend statistician operator +
            (const statistician& s1, const statistician& s2);
        friend statistician operator *
            (double scale, const statistician& s);
    private:
        int count;       // How many numbers in the sequence
        double total;    // The sum of all the numbers in the sequence
        double tinyest;  // The smallest number in the sequence
        double largest;  // The largest number in the sequence
    };

    // NON-MEMBER functions for the statistician class
    bool operator ==(const statistician& s1, const statistician& s2);

    */
    statistician::statistician()
    // reset the count and total 
    {
        count = 0;
        total = 0;

    }

    void statistician::next(double r)
    // Library facilities used: 
    {
        count++;
        total += r;
        if (count == 1)
            tinyest = largest = r;
        else {
            if (r < tinyest)
                tinyest = r;
            if (r > largest)
                largest = r;
        }

    }

    void statistician::reset()
    // Library facilities used: 
    {
        count = 0;
        total = 0;

    }

    int statistician::length() const
    // Library facilities used:
    {
        return count;

    }

    double statistician::sum() const
    // Library facilities used:
    {
        return total;

    }

    double statistician::mean() const
    // Library facilities used:
    {
        assert(length() > 0);
        return sum() / length();

    }

    double statistician::minimum() const
    // Library facilities used:
    {
        assert(length() > 0);
        return tinyest;

    }

    double statistician::maximum() const
    // Library facilities used:
    {
        assert(length() > 0);
        return largest;

    }

    // reference parameter, not pass by reference.  
    statistician operator + (const statistician& s1, const statistician& s2) 
    {
        if (s1.length() == 0)
        {
            return s2;

        }

        if (s2.length() == 0)
        {
            return s1;

        }

        statistician s;
        s.count = s1.length() + s2.length();
        s.total = s1.sum() + s2.sum();
        s.tinyest = (s1.minimum() < s2.minimum()) ? s1.minimum() : s2.minimum();
        s.largest = (s1.maximum() > s2.maximum()) ? s1.maximum() : s2.maximum();
        return s;
    }

    // passing values by reference aka value at address of statistician
    statistician operator * (double scale, const statistician& s) 
    {
        if (s.length() == 0)
        {
            return s;

        }
        // checking if s1 == 0, 
        statistician s1;
        s1.count = s.length();
        s1.total = s.sum() * scale;
        if (scale >= 0) 
        {
            s1.tinyest = s.minimum() * scale;
            s1.largest = s.maximum() * scale;

        }
        else 
        {
            s1.tinyest = s.maximum() * scale;
            s1.largest = s.minimum() * scale;

        }
        return s1;
    }

    bool operator == (const statistician& s1, const statistician& s2) 
    {
        if (s1.length() == 0 && s2.length() == 0)
        {
            return true;
        }
        return ((s1.length() == s2.length()) && (s1.sum() == s2.sum()) && 
            (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum()));

    }
    
}


/*

Running statistician tests:
TEST 1:
Testing next, reset, length, sum, and mean (62 points).
Test 1 passed.


TEST 2:
Testing minimum and maximum member functions (7 points).
Test 2 passed.


TEST 3:
Testing the + operator (7 points).
Test 3 passed.


TEST 4:
Testing the * operator (7 points).
Test 4 passed.


TEST 5:
Testing the == operator (7 points).
Test 5 passed.

If you submit the statistician to Dora now, this part of the
grade will be 90 points out of 90.

C:\Users\drdoo\Desktop\Current Classes\C++ Data Structures and Algorithms\Week 2, (9_9) Statistician Class\Statistician\Debug\Statistician.exe (process 18524) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


*/