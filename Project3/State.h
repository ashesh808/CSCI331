#ifndef STATE_H
#define STATE_H

class State
{
public:
    State();
    /**state c string*/
	char stateName [5];
	/**eastern most Zipcode c string*/
	char easternZipcode [10];
	/**western most Zipcode c string*/
	char westernZipcode [10];
	/**nothern most Zipcode c string*/
	char northernZipcode [10];
	/**southern most Zipcode c string*/
	char southernZipcode [10];
	/**Largest Longitude c string*/
	char largestLong [10];
	/**Smallest Longitude c string*/
	char smallestLong [10];
	/**Largest Latitude c string*/
	char largestLat [10];
	/**SmallestLatitude c string*/
	char smallestLat [10];
};

State::State()
{
	 stateName[0]  = 0;
	 easternZipcode[0]  = 0;
	 westernZipcode[0]  = 0;
	 northernZipcode[0]  = 0;
	 southernZipcode[0]  = 0;
	 largestLong[0]  = 0;
	 smallestLong[0]  = 0;
	 largestLat[0]  = 0;
	 smallestLat[0]  = 0;
}



#endif