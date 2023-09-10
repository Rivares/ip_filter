#pragma once

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <string>
#include <array>
#include <charconv>
#include <set>

static constexpr size_t cntDigits = 4;

struct ModeComp
{
    bool operator()(const std::array<int, cntDigits> lhs, const std::array<int, cntDigits> rhs) const
    {
        if (lhs.at(0) == rhs.at(0))
        {
            if (lhs.at(1) == rhs.at(1))
            {
                if (lhs.at(2) == rhs.at(2))
                {
                    if (lhs.at(3) == rhs.at(3))
                    {
                        return true;
                    }
                    else if (lhs.at(3) > rhs.at(3))
                    {   return true;    }
                    else
                    {   return false;   }
                }
                else if (lhs.at(2) > rhs.at(2))
                {   return true;    }
                else
                {   return false;   }
            }
            else if (lhs.at(1) > rhs.at(1))
            {   return true;    }
            else
            {   return false;   }
        }
        else if (lhs.at(0) > rhs.at(0))
        {   return true;    }
        else
        {   return false;   }
    }
};

void pluginAutoLambda()
{
    try
    {
        std::multiset<std::array<int, cntDigits>, ModeComp> ip_pool;

        std::string buff = "";
        while (std::getline(std::cin, buff))
        {
            std::array<int, cntDigits> ip_add {0, 0, 0, 0};
            std::string_view ip_addr = buff.substr(0, buff.find_first_of('\t'));

            std::string_view ip_part = ip_addr.substr(0, ip_addr.find_first_of('.'));
            std::from_chars(ip_part.data(), ip_part.data() + ip_part.size(), ip_add[0]);
            ip_addr.remove_prefix(ip_addr.find_first_of('.') + 1);

            ip_part = ip_addr.substr(0, ip_addr.find_first_of('.'));
            std::from_chars(ip_part.data(), ip_part.data() + ip_part.size(), ip_add[1]);
            ip_addr.remove_prefix(ip_addr.find_first_of('.') + 1);

            ip_part = ip_addr.substr(0, ip_addr.find_first_of('.'));
            std::from_chars(ip_part.data(), ip_part.data() + ip_part.size(), ip_add[2]);
            ip_addr.remove_prefix(ip_addr.find_first_of('.') + 1);

            ip_part = ip_addr.substr(0, ip_addr.find_first_of('.'));
            std::from_chars(ip_part.data(), ip_part.data() + ip_part.size(), ip_add[3]);

            ip_pool.insert(ip_add);
        }

        // Reverse lexicographically sort
        for (const auto& addr : ip_pool)
        {
            std::cout << addr.at(0) << '.'
                      << addr.at(1) << '.'
                      << addr.at(2) << '.'
                      << addr.at(3) << '\n';
        }

        // Filter by first byte and output . ip = filter(1)
        for (const auto& addr : ip_pool)
        {
            if (addr.at(0) != 1) { continue; }

            std::cout << addr.at(0) << '.'
                      << addr.at(1) << '.'
                      << addr.at(2) << '.'
                      << addr.at(3) << '\n';
        }

        // Filter by first and second bytes and output . ip = filter(46, 70)
        for (const auto& addr : ip_pool)
        {
            if ( (addr.at(0) != 46) || (addr.at(1) != 70) ) { continue; }

            std::cout << addr.at(0) << '.'
                      << addr.at(1) << '.'
                      << addr.at(2) << '.'
                      << addr.at(3) << '\n';
        }

        // Filter by any byte and output . ip = filter_any(46)
        for (const auto& addr : ip_pool)
        {
            if (
                    (addr.at(0) != 46)
                     && (addr.at(1) != 46)
                     && (addr.at(2) != 46)
                     && (addr.at(3) != 46)
                 ) { continue; }

            std::cout << addr.at(0) << '.'
                      << addr.at(1) << '.'
                      << addr.at(2) << '.'
                      << addr.at(3) << '\n';
        }
    }
    catch (const std::exception& except)
    {
        std::cerr << except.what() << std::endl;
    }
}

