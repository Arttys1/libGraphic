#pragma once
#ifndef H_LIGHT
#define H_LIGHT
#include "Vector3D.h"
#include "Color.h"

namespace libGraphic
{
	class Light
	{
	private:
		Vector3D position;
		Color lightColor;
		float strength;

		static Color ambientColor;
		static float ambientStrenght;

	public:
		Light(Vector3D pos);
		Light(Vector3D pos, Color color);
		Light(Vector3D pos, float strength);
		Light(Vector3D pos, Color color, float strength);		

		Vector3D getPosition() const;
		Color getLightColor() const;
		float getStrength() const;

		void setPosition(Vector3D pos);
		void setLightColor(Color color);
		void setStrenght(float strength);

		static Color getAmbientColor();
		static float getAmbientStrenght();
		static void setAmbientColor(Color color);
		static void setAmbientstrength(float strength);
	};
}

#endif // !H_LIGHT