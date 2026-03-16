#include <iomanip>
#include <string>
#include "settings.h"
#include "movie.h"

namespace seneca 
{
	void Movie::display(std::ostream& out) const
    {
        if (g_settings.m_tableView)
        {
            out << "M | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(9) << this->getYear() << " | ";
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
            out << this->getTitle() << " [" << this->getYear() << "]\n";
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
    Movie* Movie::createItem(const std::string& strMovie)
    {
        std::string temp, title, summary;
        int year;

        temp = strMovie;

        if (temp == "" || temp.find('#') == 0)
            throw "Not a valid movie.";

        title = temp.substr(0, temp.find(','));
        trim(title);
        temp.erase(0, temp.find(',') + 1);

        year = std::stoi(temp);
        temp.erase(0, temp.find(',') + 1);

        summary = temp;
        trim(summary);

        return new Movie(title, summary, year);
    }
}