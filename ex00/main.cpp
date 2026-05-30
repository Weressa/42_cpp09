/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:08:53 by assabich          #+#    #+#             */
/*   Updated: 2026/05/31 00:38:27 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include "BitcoinExchange.hpp"

int main(int ac, char** av)
{
    std::ifstream   input;
    std::ifstream   data;
    try
    {        
        if (ac != 2)
            throw std::runtime_error("Error: could not open file.");
        data.open("data.csv");
        input.open(av[1]);
        if (!input.is_open() || !data.is_open())
        {
            input.close();
            data.close();    
            throw std::runtime_error("Error: could not open file.");
        }
        BitcoinExchange btc;
        btc.fill_db(data);
        btc.handle_input(input);
        input.close();
        data.close();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return (0);
}
