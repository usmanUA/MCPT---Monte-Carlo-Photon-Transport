/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Types.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 21:02:49 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/09 21:43:25 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
using namespace std;
# define alive true
# define m_c2 511
# define pi 3.14


struct	EnergyKey
{
	float energy;
	bool operator<(EnergyKey& other) {
		return energy < other.energy;// && std::fabs(energy - other.energy) > 1e-6;
	}
};

using t_map = map<const string, map<string, float> >;
