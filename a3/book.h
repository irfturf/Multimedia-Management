#ifndef SENECA_BOOK_H
#define SENECA_BOOK_H
#include <iostream>
#include <string>
#include "mediaItem.h"

namespace seneca {
    class Book :
        public MediaItem
    {
        std::string m_author;
        //m_title
        std::string m_country;
        //m_year
        double m_price;
        //m_summary

        Book() = default;
        Book(const std::string& author, const std::string& title, const std::string& country, std::string& summary, unsigned short year, double price)
            : MediaItem(title, summary, year), m_author(author), m_country(country), m_price(price) {}
		~Book() = default;
    public:
        void display(std::ostream& out) const override;
        Book* createItem(const std::string& strBook);
    };
}

#endif