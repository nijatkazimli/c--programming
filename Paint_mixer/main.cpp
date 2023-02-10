#include <iostream>
#include <cassert>
#include "mixer.h"
#include "paint.h"

int main()
{
	//PART 1 - 1 point.
	Paint red(255, 0, 0);
	Paint green(0, 255, 0);
	Paint blue(0, 0, 255, 1);
	std::cout << "Red (should be: (255,0,0)[100%]): " << red << std::endl;
	std::cout << "Green (should be: (0,255,0)[100%]): " << green << std::endl;
	std::cout << "Blue (should be: (0,0,255)[100%]): " << blue << std::endl;

	//PART 2 - 0.5 points.
	auto empty_black = Paint::GetEmpty();
	std::cout << "Empty black (should be: (0,0,0)[0%]): " << empty_black << std::endl;
	
	//PART 3 - 0.5 points.
	auto half_red = red / 2;
	std::cout << "Half red (should be: (255,0,0)[50%]): " << half_red << std::endl;
	
	//PART 4 - 1 point.
	Paint mixed_paint = red / 2 + green / 2;
	std::cout << "Mixed half of red and half of green (should be: (127,127,0)[100%]): " << mixed_paint << std::endl;
	mixed_paint = red / 2 + green / 4 + blue / 4;
	std::cout << "Mixed half of red, quarter of green, and quarter of blue (should be: (127,63,63)[100%]): " << mixed_paint << std::endl;
	mixed_paint = red / 4 + blue / 4;
	std::cout << "Mixed quarter of red and quarter of blue (should be: (127,0,127)[50%]): " << mixed_paint << std::endl;
	mixed_paint = red / 4 + green / 4 + blue / 4;
	std::cout << "Mixed quarter of red, quarter of green, and quarter of blue (should be: (84,84,85)[75%]): " << mixed_paint << std::endl;	
	
	//PART 5 - 2 points.
	Buffer shelf;
	shelf.push(red);
	shelf.push(blue);
	shelf.push(green);
	/*auto from_shelf = shelf.pop();
	std::cout << "Taken from shelf (should be: (0,255,0)[100%]): " << from_shelf << std::endl;
	std::cout << "Current number of paints on the shelf (should be: 2): " << shelf.size() << std::endl;

	//PART 6 - 1 point.
	Mixer mixer;
	mixer.add(green, 2);
	mixer.add(blue);
	mixer.add(red, 5);

	std::cout << "Number of paints in the mixer (should be: 8): " << mixer.size() << std::endl;

	//PART 7 - 2 points.
	mixer.mix(1);
	mixed_paint = mixer.get();
	std::cout << "Color of the first mixed paint (should be: (255, 0, 0)[100%]): " << mixed_paint << std::endl;
	mixed_paint = mixer.get();
	std::cout << "Color of the second mixed paint (should be: (255, 0, 0)[100%]): " << mixed_paint << std::endl;

	assert(mixer.mix(5));
	mixed_paint = mixer.get();
	std::cout << "Color of the third mixed paint (should be: (152, 51, 50)[100%]): " << mixed_paint << std::endl;
	std::cout << "Number of paints in the mixer (should be: 5): " << mixer.size() << std::endl;

	mixed_paint = mixer.get();
	std::cout << "Color of the fourth mixed paint (should be: (152, 51, 50)[100%]): " << mixed_paint << std::endl;

	mixed_paint = mixer.get();
	std::cout << "Color of the fifth mixed paint (should be: (152, 51, 50)[100%]): " << mixed_paint << std::endl;

	mixed_paint = mixer.get();
	std::cout << "Color of the sixth mixed paint (should be: (152, 51, 50)[100%]): " << mixed_paint << std::endl;

	mixed_paint = mixer.get();
	std::cout << "Color of the seventh mixed paint (should be: (152, 51, 50)[100%]): " << mixed_paint << std::endl;

	mixed_paint = mixer.get();
	std::cout << "Color of the eighth mixed paint (should be: (0, 255, 0)[100%]): " << mixed_paint << std::endl;
	assert(!mixer.mix(1));
	*/
}
