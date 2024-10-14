/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SimulationManager.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uahmed <uahmed@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 11:03:34 by uahmed            #+#    #+#             */
/*   Updated: 2024/10/09 21:36:44 by uahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SimulationManager.hpp"

SimulationManager::SimulationManager( int n, t_map& table ) : N(n), table(table)
{};

void SimulationManager::initSimulators( void )
{
	Vector3 pos = {0, 0, 0};
	Vector3 dir = {1, 0, 0};
	float	e = 4;
	for (int i = 0; i < N; i++)
	{
		this->simulators.push_back(make_unique<PhotonSimulator>(pos, dir, e, this->table));
	}
}

void	SimulationManager::manageSimulations( void )
{
	InitWindow(800, 600, "Photon Simulation");

	// NOTE: Camera definition
	Camera camera = { 
	{ 0.0f, 10.0f, 10.0f },
	{ 0.0f, 0.0f, 0.0f },
	{ 0.0f, 1.0f, 0.0f },
	45.0f,
	CAMERA_PERSPECTIVE,
};
	while (!WindowShouldClose())
	{
		BeginDrawing();	
		ClearBackground(RAYWHITE);
		BeginMode3D(camera);
		DrawGrid(10, 1.0f);
		for (int i = 0; i < N; i++)
		{
			this->simulators[i]->simulate();
			sleep(1);
			Vector3 position = this->simulators[i]->getDirection();
			DrawSphere(position, 0.1f, PINK);

		}
		EndMode3D();
		EndDrawing();	
	}
	CloseWindow();
}

