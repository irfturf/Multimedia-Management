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

        Book(const std::string& author, const std::string& title, const std::string& country, 
            const std::string& summary, unsigned short year, double price);
    public:
        void display(std::ostream& out) const override;
        static Book* createItem(const std::string& strBook);
    };
}

#endif