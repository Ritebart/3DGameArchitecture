#ifndef  IUPDATER_H_
#define IUPDATER_H_

#include <iostream>

class IUpdater
{
protected:
	float DeltaTime = 0;

	virtual void Update() = 0;
};

#endif // ! IUPDATER_H_