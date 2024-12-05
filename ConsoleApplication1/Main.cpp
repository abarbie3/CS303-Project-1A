//Names: Alyssa Barbee, Aarohi Patel
//Date: 
//CS303 Project 1A

#include "Project1A.h"

int main() {
    vector<string> myExpressions = {
        "1+2*3",
        "2+2^2*3",
        "1==2",
        "1+3 > 2",
        "(4>=4) && 0",
        "(1+2)*3",
        "++++2-5*(3^2)"
    }; 

    for (int i = 0; i < myExpressions.size(); ++i){
        infixEvaluator(myExpressions[i]);
    }
    // try {
    //     vector<string> myExpressions = {
    //         "1+2*3",
    //         "2+2^2*3",
    //         "1==2",
    //         "1+3 > 2",
    //         "(4>=4) && 0",
    //         "(1+2)*3",
    //         "++++2-5*(3^2)"
    //     }; 

    //     for (int i = 0; i < myExpressions.size(); ++i){
    //         infixEvaluator(myExpressions[i]);
    //     }

    // }
    // catch(...){
    //     cout << "There was an unexpected error.\n";
    // }
    
    return 0;
}