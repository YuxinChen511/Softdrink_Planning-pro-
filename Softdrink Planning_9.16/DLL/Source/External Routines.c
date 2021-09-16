#include "aimmsapi.h"

enum {
    EINDHOVEN,
    HAARLEM,
    ZWOLLE,
    FACTORY_MAX
};

enum {
    AMERSFOORT,
    AMSTERDAM,
    APELDOORN,
    ARNHEM,
    ASSEN,
    BREDA,
    DENBOSCH,
    DENHAAG,
    DENHELDER,
    DEVENTER,
    DORDRECHT,
    EMMEN,
    ENSCHEDE,
    GRONINGEN,
    LEEUWARDEN,
    MAASTRICHT,
    NIJMEGEN,
    ROTTERDAM,
    TILBURG,
    UTRECHT,
    VENLO,
    VLISSINGEN,
    CENTER_MAX
};

static char *factory_name[FACTORY_MAX] = {
    /* EINDHOVEN  */ "Eindhoven",
    /* HAARLEM    */ "Haarlem",
    /* ZWOLLE     */ "Zwolle"
};

static char *center_name[CENTER_MAX] = {
    /* AMERSFOORT */ "Amersfoort",
    /* AMSTERDAM  */ "Amsterdam",
    /* APELDOORN  */ "Apeldoorn",
    /* ARNHEM     */ "Arnhem",
    /* ASSEN      */ "Assen",
    /* BREDA      */ "Breda",
    /* DENBOSCH   */ "Den Bosch",
    /* DENHAAG    */ "Den Haag",
    /* DENHELDER  */ "Den Helder",
    /* DEVENTER   */ "Deventer",
    /* DORDRECHT  */ "Dordrecht",
    /* EMMEN      */ "Emmen",
    /* ENSCHEDE   */ "Enschede",
    /* GRONINGEN  */ "Groningen",
    /* LEEUWARDEN */ "Leeuwarden",
    /* MAASTRICHT */ "Maastricht",
    /* NIJMEGEN   */ "Nijmegen",
    /* ROTTERDAM  */ "Rotterdam",
    /* TILBURG    */ "Tilburg",
    /* UTRECHT    */ "Utrecht",
    /* VENLO      */ "Venlo",
    /* VLISSINGEN */ "Vlissingen"
};

static double distance[FACTORY_MAX][CENTER_MAX] =
{
    { 154.50, 181.50, 163.50, 123.00, 337.50,  85.50,  48.00, 201.00, 306.00, 189.00, 138.00, 331.50, 270.00, 381.00, 360.00, 129.00,  93.00, 169.50,  51.00, 132.00,  84.00, 181.50 },
    { 100.50,  28.50, 175.50, 171.00, 316.50, 181.50, 154.50,  76.50, 108.00, 195.00, 141.00, 310.50, 276.00, 306.00, 222.00, 342.00, 202.50, 105.00, 193.50,  81.00, 297.00, 282.00 },
    { 105.00, 169.50,  64.50, 102.00, 114.00, 234.00, 198.00, 228.00, 235.50,  58.50, 216.00, 108.00, 112.50, 157.50, 136.50, 366.00, 156.00, 220.50, 234.00, 136.50, 255.00, 400.50 }
};


static int parse_name( char *name, BOOL is_factory )
{
    int   i, len;
    char *city;

    if ( !name ) return -1;

    len = is_factory ? FACTORY_MAX : CENTER_MAX;

	for ( i=0; i<len; i++ ) {
        city = (is_factory) ? factory_name[i] : center_name[i];
        if ( 0 == stricmp( name, city ) ) return i;
    }

    return -1;
}

DLL_EXPORT(double) DLLUnitTransportCost( char *from, char *to )
{
    int    f, ff, c, nearest_factory;
        
    f = parse_name( from, /*is_factory*/ TRUE );
    if ( f == -1 ) return 0.0;

    c = parse_name( to, /*is_factory*/ FALSE );
    if ( c == -1 ) return 0.0;

    nearest_factory = 0;
    for ( ff=0; ff<FACTORY_MAX; ff++ )
        if ( distance[ff][c] < distance[nearest_factory][c] ) nearest_factory = ff;

    /* do not consider routes that are too long */
    if ( ( f != nearest_factory ) &&
         ( distance[f][c] > 2 * distance[nearest_factory][c] ) ) return 0.0;

    return (0.5 * distance[f][c]);
}