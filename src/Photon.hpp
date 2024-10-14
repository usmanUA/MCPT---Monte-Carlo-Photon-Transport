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

#include <vector>
#include <unistd.h>
#include "raylib.h"
// // NOTE: A struct to represent the position of the photon
// struct	Position {
// 	float x, y, z;
// };

// // NOTE: A struct to represent the direction vector of the photon
// struct	Direction {
// 	float u, v, w;
// };

// struct	Vector3
// {
// 	float x, y, z;
// };

class	Photon
{
	private:
		Vector3	position;
		Vector3	direction;
		float		energy;

	public:
		// NOTE: Canonical Form
		Photon( void );
		Photon( Vector3&, Vector3&, float& );
		~Photon( void );
		Photon( Photon& );
		Photon&	operator=( const Photon& );

		// NOTE: Getter and Setters
		Vector3&	getPosition( void );
		void	setPosition( const Vector3& );
		Vector3&	getDirection( void );
		void	setDirection( const Vector3& );
		float&	getEnergy( void );
		void	setEnergy( const float& );

};
