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

Photon::Photon( Position& pos, Direction& dir, float& e ) : coords(pos), dir(dir), energy(e)
{};

Photon::~Photon( void )
{

}

Photon::Photon( Photon& photon )
{
	if (this != &photon) {
		setPosition(photon.coords);
		setDirection(photon.dir);
		setEnergy(photon.energy);
	}
}

Photon&	Photon::operator=( const Photon& photon )
{
	if (this != &photon)
	{
		setPosition(photon.coords);
		setDirection(photon.dir);
		setEnergy(photon.energy);
	}
	return *this;
}

void	Photon::setPosition( const Position& pos )
{
	this->coords.x = pos.x;
	this->coords.y = pos.y;
	this->coords.z = pos.z;
}

void	Photon::setDirection( const Direction& dir )
{
	this->dir.u = dir.u;
	this->dir.v = dir.v;
	this->dir.w = dir.w;
}

void	Photon::setEnergy( const float& e )
{
	this->energy = e;
}

