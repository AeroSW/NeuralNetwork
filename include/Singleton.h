#ifndef SINGLETON_H
#define SINGLETON_H

class singleton{
	protected:
		virtual ~singleton(){}
		unsigned int ref_counter;
	
	public:
		virtual void deref() = 0;
		virtual unsigned int get_reference_counter() = 0;
};

#endif