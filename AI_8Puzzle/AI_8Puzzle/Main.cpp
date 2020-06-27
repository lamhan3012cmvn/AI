#include"CDisplay.h"

int main()
{
    Nocursortype();
    do
    {
        CDisplay* d = new CDisplay();
        d->playGame();
		delete(d);
    } while (true);
    return 0;
}