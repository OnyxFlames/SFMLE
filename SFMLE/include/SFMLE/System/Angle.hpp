#pragma once

#include <SFMLE/System/Math.hpp>
#include <SFML/System/Vector2.hpp>

namespace sfe
{
	template <typename T>
	class Angle
	{
	protected:
		T value;
	protected:
		Angle() = default;
	public:

		static constexpr inline Angle<T> Degrees(const T degrees)
		{
			Angle<T> angle;
			angle.value = degrees;
			return angle;
		}

		static constexpr inline Angle<T> Radians(const T radians)
		{
			Angle<T> angle;
			angle.value = sfe::Math::RadToDeg(radians);
			return angle;
		}

		static inline Angle<T> FromVector(const sf::Vector2<T>& vec)
		{
			return Angle<T>::Radians(std::atan2(vec.y, vec.x));
		}

		constexpr T asDegrees() const { return value; }
		constexpr T asRadians() const { return sfe::Math::DegToRad(value); }
	};

	template <typename T>
	constexpr Angle<T> radians(const T rads) { return Angle<T>::Radians(rads); }

	template <typename T>
	constexpr Angle<T> degrees(const T degs) { return Angle<T>::Degrees(degs); }

	typedef Angle<float> FloatAngle;
	typedef Angle<double> DoubleAngle;
}