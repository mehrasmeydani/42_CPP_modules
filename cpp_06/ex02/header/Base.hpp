#pragma once

class Base {
	public:
		Base(void);
		Base(const Base& in);
		Base& operator=(const Base& in);
		virtual ~Base() = 0;
};


