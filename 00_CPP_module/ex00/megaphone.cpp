/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:32:56 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/13 19:32:57 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

void megaphone(int argc, char **argv)
{
    for(int i = 1; i < argc; ++i)
    {
        std::size_t size = std::strlen(argv[i]);
        for(int j = 0; j < (int)size; ++j)
        {
            std::cout << (char)std::toupper(argv[i][j]);
        }
    }
    std::cout << std::endl;
}


int main(int argc, char **argv)
{
  if (argc <= 1)
  {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    return (0);
  }
  megaphone(argc, argv);
  return (0);
}