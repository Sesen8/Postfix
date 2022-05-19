#include "evaluator.h"
#include <stack>
#include <sstream>
#include <math.h>


using namespace std;



double Evaluate(const string& postfix, bool& error){
    std::stack<double> numbers;
    std::stack<char> symbols;

    string a;
    string b;

    std::stringstream line(postfix);

    while(line>>a){
        if(isdigit(a.at(0))){

            numbers.push(stod(a));
        }

        else if(a=="+"|| a=="-" || a=="*" || a=="^" || a=="/"){
            if(numbers.empty() || numbers.size() == 1){
                error = true;
                return -1;
            }

            double secondNum = numbers.top();
            numbers.pop();
            double firstNum = numbers.top();
            numbers.pop();

            switch(a.at(0)){
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
