/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: microbiana <microbiana@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 17:53:06 by microbiana        #+#    #+#             */
/*   Updated: 2025/12/27 19:04:14 by microbiana       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

// =========================
// CLASSE FIXED
// =========================
// Aqui definimos um NOVO TIPO de dado.
// Não é um int, não é um float.
// É um "Fixed".
class Fixed {

private:
	// =========================
	// ESTADO INTERNO (ENCAPSULADO)
	// =========================
	// Ninguém fora da classe pode acessar isso diretamente
	int _rawBits;

	// Constante da CLASSE (não do objeto)
	static const int _fractionalBits = 8;

public:
	// =========================
	// CONTROLE DO CICLO DE VIDA
	// =========================

	// 1️CONSTRUTOR PADRÃO
	// Chamado quando o objeto NASCE sem parâmetros
	Fixed();

	// 2️ Copy constructor cria uma NOVA instância baseada em outra
	// Chamado quando o objeto NASCE a partir de outro
	Fixed(const Fixed& other);

	// 3️COPY ASSIGNMENT - Operador de atribuição ✔ Copy assignment troca conteúdo.
	// Chamado quando o objeto JÁ EXISTE e recebe outro
	Fixed& operator=(const Fixed& other);

	// 4️DESTRUTOR
	// Chamado quando o objeto MORRE
	~Fixed();

	// =========================
	// INTERFACE PÚBLICA
	// =========================

	// Apenas LÊ o estado interno
	int getRawBits(void) const;

	// Altera o estado interno de forma controlada
	void setRawBits(int const raw);
};

#endif