#ifndef SENECA_MOVIE_H
#define SENECA_MOVIE_H
#include <iomanip>
#include <string>
#include "mediaItem.h"

namespace seneca
{
	class Movie :
		public MediaItem
	{
		//title year and summary
		Movie(const std::string& title, const std::string& summary, unsigned short year) :
			MediaItem(title, summary, year) {}
	public:
		void display(std::ostream& out) const override;
		static Movie* createItem(const std::string& strMovie);
	};
}

#endif