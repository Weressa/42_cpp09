/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:57:37 by assabich          #+#    #+#             */
/*   Updated: 2026/06/05 19:58:31 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other): _stack(other._stack) {}
    
RPN::~RPN() {}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
    {
        _stack = other._stack;
    }
    return (*this);
}

RPN::RPN(const std::string &expression)
{
    calculator(expression);
}


void    RPN::calculate(char op)
{
    if (_stack.size() < 2)
        throw std::runtime_error("Error: invalid equation");
    
    int first = _stack.top();
    _stack.pop();
    int second = _stack.top();
    _stack.pop();
    
    int res = 0;
    switch (op)
    {
        case '+':
            res = first + second;
            break;
        case '-':
            res = second - first;
            break;
        case '*':
            res = second * first;
            break;
        case '/':
            if (first == 0)
                throw std::runtime_error("Error: division by zero");
            res = second / first;
            break;
        default:
            throw std::runtime_error("Error: invalid operator");
    }
    _stack.push(res);
    
}
void    RPN::calculator(const std::string &expression)
{
    std::string ops = "+-/*";
    int nb = 0;
    int op = 0;
    for (unsigned int i = 0; i < expression.size(); i++)
    {
        if (std::isspace(expression[i]))
            continue;
        else if (std::isdigit(expression[i]))
        {
            nb++;
            this->_stack.push(expression[i] - '0');
        }
        else if (ops.find(expression[i]) != std::string::npos) //valeur max dans std (dernier char)
        {
            op++;
            calculate(expression[i]);
        }
        else
            throw std::invalid_argument("Error: character not number or operator");
    }
    if (_stack.size() != 1)
        throw std::runtime_error("Error: invalid equation");

    std::cout << "Result: " << _stack.top() << std::endl;
}
