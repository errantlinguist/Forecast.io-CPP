#ifndef NOTIFIER_HPP
#define NOTIFIER_HPP

namespace common
{

template<typename N>
class Notifier
{
public:
	Notifier(N& listener) :
			pListener(&listener)
	{
	}

	virtual ~Notifier()
	{

	}

	N* getListener()
	{
		return pListener;
	}

	const N* getListener() const
	{
		return pListener;
	}

	virtual void setListener(N& listener)
	{
		this->pListener = &listener;
	}

private:

	N* pListener;

};

}

#endif // LISTENERHOLDER_HPP
