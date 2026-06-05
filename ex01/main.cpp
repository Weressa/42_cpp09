/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:14:50 by assabich          #+#    #+#             */
/*   Updated: 2026/06/05 20:01:33 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.hpp"
#include <iostream>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Format must be: ./RPN \"equation\"" << std::endl;
        return(1);
    }
    std::string expression = av[1];
    try
    {
        RPN calculator(expression);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}