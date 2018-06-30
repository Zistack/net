T::~T ()
{
	delete this -> signal;
	delete this -> epoll;
}
