#include "evaluator.h"
#include <stack>
#include <sstream>
#include <math.h>






double Evaluate(const string& postfix, bool& error){
    std::stack<double> numbers;


    string postfixLine;


    std::stringstream line(postfix);

    while(line>>postfixLine){
        if(isdigit(postfixLine.at(0))){

            numbers.push(stod(postfixLine));
        }

        else if(postfixLine=="+"|| postfixLine=="-" || postfixLine=="*" || postfixLine=="^" || postfixLine=="/"){
            if(numbers.empty() || numbers.size() == 1){
                error = true;
                return -1;
            }

            double secondNum = numbers.top();
            numbers.pop();
            double firstNum = numbers.top();
            numbers.pop();

            switch(postfixLine.at(0)){
                case '+': numbers.push(firstNum+secondNum);
                    break;
                case '-': numbers.push(firstNum-secondNum);
                    break;
                case '/': numbers.push(firstNum/secondNum);
                    break;
                case '*': numbers.push(firstNum*secondNum);
                    break;
                case '^': numbers.push(pow(firstNum,secondNum));
                    break;
            }
        }
    }

    if(numbers.size() != 1){
        error = true;
        return -1;
    }


    error = false;
	return numbers.top();

}
