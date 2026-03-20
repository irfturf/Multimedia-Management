#include <iostream>
#include <string>
#include <list>
#include <iomanip>
#include <algorithm>
#include "settings.h"
#include "mediaItem.h"
#include "tvShow.h"

namespace seneca
{
    void TvShow::display(std::ostream& out) const
    {
        if (g_settings.m_tableView)
        {
            out << "S | ";
            out << std::left << std::setfill('.');
            out << std::setw(50) << this->getTitle() << " | ";
            out << std::right << std::setfill(' ');
            out << std::setw(2) << this->m_episodes.size() << " | ";
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
            out << this->getTitle() << " [" << this->getYear() << "]\n";
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << "" << '\n';
            while (pos < this->getSummary().size())
            {
                out << "    " << this->getSummary().substr(pos, g_settings.m_maxSummaryWidth) << '\n';
                pos += g_settings.m_maxSummaryWidth;
            }
            for (auto& item : m_episodes)
            {
                out << std::setfill('0') << std::right;
                out << "    " << 'S' << std::setw(2) << item.m_season
                    << 'E' << std::setw(2) << item.m_numberInSeason << ' ';
                if (item.m_title != "")
                    out << item.m_title << '\n';
                else
                    out << "Episode " << item.m_numberOverall << '\n';

                pos = 0;
                while (pos < item.m_summary.size())
                {
                    out << "            " << item.m_summary.substr(pos, g_settings.m_maxSummaryWidth - 8) << '\n';
                    pos += g_settings.m_maxSummaryWidth - 8;
                }
            }
            out << std::setw(this->getTitle().size() + 7) << std::setfill('-') << ""
                << std::setfill(' ') << '\n';
        }
    }

    TvShow* TvShow::createItem(const std::string& strShow)
    {
        std::string temp, id, title, summary;
        int year;

        temp = strShow;
        if (!temp.empty() && temp.back() == '\r')
            temp.pop_back();

        if (temp == "" || temp.find('#') == 0)
            throw "Not a valid show.";

        id = temp.substr(0, temp.find(','));
        trim(id);
        temp.erase(0, temp.find(',') + 1);

        title = temp.substr(0, temp.find(','));
        trim(title);
        temp.erase(0, temp.find(',') + 1);

        year = std::stoi(temp);
        temp.erase(0, temp.find(',') + 1);

        summary = temp;
        trim(summary);

        return new TvShow(id, title, summary, year);
    }

    double TvShow::getEpisodeAverageLength() const
    {
        
    }

    std::list<std::string> TvShow::getLongEpisodes() const
    {
        
    }

}