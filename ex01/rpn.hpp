/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assewer <assewer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:16:09 by assabich          #+#    #+#             */
/*   Updated: 2026/05/14 19:48:11 by assewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class   RPN
{
    public:
        RPN();
        RPN(const RPN &other);
        RPN(const std::string &expression);
        ~RPN();
        RPN &operator=(const RPN &other);
        
        void    calculator(const std::string &expression);
    
    private:
    std::stack<int>     _stack;
};

#endif