template <typename ... UpgradeTargets>
std::string
T <UpgradeTargets ...>::normalize (std::string string)
{
	for (char & c : string) c = (char) std::tolower (c);

	return string;
}
