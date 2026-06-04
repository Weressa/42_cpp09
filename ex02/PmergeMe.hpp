/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 20:19:13 by assabich          #+#    #+#             */
/*   Updated: 2026/06/04 21:07:57 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <climits>
#include <cstdlib>

struct Pair
{
    int big;
    int small;
};

template <typename T>
typename T::iterator    insert_position(T &cont, int value)
{
    typename T::iterator    left = cont.begin();
    typename T::iterator    right = cont.end();
    
    while (left < right)
    {
        typename T::iterator mid = left + (right - left) / 2;
        
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    return (left);
}

template <typename T>
T    sort(T &data)
{
    std::vector<Pair> pairs;

    int last;
    bool has_last = false;
    
    if (data.size() <= 1)
        return (data);
    //create big/small pairs
    for (size_t i = 0; i + 1 < data.size(); i+= 2)
    {
        Pair p;
        if (data[i] > data[i + 1])
        {
            p.big = data[i];
            p.small = data[i + 1];
        }
        else
        {
            p.big = data[i + 1];
            p.small = data[i];
        }
        pairs.push_back(p);
    }
    //save last
    if (data.size() % 2)
    {
        has_last = true;
        last = data.back();
    }
    
    // build bigs chain    
    T   bigs;
    
    for (size_t i = 0; i < pairs.size(); i++)
        bigs.push_back(pairs[i].big);
    //sort bigs recursively
    bigs = sort(bigs);
    
    //sort pairs usings bigs
    std::vector<Pair> s_pairs;
    for (size_t i = 0; i < bigs.size(); i++)
    {
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].big == bigs[i])
            {
                s_pairs.push_back(pairs[j]);
                break;
            }
        }
    }
    
    //build mainchain
    T   main;

    main.push_back(s_pairs[0].small);
    
    for (size_t i = 0; i < s_pairs.size(); i++)
        main.push_back(s_pairs[i].big);

    // small elements - first
    T smalls;

    for (size_t i = 1; i < s_pairs.size(); i++)
        smalls.push_back(s_pairs[i].small);

    // 7. insert pending
    for (size_t i = 0; i < smalls.size(); i++)
    {
        typename T::iterator pos =
            insert_position(main, smalls[i]);

        main.insert(pos, smalls[i]);
    }

    if (has_last == true)
    {
        typename T::iterator pos = insert_position(main, last);
        main.insert(pos, last);
    }
    return (main);
}



class PmergeMe
{
    public:
    PmergeMe(int ac, char** av);
    PmergeMe(const PmergeMe &copy);
    ~PmergeMe();
    PmergeMe &operator=(const PmergeMe &copy);
    
    void    print_before();
    void    print_after();
    void    jacob();
    
    private:
        PmergeMe();
        std::vector<int>    vec;
        std::deque<int>     deq;
};

#endif