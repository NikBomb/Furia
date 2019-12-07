#pragma once 
#include "pch.h"
#include "../../source/particle.hpp"
#include "../../source/integrators.hpp"

TEST(ParticleTest, integrator) {

	furia::Vector3 expectedPosition(0, 0, 1 / 2);
	furia::Vector3 position(0, 0, 0);
	furia::Vector3 velocity(0, 0, 0);
	furia::Vector3 acceleration(0, 0, 1);
	Particle<ExponentialDamping> p(position, velocity, acceleration, 1, 0);
	p.integrate(1);

	//Continue tests
}