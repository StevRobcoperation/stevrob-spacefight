/*#ifndef MODFLOAT_HPP
#define MODFLOAT_HPP

float ModFloat(float Zahl, float Mod)
{
	int temp = 0;
	float Result = 0;
	float temp2 = 0;
	temp = static_cast<int>(Zahl / Mod);
	temp2 = Mod * static_cast<float>(temp);
	Result = Zahl - static_cast<float>(temp);

	return Result;

}




#endif // !MODFLOAT_HPP

*/