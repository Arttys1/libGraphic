#pragma once
#include "Color.h"
#ifndef H_MATERIAL
#define H_MATERIAL

namespace libGraphic
{
	class Material
	{
	private:
		Color ambiant, diffuse, specular;
		float shininess;

	public:
		Material();
		Material(Color color, float shininess = 32.f);
		Material(Color ambiant, Color diffuse, Color specular, float shininess = 32.f);
		
		Color getAmbiant() const;
		Color getDiffuse() const;
		Color getSpecular() const;
		float getShininess() const;

		void setAmbiant(Color color);
		void setDiffuse(Color color);
		void setSpecular(Color color);
		void setShininess(float shininess);
	};
}
#endif //!H_MATERIAL