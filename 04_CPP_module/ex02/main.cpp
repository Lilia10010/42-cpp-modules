/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:40:53 by lpaula-n        #+#    #+#             */
/*   Updated: 2026/02/27 12:08:31 by lpaula-n       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    //error: [aqui esta criando um animal: é obrigatório q animal tenha implementação como no ex01 ]
    //já Animal* funfa modeque [aqui esta criando espaço para armazenar endereços e ñ criando animal]
    // Animal a; 

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    dog->makeSound();
    cat->makeSound();

    delete dog;
    delete cat;

    return 0;
}