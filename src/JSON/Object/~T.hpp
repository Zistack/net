T::~T ()
{
	for (auto member : this->members) delete member.second;
}
