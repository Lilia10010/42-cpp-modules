/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:00:52 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/17 20:40:50 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;

    std::string& stringREF = str;

	 std::cout << std::endl;

    std::cout << "Adress of string:     " << &str << std::endl;
    std::cout << "Adress help by PTR:   " << stringPTR << std::endl;
    std::cout << "Adress help by REF:   " << &stringREF << std::endl;

    std::cout << std::endl;
    
    std::cout << "Value of string:	" << str << std::endl;
    std::cout << "Value help by PTR:	" << *stringPTR << std::endl;
    std::cout << "Value help by REF:	" << stringREF << std::endl;

	std::cout << std::endl;
    
    return (0);
}