/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhotonSimulator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 20:45:14 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/08 14:01:11 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Photon.hpp"
#include <map>
#include <vector>

# define alive true

class	PhotonSimulator
{
	public:
		// NOTE: Canonical Form
		PhotonSimulator( Position&, Direction&, float& , std::map<float, std::vector<float>>& );
		~PhotonSimulator( void );
		PhotonSimulator( const PhotonSimulator& );
		PhotonSimulator&	operator=( const PhotonSimulator& );

		void	simulate( void );
		void	updatePhotonPosition( const float& );
		void	updatePhotonDirection( const Direction& );
		void	updatePhotonEnergy( const float& );
	private:
		Photon photon;
		std::map<float, std::vector<float>>& table;
		std::vector<float> coefficients;
};
