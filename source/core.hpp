#pragma once
#include "precision.hpp"
#include <cmath>

namespace furia {
	class Vector3 {
	public:
		scalar x;
		scalar y;
		scalar z;
		Vector3() : x(0), y(0), z(0) {

		};

		Vector3(const scalar _x, const scalar _y, const scalar _z) : x(_x), y(_y), z(_z) {

		}

		void invert() {
			x *= -1;
			y *= -1;
			z *= -1;
		}

		scalar magnitude() const {
			return sqrt(x * x + y * y + z * z);
		}

		scalar squareMagnitude() const {
			return x * x + y * y + z * z;
		}

		void normalize() {
			scalar norm = magnitude();
			if (norm > 0) {
				x /= norm;
				y /= norm;
				z /= norm;
			}
		}

		void operator*=(const scalar value) {
			x *= value;
			y *= value;
			z *= value;
		}

		Vector3 operator*(const scalar value) const {
			return Vector3(value * x, value * y, value * z);
		}

		void operator+=(const Vector3 & v) {
			x += v.x;
			y += v.y;
			z += v.z;
		}

		Vector3 operator+(const Vector3 & v) const {
			return Vector3(x + v.x, y + v.y, z + v.z);
		}

		void operator-=(const Vector3 & v) {
			x -= v.x;
			y -= v.y;
			z -= v.z;
		}

		Vector3 operator-(const Vector3 & v) const {
			return Vector3(x - v.x, y - v.y, z - v.z);
		}

		void addScaledVector(Vector3 v, scalar value) {
			x += v.x * value;
			y += v.y * value;
			z += v.z * value;
		}

		Vector3 componentProduct(const Vector3 & v) const {
			return Vector3(x * v.x, y * v.y, z * v.z);
		}

		void componentProductInPlace(const Vector3 & v) {
			x *= v.x;
			y *= v.y;
			z *= v.z;
		}

		scalar scalarProduct(const Vector3 & v) const {
			return x * v.x + y * v.y + z * v.z;
		}

		scalar operator*(const Vector3 & v) const {
			return scalarProduct(v);
		}

		Vector3 vectorProduct(const Vector3 & v) const {
			return Vector3(y * v.z - z * v.y,
				z * v.x - x * v.z,
				x * v.y - y * v.x
			);

		}

		void vectorProductInPlace(const Vector3 & v) {
			*this = vectorProduct(v);
		};

		void makeOrthonmalBasis(Vector3 & a, Vector3 & b, Vector3 & c) {
			a.normalize();
			c = a.vectorProduct(b);
			if (c.squareMagnitude() == 0) return;
			c.normalize();
			b = c.vectorProduct(a);
		}



	};

}
