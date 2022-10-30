#include <stdio.h>

void printHelp() {
    puts(
    "Start the application for the first time\n"
    "     START     Start the application and read the configuration\n"
    "     EXIT      Exit the application\n"
    "     HELP      Help to see the explanation of the appliation especially the command\n"
    "\n"
    "After the program starts\n"
    "  Order food\n"
    "     BUY       place an order\n"
    "     DELIVERY  To display food orders\n\n"
    "  BNMO navigation\n"
    "     MOVE [<direction>]      Move BNMO by one unit according to the cardinal directions\n"
    "        direction : [NORTH] [SOUTH] [EAST] [WEST]\n"
    "        usage : MOVE NORTH or MOVE SOUTH or MOVE EAST or MOVE WEST\n\n"
    "  Food processing\n"
    "     MIX       Mixing two or more foods into one food\n"
    "     CHOP      Cut food ingredients into slices\n"
    "     FRY       Fry one on more ingredients \n"
    "     BOIL      Boil one on more ingredients\n"
    "  Mechanism of time\n"
    "     WAIT [<hours>] [<minutes>]    To hold time\n\n"
    "  Others\n"
    "     CATALOG   Display detailed information on ingredients and food available on the application\n"
    "     UNDO      Cancel the command executed by the simulator and returns the application state to before the command was executed\n"
    "     REDO      Cancel the undo command\n"
    );
}