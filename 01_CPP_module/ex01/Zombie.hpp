/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:58:21 by lpaula-n          #+#    #+#             */
/*   Updated: 2025/12/16 22:41:43 by lpaula-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>


class Zombie
{
    private:
        std::string name;


    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);

        void announce(std::string n);

        void setName(std::string name);


};




#endif