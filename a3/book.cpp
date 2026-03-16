#include <iostream>
#include <iomanip>
#include <string>
#include "settings.h"
#include "book.h"

namespace seneca {
	void Book::display(std::ostream& out) const
	{
        {
            if (g_settings.m_tableView)
            {
                out << "B | ";
                out << std::left << std::setfill('.');
                out << std::setw(50) << this->getTitle() << " | ";
                out << std::right << std::setfill(' ');
                out << std::setw(2) << this->m_country << " | ";
                out << std::setw(4) << this->getYear() << " | ";
                out << std::left;
                if (g_settings.m_maxSummaryWidth > -1)
                {
                    if (static_cast<short>(this->getSummary().size()) <= g_settings.m_maxSummaryWidth)
                        out << this->getSummary();
                    else
                        out << this->getSummary().substr(0, g_settings.m_maxSummaryWidth - 3) << "...";
                }
                else
                    out << this->getSummary();
                out << std::endl;
            }
            else
            {
                size_t pos = 0;
                out << this->getTitle() << " [" << this->getYear() << "] [";
                out << m_author << "] [" << m_country << "] [" << m_price << "]\n";
                out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
                while (pos < this->getSummary().size())
                {
                    out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
                    pos += g_settings.m_maxSummaryWidth;
                }
                out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
                    << std::setfill(' ') << '\n';
            }
        }
	}
    Book* Book::createItem(const std::string& strBook)
    {
		std::string temp, author, title, country, summary;
		int year;
        double price;

		temp = strBook;

        if (temp == "" || temp.find('#') == 0)
            throw "Not a valid book.";

        author = temp.substr(0, temp.find(','));
		trim(author);
		temp.erase(0, temp.find(',') + 1);
		
        title = temp.substr(0, temp.find(','));
		trim(title);
		temp.erase(0, temp.find(',') + 1);
		
        country = temp.substr(0, temp.find(','));
		trim(country);
		temp.erase(0, temp.find(',') + 1);
		
        price = std::stod(temp);
        temp.erase(0, temp.find(',') + 1);

		year = std::stoi(temp);
		temp.erase(0, temp.find(',') + 1);

		summary = temp;
		trim(summary);

        return new Book(author, title, country, summary, year, price);
    }
}

