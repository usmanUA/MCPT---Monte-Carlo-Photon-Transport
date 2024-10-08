/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhotonSimulator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:09:20 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/08 14:18:29 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhotonSimulator.hpp"
#include "Photon.hpp"
#include <cmath>
#include <random>

PhotonSimulator::PhotonSimulator( Position& pos, Direction& dir, float& e, std::map<float, std::vector<float>>& table) : photon(pos, dir, e), table(table)
{
	this->coefficients.push_back(table[e][0]);
	this->coefficients.push_back(table[e][1]);
	this->coefficients.push_back(table[e][2]);
}

PhotonSimulator::~PhotonSimulator( void )
{

}

PhotonSimulator::PhotonSimulator( const PhotonSimulator& from ) : table(from.table)
{
	if (this != &from)
	{
		this->photon = from.photon;
		this->table = from.table;
		this->coefficients[0] = from.coefficients[0];
		this->coefficients[1] = from.coefficients[1];
		this->coefficients[2] = from.coefficients[2];
	}
}

PhotonSimulator& PhotonSimulator::operator=( const PhotonSimulator& from )
{
	if (this != &from)
	{
		this->photon = from.photon;
		this->table = from.table;
		this->coefficients[0] = from.coefficients[0];
		this->coefficients[1] = from.coefficients[1];
		this->coefficients[2] = from.coefficients[2];
	}
	return *this;
}

void	PhotonSimulator::simulate( void )
{
	std::random_device	rd;
	std::mt19937	gen(rd());
	std::uniform_real_distribution<>	dis(0.0, 1.0);
	double	R;
	double	R2;
	double	total_attenuation;

	while (alive)
	{
		R = dis(gen);
		R2 = dis(gen);
		float u_photo = this->table[this->photon.getEnergy()][0];
		float u_comp = this->table[this->photon.getEnergy()][1];
		float u_pair = this->table[this->photon.getEnergy()][2];
		total_attenuation = u_photo + u_comp + u_pair;
		double lambda = 1.0 / total_attenuation;
		double s = -lambda * std::log(R);
		updatePhotonPosition( s );
		// TODO: I guess here comes the graphical part
		float p_photo = u_photo / total_attenuation;
		float p_comp = (u_photo + u_comp) / total_attenuation;
		if (R2 < p_photo) {
			this->photon.setEnergy(0);
		}
		else if (R2 >= p_comp) {
			this->photon.setEnergy(0);
		}
		else if (R2 <= p_photo && R2 < p_comp) {
			// TODO: calculate the new energy and angle
			// TODO: update the direction of photon
			this->photon.setEnergy(0);
		}
	}
}

void	PhotonSimulator::updatePhotonPosition( const float& s )
{
	// TODO: change the function to compute the position itself.
	Position	newpos;
	Position	pos = this->photon.getPosition();
	Direction	dir = this->photon.getDirection();
	newpos.x = pos.x + s * dir.u;
	newpos.y = pos.y + s * dir.v;
	newpos.z = pos.z + s * dir.w;

	this->photon.setPosition( newpos );
}

void	PhotonSimulator::updatePhotonDirection( const Direction& newdir )
{
	// TODO: change the function to compute the direction vector itself.
	this->photon.setDirection( newdir );
}

void	PhotonSimulator::updatePhotonEnergy( const float& newE )
{
	this->photon.setEnergy( newE );
}
