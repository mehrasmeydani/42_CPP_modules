#pragma once

class Data {
	public:
		int i;
		Data(void);
		Data(const Data& in);
		Data& operator=(const Data& in);
		~Data();
};


