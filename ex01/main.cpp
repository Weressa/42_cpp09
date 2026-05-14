/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assewer <assewer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 18:14:50 by assabich          #+#    #+#             */
/*   Updated: 2026/05/14 19:39:40 by assewer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rpn.hpp"
#include <iostream>

int main(int ac, char** av)
{
    if (ac != 2)
    {
        std::cerr << "Error: Format must be: ./RPN \"expression\"" << std::endl;
        return(1);
    }
    std::string expression = av[1];
    return (0);
}