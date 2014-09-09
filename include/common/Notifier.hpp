#ifndef NOTIFIER_HPP
#define NOTIFIER_HPP

#include <unordered_set>

namespace common
{

template<typename N>
class Notifier
{
public:
	Notifier() = default;

	Notifier(N* pListener) : Notifier(std::unordered_set<N*>({pListener}))
	{
	}

	Notifier(std::unordered_set<N*> listeners) : listeners(listeners)
	{
	}

	virtual ~Notifier() = default;

	std::unordered_set<N*>& getListeners()
	{
		return listeners;
	}

	const std::unordered_set<N*>& getListeners() const
	{
		return listeners;
	}

private:

	std::unordered_set<N*> listeners;

};

}

#endif // LISTENERHOLDER_HPP
