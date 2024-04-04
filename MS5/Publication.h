#ifndef SDDS_PUBLICATION_H
#define SDDS_PUBLICATION_H

#include "Date.h"
#include "Streamable.h"
#include "Lib.h"

namespace sdds {
    class Publication : public Streamable {
    private:
        char* m_title;
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];
        int m_membership=0;
        int m_libRef=-1;
        Date m_date;
    public:
        Publication();
        ~Publication();

        
        Publication(const Publication& publication);
        Publication& operator=(const Publication& publication);
        void setDefault();
        virtual void set(int member_id);

        void setRef(int value);
        void resetDate();

        virtual char type() const;
        bool onLoan() const;

        Date checkoutDate() const;

        bool operator==(const char* title) const;

        operator const char* () const;

        int getRef() const;

        bool conIO(std::ios& io) const;

        std::ostream& write(std::ostream& os) const;

        std::istream& read(std::istream& is);

        operator bool() const;
    };
}

#endif //SDDS_PUBLICATION_H
