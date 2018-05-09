// Helper functions for music

#include <cs50.h>
#include "helpers.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Converts a fraction formatted as X/Y to eighths
// I have tried to build this function at least 4 different ways. Every time I get
// "load of null pointer of type 'char'" as an error. It's been 6 hours. I'm done with this
int duration(string fraction)
{

    if(fraction[0] == '1')
    {
        if(fraction[2] == '8')
        {
            return 1;
        }
        else if(fraction[2] == '4')
        {
            return 2;
        }
        else if(fraction[2] == '2')
        {
            return 4;
        }
        else if(fraction[2] == '1')
        {
            return 8;
        }
    }
    else if(fraction[0] == '3' && fraction[2] == '8')
    {
        return 3;
    }
    else
    {
        return 0;
    }
    return 0;
}


// Calculates frequency (in Hz) of a note
int frequency(string note)
{
   int octave = note[strlen(note) - 1];
    octave -= 48;
    float freq = 0.0;

        // Checks which note letter it is and adjusts the frequency using A4, or 440hz, as a base
    switch (note[0])
    {
        case 'C':
            freq = 440.0 / pow(2.0, (9.0 / 12.0));
            break;

        case 'D':
            freq = 440.0 / pow(2.0, (7.0 / 12.0));
            break;

        case 'E':
            freq = 440.0 / pow(2, (5.0 / 12.0));
            break;

        case 'F':
            freq = 440.0 / pow(2.0, (4.0 / 12.0));
            break;

        case 'G':
            freq = 440.0 / pow(2.0, (2.0 / 12.0));
            break;

        case 'A':
            freq = 440.0;
            break;

        case 'B':
            freq = 440.0 * pow(2.0, (2.0 / 12.0));
            break;
    }

    // checks if the octave is lower or higher than 4, for base A4, and adjusts the frequency
    if (octave > 4)
    {
        int n = octave - 4;
        freq *= pow(2.0, n);
    }

    else if (octave < 4)
    {
        int n = 4 - octave;
        freq /= pow(2.0, n);
    }

    // Adjusts frequency if the note is sharp or flat
    if (note[1] == '#')
    {
        freq *= pow(2.0, (1.0 / 12.0));
    }

    else if (note[1] == 'b')
    {
        freq /= pow(2.0, (1.0 / 12.0));
    }

    // Rounds the frequency number to turn it from a float to an int
    int result = round(freq);
    return result;
}



// Determines whether a string represents a rest
bool is_rest(string s)
{
    // TODO
    if ( s[0] == '\n')
    {
        return true;
    }
    else
    {
        return false;
    }
}
