/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Photon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 22:17:50 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/08 13:26:12 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

// NOTE: A struct to represent the position of the photon
struct	Position {
	float x, y, z;
};

// NOTE: A struct to represent the direction vector of the photon
struct	Direction {
	float u, v, w;
};

class	Photon
{
	private:
		Position	coords;
		Direction	dir;
		float		energy;

	public:
		// NOTE: Canonical Form
		Photon( void );
		Photon( Position&, Direction&, float& );
		~Photon( void );
		Photon( Photon& );
		Photon&	operator=( const Photon& );

		// NOTE: Getter and Setters
		Position&	getPosition( void );
		void	setPosition( const Position& );
		Direction&	getDirection( void );
		void	setDirection( const Direction& );
		float&	getEnergy( void );
		void	setEnergy( const float& );

};
