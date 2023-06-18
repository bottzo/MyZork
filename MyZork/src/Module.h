#ifndef _MODULE_H__
#define _MODULE_H__

class Module {
public:
	Module();
	virtual ~Module();

	//virtual bool Init();
	virtual bool Update();
	//virtual bool CleanUp();
private:

};

#endif // !_MODULE_H__