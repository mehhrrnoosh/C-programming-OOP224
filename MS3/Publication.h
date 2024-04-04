// Publication.hpp
// Streamable
//
// Created by Apple on 2023-07-19.

#ifndef Publication_hpp
#define Publication_hpp

#include <stdio.h>
#include <ostream>
#include <istream>
#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {
    class Publication : public Streamable {
        char* m_title;
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        // Constructors and destructor
        Publication();
        Publication(const Publication& publication);
        Publication& operator=(const Publication& publication);
        ~Publication();

        // Helper function to set default values
        void defaultValue();

        // Implementation of the Streamable interface methods
        virtual std::ostream& write(std::ostream& os) const override;
        virtual std::istream& read(std::istream& is) override;
        virtual bool conIO(std::ios& io) const override;
        virtual operator bool() const override;

        // Other member functions
        void set(int member_id);
        void setRef(int value);
        void resetDate();
        char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;
    };

} // namespace sdds

#endif /* Publication_hpp */
