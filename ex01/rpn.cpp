/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assewer <assewer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 14:57:37 by assabich          #+#    #+#             */
/*   Updated: 2026/05/14 19:48:18 by assewer          ###   ########.fr       */
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
void    RPN::calculator(const std::string &expression)
{
    std::string ops = "+-/*";
    int nb = 0;
    int op = 0;    
}

    

