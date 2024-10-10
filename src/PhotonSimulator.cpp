/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhotonSimulator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:09:20 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/09 21:08:32 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhotonSimulator.hpp"
#include "Photon.hpp"
#include <cmath>
#include <random>

PhotonSimulator::PhotonSimulator( Position& pos, Direction& dir, float& e, t_map& table)
{
	this->table = table;
	this->photon = new Photon( pos, dir, e );
	this->coefficients.push_back(table[e][0]);
	this->coefficients.push_back(table[e][1]);
	this->coefficients.push_back(table[e][2]);
}

PhotonSimulator::~PhotonSimulator( void )
{
	delete this->photon;
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
	float	R;
	float	R2;
	float	epsi;
	float	total_attenuation;

	while (alive)
	{
		R = dis(gen);
		R2 = dis(gen);
		float u_photo = this->table[this->photon->getEnergy()][0];
		float u_comp = this->table[this->photon->getEnergy()][1];
		float u_pair = this->table[this->photon->getEnergy()][2];
		total_attenuation = u_photo + u_comp + u_pair;
		double lambda = 1.0 / total_attenuation;
		double s = -lambda * std::log(R);
		updatePhotonPosition( s );
		// TODO: I guess here comes the graphical part
		float p_photo = u_photo / total_attenuation;
		float p_comp = (u_photo + u_comp) / total_attenuation;
		if (R2 < p_photo) {
			this->photon->setEnergy(0);
		}
		else if (R2 >= p_comp) {
			this->photon->setEnergy(0);
		}
		else if (R2 <= p_photo && R2 < p_comp) {
			epsi = dis(gen);
			float phi_rand = dis(gen);
			float phi = 2 * pi * phi_rand;
			float prevE = this->photon->getEnergy();
			float cosTheta = 1.0 - (2*epsi)/(1.0+(prevE/(511) * (1.0-epsi)));
			float theta = std::acos(cosTheta);
			float currE = prevE / (1.0 + (prevE/m_c2*(1.0-cosTheta)));
			updatePhotonEnergy( currE );
			updatePhotonDirection(theta, phi);
		}
	}
}

void	PhotonSimulator::updatePhotonPosition( const float& s )
{
	Position	newpos;
	Position	pos = this->photon->getPosition();
	Direction	dir = this->photon->getDirection();
	newpos.x = pos.x + s * dir.u;
	newpos.y = pos.y + s * dir.v;
	newpos.z = pos.z + s * dir.w;

	this->photon->setPosition( newpos );
}

void	PhotonSimulator::updatePhotonDirection( const float& theta, const float& phi )
{
	Direction	newdir;

	newdir.u = std::cos(theta) * std::sin(phi);
	newdir.v = std::sin(theta) * std::sin(phi);
	newdir.w = std::cos(phi);
	this->photon->setDirection( newdir );
}

void	PhotonSimulator::updatePhotonEnergy( const float& newE )
{
	this->photon->setEnergy( newE );
}
