/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:08:13 by assabich          #+#    #+#             */
/*   Updated: 2026/04/06 17:31:11 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <map>

class BitcoinExchange
{
    public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    
    BitcoinExchange &operator=(const BitcoinExchange &copy);
    void            fill_db(std::ifstream &data);
    std::string     get_key(std::string &line);
    int             get_value(std::string &line);

    private:
    std::map<std::string, double> _db;
};

#endif