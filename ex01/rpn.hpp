/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:16:09 by assabich          #+#    #+#             */
/*   Updated: 2026/05/31 03:38:50 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>
#include <cctype>

class   RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        RPN(const std::string &expression);
        ~RPN();
        RPN &operator=(const RPN &other);
        
        void    calculator(const std::string &expression);
        void    calculate(char op);

    private:
    std::stack<int>     _stack;
};

#endif