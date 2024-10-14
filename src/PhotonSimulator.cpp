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
#include "Types.hpp"
#include <cmath>
#include <cstdlib>
#include <random>
#include <string>

PhotonSimulator::PhotonSimulator( Vector3& pos, Vector3& dir, float& e, t_map& table) : table(table)
{
	this->photon = new Photon( pos, dir, e );
	EnergyKey e_key = {e};
	this->coefficients["u_photo"] = table[e_key]["u_photo"];
	this->coefficients["u_comp"] = table[e_key]["u_comp"];
	this->coefficients["u_pair"] = table[e_key]["u_pair"];
}

PhotonSimulator::~PhotonSimulator( void )
{
	delete this->photon;
}

/*PhotonSimulator::PhotonSimulator( const PhotonSimulator& from ) : table(from.table)*/
/*{*/
/*	if (this != &from)*/
/*	{*/
/*		this->photon = from.photon;*/
/*		this->table = from.table;*/
/*		this->coefficients["u_photo"] = from.coefficients["u_photo"];*/
/*		this->coefficients["u_comp"] = from.coefficients["u_comp"];*/
/*		this->coefficients["u_pair"] = from.coefficients["u_pair"];*/
/*	}*/
/*}*/
/**/
/*PhotonSimulator& PhotonSimulator::operator=( const PhotonSimulator& from )*/
/*{*/
/*	if (this != &from)*/
/*	{*/
/*		this->photon = from.photon;*/
/*		this->table = from.table;*/
/*		this->coefficients["u_photo"] = from.coefficients["u_photo"];*/
/*		this->coefficients["u_comp"] = from.coefficients["u_comp"];*/
/*		this->coefficients["u_pair"] = from.coefficients["u_pair"];*/
/*	}*/
/*	return *this;*/
/*}*/

void	PhotonSimulator::simulate( void )
{
	std::random_device	rd;
	std::mt19937	gen(rd());
	std::uniform_real_distribution<>	dis(0.0, 1.0);
	float	R;
	float	R2;
	float	epsi;
	float	total_attenuation;
	bool	isAlive = true;

	while (isAlive)
	{
		R = dis(gen);
		R2 = dis(gen);
		cout << "R2: " << R2 << "\n";
		EnergyKey e = {this->photon->getEnergy()};
		float u_photo = this->table[e]["u_photo"];
		float u_comp = this->table[e]["u_comp"];
		float u_pair = this->table[e]["u_pair"];
		cout << "u_photo: " << u_photo << " u_comp: " << u_comp << " and u_pair: " << u_pair << "\n";
		total_attenuation = u_photo + u_comp + u_pair;
		double lambda = 1.0 / total_attenuation;
		double s = -lambda * std::log(R);
		updatePhotonPosition( s );
		// TODO: I guess here comes the graphical part
		float p_photo = u_photo / total_attenuation;
		float p_comp = (u_photo + u_comp) / total_attenuation;
//		cout << "u_photo: " << u_photo << " tot_atte: " << total_attenuation << " and p_photo: " << p_photo << "\n";
		if (R2 < p_photo) {
			this->photon->setEnergy(0);
			isAlive = false;
			cout << "SHIED\n";
		}
		else if (R2 >= p_comp) {
			this->photon->setEnergy(0);
			isAlive = false;
			cout << "DIED\n";
		}
		else if (R2 <= p_photo && R2 < p_comp) {
			cout << "MATCHED\n";
			exit(1);
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
		cout << "NOT any if got true\n";
	}
}

void	PhotonSimulator::updatePhotonPosition( const float& s )
{
	Vector3	newpos;
	Vector3&	pos = this->photon->getPosition();
	Vector3&	dir = this->photon->getDirection();
	newpos.x = pos.x + s * dir.x;
	newpos.y = pos.y + s * dir.y;
	newpos.z = pos.z + s * dir.z;

	this->photon->setPosition( newpos );
}

void	PhotonSimulator::updatePhotonDirection( const float& theta, const float& phi )
{
	Vector3	newdir;

	newdir.x = cos(theta) * sin(phi);
	newdir.y = sin(theta) * sin(phi);
	newdir.z = cos(phi);
	this->photon->setDirection( newdir );
}

void	PhotonSimulator::updatePhotonEnergy( const float& newE )
{
	this->photon->setEnergy( newE );
}

Vector3&	PhotonSimulator::getDirection( void )
{
	return this->photon->getDirection();
}
