//  stacks_for_regular_languages.
//  Created by Dylan Alvarez on 6/19/18.

#include <iostream>
#include <cstring>
#include <string>
#include "stack_p1.h"
using namespace std;
#ifndef stacks_for_regular_languages_h
#define stacks_for_regular_languages_h

class stacks_for_regular_languages
{
public:
    bool L1(char * inputString);
    bool L2(char * inputString);
    bool L3(char * inputString);
    bool L4(char * inputString);
};

bool stacks_for_regular_languages::L1(char * inputString)
{
    stack_p1<char> s;
    int stringLength = strlen(inputString);
    if(inputString[0] == NULL) return false; //If its the empty string, return false;

    for(int i = 0; i < stringLength; i++)
    {
        if(s.isEmpty())
        {
            s.push(inputString[i]);
        }
        else if(s.peek() == inputString[i])
        {
            s.push(inputString[i]);
        }
        else 
        {
            s.pop();
        }
        
    }
    if(s.isEmpty())
    {
        return true;
    }
    else{
        return false;
    }

}

bool stacks_for_regular_languages::L2(char* inputString)
{

    stack_p1<char> patternStack;
    int stringLength = strlen(inputString);
    int i = 1;

    //push first letter on stack
    if(inputString[0] != NULL)
    {
        patternStack.push(inputString[0]);
    }
    //else return true; //For the empty string case, #A's == #B's

    while(patternStack.peek() == inputString[i])
    {
        patternStack.push(inputString[i++]);
    }
    
//Once there's a boundry, I.E where the B's are
    for(; i < stringLength; i++)
    {
               
        if(patternStack.peek() != inputString[i]) //If the character is the same as the one before it, push it
        {
            if(patternStack.peek() != NULL) 
            {
                patternStack.pop();
            }
            else //This means there were more B's than A's 
            {
                return false;
            }
        }

        else if(patternStack.peek() == inputString[i]) //2nd boundry, means the pattern is not in L2
        {
           return false;
        }
        
    }

    //If the pattern stack is empty, it means the pattern was correct (symmetrical)
    if(patternStack.isEmpty())
    {
       
        return true;
    }
    else //This means there were more A's than B's
    {
        return false;
    }

}

bool stacks_for_regular_languages::L3(char* inputString)
{

    if(stacks_for_regular_languages::L2(inputString)) //If it passes 2, it passes three, including the empty string case
    {
        return true;
    }

    //if it fails L2 (aka it is a repeating pattern, then it can still work)

    stack_p1<char> patternStack;
    stack_p1<char> testStack;
    stack_p1<char> currentStack;
    bool patternReady = false;
    int stringLength = strlen(inputString);
    string testString = "";

    int i = 1;

    //push first letter on stack
    if(inputString[0] != NULL)
    {
        patternStack.push(inputString[0]);
    }

    while(patternStack.peek() == inputString[i])
    {
        patternStack.push(inputString[i++]);
    }

    if(patternStack.peek() != inputString[i] && i < stringLength) //Put that first B on the stack, only if there is another letter to put on it
    {
        patternStack.push(inputString[i++]);
    }
    else 
    {
        return false;
    }
    
    
//Once there's a boundry
    for(; i < stringLength; i++)
    {
        if(!patternReady) //Build the pattern stack
        {
            
            if(patternStack.peek() == inputString[i]) //If the character is the same as the one before it, push it (Push the B's on)
            {
                patternStack.push(inputString[i]);
            }
            else if(patternStack.peek() != inputString[i]) //2nd boundry
            {
                i--;
                testStack = patternStack;
                
                
                while(!testStack.isEmpty()) //Use a test stack to push the pattern to a string to test if its a valid pattern. A non valid pattern is ABB
                {
                    
                    testString += testStack.pop();
                    
                }
                
                //Convert testString
                const char* testCString = testString.c_str();
                int cStringLength = strlen(testCString);
                char* testCCString = new char[cStringLength];
                strcpy(testCCString, testCString); //Convert the c string to a char*
                
                if(!stacks_for_regular_languages::L2(testCCString)) //if the pattern isnt valid, just return false ABABABAA
                {
                    return false;
                }

                patternReady = true;
            }
            
            
        }
        else //We have our pattern in a stack to compare every other pattern with now
        {

            if(currentStack.isEmpty()) //Refill current stack with copy of pattern stack, then give it the same options as if it were full to begin with 
            {
                currentStack = patternStack;
                i--; //repeat again but with a full stack

            }
            else if(currentStack.peek() != inputString[i]) //This should always keep popping the pattern off due to the way its set up
            {
                    currentStack.pop();
            }
            else //Invalid pattern
            {
                return false;
            }
        }
        
    }

    if(!patternReady) //Handles the BBAAA case where you never see that second boundry but its still incorrect
    {
        testStack = patternStack;
                
        while(!testStack.isEmpty()) //Use a test stack to push the pattern to a string to test if its a valid pattern. A non valid pattern is ABB
        {
            testString += testStack.pop();
        }
        
        //Convert testString
        const char* testCString = testString.c_str();
        int cStringLength = strlen(testCString);
        char* testCCString = new char[cStringLength];
        strcpy(testCCString, testCString); //Convert the c string to a char*
        
        if(!stacks_for_regular_languages::L2(testCCString)) //if the pattern isnt valid, just return false ABABABAA
        {
            return false;
        }
    }

    if(currentStack.isEmpty())
    {
        return true;
    }
    else 
    {
        return false;
    }
    

}

bool stacks_for_regular_languages::L4(char* inputString)
{

    if(stacks_for_regular_languages::L3(inputString)) //If it passes 3, it passes 4, including the empty string case
    {
        return true;
    }

    //if it fails L3 it can still work

    stack_p1<char> patternStack;
    stack_p1<char> currentStack;
    stack_p1<char> reverseStack;
    bool patternReady = false;
    int stringLength = strlen(inputString);

    int i = 1;

    //push first letter on stack
    if(inputString[0] != NULL)
    {
        patternStack.push(inputString[0]);
    }

    while(patternStack.peek() == inputString[i])
    {
        patternStack.push(inputString[i++]);
    }

    if(patternStack.peek() != inputString[i] && i < stringLength) //Put that first B on the stack
    {
        patternStack.push(inputString[i++]);
    }
    else //If no B's are left, its wrong
    {
        return false;
    }
    
//Once there's a boundry
    for(; i < stringLength; i++)
    {
        if(!patternReady) //Build the pattern stack
        {
            
            if(patternStack.peek() == inputString[i]) //If the character is the same as the one before it, push it (Push the B's on)
            {
                patternStack.push(inputString[i]);
            }
            else if(patternStack.peek() != inputString[i]) //2nd boundry
            {
                i--;
                patternReady = true;
            }
            
            
        }
        else //We have our pattern in a stack to compare every other pattern with now
        {

            if(reverseStack.isEmpty()) //Refill current stack with copy of pattern stack, then give it the same options as if it were full to begin with 
            {
                currentStack = patternStack;

                //Reverse the stack order for correct pattern comparison
                while(!currentStack.isEmpty())
                {
                    reverseStack.push(currentStack.pop());
                }

                i--; //repeat again but with a full stack

            }
            else if(reverseStack.peek() == inputString[i]) //This should always keep popping the pattern off due to the way its set up
            {
                reverseStack.pop();
            }
            else //Invalid pattern
            {
                return false;
            }
        }
        
    }

    //If the reverse stack is either empty or completely full (this will happen if there is an odd number of "patterns")
    if(reverseStack.isEmpty())
    {
        return true;
    }
    else 
    {
        return false;
    }

}


#endif /* stacks_for_regular_languages_h */
