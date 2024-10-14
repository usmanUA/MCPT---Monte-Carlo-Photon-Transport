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

#pragma once

#include <map>
#include <cmath>
#include <string>
#include <iostream>
#include <GLUT/glut.h>
using namespace std;
# define alive true
# define m_c2 511
# define pi 3.14


struct	EnergyKey
{
	float energy;
	bool operator<(const EnergyKey& other) const {
		return energy < other.energy && fabs(energy - other.energy) > 1e-6;
	}
};

using t_map = map<EnergyKey, map<string, float> >;
