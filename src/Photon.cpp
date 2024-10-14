/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Photon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 12:02:44 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/08 13:28:13 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Photon.hpp"

Photon::Photon( void )
{
};

Photon::Photon( Vector3& pos, Vector3& dir, float& e ) : position(pos), direction(dir), energy(e)
{};

Photon::~Photon( void )
{

}

Photon::Photon( Photon& photon )
{
	if (this != &photon) {
		setPosition(photon.position);
		setDirection(photon.direction);
		setEnergy(photon.energy);
	}
}

Photon&	Photon::operator=( const Photon& photon )
{
	if (this != &photon)
	{
		setPosition(photon.position);
		setDirection(photon.direction);
		setEnergy(photon.energy);
	}
	return *this;
}

void	Photon::setPosition( const Vector3& pos )
{
	this->position.x = pos.x;
	this->position.y = pos.y;
	this->position.z = pos.z;
}

Vector3&	Photon::getPosition( void )
{
	return this->position;
}
void	Photon::setDirection( const Vector3& dir )
{
	this->direction.x = dir.x;
	this->direction.y = dir.y;
	this->direction.z = dir.z;
}

Vector3&	Photon::getDirection( void )
{
	return this->direction;
}

void	Photon::setEnergy( const float& e )
{
	this->energy = e;
}

float&	Photon::getEnergy( void )
{
	return this->energy;
}
