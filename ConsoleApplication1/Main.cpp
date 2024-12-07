//Names: Alyssa Barbee, Aarohi Patel, Saw Nwe
//Date: 12/6/24
//CS303 Project 1A - Extra Credit
//Note: Note: Aarohi helped with this project, but doesn't wants this extra credit assignment applied to her grade (just I and Saw)

#include "Project1A.h"

int main() {

    //Error handling with Try and Catch block
    try {
        //Initialzed example expressions with a vector
         vector<string> myExpressions = {
             "1+2*3",
             "2+2^2*3",
             "1==2",
             "1+3 > 2",
             "(4>=4) && 0",
             "(1+2)*3",
             "++++2-5*(3^2)"
         }; 

         //Evaluating and displaying expressions
         for (int i = 0; i < myExpressions.size(); ++i) {
             infixEvaluator(myExpressions[i]);
             cout << endl;
         }

     }
     catch(...){
         cout << "There was an unexpected error." << endl;
     }
    
    return 0;
}