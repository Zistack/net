void
T::addStage (std::unique_ptr<Stage::T> && stage)
{
	this->stages.emplace_back (std::move (stage));
}
