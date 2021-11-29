
void leggtilkoordinat(list_t* list, koordinat_t* ny_koordinat)
{
    list_iter_t* iter = list_createiter(list);

    koordinat_t* koordinat = list_next(iter);
    if (koordinat == NULL)
        return;

    while (koordinat != NULL)
    {                  
        koordinat->x += ny_koordinat->x;
        koordinat->y += ny_koordinat->y;

        koordinat = list_next(iter);
    }
}

void tegnfigur(list_t* list)
{
    list_iter_t* iter = list_createiter(list);

    koordinat_t* start = list_next(iter);
    if (start == NULL)
        return;

    koordinat_t* slutt = list_next(iter);
    slutt = list_next(iter);
    if (slutt == NULL)
        return;

    while (slutt != NULL)
    {                  
        drawLine(start->x, start->y, slutt->x, slutt->y);
        start = slutt;
        slutt = list_next(iter);
    }
}