#pragma once
#ifndef H_COLOR
#define H_COLOR

namespace libGraphic
{
	class Color
	{
	private:
		float r, g, b;

	public:
		Color(unsigned char red, unsigned char green, unsigned char blue);
		Color(float red, float green, float blue);

		float getRed() const;
		float getGreen() const;
		float getBlue() const;

		static Color WHITE() { return Color(1.0f, 1.0f, 1.0f); }
		static Color BLACK() { return Color(0.f, 0.f, 0.f); }
		static Color RED() { return Color(1.f, 0.f, 0.f); }
		static Color GREEN() { return Color(0.f, 1.f, 0.f); }
		static Color BLUE() { return Color(0.f, 0.f, 1.f); }
		static Color YELLOW() { return Color(1.f, 1.f, 0.f); }
		static Color CYAN() { return Color(0.f, 1.f, 1.f); }
		static Color MAGENTA() { return Color(1.f, 0.f, 1.f); }

		
	};
}

#endif // !H_COLOR