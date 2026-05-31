/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 18:08:13 by assabich          #+#    #+#             */
/*   Updated: 2026/05/31 02:46:57 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>

class BitcoinExchange
{
    public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &copy);
    
    BitcoinExchange &operator=(const BitcoinExchange &copy);
    
    void    fill_db(std::ifstream &data);
    void    handle_input(std::ifstream &file);
    void    check_date(const std::string& date); 
    void    check_value(float value);
    float   get_exchange(const std::string &date);

    private:
    std::map<std::string, float> _db;
};

#endif