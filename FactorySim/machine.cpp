#include "Machine.h"

Machine::Machine(int r, int c)
    : m_row(r), m_col(c)
{
}

Machine::~Machine()
{
}

int Machine::row() const { return m_row; }
int Machine::col() const { return m_col; }
