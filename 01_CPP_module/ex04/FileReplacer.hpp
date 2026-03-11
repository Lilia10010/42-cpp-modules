/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplacer.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpaula-n <lpaula-n@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 14:31:39 by lpaula-n        #+#    #+#             */
/*   Updated: 2025/12/21 14:46:03 by lpaula-n       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>

class FileReplacer
{
    private:
        std::string inputFile;
        std::string s1;
        std::string s2;

        std::string replaceContent(const std::string &content);

        public:
            FileReplacer(const std::string &file,
                         const std::string &search,
                         const std::string &replace);
       
        bool process();

};

#endif