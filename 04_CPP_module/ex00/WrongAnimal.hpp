/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 18:39:36 by lpaula-n        #+#    #+#             */
/*   Updated: 2026/02/08 22:44:29 by lpaula-n       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal 
{
    protected:
        std::string type;

    public:
        WrongAnimal();
        ~WrongAnimal();

        std::string getType() const;
        void makeSound() const;
};

#endif
